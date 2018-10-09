//Music.h
//music device driver software
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "stdint.h"

extern uint8_t counter;
extern int8_t i;

/*#define d1 4257
#define e1 3792
#define f1  3579
#define gf1  3378
#define g1  3189
#define a1  2841
#define b1  2531
#define c1  2389
#define d2  2128
#define e2  1896
#define f2  1790
#define gf2  1689
#define g2  1594
#define a2  1420
#define b2  1265
#define c2  1194*/

#define d1 8513
#define e1 7584
#define f1  7159
#define gf1  6757
#define g1  6378
#define a1  5682
#define b1  5062
#define c1  4778
#define d2  4257
#define e2  3792
#define f2  3579
#define gf2  3378
#define g2  3189
#define a2  2841
#define b2  2531
#define c2  2389

#define enote  1
#define qnote  2
#define hnote  4
#define wnote  8

struct note{
	double freq;
	uint32_t length;
};

extern struct note song[96];

//plays song through hardware
//input parameters: pointer to song data structure
//output parameters: none
void Music_Play(uint16_t*);

void Global_Init(void);
