;orientations
;00 up
;11 down
;01 right
;10 left 
;80x25 char 640*480 px 16colors 
include newmap.inc   
include Display.inc
include Map2.inc
include ReloadLivesScore.inc
include UpdateStatus.inc  
include Chat.inc
include Intialization.inc
include Drop.inc

.model meduim
.stack 64d
.data 
Byte db ?           
Score db 'Score: $'            
WelcomeMessage db 10,13,10,13,13,13
               db '  **         **  ********  **    ********* ******** ***           *** ********',10,13
               db '  **         **  **        **    ********* *      * ** *        *  ** **' ,10,13
               db '  **         **  **        **    **        *      * **  * *  * *   ** **'  ,10,13
               db '  **   ***   **  ********  **    **        *      * **     **      ** ********'    ,10,13
               db '  ** **   ** **  **        **    ********* *      * **             ** **'  ,10,13
               db '  ***      ****  ********  ***** ********* ******** **             ** ********$' 
FirstNameLastLife db 7d
SecondNameLastLife db 7d
FirstNameLastBullets db 5d
SecondNameLastBullets db 5d
FirstNameLastScore db 0
SecondNameLastScore db 0  


lvlselectionmess db 'Please select lvl!',10,10,'    1.Press 1 for lvl1',10,'    2.Press 2 for lvl2$' 
chosenlvlselectionmess db 'The selected lvl is lvl$' 
Lives      db 'Lives: $'
Bullets    db 'Bullets: $'

Question1 db '                           *To start chatting press F1',10,13,'$'
Question2 db '                           *To start TanksWar game press F2',10,13,'$'
Question3 db '                           *To end the program press ESC$'
                      
BackToMainMenuMess db '-If you want to return back to Main Menu or restart the game press F4$'

PlayerMessage db 10,13,10,13,10,13
                   db '         Please enter your name :',10,13,'                     $'  
                   
ChatInvitationMessage db '- You Sent a Chat Invitation To $' 
GameInvitationMessage db '- You Sent a Game Invitation To $'
ReplyingToChatInvitationMessage db ' sent you a Chat invitation, to accept press f1$' 
ReplyingToGameInvitationMessage db ' sent you a Game invitation, to accept press f2$'
ExitProgramMess db 'Program is exited!!!$'
WinnerMess db 'Winner$'
LoserMess db 'Loser$'
             
InDATA db 15,?,16 dup('$')
Player1Name db 16 dup('$')
Player1mess db ?,'$'   
Player1CursorPos dw 0000h

Player2Name db 16 dup('$')
Player2mess db ?,'$' 
Player2CursorPos dw 0000h    

DrawResult db 'Game is Draw$'
EndChatMess db 'Press f3 to end chat with $'     
EnterNameMess db '         Press enter to conitinue $'

StartPointX dw ,?
StartPointY dw ,?
EndPointX   dw ,?
EndPointY   dw ,?
linecolor   db ,?     

                                                                                                 
tank1 dw 2d,2d,42d,2d,42d,42d,2d,42d,  12d,6d,60d,120d,60d,140d,40d,140d, 45d,115d,55d,115d,55d,120d,45d,120d, 22d,22d ,0713h ;three rectangles 2 words tankcenter  more word for hp and orientation
shots1 dw 5d,0d
dw 0,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0  

colora1 db 15  
lengtha dw 40d  
lengtha1 dw ?  
lengtha2 dw ?       

tank2 dw 598d,317d,638d,377d,638d,417d,598d,417d,  90d,220d,110d,220d,110d,240d,90d,240d, 95d,215d,105d,215d,105d,220d,95d,220d, 618d,397d ,0710h

shots2 dw 5d,0d 
dw 0,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0
dw 0,0,0 

colorb1 db 13                   
lengthb dw 40d  
lengthb1 dw ?   
lengthb2 dw ?       

min_x dw 0
max_x dw 0
min_y dw 0
max_y dw 0 

damagedwall_pos dw ?,?,?  ; last word for power that wall hit with 
shootspeed dw 10
GiftsX dw 20 dup(?)
GiftsY dw 20 dup(?)

mes db '',? ,10,13 ,'$$'   

integar db ' '     
length dw ?    
startr dw ?
startc dw ? 

length1 dw ?      
startr1 dw ?
startc1 dw ? 

length2 dw ?      
startr2 dw ?
startc2 dw ? 

color1 dB ?
;------------------  
step dw 5
coll_detect dw 0
wall_col db 0Ch  
frame_col db 03h     
wall_col2 db 0Eh
temp_var dw 0  
cursorpos dw 0000h  
tmpmess db ?,'$'
notbarcursorposingame dw 0000h    
notbarcursorposinmainmenu dw 0000h
separatingline db '--------------------------------------------------------------------------------$'
F1 equ 3bh ;scan code
F2 equ 3Ch ;scan code
F3 equ 3dh ;scan code 
F4 equ 3eh ;scan code
Escape equ 01h ;scan code 
right equ 4Dh  ;scan code
left  equ 4Bh  ;scan code
up    equ 48h  ;scan code
down  equ 50h  ;scan code
shoot_Space equ 39h  ;scan code
Enter_key equ 1Ch   ;scan code
one equ 02h ;scan code
two equ 03h ;scan code
ChatByte equ 0CCh 
GameByte equ 0aah
ExitByte equ 0eeh  
iwillsendRandomTime equ 0bbh
oksendit equ   0ffh
randomtime db 0   


RChatinv db 0
Rgameinv db 0
Rexitinv db 0
RChatInGame db 0 
whichlvl db 0  
notificationbaringame dw 011Dh 
                                    
mychatposingame  dw 0000h
hischatposingame dw 0000h 
leftplayerchatingamepos dw 011bh  
leftplayerchatingamebound dw 201bh 
 
rightplayerchatingamepos dw 291bh
rightplayerchatingamebound dw 491bh 
imchating db 0

.code 
main proc far 
    mov AX,@Data
    mov DS,AX
    mov es,ax  
    PortIntialization 
    clearscreentm  
    Display  WelcomeMessage  
    ReadNames
SartingFromMainMenu:
DataIntialization 
 
    mov ah,0          
    mov al,03h
    int 10h            
    clearscreentm
    Display WelcomeMessage
    DisplayQuestions                    
    ProcessingAnswers
	
