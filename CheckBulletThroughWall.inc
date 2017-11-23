CheckBulletThroughWall MACRO 
Local LoopBullets
Local Commute
Local To5
Local To4
Local To0
Local Continue
Local Loopx
Local Bridge0
Local To5x
Local To4x
Local To0x
Local Continuex
Local Loopxx
Local Bridge
Local Again
; Bullets will be global array .. 
; OCH -> strong wall.
; 4   -> after 1st shot.
; 5   -> after 2nd shot.
; 0   -> wall was smashed.
; 3   -> this is a frame.
mov bx,offset AllBullets
mov SI,1	 ;Assumin' 10 is the max num of bullets in tha game and a bullet is reserved with word loc in memory;
LoopBullets:
mov CX,[bx]
mov DX,[bx]+2
add bx,04h
mov AH,0Dh
int 10H ; put color in AL
cmp AL,0CH
	je Commute
cmp AL,4
	je Commute
cmp AL,5
	je Commute
jmp Again
Commute:
	ChangePixels 
Again:
	inc SI
	cmp Si,3
		jne LoopBullets
ENDM CheckBulletThroughWall

;---------------------;
ChangePixels MACRO 

mov bp,0000h
mov BulletCoordinates,cx
mov BulletCoordinates+2,dx
sub cx,20d
Loopx:
	mov AH,0Dh
	int 10H
	cmp AL,0CH
		je To5
	cmp AL,4
		je To4	
	cmp AL,5
		je To0
jmp Continue
To5:
	DrawPixelCommand 5
	jmp Continue
To4:
	DrawPixelCommand 4
	jmp Continue
To0:		
	DrawPixelCommand 0
	jmp Continue
Continue: 
	inc bp
	inc cx
	cmp bp,41d
		jne Loopx	
Bridge0:
mov bp,0000h
mov cx,BulletCoordinates
mov dx,BulletCoordinates+2
sub Dx,20d
Loopxx:
	mov AH,0Dh
	int 10H
	cmp AL,0CH
		je To5x
	cmp AL,4
		je To4x	
	cmp AL,5
		je To0x

To5x:
	DrawPixelCommand 5
	jmp Continuex
To4x:
	DrawPixelCommand 4
	jmp Continuex
To0x:		
	DrawPixelCommand 0
	jmp Continuex

Continuex: 
	inc bp
	inc Dx
	cmp bp,41d
		jne Loopxx
Bridge:	
ENDM ChangePixels
;----------------;
DrawPixelCommand MACRO color
mov al,color ;Pixel color
mov ah,0ch   ;Draw Pixel Command
int 10h 
ENDM DrawPixelCommand