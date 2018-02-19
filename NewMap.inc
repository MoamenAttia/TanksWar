SetMap MACRO 

; Frame
mov word ptr StartPointX, 0d
mov word ptr StartPointY, 0d
mov word ptr EndPointX, 639d
mov word ptr EndPointY,0d
mov  linecolor,3
call DrawLine

mov word ptr StartPointX, 0d
mov word ptr StartPointY, 359d
mov word ptr EndPointX, 640d
mov word ptr EndPointY,360d
mov linecolor,3
call DrawLine

mov word ptr StartPointX, 0d
mov word ptr StartPointY, 0d
mov word ptr EndPointX, 0d
mov word ptr EndPointY,459d
mov linecolor,3
call DrawLine

mov word ptr StartPointX, 639d
mov word ptr StartPointY, 0d
mov word ptr EndPointX, 639d
mov word ptr EndPointY,459d
mov linecolor,3
call DrawLine

; First siege

mov word ptr StartPointX, 45d
mov word ptr StartPointY, 45d
mov word ptr EndPointX, 595d
mov word ptr EndPointY,45d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 45d
mov word ptr StartPointY, 315d
mov word ptr EndPointX, 596d
mov word ptr EndPointY,369d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 45d
mov word ptr StartPointY, 45d
mov word ptr EndPointX, 45d
mov word ptr EndPointY,315d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 595d
mov word ptr StartPointY, 45d
mov word ptr EndPointX, 595d
mov word ptr EndPointY,315d
mov linecolor,0CH
call DrawLine

; Second siege

mov word ptr StartPointX, 90d
mov word ptr StartPointY, 90d
mov word ptr EndPointX, 550d
mov word ptr EndPointY,90d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 90d
mov word ptr StartPointY,270d
mov word ptr EndPointX, 551d
mov word ptr EndPointY,271d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 90d
mov word ptr StartPointY, 90d
mov word ptr EndPointX, 90d
mov word ptr EndPointY,270d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 550d
mov word ptr StartPointY, 90d
mov word ptr EndPointX, 550d
mov word ptr EndPointY,270d
mov linecolor,0CH
call DrawLine

; Third siege

mov word ptr StartPointX, 135d
mov word ptr StartPointY, 135d
mov word ptr EndPointX, 505d
mov word ptr EndPointY,135d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 135d
mov word ptr StartPointY,225d
mov word ptr EndPointX, 506d
mov word ptr EndPointY,226d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 135d
mov word ptr StartPointY, 135d
mov word ptr EndPointX, 135d
mov word ptr EndPointY,225d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 505d
mov word ptr StartPointY, 135d
mov word ptr EndPointX, 505d
mov word ptr EndPointY,225d
mov linecolor,0CH
call DrawLine

;DrawUpperGates

mov word ptr StartPointX, 295d
mov word ptr StartPointY, 45d
mov word ptr EndPointX, 345d
mov word ptr EndPointY,45d
mov linecolor,0
call DrawLine

mov word ptr StartPointX, 295d
mov word ptr StartPointY, 135d
mov word ptr EndPointX, 345d
mov word ptr EndPointY,135d
mov linecolor,0
call DrawLine


;DrawLowerGates

mov word ptr StartPointX, 295d
mov word ptr StartPointY, 360-45d
mov word ptr EndPointX, 345d
mov word ptr EndPointY,360-45d
mov linecolor,0
call DrawLine

mov word ptr StartPointX, 295d
mov word ptr StartPointY, 360-45d-90d
mov word ptr EndPointX, 345d
mov word ptr EndPointY,360d-45d-90d
mov linecolor,0
call DrawLine


;DrawLeftGates

mov word ptr StartPointX, 90d
mov word ptr StartPointY, 155d
mov word ptr EndPointX, 90d
mov word ptr EndPointY,205d
mov linecolor,0
call DrawLine


;DrawRightGates

mov word ptr StartPointX, 550d
mov word ptr StartPointY, 155d
mov word ptr EndPointX, 550d
mov word ptr EndPointY,205d
mov linecolor,0
call DrawLine


;Status Bar;
mov word ptr StartPointX,0d
mov word ptr StartPointY,459d
mov word ptr EndPointX,320d
mov word ptr EndPointY,459d
mov Linecolor,3d
call DrawLine

mov word ptr StartPointX,320d
mov word ptr StartPointY,359d
mov word ptr EndPointX,320d
mov word ptr EndPointY,459d
mov Linecolor,3d
call DrawLine

mov word ptr StartPointX,320d
mov word ptr StartPointY,459d
mov word ptr EndPointX,639d
mov word ptr EndPointY,459d
mov word ptr Linecolor,3d
call DrawLine




ENDM SetMap
