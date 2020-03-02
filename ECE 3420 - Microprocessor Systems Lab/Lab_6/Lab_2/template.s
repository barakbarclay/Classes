;.global main

	AREA |.text|, CODE, READONLY, ALIGN=2
;    INCLUDE msp432.h
	THUMB

P1IN      EQU     0x40004C00  ; Port 1 Input
P2IN      EQU     0x40004C01  ; Port 2 Input
P2OUT     EQU     0x40004C03  ; Port 2 Output
P1OUT     EQU     0x40004C02  ; Port 1 Output
P1DIR     EQU     0x40004C04  ; Port 1 Direction
P2DIR     EQU     0x40004C05  ; Port 2 Direction
P1REN     EQU     0x40004C06  ; Port 1 Resistor Enable
P2REN     EQU     0x40004C07  ; Port 2 Resistor Enable
P1DS      EQU     0x40004C08  ; Port 1 Drive Strength
P2DS      EQU     0x40004C09  ; Port 2 Drive Strength
P1SEL0    EQU     0x40004C0A  ; Port 1 Select 0
P2SEL0    EQU     0x40004C0B  ; Port 2 Select 0
P1SEL1    EQU     0x40004C0C  ; Port 1 Select 1
P2SEL1    EQU     0x40004C0D  ; Port 2 Select 1
P1SELC    EQU     0x40004C16  ; Port 1 Complement Select
P2SELC    EQU     0x40004C17  ; Port 2 Complement Select
P1IES     EQU     0x40004C18  ; Port 1 Interrupt Edge Select
P2IES     EQU     0x40004C19  ; Port 2 Interrupt Edge Select
P1IE      EQU     0x40004C1A  ; Port 1 Interrupt Enable
P2IE      EQU     0x40004C1B  ; Port 2 Interrupt Enable
P1IFG     EQU     0x40004C1C  ; Port 1 Interrupt Flag
P2IFG     EQU     0x40004C1D  ; Port 2 Interrupt Flag
 
NVIC_IPR0    EQU     0xE000E400   ; Irq 0 to 3 Priority Register */
NVIC_IPR1    EQU     0xE000E404   ; Irq 4 to 7 Priority Register */
NVIC_IPR2    EQU     0xE000E408   ; Irq 8 to 11 Priority Register */
NVIC_IPR3    EQU     0xE000E40C   ; Irq 12 to 15 Priority Register */
NVIC_IPR4    EQU     0xE000E410   ; Irq 16 to 19 Priority Register */
NVIC_IPR5    EQU     0xE000E414   ; Irq 20 to 23 Priority Register */
NVIC_IPR6    EQU     0xE000E418   ; Irq 24 to 27 Priority Register */
NVIC_IPR7    EQU     0xE000E41C   ; Irq 28 to 31 Priority Register */
NVIC_IPR8    EQU     0xE000E420   ; Irq 32 to 35 Priority Register */
NVIC_IPR9    EQU     0xE000E424   ; Irq 36 to 39 Priority Register */
NVIC_IPR10   EQU     0xE000E428   ; Irq 40 to 43 Priority Register */
NVIC_IPR11   EQU     0xE000E42C   ; Irq 44 to 47 Priority Register */
NVIC_IPR12   EQU     0xE000E430   ; Irq 48 to 51 Priority Register */
NVIC_IPR13   EQU     0xE000E434   ; Irq 52 to 55 Priority Register */
NVIC_IPR14   EQU     0xE000E438   ; Irq 56 to 59 Priority Register */
NVIC_IPR15   EQU     0xE000E43C   ; Irq 60 to 63 Priority Register */
 
 
NVIC_ISER0  EQU 0xE000E100  ; Enable IRQ 31-0
NVIC_ISER1  EQU 0xE000E104  ; Enable IRQ 47-32
 
NVIC_ICER0  EQU 0xE000E180  ; Disable IRQ 31-0
NVIC_ICER1  EQU 0xE000E184  ; Disable IRQ 47-32

__main	; Code entry

_init	; Disable watchdog timer

main	; <Add your code here>
		
loop	LDR   	R0, =P1IN 	; R0 holds the port address
		LDR   	R1, [R0]		; R1 contains all 1’s
		CMP		R1, #0x0
		BEQ		sub1
		BNE		sub2
		
		B   loop
sub1	LDR		R2, =P1OUT
		LDR		R3, =0x00000000
		STR		R3, [R2]
		B	loop
sub2	LDR		R2, =P1OUT
		LDR		R3, =0x11111111
		STR		R3, [R2]
        NOP

str		DCB "Foo",0

	EXPORT __main
	EXPORT main
	END
		
