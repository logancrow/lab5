//Switch.c
//function definitions for Switch interfacing for 12 bit DAC
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "Switch.h"
#include "../inc/tm4c123gh6pm.h"
#include "Music.h"
#include "Timer1.h"

long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
extern uint8_t counter;
extern int8_t i;

//pass a number and that number * 10ms will be waited
void DelayWait10ms(uint32_t n){
	uint32_t volatile time;
  while(n){
    time = 727240*2/91;  //10msec
    while(time){
	  	time--;
    }
    n--;
  }
}

//Initializes PB0, PB1 and PB2 to be inputs
//input parameters: none
//output parameters: none
void SwitchInit(void){
	SYSCTL_RCGCGPIO_R |= 0x02;
  while((SYSCTL_PRGPIO_R&0x0002)== 0){}; // allow time for clock to start		
	GPIO_PORTB_DEN_R |= 0x07;	//PB0-2 enable
	GPIO_PORTB_DIR_R &=~ 0x07; //PB0-2 input	
  GPIO_PORTB_AFSEL_R &= ~0x07; //disable alternate function
	GPIO_PORTB_AMSEL_R = 0;          // disable analog functionality on PF
}

#define PF2       (*((volatile uint32_t *)0x40025010))

//Plays/Pauses music by enabling/disabling Timer0
//input parameters: none
//output parameters: none
void Pause(void){
	long sr;
	sr = StartCritical();
	//PF2 ^= 0x04;
	//PF2 ^= 0x04;
	if(TIMER1_CTL_R == 0x00000000){
		TIMER1_CTL_R = 0x00000001;    // toggle
		TIMER0_CTL_R = 0x00000001;
	}else{
		TIMER1_CTL_R = 0x00000000;    // toggle
		TIMER0_CTL_R = 0x00000000;
	}
	//PF2 ^= 0x04;
	EndCritical(sr);
	DelayWait10ms(100);             // debounce
}
#define PF1       (*((volatile uint32_t *)0x40025008))

void Rewind(){
	long sr;
	sr = StartCritical();
	//PF1 ^= 0x02;
	//PF1 ^= 0x02;
	TIMER0_CTL_R = 0x00000000;    // disable timer 0
	TIMER1_CTL_R = 0x00000000;    // disable timer 1
	i = 0;
	counter = 1;
	//TIMER1_CTL_R = 0x00000001;    // enable timer 0
	//TIMER0_CTL_R = 0x00000001;    // enable timer 1
	//PF1 ^= 0x02;
	EndCritical(sr);
	DelayWait10ms(100);             // debounce
}
