SetMap2 MACRO

;Frame
mov word ptr StartPointX, 0d
mov word ptr StartPointY, 0d
mov word ptr EndPointX, 639d
mov word ptr EndPointY,0d
mov linecolor,3
call DrawLine

mov word ptr StartPointX, 0d
mov word ptr StartPointY, 359d
mov word ptr EndPointX, 639d
mov word ptr EndPointY,359d
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



;First siege

mov word ptr StartPointX, 45d
mov word ptr StartPointY, 45d
mov word ptr EndPointX, 90d
mov word ptr EndPointY,45d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 45d
mov word ptr StartPointY, 315d
mov word ptr EndPointX, 90d
mov word ptr EndPointY,315d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 45d
mov word ptr StartPointY, 45d
mov word ptr EndPointX, 45d
mov word ptr EndPointY,315d
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX, 90d
mov word ptr StartPointY, 45d
mov word ptr EndPointX, 90d
mov word ptr EndPointY,315d
mov linecolor,0CH
call DrawLine

;Second Block

mov word ptr StartPointX, 135d
mov word ptr StartPointY, 45d
mov word ptr EndPointX, 180d
mov word ptr EndPointY,45
mov linecolor,0CH
call DrawLine

mov word ptr StartPointX,135d
mov word ptr StartPointY,45d
mov word ptr EndPointX,135d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,180d
mov word ptr StartPointY,45d
mov word ptr EndPointX,180d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,135d
mov word ptr StartPointY,315d
mov word ptr EndPointX,180d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine


;Third block
mov word ptr StartPointX,225
mov word ptr StartPointY,45d
mov word ptr EndPointX,270d
mov word ptr EndPointY,45d
mov Linecolor,0CH
call DrawLine


mov word ptr StartPointX,225
mov word ptr StartPointY,45d
mov word ptr EndPointX,225
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,270
mov word ptr StartPointY,45d
mov word ptr EndPointX,270
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,225
mov word ptr StartPointY,315d
mov word ptr EndPointX,270
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine


;Forth block
mov word ptr StartPointX,360d
mov word ptr StartPointY,45d
mov word ptr EndPointX,405d
mov word ptr EndPointY,45d
mov Linecolor,0CH
call DrawLine


mov word ptr StartPointX,360d
mov word ptr StartPointY,45d
mov word ptr EndPointX,360d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,405d
mov word ptr StartPointY,45d
mov word ptr EndPointX,405d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,360d
mov word ptr StartPointY,315d
mov word ptr EndPointX,405d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine


;Fifth block
mov word ptr StartPointX,450d
mov word ptr StartPointY,45d
mov word ptr EndPointX,495d
mov word ptr EndPointY,45d
mov Linecolor,0CH
call DrawLine


mov word ptr StartPointX,450d
mov word ptr StartPointY,45d
mov word ptr EndPointX,450d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,495d
mov word ptr StartPointY,45d
mov word ptr EndPointX,495d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,450d
mov word ptr StartPointY,315d
mov word ptr EndPointX,495d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

;Sixth block
mov word ptr StartPointX,540d
mov word ptr StartPointY,45d
mov word ptr EndPointX,585d
mov word ptr EndPointY,45d
mov Linecolor,0CH
call DrawLine


mov word ptr StartPointX,585d
mov word ptr StartPointY,45d
mov word ptr EndPointX,585d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,540d
mov word ptr StartPointY,45d
mov word ptr EndPointX,540d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,540d
mov word ptr StartPointY,315d
mov word ptr EndPointX,585d
mov word ptr EndPointY,315d
mov Linecolor,0CH
call DrawLine

;Status Bar;
mov word ptr StartPointX,0d
mov word ptr StartPointY,459d
mov word ptr EndPointX,320d
mov word ptr EndPointY,459d;
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
mov Linecolor,3d
call DrawLine


;Draw Obstacles
mov word ptr StartPointX,1d
mov word ptr StartPointY,90d
mov word ptr EndPointX,639d
mov word ptr EndPointY,90d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,1d
mov word ptr StartPointY,180d
mov word ptr EndPointX,639d
mov word ptr EndPointY,180d
mov Linecolor,0CH
call DrawLine

mov word ptr StartPointX,1d
mov word ptr StartPointY,270d
mov word ptr EndPointX,639d
mov word ptr EndPointY,270d
mov Linecolor,0CH
call DrawLine

;Removing Obstacles
mov word ptr StartPointX,46d
mov word ptr StartPointY,90d
mov word ptr EndPointX,90d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,46d
mov word ptr StartPointY,180d
mov word ptr EndPointX,90d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,46d
mov word ptr StartPointY,270d
mov word ptr EndPointX,90d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine

;Removing Obstacles
mov word ptr StartPointX,136d
mov word ptr StartPointY,90d
mov word ptr EndPointX,180d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,136d
mov word ptr StartPointY,180d
mov word ptr EndPointX,180d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,136d
mov word ptr StartPointY,270d
mov word ptr EndPointX,180d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine

