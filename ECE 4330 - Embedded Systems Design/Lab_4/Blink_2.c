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

void TMR0_Callback(void) //Flashes led (green)
{
	GPA_13 = ~GPA_13;
	TIMER1 ->TISR.TIF = 1; //Clear flag (needed to change from timer0 in lecture)
}

// This function is used in qsort to decide the relative order of elements at addresses p and q.
int comparator(const void *p, const void *q)
{
	// Get the values at given addresses
	int l = *(const int *)p;
	int r = *(const int *)q;
	// both odd, put the greater of two first.
	if ((l&1) && (r&1))
	return (r-l);
	// both even, put the smaller of two first
	if ( !(l&1) && !(r&1) )
	return (l-r);
	// l is even, put r first
	if (!(l&1))
	return 1;
	// l is odd, put l first
	return -1;
}

void heartbeat()
{
	GPA_13 = 1;
	//select 22 Mhz for Timer0 clock source
	DrvSYS_SelectIPClockSource(E_SYS_TMR0_CLKSRC,7);//TMR 0~3: 0= External 12M, 1=
	//External 32K, 2= HCLK, 7 = Internal 22M
	DrvTIMER_Init();//must do this before using timer
	//automatically sets timer to correct time based on number of ticks/interrupts per second
	//enable Timer0 clock source
	//Time out period is 2 ticks per second.
	// select operation mode for periodic
	DrvTIMER_Open(E_TMR0,2,E_PERIODIC_MODE);// Timer 0, 2 ticks per second, periodic
	//mode
	//setup the interrupt/callback function (user defined) and trigger the timer callback
	//function
	DrvTIMER_SetTimerEvent(E_TMR0,1,(TIMER_CALLBACK)TMR0_Callback,1); //goes to
	//the call back function every interrupt.
	DrvTIMER_EnableInt(E_TMR0);//enable Timer 0 interrupt
	DrvTIMER_ClearIntFlag(E_TMR0);////write 1 to clear for safety
	//enable the timer module (TCSR.CEN = 1)
	DrvTIMER_Start(E_TMR0); //start counting
}

void ADCprint()
{
		//Variable init
		char foo[15];
		float percent, voltage = 0.0;
		int raws[4] = {0};
		int raw = 0;
	
		//Get raw values and eliminate noise
		for(int i = 0; i < 4; i++){
			while(!DrvADC_IsConversionDone());
			raws[i] = DrvADC_GetConversionData(0);
		}
		int size = sizeof(raws) / sizeof(raws[0]);
		qsort((void*)raws, size, sizeof(raws[0]), comparator);
		raw = ((raws[1]+raws[2])/2);

		//Calculate percent & voltage
		percent = (raw/40.95);
		voltage = ((percent*3.3)/100);
		
		//Print values
		sprintf(foo,"%3.2fV %4.2f%%",voltage , percent);
		print_lcd(2,foo);
		sprintf(foo, "%4d", raw);
		print_lcd(3,foo);
		
		//Delay
		DrvSYS_Delay(50000000);
		DrvSYS_Delay(50000000);
}

int main (void) {
	//Call heartbeat
	heartbeat();
	
	//LCD init
	Initial_panel();
	clr_all_panel();
	
	// Disable GPA.0 IO digital input path
	DrvGPIO_DisableDigitalInputBit (E_GPA, 0);
	
	//Continuous ADC init
	/*   u8ChannelSelBitwise [in]:  Specify the input channels.     */    
	/*   For example, "u8ChannelSelBitwise=0x1(00000001b)" means the ADC channel 0 is enabled; */    
	/*   "u8ChannelSelBitwise=0x19(00011001b)" means the ADC channel 0, 3 and 4 are enabled.   */   
	DrvADC_Open(ADC_SINGLE_END,ADC_CONTINUOUS_OP,0x1,INTERNAL_RC22MHZ,1);
	DrvADC_StartConvert();
	
	//ADC Calibration
	DrvADC_EnableSelfCalibration();
	while(!DrvADC_IsCalibrationDone());
	
	//GPIO init
	DrvGPIO_Open(E_GPD, 0, E_IO_OUTPUT);
  DrvGPIO_Open(E_GPD, 1, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPA, 0, E_IO_INPUT);
	
	while(1){
		//00
		DrvGPIO_ClrBit(E_GPD, 0);
    DrvGPIO_ClrBit(E_GPD, 1);
		ADCprint();
		//01
		DrvGPIO_ClrBit(E_GPD, 0);
    DrvGPIO_SetBit(E_GPD, 1);
		ADCprint();
		//10
		DrvGPIO_SetBit(E_GPD, 0);
    DrvGPIO_ClrBit(E_GPD, 1);
		ADCprint();
		//11
		DrvGPIO_SetBit(E_GPD, 0);
    DrvGPIO_SetBit(E_GPD, 1);
		ADCprint();
	} // end while
} //end main
