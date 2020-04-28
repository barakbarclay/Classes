; MSP432p401r Peripheral Register Address list
; Ripped from the msp432p401r_classic.h file
; Created by Joe Leach
; Please report errors to jleach@uccs.edu
; --------------------------------------------
; This must be in the root of your Keil project
; You must add this to your assembly file with the preprocessor directive "INCLUDE msp432p401r.s" statement

	AREA |.text|, CODE, READONLY, ALIGN=2
	THUMB

_MAIN_MEMORY_START__	EQU	0x00000000	; !< Main Flash memory start address  
__MAIN_MEMORY_END__	    EQU	0x0003FFFF	; !< Main Flash memory end address	 
__BSL_MEMORY_START__	EQU	0x00202000	; !< BSL memory start address	 
__BSL_MEMORY_END__	    EQU	0x00203FFF	; !< BSL memory end address  
__SRAM_START__			EQU	0x20000000	; !< SRAM memory start address  
__SRAM_END__			EQU	0x2000FFFF	; !< SRAM memory end address	
	
NVIC_IPR0   EQU  0xE000E400   ; Irq 0 to 3 Priority Register */
NVIC_IPR1   EQU  0xE000E404   ; Irq 4 to 7 Priority Register */
NVIC_IPR2   EQU  0xE000E408   ; Irq 8 to 11 Priority Register */
NVIC_IPR3   EQU  0xE000E40C   ; Irq 12 to 15 Priority Register */
NVIC_IPR4   EQU  0xE000E410   ; Irq 16 to 19 Priority Register */
NVIC_IPR5   EQU  0xE000E414   ; Irq 20 to 23 Priority Register */
NVIC_IPR6   EQU  0xE000E418   ; Irq 24 to 27 Priority Register */
NVIC_IPR7   EQU  0xE000E41C   ; Irq 28 to 31 Priority Register */
NVIC_IPR8   EQU  0xE000E420   ; Irq 32 to 35 Priority Register */
NVIC_IPR9   EQU  0xE000E424   ; Irq 36 to 39 Priority Register */
NVIC_IPR10  EQU  0xE000E428   ; Irq 40 to 43 Priority Register */
NVIC_IPR11  EQU  0xE000E42C   ; Irq 44 to 47 Priority Register */
NVIC_IPR12  EQU  0xE000E430   ; Irq 48 to 51 Priority Register */
NVIC_IPR13  EQU  0xE000E434   ; Irq 52 to 55 Priority Register */
NVIC_IPR14  EQU  0xE000E438   ; Irq 56 to 59 Priority Register */
NVIC_IPR15	EQU	 0xE000E43C   ; Irq 60 to 63 Priority Register */
 
NVIC_ISER0	EQU	0xE000E100  ; Enable IRQ 31-0
NVIC_ISER1	EQU 0xE000E104  ; Enable IRQ 47-32
NVIC_ICER0	EQU 0xE000E180  ; Disable IRQ 31-0
NVIC_ICER1	EQU 0xE000E184  ; Disable IRQ 47-32

AESACTL0	EQU	0x40003C00	; !< AES Accelerator Control Register 0	 
AESACTL1	EQU	0x40003C02	; !< AES Accelerator Control Register 1	 
AESASTAT	EQU	0x40003C04	; !< AES Accelerator Status Register  
AESAKEY		EQU	0x40003C06	; !< AES Accelerator Key Register	
AESADIN		EQU	0x40003C08	; !< AES Accelerator Data In Register  
AESADOUT	EQU	0x40003C0A	; !< AES Accelerator Data Out Register	
AESAXDIN	EQU	0x40003C0C	; !< AES Accelerator XORed Data In Register	
AESAXIN		EQU	0x40003C0E	; !< AES Accelerator XORed Data In Register	
	
CAPTIO0CTL	EQU	0x4000540E	; !< Capacitive Touch IO x Control Register	
CAPTIO1CTL	EQU	0x4000580E	; !< Capacitive Touch IO x Control Register	
	
CE0CTL0		EQU	0x40003400	; !< Comparator Control Register 0	 
CE0CTL1		EQU	0x40003402	; !< Comparator Control Register 1	 
CE0CTL2		EQU	0x40003404	; !< Comparator Control Register 2	 
CE0CTL3		EQU	0x40003406	; !< Comparator Control Register 3	 
CE0INT		EQU	0x4000340C	; !< Comparator Interrupt Control Register  
CE0IV		EQU	0x4000340E	; !< Comparator Interrupt Vector Word Register  
CE1CTL0		EQU	0x40003800	; !< Comparator Control Register 0	 
CE1CTL1		EQU	0x40003802	; !< Comparator Control Register 1	 
CE1CTL2		EQU	0x40003804	; !< Comparator Control Register 2	 
CE1CTL3		EQU	0x40003806	; !< Comparator Control Register 3	 
CE1INT		EQU	0x4000380C	; !< Comparator Interrupt Control Register  
CE1IV		EQU	0x4000380E	; !< Comparator Interrupt Vector Word Register  
	
CRC32DI			EQU	0x40004000	; !< Data Input for CRC32 Signature Computation  
CRC32DIRB		EQU	0x40004004	; !< Data In Reverse for CRC32 Computation  
CRC32INIRES_LO	EQU	0x40004008	; !< CRC32 Initialization and Result, lower 16 bits  
CRC32INIRES_HI	EQU	0x4000400A	; !< CRC32 Initialization and Result, upper 16 bits  
CRC32RESR_LO	EQU	0x4000400C	; !< CRC32 Result Reverse, lower 16 bits  
CRC32RESR_HI	EQU	0x4000400E	; !< CRC32 Result Reverse, Upper 16 bits  
CRC16DI			EQU	0x40004010	; !< Data Input for CRC16 computation  
CRC16DIRB		EQU	0x40004014	; !< CRC16 Data In Reverse  
CRC16INIRES		EQU	0x40004018	; !< CRC16 Initialization and Result register  
CRC16RESR		EQU	0x4000401E	; !< CRC16 Result Reverse 
	
