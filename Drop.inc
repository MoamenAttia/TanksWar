include CheckT1.inc

include CheckT2.inc

;Drop
Drop macro GiftsX,GiftsY,Tank1,Tank2
local shiftrightX,shiftleftX,shiftrightY,shiftleftY,LOOPS,outerloop,innerloop
	pusha
	 
       
   mov bx,offset GiftsX  
   mov Si,offset GiftsY

  
   mov [bx+6],11b


  
   mov [bx+14],11b

   
   mov [bx+22],11b

 
   mov [bx+30],11b

  
   mov [bx+38],11b


   

   mov [si+6],11b
   

   mov [si+14],11b


  
   mov [si+22],11b

  
   mov [si+30],11b

   
   mov [si+38],11b




	Check_Passing_Through_Tank1 GiftsX,GiftsY,Tank1
	Check_Passing_Through_Tank2 GiftsX,GiftsY,Tank2
	
   mov bx,offset GiftsX  
   mov Si,offset GiftsY
	LOOPS: 
	mov di,05d
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
	lightCyan:
	mov al,1011b
	jmp label3

    maybeSecond:
	cmp di,2
	je SecondGift
	jmp maybeThird
	SecondGift:
	cmp [bx+6],00b
	je Black
	jmp lightBlue
	lightBlue:
	mov al,1001b
	jmp label3


	maybeThird:
	cmp di,3
	je ThirdGift
	jmp maybeFourth
	ThirdGift:
	cmp [bx+6],00b
	je Black
	jmp lightCyan


	maybeFourth:
	cmp di,4
	je FourthGift
	jmp DefinitelyFifth
	FourthGift:
	cmp [bx+6],00b
	je Black
	jmp lightBlue


	DefinitelyFifth:
	cmp [bx+6],00b
	je Black
	jmp lightCyan

	
	label3:
	mov cx,[bx]
	mov dx,[si] 
	
	innerloop:
	mov ah,0ch
	push bx 
	mov bh,00	
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
	dec di
	jnz outerloop
	
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
	jmp LOOPS
	start:
	popa
endm Drop
