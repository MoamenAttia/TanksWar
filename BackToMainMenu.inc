    BackToMainMenuMACRO MACRO 
    Local AyKalam1
    Local printWarning1
    Local playgame1
    mov BackToMainMenuFlag,0  
    mov ah,0
    mov al,12h
    int 10h
   
    
    Display WelcomeMessage
    
    xor bx,bx    
    mov ah,2
    mov dl,0
    mov dh,14d
    int 10h
    Display Question1
    xor bx,bx    
    mov ah,2
    mov dl,0
    mov dh,16d
    int 10h
    Display Question2
    xor bx,bx    
    mov ah,2
    mov dl,0
    mov dh,18d
    int 10h
    Display Question3
    
      
    AyKalam1: 
     mov ah,0
     int 16h  
     cmp Ax,3C00H 
        je printWarning
     cmp Ax,011BH
        je closeprogram
     jmp playgame    
    printWarning1:
        Display WarningMessage      
        jmp AyKalam
 
  playgame1:  
   mov ah,0
   mov al,12h
   int 10h 
   
   SetMap
   
   MoveCursor 1,23d
   Display Host
   Display FirstPlayerName

   MoveCursor 41d,23d
   Display Guest
   Display SecondPlayerName

   MoveCursor 1d,29d
   Display BackToMainMenu
   call calc_square
    
   call calc_centre
    
    


   
   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    mov bx,offset GiftsX  
    mov Si,offset GiftsY  
    
    
    
    mov [bx],75d
    mov [bx+2],85d
    mov [bx+4],80d
    mov [bx+6],11b
    
    
    mov [bx+8],555d
    mov [bx+10],565d
    mov [bx+12],560d
    mov [bx+14],11b
    
    mov [bx+16],315d
    mov [bx+18],325d
    mov [bx+20],320d
    mov [bx+22],11b
    
    mov [bx+24],315d
    mov [bx+26],325d
    mov [bx+28],320d
    mov [bx+30],11b
    
    mov [bx+32],315d
    mov [bx+34],325d
    mov [bx+36],320d
    mov [bx+38],11b
    
    
    
    mov [si],175d
    mov [si+2],185d
    mov [si+4],180d
    mov [si+6],11b
    
    
    mov [si+8],175d
    mov [si+10],185d
    mov [si+12],180d
    mov [si+14],11b
    
    
    mov [si+16],50d
    mov [si+18],60d
    mov [si+20],55d
    mov [si+22],11b
    
    mov [si+24],170d
    mov [si+26],180d
    mov [si+28],175d
    mov [si+30],11b
    
    mov [si+32],305d
    mov [si+34],315d
    mov [si+36],310d
    mov [si+38],11b 
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


    call tanka
    call calc_length
    call calc_points_down
    call calc_tank1  
    ;\\\\\\\\\\\\\\\\\\\\\\   
    call tankb
    call calc_length
    call calc_points_up
    call calc_tank2
    ;///////////////////////////////////////////////////////////////////////////////////////////////////////   
    call tanka
    call draw_tank
    call tankb
    call draw_tank  

    ENDM BackToMainMenuMACRO