;---------
                         
                         
  playgame:   
   clearscreenvm

   mov al,whichlvl 
   cmp al,1
   jne notlvl1     
        SetMap 
        jmp maplvldone
   notlvl1:  
        SetMap2  
    jmp maplvldone                               
   maplvldone:
   
   
   
    mov al,RGameinv
    cmp al,0
    je imowner1
    ;here iam not owner
    MoveCursor 41d,23d
    jmp cursorend1
    imowner1:
    ;here i am owner       
    MoveCursor 1,23d      
    cursorend1:
   Display Player1Name
   
    mov al,RGameinv
    cmp al,0
    je imowner2
    ;here iam not owner
     MoveCursor 1,23d
    jmp cursorend2
    imowner2:
    ;here i am owner           
    MoveCursor 41d,23d
    cursorend2:                     
   Display Player2Name 
   
   ;--------
   MoveCursor 1d,29d
   Display BackToMainMenuMess 
   ;--------
   
    mov al,RGameinv
    cmp al,0
    je imowner3
    ;here iam not owner
    MoveCursor 41d,25d
    jmp cursorend3
    imowner3:
    ;here i am owner       
    MoveCursor 1,25d 
    cursorend3:
    
   Display Bullets
   mov cx,5
   mov ah,9 	;Display
   mov bh,0 	;Page 0
   mov al,0FEH  ;Letter D
   mov bl,0Ah ;Green (A) on white(F) background
   int 10h   
   
   
    mov al,RGameinv
    cmp al,0
    je imowner4
    ;here iam not owner
    MoveCursor 1,25d
    jmp cursorend4
    imowner4:
    ;here i am owner       
     MoveCursor 41d,25d  
    cursorend4:         
             
      
   Display Bullets
   mov cx,5
   mov ah,9 	;Display
   mov bh,0 	;Page 0
   mov al,0FEH  ;Letter D
   mov bl,0Ah ;Green (A) on white(F) background
   int 10h            
                            

   tankswar:     
     call input_and_flowcontrol    
     UpdateStatus
   jmp tankswar      
closeprogram:

mov dx,3fbh
mov al,01000000b
out dx,al 
hlt
main endp 

input_and_flowcontrol proc near
    pusha   
    
    drawframe     
    mov al,RGameinv
    cmp al,0
    je imowner5
    
    mov al,whichlvl 
    cmp al,1
    jne notlvl111     
          Drop GiftsX,GiftsY,tank2,tank1
    notlvl111:                                      
     jmp Dropend
     imowner5: 
    
    mov al,whichlvl 
    cmp al,1
    jne notlvl1111     
          Drop GiftsX,GiftsY,tank1,tank2
    notlvl1111:                                
    maplvldonee:
          
     Dropend:
    
  
    mov ah,1d
    int 16h 
    jnz con  
    jmp remotebuffer 
    con:                                  
    ;check if f444444444444444444444444444
    cmp ah,f4
    jne notf4
        mov ah,0d
        int 16h     
        mov al,ExitByte
        mov byte,al  
        send byte  
        endgamewithscore
    notf4:
    ;check if enterrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr 
    
    mov cl,imchating
    cmp cl,1 
    je chating
    
    cmp ah,Enter_key
    jne notenterpress
        mov imchating ,1 
        mov ah,0d
        int 16h    
        mov al,chatbyte
        mov byte,al
        send byte
        chating:
        SendChatVM 
        jmp remotebuffer 
    notenterpress:

    cmp ah,shoot_Space
    jnz noshoot
        mov al,RGameinv
        cmp al,0
        je imowner6         
        mov bx, offset shots2
        mov di, offset tank2     
        jmp shootend
        imowner6:
        mov bx, offset shots1
        mov di, offset tank1             
        shootend: 
        mov ah,0d
        int 16h                     
        call inputshots            
        mov byte,ah 
        send byte          
        jmp remotebuffer    
    noshoot: 
               
    cmp ah,right  
    jz moveuser  
    cmp ah,left
    jz moveuser 
    cmp ah,up
    jz moveuser
    cmp ah,down
    jz moveuser
                    
    jmp no_move_user    
    moveuser: 
      
   
    
    mov al,RGameinv
    cmp al,0   
    push ax
    je imowner7
    mov ah,0d
    int 16h      
    call tank_control_2
    ;reset centre 
    mov ax,lengthb
    mov dl,2
    div dl
    mov bx,tank2
    add bx,ax
    mov tank2+48,bx
    mov bx,tank2+2
    add bx,ax
    mov tank2+50,bx 
    jmp moveend
    imowner7: 
    mov ah,0d
    int 16h    
    call tank_control_1
    ;reset centre 
    mov ax,lengtha
    mov dl,2
    div dl
    mov bx,tank1
    add bx,ax
    mov tank1+48,bx
    mov bx,tank1+2
    add bx,ax
    mov tank1+50,bx        
    moveend:  
    pop ax
    mov byte,ah 
    send byte              
    jmp remotebuffer        
    no_move_user:  
                        
remotebuffer:
	makesurethesentisrecived:
		mov dx,3fdh
		in al,dx
		and al,00100000b
	jz makesurethesentisrecived

	mov dx,3fdh
	in al,dx
	and al,00000001b
	jz nothingrecived
	mov dx,3f8h
	in al,dx     
	mov ah,al  
    cmp ah,chatbyte
    jne notchatbyte
        mov al,rchatingame
        cmp al,1   
        je one_label 
           mov rchatingame,1 
           jmp nothingrecived ; chat byte wonot be used now          
        one_label: 
           mov rchatingame,0 
           jmp nothingrecived
    notchatbyte:
     mov al,rchatingame
     cmp al,1 
     je chatingame  
     
     
    ;chec exitttttttttttttttttttttttttttttttttttttttttt 
    ;cehck if chaaaaaaaaaaaat byte and RChatInGame Flag 
    cmp ah,exitbyte
    jne notexitbyte 
        mov byte,ah
        send byte  
        endgamewithscore
    notexitbyte:
                 
    cmp ah,shoot_Space
    jnz noshoot_
        mov al,RGameinv
        cmp al,1
        je imowner8 
        mov bx, offset shots2
        mov di, offset tank2     
        jmp shootend_
        imowner8:
        mov bx, offset shots1
        mov di, offset tank1             
        shootend_:             
        call inputshots                     
        jmp nothingrecived    
    noshoot_: 
               
    cmp ah,right  
    jz moveuser_  
    cmp ah,left
    jz moveuser_ 
    cmp ah,up
    jz moveuser_
    cmp ah,down
    jz moveuser_
                    
    jmp no_move_user_    
    moveuser_:    
    mov al,RGameinv
    cmp al,1
    je imowner9  
    call tank_control_2 
    ;reset centre 
    mov ax,lengthb
    mov dl,2
    div dl
    mov bx,tank2
    add bx,ax
    mov tank2+48,bx
    mov bx,tank2+2
    add bx,ax
    mov tank2+50,bx 
    jmp moveend_
    imowner9:  
    call tank_control_1
    ;reset centre 
    mov ax,lengtha
    mov dl,2
    div dl
    mov bx,tank1
    add bx,ax
    mov tank1+48,bx
    mov bx,tank1+2
    add bx,ax
    mov tank1+50,bx        
    moveend_:                           
    no_move_user_:
    jmp nothingrecived
    chatingame:  
    RecChatVM  
