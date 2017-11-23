Display MACRO MyMessage
mov Ah,9
mov dx,offset MyMessage
int 21h
ENDM Display