//
// Matt Laubhan (11/15/2015)
//
// Addresses for the two types of I2C I/O expanders you may have.
// These are bits A6-A3 of the I2C raw address.
// x010 0xxx (PCF8574)
// x011 1xxx (PCF8574A)
//
#define I2C_8574   0x20
#define I2C_8574_A 0x38

//
// The possible address values to be passed into the functions below.
//
#define I2C_0   0x00   // A2-A0: 000
#define I2C_1   0x01   // A2-A0: 001
#define I2C_2   0x02   // A2-A0: 010
#define I2C_3   0x03   // A2-A0: 011
#define I2C_4   0x04   // A2-A0: 100
#define I2C_5   0x05   // A2-A0: 101
#define I2C_6   0x06   // A2-A0: 110
#define I2C_7   0x07   // A2-A0: 111

// Usage of address is <device> | <I2C_?>
// Ex:  address = I2C_8574 | I2C_0
// Ex:  address = I2C_8574_A | I2C_3
//
// data is always 8-bit

// No parameters
void InitI2C(void);
          
// address is A2-A0 pins left-shifted one
// data is the data to transmit
void OutI2C(unsigned char address, unsigned char data);
        
// address in A2-A0 pins left-shifted one
// On return:  the data received from I2C device
unsigned char InI2C(unsigned char address);