PAIN		EQU	0x40004C00	; !< Port A Input  
PAOUT		EQU	0x40004C02	; !< Port A Output	
PADIR		EQU	0x40004C04	; !< Port A Direction  
PAREN		EQU	0x40004C06	; !< Port A Resistor Enable  
PADS		EQU	0x40004C08	; !< Port A Drive Strength  
PASEL0		EQU	0x40004C0A	; !< Port A Select 0  
PASEL1		EQU	0x40004C0C	; !< Port A Select 1  
P1IV		EQU	0x40004C0E	; !< Port 1 Interrupt Vector Register  
PASELC		EQU	0x40004C16	; !< Port A Complement Select	 
PAIES		EQU	0x40004C18	; !< Port A Interrupt Edge Select	
PAIE		EQU	0x40004C1A	; !< Port A Interrupt Enable	
PAIFG		EQU	0x40004C1C	; !< Port A Interrupt Flag  
P2IV		EQU	0x40004C1E	; !< Port 2 Interrupt Vector Register  
PBIN		EQU	0x40004C20	; !< Port B Input  
PBOUT		EQU	0x40004C22	; !< Port B Output	
PBDIR		EQU	0x40004C24	; !< Port B Direction  
PBREN		EQU	0x40004C26	; !< Port B Resistor Enable  
PBDS		EQU	0x40004C28	; !< Port B Drive Strength  
PBSEL0		EQU	0x40004C2A	; !< Port B Select 0  
PBSEL1		EQU	0x40004C2C	; !< Port B Select 1  
P3IV		EQU	0x40004C2E	; !< Port 3 Interrupt Vector Register  
PBSELC		EQU	0x40004C36	; !< Port B Complement Select	 
PBIES		EQU	0x40004C38	; !< Port B Interrupt Edge Select	
PBIE		EQU	0x40004C3A	; !< Port B Interrupt Enable	
PBIFG		EQU	0x40004C3C	; !< Port B Interrupt Flag  
	
P4IV		EQU	0x40004C3E	; !< Port 4 Interrupt Vector Register  
PCIN		EQU	0x40004C40	; !< Port C Input  
PCOUT		EQU	0x40004C42	; !< Port C Output	
PCDIR		EQU	0x40004C44	; !< Port C Direction  
PCREN		EQU	0x40004C46	; !< Port C Resistor Enable  
PCDS		EQU	0x40004C48	; !< Port C Drive Strength  
PCSEL0		EQU	0x40004C4A	; !< Port C Select 0  
PCSEL1		EQU	0x40004C4C	; !< Port C Select 1  
P5IV		EQU	0x40004C4E	; !< Port 5 Interrupt Vector Register  
PCSELC		EQU	0x40004C56	; !< Port C Complement Select	 
PCIES		EQU	0x40004C58	; !< Port C Interrupt Edge Select	
PCIE		EQU	0x40004C5A	; !< Port C Interrupt Enable	
PCIFG		EQU	0x40004C5C	; !< Port C Interrupt Flag  
P6IV		EQU	0x40004C5E	; !< Port 6 Interrupt Vector Register  
PDIN		EQU	0x40004C60	; !< Port D Input  
PDOUT		EQU	0x40004C62	; !< Port D Output	
PDDIR		EQU	0x40004C64	; !< Port D Direction  
PDREN		EQU	0x40004C66	; !< Port D Resistor Enable  
PDDS		EQU	0x40004C68	; !< Port D Drive Strength  
PDSEL0		EQU	0x40004C6A	; !< Port D Select 0  
PDSEL1		EQU	0x40004C6C	; !< Port D Select 1  
P7IV		EQU	0x40004C6E	; !< Port 7 Interrupt Vector Register  
PDSELC		EQU	0x40004C76	; !< Port D Complement Select	 
PDIES		EQU	0x40004C78	; !< Port D Interrupt Edge Select	
PDIE		EQU	0x40004C7A	; !< Port D Interrupt Enable	
PDIFG		EQU	0x40004C7C	; !< Port D Interrupt Flag  
P8IV		EQU	0x40004C7E	; !< Port 8 Interrupt Vector Register  
PEIN		EQU	0x40004C80	; !< Port E Input  
PEOUT		EQU	0x40004C82	; !< Port E Output	
PEDIR		EQU	0x40004C84	; !< Port E Direction  
PEREN		EQU	0x40004C86	; !< Port E Resistor Enable  
PEDS		EQU	0x40004C88	; !< Port E Drive Strength  
PESEL0		EQU	0x40004C8A	; !< Port E Select 0  
PESEL1		EQU	0x40004C8C	; !< Port E Select 1  
P9IV		EQU	0x40004C8E	; !< Port 9 Interrupt Vector Register  
PESELC		EQU	0x40004C96	; !< Port E Complement Select	 
PEIES		EQU	0x40004C98	; !< Port E Interrupt Edge Select	
PEIE		EQU	0x40004C9A	; !< Port E Interrupt Enable	
PEIFG		EQU	0x40004C9C	; !< Port E Interrupt Flag  
P10IV		EQU	0x40004C9E	; !< Port 10 Interrupt Vector Register	
PJIN		EQU	0x40004D20	; !< Port J Input  
PJOUT		EQU	0x40004D22	; !< Port J Output	
PJDIR		EQU	0x40004D24	; !< Port J Direction  
PJREN		EQU	0x40004D26	; !< Port J Resistor Enable  
PJDS		EQU	0x40004D28	; !< Port J Drive Strength  
PJSEL0		EQU	0x40004D2A	; !< Port J Select 0  
PJSEL1		EQU	0x40004D2C	; !< Port J Select 1  
PJSELC		EQU	0x40004D36	; !< Port J Complement Select	 
	
