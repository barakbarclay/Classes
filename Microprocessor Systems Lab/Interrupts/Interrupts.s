; (c) 2016 - Jeff Heckey
		  
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
  
Stack_Size      EQU     0x00000200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     main                      ; Run main
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     PSS_IRQHandler            ;  0:  PSS Interrupt
                DCD     CS_IRQHandler             ;  1:  CS Interrupt
                DCD     PCM_IRQHandler            ;  2:  PCM Interrupt
                DCD     WDT_A_IRQHandler          ;  3:  WDT_A Interrupt
                DCD     FPU_IRQHandler            ;  4:  FPU Interrupt
                DCD     FLCTL_IRQHandler          ;  5:  FLCTL Interrupt
                DCD     COMP_E0_IRQHandler        ;  6:  COMP_E0 Interrupt
                DCD     COMP_E1_IRQHandler        ;  7:  COMP_E1 Interrupt
                DCD     TA0_0_IRQHandler          ;  8:  TA0_0 Interrupt
                DCD     TA0_N_IRQHandler          ;  9:  TA0_N Interrupt
                DCD     TA1_0_IRQHandler          ; 10:  TA1_0 Interrupt
                DCD     TA1_N_IRQHandler          ; 11:  TA1_N Interrupt
                DCD     TA2_0_IRQHandler          ; 12:  TA2_0 Interrupt
                DCD     TA2_N_IRQHandler          ; 13:  TA2_N Interrupt
                DCD     TA3_0_IRQHandler          ; 14:  TA3_0 Interrupt
                DCD     TA3_N_IRQHandler          ; 15:  TA3_N Interrupt
                DCD     EUSCIA0_IRQHandler        ; 16:  EUSCIA0 Interrupt
                DCD     EUSCIA1_IRQHandler        ; 17:  EUSCIA1 Interrupt
                DCD     EUSCIA2_IRQHandler        ; 18:  EUSCIA2 Interrupt
                DCD     EUSCIA3_IRQHandler        ; 19:  EUSCIA3 Interrupt
                DCD     EUSCIB0_IRQHandler        ; 20:  EUSCIB0 Interrupt
                DCD     EUSCIB1_IRQHandler        ; 21:  EUSCIB1 Interrupt
                DCD     EUSCIB2_IRQHandler        ; 22:  EUSCIB2 Interrupt
                DCD     EUSCIB3_IRQHandler        ; 23:  EUSCIB3 Interrupt
                DCD     ADC14_IRQHandler          ; 24:  ADC14 Interrupt
                DCD     T32_INT1_IRQHandler       ; 25:  T32_INT1 Interrupt
                DCD     T32_INT2_IRQHandler       ; 26:  T32_INT2 Interrupt
                DCD     T32_INTC_IRQHandler       ; 27:  T32_INTC Interrupt
                DCD     AES256_IRQHandler         ; 28:  AES256 Interrupt
                DCD     RTC_C_IRQHandler          ; 29:  RTC_C Interrupt
                DCD     DMA_ERR_IRQHandler        ; 30:  DMA_ERR Interrupt
                DCD     DMA_INT3_IRQHandler       ; 31:  DMA_INT3 Interrupt
                DCD     DMA_INT2_IRQHandler       ; 32:  DMA_INT2 Interrupt
                DCD     DMA_INT1_IRQHandler       ; 33:  DMA_INT1 Interrupt
                DCD     DMA_INT0_IRQHandler       ; 34:  DMA_INT0 Interrupt
                DCD     PORT1_IRQHandler          ; 35:  PORT1 Interrupt
                DCD     PORT2_IRQHandler          ; 36:  PORT2 Interrupt
                DCD     PORT3_IRQHandler          ; 37:  PORT3 Interrupt
                DCD     PORT4_IRQHandler          ; 38:  PORT4 Interrupt
                DCD     PORT5_IRQHandler          ; 39:  PORT5 Interrupt
                DCD     PORT6_IRQHandler          ; 40:  PORT6 Interrupt
                DCD     0                         ; 41:  Reserved
                DCD     0                         ; 42:  Reserved
                DCD     0                         ; 43:  Reserved
                DCD     0                         ; 44:  Reserved
                DCD     0                         ; 45:  Reserved
                DCD     0                         ; 46:  Reserved
                DCD     0                         ; 47:  Reserved
                DCD     0                         ; 48:  Reserved
                DCD     0                         ; 49:  Reserved
                DCD     0                         ; 50:  Reserved
                DCD     0                         ; 51:  Reserved
                DCD     0                         ; 52:  Reserved
                DCD     0                         ; 53:  Reserved
                DCD     0                         ; 54:  Reserved
                DCD     0                         ; 55:  Reserved
                DCD     0                         ; 56:  Reserved
                DCD     0                         ; 57:  Reserved
                DCD     0                         ; 58:  Reserved
                DCD     0                         ; 59:  Reserved
                DCD     0                         ; 60:  Reserved
                DCD     0                         ; 61:  Reserved
                DCD     0                         ; 62:  Reserved
                DCD     0                         ; 63:  Reserved
                DCD     0                         ; 64:  Reserved
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC
                EXPORT  PSS_IRQHandler            [WEAK]
                EXPORT  CS_IRQHandler             [WEAK]
                EXPORT  PCM_IRQHandler            [WEAK]
                EXPORT  WDT_A_IRQHandler          [WEAK]
                EXPORT  FPU_IRQHandler            [WEAK]
                EXPORT  FLCTL_IRQHandler          [WEAK]
                EXPORT  COMP_E0_IRQHandler        [WEAK]
                EXPORT  COMP_E1_IRQHandler        [WEAK]
                EXPORT  TA0_0_IRQHandler          [WEAK]
                EXPORT  TA0_N_IRQHandler          [WEAK]
                EXPORT  TA1_0_IRQHandler          [WEAK]
                EXPORT  TA1_N_IRQHandler          [WEAK]
                EXPORT  TA2_0_IRQHandler          [WEAK]
                EXPORT  TA2_N_IRQHandler          [WEAK]
                EXPORT  TA3_0_IRQHandler          [WEAK]
                EXPORT  TA3_N_IRQHandler          [WEAK]
                EXPORT  EUSCIA0_IRQHandler        [WEAK]
                EXPORT  EUSCIA1_IRQHandler        [WEAK]
                EXPORT  EUSCIA2_IRQHandler        [WEAK]
                EXPORT  EUSCIA3_IRQHandler        [WEAK]
                EXPORT  EUSCIB0_IRQHandler        [WEAK]
                EXPORT  EUSCIB1_IRQHandler        [WEAK]
                EXPORT  EUSCIB2_IRQHandler        [WEAK]
                EXPORT  EUSCIB3_IRQHandler        [WEAK]
                EXPORT  ADC14_IRQHandler          [WEAK]
                EXPORT  T32_INT1_IRQHandler       [WEAK]
                EXPORT  T32_INT2_IRQHandler       [WEAK]
                EXPORT  T32_INTC_IRQHandler       [WEAK]
                EXPORT  AES256_IRQHandler         [WEAK]
                EXPORT  RTC_C_IRQHandler          [WEAK]
                EXPORT  DMA_ERR_IRQHandler        [WEAK]
                EXPORT  DMA_INT3_IRQHandler       [WEAK]
                EXPORT  DMA_INT2_IRQHandler       [WEAK]
                EXPORT  DMA_INT1_IRQHandler       [WEAK]
                EXPORT  DMA_INT0_IRQHandler       [WEAK]
                EXPORT  PORT1_IRQHandler          [WEAK]
                EXPORT  PORT2_IRQHandler          [WEAK]
                EXPORT  PORT3_IRQHandler          [WEAK]
                EXPORT  PORT4_IRQHandler          [WEAK]
                EXPORT  PORT5_IRQHandler          [WEAK]
                EXPORT  PORT6_IRQHandler          [WEAK]

  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Port 1 ISR
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  EXPORT PORT1_IRQHandler
PORT1_IRQHandler

  ; Test P1.1 and P1.4 flags
  LDR   R1, =P1IN
  LDR   R2, =P2OUT
  
  LDRB  R0, [R1]
  ; Mask off bits I'm not interested in.
  AND   R0, #0x12
  ; Possible values in R0 are now 0x10, 0x02, or 0x12
  CMP   R0, #0x02
  BEQ   LedsOn
  CMP   R0, #0x10
  BEQ   LedsOff
  ; Both switches pressed at same time
  B     Rj  ; do nothing
