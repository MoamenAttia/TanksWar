;orientations
;00 up
;11 down
;01 right
;10 left  
include test.inc

include map.inc   
include map2.inc
include Display.inc 
include CheckBulletThroughWall.inc

.model meduim
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
tank1 dw 30d,110d,70d,110d,70d,150d,30d,150d,  40d,120d,60d,120d,60d,140d,40d,140d, 45d,115d,55d,115d,55d,120d,45d,120d, 50d,130d ,0721h ;three rectangles 2 words tankcenter  more word for hp and orientation
shots1 dw 5d,0d
dw 0,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0

user2 label byte; +48 to get center + 52 to get orientation and hp word
tank2 dw 80d,210d,120d,210d,120d,250d,80d,250d,  90d,220d,110d,220d,110d,240d,90d,240d, 95d,215d,105d,215d,105d,220d,95d,220d, 100d,230d ,0711h
shots2 dw 5d,0d
dw 0,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0

min_x dw 0
max_x dw 0
min_y dw 0
max_y dw 0 

damagedwall_pos dw ?,?,?  ; last word for power that wall hit with 
shootspeed dw 2

mes dw 'aaaaaaaaaaaaaaaaaaaaaaaaaa' ,10,13 ,'$$'
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
    mov bh,0
    mov ah,0
    mov al,12h
    int 10h   
    
    
    SetMap
 
    
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
        mov bx,offset shots1 ;bx on shots1(2) di for tank1(2)
        mov di,offset tank1
        call inputshots
        ;---------------------------------
        mov bx, offset shots1
        mov di, offset tank2
        call process_shots  ;bx on shots1(2) of attacker tank2(1) and di on victm tank
    jmp l1    
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


drawpx proc near ; draw pixel with color in al
    pusha
    mov cx,[bx]
    mov dx,[bx]+2
    mov ah,0ch
    mov bh,0
    int 10h
    popa
    ret 
drawpx endp 



inputshots proc near
    pusha 
    ;i here interset in shoot only  
    mov ah,1d
    int 16h 
    jnz con
    popa
    ret
    con: 
    cmp ah,57d     
    jz con2
    popa
    ret
    con2:
    
        mov si ,[bx]
        mov ax ,[bx]+2
        cmp si ,ax
    jnz con3
    mov ah,0
    int 16h   
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
    mov cx  , [di]+48d
    mov [bx], cx
    mov cx  , [di]+50d
    mov [bx] +2 , cx
    mov cx  , [di]+52d 
    and cx,00ffh
    mov [bx] +4 ,cx
    mov cx  , [di]+52d
    and cx,0ff1fh
    or cx ,0010h  
    mov [di]+52d ,cx   
    and cl ,00000011b
  
    cas1:    
        cmp cl , 0d
        jnz cas2
        mov si,[bx +2]
        sub si ,21d
        mov [bx+2],si
        jmp finish
    cas2:
        cmp cl ,1d
        jnz cas3
        mov si,[bx]
        add si ,21d
        mov [bx],si
        jmp finish
    cas3:    
        cmp cl , 2d 
        jnz cas4
        mov si,[bx]
        sub si ,21d
        mov [bx],si 
        jmp finish
    cas4:    
        cmp cl , 3d
        jnz finish
        mov si,[bx +2]
        add si ,21
        mov [bx+2],si
    finish:      
     
    
    ;---------------    
    popa
    ret
inputshots endp