P1IN		EQU	0x40004C00	; !< Port 1 Input  
P2IN		EQU	0x40004C01	; !< Port 2 Input  
P2OUT		EQU	0x40004C03	; !< Port 2 Output	
P1OUT		EQU	0x40004C02	; !< Port 1 Output	
P1DIR		EQU	0x40004C04	; !< Port 1 Direction  
P2DIR		EQU	0x40004C05	; !< Port 2 Direction  
P1REN		EQU	0x40004C06	; !< Port 1 Resistor Enable  
P2REN		EQU	0x40004C07	; !< Port 2 Resistor Enable  
P1DS		EQU	0x40004C08	; !< Port 1 Drive Strength  
P2DS		EQU	0x40004C09	; !< Port 2 Drive Strength  
P1SEL0		EQU	0x40004C0A	; !< Port 1 Select 0  
P2SEL0		EQU	0x40004C0B	; !< Port 2 Select 0  
P1SEL1		EQU	0x40004C0C	; !< Port 1 Select 1  
P2SEL1		EQU	0x40004C0D	; !< Port 2 Select 1  
P1SELC		EQU	0x40004C16	; !< Port 1 Complement Select	 
P2SELC		EQU	0x40004C17	; !< Port 2 Complement Select	 
P1IES		EQU	0x40004C18	; !< Port 1 Interrupt Edge Select	
P2IES		EQU	0x40004C19	; !< Port 2 Interrupt Edge Select	
P1IE		EQU	0x40004C1A	; !< Port 1 Interrupt Enable	
P2IE		EQU	0x40004C1B	; !< Port 2 Interrupt Enable	
P1IFG		EQU	0x40004C1C	; !< Port 1 Interrupt Flag  
P2IFG		EQU	0x40004C1D	; !< Port 2 Interrupt Flag  
P3IN		EQU	0x40004C20	; !< Port 3 Input  
P4IN		EQU	0x40004C21	; !< Port 4 Input  
P3OUT		EQU	0x40004C22	; !< Port 3 Output	
P4OUT		EQU	0x40004C23	; !< Port 4 Output	
P3DIR		EQU	0x40004C24	; !< Port 3 Direction  
P4DIR		EQU	0x40004C25	; !< Port 4 Direction  
P3REN		EQU	0x40004C26	; !< Port 3 Resistor Enable  
P4REN		EQU	0x40004C27	; !< Port 4 Resistor Enable  
P3DS		EQU	0x40004C28	; !< Port 3 Drive Strength  
P4DS		EQU	0x40004C29	; !< Port 4 Drive Strength  
P4SEL0		EQU	0x40004C2B	; !< Port 4 Select 0  
P3SEL0		EQU	0x40004C2A	; !< Port 3 Select 0  
P3SEL1		EQU	0x40004C2C	; !< Port 3 Select 1  
P4SEL1		EQU	0x40004C2D	; !< Port 4 Select 1  
P3SELC		EQU	0x40004C36	; !< Port 3 Complement Select	 
P4SELC		EQU	0x40004C37	; !< Port 4 Complement Select	 
P3IES		EQU	0x40004C38	; !< Port 3 Interrupt Edge Select	
P4IES		EQU	0x40004C39	; !< Port 4 Interrupt Edge Select	
P3IE		EQU	0x40004C3A	; !< Port 3 Interrupt Enable	
P4IE		EQU	0x40004C3B	; !< Port 4 Interrupt Enable	
P3IFG		EQU	0x40004C3C	; !< Port 3 Interrupt Flag  
P4IFG		EQU	0x40004C3D	; !< Port 4 Interrupt Flag  
P5IN		EQU	0x40004C40	; !< Port 5 Input  
P6IN		EQU	0x40004C41	; !< Port 6 Input  
P5OUT		EQU	0x40004C42	; !< Port 5 Output	
P6OUT		EQU	0x40004C43	; !< Port 6 Output	
P5DIR		EQU	0x40004C44	; !< Port 5 Direction  
P6DIR		EQU	0x40004C45	; !< Port 6 Direction  
P5REN		EQU	0x40004C46	; !< Port 5 Resistor Enable  
P6REN		EQU	0x40004C47	; !< Port 6 Resistor Enable  
P5DS		EQU	0x40004C48	; !< Port 5 Drive Strength  
P6DS		EQU	0x40004C49	; !< Port 6 Drive Strength  
P5SEL0		EQU	0x40004C4A	; !< Port 5 Select 0  
P6SEL0		EQU	0x40004C4B	; !< Port 6 Select 0  
P5SEL1		EQU	0x40004C4C	; !< Port 5 Select 1  
P6SEL1		EQU	0x40004C4D	; !< Port 6 Select 1  
P5SELC		EQU	0x40004C56	; !< Port 5 Complement Select	 
P6SELC		EQU	0x40004C57	; !< Port 6 Complement Select	 
P5IES		EQU	0x40004C58	; !< Port 5 Interrupt Edge Select	
P6IES		EQU	0x40004C59	; !< Port 6 Interrupt Edge Select	
P5IE		EQU	0x40004C5A	; !< Port 5 Interrupt Enable	
P6IE		EQU	0x40004C5B	; !< Port 6 Interrupt Enable	
P5IFG		EQU	0x40004C5C	; !< Port 5 Interrupt Flag  
P6IFG		EQU	0x40004C5D	; !< Port 6 Interrupt Flag  
P7IN		EQU	0x40004C60	; !< Port 7 Input  
P8IN		EQU	0x40004C61	; !< Port 8 Input  
P7OUT		EQU	0x40004C62	; !< Port 7 Output	
P8OUT		EQU	0x40004C63	; !< Port 8 Output	
P7DIR		EQU	0x40004C64	; !< Port 7 Direction  
P8DIR		EQU	0x40004C65	; !< Port 8 Direction  
P7REN		EQU	0x40004C66	; !< Port 7 Resistor Enable  
P8REN		EQU	0x40004C67	; !< Port 8 Resistor Enable  
P7DS		EQU	0x40004C68	; !< Port 7 Drive Strength  
P8DS		EQU	0x40004C69	; !< Port 8 Drive Strength  
P7SEL0		EQU	0x40004C6A	; !< Port 7 Select 0  
P8SEL0		EQU	0x40004C6B	; !< Port 8 Select 0  
P7SEL1		EQU	0x40004C6C	; !< Port 7 Select 1  
P8SEL1		EQU	0x40004C6D	; !< Port 8 Select 1  
P7SELC		EQU	0x40004C76	; !< Port 7 Complement Select	 
P8SELC		EQU	0x40004C77	; !< Port 8 Complement Select	 
P7IES		EQU	0x40004C78	; !< Port 7 Interrupt Edge Select	
P8IES		EQU	0x40004C79	; !< Port 8 Interrupt Edge Select	
P7IE		EQU	0x40004C7A	; !< Port 7 Interrupt Enable	
P8IE		EQU	0x40004C7B	; !< Port 8 Interrupt Enable	
P7IFG		EQU	0x40004C7C	; !< Port 7 Interrupt Flag  
P8IFG		EQU	0x40004C7D	; !< Port 8 Interrupt Flag  
P9IN		EQU	0x40004C80	; !< Port 9 Input  
P10IN		EQU	0x40004C81	; !< Port 10 Input	
P9OUT		EQU	0x40004C82	; !< Port 9 Output	
P10OUT		EQU	0x40004C83	; !< Port 10 Output	 
P9DIR		EQU	0x40004C84	; !< Port 9 Direction  
P10DIR		EQU	0x40004C85	; !< Port 10 Direction  
P9REN		EQU	0x40004C86	; !< Port 9 Resistor Enable  
P10REN		EQU	0x40004C87	; !< Port 10 Resistor Enable	
P9DS		EQU	0x40004C88	; !< Port 9 Drive Strength  
P10DS		EQU	0x40004C89	; !< Port 10 Drive Strength  
P9SEL0		EQU	0x40004C8A	; !< Port 9 Select 0  
P10SEL0		EQU	0x40004C8B	; !< Port 10 Select 0  
P9SEL1		EQU	0x40004C8C	; !< Port 9 Select 1  
P10SEL1		EQU	0x40004C8D	; !< Port 10 Select 1  
P9SELC		EQU	0x40004C96	; !< Port 9 Complement Select	 
P10SELC		EQU	0x40004C97	; !< Port 10 Complement Select  
P9IES		EQU	0x40004C98	; !< Port 9 Interrupt Edge Select	
P10IES		EQU	0x40004C99	; !< Port 10 Interrupt Edge Select	 
P9IE		EQU	0x40004C9A	; !< Port 9 Interrupt Enable	
P10IE		EQU	0x40004C9B	; !< Port 10 Interrupt Enable	 
P9IFG		EQU	0x40004C9C	; !< Port 9 Interrupt Flag  
P10IFG		EQU	0x40004C9D	; !< Port 10 Interrupt Flag  
	
