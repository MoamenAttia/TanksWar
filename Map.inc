include DrawLine.inc
SetMap MACRO 

; Frame
DrawLine 0d,0d,639d,0d,3
DrawLine 0d,479d,640d,480d,3
DrawLine 0d,0d,0d,479d,3
DrawLine 639d,0d,639d,479d,3

; First siege
DrawLine 40d,40d,600d,40d,0CH
DrawLine 40d,440d,601d,441d,0CH
DrawLine 40d,40d,40d,440d,0CH
DrawLine 600d,40d,600d,440d,0CH

; Second siege
DrawLine 80d,80d,560d,80d,0CH
DrawLine 80d,400d,561d,401d,0CH
DrawLine 80d,80d,80d,400d,0CH
DrawLine 560d,80d,560d,400d,0CH

; Third siege
DrawLine 120d,120d,520d,120d,0CH
DrawLine 120d,360d,521d,361d,0CH
DrawLine 120d,120d,120d,360d,0CH
DrawLine 520d,120d,520d,360d,0CH

; Forth siege
DrawLine 160d,160d,480d,160d,0CH
DrawLine 160d,320d,481d,321d,0CH
DrawLine 160d,160d,160d,320d,0CH
DrawLine 480d,160d,480d,320d,0CH

; Fifth siege
DrawLine 200d,200d,440d,200d,0CH
DrawLine 200d,280d,441d,281d,0CH
DrawLine 200d,200d,200d,280d,0CH
DrawLine 440d,200d,440d,280d,0CH

;DrawUpperGates
DrawLine 300d,40d,340d,40d,0
DrawLine 300d,120d,340d,120d,0
DrawLine 300d,200d,340d,200d,0

;DrawLowerGates
DrawLine 300d,480-40d,340d,480-40d,0
DrawLine 300d,480-120d,340d,480-120d,0
DrawLine 300d,480-200d,340d,480-200d,0

;DrawLeftGates
DrawLine 80d,220d,80d,260d,0
DrawLine 160d,220d,160d,260d,0
DrawLine 240d,220d,240d,260d,0

;DrawRightGates
DrawLine 640-80d ,220d ,640-80d,260d,0
DrawLine 640-160d,220d,640-160d,260d,0
DrawLine 640-240d,220d,640-240d,260d,0

ENDM SetMap