process_shots proc near   ;bx on shots of attacker tank and di on victm tank 
    ;steps
    ;1.process shots 2.draw shots 3.clear and move them 4.repeat
    pusha  ;now shots to process 
    mov cx,[bx]+2 
    cmp cx,0
    jnz cont
    popa
    ret
    cont:


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
    
    mov max_x,ax
    mov min_x,dx     
    ;-----------------------------
    
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
    mov max_y,ax
    mov min_y,dx
    ;-----------------------------
    
    mov cx,[bx]+2 
    add bx,4
    push bx             
    check_del_shots:
        push cx        
        ;first check shots throug wall  
        mov cx ,[bx] +4
        and cl ,00000011b
        mov ax,shootspeed ;this is shoot speed  
        option1:   
            cmp cl , 0d
            jnz option2
            push cx
            mov cx,[bx]
            mov dx,[bx +2] 
            dec ax ; dec ax counter of loop to use it
            add dx,ax
            inc ax ;bring it back
            push ax 
            mov ah,0dh
            ;
            push bx
            mov bh,0
            int 10h
            pop bx
            ; 
            cmp al,3d     ;very very strong wall
            jnz to1 
                pop ax
                pop cx 
                jmp noneg  ;noneg name has no meaning here it will go to line when i start deleteing node (by chance :D)       
          to1:   
            cmp al,0ch    ;strong wall   
            jz todamge1
            cmp al,0eh   ;weak wall 
            jnz to2  
            
            
            todamge1: ; here i should change wall color 
            mov damagedwall_pos ,cx
            mov damagedwall_pos +2  ,dx
            ;-----
            push cx
            mov cx,[bx]+4
            shr cx,4
            xor ch,ch 
            mov damagedwall_pos +4  ,cx
            pop cx
            ;----- 
            call damagewall   
            
            pop ax
            pop cx
            jmp noneg        
            to2:
            pop ax
            pop cx  
                
            dec ax
         jnz option1
        option2:
            cmp cl , 1d
            jnz option3
            push cx
            mov cx,[bx]
            mov dx,[bx +2]
            dec ax ; dec ax counter of loop to use it
            add cx,ax
            inc ax ;bring it back
            push ax 
            mov ah,0dh 
            ;
            push bx
            mov bh,0
            int 10h
            pop bx 
            ; 
            cmp al,3d      ;very very strong wall
            jnz to11 
                pop ax
                pop cx 
                jmp noneg        
          to11:
            cmp al,0ch    ;strong wall   
            jz todamge2
            cmp al,0eh   ;weak wall 
            jnz to22  

            todamge2: ; here i should change wall color 
            mov damagedwall_pos ,cx
            mov damagedwall_pos +2  ,dx
            ;-----
            push cx
            mov cx,[bx]+4
            shr cx,4
            xor ch,ch 
            mov damagedwall_pos +4  ,cx
            pop cx
            ;-----  
            call damagewall   
            
            pop ax
            pop cx
            jmp noneg          
            to22:
            pop ax
            pop cx  
                
             dec ax
         jnz option2
        option3:    
            cmp cl , 2d
            jnz option4
            push cx
            mov cx,[bx]
            mov dx,[bx +2]
            dec ax ; dec ax counter of loop to use it
            sub cx,ax
            inc ax ;bring it back
            push ax 
            mov ah,0dh
            ;
            push bx
            mov bh,0
            int 10h
            pop bx 
            ; 
            cmp al,3d
            jnz to111 
                pop ax
                pop cx 
                jmp noneg        
          to111:
            cmp al,0ch    ;strong color   
            jz todamge3
            cmp al,0eh   ;weak color 
            jnz to222  

            todamge3: ; here i should change wall color 
            mov damagedwall_pos ,cx
            mov damagedwall_pos +2  ,dx
            ;-----
            push cx
            mov cx,[bx]+4
            shr cx,4
            xor ch,ch 
            mov damagedwall_pos +4  ,cx
            pop cx
            ;-----  
            call damagewall   
            
            pop ax
            pop cx
            jmp noneg         
            to222:
            pop ax
            pop cx  
                
            dec ax
         jnz option3
        option4:    
            cmp cl , 3d
            jnz finishcheck
            push cx
            mov cx,[bx]
            mov dx,[bx +2]
            dec ax ; dec ax counter of loop to use it
            sub dx,ax
            inc ax ;bring it back
            push ax 
            mov ah,0dh
            ;
            push bx
            mov bh,0
            int 10h
            pop bx 
            ; 
            cmp al,3d
            jnz to1111 
                pop ax
                pop cx 
                jmp noneg        
          to1111:
            cmp al,0ch    ;strong wall   
            jz todamge4
            cmp al,0eh   ;weak wall 
            jnz to2222  

            todamge4: ; here i should change wall color 
            mov damagedwall_pos ,cx
            mov damagedwall_pos +2  ,dx
            ;-----
            push cx
            mov cx,[bx]+4
            shr cx,4
            xor ch,ch 
            mov damagedwall_pos +4  ,cx
            pop cx
            ;----- 
            call damagewall    
            
            pop ax
            pop cx
            jmp noneg         
            to2222:
            pop ax
            pop cx     
            dec ax
         jnz option4
        finishcheck:  
   
        ;check point between two xs
        mov ax,min_x
        cmp [bx],ax
        jb next
        mov ax,max_x
        cmp [bx],ax
        ja next 
                   
        ;check point between two ys 
        mov ax,min_y
        cmp [bx+2],ax
        jb next     
        mov ax,max_y
        cmp [bx+2],ax
        ja next 
                      
        ; process deleting pixel and decreaing tank hp to be continue
        mov ax,[di]+52d 
        mov dx,[bx]+4d
        shr dl,4
        sub ah,dl
        ja noneg
            mov ah,0 
        noneg:
        mov [di]+52,ax
    
        pop ax ; now orginal cx in ax ; i wonot use just to get original bx
        pop si ; now original bx in si
        push si ;put them back
        push ax ;put them back
        mov cx,[si]-2
        mov ax,cx
        dec ax
        mov cl,6
        mul cl
        add si,ax ;si on last shot now replace
        mov cx,[si] ;first word
        mov [bx],cx
        mov cx,[si]+2 ;second word
        mov [bx]+2,cx
        mov cx,[si]+4 ;third word
        mov [bx]+4,cx
        sub si,ax ;get si back of first shot
        mov ax,[si-2]
        dec ax
        mov [si-2],ax
        sub bx,6d
        pop cx
        cmp cx,1
        jz donot
        dec cx 
        donot:
        push cx
        next: 

        
        ;here check shots and walls
        
        add bx,6d   
        pop cx
    loop check_del_shots
    pop bx
    
    
    call drawshots 
    call moveshots ;mov shots and clear old shots the from screen 

    popa
    ret
