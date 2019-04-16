[BITS 32]
		mov eax,[0x1000]
		; mov ebx, [eax]
		MOV		AL,'h'
		CALL    2*8:ebx
		; CALL    2*8:0xbe8
		; MOV		AL,'e'
		; CALL    2*8:0xbe8
		; MOV		AL,'l'
		; CALL    2*8:0xbe8
		; MOV		AL,'l'
		; CALL    2*8:0xbe8
		; MOV		AL,'o'
		; CALL    2*8:0xbe8
		RETF
