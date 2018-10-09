// PeriodicTimer0AInts.c
// Runs on LM4F120/TM4C123
// Use Timer0A in periodic mode to request interrupts at a particular
// period.
// Daniel Valvano
// September 11, 2013

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2015
  Program 7.5, example 7.6

 Copyright 2015 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

// oscilloscope or LED connected to PF3-1 for period measurement
// When using the color wheel, the blue LED on PF2 is on for four
// consecutive interrupts then off for four consecutive interrupts.
// Blue is off for: dark, red, yellow, green
// Blue is on for: light blue, blue, purple, white
// Therefore, the frequency of the pulse measured on PF2 is 1/8 of
// the frequency of the Timer0A interrupts.

#include "..//inc//tm4c123gh6pm.h"
#include <stdint.h>
#include "PLL.h"
#include "Timer0A.h"
#include "ST7735.h"
#include "Music.h"
#include "Switch.h"
#include "DAC.h"
#include "Timer1.h"
#include "Switch.h"

#define PF1       (*((volatile uint32_t *)0x40025008))
#define PF2       (*((volatile uint32_t *)0x40025010))
#define PF3       (*((volatile uint32_t *)0x40025020))
#define PF4       (*((volatile uint32_t *)0x40025040))
#define PF0       (*((volatile uint32_t *)0x40025004))
#define PB0       (*((volatile uint32_t *)0x40005004))
#define PB1       (*((volatile uint32_t *)0x40005008))
#define PB2       (*((volatile uint32_t *)0x40005010))


void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

void UserTask(void){
}
// if desired interrupt frequency is f, Timer0A_Init parameter is busfrequency/f
#define F16HZ 2389
#define F20KHZ 3500


void PortFInit(){
  SYSCTL_RCGCGPIO_R |= 0x20;       // activate port F
  while((SYSCTL_PRGPIO_R&0x0020) == 0){};// ready?
  GPIO_PORTF_DIR_R |= 0x0E;        // make PF3-1 output (PF3-1 built-in LEDs)
  GPIO_PORTF_AFSEL_R &= ~0x1F;     // disable alt funct on PF3-1
  GPIO_PORTF_DEN_R |= 0x1F;        // enable digital I/O on PF3-1
                                   // configure PF3-1 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;          // disable analog functionality on PF
}


int main(void){ 
  PLL_Init(Bus80MHz);              // bus clock at 80 MHz
	SwitchInit();
	DAC_Init();
  Timer0A_Init(&DAC_Out, song[0].freq);  // initialize timer0A (16 Hz)
	Timer1_Init();
	Global_Init();
	PortFInit();
  EnableInterrupts();
	TIMER1_CTL_R = 0x00000000;    // turn off timer 1
	TIMER0_CTL_R = 0x00000000;
  while(1){
			if(PB0 == 0x01) Pause();
			if((GPIO_PORTB_DATA_R & 0x02) == 0x02) Rewind();
			if((GPIO_PORTB_DATA_R & 0x04) == 0x04) {
				if (instrument == 1) instrument = 0;
				else instrument = 1;
				DelayWait10ms(100);
			}
  }
}

