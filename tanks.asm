.model small
.stack 64
.data

.code 
main proc far
mov AX,@Data
mov DS,AX
mov es,ax
mov ah,0
mov al,12h
int 10h   
   
   
loop1:
jmp loop1   
   
   

    
    
    
hlt
main endp
end main