UCA0CTLW0		EQU	0x40001000	; !< eUSCI_Ax Control Word Register 0  
UCA0CTLW0_SPI	EQU	0x40001000	; !< eUSCI_Ax Control Word Register 0  
UCA0CTLW1		EQU	0x40001002	; !< eUSCI_Ax Control Word Register 1  
UCA0BRW			EQU	0x40001006	; !< eUSCI_Ax Baud Rate Control Word Register  
UCA0BRW_SPI		EQU	0x40001006	; !< eUSCI_Ax Bit Rate Control Register 1  
UCA0MCTLW		EQU	0x40001008	; !< eUSCI_Ax Modulation Control Word Register  
UCA0STATW		EQU	0x4000100A	; !< eUSCI_Ax Status Register	 
UCA0RXBUF		EQU	0x4000100C	; !< eUSCI_Ax Receive Buffer Register  
UCA0RXBUF_SPI	EQU	0x4000100C	; !< eUSCI_Ax Receive Buffer Register  
UCA0TXBUF		EQU	0x4000100E	; !< eUSCI_Ax Transmit Buffer Register	
UCA0TXBUF_SPI	EQU	0x4000100E	; !< eUSCI_Ax Transmit Buffer Register	
UCA0ABCTL		EQU	0x40001010	; !< eUSCI_Ax Auto Baud Rate Control Register  
UCA0IRCTL		EQU	0x40001012	; !< eUSCI_Ax IrDA Control Word Register  
UCA0IE			EQU	0x4000101A	; !< eUSCI_Ax Interrupt Enable Register	 
UCA0IE_SPI		EQU	0x4000101A	; !< eUSCI_Ax Interrupt Enable Register	 
UCA0IFG			EQU	0x4000101C	; !< eUSCI_Ax Interrupt Flag Register  
UCA0IFG_SPI		EQU	0x4000101C	; !< eUSCI_Ax Interrupt Flag Register  
UCA0IV			EQU	0x4000101E	; !< eUSCI_Ax Interrupt Vector Register	 
UCA0IV_SPI		EQU	0x4000101E	; !< eUSCI_Ax Interrupt Vector Register	 
UCA1CTLW0		EQU	0x40001400	; !< eUSCI_Ax Control Word Register 0  
UCA1CTLW0_SPI	EQU	0x40001400	; !< eUSCI_Ax Control Word Register 0  
UCA1CTLW1		EQU	0x40001402	; !< eUSCI_Ax Control Word Register 1  
UCA1BRW			EQU	0x40001406	; !< eUSCI_Ax Baud Rate Control Word Register  
UCA1BRW_SPI		EQU	0x40001406	; !< eUSCI_Ax Bit Rate Control Register 1  
UCA1MCTLW		EQU	0x40001408	; !< eUSCI_Ax Modulation Control Word Register  
UCA1STATW		EQU	0x4000140A	; !< eUSCI_Ax Status Register	 
UCA1RXBUF		EQU	0x4000140C	; !< eUSCI_Ax Receive Buffer Register  
UCA1RXBUF_SPI	EQU	0x4000140C	; !< eUSCI_Ax Receive Buffer Register  
UCA1TXBUF		EQU	0x4000140E	; !< eUSCI_Ax Transmit Buffer Register	
UCA1TXBUF_SPI	EQU	0x4000140E	; !< eUSCI_Ax Transmit Buffer Register	
UCA1ABCTL		EQU	0x40001410	; !< eUSCI_Ax Auto Baud Rate Control Register  
UCA1IRCTL		EQU	0x40001412	; !< eUSCI_Ax IrDA Control Word Register  
UCA1IE			EQU	0x4000141A	; !< eUSCI_Ax Interrupt Enable Register	 
UCA1IE_SPI		EQU	0x4000141A	; !< eUSCI_Ax Interrupt Enable Register	 
UCA1IFG			EQU	0x4000141C	; !< eUSCI_Ax Interrupt Flag Register  
UCA1IFG_SPI		EQU	0x4000141C	; !< eUSCI_Ax Interrupt Flag Register  
UCA1IV			EQU	0x4000141E	; !< eUSCI_Ax Interrupt Vector Register	 
UCA1IV_SPI		EQU	0x4000141E	; !< eUSCI_Ax Interrupt Vector Register	 
UCA2CTLW0		EQU	0x40001800	; !< eUSCI_Ax Control Word Register 0  
UCA2CTLW0_SPI	EQU	0x40001800	; !< eUSCI_Ax Control Word Register 0  
UCA2CTLW1		EQU	0x40001802	; !< eUSCI_Ax Control Word Register 1  
UCA2BRW			EQU	0x40001806	; !< eUSCI_Ax Baud Rate Control Word Register  
UCA2BRW_SPI		EQU	0x40001806	; !< eUSCI_Ax Bit Rate Control Register 1  
UCA2MCTLW		EQU	0x40001808	; !< eUSCI_Ax Modulation Control Word Register  
UCA2STATW		EQU	0x4000180A	; !< eUSCI_Ax Status Register	 
UCA2RXBUF		EQU	0x4000180C	; !< eUSCI_Ax Receive Buffer Register  
UCA2RXBUF_SPI	EQU	0x4000180C	; !< eUSCI_Ax Receive Buffer Register  
UCA2TXBUF		EQU	0x4000180E	; !< eUSCI_Ax Transmit Buffer Register	
UCA2TXBUF_SPI	EQU	0x4000180E	; !< eUSCI_Ax Transmit Buffer Register	
UCA2ABCTL		EQU	0x40001810	; !< eUSCI_Ax Auto Baud Rate Control Register  
UCA2IRCTL		EQU	0x40001812	; !< eUSCI_Ax IrDA Control Word Register  
UCA2IE			EQU	0x4000181A	; !< eUSCI_Ax Interrupt Enable Register	 
UCA2IE_SPI		EQU	0x4000181A	; !< eUSCI_Ax Interrupt Enable Register	 
UCA2IFG			EQU	0x4000181C	; !< eUSCI_Ax Interrupt Flag Register  
UCA2IFG_SPI		EQU	0x4000181C	; !< eUSCI_Ax Interrupt Flag Register  
UCA2IV			EQU	0x4000181E	; !< eUSCI_Ax Interrupt Vector Register	 
UCA2IV_SPI		EQU	0x4000181E	; !< eUSCI_Ax Interrupt Vector Register	 
UCA3CTLW0		EQU	0x40001C00	; !< eUSCI_Ax Control Word Register 0  
UCA3CTLW0_SPI	EQU	0x40001C00	; !< eUSCI_Ax Control Word Register 0  
UCA3CTLW1		EQU	0x40001C02	; !< eUSCI_Ax Control Word Register 1  
UCA3BRW			EQU	0x40001C06	; !< eUSCI_Ax Baud Rate Control Word Register  
UCA3BRW_SPI		EQU	0x40001C06	; !< eUSCI_Ax Bit Rate Control Register 1  
UCA3MCTLW		EQU	0x40001C08	; !< eUSCI_Ax Modulation Control Word Register  
UCA3STATW		EQU	0x40001C0A	; !< eUSCI_Ax Status Register	 
UCA3RXBUF		EQU	0x40001C0C	; !< eUSCI_Ax Receive Buffer Register  
UCA3RXBUF_SPI	EQU	0x40001C0C	; !< eUSCI_Ax Receive Buffer Register  
UCA3TXBUF		EQU	0x40001C0E	; !< eUSCI_Ax Transmit Buffer Register	
UCA3TXBUF_SPI	EQU	0x40001C0E	; !< eUSCI_Ax Transmit Buffer Register	
UCA3ABCTL		EQU	0x40001C10	; !< eUSCI_Ax Auto Baud Rate Control Register  
UCA3IRCTL		EQU	0x40001C12	; !< eUSCI_Ax IrDA Control Word Register  
UCA3IE			EQU	0x40001C1A	; !< eUSCI_Ax Interrupt Enable Register	 
UCA3IE_SPI		EQU	0x40001C1A	; !< eUSCI_Ax Interrupt Enable Register	 
UCA3IFG			EQU	0x40001C1C	; !< eUSCI_Ax Interrupt Flag Register  
UCA3IFG_SPI		EQU	0x40001C1C	; !< eUSCI_Ax Interrupt Flag Register  
UCA3IV			EQU	0x40001C1E	; !< eUSCI_Ax Interrupt Vector Register	 
UCA3IV_SPI		EQU	0x40001C1E	; !< eUSCI_Ax Interrupt Vector Register	 
UCB0CTLW0		EQU	0x40002000	; !< eUSCI_Bx Control Word Register 0  
UCB0CTLW0_SPI	EQU	0x40002000	; !< eUSCI_Bx Control Word Register 0  
UCB0CTLW1		EQU	0x40002002	; !< eUSCI_Bx Control Word Register 1  
UCB0BRW			EQU	0x40002006	; !< eUSCI_Bx Baud Rate Control Word Register  
UCB0BRW_SPI		EQU	0x40002006	; !< eUSCI_Bx Bit Rate Control Register 1  
UCB0STATW		EQU	0x40002008	; !< eUSCI_Bx Status Register	 
UCB0TBCNT		EQU	0x4000200A	; !< eUSCI_Bx Byte Counter Threshold Register  
UCB0RXBUF		EQU	0x4000200C	; !< eUSCI_Bx Receive Buffer Register  
UCB0RXBUF_SPI	EQU	0x4000200C	; !< eUSCI_Bx Receive Buffer Register  
UCB0TXBUF		EQU	0x4000200E	; !< eUSCI_Bx Transmit Buffer Register	
UCB0TXBUF_SPI	EQU	0x4000200E	; !< eUSCI_Bx Transmit Buffer Register	
UCB0I2COA0		EQU	0x40002014	; !< eUSCI_Bx I2C Own Address 0 Register  
UCB0I2COA1		EQU	0x40002016	; !< eUSCI_Bx I2C Own Address 1 Register  
UCB0I2COA2		EQU	0x40002018	; !< eUSCI_Bx I2C Own Address 2 Register  
UCB0I2COA3		EQU	0x4000201A	; !< eUSCI_Bx I2C Own Address 3 Register  
UCB0ADDRX		EQU	0x4000201C	; !< eUSCI_Bx I2C Received Address Register	
UCB0ADDMASK		EQU	0x4000201E	; !< eUSCI_Bx I2C Address Mask Register	 
UCB0I2CSA		EQU	0x40002020	; !< eUSCI_Bx I2C Slave Address Register  
UCB0IE			EQU	0x4000202A	; !< eUSCI_Bx Interrupt Enable Register	 
UCB0IE_SPI		EQU	0x4000202A	; !< eUSCI_Bx Interrupt Enable Register	 
UCB0IFG			EQU	0x4000202C	; !< eUSCI_Bx Interrupt Flag Register  
UCB0IFG_SPI		EQU	0x4000202C	; !< eUSCI_Bx Interrupt Flag Register  
UCB0IV			EQU	0x4000202E	; !< eUSCI_Bx Interrupt Vector Register	 
UCB0IV_SPI		EQU	0x4000202E	; !< eUSCI_Bx Interrupt Vector Register	 
UCB1CTLW0		EQU	0x40002400	; !< eUSCI_Bx Control Word Register 0  
UCB1CTLW0_SPI	EQU	0x40002400	; !< eUSCI_Bx Control Word Register 0  
UCB1CTLW1		EQU	0x40002402	; !< eUSCI_Bx Control Word Register 1  
UCB1BRW			EQU	0x40002406	; !< eUSCI_Bx Baud Rate Control Word Register  
UCB1BRW_SPI		EQU	0x40002406	; !< eUSCI_Bx Bit Rate Control Register 1  
UCB1STATW		EQU	0x40002408	; !< eUSCI_Bx Status Register	 
UCB1TBCNT		EQU	0x4000240A	; !< eUSCI_Bx Byte Counter Threshold Register  
UCB1RXBUF		EQU	0x4000240C	; !< eUSCI_Bx Receive Buffer Register  
UCB1RXBUF_SPI	EQU	0x4000240C	; !< eUSCI_Bx Receive Buffer Register  
UCB1TXBUF		EQU	0x4000240E	; !< eUSCI_Bx Transmit Buffer Register	
UCB1TXBUF_SPI	EQU	0x4000240E	; !< eUSCI_Bx Transmit Buffer Register	
UCB1I2COA0		EQU	0x40002414	; !< eUSCI_Bx I2C Own Address 0 Register  
UCB1I2COA1		EQU	0x40002416	; !< eUSCI_Bx I2C Own Address 1 Register  
UCB1I2COA2		EQU	0x40002418	; !< eUSCI_Bx I2C Own Address 2 Register  
UCB1I2COA3		EQU	0x4000241A	; !< eUSCI_Bx I2C Own Address 3 Register  
UCB1ADDRX		EQU	0x4000241C	; !< eUSCI_Bx I2C Received Address Register	
UCB1ADDMASK		EQU	0x4000241E	; !< eUSCI_Bx I2C Address Mask Register	 
UCB1I2CSA		EQU	0x40002420	; !< eUSCI_Bx I2C Slave Address Register  
UCB1IE			EQU	0x4000242A	; !< eUSCI_Bx Interrupt Enable Register	 
UCB1IE_SPI		EQU	0x4000242A	; !< eUSCI_Bx Interrupt Enable Register	 
UCB1IFG			EQU	0x4000242C	; !< eUSCI_Bx Interrupt Flag Register  
UCB1IFG_SPI		EQU	0x4000242C	; !< eUSCI_Bx Interrupt Flag Register  
UCB1IV			EQU	0x4000242E	; !< eUSCI_Bx Interrupt Vector Register	 
UCB1IV_SPI		EQU	0x4000242E	; !< eUSCI_Bx Interrupt Vector Register	 
UCB2CTLW0		EQU	0x40002800	; !< eUSCI_Bx Control Word Register 0  
UCB2CTLW0_SPI	EQU	0x40002800	; !< eUSCI_Bx Control Word Register 0  
UCB2CTLW1		EQU	0x40002802	; !< eUSCI_Bx Control Word Register 1  
UCB2BRW			EQU	0x40002806	; !< eUSCI_Bx Baud Rate Control Word Register  
UCB2BRW_SPI		EQU	0x40002806	; !< eUSCI_Bx Bit Rate Control Register 1  
UCB2STATW		EQU	0x40002808	; !< eUSCI_Bx Status Register	 
UCB2TBCNT		EQU	0x4000280A	; !< eUSCI_Bx Byte Counter Threshold Register  
UCB2RXBUF		EQU	0x4000280C	; !< eUSCI_Bx Receive Buffer Register  
UCB2RXBUF_SPI	EQU	0x4000280C	; !< eUSCI_Bx Receive Buffer Register  
UCB2TXBUF		EQU	0x4000280E	; !< eUSCI_Bx Transmit Buffer Register	
UCB2TXBUF_SPI	EQU	0x4000280E	; !< eUSCI_Bx Transmit Buffer Register	
UCB2I2COA0		EQU	0x40002814	; !< eUSCI_Bx I2C Own Address 0 Register  
UCB2I2COA1		EQU	0x40002816	; !< eUSCI_Bx I2C Own Address 1 Register  
UCB2I2COA2		EQU	0x40002818	; !< eUSCI_Bx I2C Own Address 2 Register  
UCB2I2COA3		EQU	0x4000281A	; !< eUSCI_Bx I2C Own Address 3 Register  
UCB2ADDRX		EQU	0x4000281C	; !< eUSCI_Bx I2C Received Address Register	
UCB2ADDMASK		EQU	0x4000281E	; !< eUSCI_Bx I2C Address Mask Register	 
UCB2I2CSA		EQU	0x40002820	; !< eUSCI_Bx I2C Slave Address Register  
UCB2IE			EQU	0x4000282A	; !< eUSCI_Bx Interrupt Enable Register	 
UCB2IE_SPI		EQU	0x4000282A	; !< eUSCI_Bx Interrupt Enable Register	 
UCB2IFG			EQU	0x4000282C	; !< eUSCI_Bx Interrupt Flag Register  
UCB2IFG_SPI		EQU	0x4000282C	; !< eUSCI_Bx Interrupt Flag Register  
UCB2IV			EQU	0x4000282E	; !< eUSCI_Bx Interrupt Vector Register	 
UCB2IV_SPI		EQU	0x4000282E	; !< eUSCI_Bx Interrupt Vector Register	 
UCB3CTLW0		EQU	0x40002C00	; !< eUSCI_Bx Control Word Register 0  
UCB3CTLW0_SPI	EQU	0x40002C00	; !< eUSCI_Bx Control Word Register 0  
UCB3CTLW1		EQU	0x40002C02	; !< eUSCI_Bx Control Word Register 1  
UCB3BRW			EQU	0x40002C06	; !< eUSCI_Bx Baud Rate Control Word Register  
UCB3BRW_SPI		EQU	0x40002C06	; !< eUSCI_Bx Bit Rate Control Register 1  
UCB3STATW		EQU	0x40002C08	; !< eUSCI_Bx Status Register	 
UCB3TBCNT		EQU	0x40002C0A	; !< eUSCI_Bx Byte Counter Threshold Register  
UCB3RXBUF		EQU	0x40002C0C	; !< eUSCI_Bx Receive Buffer Register  
UCB3RXBUF_SPI	EQU	0x40002C0C	; !< eUSCI_Bx Receive Buffer Register  
UCB3TXBUF		EQU	0x40002C0E	; !< eUSCI_Bx Transmit Buffer Register	
UCB3TXBUF_SPI	EQU	0x40002C0E	; !< eUSCI_Bx Transmit Buffer Register	
UCB3I2COA0		EQU	0x40002C14	; !< eUSCI_Bx I2C Own Address 0 Register  
UCB3I2COA1		EQU	0x40002C16	; !< eUSCI_Bx I2C Own Address 1 Register  
UCB3I2COA2		EQU	0x40002C18	; !< eUSCI_Bx I2C Own Address 2 Register  
UCB3I2COA3		EQU	0x40002C1A	; !< eUSCI_Bx I2C Own Address 3 Register  
UCB3ADDRX		EQU	0x40002C1C	; !< eUSCI_Bx I2C Received Address Register	
UCB3ADDMASK		EQU	0x40002C1E	; !< eUSCI_Bx I2C Address Mask Register	 
UCB3I2CSA		EQU	0x40002C20	; !< eUSCI_Bx I2C Slave Address Register  
UCB3IE			EQU	0x40002C2A	; !< eUSCI_Bx Interrupt Enable Register	 
UCB3IE_SPI		EQU	0x40002C2A	; !< eUSCI_Bx Interrupt Enable Register	 
UCB3IFG			EQU	0x40002C2C	; !< eUSCI_Bx Interrupt Flag Register  
UCB3IFG_SPI		EQU	0x40002C2C	; !< eUSCI_Bx Interrupt Flag Register  
UCB3IV			EQU	0x40002C2E	; !< eUSCI_Bx Interrupt Vector Register	 
UCB3IV_SPI		EQU	0x40002C2E	; !< eUSCI_Bx Interrupt Vector Register 
	
