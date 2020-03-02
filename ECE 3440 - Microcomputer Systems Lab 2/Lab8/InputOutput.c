// Basic I2C Driver.
// Runs on MSP432.
// Matt Laubhan (11/15/2015)
//

#include <stdint.h>
#include <stdio.h>
#include "msp.h"
#include "InputOutput.h"
#define NVIC_ISER0  (HWREG32(0xE000E100))
#define NVIC_ISER1  (HWREG32(0xE000E104)) /* Irq 32 to 63 Set Enable Register */


// Global variables (shared between main and ISR)
volatile unsigned short high;
volatile unsigned short low;
volatile unsigned short prevFall;
volatile unsigned short prevRise;
volatile unsigned short prevPrevCap;
volatile unsigned short prevCap;
volatile unsigned short curCap;
volatile unsigned short period = 0;
volatile unsigned short delta;
char checkPin;
int getSwitchValue = 0;

// Function prototype
extern void WaitForInterrupt(void); // defined in startup_msp432.s as a subroutine

// Function prototype
extern void EnableInterrupts(void); // defined in startup_msp432.s as a subroutine

//----------------------------------------  
// eUSCI wait until START and address are transmitted
//----------------------------------------
void WaitStart(void)
{
  while ((UCB0CTLW0 & UCTXSTT) != 0);
}

//----------------------------------------  
// eUSCI wait until STOP is complete
//----------------------------------------
void WaitStop(void)
{
  while ((UCB0CTLW0 & UCTXSTP) != 0);
}

//----------------------------------------  
// eUSCI wait until TX is complete
//----------------------------------------
void WaitTx(void)
{
  while ((UCB0IFG & UCTXIFG0) == 0);
}

//----------------------------------------  
// eUSCI wait until RX is complete
//----------------------------------------
void WaitRx(void)
{
  while ((UCB0IFG & UCRXIFG0) == 0);
}

//----------------------------------------  
// eUSCI generate start
//----------------------------------------
void GenStart(void)
{
  UCB0CTLW0 |= UCTXSTT;
}

//----------------------------------------  
// eUSCI generate stop
//----------------------------------------
void GenStop(void)
{
  UCB0CTLW0 |= UCTXSTP;
}

// No parameters
void InitI2C(void)
{
  //
  // Configure with the following parameters:
  // * 7-bit addresses.
  // * single master environment.
  // * MSP432 is always master.
  // * I2C mode.
  // * Synchronous mode.
  // * SMCLK is source.
  // * Automatically trigger address ACK.
  // * No interrupts.
  //
  UCB0CTLW0 |= UCSWRST;   // hold USCI in reset.
  P1SEL0 |= 0xC0;   // P1.7 (SCL) and P1.6 (SDA) multiplexing.
  P1SEL1 &= ~0xC0; 
  UCB0CTLW0 |= (UCMST | UCMODE_3 | UCSYNC | UCSSEL_2);
  UCB0BRW = 400; // Divide SMCLK down by this factor to get SCL.
  UCB0CTLW0 &= ~UCSWRST;   // release USCI reset.
}

//
// Send a byte of data to the I2C target.
// [Note there is no error checking here.]
//
void OutI2C(unsigned char address, unsigned char data)
{
  UCB0I2CSA = address; // UCB0I2CSA = <expander addr w/o R/W bit>.
  UCB0CTLW0 |= UCTR;   // TX.
  GenStart();          // Generate a START.
  WaitStart();         // Wait for START and slave address to be sent.
  WaitTx();            // Wait until it is safe to write to TX buffer.
  UCB0TXBUF = data;    // UCB0TXBUF = <data> (prep data).
  if ((UCB0IFG & UCNACKIFG) == 0) // Check for slave NACK.
  {
    // I2C slave responded.
    WaitTx();          // Wait until data is transferred.
  }
  else
  {
    // I2C slave did not respond.
  }
  GenStop();           // Generate a STOP.
  WaitStop();          // Wait for STOP to be sent/ready to go again.
}

//
// Receive a byte of data from the I2C target.
// [Note there is no error checking here.]
//
unsigned char InI2C(unsigned char address)
{
  unsigned char retVal;
  
  UCB0I2CSA = address; // UCB0I2CSA = <expander addr w/o R/W bit>.
  UCB0CTLW0 &= ~UCTR;  // RX.
  GenStart();          // Generate a START.
  WaitStart();         // Wait for START and slave address to be sent.
  if ((UCB0IFG & UCNACKIFG) == 0) // Check for slave NACK.
  {
    // I2C slave responded.  Get data.
    WaitRx();            // Wait for data.
    retVal = UCB0RXBUF;  // Read UCB0RXBUF for data.
  }	
  else
  {
    // I2C slave did not respond.
  }
  GenStop();           // Generate a STOP.
  WaitStop();          // Wait for STOP to be sent/ready to go again.
  
  return retVal;
}