LedsOn
  LDRB  R0, [R2]
  ORR   R0, #0x7   ; active-high LEDs
  STRB  R0, [R2]
  B     Rj
LedsOff
  LDRB  R0, [R2]
  BIC   R0, #0x7   ; active-high LEDs
  STRB  R0, [R2]
Rj	
  ; Clear P1.1 and P1.4 flags
  MOV   R0, #0
  STRB  R0, [R1]
  
  ; Leave ISR
  BX    LR
    
  ALIGN                           ; make sure the end of this section is aligned

PSS_IRQHandler
CS_IRQHandler
PCM_IRQHandler
WDT_A_IRQHandler
FPU_IRQHandler
FLCTL_IRQHandler
COMP_E0_IRQHandler
COMP_E1_IRQHandler
TA0_0_IRQHandler
TA0_N_IRQHandler
TA1_0_IRQHandler
TA1_N_IRQHandler
TA2_0_IRQHandler
TA2_N_IRQHandler
TA3_0_IRQHandler
TA3_N_IRQHandler
EUSCIA0_IRQHandler
EUSCIA1_IRQHandler
EUSCIA2_IRQHandler
EUSCIA3_IRQHandler
EUSCIB0_IRQHandler
EUSCIB1_IRQHandler
EUSCIB2_IRQHandler
EUSCIB3_IRQHandler
ADC14_IRQHandler
T32_INT1_IRQHandler
T32_INT2_IRQHandler
T32_INTC_IRQHandler
AES256_IRQHandler
RTC_C_IRQHandler
DMA_ERR_IRQHandler
DMA_INT3_IRQHandler
DMA_INT2_IRQHandler
DMA_INT1_IRQHandler
DMA_INT0_IRQHandler
;PORT1_IRQHandler
PORT2_IRQHandler
PORT3_IRQHandler
PORT4_IRQHandler
PORT5_IRQHandler
PORT6_IRQHandler
                B       .
                ENDP

                ALIGN

