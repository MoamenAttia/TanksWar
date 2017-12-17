;-----------------MACROS-------------------
;*PrintString
PrintString macro MyMessage
	pusha
	mov dx,offset MyMessage
	mov ah,9h
	int 21h
	popa
endm PrintString
;----------------------------------------------------
;*PrintChar print char in ascii code in al (white on black)
PrintChar macro
pusha
mov ah,9
mov bh,0
mov cx,1
mov bl,00fh
int 10h
popa
endm PrintChar
;---------------------------------------------------
;*PrintUint : print number in ax upto 2559
PrintUInt macro
    pusha
    local con
    local printloop
    mov bh,10
    mov cx,0
    con:
        inc cl
        div bh
        xchg ah,al
        mov ch,ah
        xor ah,ah
        push ax
        mov al,ch 
        and al,al
    jnz con
    xor ch,ch
    printloop:
        pop dx
        add dl,48
        mov ah,2
        int 21h
    loop printloop
    popa
endm PrintUInt
;---------------------------------------------------
;*EndLine
EndLine macro
	pusha 
	mov ah,2
	mov dl,10
	int 21h
	mov dl,13
	int 21h
	popa
endm EndLine
;---------------------------------------------------
;*Space
Space macro
	pusha 
	mov ah,2
	mov dl,' '
	int 21h
	popa
endm Space
;---------------------------------------------------
;*inputstring
inputstring macro buffer
	pusha
	mov dx,offset buffer
	mov ah,0ah
	int 21h
	popa
endm inputstring 
;-----------------------------------------------------
;*inputint read string transfere to int save in ax
inputint macro integar
	local extract
	inputstring integar
	xor ax,ax
	mov al,integar + 1
	mov bx ,offset integar
	inc bx
	add bx,ax
	mov cx,5
	cmp integar+1,5
	jg donothing
	mov cl,integar+1 
	donothing:
	mov di,cx
	extract:
		xor ax,ax
		mov al,[bx]
		sub al,48d
		push cx
		m10:
		cmp cx,di
		jz stop
		mov dx,0ah
		mul dx
		inc cx			
		jmp m10
		stop:
		pop cx
		add si,ax
		dec bx
	loop extract
	mov ax,si	
 endm inputint

;---------------------------------------------------------
;*clearscreen in textmode 
clearscreenTM macro
	pusha
	mov ax,0600h
	mov bh,07h
	mov cx,0
	mov dx,184fh
	int 10h
	mov ah,02h
	mov dx,0000h
	xchg dh,dl
	mov bh,0
	int 10h
	popa
endm clearscreenTM
;-----------------------------------------------------------
;*clearscreen in videomode 
clearscreenVM macro
	pusha
	mov ax,0600h
	mov bh,00h
	mov cx,0
	mov dx,184fh
	int 10h
	mov ah,02h
	mov dx,0000h
	xchg dh,dl
	mov bh,0
	int 10h
	popa
endm clearscreenVM
;------------------------------------------------------------
;*moving cursor to pos
movecursorshehab macro cursorpos
	pusha
	mov ah,02h
	mov dx,cursorpos
	xchg dh,dl
	mov bh,0
	int 10h
	popa
endm movecursor
;*----------------------------------------------------------
inputusername macro username
	pusha
	inputstring username
	mov bl, username+1
	xor bh,bh
	mov si,bx  
	mov bx,offset username+2
	mov [bx][si],':'
	popa
endm inputusername
;*----------------------------------------------------------
;get cursor postion and put it in memory
getcursorpos macro cursorpos
	pusha
	mov ah,3h
	mov bh,0h
	int 10h
	xchg dh,dl
	mov cursorpos,dx
	popa
endm getcursorpos
;----------------------------------------
;display second mainmenu questions
DisplayQuestions macro
	pusha
    mov cursorpos,000eh
    movecursorshehab cursorpos
    Display Question1 
    mov cursorpos,000fh
    movecursorshehab cursorpos
    Display Question2   
    mov cursorpos,0010h
    movecursorshehab cursorpos
    Display Question3	
	mov cursorpos,0014h
	movecursorshehab cursorpos
	Display separatingline
	getcursorpos notbarcursorposinmainmenu
	popa
endm DisplayQuestions




exitgame macro
local lol
	pusha
	clearscreenTM
	mov cursorpos ,280ah
	movecursorshehab cursorpos
	printstring ExitProgramMess
	popa
	lol:
	jmp lol
endm exitgame

