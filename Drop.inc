include CheckT1.inc
include CheckT2.inc

;Drop
Drop macro GiftsX,GiftsY,Tank1,Tank2
local shiftrightX,shiftleftX,shiftrightY,shiftleftY,LOOPS,outerloop,innerloop,checks,placing,Position1,Position2,Position3,Position4
local firstgift,secondgift,thirdgift,fourthgift,black,lightCyan,lightblue,start,maybeSecond,maybeThird,maybeFourth,DefinitelyFifth
local label3,draw,label,label2,firstBlack,secondblack,thirdblack,FourthBlack,removeblack,imowner,firstbyteend,tryagain,tryagain1
local secondbyteend,imowner2
	pusha
	
	mov al,RGameinv
    cmp al,0
    je imowner
    ;here iam not owner
	tryagain1:
	recive byte
	mov al,byte
	cmp al,iwillsendRandomTime
	jne tryagain1
	mov byte,oksendit
	send byte
	recive byte
	mov al,byte
	mov randomtime,al
	jmp firstbyteend
    imowner:
    ;here i am owner
		tryagain:	
		mov al,iwillsendRandomTime
		mov byte,al
		send byte
		recive byte
		mov al,byte
		cmp al,oksendit
		jne tryagain
    firstbyteend:                     
	


 mov bx,offset GiftsX  
 mov Si,offset GiftsY