PMAPKEYID	EQU	0x40005000	; !< Port Mapping Key Register  
PMAPCTL		EQU	0x40005002	; !< Port Mapping Control Register	 
P1MAP01		EQU	0x40005008	; !< Port mapping register, P1.0 and P1.1  
P1MAP23		EQU	0x4000500A	; !< Port mapping register, P1.2 and P1.3  
P1MAP45		EQU	0x4000500C	; !< Port mapping register, P1.4 and P1.5  
P1MAP67		EQU	0x4000500E	; !< Port mapping register, P1.6 and P1.7  
P2MAP01		EQU	0x40005010	; !< Port mapping register, P2.0 and P2.1  
P2MAP23		EQU	0x40005012	; !< Port mapping register, P2.2 and P2.3  
P2MAP45		EQU	0x40005014	; !< Port mapping register, P2.4 and P2.5  
P2MAP67		EQU	0x40005016	; !< Port mapping register, P2.6 and P2.7  
P3MAP01		EQU	0x40005018	; !< Port mapping register, P3.0 and P3.1  
P3MAP23		EQU	0x4000501A	; !< Port mapping register, P3.2 and P3.3  
P3MAP45		EQU	0x4000501C	; !< Port mapping register, P3.4 and P3.5  
P3MAP67		EQU	0x4000501E	; !< Port mapping register, P3.6 and P3.7  
P4MAP01		EQU	0x40005020	; !< Port mapping register, P4.0 and P4.1  
P4MAP23		EQU	0x40005022	; !< Port mapping register, P4.2 and P4.3  
P4MAP45		EQU	0x40005024	; !< Port mapping register, P4.4 and P4.5  
P4MAP67		EQU	0x40005026	; !< Port mapping register, P4.6 and P4.7  
P5MAP01		EQU	0x40005028	; !< Port mapping register, P5.0 and P5.1  
P5MAP23		EQU	0x4000502A	; !< Port mapping register, P5.2 and P5.3  
P5MAP45		EQU	0x4000502C	; !< Port mapping register, P5.4 and P5.5  
P5MAP67		EQU	0x4000502E	; !< Port mapping register, P5.6 and P5.7  
P6MAP01		EQU	0x40005030	; !< Port mapping register, P6.0 and P6.1  
P6MAP23		EQU	0x40005032	; !< Port mapping register, P6.2 and P6.3  
P6MAP45		EQU	0x40005034	; !< Port mapping register, P6.4 and P6.5  
P6MAP67		EQU	0x40005036	; !< Port mapping register, P6.6 and P6.7  
P7MAP01		EQU	0x40005038	; !< Port mapping register, P7.0 and P7.1  
P7MAP23		EQU	0x4000503A	; !< Port mapping register, P7.2 and P7.3  
P7MAP45		EQU	0x4000503C	; !< Port mapping register, P7.4 and P7.5  
P7MAP67		EQU	0x4000503E	; !< Port mapping register, P7.6 and P7.7  
	
