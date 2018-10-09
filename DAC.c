//DAC.c
//function definitions for interfacing 12 bit DAC
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "DAC.h"
#include "../inc/tm4c123gh6pm.h"


//initializes SSI1 for DAC interface
//input parameters: none
//output parameters: none
void DAC_Init(void){
  SYSCTL_RCGCSSI_R |= 0x02;       // activate SSI1
  SYSCTL_RCGCGPIO_R |= 0x08;      // activate port D
  while((SYSCTL_PRGPIO_R&0x08) == 0){};// ready?
  GPIO_PORTD_AFSEL_R |= 0x0B;     // enable alt funct on PD0,2,3
  GPIO_PORTD_DEN_R |= 0x0B;       // configure PD0,2,3 as SSI
  GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0xFFFF00F0)+0x0002202;
  GPIO_PORTD_AMSEL_R = 0;         // disable analog functionality on PD
  SSI1_CR1_R = 0x00000000;        // disable SSI, master mode
  SSI1_CPSR_R = 0x02;             // 8 MHz SSIClk 
  SSI1_CR0_R &= ~(0x0000FFF0);    // SCR = 0, SPH = 0, SPO = 0 Freescale
  SSI1_CR0_R |= 0x0F;             // DSS = 16-bit data
  SSI1_CR1_R |= 0x00000002;       // enable SSI

}

//outputs value to DAC
//input parameters: value to send to DAC
//output parameters: none
void DAC_Out(uint16_t value){
	  SSI1_DR_R = value;               // load 'value' into transmit FIFO
}
