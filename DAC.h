//DAC.h
//function declerations for interfacing 12 bit DAC
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "stdint.h"

struct note{
	uint32_t frequency;
	uint32_t length;
};

struct note song[100];

//initializes SSI1 for DAC interface
//input parameters: none
//output parameters: none
void DAC_Init(void);

//outputs value to DAC
//input parameters: value to send to DAC
//output parameters: none
void DAC_Out(uint16_t);
