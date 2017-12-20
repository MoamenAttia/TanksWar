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


endgamewithscore macro
	pusha
	local greater,greater2,greater3,greater4,done,done2,done3,done4,macroend,imowner
	clearscreenVM
	mov cursorpos ,000fh
	movecursorshehab cursorpos
	mov al,RGameinv
    cmp al,0	
	je imowner
	printstring player2Name
	endline
	printstring Score
	mov al,SecondNameLastScore
	add al,'0'
	mov tmpmess,al
	printstring tmpmess
	space 
	mov al,SecondNameLastScore
	mov ah,FirstNameLastScore
	cmp al,ah
	ja greater
	printstring losermess
	jmp done
	greater:
	printstring winnermess
	done:
	endline 
	endline
	endline
	printstring player1Name
	endline
	printstring Score
	mov al,FirstNameLastScore
	add al,'0'
	mov tmpmess,al
	printstring tmpmess
	space 
	mov al,FirstNameLastScore
	mov ah,SecondNameLastScore
	cmp al,ah
	ja greater2
	printstring losermess
	jmp done2
	greater2:
	printstring winnermess
	done2:
	
    jmp macroend
    imowner:
	printstring player1Name
	endline
	printstring Score
	mov al,FirstNameLastScore
	add al,'0'
	mov tmpmess,al
	printstring tmpmess
	space 
	mov al,FirstNameLastScore
	mov ah,SecondNameLastScore
	cmp al,ah
	ja greater3
		printstring losermess
		jmp done3
	greater3:
	printstring winnermess
	done3:
	endline 
	endline
	endline
	printstring player2Name
	endline
	printstring Score
	mov al,SecondNameLastScore
	add al,'0'
	mov tmpmess,al
	printstring tmpmess
	space 
	mov al,SecondNameLastScore
	mov ah,FirstNameLastScore
	cmp al,ah
	ja greater4
		printstring losermess
		jmp done4
	greater4:
	printstring winnermess
	done4:
	macroend:
	mov cx,004ch 
    mov dx,4b40h
    mov ah,86h
    int 15h 
	popa
	jmp SartingFromMainMenu
endm endgamewithscore




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
endm recive 
;-----------------------
; Reading players names
ReadNames macro
pusha
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
popa
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
	mov RChatinv,0
	mov Rexitinv,0
	clearscreenTM
	justbeforegame
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

;justbeforegame( detecting lvl)
justbeforegame macro
local imowner,imnotowner,macroend,tryagain,lvlselectiondone,neither1nor2
	pusha
	mov al,RGameinv
	cmp al,0
	je imowner
	;here iam not owner
		mov ah,0
		mov al,12h
		int 10h
		mov word ptr StartPointX, 0d
		mov word ptr StartPointY, 459d
		mov word ptr EndPointX, 639d
		mov word ptr EndPointY,459d
		mov linecolor,3d
		call DrawLine
	
	
    ;----------------
	call calc_centre	
	call calc_square
    ;----------------   
    call tanka
    call draw_tank
    call tankb
    call draw_tank
		
		recive byte
		mov al,byte
		mov whichlvl,al
		tell_lvl_selction_for_Guest
		
		jmp macroend
	imowner:
	;here i am owner 
	clearscreenTM
	mov cursorpos,0014h
	movecursorshehab cursorpos
	printstring separatingline
	mov cursorpos ,100ah
	movecursorshehab cursorpos
	printstring lvlselectionmess
	tryagain:
	mov ah,0
	int 16h
	cmp ah,one
	jne maybe2
		mov whichlvl,1
		send whichlvl
		jmp lvlselectiondone
	maybe2:
	cmp ah,two
	jne neither1nor2
		mov whichlvl,2
		send whichlvl
		jmp lvlselectiondone
	neither1nor2:
	jmp tryagain
lvlselectiondone:
	tell_lvl_selction_for_host
	mov ah,0
	mov al,12h
	int 10h 
macroend:
	popa
	jmp playgame
endm justbeforegame



tell_lvl_selction_for_host macro
pusha
	mov cursorpos,0015h
	movecursorshehab cursorpos
	printstring chosenlvlselectionmess
	mov al,whichlvl
	add al,'0';
	mov tmpmess,al
	printstring tmpmess
	mov cursorpos,0000h
	movecursorshehab cursorpos
	;waiting
    mov cx,002dh 
    mov dx,0c6c0h
    mov ah,86h
    int 15h    
	 
