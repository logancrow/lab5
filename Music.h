//Music.h
//music device driver software
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "stdint.h"

struct note{
	uint32_t frequency;
	uint32_t length;
};

struct note song[100];

//plays song through hardware
//input parameters: pointer to song data structure
//output parameters: none
void Music_Play(uint16_t* song);