REFCTL0		EQU	0x40003000	; !< REF Control Register 0  
	
RTCCTL0		EQU	0x40004400	; !< RTCCTL0 Register  
RTCCTL13	EQU	0x40004402	; !< RTCCTL13 Register  
RTCOCAL		EQU	0x40004404	; !< RTCOCAL Register  
RTCTCMP		EQU	0x40004406	; !< RTCTCMP Register  
RTCPS0CTL	EQU	0x40004408	; !< Real-Time Clock Prescale Timer 0 Control Register	 
RTCPS1CTL	EQU	0x4000440A	; !< Real-Time Clock Prescale Timer 1 Control Register	 
RTCPS		EQU	0x4000440C	; !< Real-Time Clock Prescale Timer Counter Register  
RTCIV		EQU	0x4000440E	; !< Real-Time Clock Interrupt Vector Register  
RTCTIM0		EQU	0x40004410	; !< RTCTIM0 Register ? Hexadecimal Format  
RTCTIM0_BCD	EQU	0x40004410	; !< RTCTIM0 Register ? BCD Format	 
RTCTIM1		EQU	0x40004412	; !< Real-Time Clock Hour, Day of Week	
RTCTIM1_BCD	EQU	0x40004412	; !< RTCTIM1 Register ? BCD Format	 
RTCDATE		EQU	0x40004414	; !< RTCDATE - Hexadecimal Format	
RTCDATE_BCD	EQU	0x40004414	; !< Real-Time Clock Date - BCD Format	
RTCYEAR		EQU	0x40004416	; !< RTCYEAR Register ? Hexadecimal Format  
RTCYEAR_BCD	EQU	0x40004416	; !< RTCYEAR Register ? BCD Format	 
RTCAMINHR		EQU	0x40004418	; !< RTCMINHR - Hexadecimal Format	 
RTCAMINHR_BCD	EQU	0x40004418	; !< RTCMINHR - BCD Format  
RTCADOWDAY		EQU	0x4000441A	; !< RTCADOWDAY - Hexadecimal Format  
RTCADOWDAY_BCD	EQU	0x4000441A	; !< RTCADOWDAY - BCD Format	
RTCBIN2BCD		EQU	0x4000441C	; !< Binary-to-BCD Conversion Register	
RTCBCD2BIN		EQU	0x4000441E	; !< BCD-to-Binary Conversion Register	
	
