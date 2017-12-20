Display MACRO MyMessage
pusha
mov Ah,9
mov dx,offset MyMessage
int 21h
popa
ENDM Display