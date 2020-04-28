;.global main

	AREA |.text|, CODE, READONLY, ALIGN=2
;    INCLUDE msp432.h
	THUMB
		
;stkptr      DCD 0x20000200
	
__main	; Code entry

_init	; Disable watchdog timer

main ; <Add your code here>
	LDR R0,=0x11223344
	LDR R1,=0x44332211
	LDR R2,=0x00000002
	LDR R3,=0x0000000A
	PUSH {R0,R1,R2,R3,LR}
	BL Math1
	POP {R4}
	POP {R0,R1,R2,R3,LR}
stop    B   stop
Math1 LDR R0,=0x20000200
	LDR R1,[R0,#-20]
	LDR R2,[R0,#-16]
	ADD R4,R1,R2
	PUSH {R4}
	PUSH {LR}
	BL Math2
	POP {R5,LR}
	BX LR
Math2 LDR R0,=0x20000200
	LDR R1,[R0,#-24]
	LDR R2,[R0,#-12]
	LDR R3,[R0,#-8]
	MUL R4,R1,R2
	UDIV R5,R4,R3
	PUSH {R5}
	BX LR

        NOP

str		DCB "Foo",0

	EXPORT __main
	EXPORT main
	END
		
