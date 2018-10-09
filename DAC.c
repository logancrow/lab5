//DAC.c
//function definitions for interfacing 12 bit DAC
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "DAC.h"

const unsigned short Wave[32] = {
	1024, 1122, 1215, 1302, 1378, 1440, 1486, 1514, 1524, 1514, 1486, 
	1440, 1378, 1302, 1215, 1122, 1024, 926, 833, 746, 670, 608,
	562, 534, 524, 534, 562, 608, 670, 746, 833, 926
};

const unsigned short Trumpet[32] = {
	1007, 1088, 1156, 1194, 1067, 789, 303, 99, 789, 1510, 1476,
	1173, 1067, 1037, 1084, 1062, 1011, 1015, 1045, 1062, 1011, 1011, 
	1058, 1113, 1084, 1075, 1079, 1105, 1088, 1049, 1015, 1045
};

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
