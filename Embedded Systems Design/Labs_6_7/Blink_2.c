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
float RPM = 0.0;
int updateTerminal = 0;
int updateDutyCycle = 0;
int halfSecondPerCount = 0;

void TMR0_Callback(void) //Flashes led (green)
{
	updateDutyCycle = 1;
	halfSecondPerCount++;
	RPM = ((double)count) * 60.0;
	count = 0;
	updateTerminal = 1;
	GPA_13 = ~GPA_13;
	TIMER0 ->TISR.TIF = 1; //Clear flag
}

void TMR1_Callback(void)
{
	TIMER1 ->TISR.TIF = 1; //Clear flag
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
	DrvTIMER_Open(E_TMR0,2,E_PERIODIC_MODE);//Timer 0, 2 ticks per second (2Hz or 0.5s), periodic
	DrvTIMER_SetTimerEvent(E_TMR0,1,(TIMER_CALLBACK)TMR0_Callback,1); 
	DrvTIMER_EnableInt(E_TMR0);
	DrvTIMER_ClearIntFlag(E_TMR0);
	DrvTIMER_Start(E_TMR0);
}

void redLEDs(int keyPadButton)
{
	//Set lights based on button pressed
	if (keyPadButton % 2 == 0)
		GPC_15 = 1;
	else 
		GPC_15 = 0;
	if ((keyPadButton >> 1) % 2 == 0)
		GPC_14 = 1; 
	else 
		GPC_14 = 0;
	if ((keyPadButton >> 2) % 2 == 0)
		GPC_13 = 1;
	else 
		GPC_13 = 0;
	if ((keyPadButton >> 3) % 2 == 0)
		GPC_12 = 1;
	else 
		GPC_12 = 0;
}

int adjustDutyCycle (int dutyCycle, int commandedRPM)
{
  //Init variables
  char foo[15]; 
	int error; 
	//Print
  sprintf(foo, "Duty Cycle: %3d", dutyCycle); 
  print_lcd(0, foo); 
	sprintf(foo, "RPM: %5.0f", RPM); 
  print_lcd(1, foo);
	error = commandedRPM - RPM;
	error = abs(error/100); 
  sprintf(foo, "Error: %5d", error); 
	print_lcd(2, foo);
	//Task 3
//	if (RPM + 500 < commandedRPM && dutyCycle != 100)
//		dutyCycle++;
//	else if (RPM - 500 > commandedRPM && dutyCycle != 1)
//		dutyCycle--;
	//Task 4
	if (RPM + 500 < commandedRPM && dutyCycle + error >= 1)
		dutyCycle = dutyCycle + error;
	else if (RPM - 500 > commandedRPM && dutyCycle - error <= 100)
		dutyCycle = dutyCycle - error;
	if (dutyCycle < 1)
		dutyCycle = 1;
	if (dutyCycle > 100)
		dutyCycle = 100;
	//Change duty cycle
	sPt.u8HighPulseRatio = dutyCycle;
	DrvPWM_SetTimerClk(DRVPWM_TIMER3 , &sPt);
	return dutyCycle;
}

void printToTerminal (int commandedRPM)
{
	char text [64] = {' '};
	sprintf(text, "%-3d,%-5.0f", commandedRPM, RPM);
	text[62] = 0x0d;	
	text[63] = 0x0a;
	DrvUART_Write(UART_PORT0, text, 64);
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
	//Timer1 update init
	DrvSYS_SelectIPClockSource(E_SYS_TMR1_CLKSRC,7);//Select 22 Mhz for Timer1
	DrvTIMER_Init();
	DrvTIMER_Open(E_TMR1,10,E_PERIODIC_MODE);//Timer 1, (10 Hz or .1s))10 ticks per second, periodic
	DrvTIMER_SetTimerEvent(E_TMR1,1,(TIMER_CALLBACK)TMR1_Callback,1); 
	DrvTIMER_EnableInt(E_TMR1);
	DrvTIMER_ClearIntFlag(E_TMR1);
	DrvTIMER_Start(E_TMR1);
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
	int commandedRPM = 0;
	//////////////////////NEW//////////////////////////////////////
	//UART init
	DrvSYS_SelectIPClockSource(E_SYS_UART_CLKSRC, 0x00);//Can also try 0x01 or 0x03
	DrvGPIO_InitFunction(E_FUNC_UART0);// Might need to be somthing different
	struct STR_UART_T
	{
		unsigned int u32BaudRate;
		char u8cDataBits;
		char u8cStopBits;
		char u8cParity;
		char u8cRxTriggerLevel;
	};
	STR_UART_T sUART;
	sUART.u32BaudRate = 9600;
	sUART.u8cDataBits = DRVUART_DATABITS_8;
	sUART.u8cStopBits = DRVUART_STOPBITS_1;
	sUART.u8cParity = DRVUART_PARITY_NONE;
	sUART.u8cRxTriggerLevel = DRVUART_FIFO_1BYTES;
	DrvUART_Open(UART_PORT0, &sUART);
	//EINT0 init
	DrvGPIO_EnableEINT0(E_IO_FALLING, E_MODE_EDGE, (GPIO_EINT0_CALLBACK)EINT0_Callback);
	/////////////////////////////////////////////////////////////////
	while(1){
switch(Scankey())
		{
			case 1:
			halfSecondPerCount = 0;
      dutyCycle = 1;   
			redLEDs(1);
			commandedRPM = 0;
			break;
			case 2:
			halfSecondPerCount = 0;
			dutyCycle = 23;
			redLEDs(2);
			commandedRPM = 1500;
			break; 
			case 3:
			halfSecondPerCount = 0;
			dutyCycle = 38;
			redLEDs(3);
			commandedRPM = 3000;
			break;
			case 4:
			halfSecondPerCount = 0;
			dutyCycle = 53;
			redLEDs(4);
			commandedRPM = 4500;
			break;
			case 5:
			halfSecondPerCount = 0;
			dutyCycle = 68;
			redLEDs(5);
			commandedRPM = 6000;
			break;
			case 6:
			halfSecondPerCount = 0;
			dutyCycle = 83;
			redLEDs(6);
			commandedRPM = 7500;
			break;
			case 7:
			halfSecondPerCount = 0;
			dutyCycle = 98;
			redLEDs(7);
			commandedRPM = 9000;
			break;
			case 8:
			halfSecondPerCount = 0;
			dutyCycle = 100;
			redLEDs(8);
			commandedRPM = 9500;
			break;
			case 9:
			halfSecondPerCount = 0;
			dutyCycle = 100;
			redLEDs(9);
			commandedRPM = 9500;
			break;
			default:
			break;
		}//End switch
    //Change duty cycle based on ambient light and print
		if (updateDutyCycle)
		{
			dutyCycle = adjustDutyCycle(dutyCycle, commandedRPM);
			updateDutyCycle = 0;
		}
		if (updateTerminal && halfSecondPerCount > 5)
		{
			printToTerminal(commandedRPM);
			updateTerminal = 0;
		}
	}//End while
} //End main