IRecGameInvMess macro
local donotscroll
	pusha
	movecursorshehab notbarcursorposinmainmenu
	getcursorpos cursorpos
	mov ax,cursorpos
	cmp al,23d
	jnz donotscroll
		mov ax,0601h
		mov bh,07h
		mov cx,1500h
		mov dx,164fh
		int 10h
		mov notbarcursorposinmainmenu,0016h
	donotscroll:
	movecursorshehab notbarcursorposinmainmenu  
	mov tmpmess,'-'
	printstring tmpmess
	mov tmpmess,' '
	printstring tmpmess           
	printstring player2name
	printstring ReplyingToGameInvitationMessage 
	endline
	getcursorpos notbarcursorposinmainmenu	
	popa
endm IRecGameInvMess

ISendGameInvMess macro
	local donotscroll
	pusha
	movecursorshehab notbarcursorposinmainmenu
	getcursorpos cursorpos
	mov ax,cursorpos
	cmp al,23d
	jnz donotscroll
		mov ax,0601h
		mov bh,07h
		mov cx,1500h
		mov dx,164fh
		int 10h
		mov notbarcursorposinmainmenu,0016h
	donotscroll:
	movecursorshehab notbarcursorposinmainmenu
	printstring  GameInvitationMessage 
	printstring player2Name
	endline
	getcursorpos notbarcursorposinmainmenu 
	popa
endm ISendGameInvMess


IRecChatInvMess macro
local donotscroll
	pusha
	movecursorshehab notbarcursorposinmainmenu
	getcursorpos cursorpos
	mov ax,cursorpos
	cmp al,23d
	jnz donotscroll
		mov ax,0601h
		mov bh,07h
		mov cx,1500h
		mov dx,164fh
		int 10h
		mov notbarcursorposinmainmenu,0016h
	donotscroll:
	movecursorshehab notbarcursorposinmainmenu  
	mov tmpmess,'-'
	printstring tmpmess
	mov tmpmess,' '
	printstring tmpmess           
	printstring player2name
	printstring ReplyingToChatInvitationMessage 
	endline
	getcursorpos notbarcursorposinmainmenu
	popa
endm IRecChatInvMess


ISendChatInvMess macro
local donotscroll
	pusha
	movecursorshehab notbarcursorposinmainmenu
	getcursorpos cursorpos
	mov ax,cursorpos
	cmp al,23d
	jnz donotscroll
		mov ax,0601h
		mov bh,07h
		mov cx,1500h
		mov dx,164fh
		int 10h
		mov notbarcursorposinmainmenu,0016h
	donotscroll:
	movecursorshehab notbarcursorposinmainmenu
	printstring  ChatInvitationMessage 
	printstring player2Name
	endline
	getcursorpos notbarcursorposinmainmenu 
	popa
endm ISendChatInvMess

;--------------------------------------serial--------------------------------
;serial macros
send macro byte ; sending with wating
	local again
	push ax
	push dx
	again:
		mov dx,3fdh
		in al,dx
		and al,00100000b
	jz again
	mov al,byte
	mov dx,3f8h
	out dx,al
	pop dx
	pop ax
endm send 
;-----------------
; recivomg with wating
recive macro byte
	local again
	push ax
	push dx
	again:
		mov dx,3fdh
		in al,dx
		and al,00000001b
	jz again
	mov dx,3f8h
	in al,dx
	mov byte,al
	pop dx
	pop ax
endm send 
;-----------------------
; Reading players names
ReadNames macro near
local EnterFirstNameAgain,no_more_send,no_more_recive,ExchangeNames
    EnterFirstNameAgain:
        xor bx,bx    
        mov ah,2
        mov dl,0
        mov dh,14d
        int 10h
        Display PlayerMessage 
		getcursorpos cursorpos
		endline
		Display EnterNameMess
		movecursorshehab cursorpos
        mov ah,0AH
        mov dx,offset InDATA
        int 21h
        mov bx,offset InData+2
        mov Si,offset player1Name
        mov ax,[bx]
        sub ax,'0'
        cmp al,9
    jle EnterFirstNameAgain  
    
    xor ch,ch
    mov cl,InData+1
    mov si,offset InData+2
    mov di,offset player1Name
    rep movsb
    
	;sending and reciveing one by one
    mov cl,InData+1 
    mov byte,cl
    send byte  

	recive byte  ;first recive name length
    mov ch,byte 
	 
    mov bx,offset InData+2
	mov si,offset player2Name
    ExchangeNames:	
		cmp cl,00h
		jz no_more_send
			mov al,[bx]
			mov byte,al
			send byte
			inc bx
			dec cl
		no_more_send:
		
		cmp ch,00h
		jz no_more_recive
			recive byte
			mov al,byte
			mov [si],al
			inc si
			dec ch
		no_more_recive:
		cmp cx,0000h
    jnz ExchangeNames 
