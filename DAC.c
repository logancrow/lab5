//DAC.c
//function definitions for interfacing 12 bit DAC
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "DAC.h"
#include "../inc/tm4c123gh6pm.h"


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

int j = 0;

//initializes SSI1 for DAC interface
//input parameters: none
//output parameters: none
void DAC_Init(void){
  SYSCTL_RCGCSSI_R |= 0x01;       // activate SSI0
  SYSCTL_RCGCGPIO_R |= 0x01;      // activate port A
  while((SYSCTL_PRGPIO_R&0x01) == 0){};// ready?
  GPIO_PORTA_AFSEL_R |= 0x2C;     // enable alt funct on PA2,3,5
  GPIO_PORTA_DEN_R |= 0x2C;       // configure PA2,3,5 as SSI
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFF0F00FF)+0x00202200;
  GPIO_PORTA_AMSEL_R = 0;         // disable analog functionality on PA
  SSI0_CR1_R = 0x00000000;        // disable SSI, master mode
  SSI0_CPSR_R = 0x02;             // 8 MHz SSIClk 
  SSI0_CR0_R &= ~(0x0000FFF0);    // SCR = 0, SPH = 0, SPO = 0 Freescale
  SSI0_CR0_R |= 0x0F;             // DSS = 16-bit data
  SSI0_CR1_R |= 0x00000002;       // enable SSI

	j = 0;
}

#define PF1       (*((volatile uint32_t *)0x40025008))
#define PF2       (*((volatile uint32_t *)0x40025010))
#define PF3       (*((volatile uint32_t *)0x40025020))
//outputs value to DAC
//input parameters: value to send to DAC
//output parameters: none
void DAC_Out(){
	PF3 ^= 0x08;
	SSI0_DR_R = (Wave[j] & 0x0FFF) | 0xC000;               // load 'value' into transmit FIFO
	j = (j + 1)%32;
}