TA0CTL		EQU	0x40000000	; !< TimerAx Control Register	 
TA0CCTL0	EQU	0x40000002	; !< Timer_A Capture/Compare Control Register  
TA0CCTL1	EQU	0x40000004	; !< Timer_A Capture/Compare Control Register  
TA0CCTL2	EQU	0x40000006	; !< Timer_A Capture/Compare Control Register  
TA0CCTL3	EQU	0x40000008	; !< Timer_A Capture/Compare Control Register  
TA0CCTL4	EQU	0x4000000A	; !< Timer_A Capture/Compare Control Register  
TA0CCTL5	EQU	0x4000000C	; !< Timer_A Capture/Compare Control Register  
TA0CCTL6	EQU	0x4000000E	; !< Timer_A Capture/Compare Control Register  
TA0R		EQU	0x40000010	; !< TimerA register  
TA0CCR0		EQU	0x40000012	; !< Timer_A Capture/Compare	Register	
TA0CCR1		EQU	0x40000014	; !< Timer_A Capture/Compare	Register	
TA0CCR2		EQU	0x40000016	; !< Timer_A Capture/Compare	Register	
TA0CCR3		EQU	0x40000018	; !< Timer_A Capture/Compare	Register	
TA0CCR4		EQU	0x4000001A	; !< Timer_A Capture/Compare	Register	
TA0CCR5		EQU	0x4000001C	; !< Timer_A Capture/Compare	Register	
TA0CCR6		EQU	0x4000001E	; !< Timer_A Capture/Compare	Register	
TA0EX0		EQU	0x40000020	; !< TimerAx Expansion 0 Register	
TA0IV		EQU	0x4000002E	; !< TimerAx Interrupt Vector Register	
TA1CTL		EQU	0x40000400	; !< TimerAx Control Register	 
TA1CCTL0	EQU	0x40000402	; !< Timer_A Capture/Compare Control Register  
TA1CCTL1	EQU	0x40000404	; !< Timer_A Capture/Compare Control Register  
TA1CCTL2	EQU	0x40000406	; !< Timer_A Capture/Compare Control Register  
TA1CCTL3	EQU	0x40000408	; !< Timer_A Capture/Compare Control Register  
TA1CCTL4	EQU	0x4000040A	; !< Timer_A Capture/Compare Control Register  
TA1CCTL5	EQU	0x4000040C	; !< Timer_A Capture/Compare Control Register  
TA1CCTL6	EQU	0x4000040E	; !< Timer_A Capture/Compare Control Register  
TA1R		EQU	0x40000410	; !< TimerA register  
TA1CCR0		EQU	0x40000412	; !< Timer_A Capture/Compare	Register	
TA1CCR1		EQU	0x40000414	; !< Timer_A Capture/Compare	Register	
TA1CCR2		EQU	0x40000416	; !< Timer_A Capture/Compare	Register	
TA1CCR3		EQU	0x40000418	; !< Timer_A Capture/Compare	Register	
TA1CCR4		EQU	0x4000041A	; !< Timer_A Capture/Compare	Register	
TA1CCR5		EQU	0x4000041C	; !< Timer_A Capture/Compare	Register	
TA1CCR6		EQU	0x4000041E	; !< Timer_A Capture/Compare	Register	
TA1EX0		EQU	0x40000420	; !< TimerAx Expansion 0 Register	
TA1IV		EQU	0x4000042E	; !< TimerAx Interrupt Vector Register	
TA2CTL		EQU	0x40000800	; !< TimerAx Control Register	 
TA2CCTL0	EQU	0x40000802	; !< Timer_A Capture/Compare Control Register  
TA2CCTL1	EQU	0x40000804	; !< Timer_A Capture/Compare Control Register  
TA2CCTL2	EQU	0x40000806	; !< Timer_A Capture/Compare Control Register  
TA2CCTL3	EQU	0x40000808	; !< Timer_A Capture/Compare Control Register  
TA2CCTL4	EQU	0x4000080A	; !< Timer_A Capture/Compare Control Register  
TA2CCTL5	EQU	0x4000080C	; !< Timer_A Capture/Compare Control Register  
TA2CCTL6	EQU	0x4000080E	; !< Timer_A Capture/Compare Control Register  
TA2R		EQU	0x40000810	; !< TimerA register  
TA2CCR0		EQU	0x40000812	; !< Timer_A Capture/Compare	Register	
TA2CCR1		EQU	0x40000814	; !< Timer_A Capture/Compare	Register	
TA2CCR2		EQU	0x40000816	; !< Timer_A Capture/Compare	Register	
TA2CCR3		EQU	0x40000818	; !< Timer_A Capture/Compare	Register	
TA2CCR4		EQU	0x4000081A	; !< Timer_A Capture/Compare	Register	
TA2CCR5		EQU	0x4000081C	; !< Timer_A Capture/Compare	Register	
TA2CCR6		EQU	0x4000081E	; !< Timer_A Capture/Compare	Register	
TA2EX0		EQU	0x40000820	; !< TimerAx Expansion 0 Register	
TA2IV		EQU	0x4000082E	; !< TimerAx Interrupt Vector Register	
TA3CTL		EQU	0x40000C00	; !< TimerAx Control Register	 
TA3CCTL0	EQU	0x40000C02	; !< Timer_A Capture/Compare Control Register  
TA3CCTL1	EQU	0x40000C04	; !< Timer_A Capture/Compare Control Register  
TA3CCTL2	EQU	0x40000C06	; !< Timer_A Capture/Compare Control Register  
TA3CCTL3	EQU	0x40000C08	; !< Timer_A Capture/Compare Control Register  
TA3CCTL4	EQU	0x40000C0A	; !< Timer_A Capture/Compare Control Register  
TA3CCTL5	EQU	0x40000C0C	; !< Timer_A Capture/Compare Control Register  
TA3CCTL6	EQU	0x40000C0E	; !< Timer_A Capture/Compare Control Register  
TA3R		EQU	0x40000C10	; !< TimerA register  
TA3CCR0		EQU	0x40000C12	; !< Timer_A Capture/Compare	Register	
TA3CCR1		EQU	0x40000C14	; !< Timer_A Capture/Compare	Register	
TA3CCR2		EQU	0x40000C16	; !< Timer_A Capture/Compare	Register	
TA3CCR3		EQU	0x40000C18	; !< Timer_A Capture/Compare	Register	
TA3CCR4		EQU	0x40000C1A	; !< Timer_A Capture/Compare	Register	
TA3CCR5		EQU	0x40000C1C	; !< Timer_A Capture/Compare	Register	
TA3CCR6		EQU	0x40000C1E	; !< Timer_A Capture/Compare	Register	
TA3EX0		EQU	0x40000C20	; !< TimerAx Expansion 0 Register	
TA3IV		EQU	0x40000C2E	; !< TimerAx Interrupt Vector Register	
	
WDTCTL		EQU	0x4000480C	; !< Watchdog Timer Control Register  
	
	END