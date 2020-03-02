#include <stdio.h>
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
//Had to include paths in target options -> C/C++ 
//Also had to add file extensions to library
#include "LCD_Driver.h"
#include "Seven_Segment.h"

#include "ScanKey.h"

void TMR1_IRQHandler(void) //Flashes led (green)
{
GPA_13 = ~GPA_13;
TIMER1 ->TISR.TIF = 1; //Clear flag (needed to change from timer0 in lecture)
}

int main (void) {
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
	
//LCD init
Initial_panel();
clr_all_panel(); 

//Keypad 
OpenKeyPad();

//Displays init values
print_lcd(0,"Hello World!");
int i,k=0;
char j[15] = "Key Value:";

while(1) {
i=Scankey();
//Keeps last value pressed
if(i!=0)
k = i;
//Interrupt button resets display to 0 & sets off buzzer
if(!GPB_15){
	k=0;
	GPB_11 = 0;
}
if(GPB_15){
	GPB_11 = 1;
}
//Display on LCD
sprintf(j+10,"%d", k);
print_lcd(2,j);
//Display on 7-segment
OpenSevenSegment();
 ShowSevenSegment(0,k);
DrvSYS_Delay(1000);
CloseSevenSegment();
OpenSevenSegment();
 ShowSevenSegment(1,1);
DrvSYS_Delay(1000);
CloseSevenSegment();
OpenSevenSegment();
 ShowSevenSegment(2,0);
DrvSYS_Delay(1000);
CloseSevenSegment();
OpenSevenSegment();
 ShowSevenSegment(3,2);
DrvSYS_Delay(1000);
CloseSevenSegment();
}
		
////unlock the protected registers
//UNLOCKREG();
// //select the 22MHz RC clock
//DrvSYS_SetOscCtrl(E_SYS_OSC22M,1);
////wait until the clock is stable
// while(DrvSYS_GetChipClockSourceStatus(E_SYS_OSC22M) != 1);
////HCLK clock source 7: internal 22MHz RC oscillator
//DrvSYS_SelectHCLKSource(7);
////Lock the protected registers
//LOCKREG();
////clock frequency is HCLK clock source/(HCLK_N +1)
////Max divisor value 0xF; Min value is 0x0 - (hence the "+1" above)
//DrvSYS_SetClockDivider(E_SYS_HCLK_DIV,2); //slower clock, 0 is very fast.
//while(1){
///* DrvGPIO.h gives us the option to use the pins/ports directly for this chip */
///* see line 35 in DrvGPIO.h */
//GPC_15 = 1; //off
//GPC_12 = 0; //on
//DrvSYS_Delay(10000000); //DrvSYS.h line 182, DrvSYS.c line 1310
//GPC_12 = 1; //off
//GPC_13 = 0; //on
//DrvSYS_Delay(10000000);
//GPC_13 = 1; //off
//GPC_14 = 0; //on
//DrvSYS_Delay(1000);
//GPC_14 = 1; //off
//GPC_15 = 0; //on
//DrvSYS_Delay(10000000);
//}//end while
} //end main
