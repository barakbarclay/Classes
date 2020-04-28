				INCLUDE msp432p401r.s
			
				;changes in bit 5 to do an output 
				;PxDIR = xx1x_xxxx
				;PxSEL0 = xx1x_xxxx
				;PxSEL1 = xx0x_xxxx
				
				;INPUT CAPTURE 			PM_TA0.1;P2.4			Timer0_A1
				;each time a edge is detected, perform an isr to say a copy of TA0CCRx; check switch values in isr; calculate values
				;switches P2.0 & P2.1
				LDRH R0, =TA0CTL
				LDRH R1, [R0]
				ORR R1, 0x20 ; to set timer in continous mode
				STRH R1, [R0]
				LDRH R0, =TA0CCTL1
				LDRH R1, [R0]
				ORR R1, 0xC100 ; to set timer to capture on both rising and falling edge 
				STRH R1, [R0]
				;LDR R0, =TACCR1
				;LDRH R1, [R0]
				;LDR R0, =PrevCap
				;LDRH R2, [R0]
				;SUB R3,R1,R2
				;STRH R1, [R0]
				;LDR R0, =period
				;STRH R3, [R0]
				;LDR R0, =TA0CCTL1
				;...
				;BX LR
				
				;OUTPUT COMPARE 		TA2.1;P5.6				Timer2_A1
				;use two TA2CCRx registers to control freq and duty cycle
				LDRH R0, =TA2CTL
				LDRH R1, [R0]
				ORR R1, 0x10 ; to set timer in up mode
				STRH R1, [R0]
				LDRH R0, =TA0CCTL1
				LDRH R1, [R0]
				ORR R1, 0x0000 ; to set timer to compare and change output mode
				STRH R1, [R0]
				;LDR R0, =P2DIR
				;LDRB R1, [R0]
				;ORR R1, #0x8
				;STRB R1, [R0]
				
TA1FG_Handler	LDR	R0, =TA1CCTL
				LDR R1, =RollCount
				LDR R2, [R1]
				ADD R2, #0x10000
				STR R2,[R1]
				LDRH R2, [R0]
				BIC R2, #TA1FG
				BX LR 
				
TA0CCR1_Handler	LDR R0, =TA0CCR1
				LDR R1, =RollCount
				LDRH R2, [R0]; CURRENT TIME 0x0005
				LDR R3, [R1]; ROUNTCOUNT 0x3
				;LSL R3, [R1]
				ADD R2, R3; CURRENT TIME 0x3_0005
				LDR R1, =PrevTime
				LDR	R3, [R1];0x0000_FFF0
				SUB R2, R3;CURRENT MINUS PREVIOUS