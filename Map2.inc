SetMap2 MACRO
; Frame
mov StartPointX, 0d
mov StartPointY, 0d
mov EndPointX, 639d
mov EndPointY,0d
mov linecolor,3
call DrawLine

mov StartPointX, 0d
mov StartPointY, 479d-40d
mov EndPointX, 640d
mov EndPointY,480d-40d
mov linecolor,3
call DrawLine

mov StartPointX, 0d
mov StartPointY, 0d
mov EndPointX, 0d
mov EndPointY,479d-40d
mov linecolor,3
call DrawLine

mov StartPointX, 639d
mov StartPointY, 0d
mov EndPointX, 639d
mov EndPointY,479d-40d
mov linecolor,3
call DrawLine



;First Stage
mov StartPointX, 40d
mov StartPointY, 40d
mov EndPointX, 40d
mov EndPointY,440-40d
mov linecolor,0CH
call DrawLine

mov StartPointX, 640d-40d
mov StartPointY, 40d
mov EndPointX, 640-40d
mov EndPointY,440-40d
mov linecolor,0CH
call DrawLine


;Second Stage
mov StartPointX, 80d
mov StartPointY, 80d
mov EndPointX, 80d
mov EndPointY,400d-40d
mov linecolor,0CH
call DrawLine

mov StartPointX, 600d-40d
mov StartPointY, 80d
mov EndPointX, 600d-40d
mov EndPointY,400d-40d
mov linecolor,0CH
call DrawLine


;Third Stage
mov StartPointX, 120d
mov StartPointY, 120d
mov EndPointX, 120d
mov EndPointY,360d-40d
mov linecolor,0CH
call DrawLine

mov StartPointX, 560d-40d
mov StartPointY, 120d
mov EndPointX, 560d-40d
mov EndPointY,360d-40d
mov linecolor,0CH
call DrawLine


;Third Stage
mov StartPointX, 160d
mov StartPointY, 160d
mov EndPointX, 160d
mov EndPointY,320d-40d
mov linecolor,0CH
call DrawLine

mov StartPointX, 520d-40d
mov StartPointY, 160d
mov EndPointX, 520d-40d
mov EndPointY,320d-40d
mov linecolor,0CH
call DrawLine

;Forth Stage
;mov StartPointX, 200d
;mov StartPointY, 200d
;mov EndPointX, 200d
;mov EndPointY,280d-40d
;mov linecolor,0CH
;call DrawLine

;mov StartPointX, 480d-40d
;mov StartPointY, 200d
;mov EndPointX, 480d-40d
;mov EndPointY,280d-40d
;mov linecolor,0CH
;call DrawLine

mov StartPointX, 200d
mov StartPointY, 200d
mov EndPointX, 200d+240d
mov EndPointY,200d
mov linecolor,0CH
call DrawLine

mov StartPointX, 200d
mov StartPointY, 280d-40d
mov EndPointX, 200d+240d
mov EndPointY,280d-40d
mov linecolor,0CH
call DrawLine

mov StartPointX, 200d
mov StartPointY, 200d
mov EndPointX, 200d
mov EndPointY,280d-40d
mov linecolor,0CH
call DrawLine

mov StartPointX, 480d-40d
mov StartPointY, 200d
mov EndPointX, 480d-40d
mov EndPointY,280d-40d
mov linecolor,0CH
call DrawLine

;Drawing UpperGates
mov StartPointX, 300d
mov StartPointY, 200d
mov EndPointX, 340d
mov EndPointY,40d
mov linecolor,0
call DrawLine

mov StartPointX, 300d
mov StartPointY, 200d+40d
mov EndPointX, 340d
mov EndPointY,200d+40d
mov linecolor,0
call DrawLine

; Drawing Horizontal Sieges

mov StartPointX, 200d
mov StartPointY, 200d-40d
mov EndPointX, 200d+240d
mov EndPointY,200d-40d
mov linecolor,0CH
call DrawLine

mov StartPointX, 200d
mov StartPointY, 280d
mov EndPointX, 200d+240d
mov EndPointY,280d
mov linecolor,0CH
call DrawLine

; Drawing Horizontal Sieges2

mov StartPointX, 200d-40d
mov StartPointY, 200d-40d-40d
mov EndPointX, 200d+240d+40d
mov EndPointY,200d-40d-40d
mov linecolor,0CH
call DrawLine

mov StartPointX, 200d-40d
mov StartPointY, 280d+40d
mov EndPointX, 200d+240d+40d
mov EndPointY,280d+40d
mov linecolor,0CH
call DrawLine

; Drawing Horizontal Sieges3

mov StartPointX, 200d-40d-40d
mov StartPointY, 200d-40d-40d-40d
mov EndPointX, 200d+240d+40d+40d
mov EndPointY,200d-40d-40d-40d
mov linecolor,0CH
call DrawLine

mov StartPointX, 200d-40d-40d
mov StartPointY, 280d+40d+40d
mov EndPointX, 200d+240d+40d+40d
mov EndPointY,280d+40d+40d
mov linecolor,0CH
call DrawLine

; Drawing Horizontal Sieges4

mov StartPointX, 200d-40d-40d-40d
mov StartPointY, 200d-40d-40d-40d-40d
mov EndPointX, 200d+240d+40d+40d+40d
mov EndPointY,200d-40d-40d-40d-40d
mov linecolor,0CH
call DrawLine

mov StartPointX, 200d-40d-40d-40d
mov StartPointY, 280d+40d+40d+40d
mov EndPointX, 200d+240d+40d+40d+40d
mov EndPointY,280d+40d+40d+40d
mov linecolor,0CH
call DrawLine


ENDM SetMap2