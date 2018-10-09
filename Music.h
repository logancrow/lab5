//Music.h
//music device driver software
//Logan Crow and Samantha Flaim
//Date Created: 10-3-18
//Date Last Modified: 10-3-18

#include "stdint.h"

const double e1 = 659.26;
const double f1 = 698.46;
const double gf1 = 739.99;
const double g1 = 783.99;
const double a1 = 880;
const double b1 = 987.77;
const double c1 = 1046.5;
const double d2 = 1174.66;
const double e2 = 1318.51;
const double f2 = 1396.91;
const double gf2 = 1479.98;
const double g2 = 1567.98;
const double a2 = 1760;
const double b2 = 1975.53;
const double c2 = 2093;

const uint8_t enote = 1;
const uint8_t qnote = 2;
const uint8_t hnote = 4;
const uint8_t wnote = 8;

struct note{
	double freq;
	uint32_t length;
};

struct note song[100];

//plays song through hardware
//input parameters: pointer to song data structure
//output parameters: none
void Music_Play(uint16_t* song);