nothingrecived:
    ;if entered bad key 
    mov ah,1d
    int 16h 
    jz connnnn  
        mov ah,0h
        int 16h
    connnnn: 
    ;-----------
      
    call calc_centre
    call calc_square
    ;------------ 
    call tanka
    call draw_tank
    call tankb
    call draw_tank 
    ;-------------
    mov bx, offset shots2
    mov di, offset tank1    
    call process_shots
    
    mov bx, offset shots1
    mov di, offset tank2
    call process_shots 
    
    
    ;------------ 
     ; wait int
     mov cx,0  
     mov dx,7000d
     mov ah,86h
     int 15h       
    ;----------
    
    mov bx, offset shots1
    add bx,4
    call moveshots ;mov shots and clear old shots the from screen 
    mov bx, offset shots2
    add bx,4    
    call moveshots ;mov shots and clear old shots the from screen    
    
    popa
    ret
input_and_flowcontrol endp    
  



DrawLine proc near
    pusha
    mov AX,StartPointX
    cmp Ax,EndPointX
	je VerticalLine

    HorizontalLine:
    mov cx,StartPointX 	;Column
    mov dx,StartPointY 	;Row
    mov al,linecolor  		;Pixel color
    mov ah,0ch  		;Draw Pixel Command 
    mov bh,0
    looop1: int 10h
    	 inc cx
    	 cmp cx,EndPointX
    	 jnz looop1
    popa
    ret
    
    VerticalLine:
    mov cx,StartPointX 	;Column
    mov dx,StartPointY 	;Row
    mov al,linecolor  		;Pixel color
    mov ah,0ch  		;Draw Pixel Command 
    mov bh,0
    looop2: int 10h
	 inc dx
	 cmp dx,EndPointY
	 jnz looop2 

    popa
    ret
Drawline endp 

 
drawpx proc near ; draw pixel with color in al
    pusha
    mov cx,[bx]
    mov dx,[bx]+2
    mov ah,0ch
    mov bh,0
    int 10h
    popa
    ret 
drawpx endp 



inputshots proc near
    pusha 
    ;i here interset in shoot only       
    mov si ,[bx]
    mov ax ,[bx]+2
    cmp si ,ax 
    jnz con3 
    popa
    ret
    con3: 
    ;-----------
    mov ax,[bx]+2
    mov cl,6 
    mul cl
    mov cx,[bx]+2
    inc cx
    mov [bx]+2,cx 
    add bx,4
    add bx,ax 
    ;--------- 
    mov cx  , [di]+48d
    mov [bx], cx
    mov cx  , [di]+50d
    mov [bx] +2 , cx
    mov cx  , [di]+52d 
    and cx,00ffh
    mov [bx] +4 ,cx
    mov cx  , [di]+52d
    and cx,0ff1fh
    or cx ,0010h  
    mov [di]+52d ,cx   
    and cl ,00000011b
  
    cas1:    
        cmp cl , 0d
        jnz cas2
        mov si,[bx +2]
        sub si ,21d
        mov [bx+2],si
        jmp finish
    cas2:
        cmp cl ,1d
        jnz cas3
        mov si,[bx]
        add si ,21d
        mov [bx],si
        jmp finish
    cas3:    
        cmp cl , 2d 
        jnz cas4
        mov si,[bx]
        sub si ,21d
        mov [bx],si 
        jmp finish
    cas4:    
        cmp cl , 3d
        jnz finish
        mov si,[bx +2]
        add si ,21d
        mov [bx+2],si
    finish:      
     
    
    ;---------------    
    popa
    ret
inputshots endp

