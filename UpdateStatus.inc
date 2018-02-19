include MoveCursor.inc
UpdateStatus MACRO
Local SomeLabel,SomeLabel2,DrawGame,SecondisWinner,FirstisWinner,IncrementTank1,IncrementTank2,AboveAll,ContinueTheGame,EndTheGame2,EndTheGame1,RemoveOneBullet1,DrawOneBullet1,RemoveOneBullet,DrawOneBullet,TanksLives,CalculateBulletsForTank2
Local SomeLabel_,SomeLabel2_,DrawGame_,SecondisWinner_,FirstisWinner_,IncrementTank1_,IncrementTank2_,AboveAll_,ContinueTheGame_,EndTheGame2_,EndTheGame1_,RemoveOneBullet1_,DrawOneBullet1_,RemoveOneBullet_,DrawOneBullet_,TanksLives_,CalculateBulletsForTank2_
local macroend,imowner
	pusha
    mov al,RGameinv
    cmp al,0
    je imowner
	;here imnot owner
	mov bl,FirstNameLastLife
		mov Ax,tank2+52
		mov al,ah
		sub bl,al
		cmp bl,0
			je SomeLabel_
		mov FirstNameLastLife,al
		MoveCursor 41d,24d
		Display Lives
		mov cx,7d
		mov ah,9 	;Display
		mov bh,0 	;Page 0
		mov al,03  ;Letter D
		mov bl,00h ;Green (A) on white(F) background
		int 10h

		SomeLabel_:
		mov bl,SecondNameLastLife
		mov Ax,tank1+52
		mov al,ah
		sub bl,al
		cmp bl,0
			je SomeLabel2_
		mov SecondNameLastLife,al
		MoveCursor 1d,24d
		Display Lives
		mov cx,7d
		mov ah,9 	;Display
		mov bh,0 	;Page 0
		mov al,03  ;Letter D
		mov bl,00h ;Green (A) on white(F) background
		int 10h
		SomeLabel2_:

		mov ax,shots2    ;max size
		mov bx,shots2+2  ;in the map 
		sub ax,bx  ; ax have the actual bullets player one have
		cmp al,	FirstNameLastBullets
			jg DrawOneBullet_

		cmp al,	FirstNameLastBullets
			jl RemoveOneBullet_
		jmp CalculateBulletsForTank2_
		DrawOneBullet_:
			mov cl,FirstNameLastBullets
			mov FirstNameLastBullets,al
			add cl,50d
			MoveCursor cl,25d
			XOR BX,BX
			mov cx,1d
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,0FEH  ;Letter D
			mov bl,0Ah ;Green (A) on white(F) background
			int 10h
			jmp CalculateBulletsForTank2_
		RemoveOneBullet_:
			mov FirstNameLastBullets,al
			add al,50d
			MoveCursor al,25d
			XOR BX,BX
			mov cx,1d
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,0FEH  ;Letter D
			mov bl,00h ;Green (A) on white(F) background
			int 10h
		CalculateBulletsForTank2_:
		mov ax,shots1    ;max size
		mov bx,shots1+2  ;in the map 
		sub ax,bx  ; ax have the actual bullets player one have
		cmp al,	SecondNameLastBullets
			jg DrawOneBullet1_

		cmp al,	SecondNameLastBullets
			jl RemoveOneBullet1_
		jmp TanksLives_
		DrawOneBullet1_:
			mov cl,SecondNameLastBullets
			mov SecondNameLastBullets,al
			add cl,10d
			MoveCursor cl,25d
			XOR BX,BX
			mov cx,1d
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,0FEH  ;Letter D
			mov bl,0Ah ;Green (A) on white(F) background
			int 10h
			jmp TanksLives_
		RemoveOneBullet1_:
			mov SecondNameLastBullets,al
			add al,10d
			MoveCursor al,25d
			XOR BX,BX
			mov cx,1d
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,0FEH  ;Letter D
			mov bl,00h ;Green (A) on white(F) background
			int 10h

		TanksLives_:

		mov Ax,tank2+52
		mov al,ah
		xor cx,cx

		MoveCursor 41d,24d
		Display Lives
		XOR BX,BX
		mov cl,FirstNameLastLife
		mov ah,9 	;Display
		mov bh,0 	;Page 0
		mov al,03  ;Letter D
		mov bl,00Ah ;Green (A) on white(F) background
		int 10h

		mov Ax,tank1+52
		mov al,ah
		xor cx,cx
		
		MoveCursor 1d,24d

		Display Lives
		XOR BX,BX
		mov cl,SecondNameLastLife
		mov ah,9 	;Display
		mov bh,0 	;Page 0
		mov al,03  ;Letter D
		mov bl,00Ah ;Green (A) on white(F) background
		int 10h

		mov Ax,tank2+52
		mov al,ah
		mov bx,tank1+52
		mov bl,bh

		cmp bx,0
			je IncrementTank1_
		cmp ax,0	
			je IncrementTank2_
		jmp AboveAll_
		IncrementTank1_:
			inc FirstNameLastScore
			jmp DrawGame_
		IncrementTank2_:
			inc SecondNameLastScore
		DrawGame_:
			mov FirstNameLastLife,7d
			mov SecondNameLastLife,7d
			mov Ax,tank2+52
			mov ah,07d
			mov tank2+52,Ax
			mov Ax,tank1+52
			mov ah,07d
			mov tank1+52,Ax
		AboveAll_:
			MoveCursor 41d,26d
			Xor Bx,Bx
			Display Score
			mov cl,1
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,FirstNameLastScore 
			add al,'0'
			mov bl,00Ah ;Green (A) on white(F) background
			int 10h

			MoveCursor 1d,26d
			Xor Bx,Bx
			Display Score
			Xor Bx,Bx
			mov cl,1
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,SecondNameLastScore 
			add al,'0'
			mov bl,00Ah ;Green (A) on white(F) background
			int 10h

		mov dl,FirstNameLastScore
		cmp dl,3d
			je EndTheGame1_

		mov dl,SecondNameLastScore
		cmp dl,3d
			je EndTheGame2_
		jmp ContinueTheGame_
		EndTheGame1_:
        mov al,ExitByte
        mov byte,al  
        send byte 		
		endgamewithscore
		jmp ContinueTheGame_
		EndTheGame2_:
        mov al,ExitByte
        mov byte,al  
        send byte 		
		endgamewithscore
		ContinueTheGame_:
