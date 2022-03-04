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
void LL_SetVoltageRange(bool State);
void LL_SetStateExtMsrLed(bool State);
void LL_SetStateLineSync1(bool State);
void LL_SetStateLineSync2(bool State);
bool LL_GetStateLineSync1();
bool LL_GetStateLineSync2();
void LL_PowerSupplyEnable(bool State);
void LL_WriteDACx(Int16U Data, Int16U CellStartNumber, Int16U CellTotal, bool ToggleLDAC);
void LL_SetStateCS_SYNC1(bool State);
void LL_SetStateCS_SYNC2(bool State);
void LL_SetStateCS_SYNC3(bool State);
void LL_SetStateCS_SYNC4(bool State);
void LL_SetStateCS_SYNC5(bool State);
void LL_SetStateCS_SYNC6(bool State);
void LL_SetStateCS_SYNC7(bool State);
void LL_SetStateCS_SYNC8(bool State);
void LL_SetCurrentRange0();
void LL_SetCurrentRange1();
void LL_SetCurrentRange2();
void LL_SetCurrentRange3();
void LL_ToggleLDAC();

#endif //__LOWLEVEL_H