process_shots proc near   ;bx on shots of attacker tank and di on victm tank 
    ;steps
    ;1.process shots 2.draw shots 3.clear and move them 4.repeat
    pusha  ;now shots to process 
    mov cx,[bx]+2 
    cmp cx,0
    jnz cont
    popa
    ret
    cont:


    ;get smallest and bigest x  
    push di
    mov ax,[di] ;max x
    mov dx,ax   ;min x
    add di,4
    mov cx,3
    get_min_max_x:
       cmp ax,[di]
       ja here
           mov ax,[di]
           jmp skip
       here:
       cmp dx,[di]
       jb skip
       mov dx,[di] 
        
    skip:
    add di,4
    loop get_min_max_x   
    pop di 
    
    mov max_x,ax
    mov min_x,dx     
    ;-----------------------------
    
    ;get smallest and bigest y  
    push di  
    add di,2
    mov ax,[di] ;max y
    mov dx,ax   ;min y
    add di,4
    
    mov cx,3
    get_min_max_y:
       cmp ax,[di]
       ja here2
           mov ax,[di]
           jmp skip2
       here2:
       cmp dx,[di]
       jb skip2
       mov dx,[di] 
        
    skip2:add di,4
    loop get_min_max_y  
    pop di
    mov max_y,ax
    mov min_y,dx
    ;-----------------------------
    
    mov cx,[bx]+2 
    add bx,4
    push bx             
    check_del_shots:
        push cx        
        ;first check shots throug wall  
        mov cx ,[bx] +4
        and cl ,00000011b
        mov ax,shootspeed ;this is shoot speed  
        option1:   
            cmp cl , 0d
            jnz option2
            push cx
            mov cx,[bx]
            mov dx,[bx +2] 
            dec ax ; dec ax counter of loop to use it
            add dx,ax
            inc ax ;bring it back
            push ax 
            mov ah,0dh
            ;
            push bx
            mov bh,0
            int 10h
            pop bx
            ; 
            cmp al,3d     ;very very strong wall
            jnz to1 
                pop ax
                pop cx 
                jmp deleteshot        
          to1:   
            cmp al,0ch    ;strong wall   
            jz todamge1
            cmp al,0eh   ;weak wall 
            jnz to2  
            
            
            todamge1: ; here i should change wall color 
            mov damagedwall_pos ,cx
            mov damagedwall_pos +2  ,dx
            ;-----
            push cx
            mov cx,[bx]+4
            shr cx,4
            xor ch,ch 
            mov damagedwall_pos +4  ,cx
            pop cx
            ;----- 
            call damagewall   
            
            pop ax
            pop cx
            jmp deleteshot        
            to2:
            pop ax
            pop cx  
                
            dec ax
         jnz option1
        option2:
            cmp cl , 1d
            jnz option3
            push cx
            mov cx,[bx]
            mov dx,[bx +2]
            dec ax ; dec ax counter of loop to use it
            add cx,ax
            inc ax ;bring it back
            push ax 
            mov ah,0dh 
            ;
            push bx
            mov bh,0
            int 10h
            pop bx 
            ; 
            cmp al,3d      ;very very strong wall
            jnz to11 
                pop ax
                pop cx 
                jmp deleteshot        
          to11:
            cmp al,0ch    ;strong wall   
            jz todamge2
            cmp al,0eh   ;weak wall 
            jnz to22  

            todamge2: ; here i should change wall color 
            mov damagedwall_pos ,cx
            mov damagedwall_pos +2  ,dx
            ;-----
            push cx
            mov cx,[bx]+4
            shr cx,4
            xor ch,ch 
            mov damagedwall_pos +4  ,cx
            pop cx
            ;-----  
            call damagewall   
            
            pop ax
            pop cx
            jmp deleteshot          
            to22:
            pop ax
            pop cx  
                
             dec ax
         jnz option2
        option3:    
            cmp cl , 2d
            jnz option4
            push cx
            mov cx,[bx]
            mov dx,[bx +2]
            dec ax ; dec ax counter of loop to use it
            sub cx,ax
            inc ax ;bring it back
            push ax 
            mov ah,0dh
            ;
            push bx
            mov bh,0
            int 10h
            pop bx 
            ; 
            cmp al,3d
            jnz to111 
                pop ax
                pop cx 
                jmp deleteshot        
          to111:
            cmp al,0ch    ;strong color   
            jz todamge3
            cmp al,0eh   ;weak color 
            jnz to222  

            todamge3: ; here i should change wall color 
            mov damagedwall_pos ,cx
            mov damagedwall_pos +2  ,dx
            ;-----
            push cx
            mov cx,[bx]+4
            shr cx,4
            xor ch,ch 
            mov damagedwall_pos +4  ,cx
            pop cx
            ;-----  
            call damagewall   
            
            pop ax
            pop cx
            jmp deleteshot         
            to222:
            pop ax
            pop cx  
                
            dec ax
         jnz option3
        option4:    
            cmp cl , 3d
            jnz finishcheck
            push cx
            mov cx,[bx]
            mov dx,[bx +2]
            dec ax ; dec ax counter of loop to use it
            sub dx,ax
            inc ax ;bring it back
            push ax 
            mov ah,0dh
            ;
            push bx
            mov bh,0
            int 10h
            pop bx 
            ; 
            cmp al,3d
            jnz to1111 
                pop ax
                pop cx 
                jmp deleteshot        
          to1111:
            cmp al,0ch    ;strong wall   
            jz todamge4
            cmp al,0eh   ;weak wall 
            jnz to2222  

            todamge4: ; here i should change wall color 
            mov damagedwall_pos ,cx
            mov damagedwall_pos +2  ,dx
            ;-----
            push cx
            mov cx,[bx]+4
            shr cx,4
            xor ch,ch 
            mov damagedwall_pos +4  ,cx
            pop cx
            ;----- 
            call damagewall    
            
            pop ax           
            pop cx
            jmp deleteshot         
            to2222:
            pop ax
            pop cx     
            dec ax
         jnz option4
        finishcheck:  
   
        ;check point between two xs
        mov ax,min_x
        cmp [bx],ax
        jb next
        mov ax,max_x
        cmp [bx],ax
        ja next 
                   
        ;check point between two ys 
        mov ax,min_y
        cmp [bx+2],ax
        jb next     
        mov ax,max_y
        cmp [bx+2],ax
        ja next 
                      
        ; process deleting pixel and decreaing tank hp to be continue
        mov ax,[di]+52d 
        mov dx,[bx]+4d
        shr dl,4
        sub ah,dl
        ja noneg
            mov ah,0
        noneg:

        mov [di]+52,ax 
        
        deleteshot:
    
        pop ax ; now orginal cx in ax ; i wonot use just to get original bx
        pop si ; now original bx in si
        push si ;put them back
        push ax ;put them back
        mov cx,[si]-2
        mov ax,cx
        dec ax
        mov cl,6
        mul cl
        add si,ax ;si on last shot now replace
        mov cx,[si] ;first word
        mov [bx],cx
        mov cx,[si]+2 ;second word
        mov [bx]+2,cx
        mov cx,[si]+4 ;third word
        mov [bx]+4,cx
        sub si,ax ;get si back of first shot
        mov ax,[si-2]
        dec ax
        mov [si-2],ax
        sub bx,6d
        pop cx
        cmp cx,1
        jz donot
        dec cx 
        donot:
        push cx
        next: 

             
        add bx,6d   
        pop cx
    loop check_del_shots
    pop bx
      
;    mov cx,10
;    make_shots_stay_longer:
     call drawshots
;    loop make_shots_stay_longer
     

    popa
    ret
process_shots endp


moveshots proc near
    pusha  

    mov cx,[bx]-2
    cmp cx,0
    jnz moveshotsloop
    popa
    ret
    moveshotsloop:
        push cx         
        mov al ,00h  ;remove(from screen) shot before moving ant itwill redrawn in next iteration 
        call drawpx 
        
        mov ax,[bx]+4  
        and al ,00000011b
    
        cas_1:    
            cmp al , 0d
            jnz cas_2
            mov si,[bx +2] 
            ;--
            cmp si,shootspeed
            jb overflow1 ; over flow check
            sub si ,shootspeed 
            jmp nooverflow1
            overflow1:
            mov si,0
            nooverflow1:
            ;--
            mov [bx+2],si
            jmp finish2
        cas_2:
            cmp al ,1d
            jnz cas_3
            mov si,[bx] 
            ;---
            add si ,shootspeed 
            jo overflow2 ; over flow check 
            jmp nooverflow2
            overflow2:
            mov si,0
            nooverflow2:
            
            ;---
            mov [bx],si
            jmp finish2
        cas_3:    
            cmp al , 2d 
            jnz cas_4
            mov si,[bx]
            ;---
            cmp si ,shootspeed 
            jb overflow3 ; over flow check
            sub si ,shootspeed 
            jmp nooverflow3
            overflow3:
            mov si,0
            nooverflow3:
            ;---
            mov [bx],si 
            jmp finish2
        cas_4:    
            cmp al , 3d
            jnz finish2
            mov si,[bx +2]
            ;---
            add si ,shootspeed 
            jo overflow4 ; over flow check 
            jmp nooverflow4
            overflow4:
            mov si,0
            nooverflow4:
            ;---
            mov [bx+2],si
        finish2:
        add bx,6d   
        pop cx       
    loop moveshotsloop
    popa
    ret     
