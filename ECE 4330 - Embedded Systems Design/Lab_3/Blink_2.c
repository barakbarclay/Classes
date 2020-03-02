#include <stdio.h>
#include <stdlib.h>
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
//Had to include paths in target options -> C/C++
//Also had to add file extensions to library
#include "LCD_Driver.h"
#include "Seven_Segment.h"
#include "DrvADC.h"
#include "DrvTimer.h"
//Added to source folder
#include "ScanKey.h"

int run = 0; //Global run variable for interrupt

void TMR0_Callback(void) //Flashes led (green)
{
	GPA_13 = ~GPA_13;
	TIMER1 ->TISR.TIF = 1; //Clear flag (needed to change from timer0 in lecture)
}

void heartbeat()
{
	//CLK init
	SYSCLK->CLKSEL1.TMR1_S = 7;
	SYSCLK->APBCLK.TMR1_EN = 1;
	TIMER1->TCSR.MODE = 1; //0 = one shot, 1 = periodic, 2 = toggle, 3 = continuous
	TIMER1->TCSR.PRESCALE = 1;
	TIMER1->TCMPR = 5500000; //Calculated
	TIMER1->TCSR.IE = 1;
	TIMER1->TISR.TIF= 1;
	TIMER1->TCSR.TDR_EN= 1;
	TIMER1->TCSR.CRST = 1;
	TIMER1->TCSR.CEN= 1;
	TIMER1->TCSR.TDR_EN= 1;
	
	//Heartbeat interrupt
	TIMER1 ->TISR.TIF = 1; //Clear flag (do before using interrupt)
	GPA_13 = 1;
	NVIC_EnableIRQ(TMR1_IRQn);
}

//Stop interrupt button callback function
void EINT1_Callback(void){
	run = 0;
}

int main (void) {
	//Call heartbeat
	heartbeat();
	
	//LCD init
	Initial_panel();
	clr_all_panel();
	
	//Keypad init
	OpenKeyPad();
	
	//GPA_6 init
	DrvGPIO_Open(E_GPA, 6, E_IO_INPUT);
	
	//EINT1 init for STOP
	DrvGPIO_EnableEINT1(E_IO_FALLING, E_MODE_EDGE, EINT1_Callback);
	
	//Values init
	int count = 0;
	char countDisplay[15];
	
	while(1){
		//START & RESET
		switch(Scankey())
		{
			case 1: //START
			print_lcd(0, "START");
			run = 1;
			sprintf(countDisplay, "Count: %4d", count);
			print_lcd(1, countDisplay);
			break;
			case 2: //RESET
			print_lcd(0, "RESET");
			count = 0;
			sprintf(countDisplay, "Count: %4d", count);
			print_lcd(1, countDisplay);
			break;
			default:
			break;
		}//End switch
		if (GPB_15 == 0)//STOP print (seperate from IRS)
				{
					print_lcd(0, "STOP ");
					while (Scankey() != 1); //Wait until start is pressed
				}
		if (run == 1)
		{
			print_lcd(2, "UNBLOCKED");
			if (GPA_6 == 0) //Blocked counter
			{
				print_lcd(2, "BLOCKED");
				count = count + 1;
				GPC_12 = 0; //Turn on LED
				sprintf(countDisplay, "Count: %4d", count);
				print_lcd(1, countDisplay);
				while (GPA_6 == 0); //Wait until unblocked
				GPC_12 = 1; //Turn off LED
			}//End if GPA_6 == 0
		}//End if run == 1
	}//end while
} //end main
