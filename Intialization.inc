PortIntialization macro
	pusha
	mov al,10000000b 
	mov dx,3fbh
	
	out dx,al 
	mov al, 0ch
	mov dx,3fbh
	out dx,al
	
	mov dx,3f9h
	mov al,00h
	out dx,al  
	
	mov al,00011011b 
	mov dx, 3fbh
	out dx,al
	popa
endm PortIntialization

DataIntialization macro 
   call calc_square 
   call calc_centre
;----------------
   mov bx,offset GiftsX  
   mov Si,offset GiftsY  
    
   mov word ptr [bx],75d
   mov word ptr [bx+2],85d
   mov word ptr [bx+4],80d
   mov word ptr [bx+6],11b
   
   
   mov word ptr [bx+8],555d
   mov word ptr [bx+10],565d
   mov word ptr [bx+12],560d
   mov word ptr [bx+14],11b
   
   mov word ptr [bx+16],315d
   mov word ptr [bx+18],325d
   mov word ptr [bx+20],320d
   mov word ptr [bx+22],11b
   
   mov word ptr [bx+24],315d
   mov word ptr [bx+26],325d
   mov word ptr [bx+28],320d
   mov word ptr [bx+30],11b
   
   mov word ptr [bx+32],315d
   mov word ptr [bx+34],325d
   mov word ptr [bx+36],320d
   mov word ptr [bx+38],11b
   
    
   mov word ptr [si],175d
   mov word ptr [si+2],185d
   mov word ptr [si+4],180d
   mov word ptr [si+6],11b 
    
   mov word ptr [si+8],175d
   mov word ptr [si+10],185d
   mov word ptr [si+12],180d
   mov word ptr [si+14],11b
     
   mov word ptr [si+16],170d
   mov word ptr [si+18],180d
   mov word ptr [si+20],175d
   mov word ptr [si+22],11b
    
   mov word ptr [si+24],50d
   mov word ptr [si+26],60d
   mov word ptr [si+28],55d
   mov word ptr [si+30],11b
  
   mov word ptr [si+32],305d
   mov word ptr [si+34],315d
   mov word ptr [si+36],310d
   mov word ptr [si+38],11b   
   ;---------------- 
   ;----------------
   call tanka
   call calc_length
   call calc_points_down
   call calc_tank1  
   ;----------------   
   call tankb
   call calc_length
   call calc_points_up
   call calc_tank2
   ;----------------   
   call tanka
   call draw_tank
   call tankb
   call draw_tank 
endm DataIntialization	