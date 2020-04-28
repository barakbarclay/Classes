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
//Added to source folder
#include "ScanKey.h"
//Init global variables
S_DRVPWM_TIME_DATA_T sPt; 
int update = 0;

void TMR0_Callback(void) //Flashes led (green)
{
	GPA_13 = ~GPA_13;
	TIMER0 ->TISR.TIF = 1; //Clear flag
}
void TMR1_Callback(void)
{
	update = 1;
	TIMER1 ->TISR.TIF = 1; //Clear flag
}

void heartbeat()
{
	//LED init
	GPA_13 = 1;
	//Timer init
	DrvSYS_SelectIPClockSource(E_SYS_TMR0_CLKSRC,7);//Select 22 Mhz for Timer0
	DrvTIMER_Init();
	DrvTIMER_Open(E_TMR0,2,E_PERIODIC_MODE);//Timer 0, 2 ticks per second, periodic
	DrvTIMER_SetTimerEvent(E_TMR0,1,(TIMER_CALLBACK)TMR0_Callback,1); 
	DrvTIMER_EnableInt(E_TMR0);
	DrvTIMER_ClearIntFlag(E_TMR0);
	DrvTIMER_Start(E_TMR0);
}

void adjustDutyCycle (int dutyCycle, int raw, double target)
{
  //Change duty cycle based on ambient light and print
  char foo[15]; 
  sprintf(foo, "%4.0lf   %3d", target, dutyCycle); 
  print_lcd(2, foo); 
  if (raw + 100 < target && sPt.u8HighPulseRatio <= 98)
	{
    sPt.u8HighPulseRatio = sPt.u8HighPulseRatio + 2;
	}
	else if (raw - 100  > target && sPt.u8HighPulseRatio >= 3)
	{
    sPt.u8HighPulseRatio = sPt.u8HighPulseRatio - 2;
	}
  DrvPWM_SetTimerClk(DRVPWM_TIMER3 , &sPt);
  sprintf(foo, "%4d   %3d", raw, sPt.u8HighPulseRatio); 
  print_lcd(3, foo);
}

int ADCraw() 
{ 
    //Variable init 
    int raw = 0;
    //Get raw values and eliminate noise 
    DrvADC_StartConvert(); 
    while (!DrvADC_IsConversionDone()) ; 
    raw = DrvADC_GetConversionData(6); 
    DrvADC_StopConvert(); 
    return raw;
} 

int main (void) {
	//Call heartbeat
	heartbeat();
	//LCD init
	Initial_panel();
	clr_all_panel();
	//Keypad init
	OpenKeyPad();
	// Disable GPA.6 IO digital input path 
	DrvGPIO_DisableDigitalInputBit(E_GPA, 6);  
	//Single ADC init 
	/*   u8ChannelSelBitwise [in]:  Specify the input channels.     */ 
	/*   For example, "u8ChannelSelBitwise=0x1(00000001b)" means the ADC channel 0 is enabled; */ 
	/*   "u8ChannelSelBitwise=0x19(00011001b)" means the ADC channel 0, 3 and 4 are enabled.   */ 
	DrvADC_Open(ADC_SINGLE_END, ADC_SINGLE_OP, 0x40, INTERNAL_RC22MHZ, 1); 
	//ADC Calibration 
	DrvADC_EnableSelfCalibration(); 
	while (!DrvADC_IsCalibrationDone()) ; 
	//GPIO init 
	DrvGPIO_Open(E_GPA, 15, E_IO_OUTPUT); 
	DrvGPIO_Open(E_GPA, 6, E_IO_INPUT); 
	//////////////////////////////NEW/////////////////////////////
	//Timer1 update init
	DrvSYS_SelectIPClockSource(E_SYS_TMR1_CLKSRC,7);//Select 22 Mhz for Timer1
	DrvTIMER_Init();
	DrvTIMER_Open(E_TMR1,20,E_PERIODIC_MODE);//Timer 1, 20 ticks per second, periodic
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
  int raw = 0;
  int no_LED = 0;
	int full_LED = 0;
	double target = (double)no_LED;
	char initDisplay[15]; 
	//Initilize no_LED & full_LED
  sPt.u8HighPulseRatio = 1;
  DrvPWM_SetTimerClk(DRVPWM_TIMER3 , &sPt);
	DrvSYS_Delay(5000000);
	no_LED = ADCraw();
	sPt.u8HighPulseRatio = 100;
  DrvPWM_SetTimerClk(DRVPWM_TIMER3 , &sPt);
	DrvSYS_Delay(5000000);
	full_LED = ADCraw();
	target = (double)no_LED;
	sprintf(initDisplay, "No LED:%4d", no_LED); 
  print_lcd(0, initDisplay);
	sprintf(initDisplay, "Full LED:%4d", full_LED); 
  print_lcd(1, initDisplay);
	while(1){
		switch(Scankey())
		{
			case 1:
      dutyCycle = 1;
      target = no_LED;      
			GPC_12 = 1;
			GPC_13 = 1;
			GPC_14 = 1;
			GPC_15 = 1;
			break;
			case 2:
			dutyCycle = 25;
      target = no_LED + (((double)full_LED - (double)no_LED)*1.0/4.0);
			GPC_12 = 0;
			GPC_13 = 1;
			GPC_14 = 1;
			GPC_15 = 1;
			break; 
			case 3:
			dutyCycle = 50;
      target = no_LED + (((double)full_LED - (double)no_LED)*1.0/2.0);
			GPC_12 = 0;
			GPC_13 = 0;
			GPC_14 = 1;
			GPC_15 = 1;
			break;
			case 4:
			dutyCycle = 75;
      target = no_LED + (((double)full_LED - (double)no_LED)*3.0/4.0);
			GPC_12 = 0;
			GPC_13 = 0;
			GPC_14 = 0;
			GPC_15 = 1;
			break;
			case 5:
			dutyCycle = 100;
      target = full_LED;
			GPC_12 = 0;
			GPC_13 = 0;
			GPC_14 = 0;
			GPC_15 = 0;
			break;
			default:
			break;
		}//End switch
		if (update)
		{
      //Get raw ADC value
			raw = ADCraw();
      //Change duty cycle based on ambient light and print
      adjustDutyCycle (dutyCycle, raw, target);
			update = 0;
		}//End if(update)
	}//End while
} //End main
