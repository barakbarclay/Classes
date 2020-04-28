;.global main

	AREA |.text|, CODE, READONLY, ALIGN=2
;    INCLUDE msp432.h
	THUMB

__main ; 

_init ; Disable watchdog timer

main ; <Add your code here>
	LDR R0,=0x0000000F ;15 in hex
	LDR R1,=0x00000010 ;16 in hex
	LDR R2,=0x0000000A ;10 in hex
	PUSH {R0,R1,R2}
	BL f
	POP {R3}
	POP {R0,R1,R2}
stop    B   stop
f 	LDR R0,=0x20000200
	LDR R1,[R0,#-12]
	LDR R2,[R0,#-8]
	ADD R3,R1,R2
	LDR R1,[R0,#-4]
	SUB R3,R3,R1
	LDR R0,=0x00000002
	MUL R3,R3,R0
	PUSH {R3}
	BX LR
        NOP

str		DCB "Foo",0

	EXPORT __main
	EXPORT main
	END
		
