;orientations
;00 up
;11 down
;01 right
;10 left  
include test.inc
include map.inc
include Display.inc 
include CheckBulletThroughWall.inc
.model medium
.stack 64d
.data                        
WelcomeMessage db 10,13,10,13,13,13
               db '**         **  ********  **    ********* ******** ***           *** ********',10,13
               db '**         **  **        **    ********* *      * ** *        *  ** **' ,10,13
               db '**         **  **        **    **        *      * **  * *  * *   ** **'  ,10,13
               db '**   ***   **  ********  **    **        *      * **     **      ** ********'    ,10,13
               db '** **   ** **  **        **    ********* *      * **             ** **'  ,10,13
               db '***      ****  ********  ***** ********* ******** **             ** ********$' 
              
DoYoWantToPlay db 10,13,10,13,10,13,'                         If You want to play ,, press any key$'           
BulletCoordinates dw 00d,00d 
AllBullets dw 0000H,0000H

line label byte
StartPointX dw ,?
StartPointY dw ,?
EndPointX   dw ,?
EndPointY   dw ,?
linecolor   db ,?


user1 label byte; +48 to get center + 52 to get orientation and hp word                                                                                                     
tank1 dw 30d,110d,70d,110d,70d,170d,30d,170d,  40d,125d,60d,125d,60d,155d,40d,155d, 48d,120d,52d,120d,52d,125d,48d,125d, 50d,140d ,0701h ;three rectangles 2 words tankcenter  more word for hp and orientation
shots1 dw 5d,1d
dw 150,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0

user2 label byte; +48 to get center + 52 to get orientation and hp word
tank2 dw 130d,110d,170d,110d,170d,170d,130d,170d, 140d,125d,160d,125d,160d,155d,140d,155d, 148d,120d,152d,120d,152d,125d,148d,125d, 150d,140d ,0d
shots2 dw 5d,0d
dw 0,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0   

mes dw '  ' ,'$$'
integar db ' '

.code 
main proc far 
    mov AX,@Data
    mov DS,AX
    mov es,ax    
    
    ;Display  WelcomeMessage
    ;Display  DoYoWantToPlay
    
    ;mov ah,0
    ;int 16h
    
    mov ah,0
    mov al,12h
    int 10h   
    
    SetMap  
    ;CheckBulletThroughWall 
    mov bx ,offset tank1
    mov cx ,13d
    loop1:
        mov al ,1d
        call drawpx
        add bx,4d
    loop loop1
        mov bx ,offset tank2
        mov cx ,13d
    loop2:
        mov al ,2d
        call drawpx
        add bx,4d
    loop loop2
    l1:
        ;---------------------------------
        mov bx,offset shots1 ;bx on shots1(2)
        ;call inputshots
        ;---------------------------------
        ;mov bx, offset shots1 ;bx on shots1(2)
        ;call drawshot
        ;---------------------------------
        mov bx, offset shots1
        mov di, offset tank2
        call process_shots  ;bx on shots1(2) of attacker tank2(1) and di on victm tank
        ;---------------------------------
        mov ax,tank1 + 52d
        add ah ,'0'
        xor al,al
    jz l1    
    hlt
main endp

DrawLine proc near
    pusha
    mov AX,StartPointX
    cmp Ax,EndPointX
	je VerticalLine

    HorizontalLine:
    mov cx,StartPointX 	;Column
    mov dx,StartPointY 	;Row
    mov al,linecolor  		;Pixel color
    mov ah,0ch  		;Draw Pixel Command
    looop1: int 10h
    	 inc cx
    	 cmp cx,EndPointX
    	 jnz looop1
    popa
    ret
    
    VerticalLine:
    mov cx,StartPointX 	;Column
    mov dx,StartPointY 	;Row
    mov al,linecolor  		;Pixel color
    mov ah,0ch  		;Draw Pixel Command
    looop2: int 10h
	 inc dx
	 cmp dx,EndPointY
	 jnz looop2 
	
    popa
    ret
Drawline endp


