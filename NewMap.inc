SetMap MACRO 

; Frame
mov StartPointX, 0d
mov StartPointY, 0d
mov EndPointX, 639d
mov EndPointY,0d
mov linecolor,3
call DrawLine

mov StartPointX, 0d
mov StartPointY, 359d
mov EndPointX, 640d
mov EndPointY,360d
mov linecolor,3
call DrawLine

mov StartPointX, 0d
mov StartPointY, 0d
mov EndPointX, 0d
mov EndPointY,459d
mov linecolor,3
call DrawLine

mov StartPointX, 639d
mov StartPointY, 0d
mov EndPointX, 639d
mov EndPointY,459d
mov linecolor,3
call DrawLine

; First siege

mov StartPointX, 45d
mov StartPointY, 45d
mov EndPointX, 595d
mov EndPointY,45d
mov linecolor,0CH
call DrawLine

mov StartPointX, 45d
mov StartPointY, 315d
mov EndPointX, 596d
mov EndPointY,369d
mov linecolor,0CH
call DrawLine

mov StartPointX, 45d
mov StartPointY, 45d
mov EndPointX, 45d
mov EndPointY,315d
mov linecolor,0CH
call DrawLine

mov StartPointX, 595d
mov StartPointY, 45d
mov EndPointX, 595d
mov EndPointY,315d
mov linecolor,0CH
call DrawLine

; Second siege

mov StartPointX, 90d
mov StartPointY, 90d
mov EndPointX, 550d
mov EndPointY,90d
mov linecolor,0CH
call DrawLine

mov StartPointX, 90d
mov StartPointY,270d
mov EndPointX, 551d
mov EndPointY,271d
mov linecolor,0CH
call DrawLine

mov StartPointX, 90d
mov StartPointY, 90d
mov EndPointX, 90d
mov EndPointY,270d
mov linecolor,0CH
call DrawLine

mov StartPointX, 550d
mov StartPointY, 90d
mov EndPointX, 550d
mov EndPointY,270d
mov linecolor,0CH
call DrawLine

; Third siege

mov StartPointX, 135d
mov StartPointY, 135d
mov EndPointX, 505d
mov EndPointY,135d
mov linecolor,0CH
call DrawLine

mov StartPointX, 135d
mov StartPointY,225d
mov EndPointX, 506d
mov EndPointY,226d
mov linecolor,0CH
call DrawLine

mov StartPointX, 135d
mov StartPointY, 135d
mov EndPointX, 135d
mov EndPointY,225d
mov linecolor,0CH
call DrawLine

mov StartPointX, 505d
mov StartPointY, 135d
mov EndPointX, 505d
mov EndPointY,225d
mov linecolor,0CH
call DrawLine

;DrawUpperGates

mov StartPointX, 295d
mov StartPointY, 45d
mov EndPointX, 345d
mov EndPointY,45d
mov linecolor,0
call DrawLine

mov StartPointX, 295d
mov StartPointY, 135d
mov EndPointX, 345d
mov EndPointY,135d
mov linecolor,0
call DrawLine


;DrawLowerGates

mov StartPointX, 295d
mov StartPointY, 360-45d
mov EndPointX, 345d
mov EndPointY,360-45d
mov linecolor,0
call DrawLine

mov StartPointX, 295d
mov StartPointY, 360-45d-90d
mov EndPointX, 345d
mov EndPointY,360d-45d-90d
mov linecolor,0
call DrawLine


;DrawLeftGates

mov StartPointX, 90d
mov StartPointY, 155d
mov EndPointX, 90d
mov EndPointY,205d
mov linecolor,0
call DrawLine


;DrawRightGates

mov StartPointX, 550d
mov StartPointY, 155d
mov EndPointX, 550d
mov EndPointY,205d
mov linecolor,0
call DrawLine


;Status Bar;
mov StartPointX,0d
mov StartPointY,459d
mov EndPointX,320d
mov EndPointY,459d
mov Linecolor,3d
call DrawLine

mov StartPointX,320d
mov StartPointY,359d
mov EndPointX,320d
mov EndPointY,459d
mov Linecolor,3d
call DrawLine

mov StartPointX,320d
mov StartPointY,459d
mov EndPointX,639d
mov EndPointY,459d
mov Linecolor,3d
call DrawLine




ENDM SetMap