;
; Declare global variables here...
;
  AREA    DATA, ALIGN=2

;
; This is the read-only code section...
;
  AREA    |.text|, CODE, READONLY, ALIGN=2
  THUMB
        
GPIO_Init_Switches
  ; Initialize P1.1 and P1.4 as GPIO inputs
  
  ; (defaults are OK)
  ;LDR  R1, =P1SEL0               
  ;LDRB R0, [R1]                 
  ;BIC  R0, R0, #0x12 
  ;STRB R0, [R1]      
  
  ; (defaults are OK)
  ;LDR  R1, =P1SEL1              
  ;LDRB R0, [R1]                 
  ;BIC  R0, R0, #0x12 
  ;STRB R0, [R1]
  
  LDR  R1, =P1DIR                
  LDRB R0, [R1]                
  BIC  R0, R0, #0x12
  STRB R0, [R1]      
  
  ;
  ; One side of the switch is grounded and the switch is
  ; normally open.  When pressed, the input goes low.  When
  ; not pressed, there must be a pull-up resistor involved.
  ;
  ; Enable internal pull-up resister because P1.1 or P1.4
  ; may not have an externally-interfaced pull-up resistor.
  ;

  ; Turn on internal resistor
  LDR  R1, =P1REN
  LDRB R0, [R1]                
  ORR  R0, R0, #0x12 
  STRB R0, [R1]      

  ; Select a pull-up resistor
  LDR  R1, =P1OUT
  LDRB R0, [R1]                
  ORR  R0, R0, #0x12 
  STRB R0, [R1]      

  ; Change P1IES for rising or falling edge-triggered
  ; interrupts (make falling edge)
  LDR   R1, =P1IES
  LDRB  R0, [R1]
  ORR   R0, R0, #0x12
  STRB  R0, [R1]

  ; Allow P1.1 and P1.4 to generate interrupts
  LDR   R1, =P1IE
  LDRB  R0, [R1]
  ORR   R0, R0, #0x12
  STRB  R0, [R1]

  ; Set priority to 2 (defaults are OK)
  ;LDR  R1, =NVIC_IPR8
  ;LDR  R0, [R1]                
  ;BIC  R0, R0, #0xFF000000
  ;ORR  R0, R0, #0x40000000
  ;STR  R0, [R1]      

  ; Set bit 3 in NVIC_ISER1 register to allow the NVIC to pass the
  ; interrupt onto the CPU.
  LDR   R1, =NVIC_ISER1
  MOV   R0, #0x8
  STR   R0, [R1]
  
  BX   LR   
  ALIGN	

GPIO_Init_LEDs
  ; initialize P2.2-P2.0 as GPIO outputs
  
  ; (defaults are OK)
  ;LDR  R1, =P2SEL0               
  ;LDRB R0, [R1]                 
  ;BIC  R0, R0, #0x07
  ;STRB R0, [R1]                 
  
  ; (defaults are OK)
  ;LDR  R1, =P2SEL1              
  ;LDRB R0, [R1]                 
  ;BIC  R0, R0, #0x07 
  ;STRB R0, [R1]
  
  LDR  R1, =P2DIR                
  LDRB R0, [R1]                
  ORR  R0, R0, #0x07 
  STRB R0, [R1]  
  
  BX   LR                       
  ALIGN
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Main entry point
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  EXPORT  Reset_Handler
  EXPORT  main
Reset_Handler
main

  CPSID I	; disable interrupts during init

  ; Switches on P1.1 and P1.4
  ; LEDs on P1.0 (red), P2.2-0 (red, green, blue).

  ; Configure switches
  BL    GPIO_Init_Switches
  
  ; Configure LEDs
  BL    GPIO_Init_LEDs
    
  ; Test:  Turn all LEDs on
  ;LDR  R1,=P2OUT
  ;MOV  R0, #0x7
  STRB R0, [R1]
    
  ; Test:  Turn all LEDs off
  ;LDR  R1,=P2OUT
  ;MOV  R0, #0x0
  ;STRB R0, [R1]

  ; Adjust CPU PRIMASK register (clear bit 0) to allow the interrupt
  ; into the CPU.
  CPSIE I   ; set I=0
    
  ; Nothing more to do.  Loop indefinitely, or go to sleep.
D WFI      ; sleep while waiting on interrupt
  B   D
  ALIGN

  END                             ; end of file