// Basic I2C Driver.
// Runs on MSP432.
// Matt Laubhan (11/15/2015)
//

#define 	osFeature_Wait   1
#include <stdint.h>
#include "msp.h"
#include "InputOutput.h"
#define NVIC_ISER1  (HWREG32(0xE000E104)) /* Irq 32 to 63 Set Enable Register */
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

int main(void)
{
	unsigned int num = 0;
	unsigned char mode = 0;
	unsigned char base = 0;
	unsigned int countDirection = 0;
	unsigned char switchAddress = I2C_8574 | I2C_0;
	
	InitI2C();
	ConfigureInterrupts();
  EnableInterrupts();
	P4IFG &= ~BIT6;
	getSwitchValue = 1;
	while(1){
		if (getSwitchValue == 1){
			base = InI2C(switchAddress);
			base = InI2C(switchAddress);
			base = InI2C(switchAddress);
			base = base&0x0F;
			base = base % 2;
			mode = InI2C(switchAddress);
			mode = InI2C(switchAddress);
			mode = InI2C(switchAddress);
			mode = mode >> 1;
			mode = mode&0x0F;
			mode = mode % 4;
			countDirection = InI2C(switchAddress);
			countDirection = InI2C(switchAddress);
			countDirection = InI2C(switchAddress);
			countDirection = countDirection >> 3;
			countDirection = countDirection&0x0F;
			countDirection = countDirection % 2;
			getSwitchValue = 0;
		}
		OutputNumTo7Seg(num, mode, base);
		if (countDirection == 0){
			num++;
		}
		if (countDirection == 1){
			num--;
		}
	}

  // this will never be hit (compiler will probably warn)
  //return 0;
}
