include IO.inc
StartChatTM macro
	pusha
	local start,con,again1,donotscroll1,donotscroll2
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
	getcursorpos notbarcursorpos
	printstring EndChat
	printstring player2name
	
	;screen ready for chat
	start:
		mov ah,1h
		int 16h 
		jz con
			mov ah,0h
			int 16h 
			push ax
			mov ax,player1cursorpos
			cmp al,0ah
			jnz donotscroll1
				mov ax,0601h
				mov bh,07h
				mov cx,0100h
				mov dx,094fh
				int 10h
				mov ah,02h
				mov dx,0000h
				mov bh,0
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
		movecursorshehab player2cursorpos
		mov player2mess,al
		printstring player2mess ;print char in al
		getcursorpos player2cursorpos
	jmp start
	popa
endm StartChatTM

; StartChatVM macro
	; pusha
	; clearscreenVM
	; printstring player1name+2
	; mov word ptr cursorpos,000bh
	; movecursorshehab cursorpos
	; printstring separatingline
	; printstring player2name+2	
	; mov word ptr cursorpos,0017h
	; movecursorshehab cursorpos
	; printstring separatingline

	; popa
; endm StartChatVM