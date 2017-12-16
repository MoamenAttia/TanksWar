include IO.inc
StartChatTM macro
	pusha
	local start,con,again1,donotscroll1,donotscroll2
	clearscreenTM	
	
	printstring user1name+2
	mov user1mess,10d
	printstring user1mess
	mov user1mess,13d
	printstring user1mess
	getcursorpos user1cursorpos
	
	mov cursorpos,000Ah
	movecursorshehab cursorpos
	printstring separatingline
	printstring separatingline
	
	printstring user2name+2
	mov user2mess,10d
	printstring user2mess
	mov user2mess,13d
	printstring user2mess	
	getcursorpos user2cursorpos
	mov cursorpos,0017h
	movecursorshehab cursorpos
	printstring separatingline
	getcursorpos notbarcursorpos
	
	;screen ready for chat
	start:
		mov ah,1h
		int 16h 
		jz con
			mov ah,0h
			int 16h 
			push ax
			mov ax,user1cursorpos
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
				mov user1cursorpos,0009h
			donotscroll1:
			pop ax
			movecursorshehab user1cursorpos
			mov user1mess,al
			printstring user1mess ;print char in al
			getcursorpos user1cursorpos

			mov al,user1mess
			mov byte,al
			send byte
		con:
		mov dx,3fdh
		in al,dx
		and al,00000001b
		jz start
			push ax
			mov ax,user2cursorpos
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
				mov user2cursorpos,0015h
			donotscroll2:
			pop ax		
		mov dx,3f8h
		in al,dx
		movecursorshehab user2cursorpos
		mov user2mess,al
		printstring user2mess ;print char in al
		getcursorpos user2cursorpos
	jmp start
	popa
endm StartChatTM

; StartChatVM macro
	; pusha
	; clearscreenVM
	; printstring user1name+2
	; mov word ptr cursorpos,000bh
	; movecursorshehab cursorpos
	; printstring separatingline
	; printstring user2name+2	
	; mov word ptr cursorpos,0017h
	; movecursorshehab cursorpos
	; printstring separatingline

	; popa
; endm StartChatVM