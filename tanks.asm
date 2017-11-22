;orientations
;00 up
;11 down
;01 right
;10 left  
.286
include test.inc
.model medium
.stack 64d
.data
user1 label byte; +48 to get center + 52 to get orientation and hp word                                                                                                     
tank1 dw 30d,110d,70d,110d,70d,170d,30d,170d,  40d,125d,60d,125d,60d,155d,40d,155d, 48d,120d,52d,120d,52d,125d,48d,125d, 50d,140d ,0d ;three rectangles 2 words tankcenter  more word for hp and orientation
shots1 dw 5d,0d
dw ?,?,?
dw ?,?,?
dw ?,?,?
dw ?,?,?
dw ?,?,?

user2 label byte; +48 to get center + 52 to get orientation and hp word
tank2 dw 130d,110d,170d,110d,170d,170d,130d,170d, 140d,125d,160d,125d,160d,155d,140d,155d, 148d,120d,152d,120d,152d,125d,148d,125d, 150d,140d ,0d
shots2 dw 5d,0d
dw ?,?,?
dw ?,?,?
dw ?,?,?
dw ?,?,?
dw ?,?,?   

mes db 'a $'
integar db ' '

.code 
main proc far 
    mov AX,@Data
    mov DS,AX
    mov es,ax    
    
    mov ah,0
    mov al,12h
    int 10h   
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
        mov ax,0d 
        mov tank1+52,ax
    l1: 
        mov bx,offset shots1
        call inputshots
        mov bx, offset shots1+4
        mov al,0ch
        call drawpx
        ;call drawshot
        mov bx, offset shots1
        call process_shots
       
    jmp l1
    
    hlt
main endp


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

process_shots proc near
    pusha
    mov cx,[bx]+2 
    cmp cx,0
    jnz cont
    popa
    ret
    cont:
    
    add bx,4
moveshots:
    mov ax,[bx]+4
    cas_1:    
        cmp al , 0d
        jnz cas_2
        mov si,[bx +2]
        sub si ,2
        mov [bx+2],si
        jmp finish2
    cas_2:
        cmp al ,1d
        jnz cas_3
        mov si,[bx]
        add si ,2
        mov [bx],si
        jmp finish2
    cas_3:    
        cmp al , 2d 
        jnz cas_4
        mov si,[bx]
        sub si ,2
        mov [bx],si 
        jmp finish2
    cas_4:    
        cmp al , 3d
        jnz finish2
        mov si,[bx +2]
        add si ,2d
        mov [bx+2],si
    finish2:
    add bx,6d
loop moveshots
    popa
    ret
process_shots endp


drawshot proc near
    pusha
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
    popa
;-----
    inc dx
    mov ah,0ch
    int 10h
    popa
;-----
    inc dx
    mov ah,0ch
    int 10h
    popa
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