process_shots endp




moveshots proc near
    pusha  
    
    
    mov cx,[bx]-2
    cmp cx,0
    jnz moveshotsloop
    popa
    ret
    moveshotsloop:
        push cx         
        mov al ,00h  ;remove(from screen) shot before moving ant itwill redrawn in next iteration 
        call drawpx 
        
        mov ax,[bx]+4
        and al ,00000011b
    
        cas_1:    
            cmp al , 0d
            jnz cas_2
            mov si,[bx +2] 
            ;--
            cmp si,shootspeed
            jb overflow1 ; over flow check
            sub si ,shootspeed 
            jmp nooverflow1
            overflow1:
            mov si,0
            nooverflow1:
            ;--
            mov [bx+2],si
            jmp finish2
        cas_2:
            cmp al ,1d
            jnz cas_3
            mov si,[bx] 
            ;---
            cmp si,0fffdh 
            ja overflow2 ; over flow check ; it will never exceed that number before delete (casue of map borders)
            add si ,shootspeed 
            jmp nooverflow2
            overflow2:
            mov si,0
            nooverflow2:
            ;---
            mov [bx],si
            jmp finish2
        cas_3:    
            cmp al , 2d 
            jnz cas_4
            mov si,[bx]
            ;---
            cmp si,shootspeed
            jb overflow3 ; over flow check
            sub si ,shootspeed 
            jmp nooverflow3
            overflow3:
            mov si,0
            nooverflow3:
            ;---
            mov [bx],si 
            jmp finish2
        cas_4:    
            cmp al , 3d
            jnz finish2
            mov si,[bx +2]
            ;---
            cmp si,0fffdh 
            ja overflow4 ; over flow check ; it will never exceed that number before delete (casue of map borders)
            add si ,shootspeed 
            jmp nooverflow4
            overflow4:
            mov si,0
            nooverflow4:
            ;---
            mov [bx+2],si
        finish2:
        add bx,6d   
        pop cx       
    loop moveshotsloop
    popa
    ret     
moveshots endp 


drawshots proc near
    pusha 
    ; now bx on first shot
    mov cx,[bx-2] 
    cmp cx,0
    jnz drawshotsloop 
    popa
    ret
    drawshotsloop:
         mov al ,0fh
         call drawpx
         add bx,6d
    loop drawshotsloop
    popa
    ret  
drawshots endp



