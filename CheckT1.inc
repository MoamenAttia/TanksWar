Check_Passing_Through_Tank1 macro GiftsX,GiftsY,Tank1
local loop1,label1,label2,label3,label4,labela,labelb,labelc,checkY,apply,boost_HP,boost_Power,ForSure1,ForSure2

	pusha
	
	mov bx,offset GiftsX
	mov Si,offset GiftsY
	mov Di,offset Tank1
	mov cx,05d
	loop1:
	mov dx,[di+48]
    cmp [bx+4],dx
	jge label1 
	jmp label2
	label1:
	mov ax,00
	mov ax,[bx+4]
	sub ax,[di+48]
	cmp ax,25d
	jb label3
	jmp label4
	label3:
	jmp checkY
	label2:
	add ax,00
	mov ax,[di+48]
	sub ax,[bx+4]
	cmp ax,25d
	jb label3
	label4:
	add bx,08d
	add si,08d
	loop loop1
	jmp tt
	checkY:
	mov dx,[di+50]
	cmp [si+4],dx
	jge labela 
	jmp labelb
	labela:
	add ax,00
	mov ax,[si+4]
	sub ax,[di+50]
	cmp ax,25d
	jb labelc
	jmp label4
	labelc:
	jmp apply
	labelb:
	add ax,00
	mov ax,[di+50]
	sub ax,[si+4]
	cmp ax,25d
	jb labelc
	add bx,08d
	add si,08d
	loop loop1
	apply:
	cmp cx,1
	je boost_HP
	cmp cx,3
	je boost_HP
	cmp cx,5
	je boost_HP
	cmp cx,2
	jmp boost_Power
	boost_HP:
	cmp [bx+6],11b
	je ForSure1
	add bx,08d
	add si,08d
	loop loop1
	ForSure1:
	mov dx,[di+52]
	mov dh,07d
	mov [di+52],dx
	and [bx+6],00b
	add bx,08d
	add si,08d
	loop loop1
	boost_Power:
	cmp [bx+6],11b
	je ForSure2
	add bx,08d
	add si,08d
	loop loop1
	ForSure2:
	mov dx,[di+52]
	OR  dx,0000000000100000b 
	And dx,1111111111101111b
	mov [di+52],dx
	and [bx+6],00b
	add bx,08d
	add si,08d
	loop loop1
	tt:
	popa
endm Check_Passing_Through_Tank1