inputshots proc near
    pusha
    ;i here interset in shoot only
    mov si ,[bx]
    mov di ,[bx]+2
    cmp si ,di
    jnz con
    popa
    ret
    con:
    xor ax,ax
    mov ah,1d
    int 16h
    jnz con2
    popa
    ret
    con2:
    cmp ah,57d
    jz con3
    popa
    ret
    con3:
    mov ah,0
    int 16h     
    ;-----------
    mov ax,[bx]+2
    mov cl,6 
    mul cl
    mov cx,[bx]+2
    inc cx
    mov [bx]+2,cx 
    add bx,4
    add bx,ax 
    ;--------- 
    mov cx  , tank1+48
    mov [bx], cx
    mov cx  , tank1+50
    mov [bx] +2 , cx
    mov cx  , tank1+52
    and cl ,00000011b  
    mov [bx] +4 ,cx
    cas1:    
        cmp cl , 0d
        jnz cas2
        mov si,[bx +2]
        sub si ,35
        mov [bx+2],si
        jmp finish
    cas2:
        cmp cl ,1d
        jnz cas3
        mov si,[bx]
        add si ,35
        mov [bx],si
        jmp finish
    cas3:    
        cmp cl , 2d 
        jnz cas4
        mov si,[bx]
        sub si ,35
        mov [bx],si 
        jmp finish
    cas4:    
        cmp cl , 3d
        jnz finish
        mov si,[bx +2]
        add si ,35
        mov [bx+2],si
    finish:
    ;---------------    
    popa
    ret
inputshots endp

process_shots proc near   ;bx on shots of attacker tank and di on victm tank
    pusha
    mov cx,[bx]+2 
    cmp cx,0
    jnz cont
    popa
    ret
    cont:
    add bx,4 ; no bx on first shot
    moveshots:
        push cx
        mov ax,[bx]+4
        cas_1:    
            cmp al , 0d
            jnz cas_2
            mov si,[bx +2] 
            cmp si,2
            jb cas_2 ; over flow check
            sub si ,2
            mov [bx+2],si
            jmp finish2
        cas_2:
            cmp al ,1d
            jnz cas_3
            mov si,[bx] 
            cmp si,0fffdh ; over flow check
            jg cas_3
            add si ,2 
            mov [bx],si
            jmp finish2
        cas_3:    
            cmp al , 2d 
            jnz cas_4
            mov si,[bx]
            cmp si,2
            jb cas_4 ; over flow check
            sub si ,2
            mov [bx],si 
            jmp finish2
        cas_4:    
            cmp al , 3d
            jnz finish2
            mov si,[bx +2]
            cmp si,0fffdh ; over flow check
            jg finish2
            add si ,2d
            mov [bx+2],si
        finish2:        ; moving one point the process point
         
        ;get smallest and bigest x  
        push di
        mov ax,[di] ;max x
        mov dx,ax   ;min x
        add di,4
        
        mov cx,3
        get_min_max_x:
           cmp ax,[di]
           ja here
               mov ax,[di]
               jmp skip
           here:
           cmp dx,[di]
           jb skip
           mov dx,[di] 
            
        skip:
        add di,4
        loop get_min_max_x   
        pop di      
        
        ;check point between two xs
        cmp [bx],dx
        jb next
        cmp [bx],ax
        ja next 
        
        ;get smallest and bigest y  
        push di  
        add di,2
        mov ax,[di] ;max y
        mov dx,ax   ;min y
        add di,4
        
        mov cx,3
        get_min_max_y:
           cmp ax,[di]
           ja here2
               mov ax,[di]
               jmp skip2
           here2:
           cmp dx,[di]
           jb skip2
           mov dx,[di] 
            
        skip2:add di,4
        loop get_min_max_y   
        pop di   
        
        ;check point between two ys
        cmp [bx+2],dx
        jb next
        cmp [bx+2],ax
        ja next               
        
        
         ; process deleting pixel and decreaing tank hp to be continue
        
        
        
        
        
        next:
        
        add bx,6d   
        pop cx
    loop moveshots 
    
    
    
    
    
    
    
    
    
    
    
    
    
    popa
    ret
process_shots endp


drawshot proc near
    pusha 
    add bx,4
    mov al ,0ch
    mov cx,[bx]
    mov dx,[bx]+2
    
    mov ah,0ch
    int 10h
    ;-----
    inc cx
    mov ah,0ch
    int 10h
    ;-----
    inc dx
    mov ah,0ch
    int 10h
    ;-----
    dec cx
    mov ah,0ch
    int 10h
    ;-----
    dec cx
    mov ah,0ch
    int 10h
    ;-----
    dec dx
    mov ah,0ch
    int 10h
    ;-----
    dec dx
    mov ah,0ch
    int 10h
    ;-----
    inc cx
    mov ah,0ch
    int 10h
    ;-----
    inc cx
    mov ah,0ch
    int 10h
    popa
    ret
drawshot endp



drawpx proc near ; draw pixel with color in al
    pusha
    mov cx,[bx]
    mov dx,[bx]+2
    mov ah,0ch
    int 10h
    popa
    ret 
drawpx endp


end main
