; haribote-os
; TAB=4

;		ORG		0xc200			; このプログラムがどこに読み込まれるのか
;fin:
;		HLT
;		JMP		fin

; haribote-os
; TAB=4
ORG 0xc200 ; ?个程序将要被装?到内存的什?地方?？
MOV AL,0x6a ; VGA??，320x200x8位彩色
MOV AH,0x00
INT 0x10
fin:
HLT
JMP fin