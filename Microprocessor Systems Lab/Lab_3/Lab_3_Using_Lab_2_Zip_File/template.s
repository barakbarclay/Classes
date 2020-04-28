;.global main

	AREA |.text|, CODE, READONLY, ALIGN=2
;    INCLUDE msp432.h
	THUMB

__main	; Code entry

_init	; Disable watchdog timer

main	; <Add your code here>
		
		MOV	R0, #0x00000000
		MOV	R1, #0x00000009
		MOV	R2, #0x20000000
		MOV	R3, #0x00000010
		MOV	R4, #0x00000019
		MOV	R5, #0x00000000
		MOV	R6, #0x00000000
		MOV	R7, #0x00000000
		
loop	STRB R0,[R2],#1
		ADD R0,R0,#0x00000001
		CMP R0,R1
		BGT loop2
		B	loop
		
loop2	STRB R3,[R2],#1
		ADD R3,R3,#0x00000001
		CMP R3,R4
		BGT addints
		B	loop2
		
addints	MOV	R0, #0x00000000
		MOV	R1, #0x00000009
		MOV	R2, #0x20000000	
loop3	LDRB R7,[R2],#1
		ADD R5,R5,R7
		ADD R0,R0,#0x00000001
		CMP R0,R1
		BGT subints
		B	loop3
		
subints	MOV	R0, #0x00000000
		MOV	R1, #0x00000000
		MOV	R2, #0x20000000
		LDRB R0,[R2],#1
		LDRB R1,[R2]
		SUBS R6,R0,R1
		
stop    B   stop
        NOP

str		DCB "Foo",0

	EXPORT __main
	EXPORT main
	END
		