;Removing Obstacles
mov word ptr StartPointX,226d
mov word ptr StartPointY,90d
mov word ptr EndPointX,270d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,226d
mov word ptr StartPointY,180d
mov word ptr EndPointX,270d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,226d
mov word ptr StartPointY,270d
mov word ptr EndPointX,270d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine

;Removing Obstacles
mov word ptr StartPointX,361d
mov word ptr StartPointY,90d
mov word ptr EndPointX,405d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,361d
mov word ptr StartPointY,180d
mov word ptr EndPointX,405d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,361d
mov word ptr StartPointY,270d
mov word ptr EndPointX,405d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine


;Removing Obstacles
mov word ptr StartPointX,451d
mov word ptr StartPointY,90d
mov word ptr EndPointX,495d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,451d
mov word ptr StartPointY,180d
mov word ptr EndPointX,495d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,451d
mov word ptr StartPointY,270d
mov word ptr EndPointX,495d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine

;Removing Obstacles
mov word ptr StartPointX,541d
mov word ptr StartPointY,90d
mov word ptr EndPointX,585d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,541d
mov word ptr StartPointY,180d
mov word ptr EndPointX,585d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,541d
mov word ptr StartPointY,270d
mov word ptr EndPointX,585d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine




;Removing Points
mov word ptr StartPointX,91d
mov word ptr StartPointY,90d
mov word ptr EndPointX,92d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,91d
mov word ptr StartPointY,180d
mov word ptr EndPointX,92d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,91d
mov word ptr StartPointY,270d
mov word ptr EndPointX,92d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine

;Removing Points
mov word ptr StartPointX,44d
mov word ptr StartPointY,90d
mov word ptr EndPointX,45d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,44d
mov word ptr StartPointY,180d
mov word ptr EndPointX,45d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,44d
mov word ptr StartPointY,270d
mov word ptr EndPointX,45d             
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine




;Removing Points
mov word ptr StartPointX,181d
mov word ptr StartPointY,90d
mov word ptr EndPointX,182d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,181d
mov word ptr StartPointY,180d
mov word ptr EndPointX,182d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,181d
mov word ptr StartPointY,270d
mov word ptr EndPointX,182d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine

;Removing Points
mov word ptr StartPointX,134d
mov word ptr StartPointY,90d
mov word ptr EndPointX,135d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,134d
mov word ptr StartPointY,180d
mov word ptr EndPointX,135d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,134d
mov word ptr StartPointY,270d
mov word ptr EndPointX,135d          
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine




;Removing Points
mov word ptr StartPointX,271d
mov word ptr StartPointY,90d
mov word ptr EndPointX,272d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,271d
mov word ptr StartPointY,180d
mov word ptr EndPointX,272d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,271d
mov word ptr StartPointY,270d
mov word ptr EndPointX,272d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine

;Removing Points
mov word ptr StartPointX,224d
mov word ptr StartPointY,90d
mov word ptr EndPointX,225d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,224d
mov word ptr StartPointY,180d
mov word ptr EndPointX,225d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,224d
mov word ptr StartPointY,270d
mov word ptr EndPointX,225d        
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine



;Removing Points
mov word ptr StartPointX,406d
mov word ptr StartPointY,90d
mov word ptr EndPointX,407d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,406d
mov word ptr StartPointY,180d
mov word ptr EndPointX,407d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,406d
mov word ptr StartPointY,270d
mov word ptr EndPointX,407d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine

;Removing Points
mov word ptr StartPointX,359d
mov word ptr StartPointY,90d
mov word ptr EndPointX,360d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,359d
mov word ptr StartPointY,180d
mov word ptr EndPointX,360d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,359d
mov word ptr StartPointY,270d
mov word ptr EndPointX,360d      
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine



;Removing Points
mov word ptr StartPointX,496d
mov word ptr StartPointY,90d
mov word ptr EndPointX,497d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,496d
mov word ptr StartPointY,180d
mov word ptr EndPointX,497d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,496d
mov word ptr StartPointY,270d
mov word ptr EndPointX,497d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine

;Removing Points
mov word ptr StartPointX,449d
mov word ptr StartPointY,90d
mov word ptr EndPointX,450d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,449d
mov word ptr StartPointY,180d
mov word ptr EndPointX,450d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,449d
mov word ptr StartPointY,270d
mov word ptr EndPointX,450d    
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine



;Removing Points
mov word ptr StartPointX,586d
mov word ptr StartPointY,90d
mov word ptr EndPointX,587d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,586d
mov word ptr StartPointY,180d
mov word ptr EndPointX,587d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,586d
mov word ptr StartPointY,270d
mov word ptr EndPointX,587d
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine

;Removing Points
mov word ptr StartPointX,539d
mov word ptr StartPointY,90d
mov word ptr EndPointX,540d
mov word ptr EndPointY,90d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,539d
mov word ptr StartPointY,180d
mov word ptr EndPointX,540d
mov word ptr EndPointY,180d
mov Linecolor,0
call DrawLine

mov word ptr StartPointX,539d
mov word ptr StartPointY,270d
mov word ptr EndPointX,540d  
mov word ptr EndPointY,270d
mov Linecolor,0
call DrawLine

ENDM SetMap2
