include IO.inc
StartChatTM macro
	pusha
	local start,con,again1,donotscroll1,donotscroll2,chatdone,endchat
	clearscreenTM	
	
	printstring player1name
	mov player1mess,10d
	printstring player1mess
	mov player1mess,13d
	printstring player1mess
	getcursorpos player1cursorpos
	
	mov cursorpos,000Ah
	movecursorshehab cursorpos
	printstring separatingline
	printstring separatingline
	
	printstring player2name
	mov player2mess,10d
	printstring player2mess
	mov player2mess,13d
	printstring player2mess	
	getcursorpos player2cursorpos
	mov cursorpos,0017h
	movecursorshehab cursorpos
	printstring separatingline
	getcursorpos notbarcursorposingame
	printstring EndChatMess
	printstring player2name
	
	;screen ready for chat
	start:
		mov ah,1h
		int 16h 
		jz con
			mov ah,0h
			int 16h 
			cmp ah,F3
			jne endchat
				mov al,exitbyte
				mov byte,al
				send byte
				jmp chatdone
			endchat:
			push ax
			mov ax,player1cursorpos
			cmp al,0ah
			jnz donotscroll1
				mov ax,0601h
				mov bh,07h
				mov cx,0100h
				mov dx,094fh
				int 10h
				mov player1cursorpos,0009h
			donotscroll1:
			pop ax
			movecursorshehab player1cursorpos
			mov player1mess,al
			printstring player1mess ;print char in al
			getcursorpos player1cursorpos

			mov al,player1mess
			mov byte,al
			send byte
		con:
		mov dx,3fdh
		in al,dx
		and al,00000001b
		jz start
			push ax
			mov ax,player2cursorpos
			cmp al,22d
			jnz donotscroll2
				mov ax,0601h
				mov bh,07h
				mov cx,0d00h
				mov dx,164fh
				int 10h
				mov ah,02h
				mov dx,0000h
				xchg dh,dl
				mov bh,0
				int 10h
				mov player2cursorpos,0015h
			donotscroll2:
			pop ax		
		mov dx,3f8h
		in al,dx
		mov ch,exitbyte
		cmp al,ch
		je chatdone
		movecursorshehab player2cursorpos
		mov player2mess,al
		printstring player2mess ;print char in al
		getcursorpos player2cursorpos
	jmp start
	chatdone:
	popa
	jmp SartingFromMainMenu
endm StartChatTM

SendChatVM macro
local imowner,chatend,noXviolation,noXviolation2,breakchat
	pusha
	mov ah,0
	int 16h
	cmp ah,Enter_key
	je breakchat
	mov tmpmess,al
	mov byte,al
	send byte
	mov al,RGameinv
    cmp al,1
	je imowner
	movecursorshehab leftplayerchatingamepos
	mov dx ,leftplayerchatingamepos
	mov cx,leftplayerchatingamebound
	cmp ch,dh
	jne noXviolation
	mov ax,0600h
	mov bh,00h
	mov cx,1b01h
	mov dx,leftplayerchatingamebound
	xchg dh,dl
	int 10h
	mov leftplayerchatingamepos,011bh
 noXviolation: 
	movecursorshehab leftplayerchatingamepos
	printstring tmpmess
	getcursorpos leftplayerchatingamepos
    jmp chatend
    imowner: 
	movecursorshehab Rightplayerchatingamepos
	mov dx ,Rightplayerchatingamepos
	mov cx,Rightplayerchatingamebound
	cmp ch,dh
	jne noXviolation2
	mov ax,0600h
	mov bh,00h
	mov cx,1b29h
	mov dx,Rightplayerchatingamebound
	xchg dh,dl
	int 10h
	mov Rightplayerchatingamepos,291bh
 noXviolation2: 	
	movecursorshehab Rightplayerchatingamepos
	printstring tmpmess
	getcursorpos Rightplayerchatingamepos
	jmp chatend
	breakchat:
	mov imchating,0
	mov al,chatbyte
	mov byte,al
	send byte
	chatend:
	popa
endm SendChatVM

RecChatVM macro
	pusha
	local imowner,chatend,noXviolation,noXviolation2
	mov tmpmess,ah
	mov al,RGameinv
    cmp al,0
	je imowner
    ;here iam not owner
	movecursorshehab leftplayerchatingamepos
	mov dx ,leftplayerchatingamepos
	mov cx,leftplayerchatingamebound
	cmp ch,dh
	jne noXviolation2	
	mov ax,0600h
	mov bh,00h
	mov cx,1b01h
	mov dx,leftplayerchatingamebound
	xchg dh,dl
	int 10h
	mov leftplayerchatingamepos,011bh
 noXviolation2: 
	movecursorshehab leftplayerchatingamepos
	printstring tmpmess
	getcursorpos leftplayerchatingamepos
    jmp chatend
    imowner:
    ;here i am owner  
	movecursorshehab Rightplayerchatingamepos
	mov dx ,Rightplayerchatingamepos
	mov cx,Rightplayerchatingamebound
	cmp ch,dh
	jne noXviolation
	mov ax,0600h
	mov bh,00h
	mov cx,1b29h
	mov dx,Rightplayerchatingamebound
	xchg dh,dl
	int 10h
	mov Rightplayerchatingamepos,291bh
 noXviolation: 
	movecursorshehab Rightplayerchatingamepos
	printstring tmpmess
	getcursorpos Rightplayerchatingamepos
  chatend:
	popa
endm RecChatVM