moveshots endp 


drawshots proc near
    pusha 
    ; now bx on first shot
    mov cx,[bx-2] 
    cmp cx,0
    mov si,bx
    jnz drawshotsloop 
    popa
    ret  
    drawshotsloop:
         mov al ,[si]+30
         call drawpx
         add bx,6d
    loop drawshotsloop
    popa
    ret  
drawshots endp



damagewall proc near  
    pusha 
    ;----------------------------   1 
    mov di,21d
    vrmup:     ;vertical removal up then down
    mov cx,damagedwall_pos
    mov dx,damagedwall_pos+ 2
    sub dx,di
    ;----
    push cx
    push dx
    push di 
    mov bh,0
    mov ah,0dh
    int 10h
    pop di
    pop dx
    pop cx   
    ;----
    cmp al,0ch
    jz damage1
    cmp al,0eh
    jnz remove1
    mov al,0h
    jmp remove1
    damage1:
    cmp damagedwall_pos+4,2
    jz strongdamage1
        mov al,0eh 
        jmp remove1   
    strongdamage1:
    mov al,0h
    remove1:

        
    
    mov si ,damagedwall_pos+ 2
    mov  damagedwall_pos+ 2,dx
    mov bx,offset damagedwall_pos
    call drawpx 
    mov damagedwall_pos +2,si

    dec di
    jnz vrmup
    ;------------------------- 
     ; i wonot process middle pixel as it will be processed in horizontal remove
    ;----------------------------    2 
    mov di,21d
    vrmdw:     ;vertical removal down then down
    mov cx,damagedwall_pos
    mov dx,damagedwall_pos+ 2
    add dx,di
    ;----
    push cx
    push dx
    push di 
    mov bh,0
    mov ah,0dh
    int 10h
    pop di
    pop dx
    pop cx  
    ;---- 
    cmp al,0ch
    jz damage2
    cmp al,0eh
    jnz remove2
    mov al,0h
    jmp remove2
    damage2:
    cmp damagedwall_pos+4,2
    jz strongdamage2
        mov al,0eh 
        jmp remove2   
    strongdamage2:
    mov al,0h
    remove2:
     
    
    mov si ,damagedwall_pos+ 2
    mov  damagedwall_pos+ 2,dx
    mov bx,offset damagedwall_pos
    call drawpx 
    mov damagedwall_pos +2,si

    dec di
    jnz vrmdw
    ;-------------------------  
    
    
    ;----------------------------    3          now horizontal removal right then left
    mov di,21
    hrrmr:     ;horizontal remove right 
    mov cx,damagedwall_pos
    mov dx,damagedwall_pos+ 2
    add cx,di
    ;----
    push cx
    push dx
    push di 
    mov bh,0
    mov ah,0dh
    int 10h
    pop di
    pop dx
    pop cx
    ;----  
    cmp al,0ch
    jz damage3
    cmp al,0eh
    jnz remove3
    mov al,0h
    jmp remove3
    damage3:
    cmp damagedwall_pos+4,2
    jz strongdamage3
        mov al,0eh 
        jmp remove3   
    strongdamage3:
    mov al,0h
    remove3:     
    
    mov si ,damagedwall_pos
    mov  damagedwall_pos,cx
    mov bx,offset damagedwall_pos
    call drawpx 
    mov damagedwall_pos,si
    
    dec di
    jnz hrrmr
    ;------------------------- 
    ;in last loop i removed 20 point right center point so i will go right one step and remove 20 point left ; i will bring it back after all horizontal removing
    mov ax,damagedwall_pos
    inc ax
    mov damagedwall_pos,ax 
    
    ;----------------------------    4 
    mov di,21
    hrrml:     ;horizontal remove left
    mov cx,damagedwall_pos
    mov dx,damagedwall_pos+ 2
    sub cx,di
    ;----
    push cx
    push dx
    push di 
    mov bh,0
    mov ah,0dh
    int 10h
    pop di
    pop dx
    pop cx  
    ;-----
    cmp al,0ch
    jz damage4
    cmp al,0eh
    jnz remove4
    mov al,0h
    jmp remove4
    damage4:
    cmp damagedwall_pos+4,2
    jz strongdamage4
        mov al,0eh 
        jmp remove4   
    strongdamage4:
    mov al,0h
    remove4:      
    
    mov si ,damagedwall_pos
    mov  damagedwall_pos,cx
    mov bx,offset damagedwall_pos
    call drawpx 
    mov damagedwall_pos,si

    dec di
    jnz hrrml
    ;-------------------------  
    
    ;see comments above 
    mov ax,damagedwall_pos
    dec ax
    mov damagedwall_pos,ax 
       
    
    popa
    ret
damagewall endp

 
 calc_tank1 proc near
    pusha           
   ;move values from temp values to permanent variables 
    mov ax,length
    mov bx,startr
    mov cx,startc
    mov lengtha,ax 
    mov tank1+2,bx
    mov tank1,cx
    
    mov ax,length1
    mov bx,startr1
    mov cx,startc1
    mov lengtha1,ax 
    mov tank1+18,bx
    mov tank1+16,cx
    
    mov ax,length2
    mov bx,startr2
    mov cx,startc2
    mov lengtha2,ax 
    mov tank1+34,bx
    mov tank1+32,cx 
        
    mov ax,length
    mov dl,2             
    div dl    
    mov dx,tank1
    add dx,ax
    mov tank1+48,dx
    mov dx,tank1+2
    add dx,ax 
    mov tank1+50,dx
    popa
    ret
calc_tank1 endp                  

calc_tank2 proc near
    pusha 
    ;move values from temp values to permanent variables   
    mov ax,length
    mov bx,startr
    mov cx,startc
    mov lengthb,ax 
    mov tank2+2,bx
    mov tank2,cx
    
    mov ax,length1
    mov bx,startr1
    mov cx,startc1
    mov lengthb1,ax 
    mov tank2+18,bx
    mov tank2+16,cx
    
    mov ax,length2
    mov bx,startr2
    mov cx,startc2
    mov lengthb2,ax 
    mov tank2+34,bx
    mov tank2+32,cx
    mov ax,length
    mov dl,2
    div dl    
    mov dx,tank2
    add dx,ax
    mov tank2+48,dx
    mov dx,tank2+2
    add dx,ax
    mov tank2+50,dx
    popa
    ret
calc_tank2 endp    

