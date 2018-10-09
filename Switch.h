//Switch.h
//function decleration for Switch interfacing for 12 bit DAC
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "stdint.h"

//Initializes PB0 and PB1 to be inputs
//input parameters: none
//output parameters: none
void SwitchInit(void);

//Plays/Pauses music by enabling/disabling Timer0
//input parameters: none
//output parameters: none
void Pause(void);

//waits 10ms
void DelayWait10ms(uint32_t);

//rewinds and stops
void Rewind(void);
