//DAC.h
//function declerations for interfacing 12 bit DAC
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "stdint.h"

//initializes SSI1 for DAC interface
//input parameters: none
//output parameters: none
void DAC_Init(void);

//outputs value to DAC
//input parameters: none
//output parameters: none
void DAC_Out(void);