calc_centre proc  near
    pusha
    mov ax,lengtha
    mov dl,2
    div dl
    mov bx,tank1
    add bx,ax
    mov tank1+48,bx
    mov bx,tank1+2
    add bx,ax
    mov tank1+50,bx
    
    
    
    
    mov ax,lengthb
    mov dl,2
    div dl
    mov bx,tank2
    add bx,ax
    mov tank2+48,bx
    mov bx,tank2+2
    add bx,ax
    mov tank2+50,bx   
    popa
    ret
calc_centre endp    

calc_square proc  near
    pusha
    mov ax,lengtha   
    mov lengthb,ax
    mov ax,tank1 
    mov tank1+12,ax
    add ax,lengtha
    mov tank1+4,ax    
    mov tank1+8,ax 
    
    mov ax,tank1+2 
    mov tank1+6,ax
    add ax,lengtha
    mov tank1+10,ax    
    mov tank1+14,ax    
    
    
    mov ax,tank2 
    mov tank2+12,ax
    add ax,lengtha
    mov tank2+4,ax    
    mov tank2+8,ax 
    
    mov ax,tank2+2 
    mov tank2+6,ax
    add ax,lengtha
    mov tank2+10,ax    
    mov tank2+14,ax     
    popa            
    ret
calc_square endp
calc_length proc near 
    ;calc smaller lengths
    pusha 
    mov ax,length
    mov dl,2
    div dl 
    mov ah,00
    mov length1,ax
    
    
    mov ax,length1
    mov dl,3
    div dl   
    mov ah,00
    mov length2,ax 
    popa   
    ret
calc_length endp  


calc_points_up proc near 
    pusha 
    mov bx,length
    add bx,startr
    mov ax,length
    sub ax,length1
    mov dl,3
    div dl
    mov ah,00 
    sub bx,ax  
    sub bx,length1
    mov startr1,bx  
    
  
    
    mov bx,length
    add bx,startc
    mov ax,length
    sub ax,length1
    mov dl,2
    div dl  
    mov ah,00
    sub bx,ax
    sub bx,length1 
    mov startc1,bx   
    
    mov bx,length1
    add bx,startc1
    mov ax,length1
    sub ax,length2
    mov dl,2
    div dl  
    mov ah,00
    sub bx,ax
    sub bx,length2 
    mov startc2,bx
                    
                    
    mov bx,startr1
    sub bx,length2
    mov startr2,bx
    
     
    popa  
    ret
calc_points_up endp   
    

calc_points_down proc near
    pusha  
    mov bx,length
    add bx,startr
    mov ax,length
    sub ax,length1
    mov dl,3
    div dl 
    mov ah,00 
    mov dl,2
    mul dl  
    mov ah,00 
    sub bx,ax  
    sub bx,length1
    mov startr1,bx  
    
  
    mov bx,length
    add bx,startc
    mov ax,length
    sub ax,length1
    mov dl,2
    div dl  
    mov ah,00
    sub bx,ax
    sub bx,length1 
    mov startc1,bx   
    
    
    mov bx,length1
    add bx,startc1
    mov ax,length1
    sub ax,length2
    mov dl,2
    div dl  
    mov ah,00
    sub bx,ax
    sub bx,length2 
    mov startc2,bx
                    
                    
    mov bx,startr1
    add bx,length1
    mov startr2,bx  
    popa 
    ret
calc_points_down endp   
        


calc_points_right proc near
    pusha  
    mov bx,length
    add bx,startc
    mov ax,length
    sub ax,length1
    mov dl,3
    div dl 
    mov ah,00 
    mov dl,2
    mul dl  
    mov ah,00 
    sub bx,ax  
    sub bx,length1
    mov startc1,bx  
    
  
    
    mov bx,length
    add bx,startr
    mov ax,length
    sub ax,length1
    mov dl,2
    div dl  
    mov ah,00
    sub bx,ax
    sub bx,length1 
    mov startr1,bx   
    
    mov bx,length1
    add bx,startr1
    mov ax,length1
    sub ax,length2
    mov dl,2
    div dl  
    mov ah,00
    sub bx,ax
    sub bx,length2 
    mov startr2,bx
                    
                    
    mov bx,startc1
    add bx,length1
    mov startc2,bx 
    popa  
    ret
calc_points_right endp

calc_points_left proc near
    pusha  
    mov bx,length
    add bx,startc
    mov ax,length
    sub ax,length1
    mov dl,3
    div dl
    mov ah,00 
    sub bx,ax  
    sub bx,length1
    mov startc1,bx  
    
  
    
    mov bx,length
    add bx,startr
    mov ax,length
    sub ax,length1
    mov dl,2
    div dl  
    mov ah,00
    sub bx,ax
    sub bx,length1 
    mov startr1,bx   
    
    mov bx,length1
    add bx,startr1
    mov ax,length1
    sub ax,length2
    mov dl,2
    div dl  
    mov ah,00
    sub bx,ax
    sub bx,length2 
    mov startr2,bx
                    
                    
    mov bx,startc1
    sub bx,length2
    mov startc2,bx 
    popa  
    ret
calc_points_left endp 

draw_vertical_line proc near
    pusha        
    loopa:
    push cx
    mov cx,si ;Column
    mov dx,di ;Row
    mov ah,0ch ;Draw Pixel Command 
    mov bh,0
    int 10h       
    inc di
    pop cx
    loop loopa
    popa  
    ret
draw_vertical_line endp

draw_horizontal_line proc  near      
    pusha
    loopb:
    push cx
    mov cx,si ;Column
    mov dx,di ;Row
    mov ah,0ch ;Draw Pixel Command
    mov bh,0
    int 10h       
    inc si
    pop cx
    loop loopb
    popa   
    ret
draw_horizontal_line endp

tanka proc  near
    pusha
    mov ax,lengtha
    mov bx,tank1+2
    mov cx,tank1
    mov length,ax 
    mov startr,bx
    mov startc,cx
    
    mov ax,lengtha1
    mov bx,tank1+18
    mov cx,tank1+16
    mov length1,ax 
    mov startr1,bx
    mov startc1,cx
    
    mov ax,lengtha2
    mov bx,tank1+34
    mov cx,tank1+32
    mov length2,ax 
    mov startr2,bx
    mov startc2,cx
    
    mov bl,colora1
    mov color1,bl
    popa  
    ret
tanka endp         

tankb proc near 
    pusha
    mov ax,lengthb
    mov bx,tank2+2
    mov cx,tank2
    mov length,ax 
    mov startr,bx
    mov startc,cx
    
    mov ax,lengthb1
    mov bx,tank2+18
    mov cx,tank2+16
    mov length1,ax 
    mov startr1,bx
    mov startc1,cx
    
    mov ax,lengthb2
    mov bx,tank2+34
    mov cx,tank2+32
    mov length2,ax 
    mov startr2,bx
    mov startc2,cx
    
    mov bl,colorb1
    mov color1,bl
    popa  
    ret
