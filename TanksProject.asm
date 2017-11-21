.model small
.stack 64
.data


.code 
main proc far
mov AX,@Data
mov DS,AX
   
   
mov ah,0
mov al,3
int 10h   
   
   
   
   
   

    
    
    
hlt
main endp
end main
