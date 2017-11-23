SetMap MACRO ;640*480 

; Frame

mov StartPointX, 0d
mov StartPointY, 0d
mov EndPointX, 639d
mov EndPointY,0d
mov linecolor,3
call DrawLine

mov StartPointX, 0d
mov StartPointY, 479d
mov EndPointX, 640d
mov EndPointY,480d
mov linecolor,3
call DrawLine

mov StartPointX, 0d
mov StartPointY, 0d
mov EndPointX, 0d
mov EndPointY,479d
mov linecolor,3
call DrawLine

mov StartPointX, 639d
mov StartPointY, 0d
mov EndPointX, 639d
mov EndPointY,479d
mov linecolor,3
call DrawLine

; First siege

mov StartPointX, 40d
mov StartPointY, 40d
mov EndPointX, 600d
mov EndPointY,40d
mov linecolor,0CH
call DrawLine

mov StartPointX, 40d
mov StartPointY, 440d
mov EndPointX, 601d
mov EndPointY,441d
mov linecolor,0CH
call DrawLine

mov StartPointX, 40d
mov StartPointY, 40d
mov EndPointX, 40d
mov EndPointY,440d
mov linecolor,0CH
call DrawLine

mov StartPointX, 600d
mov StartPointY, 40d
mov EndPointX, 600d
mov EndPointY,440d
mov linecolor,0CH
call DrawLine

; Second siege

mov StartPointX, 80d
mov StartPointY, 80d
mov EndPointX, 560d
mov EndPointY,80d
mov linecolor,0CH
call DrawLine

mov StartPointX, 80d
mov StartPointY, 400d
mov EndPointX, 561d
mov EndPointY,401d
mov linecolor,0CH
call DrawLine

mov StartPointX, 80d
mov StartPointY, 80d
mov EndPointX, 80d
mov EndPointY,400d
mov linecolor,0CH
call DrawLine

mov StartPointX, 560d
mov StartPointY, 80d
mov EndPointX, 560d
mov EndPointY,400d
mov linecolor,0CH
call DrawLine

; Third siege

mov StartPointX, 120d
mov StartPointY, 120d
mov EndPointX, 520d
mov EndPointY,120d
mov linecolor,0CH
call DrawLine

mov StartPointX, 120d
mov StartPointY, 360d
mov EndPointX, 521d
mov EndPointY,361d
mov linecolor,0CH
call DrawLine

mov StartPointX, 120d
mov StartPointY, 120d
mov EndPointX, 120d
mov EndPointY,360d
mov linecolor,0CH
call DrawLine

mov StartPointX, 520d
mov StartPointY, 120d
mov EndPointX, 520d
mov EndPointY,360d
mov linecolor,0CH
call DrawLine

; Forth siege

mov StartPointX, 160d
mov StartPointY, 160d
mov EndPointX, 480d
mov EndPointY,160d
mov linecolor,0CH
call DrawLine

mov StartPointX, 160d
mov StartPointY, 320d
mov EndPointX, 481d
mov EndPointY,321d
mov linecolor,0CH
call DrawLine

mov StartPointX, 160d
mov StartPointY, 160d
mov EndPointX, 160d
mov EndPointY,320d
mov linecolor,0CH
call DrawLine

mov StartPointX, 480d
mov StartPointY, 160d
mov EndPointX, 480d
mov EndPointY,320d
mov linecolor,0CH
call DrawLine

; Fifth siege

mov StartPointX, 200d
mov StartPointY, 200d
mov EndPointX, 440d
mov EndPointY,200d
mov linecolor,0CH
call DrawLine

mov StartPointX, 200d
mov StartPointY, 280d
mov EndPointX, 441d
mov EndPointY,281d
mov linecolor,0CH
call DrawLine

mov StartPointX, 200d
mov StartPointY, 200d
mov EndPointX, 200d
mov EndPointY,280d
mov linecolor,0CH
call DrawLine

mov StartPointX, 440d
mov StartPointY, 200d
mov EndPointX, 440d
mov EndPointY,280d
mov linecolor,0CH
call DrawLine

;DrawUpperGates

mov StartPointX, 300d
mov StartPointY, 40d
mov EndPointX, 340d
mov EndPointY,40d
mov linecolor,0
call DrawLine

mov StartPointX, 300d
mov StartPointY, 120d
mov EndPointX, 340d
mov EndPointY,120d
mov linecolor,0
call DrawLine

mov StartPointX, 300d
mov StartPointY, 200d
mov EndPointX, 340d
mov EndPointY,200d
mov linecolor,0
call DrawLine

;DrawLowerGates

mov StartPointX, 300d
mov StartPointY, 480-40d
mov EndPointX, 340d
mov EndPointY,480-40d
mov linecolor,0
call DrawLine

mov StartPointX, 300d
mov StartPointY, 480-120d
mov EndPointX, 340d
mov EndPointY,480-120d
mov linecolor,0
call DrawLine

mov StartPointX, 300d
mov StartPointY, 480-200d
mov EndPointX, 340d
mov EndPointY,480-200d
mov linecolor,0
call DrawLine

;DrawLeftGates

mov StartPointX, 80d
mov StartPointY, 220d
mov EndPointX, 80d
mov EndPointY,260d
mov linecolor,0
call DrawLine

mov StartPointX, 160d
mov StartPointY, 220d
mov EndPointX, 160d
mov EndPointY,260d
mov linecolor,0
call DrawLine

mov StartPointX, 240d
mov StartPointY, 220d
mov EndPointX, 240d
mov EndPointY,260d
mov linecolor,0
call DrawLine

;DrawRightGates

mov StartPointX, 640-80d 
mov StartPointY, 220d 
mov EndPointX, 640-80d
mov EndPointY,260d
mov linecolor,0
call DrawLine

mov StartPointX, 640-160d
mov StartPointY, 220d
mov EndPointX, 640-160d
mov EndPointY,260d
mov linecolor,0
call DrawLine

mov StartPointX, 640-240d
mov StartPointY, 220d
mov EndPointX, 640-240d
mov EndPointY,260d
mov linecolor,0
call DrawLine


ENDM SetMap