tankb endp

draw_tank proc near
    pusha 
    mov cx,length    
    mov si,startc
    mov di,startr   
    mov al,color1 ;Pixel color
    call draw_vertical_line 
   
   
    mov cx,length   
    mov si,startc
    mov di,startr
    mov al,color1 ;Pixel color
    call draw_horizontal_line 
    
    
    
    mov cx,length     
    mov bx,startr
    add bx,length 
    mov si,startc
    mov di,bx
    mov al,color1 ;Pixel color
    call draw_horizontal_line 
  
    
    
    
    mov cx,length
    add cx,1     
    mov bx,startc
    add bx,length 
    mov si,bx
    mov di,startr
    mov al,color1 ;Pixel color
    call draw_vertical_line 







    mov cx,length1    
    mov si,startc1
    mov di,startr1   
    mov al,color1 ;Pixel color
    call draw_vertical_line 
    
    
    mov cx,length1    
    mov si,startc1
    mov di,startr1
    mov al,color1 ;Pixel color
    call draw_horizontal_line 
    
    
    mov cx,length1     
    mov bx,startr1
    add bx,length1 
    mov si,startc1
    mov di,bx
    mov al,color1 ;Pixel color
    call draw_horizontal_line 
    
    
    
    mov cx,length1 
    add cx,1    
    mov bx,startc1
    add bx,length1 
    mov si,bx
    mov di,startr1
    mov al,color1 ;Pixel color
    call draw_vertical_line 
    
    
    
    
    
    mov cx,length2    
    mov si,startc2
    mov di,startr2   
    mov al,color1 ;Pixel color
    call draw_vertical_line 
    
    
    mov cx,length2    
    mov si,startc2
    mov di,startr2
    mov al,color1 ;Pixel color
    call draw_horizontal_line 
    
    
    mov cx,length2     
    mov bx,startr2
    add bx,length2 
    mov si,startc2
    mov di,bx
    mov al,color1 ;Pixel color
    call draw_horizontal_line 
    
    
    
    mov cx,length2 
    add cx,1      
    mov bx,startc2
    add bx,length2 
    mov si,bx
    mov di,startr2
    mov al,color1 ;Pixel color
    call draw_vertical_line   
    
   
    
    popa    
    ret 
draw_tank endp 

clear_tank proc  near
    pusha 
    mov color1,0
    call draw_tank     
    popa 
    ret
clear_tank endp 

                       
             

check_up proc  near
    pusha     
    mov di,startc
    mov ax,length  
    mov temp_var,ax
    inc temp_var
    loopout1:
    push temp_var  
    mov si,startr  
    mov ax,step
    mov temp_var,ax
    inc temp_var
    loopin1:
    mov ah,0Dh
    mov bh,00
    mov cx,di
    mov dx,si
    int 10h
    cmp al,wall_col
    jz collup 
    cmp al,frame_col
    jz collup 
    cmp al,colora1
    jz collup 
    cmp al,colorb1
    jz collup 
    cmp al,wall_col2
    jz collup 
    inc si
    dec temp_var
    jnz loopin1  
    pop temp_var
    inc di
    dec temp_var
    jnz loopout1     
    mov word ptr coll_detect,0   
    popa
    ret
    collup:  
    pop temp_var 
    mov word ptr coll_detect,1 
    popa      
ret
check_up endp                 


check_down proc near
    pusha  
    mov di,startc
    mov ax,length  
    mov temp_var,ax
    inc temp_var
    loopout2:
    push temp_var   
    mov si,startr
    add si,length 
    mov ax,step
    mov temp_var,ax
    inc temp_var 
    loopin2:
    mov ah,0Dh
    mov bh,00
    mov cx,di
    mov dx,si
    int 10h
    cmp al,wall_col
    jz colldown 
    cmp al,frame_col
    jz colldown 
    cmp al,colora1
    jz colldown 
    cmp al,colorb1
    jz colldown   
    cmp al,wall_col2
    jz colldown 
    dec si    
    dec temp_var
    jnz loopin2
    pop temp_var
    inc di
    dec temp_var
    jnz loopout2     
    mov word ptr coll_detect,0   
    popa
    ret
    colldown:    
    pop temp_var      
    mov word ptr coll_detect,1 
    popa      
ret
check_down endp 



check_right proc  near
    pusha 
    mov si,startr    
    mov ax,length  
    mov temp_var,ax
    inc temp_var
    loopout3:
    push temp_var    
    mov di,startc
    add di,length 
    mov ax,step    
    mov temp_var,ax
    inc temp_var 
    loopin3:
    mov ah,0Dh
    mov bh,00
    mov cx,di
    mov dx,si
    int 10h
    cmp al,wall_col
    jz collright 
    cmp al,frame_col
    jz collright 
    cmp al,colora1
    jz collright 
    cmp al,colorb1
    jz collright 
    cmp al,wall_col2
    jz collright 
    dec di   
    dec temp_var
    jnz loopin3 
    pop temp_var
    inc si
    dec temp_var
    jnz loopout3     
    mov word ptr coll_detect,0   
    popa
    ret
    collright:      
    pop temp_var
    mov word ptr coll_detect,1 
    popa      
ret
check_right endp    


check_left proc  near
    pusha  
    mov si,startr
    mov ax,length  
    mov temp_var,ax
    inc temp_var
    loopout4:
    push temp_var   
    mov di,startc  
    mov ax,step    
    mov temp_var,ax
    inc temp_var   
    loopin4:
    mov ah,0Dh
    mov bh,00
    mov cx,di
    mov dx,si
    int 10h
    cmp al,wall_col
    jz collleft 
    cmp al,frame_col
    jz collleft 
    cmp al,colora1
    jz collleft 
    cmp al,colorb1
    jz collleft  
    cmp al,wall_col2
    jz collleft 
    inc di
    dec temp_var
    jnz loopin4 
    pop temp_var
    inc si
    dec temp_var
    jnz loopout4     
    mov word ptr coll_detect,0   
    popa
    ret
    collleft:           
    pop temp_var    
    mov word ptr coll_detect,1 
    popa      
ret
check_left endp


move_up1 proc   near
    pusha
    call tanka
    call clear_tank 
    call tankb
    call draw_tank  
    mov ax,step
    sub tank1+2,ax 
    call tanka   
    call check_up 
    cmp word ptr coll_detect,1
    jz col1   
    mov ax,0
    jmp conti1
    col1:
    mov ax,step 
    add tank1+2,ax
    conti1: 
    mov word ptr coll_detect,0 
    ;orientation up  
    mov ax,tank1+52
    and ax,0fff0h
    or ax,0000H
    mov tank1+52,AX
    call tanka 
    call calc_points_up
    call calc_tank1    
    call draw_tank 
    popa
    ret          
