// _COLOR_MODES.h

#ifndef __COLOR_MODES_h
#define __COLOR_MODES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif




////////////////////////////////////////////////////////////////////////////////////////////////
//// COLOR MODES  //// COLOR MODES  //// COLOR MODES  //// COLOR MODES  //// COLOR MODES  //////
////////////////////////////////////////////////////////////////////////////////////////////////
const PROGMEM  uint8_t ModeSetFLASH [14][36]= // FACTORY DEFAULT
{
	3,0,  21,0,   4,3,  23,0,   0,0,  0,0,    0,0,   0,0,  0,1,    // Mode 1  // Prime A
	2,0,  8,0,   13,3,  0,0,   0,0,  0,0,    0,0,   0,0,  0,2,    // Mode 1  // Prime B

	2,0,  1,0,  7,3,  10,0,  18,2,  0,0,  0,0,  0,0,  0,3,    // Mode 2  // Prime A
	5,0,  21,0,  1,0,  6,0,  14,2,  0,0,  0,0,  0,0,  0,4,    // Mode 2  // Prime B

	5,0,  5,0,  12,0,  23,2,  4,1,  1,0,  0,0,  0,0,  0,5,      // Mode 3  // Prime A
	5,0,  22,0,  17,0,  16,2,  20,1,  25,0,  0,0,  0,0,  0,6,    // Mode 3  // Prime B

	3,0,  6,0,  10,0,  5,0,  7,0,  12,0,  15,0,  18,0,  21,0,    // Mode 4  // Prime A
	8,0,  1,0,  3,0,  5,0,  7,0,  12,0,  15,0,  18,0,  21,0,    // Mode 4  // Prime B

	4,0,  1,3,  6,0,  21,0,  14,0,  2,1,  0,0,  0,0,  0,9,    // Mode 5  // Prime A ////////////
	4,0,  14,3, 6,0,  21,0,  14,0,  2,1,  0,0,  0,0,  0,10,    // Mode 5  // Prime B

	3,0,  23,0,  23,3,  24,3,  7,0,  0,0,  0,0,  0,0,  0,11,   // Mode 6 // Prime A
	3,0,  13,0,  14,3,  15,3,  7,0,  0,0,  0,0,  0,0,  0,12,   // Mode 6 // Prime B

	2,0,  1,3,  14,0,  21,0,   0,0,  0,0,    0,0,   0,0,  0,13,   // Mode 7 // Prime A//////
	4,0,  23,0,  23,3,  24,3,   4,0,  0,0,    0,0,   0,0,  0,14,   // Mode 7 // Prime B

	3,0,    1,0,  5,0,  7,0,  5,0,  11,0,  0,0,  0,0,  0,15,   // Mode 8 // Prime A
	3,0,    13,0,  17,0,  20,0,  5,0,  11,0,  0,0,  0,0,  0,16,   // Mode 8 // Prime B

	1,0,    0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,17,   // Mode 9 // Prime A
	1,0,    0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,18,   // Mode 9 // Prime B

	1,0,    0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,19,   // Mode 10 // Prime A
	1,0,    0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,20,    // Mode 10 // Prime B

	31,0,    0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,21,    // Mode 11  // Prime A
	1,0,    0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,22,     // Mode 11  // Prime B

	1,0,    0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,23,   // Mode 12 // Prime A
	1,0,    0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,24,   // Mode 12 // Prime B

	1,0,    0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,25,   // Mode 13 // Prime A // RESERVED
	1,0,    0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,0,  0,26   // Mode 13 // Prime B // RESERVED

};
////////////////////////////////////////////////////////////////////////////////////////////////
//// COLOR MODES  //// COLOR MODES  //// COLOR MODES  //// COLOR MODES  //// COLOR MODES  //////
////////////////////////////////////////////////////////////////////////////////////////////////




#endif

