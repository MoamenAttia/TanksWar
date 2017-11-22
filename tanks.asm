;orientations
;00 up
;11 down
;01 right
;10 left  
include test.inc
include map.inc
.model medium
.stack 64d
.data
;user1 label byte; +48 to get center + 52 to get orientation and hp word                                                                                                     
;tank1 dw 30d,110d,70d,110d,70d,170d,30d,170d,  40d,125d,60d,125d,60d,155d,40d,155d, 48d,120d,52d,120d,52d,125d,48d,125d, 50d,140d ,0d ;three rectangles 2 words tankcenter  more word for hp and orientation
;shoots1 dw 5d,0d
;dw ?,?,?
;dw ?,?,?
;dw ?,?,?
;dw ?,?,?
;dw ?,?,?
;
;user2 label byte; +48 to get center + 52 to get orientation and hp word
;tank2 dw 130d,110d,170d,110d,170d,170d,130d,170d, 140d,125d,160d,125d,160d,155d,140d,155d, 148d,120d,152d,120d,152d,125d,148d,125d, 150d,140d ,0d
;shoots2 dw 5d,0d
;dw ?,?,?
;dw ?,?,?
;dw ?,?,?
;dw ?,?,?
;dw ?,?,?   
;
;mes db 'a $'
;integar db ' '

.code 
main proc far 
    mov AX,@Data
    mov DS,AX
    mov es,ax    
    
    mov ah,0
    mov al,12h
    int 10h   
    
    SetMap
    ;mov bx ,offset tank1
;    mov cx ,13d
;    loop1:
;    mov al ,1d
;    call drawpx
;    add bx,4d
;    loop loop1
;    mov bx ,offset tank2
;    mov cx ,13d
;    loop2:
;    mov al ,2d
;    call drawpx
;    add bx,4d
;    loop loop2
;    mov ax,2d 
;    mov tank1+52,ax
;    l1: 
;    mov bx,offset shoots1
;    call inputshots
;    mov bx, offset shoots1+4
;    call drawpx
;  
;     
;    jmp l1
    
    hlt
main endp
;
;
;inputshots proc near
;    pusha
;    ;i here interset in shoot only
;    mov si ,[bx]
;    mov di ,[bx]+2
;    cmp si ,di
;    jnz con
;    popa
;    ret
;con:
;    xor ax,ax
;    mov ah,1d
;    int 16h
;    jnz con2
;    popa
;    ret
;con2:
;    cmp ah,57d
;    jz con3
;    popa
;    ret
;con3:
;    mov ah,0
;    int 16h     
;;-----------
;    mov ax,[bx]+2
;    mov cl,6 
;    mul cl
;    mov cx,[bx]+2
;    inc cx
;    mov [bx]+2,cx 
;    add bx,4
;    add bx,ax 
;    
;    mov cx  , tank1+48
;    mov [bx], cx
;    mov cx  , tank1+50
;    mov [bx] +2 , cx
;    mov cx  , tank1+52
;    and cl ,00000011b  
;    mov [bx] +4 ,cx
;    
;    cmp cl , 0d
;    jnz cas2
;    mov si,[bx +2]
;    sub si ,35
;    mov [bx+2],si
;    jmp finish
;cas2:
;    cmp cl ,1d
;    jnz cas3
;    mov si,[bx]
;    add si ,35
;    mov [bx],si
;    printstring mes  
;    jmp finish
;cas3:    
;    cmp cl , 2d 
;    jnz cas4
;    mov si,[bx]
;    sub si ,35
;    mov [bx],si 
;    jmp finish
;cas4:    
;    cmp cl , 3d
;    jnz finish
;    mov si,[bx +2]
;    add si ,35
;    mov [bx+2],si
;    
;finish:
;
;;---------------    
;    popa
;    ret
;inputshots endp
;
;
;
;
;drawpx proc near ; draw pixel with color in al
;    pusha
;    mov cx,[bx]
;    mov dx,[bx]+2
;    mov ah,0ch
;    int 10h
;    popa
;    ret 
;drawpx endp
;
;



end main
