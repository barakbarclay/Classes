// ECE 3440 Test Program.
// Runs on MSP432P401R.
// Matt Laubhan (11/29/2015)
//

#include <stdint.h>
#include <stdio.h>
#include "msp.h"

// Defined in InputOutput.lib
extern int Run3440Test(void);

int main(void)
{  
  return Run3440Test();
}