damagewall proc near  
    pusha 
    ;----------------------------   1 
    mov di,21d
    vrmup:     ;vertical removal up then down
    mov cx,damagedwall_pos
    mov dx,damagedwall_pos+ 2
    sub dx,di
    ;----
    push cx
    push dx
    push di 
    mov bh,0
    mov ah,0dh
    int 10h
    pop di
    pop dx
    pop cx   
    ;----
    cmp al,0ch
    jz damage1
    cmp al,0eh
    jnz remove1
    mov al,0h
    jmp remove1
    damage1:
    cmp damagedwall_pos+4,2
    jz strongdamage1
        mov al,0eh 
        jmp remove1   
    strongdamage1:
    mov al,0h
    remove1:

        
    
    mov si ,damagedwall_pos+ 2
    mov  damagedwall_pos+ 2,dx
    mov bx,offset damagedwall_pos
    call drawpx 
    mov damagedwall_pos +2,si

    dec di
    jnz vrmup
    ;------------------------- 
     ; i wonot process middle pixel as it will be processed in horizontal remove
    ;----------------------------    2 
    mov di,21d
    vrmdw:     ;vertical removal down then down
    mov cx,damagedwall_pos
    mov dx,damagedwall_pos+ 2
    add dx,di
    ;----
    push cx
    push dx
    push di 
    mov bh,0
    mov ah,0dh
    int 10h
    pop di
    pop dx
    pop cx  
    ;---- 
    cmp al,0ch
    jz damage2
    cmp al,0eh
    jnz remove2
    mov al,0h
    jmp remove2
    damage2:
    cmp damagedwall_pos+4,2
    jz strongdamage2
        mov al,0eh 
        jmp remove2   
    strongdamage2:
    mov al,0h
    remove2:
     
    
    mov si ,damagedwall_pos+ 2
    mov  damagedwall_pos+ 2,dx
    mov bx,offset damagedwall_pos
    call drawpx 
    mov damagedwall_pos +2,si

    dec di
    jnz vrmdw
    ;-------------------------  
    
    
    ;----------------------------    3          now horizontal removal right then left
    mov di,21
    hrrmr:     ;horizontal remove right 
    mov cx,damagedwall_pos
    mov dx,damagedwall_pos+ 2
    add cx,di
    ;----
    push cx
    push dx
    push di 
    mov bh,0
    mov ah,0dh
    int 10h
    pop di
    pop dx
    pop cx
    ;----  
    cmp al,0ch
    jz damage3
    cmp al,0eh
    jnz remove3
    mov al,0h
    jmp remove3
    damage3:
    cmp damagedwall_pos+4,2
    jz strongdamage3
        mov al,0eh 
        jmp remove3   
    strongdamage3:
    mov al,0h
    remove3:     
    
    mov si ,damagedwall_pos
    mov  damagedwall_pos,cx
    mov bx,offset damagedwall_pos
    call drawpx 
    mov damagedwall_pos,si
    
    dec di
    jnz hrrmr
    ;------------------------- 
    ;in last loop i removed 20 point right center point so i will go right one step and remove 20 point left ; i will bring it back after all horizontal removing
    mov ax,damagedwall_pos
    inc ax
    mov damagedwall_pos,ax 
    
    ;----------------------------    4 
    mov di,21
    hrrml:     ;horizontal remove left
    mov cx,damagedwall_pos
    mov dx,damagedwall_pos+ 2
    sub cx,di
    ;----
    push cx
    push dx
    push di 
    mov bh,0
    mov ah,0dh
    int 10h
    pop di
    pop dx
    pop cx  
    ;-----
    cmp al,0ch
    jz damage4
    cmp al,0eh
    jnz remove4
    mov al,0h
    jmp remove4
    damage4:
    cmp damagedwall_pos+4,2
    jz strongdamage4
        mov al,0eh 
        jmp remove4   
    strongdamage4:
    mov al,0h
    remove4:      
    
    mov si ,damagedwall_pos
    mov  damagedwall_pos,cx
    mov bx,offset damagedwall_pos
    call drawpx 
    mov damagedwall_pos,si

    dec di
    jnz hrrml
    ;-------------------------  
    
    ;see comments above 
    mov ax,damagedwall_pos
    dec ax
    mov damagedwall_pos,ax 
       
    
    popa
    ret
damagewall endp



end main
                                 
                                 