;----------------------------------------------------------------------------------------------------------------
    jmp macroend
    imowner:
    ;here i am owner       
	mov bl,FirstNameLastLife
		mov Ax,tank1+52
		mov al,ah
		sub bl,al
		cmp bl,0
			je SomeLabel
		mov FirstNameLastLife,al
		MoveCursor 1d,24d
		Display Lives
		mov cx,7d
		mov ah,9 	;Display
		mov bh,0 	;Page 0
		mov al,03  ;Letter D
		mov bl,00h ;Green (A) on white(F) background
		int 10h

		SomeLabel:
		mov bl,SecondNameLastLife
		mov Ax,tank2+52
		mov al,ah
		sub bl,al
		cmp bl,0
			je SomeLabel2
		mov SecondNameLastLife,al
		MoveCursor 41d,24d
		Display Lives
		mov cx,7d
		mov ah,9 	;Display
		mov bh,0 	;Page 0
		mov al,03  ;Letter D
		mov bl,00h ;Green (A) on white(F) background
		int 10h
		SomeLabel2:

		mov ax,shots1    ;max size
		mov bx,shots1+2  ;in the map 
		sub ax,bx  ; ax have the actual bullets player one have
		cmp al,	FirstNameLastBullets
			jg DrawOneBullet

		cmp al,	FirstNameLastBullets
			jl RemoveOneBullet
		jmp CalculateBulletsForTank2
		DrawOneBullet:
			mov cl,FirstNameLastBullets
			mov FirstNameLastBullets,al
			add cl,10d
			MoveCursor cl,25d
			XOR BX,BX
			mov cx,1d
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,0FEH  ;Letter D
			mov bl,0Ah ;Green (A) on white(F) background
			int 10h
			jmp CalculateBulletsForTank2
		RemoveOneBullet:
			mov FirstNameLastBullets,al
			add al,10d
			MoveCursor al,25d
			XOR BX,BX
			mov cx,1d
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,0FEH  ;Letter D
			mov bl,00h ;Green (A) on white(F) background
			int 10h


		CalculateBulletsForTank2:
		mov ax,shots2    ;max size
		mov bx,shots2+2  ;in the map 
		sub ax,bx  ; ax have the actual bullets player one have
		cmp al,	SecondNameLastBullets
			jg DrawOneBullet1

		cmp al,	SecondNameLastBullets
			jl RemoveOneBullet1
		jmp TanksLives
		DrawOneBullet1:
			mov cl,SecondNameLastBullets
			mov SecondNameLastBullets,al
			add cl,50d
			MoveCursor cl,25d
			XOR BX,BX
			mov cx,1d
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,0FEH  ;Letter D
			mov bl,0Ah ;Green (A) on white(F) background
			int 10h
			jmp TanksLives
		RemoveOneBullet1:
			mov SecondNameLastBullets,al
			add al,50d
			MoveCursor al,25d
			XOR BX,BX
			mov cx,1d
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,0FEH  ;Letter D
			mov bl,00h ;Green (A) on white(F) background
			int 10h
			jmp TanksLives

		TanksLives:

		mov Ax,tank1+52
		mov al,ah
		xor cx,cx

		MoveCursor 1d,24d
		Display Lives
		XOR BX,BX
		mov cl,FirstNameLastLife
		mov ah,9 	;Display
		mov bh,0 	;Page 0
		mov al,03  ;Letter D
		mov bl,00Ah ;Green (A) on white(F) background
		int 10h

		mov Ax,tank2+52
		mov al,ah
		xor cx,cx

		MoveCursor 41d,24d
		Display Lives
		XOR BX,BX
		mov cl,SecondNameLastLife
		mov ah,9 	;Display
		mov bh,0 	;Page 0
		mov al,03  ;Letter D
		mov bl,00Ah ;Green (A) on white(F) background
		int 10h

		mov Ax,tank1+52
		mov al,ah
		mov bx,tank2+52
		mov bl,bh

		cmp bx,0
			je IncrementTank1
		cmp ax,0	
			je IncrementTank2
		jmp AboveAll
		IncrementTank1:
			inc FirstNameLastScore
			jmp DrawGame
		IncrementTank2:
			inc SecondNameLastScore
		DrawGame:
			mov FirstNameLastLife,7d
			mov SecondNameLastLife,7d
			mov Ax,tank1+52
			mov ah,07d
			mov tank1+52,Ax
			mov Ax,tank2+52
			mov ah,07d
			mov tank2+52,Ax
		AboveAll:
			MoveCursor 1d,26d
			Xor Bx,Bx
			Display Score
			mov cl,1
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,FirstNameLastScore 
			add al,'0'
			mov bl,00Ah ;Green (A) on white(F) background
			int 10h

			MoveCursor 41d,26d
			Xor Bx,Bx
			Display Score
			Xor Bx,Bx
			mov cl,1
			mov ah,9 	;Display
			mov bh,0 	;Page 0
			mov al,SecondNameLastScore 
			add al,'0'
			mov bl,00Ah ;Green (A) on white(F) background
			int 10h

		mov dl,FirstNameLastScore
		cmp dl,3d
			je EndTheGame1

		mov dl,SecondNameLastScore
		cmp dl,3d
			je EndTheGame2
		jmp ContinueTheGame
		EndTheGame1:
		mov al,ExitByte
        mov byte,al  
        send byte 
			endgamewithscore
		jmp ContinueTheGame
		EndTheGame2:	
		mov al,ExitByte
        mov byte,al  
        send byte 
		endgamewithscore
		ContinueTheGame:

macroend:
	popa
endm UpdateStatus 