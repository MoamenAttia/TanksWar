stay macro peroid  ; number of s/100  (if want 10/100 sec so peroid = 10)  that loop will take to finish
	; note it's pretty safe for 50 (.5 sec) or smaller mor than .5 sec may cause problems
	local timeloop
	local breaktimeloop
	local dl_bigger
	
	mov ah,2ch
	int 21h
		mov bl,dl      
		mov bh,peroid 
	timeloop:
		mov ah,2ch
		int 21h             
		cmp bl,dl
		jbe dl_bigger
		mov al,99d
		sub al,bl
		add al,dl
		inc al
		cmp al,bh
		jae breaktimeloop 
		jmp timeloop
		dl_bigger:
		mov al,dl
		sub al,bl
		cmp al,bh
		jae breaktimeloop 
		jmp timeloop   
		breaktimeloop: 
	 
endm stay