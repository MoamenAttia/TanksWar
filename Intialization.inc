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
	pusha
	local nothingrecived1,clear
	
	mov FirstNameLastLife,7d
	mov SecondNameLastLife,7d
	mov FirstNameLastBullets,5d
	mov SecondNameLastBullets,5d
	mov FirstNameLastScore,0d
	mov SecondNameLastScore,0d
	mov whichlvl,0d
	mov word ptr coll_detect,0
	mov word ptr leftplayerchatingamepos,011bh
	mov word ptr rightplayerchatingamepos ,291bh
	
	   
	mov RChatinv,0
	mov Rgameinv,0
	mov Rexitinv,0
	mov RChatInGame,0
	mov imchating,0
	
	clear:
	mov dx,3fdh
	in al,dx
	and al,00000001b
	jz nothingrecived1
	mov dx,3f8h
	in al,dx 
	jmp clear
	nothingrecived1:

	
	mov word ptr tank1  , 2d
	mov word ptr tank1+2, 2d
	mov word ptr tank1+16, 12d
	mov word ptr tank1+18, 6d
	mov word ptr tank1+32, 45d
	mov word ptr tank1+34, 115d
	mov word ptr tank1+48 ,22d
	mov word ptr tank1+50 ,22d
	mov word ptr tank1+52 ,0712h
	mov word ptr shots1+2,0d
	
	mov word ptr tank2  , 598d
	mov word ptr tank2+2, 317d
	
	mov word ptr tank2+16, 90d
	mov word ptr tank2+18, 220d
	mov word ptr tank2+32, 95d
	mov word ptr tank2+34, 215d
	
	mov word ptr tank2+48 ,618d
	mov word ptr tank2+50 ,397d
	mov word ptr tank2+52 ,0712h
	mov word ptr shots2+2,0d
	
	mov word ptr coll_detect,0d

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
    ;drawing tanks  
    call calc_centre
    call calc_square
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
;------------------------- 
 
;----------------------------
	popa
endm DataIntialization	

drawframe macro
pusha

;Frame
mov word ptr StartPointX, 0d
mov word ptr StartPointY, 0d
mov word ptr EndPointX, 639d
mov word ptr EndPointY,0d
mov linecolor,3
call DrawLine

mov word ptr StartPointX, 0d
mov word ptr StartPointY, 359d
mov word ptr EndPointX, 639d
mov word ptr EndPointY,359d
mov linecolor,3
call DrawLine

mov word ptr StartPointX, 0d
mov word ptr StartPointY, 0d
mov word ptr EndPointX, 0d
mov word ptr EndPointY,459d
mov linecolor,3
call DrawLine

mov word ptr StartPointX, 639d
mov word ptr StartPointY, 0d
mov word ptr EndPointX, 639d
mov word ptr EndPointY,459d
mov linecolor,3
call DrawLine

popa

endm drawframe



StartGame macro
  clearscreenvm
local maplvldone,imowner1,cursorend1,imowner2,cursorend2,imowner3,cursorend3,imowner4,cursorend4

   mov al,whichlvl 
   cmp al,1
   jne notlvl1     
        SetMap 
        jmp maplvldone
   notlvl1:  
        SetMap2  
    jmp maplvldone                               
   maplvldone:
   
   
    mov al,RGameinv
    cmp al,0
    je imowner1
    ;here iam not owner
    MoveCursor 41d,23d
    jmp cursorend1
    imowner1:
    ;here i am owner       
    MoveCursor 1,23d      
    cursorend1:
   Display Player1Name
   
    mov al,RGameinv
    cmp al,0
    je imowner2
    ;here iam not owner
     MoveCursor 1,23d
    jmp cursorend2
    imowner2:
    ;here i am owner           
    MoveCursor 41d,23d
    cursorend2:                     
   Display Player2Name 
   
   ;--------
   MoveCursor 1d,29d
   Display BackToMainMenuMess 
   ;--------
   
    mov al,RGameinv
    cmp al,0
    je imowner3
    ;here iam not owner
    MoveCursor 41d,25d
    jmp cursorend3
    imowner3:
    ;here i am owner       
    MoveCursor 1,25d 
    cursorend3:
    
   Display Bullets
   mov cx,5
   mov ah,9 	;Display
   mov bh,0 	;Page 0
   mov al,0FEH  ;Letter D
   mov bl,0Ah ;Green (A) on white(F) background
   int 10h   
   
   
    mov al,RGameinv
    cmp al,0
    je imowner4
    ;here iam not owner
    MoveCursor 1,25d
    jmp cursorend4
    imowner4:
    ;here i am owner       
     MoveCursor 41d,25d  
    cursorend4:         
             
      
   Display Bullets
   mov cx,5
   mov ah,9 	;Display
   mov bh,0 	;Page 0
   mov al,0FEH  ;Letter D
   mov bl,0Ah ;Green (A) on white(F) background
   int 10h            
 endm StartGame