;'''''''''''''''''''''''''''''''''''''''''''''''
checks:
	Check_Passing_Through_Tank1 GiftsX,GiftsY,Tank1
	Check_Passing_Through_Tank2 GiftsX,GiftsY,Tank2
	jmp LOOPS
placing:
   push ax
   mov ah,2ch
   int 21h
   pop ax
   and dh,00001111b

	mov al,RGameinv
	cmp al,0
	je imowner2
	;here iam not owner
	mov dh,randomtime
	jmp secondbyteend
	imowner2:
	;here i am owner 
	mov byte,dh ;sending time
	send byte
	secondbyteend: 
   cmp dh,03d
   jbe position1
   cmp dh,07d
   jbe position2
   cmp dh,11d
   jmp position3
   jmp position4
   ;//////////////////////////////////////
    position1:
    mov bx,offset GiftsX  
    mov Si,offset GiftsY  
	
    mov word ptr [bx],600d
    mov word ptr [bx+2],610d
    mov word ptr [bx+4],605d
    mov word ptr [bx+6],11b
 
    mov word ptr [bx+8],5d
    mov word ptr [bx+10],15d
    mov word ptr [bx+12],10d
    mov word ptr [bx+14],11b
   
    mov word ptr [bx+16],150d
    mov word ptr [bx+18],160d
    mov word ptr [bx+20],155d
    mov word ptr [bx+22],11b
    
    mov word ptr [bx+24],460d
    mov word ptr [bx+26],470d
    mov word ptr [bx+28],465d
    mov word ptr [bx+30],11b
    
    mov word ptr [bx+32],315d
    mov word ptr [bx+34],325d
    mov word ptr [bx+36],320d
    mov word ptr [bx+38],11b
    
    
  
    mov word ptr [si],315d
    mov word ptr [si+2],325d
    mov word ptr [si+4],320d
    mov word ptr [si+6],11b
    
    
    mov word ptr [si+8],5d
    mov word ptr [si+10],15d
    mov word ptr [si+12],10d
    mov word ptr [si+14],11b
    
    
    mov word ptr [si+16],170d
    mov word ptr [si+18],180d
    mov word ptr [si+20],175d
    mov word ptr [si+22],11b
    
    mov word ptr [si+24],170d
    mov word ptr [si+26],180d
    mov word ptr [si+28],175d
    mov word ptr [si+30],11b
    
    mov word ptr [si+32],50d
    mov word ptr [si+34],60d
    mov word ptr [si+36],55d
    mov word ptr [si+38],11b
   
Check_Passing_Through_Tank1 GiftsX,GiftsY,Tank1
Check_Passing_Through_Tank2 GiftsX,GiftsY,Tank2	
	jmp LOOPS
;   ; //////////////////////// 
position2:
   mov bx,offset GiftsX  
   mov Si,offset GiftsY
    

    mov word ptr [bx],5d
    mov word ptr [bx+2],15d
    mov word ptr [bx+4],10d
    mov word ptr [bx+6],11b
    
    
    mov word ptr [bx+8],600d
    mov word ptr [bx+10],610d
    mov word ptr [bx+12],605d
    mov word ptr [bx+14],11b
    
    mov word ptr [bx+16],5d
    mov word ptr [bx+18],15d
    mov word ptr [bx+20],10d
    mov word ptr [bx+22],11b
    
    mov word ptr [bx+24],600d
    mov word ptr [bx+26],610d
    mov word ptr [bx+28],605d
    mov word ptr [bx+30],11b
    
    mov word ptr [bx+32],315d
    mov word ptr [bx+34],325d
    mov word ptr [bx+36],320d
    mov word ptr [bx+38],11b
    
    
    
    mov word ptr [si],5d
    mov word ptr [si+2],15d
    mov word ptr [si+4],10d
    mov word ptr [si+6],11b
    
    
    mov word ptr [si+8],5d
    mov word ptr [si+10],15d
    mov word ptr [si+12],10d
    mov word ptr [si+14],11b
    
    
    mov word ptr [si+16],315d
    mov word ptr [si+18],325d
    mov word ptr [si+20],320d
    mov word ptr [si+22],11b
    
    mov word ptr [si+24],315d
    mov word ptr [si+26],325d
    mov word ptr [si+28],320d
    mov word ptr [si+30],11b
    
    mov word ptr [si+32],170d
    mov word ptr [si+34],180d
    mov word ptr [si+36],175d
    mov word ptr [si+38],11b 
Check_Passing_Through_Tank1 GiftsX,GiftsY,Tank1
Check_Passing_Through_Tank2 GiftsX,GiftsY,Tank2
	jmp LOOPS
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    position3:
     mov bx,offset GiftsX  
      mov Si,offset GiftsY
   
    mov word ptr[bx],600d
    mov word ptr[bx+2],610d
    mov word ptr[bx+4],605d
    mov word ptr[bx+6],11b
    
    
    mov word ptr[bx+8],5d
    mov word ptr[bx+10],15d
    mov word ptr[bx+12],10d
    mov word ptr[bx+14],11b
    
    mov word ptr[bx+16],280d
    mov word ptr[bx+18],290d
    mov word ptr[bx+20],285d
    mov word ptr[bx+22],11b
    
    mov word ptr[bx+24],505d
    mov word ptr[bx+26],515d
    mov word ptr[bx+28],510d
    mov word ptr[bx+30],11b
    
    mov word ptr[bx+32],400d
    mov word ptr[bx+34],410d
    mov word ptr[bx+36],405d
    mov word ptr[bx+38],11b
    
    
    
    mov word ptr[si],5d
    mov word ptr[si+2],15d
    mov word ptr[si+4],10d                            
    mov word ptr[si+6],11b
    
    
    mov word ptr[si+8],315d
    mov word ptr[si+10],325d
    mov word ptr[si+12],320d
	mov word ptr [si+14],11b
     
  
   mov word ptr[si+16],60d
   mov word ptr[si+18],70d
   mov word ptr[si+20],65d
   mov word ptr[si+22],11b
   
   mov word ptr[si+24],280d
   mov word ptr[si+26],290d
   mov word ptr[si+28],285d
   mov word ptr[si+30],11b
   
    mov word ptr[si+32],60d
    mov word ptr[si+34],70d
    mov word ptr[si+36],65d
    mov word ptr[si+38],11b
    
Check_Passing_Through_Tank1 GiftsX,GiftsY,Tank1
Check_Passing_Through_Tank2 GiftsX,GiftsY,Tank2
jmp LOOPS
position4: 
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
Check_Passing_Through_Tank1 GiftsX,GiftsY,Tank1
Check_Passing_Through_Tank2 GiftsX,GiftsY,Tank2	
  
  
	LOOPS: 
	 mov bx,offset GiftsX  
    mov Si,offset GiftsY 
	
	mov di,01d
	outerloop:
	
	cmp di,1
	je firstGift
	jmp maybeSecond
	firstGift:
	cmp [bx+6],00b
	je Black
	jmp lightCyan
	Black:
	mov al,0000b
	jmp label3
	lightblue:
	mov al,1011b
	jmp label3

    maybeSecond:
	cmp di,2
	je SecondGift
	jmp maybeThird
	SecondGift:
	cmp [bx+6],00b
	je Black
	jmp lightCyan
	lightCyan:
	mov al,1001b
	jmp label3


	maybeThird:
	cmp di,3
	je ThirdGift
	jmp maybeFourth
	ThirdGift:
	cmp [bx+6],00b
	je Black
	jmp lightblue


	maybeFourth:
	cmp di,4
	je FourthGift
	jmp DefinitelyFifth
	FourthGift:
	cmp [bx+6],00b
	je Black
	jmp lightCyan


	DefinitelyFifth:
	cmp [bx+6],00b
	je Black
	jmp lightCyan

	
	label3:
	mov cx,[bx]
	mov dx,[si] 
	
	innerloop:
	push ax 
	push bx 
	mov bh,00h
	mov ah,0dh 	
	int 10h
	cmp al,00000000b
	je draw
	cmp al,1001b
	je draw
	cmp al,1011b
	je draw
	pop bx 
	pop ax
	inc cx
	cmp cx,[bx+2]
	je label 
	jmp innerloop
	draw:
	pop bx
	pop ax
	
	push bx
	mov bh,00
    mov ah,0ch
	int 10h
	pop bx
	inc cx
	cmp cx,[bx+2]
	je label
	jmp innerloop
	label:
	cmp dx,[si+2]
	je label2
	sub cx,10d
	inc dx    
	jmp innerloop
	label2:
	add bx,08d
	add si,08d
	inc di 
	cmp di,05d
	jbe outerloop
	
	mov bx,offset GiftsX
	mov Si,offset GiftsY
	cmp [bx+6],00b
	je firstBlack
	jmp start
	firstBlack:
	cmp [bx+14],00b
	je SecondBlack
	Jmp start
	SecondBlack:
	cmp [bx+22],00b
	je ThirdBlack
	Jmp start
	ThirdBlack:
	cmp [bx+30],00b
	je FourthBlack
	Jmp start
	FourthBlack:
	cmp [bx+38],00b
	je RemoveBlack
	Jmp start
	RemoveBlack:
	mov [bx+6],11b
	mov [bx+14],11b
	mov [bx+22],11b
	mov [bx+30],11b
	mov [bx+38],11b
	jmp placing
	start:
	popa
endm Drop