move_up1 endp 

move_down1 proc  near
    pusha
    call tanka
    call clear_tank
    call tankb
    call draw_tank  
    mov ax,step 
    add tank1+2,ax 
    call tanka 
    call check_down  
    cmp coll_detect,1
    jz col2    
    mov ax,0
    jmp conti2
    col2:
    mov ax,step 
    sub tank1+2,ax
    conti2:   
    mov word ptr  coll_detect,0
    mov ax,tank1+52 
    and ax,0fff0h
    or  ax,0003H
    mov tank1+52,AX
    call tanka   
    call calc_points_down
    call calc_tank1 
    call draw_tank
    popa        
    ret    
move_down1 endp

move_right1 proc near 
    pusha   
    call tanka
    call clear_tank
    call tankb
    call draw_tank
    mov ax,step 
    add tank1,ax   
    call tanka 
    call check_right 
    cmp coll_detect,1
    jz col3    
    mov ax,0
    jmp conti3
    col3:
    mov ax,step 
    sub tank1,ax
    conti3:         
    mov word ptr  coll_detect,0
    mov ax,tank1+52
    and ax,0fff0h
    or  ax,0001H
    mov tank1+52,AX
    call tanka  
    call calc_points_right
    call calc_tank1
    call draw_tank  
    popa
    ret    
move_right1 endp

move_left1 proc   near
    pusha     
    call tanka
    call clear_tank 
    call tankb
    call draw_tank
    mov ax,step
    sub tank1,ax    
    call tanka 
    call check_left  
    cmp coll_detect,1
    jz col4       
    mov ax,0
    jmp conti4
    col4:
    mov ax,step 
    add tank1,ax
    conti4:           
    mov word ptr  coll_detect,0  
    mov ax,tank1+52 
    and ax,0fff0h
    or  ax,0002H
    mov tank1+52,AX
    call tanka 
    call calc_points_left
    call calc_tank1   
    call draw_tank   
    popa
    ret    
move_left1 endp

move_up2 proc near
    pusha
    call tankb
    call clear_tank 
    call tanka
    call draw_tank
    mov ax,step 
    sub tank2+2,ax
    call tankb
    call check_up
    cmp coll_detect,1
    jz col5   
    mov ax,0
    jmp conti5
    col5:
    mov ax,step
    add tank2+2,ax
    conti5: 
    mov word ptr  coll_detect,0  
    mov ax,tank2+52
    and ax,0fff0h
    or ax,0000H
    mov tank2+52,AX
    call tankb 
    call calc_points_up
    call calc_tank2
    call draw_tank 
    popa
    ret    
move_up2 endp 

move_down2 proc near
    pusha
    call tankb
    call clear_tank
    call tanka
    call draw_tank  
    mov ax,step 
    add tank2+2,ax 
    call tankb 
    call check_down  
    cmp coll_detect,1
    jz col6        
    mov ax,0
    jmp conti6
    col6:
    mov ax,step 
    sub tank2+2,ax
    conti6:   
    mov word ptr  coll_detect,0
    mov ax,tank2+52
    and ax,0fff0h
    or ax,0003H
    mov tank2+52,AX
    call tankb   
    call calc_points_down
    call calc_tank2 
    call draw_tank
    popa        
    ret    
move_down2 endp

move_right2 proc near
    pusha
    call tankb
    call clear_tank
    call tanka
    call draw_tank
    mov ax,step   
    add tank2,ax   
    call tankb
    call check_right 
    cmp coll_detect,1
    jz col7          
    mov ax,0
    jmp conti7
    col7:
    mov ax,step 
    sub tank2,ax
    conti7:   
    mov word ptr  coll_detect,0
    mov ax,tank2+52
    and ax,0fff0h
    or  ax,0001H
    mov tank2+52,AX
    call tankb 
    call calc_points_right
    call calc_tank2
    call draw_tank
    popa
    ret    
move_right2 endp

move_left2 proc near
    pusha 
    call tankb
    call clear_tank 
    call tanka
    call draw_tank
    mov ax,step 
    sub tank2,ax  
    call tankb
    call check_left 
    cmp coll_detect,1
    jz col8     
    mov ax,0
    jmp conti8
    col8:
    mov ax,step
    add tank2,ax
    conti8:   
    mov word ptr  coll_detect,0
    mov ax,tank2+52
    and ax,0fff0h
    or  ax,0002H
    mov tank2+52,AX
    call tankb
    call calc_points_left
    call calc_tank2 
    call draw_tank 
    popa
    ret    
move_left2 endp    

                       
             
tank_control_2 proc near
    pusha      
    cmp ah,48h
    jz up2  
    cmp ah,50h
    jz down2
    cmp ah,4Dh
    jz right2
    cmp ah,4Bh
    jz left2
    
    up2:
    call move_up2
    jmp walk      
    
    down2:
    call move_down2
    jmp walk
    
    right2:
    call move_right2
    jmp walk
    
    left2:
    call move_left2
    jmp walk
        
    walk:
    popa
    ret
tank_control_2 endp                           



tank_control_1 proc near
    pusha      
    cmp ah,48h
    jz up1  
    cmp ah,50h
    jz down1
    cmp ah,4Dh
    jz right1
    cmp ah,4Bh
    jz left1

    up1:
    call move_up1
    jmp walkk      
    
    down1:
    call move_down1
    jmp walkk
    
    right1:
    call move_right1
    jmp walkk
    
    left1:
    call move_left1
    jmp walkk      
  
    walkk:
    popa
    ret
tank_control_1 endp 

;check_tank_collision proc 
;    mov ax,tank1
;    mov bx,tank2
;    mov dx,tank2
;    add dx,lengthb
;    mov cx,lengtha
;    hor_loop:    
;    cmp ax,bx
;    jae p1
;    jmp cont1
;    p1:
;    cmp ax,dx
;    jbe ver
;    cont1:
;    inc ax
;    loop hor_loop
;    ret
;    ver:     
;    mov ax,tank1+2
;    mov bx,tank2+2
;    mov dx,tank2+2
;    add dx,lengthb  
;    mov cx,lengtha
;    ver_loop:  
;    cmp ax,bx
;    jae p2
;    jmp cont1a
;    p2:
;    cmp ax,dx
;    jbe coll
;    cont1a:
;    inc ax
;    loop ver_loop 
;    mov ax,0
;    ret
;    coll:
;    mov ax,coll_detect
;    ret
; 
;check_tank_collision endp
;   

end main
                                 
                                 