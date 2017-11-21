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
PrintCharWonB macro
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
;*clearscreen   in video mode scroll screen
clearscreen macro
	pusha
	mov ax,0600h
	mov bh,07
	mov cx,0
	mov dx,184fh
	int 10h
	popa
endm clearscreen