popa
endm  tell_lvl_selction_for_host


tell_lvl_selction_for_Guest macro
local con,again
	pusha
	movecursorshehab notificationbaringame
	printstring chosenlvlselectionmess
	mov al,whichlvl
	add al,'0';
	mov tmpmess,al
	printstring tmpmess
	mov cursorpos,0000h
	movecursorshehab cursorpos
again:
    mov ah,1d
    int 16h 
    jz con  
        mov ah,0h
        int 16h
		jmp again
    con:
	
	;wating
    mov cx,002dh 
    mov dx,0c6c0h
    mov ah,86h
    int 15h    
	popa
endm  tell_lvl_selction_for_Guest
;--------------
; input_and_flowcontrol macro
; local imowner5,Dropend,con,notf4,chating,chatend,nothingrecived,notenterpress,imowner6,shootend,shootend_,noshoot,moveuser,moveend_
; local imowner7,imowner8,imowner9,no_move_user,notchatbyte,one_label,moveuser_,no_move_user_,chatingame,connnnn,moveend,remotebuffer
; local notexitbyte,noshoot_

; pusha
    ; mov al,RGameinv
    ; cmp al,0
    ; je imowner5
; ;     Drop GiftsX,GiftsY,tank2,tank1     
    ; jmp Dropend
    ; imowner5:
; ;        Drop GiftsX,GiftsY,tank1,tank2  
    ; Dropend:
    
  
    ; mov ah,1d
    ; int 16h 
    ; jnz con  
    ; jmp remotebuffer 
    ; con:                                  
    ; ;check if f444444444444444444444444444
    ; cmp ah,f4
    ; jne notf4
        ; mov ah,0d
        ; int 16h     
        ; mov al,ExitByte
        ; mov byte,al  
        ; send byte  
        ; endgamewithscore
    ; notf4:
    ; ;check if enterrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr 
    
    ; mov cl,imchating
    ; cmp cl,1 
    ; je chating
    
    ; cmp ah,Enter_key
    ; jne notenterpress
        ; mov imchating ,1 
        ; mov ah,0d
        ; int 16h    
        ; mov al,chatbyte
        ; mov byte,al
        ; send byte
        ; chating:
        ; SendChatVM 
        ; jmp remotebuffer 
    ; notenterpress:

    ; cmp ah,shoot_Space
    ; jnz noshoot
        ; mov al,RGameinv
        ; cmp al,0
        ; je imowner6         
        ; mov bx, offset shots2
        ; mov di, offset tank2     
        ; jmp shootend
        ; imowner6:
        ; mov bx, offset shots1
        ; mov di, offset tank1             
        ; shootend: 
        ; mov ah,0d
        ; int 16h                     
        ; call inputshots            
        ; mov byte,ah 
        ; send byte          
        ; jmp remotebuffer    
    ; noshoot: 
               
    ; cmp ah,right  
    ; jz moveuser  
    ; cmp ah,left
    ; jz moveuser 
    ; cmp ah,up
    ; jz moveuser
    ; cmp ah,down
    ; jz moveuser
                    
    ; jmp no_move_user    
    ; moveuser: 
      
   
    
    ; mov al,RGameinv
    ; cmp al,0   
    ; push ax
    ; je imowner7
    ; mov ah,0d
    ; int 16h      
    ; call tank_control_2
    ; ;reset centre 
    ; mov ax,lengthb
    ; mov dl,2
    ; div dl
    ; mov bx,tank2
    ; add bx,ax
    ; mov tank2+48,bx
    ; mov bx,tank2+2
    ; add bx,ax
    ; mov tank2+50,bx 
    ; jmp moveend
    ; imowner7: 
    ; mov ah,0d
    ; int 16h    
    ; call tank_control_1
    ; ;reset centre 
    ; mov ax,lengtha
    ; mov dl,2
    ; div dl
    ; mov bx,tank1
    ; add bx,ax
    ; mov tank1+48,bx
    ; mov bx,tank1+2
    ; add bx,ax
    ; mov tank1+50,bx        
    ; moveend:  
    ; pop ax
    ; mov byte,ah 
    ; send byte              
    ; jmp remotebuffer        
    ; no_move_user:  
                        