////////////////////////////////////////////////////////////////////////
//
// Enable interrupts on P4.6.  Port4_IRQHandler should get called below whenever
// a one of the 8 inputs to I2C_SWITCH change--provided P4.6 is connected
// to the INT signal on I2C_0.
//
void ConfigureInterrupts()
{  
  // Make sure P4.6 is an input and allow it to generate interrupts.
  // Needs an internal pull-up resistor too.
  P4DIR &= ~BIT6;
  P4IES |= BIT6;
  P4IE |= BIT6;
  P4REN |= BIT6;
  P4OUT |= BIT6;
  P4IFG &= ~BIT6;
  NVIC_ISER1 |= BIT6; // IRQ 38
}

// In Keil, name the ISR exactly the following...
void PORT4_IRQHandler(void)
{ 
	for (int i = 0; i<=100; i++)
		{
			
		}
	getSwitchValue = 1;	
  // Always clear the port-level latch.
  P4IFG &= ~BIT6;

  // MSP432 will now resume whatever it was doing when the interrupt
  // came in
}

void OutputNumTo7Seg(unsigned int number, unsigned char mode, unsigned char base)
{
  unsigned char sevenSegLedAddress = I2C_8574 | I2C_3;
  unsigned char sevenSegLedAddress2 = I2C_8574 | I2C_4;
  unsigned char data;
  unsigned char lookup[16] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 
	0x00, 0x18, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0E};
	int i = 0;
	int i2 = 0;
  if (base == 0){
		i = number % 10;
		i2 = (number / 10) % 10;
	}
  if (base == 1){
		i = number % 16;
		i2 = (number / 16) % 16;
	}	
		
	switch (mode){
		case 0: {
			data = lookup[i];
			OutI2C(sevenSegLedAddress2, data);
			data = lookup[0];
			OutI2C(sevenSegLedAddress, data);
			for(int x=0;x<100;x++)
			for(int y=0;y<1275;y++);
			break;
		}
		case 1: {
			data = lookup[i];
			OutI2C(sevenSegLedAddress2, data);
			data = lookup[0];
			OutI2C(sevenSegLedAddress, data);
			for(int x=0;x<100;x++)
			for(int y=0;y<1275;y++);
			break;
		}
		case 2:{
			data = lookup[i];
			OutI2C(sevenSegLedAddress, data);
			data = lookup[0];
			OutI2C(sevenSegLedAddress2, data);
			for(int x=0;x<100;x++)
			for(int y=0;y<1275;y++);
			break;
		}
		case 3:{
			data = lookup[i2];
			OutI2C(sevenSegLedAddress2, data);
			data = lookup[i];
			OutI2C(sevenSegLedAddress, data);
			for(int x=0;x<100;x++)
			for(int y=0;y<1275;y++);
			break;
		}
	}
}

void LCDSDEL()
{
  for (int i = 0; i <= 1; i++){}
		return;
}
void LCDLDEL()
{
  for (int j = 0; j <=220; j++){}
		return;
}
void OutLCD(unsigned char output, unsigned char type)
{
  unsigned char lcdModeAddress = I2C_8574 | I2C_1;
  unsigned char lcdDispAddress = I2C_8574 | I2C_2;
  unsigned char mask;
  
  OutI2C(lcdModeAddress,output);
  OutI2C(lcdDispAddress,output);
  
  if (type == 0x00)
  {
    mask = 0x00;
  }
  else{
    mask = 0x01;
  }
  
  OutI2C(lcdModeAddress, 0x04 | mask);
  
  OutI2C(lcdDispAddress,output);
  
  OutI2C(lcdModeAddress, 0x04 & mask);
}
void InitLCD()
{
  for(int x=0;x<1275;x++);
  OutLCD(0x3f, 0);
  //LCDSDEL();
  OutLCD(0x18, 0);
  //LCDSDEL();
  OutLCD(0x0c, 0);
  //LCDSDEL();
  OutLCD(0x06, 0);
  //LCDSDEL();
  OutLCD(0x01, 0);
  //LCDLDEL();
}

void OutputString(char *str)
{
  char myChar = *str;
  
  while (myChar != 0) 
  {
    OutLCD(myChar, 1);
    str++;
    myChar = *str;
  }
}

void InitAD (void)
{
	P6SEL0 |= BIT0;
	P6SEL1 |= BIT0;
	ADC14CTL0 &= ~0x00000002;
	while(ADC14CTL0&0x00010000){};
		ADC14CTL0 |= 0x04243310;
		ADC14CTL1 = 0x00000030;
		ADC14MCTL0 |= 0x0000018F;
		while(ADC14CTL0&0x00010000){};
			ADC14CTL0 |= 0x00000003;
}

