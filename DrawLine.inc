DrawLine MACRO StartPointX,StartPointY,EndPointX,EndPointY,color
Local HorizontalLine
Local VerticalLine
Local loop1
Local loop2
Local EndMacro

mov AX,StartPointX
cmp Ax,EndPointX
	je VerticalLine

HorizontalLine:
mov cx,StartPointX 	;Column
mov dx,StartPointY 	;Row
mov al,color  		;Pixel color
mov ah,0ch  		;Draw Pixel Command
loop1: int 10h
	 inc cx
	 cmp cx,EndPointX
	 jnz loop1
jmp EndMacro

VerticalLine:
mov cx,StartPointX 	;Column
mov dx,StartPointY 	;Row
mov al,color  		;Pixel color
mov ah,0ch  		;Draw Pixel Command
loop2: int 10h
	 inc dx
	 cmp dx,EndPointY
	 jnz loop2
EndMacro:
ENDM DrawLine