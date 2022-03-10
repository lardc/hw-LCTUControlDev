#ifndef __LOWLEVEL_H
#define __LOWLEVEL_H

// Include
#include "Board.h"
#include "stdinc.h"

// Defines
#define DAC_CHANNEL_B		BIT15

// Functions
//
void LL_ToggleBoardLED();
void LL_SetStateLineSync(bool State);
void LL_WriteDACx(Int16U Data);
void LL_SetCurrentRange0();
void LL_SetCurrentRange1();
void LL_SetCurrentRange2();
void LL_SetCurrentRange3();
void LL_ToggleLDAC();

#endif //__LOWLEVEL_H
