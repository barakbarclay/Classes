;.global main

	AREA |.text|, CODE, READONLY, ALIGN=2
;    INCLUDE msp432.h
	THUMB

__main	; Code entry

_init	; Disable watchdog timer

main	; <Add your code here>
		
		
		
		
		
		
		
		
stop    B   stop
        NOP

str		DCB "Foo",0

	EXPORT __main
	EXPORT main
	END
		