void SetupPeriodMeas()
{
  // Set up output pin parameters
  P5DIR &= ~BIT7;   // P5.7 is input
  P5SEL0 |= BIT7;   // Multiplexing
  P5SEL1 &= ~BIT7;  // "          "
    
  // Set up attributes for TimerA instance 0
  // (common to all channels)
  TA2CTL = (TASSEL_2 | ID_0 | MC_2); // SMCLK sourced, /1, "continuous" mode, no interrupts

  // Set up the channel-specific functions (for channel 1)
  // - configure input capture channel 0 (rising and falling edges)
  // - sourced by CCI1A
  // - interrupt notification on capture
  TA2CCTL2 = (CM_3 | CCIS_0 | SCS | CAP | CCIE);
  
  // Allow interrupt to pass through NVIC
  NVIC_ISER0 |= BITD;
	
	// Allow maskable interrupts into the CPU
  EnableInterrupts();
}

void TA2_N_IRQHandler(void)
{
  // read TA2CCR2 to prevent COV flag,
  // pull into a local variable
	unsigned short check;
  check = P5IN & BIT7;

//	unsigned short curCap = TA2CCR2;

	if(check)
	{
//		period = curCap - prevPrevCap;
		low = TA2CCR2 - prevFall;
		prevRise = TA2CCR2;
	}
	
	else
	{
//		delta = curCap - prevCap;
		high = TA2CCR2 - prevRise;
		prevFall = TA2CCR2;
	}
//	prevPrevCap = prevCap;
//	prevCap = curCap;
  
  // clear the CCIFG flag in the TA2CCTL2 before returning
  TA2CCTL2 &= ~CCIFG;
	TA2CTL &= ~TAIFG;
	
	// Allow maskable interrupts into the CPU
  EnableInterrupts();
}



















//------------LAB 08--------------------
//
void initThermo(){
    //set the clock pin 1.5 as output
    P1DIR |=BIT5;
    //set reset pin 3.o as output
    P3DIR |=BIT0;
}

void clk_high()
{
        P1OUT |=BIT5;
}

void clk_low()
{
        P1OUT &= ~BIT5;
}

void rst_high()
{
        P3OUT |=BIT0;
}

void rst_low()
{
        P3OUT &= ~BIT0;
}

void out_bit(int bit)
{
        //port 4.3 is output
        P4DIR  |= BIT3;
        if(bit == 1){
            P4OUT|=BIT3;
        }
        else{
            P4OUT  &= ~ BIT3;
        }
        clk_low();             /* and then provide a clock pulse */
        clk_high();
}

void write_command(int command)
/* sends 8 bit command on DQ output, least sig bit first */
{
        int n, bit;

        for (n = 0; n < 8; n++)
        {
                bit = ((command >> n) & (0x01));
                out_bit(bit);
        }
}

void WrCfg(){
    write_command(0x0c);
}

void RdCfg(){
    write_command(0xac);
}

void StartCnv(){
    write_command(0xEE);
}

void write_data(int data)
/* sends 9 bit data on DQ output, least sig bit first */
{
        int n, bit;

        for (n = 0; n < 8; n++)
        {
                bit = ((data >> n) & (0x01));
                out_bit(bit);
        }
        out_bit(0); //9th bit
}

int read_raw_data()
{
        int bit, n;
        int raw_data = 0;
        // go into input mode
        //port 4.3 is output
        P4DIR  &= ~ BIT3;

        /* jam the dq lead high to use as input */
        for (n = 0; n < 9; n++)
        {
                clk_low();
                if (P4IN & BIT3)
                        bit = 1;
                else
                        bit = 0;
                clk_high();
                raw_data = raw_data | (bit << n);
        }
        //          pinMode(dqPin, OUTPUT);
        // make it a output again
        //port 4.3 is output
        P4DIR  |= BIT3;
       
        return (raw_data);
}

double RdTemp()
{
        rst_low();

        clk_high();
        rst_high(); //all data transfer are initiated by driving RST high
        //write_command(0x0c); // write config command
        WrCfg();// write config command
        write_command(0x02); // cpu mode
        rst_low();

        clk_high();
        rst_high();
        //write_command(0xEE); //start conversion
        StartCnv(); //start conversion
        rst_low();

        clk_high();
        rst_high();
        write_command(0xAA);
        int raw_data = read_raw_data();
        rst_low();

        return ((double)raw_data / 2.0);
}

int main(void)
{
  char str[17];
  double CelTemp = 0.0;
  double FahTemp = 0.0;
   
	InitI2C();
  InitLCD();
	InitAD();
	ConfigureInterrupts();
	EnableInterrupts();
  initThermo();
 // StartCnv();
	
	while(1){
		CelTemp = RdTemp();
    FahTemp = CelTemp * 9.0 / 5.0 + 32.0;
		
		OutLCD(0x3, 0);
		LCDSDEL(); 
		sprintf(str, "%.1f", CelTemp);
		OutputString(str);
		LCDSDEL();
		
		sprintf(str, " %.1f" , FahTemp);
		OutLCD(0x86, 0);
		LCDSDEL();
		OutputString(str);
		LCDSDEL();
	}

  // this will never be hit (compiler will probably warn)
  //return 0;
}
