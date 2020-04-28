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
#include "DrvPWM.h"
#include "DrvUART.h"
//Added to source folder
#include "ScanKey.h"
//Init global variables
S_DRVPWM_TIME_DATA_T sPt; 
int count = 0;
double RPM = 0.0;

void TMR0_Callback(void) //Flashes led (green)
{
	RPM = ((double)count) /2.0 * 60.0;
	count = 0;
	GPA_13 = ~GPA_13;
	TIMER0 ->TISR.TIF = 1; //Clear flag
}

void EINT0_Callback(void) 
{
	count++;
}

void heartbeat()
{
	//LED init
	GPA_13 = 1;
	//Timer init
	DrvSYS_SelectIPClockSource(E_SYS_TMR0_CLKSRC,7);//Select 22 Mhz for Timer0
	DrvTIMER_Init();
	DrvTIMER_Open(E_TMR0,1,E_PERIODIC_MODE);//Timer 0, 2 ticks per second (2Hz or 0.5s), periodic
	DrvTIMER_SetTimerEvent(E_TMR0,1,(TIMER_CALLBACK)TMR0_Callback,1); 
	DrvTIMER_EnableInt(E_TMR0);
	DrvTIMER_ClearIntFlag(E_TMR0);
	DrvTIMER_Start(E_TMR0);
}

void adjustDutyCycle (int dutyCycle)
{
  //Init variables
  char foo[15]; 
	//Print
  sprintf(foo, "Duty Cycle: %3d", dutyCycle); 
  print_lcd(0, foo); 
	sprintf(foo, "RPM: %5.0lf", RPM); 
  print_lcd(1, foo);
	sPt.u8HighPulseRatio = dutyCycle;
	DrvPWM_SetTimerClk(DRVPWM_TIMER3 , &sPt);
}

int main (void) {
	//Call heartbeat
	heartbeat();
	//LCD init
	Initial_panel();
	clr_all_panel();
	//Keypad init
	OpenKeyPad();
	//GPIO init 
	DrvGPIO_Open(E_GPA, 15, E_IO_OUTPUT); 
	//PWM init
	DrvGPIO_InitFunction (E_FUNC_PWM3);
	SYS->GPAMFP.PWM3_I2SMCLK = 1;
	DrvPWM_Open();
	/* PWM Timer property */
	sPt.u8Mode = DRVPWM_AUTO_RELOAD_MODE;
	sPt.u8HighPulseRatio = 1; /* High Pulse peroid : Total Pulse peroid = 20 : 100 */
	sPt.i32Inverter = 0;
	sPt.u32Frequency = 1000; // Set 1KHz to PWM timer output frequency
	/* Select PWM engine clock */
	DrvPWM_SelectClockSource(DRVPWM_TIMER3, DRVPWM_HCLK);
	/* Set PWM Timer3 Configuration */
	DrvPWM_SetTimerClk(DRVPWM_TIMER3, &sPt);
	/* Enable Output for PWM Timer3 */
	DrvPWM_SetTimerIO(DRVPWM_TIMER3, 1);
	/* Enable the PWM Timer 3 */
	DrvPWM_Enable(DRVPWM_TIMER3, 1);
	//Variables init
	int dutyCycle = 1;
	//////////////////////NEW//////////////////////////////////////
	//EINT0 init
	DrvGPIO_EnableEINT0(E_IO_FALLING, E_MODE_EDGE, (GPIO_EINT0_CALLBACK)EINT0_Callback);
	/////////////////////////////////////////////////////////////////
	while(1){
switch(Scankey())
		{
			case 1:
      dutyCycle = 1;   
			break;
			case 2:
			dutyCycle = 23;
			break; 
			case 3:
			dutyCycle = 38;
			break;
			case 4:
			dutyCycle = 53;
			break;
			case 5:
			dutyCycle = 68;
			break;
			case 6:
			dutyCycle = 83;
			break;
			case 7:
			dutyCycle = 98;
			break;
			case 8:
			dutyCycle = 100;
			break;
			case 9:
			dutyCycle = 100;
			break;
			default:
			break;
		}//End switch
    //Change duty cycle based on ambient light and print
		adjustDutyCycle(dutyCycle);
	}//End while
} //End main
