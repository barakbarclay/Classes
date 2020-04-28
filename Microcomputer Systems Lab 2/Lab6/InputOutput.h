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



////////////////////////////////
// Old ADC14 register definitions
////////////////////////////////
#define ADC14CTL0   (HWREG32(0x40012000))
#define ADC14CTL1   (HWREG32(0x40012004))
#define ADC14MCTL0  (HWREG32(0x40012018))
#define ADC14MEM0   (HWREG32(0x40012098))
#define ADC14IER0   (HWREG32(0x4001213C))
#define ADC14IFGR0  (HWREG32(0x40012144))

////////////////////////////////
// Old ADC14 register bit names
////////////////////////////////

// For ADC14CTL0
#define ADC14SHP     ((uint32_t)1 << 26)

#define ADC14DIV_0   ((uint32_t)0 << 22)
#define ADC14DIV_1   ((uint32_t)1 << 22)
#define ADC14DIV_2   ((uint32_t)2 << 22)
#define ADC14DIV_3   ((uint32_t)3 << 22)
#define ADC14DIV_4   ((uint32_t)4 << 22)
#define ADC14DIV_5   ((uint32_t)5 << 22)
#define ADC14DIV_6   ((uint32_t)6 << 22)
#define ADC14DIV_7   ((uint32_t)7 << 22)

#define ADC14SSEL_0   ((uint32_t)0 << 19)
#define ADC14SSEL_1   ((uint32_t)1 << 19)
#define ADC14SSEL_2   ((uint32_t)2 << 19)
#define ADC14SSEL_3   ((uint32_t)3 << 19)
#define ADC14SSEL_4   ((uint32_t)4 << 19)
#define ADC14SSEL_5   ((uint32_t)5 << 19)
#define ADC14SSEL_6   ((uint32_t)6 << 19)
#define ADC14SSEL_7   ((uint32_t)7 << 19)

#define ADC14CONSEQ_0  ((uint32_t)0 << 17)
#define ADC14CONSEQ_1  ((uint32_t)1 << 17)
#define ADC14CONSEQ_2  ((uint32_t)2 << 17)
#define ADC14CONSEQ_3  ((uint32_t)3 << 17)

#define ADC14BUSY      ((uint32_t)1 << 16)

#define ADC14SHT0_0    ((uint32_t)0 << 8)
#define ADC14SHT0_1    ((uint32_t)1 << 8)
#define ADC14SHT0_2    ((uint32_t)2 << 8)
#define ADC14SHT0_3    ((uint32_t)3 << 8)
#define ADC14SHT0_4    ((uint32_t)4 << 8)
#define ADC14SHT0_5    ((uint32_t)5 << 8)
#define ADC14SHT0_6    ((uint32_t)6 << 8)
#define ADC14SHT0_7    ((uint32_t)7 << 8)

#define ADC14MSC       ((uint32_t)1 << 7)
#define ADC14ON        ((uint32_t)1 << 4)
#define ADC14ENC       ((uint32_t)1 << 1)
#define ADC14SC        ((uint32_t)1)

// For ADC14CTL1
#define ADC14RES_0  ((uint32_t)0 << 4)
#define ADC14RES_1  ((uint32_t)1 << 4)
#define ADC14RES_2  ((uint32_t)2 << 4)
#define ADC14RES_3  ((uint32_t)3 << 4)

// For ADC14MCTL0
#define ADC14INCH_0   ((uint32_t)0)
#define ADC14INCH_1   ((uint32_t)1)
#define ADC14INCH_2   ((uint32_t)2)
#define ADC14INCH_3   ((uint32_t)3)
#define ADC14INCH_4   ((uint32_t)4)
#define ADC14INCH_5   ((uint32_t)5)
#define ADC14INCH_6   ((uint32_t)6)
#define ADC14INCH_7   ((uint32_t)7)
#define ADC14INCH_8   ((uint32_t)8)
#define ADC14INCH_9   ((uint32_t)9)
#define ADC14INCH_10  ((uint32_t)10)
#define ADC14INCH_11  ((uint32_t)11)
#define ADC14INCH_12  ((uint32_t)12)
#define ADC14INCH_13  ((uint32_t)13)
#define ADC14INCH_14  ((uint32_t)14)
#define ADC14INCH_15  ((uint32_t)15)
#define ADC14INCH_16  ((uint32_t)16)
#define ADC14INCH_17  ((uint32_t)17)
#define ADC14INCH_18  ((uint32_t)18)
#define ADC14INCH_19  ((uint32_t)19)
#define ADC14INCH_20  ((uint32_t)20)
#define ADC14INCH_21  ((uint32_t)21)
#define ADC14INCH_22  ((uint32_t)22)
#define ADC14INCH_23  ((uint32_t)23)
#define ADC14INCH_24  ((uint32_t)24)
#define ADC14INCH_25  ((uint32_t)25)
#define ADC14INCH_26  ((uint32_t)26)
#define ADC14INCH_27  ((uint32_t)27)
#define ADC14INCH_28  ((uint32_t)28)
#define ADC14INCH_29  ((uint32_t)29)
#define ADC14INCH_30  ((uint32_t)30)
#define ADC14INCH_31  ((uint32_t)31)





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
