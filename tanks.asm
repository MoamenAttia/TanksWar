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
user1 label byte; +24 to reach shoots +0 to reach tank2
tank1 dw 10d,110d,50d,110d,50d,170d,10d,170d, 20d,125d,40d,125d,40d,155d,20d,155d, 28d,120d,32d,120d,32d,125d,28d,125d ;three rectangles more word for hp and orientation
shoots1 dw 5d,1d
dw 10d,?,?
dw 'ab',?,?
dw 'cd',?,?
dw 'ef',?,?
dw 'gz',?,?

user2 label byte; +24 to reach shoots +0 to reach tank2
tank2 dw 110d,110d,150d,110d,150d,170d,110d,170d, 120d,125d,140d,125d,140d,155d,120d,155d, 128d,120d,132d,120d,132d,125d,128d,125d
shoots2 dw 5d,0d
dw ?,?,?
dw ?,?,?
dw ?,?,?
dw ?,?,?
dw ?,?,?
mes db 'a $'
.code 
main proc far
    mov AX,@Data
    mov DS,AX
    mov es,ax
    mov ah,0
    mov al,12h
    int 10h   
    mov bx ,offset tank1
    mov cx ,12d
    loop1:
    mov al ,1d
    call drawpx
    add bx,4d
    loop loop1
    mov bx ,offset tank2
    mov cx ,12d
    loop2:
    mov al ,2d
    call drawpx
    add bx,4d
    loop loop2
    l1:
    call inputshots
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
    mov ah,1
    int 16h
    jz con2
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
    mov [bx]+2,ax
    mov bl,6 
    mul bl
    mov cx,[bx]+2
    inc cx
    add [bx]+2,cx 
    add bx,4
    add bx,ax

    printstring mes
    popa
    ret
inputshots endp




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
