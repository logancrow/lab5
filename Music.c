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

struct note song[96] = {
	//5*4 + 4*2 = 20+8 = 28
	 {b1, enote}, {g1, enote}, {b1, hnote}, {b1, enote}, {g1, enote},
	 {b1, enote}, {g1, enote}, {b1, hnote}, {b1, enote}, {g1, enote},
	 {b1, enote}, {a1, enote}, {b1, hnote}, {b1, enote}, {b1, enote},
	 {c1, qnote}, {c1, qnote}, {c1, enote}, {b1, enote}, {a1, enote}, {b1, enote},
	 {g1, qnote}, {g1, qnote}, {g2, wnote},
   {gf2, enote}, {g2, enote}, {gf2, enote}, {d2, enote},
	 
	 //6*2 + 4*3 + 1 = 12+12+1 = 25 --> 53
	 {e1, hnote}, 
	 {c1, qnote}, {c1, qnote}, {c1, enote}, {b1, enote}, {a1, enote}, {b1, enote},
	 {g1, qnote}, {g1, qnote}, {g2, wnote},
	 {gf1, enote}, {g2, enote}, {b2, enote}, {gf1, enote},
	 {e1, hnote}, {e1, enote}, {gf1, enote}, {g2, enote}, {e1, enote},
	 {c1, qnote}, {c1, qnote}, {c1, enote}, {b1, enote}, {a1, enote}, {b1, enote},
	 
	 //6 + 4*3 + 3 = 9+12 = 21 --> 74
	 {g1, qnote}, {g1, qnote}, {g2, wnote},
	 {gf1, enote}, {g2, enote}, {gf1, enote}, {d1, enote},
	 {e1, wnote},
	 {c1, qnote}, {c1, qnote}, {c1, enote}, {b1, enote}, {a1, enote}, {b1, enote},
	 {g1, qnote}, {g1, qnote}, {g2, wnote},
	 {gf1, enote}, {g2, enote}, {b2, enote}, {gf1, enote},
	 
	 //5*2 + 2 = 12 --> 96
	 {e1, hnote}, {e1, enote}, {gf1, enote}, {g2, enote}, {e1, enote},
	 {c1, qnote}, {c1, qnote}, {c1, enote}, {b1, enote}, {a1, enote}, {b1, enote},
	 {g1, wnote}
};

void Global_Init(){
	i = 0;
	counter = 1;
}
