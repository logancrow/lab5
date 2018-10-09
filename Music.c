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
	 {d2, qnote}, {g1, qnote}, {d2, hnote}, {d2, qnote}, {g1, qnote},
	 {d2, qnote}, {g1, qnote}, {d2, hnote}, {d2, qnote}, {g1, qnote},
	 {e2, qnote}, {a1, qnote}, {e2, hnote}, {e2, qnote}, {b2, qnote},
	 {e2, qnote}, {e2, qnote}, {c2, qnote}, {b2, qnote}, {a1, qnote}, {b2, qnote},
	 {g1, qnote}, {g1, qnote}, {a2, hnote}, {a2, hnote},
	 {a2, hnote}, {gf2, qnote}, {a2, qnote}, {gf2, qnote}, {d2, qnote}
};

void Global_Init(){
	i = 0;
	counter = 1;
}
