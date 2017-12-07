ReloadLivesScore MACRO
Local DrawGame
Local IncrementTank2
Local IncrementTank1
Local EndThisProcedure

mov Ax,tank1+52
mov Bx,tank2+52
sub Ax,Bx

cmp Ax,0
	je DrawGame

mov Ax,tank1+52
mov Bx,tank2+52

cmp Ax,0
	je IncrementTank2
cmp Bx,0
	je IncrementTank1

jmp EndThisProcedure
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

EndThisProcedure:
ENDM ReloadLivesScore
