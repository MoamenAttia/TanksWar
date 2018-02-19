MoveCursor MACRO X,Y
xor bx,bx    
mov ah,2
mov dl,X
mov dh,Y
int 10h
ENDM MoveCursor