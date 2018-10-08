//DAC.c
//function definitions for interfacing 12 bit DAC
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "DAC.h"

//initializes SSI1 for DAC interface
//input parameters: none
//output parameters: none
void DAC_Init(void){
	SYSCTL_RCGC2_R |= 0x02; //turn clock on for PB
	uint32_t delay = SYSCTL_RCGC2_R;
	GPIO_PORTB_DIR_R |= 0x0F;
	GPIO_PORTB_AFSEL_R &= ~0x0F;
	GPIO_PORTB_DEN_R |= 0x0F;
	GPIO_PORTB_AMSEL_R &= ~0x0F; //no analog
	GPIO_PORTB_PCTL_R &= ~0x00000FFF;
	GPIO_PORTB_DR8R_R |= 0x0F;
}

//outputs value to DAC
//input parameters: value to send to DAC
//output parameters: none
void DAC_Out(uint16_t value){
	
}