; remotebuffer:

	; mov dx,3fdh
	; in al,dx
	; and al,00000001b
	; jz nothingrecived
	; mov dx,3f8h
	; in al,dx     
	; mov ah,al  
    ; cmp ah,chatbyte
    ; jne notchatbyte
        ; mov al,rchatingame
        ; cmp al,1   
        ; je one_label 
           ; mov rchatingame,1 
           ; jmp nothingrecived ; chat byte wonot be used now          
        ; one_label: 
           ; mov rchatingame,0 
           ; jmp nothingrecived
    ; notchatbyte:
     ; mov al,rchatingame
     ; cmp al,1 
     ; je chatingame  
     
     
    ; ;chec exitttttttttttttttttttttttttttttttttttttttttt 
    ; ;cehck if chaaaaaaaaaaaat byte and RChatInGame Flag 
    ; cmp ah,exitbyte
    ; jne notexitbyte 
        ; mov byte,ah
        ; send byte  
        ; endgamewithscore
    ; notexitbyte:
                 
    ; cmp ah,shoot_Space
    ; jnz noshoot_
        ; mov al,RGameinv
        ; cmp al,1
        ; je imowner8 
        ; mov bx, offset shots2
        ; mov di, offset tank2     
        ; jmp shootend_
        ; imowner8:
        ; mov bx, offset shots1
        ; mov di, offset tank1             
        ; shootend_:             
        ; call inputshots                     
        ; jmp nothingrecived    
    ; noshoot_: 
               
    ; cmp ah,right  
    ; jz moveuser_  
    ; cmp ah,left
    ; jz moveuser_ 
    ; cmp ah,up
    ; jz moveuser_
    ; cmp ah,down
    ; jz moveuser_
                    
    ; jmp no_move_user_    
    ; moveuser_:    
    ; mov al,RGameinv
    ; cmp al,1
    ; je imowner9  
    ; call tank_control_2 
    ; ;reset centre 
    ; mov ax,lengthb
    ; mov dl,2
    ; div dl
    ; mov bx,tank2
    ; add bx,ax
    ; mov tank2+48,bx
    ; mov bx,tank2+2
    ; add bx,ax
    ; mov tank2+50,bx 
    ; jmp moveend_
    ; imowner9:  
    ; call tank_control_1
    ; ;reset centre 
    ; mov ax,lengtha
    ; mov dl,2
    ; div dl
    ; mov bx,tank1
    ; add bx,ax
    ; mov tank1+48,bx
    ; mov bx,tank1+2
    ; add bx,ax
    ; mov tank1+50,bx        
    ; moveend_:                           
    ; no_move_user_:
    ; jmp nothingrecived
    ; chatingame:  
    ; RecChatVM  
; nothingrecived:
    ; ;if entered bad key 
    ; mov ah,1d
    ; int 16h 
    ; jz connnnn  
		; cmp ah,right
		; je connnnn
		; cmp ah,left
		; je connnnn
		; cmp ah,up
		; je connnnn
		; cmp ah,down
		; je connnnn
		; cmp ah,Enter_key
		; je connnnn
		; cmp ah,shoot_Space
		; je connnnn
		; cmp ah,f4
		; je connnnn
        ; mov ah,0h
        ; int 16h
    ; connnnn:
      
    ; ;drawing tanks  
    ; call calc_centre
    ; call calc_square
    ; ;------------ 
    ; call tanka
    ; call draw_tank
    ; call tankb
    ; call draw_tank 
    ; ;-----------
    ; mov bx, offset shots2
    ; mov di, offset tank1    
    ; call process_shots
    
    ; mov bx, offset shots1
    ; mov di, offset tank2
    ; call process_shots 
    
    
    ; ;------------ 
     ; ; wait int
     ; mov cx,0  
     ; mov dx,7000d
     ; mov ah,86h
     ; int 15h       
    ; ;----------
    
    ; mov bx, offset shots1
    ; add bx,4
    ; call moveshots ;mov shots and clear old shots the from screen 
    ; mov bx, offset shots2
    ; add bx,4    
    ; call moveshots ;mov shots and clear old shots the from screen
; popa
; endm input_and_flowcontrol