endm ReadNames
;------------------------------
;processinganswers 
ProcessingAnswers macro
local NoChatToTheOther,donotscroll,exit,nothingrecived,mainloop,notexitbyte,notexitbyte2,notexitbyte3,chkrecacc,notgamebyte,notgamebyte2,startchating,gamesection,NoExit
	pusha
	;---------------------
    mainloop:
    mov al,RChatinv
	cmp al,1
	je  chkrecacc
	
	
	mov dx,3fdh
	in al,dx
	and al,1h
	
	jz nothingrecived
	recive byte
	mov al,byte
	
	cmp al,gamebyte
	jne notgamebyte
		mov al,Rgameinv
		cmp al,1
		je chkgameacc
		mov Rgameinv,1
		mov RChatinv,0
		mov Rexitinv,0
		IRecGameInvMess	
		jmp chkgameacc
	notgamebyte:
	
	cmp al,exitbyte
	jne notexitbyte
		mov Rexitinv,0
		mov RChatinv,0
		mov Rexitinv,0
		exitgame
	notexitbyte:
	
	mov RChatinv,1
	;-----------------printing
	IRecChatInvMess
	;-----------------
	   
	chkrecacc:  
    mov ah,1
	int 16h
	jz NoChatToTheOther
	cmp ah,F1
	jne NoChatToTheOther
	mov ah,0
	int 16h
	mov al,RChatinv
	cmp al,1
	je startchating
	nothingrecived:
	
	mov ah,1
	int 16h
	jz NoChatToTheOther
	cmp ah,F1
	jne NoChatToTheOther
	mov ah,0
	int 16h
	
	mov al,ChatByte
	mov Byte,al
	Send Byte
	;clearing all other Rinvs
	mov Rgameinv,0
	mov RChatinv,0
	mov Rexitinv,0
	
	ISendChatInvMess
	
	recive byte
	mov al,byte
	
	cmp al,gamebyte
	jne notgamebyte2
		mov al,Rgameinv
		cmp al,1
		je chkgameacc
		mov Rgameinv,1
		mov RChatinv,0
		mov Rexitinv,0
		IRecGameInvMess
		jmp chkgameacc
	notgamebyte2:
		
	cmp al,exitbyte
	jne notexitbyte2
		mov Rexitinv,0
		mov RChatinv,0
		mov Rexitinv,0
		exitgame
	notexitbyte2:
	
	cmp al,chatbyte 
	
	jne NoChatToTheOther
		mov Rgameinv,0
		mov RChatinv,0
		mov Rexitinv,0	
	    startchattm   
		jmp exit
	jmp NoChatToTheOther
startchating: 
    mov RChatinv,0
	mov Rgameinv,0
	mov Rexitinv,0
	mov al,ChatByte
	mov Byte,al
	Send Byte
	startchattm
	NoChatToTheOther:
;--------------------------------------------------------------------------------------------------------------------------------------------------
gamesection:
	mov al,Rgameinv
	cmp al,1
	jne  nogameinvcome
	chkgameacc:
		mov ah,1
		int 16h
		jz NoGameWithOther
		cmp ah,F2
		jne NoGameWithOther
		mov ah,0
		int 16h
		jmp startplayingafteracc
	nogameinvcome:
	
	
	mov ah,1
	int 16h
	jz NoGameWithOther
	cmp ah,F2
	jne NoGameWithOther
	mov ah,0
	int 16h
	
	mov al,GameByte
	mov Byte,al
	Send Byte
	mov Rgameinv,0
	mov RChatinv,0
	mov Rexitinv,0
	ISendGameInvMess
	recive byte
	mov al,byte
	cmp al,chatbyte
	jne notchatbyte3
		mov al,RChatinv
		cmp al,1
		je notchatbyte3
		IRecChatInvMess
		mov RChatinv,1
		mov Rgameinv,0
		mov Rexitinv,0
	jmp  mainloop
	notchatbyte3:
	
	cmp al,exitbyte
	jne notexitbyte3
		mov Rexitinv,0
		mov RChatinv,0
		mov Rexitinv,0
		exitgame
	notexitbyte3:
jmp startplaying	

startplayingafteracc:	
	mov al,GameByte
	mov Byte,al
	Send Byte
	
startplaying:
	mov Rgameinv,0
	mov RChatinv,0
	mov Rexitinv,0
	clearscreenTM
	
	printstring player1Name
	printstring player1Name
	printstring player1Name
	printstring player2Name
	printstring player2Name
	printstring player2Name
	
	;;;;;;;;;;;;;;;;;;;;;;;;;game logic
	jmp mainloop
NoGameWithOther:
	
	mov ah,1
	int 16h
	jz NoExit
	cmp ah,Escape
	jne NoExit
	mov ah,0
	int 16h
	mov al,exitbyte
	mov byte,al
	send byte
	mov Rexitinv,0
	mov RChatinv,0
	mov Rexitinv,0
	exitgame
	NoExit:
	
	jmp mainloop 
	exit:
	popa
endm ProcessingAnswers



