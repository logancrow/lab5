//Music.c
//music device driver software
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "Music.h"


//plays song through hardware
//input parameters: pointer to song data structure
//output parameters: none
void Music_Play(uint16_t* song1);

struct note song[30] = {
	 {b1, enote}, {g1, enote}, {b1, hnote}, {b1, enote}, {g1, enote},
	 {b1, enote}, {g1, enote}, {b1, hnote}, {b1, enote}, {g1, enote},
	 {b1, enote}, {a1, enote}, {b1, hnote}, {b1, enote}, {b1, enote},
	 {c1, qnote}, {c1, qnote}, {c1, enote}, {b1, enote}, {a1, enote}, {b1, enote},
	 {g1, qnote}, {g1, qnote}, {a2, wnote},
   {gf2, enote}, {a2, enote}, {gf2, enote}, {d2, enote}
};

void Global_Init(){
	i = 0;
	counter = 1;
}
