#ifndef __DEBUGACTIONS_H
#define __DEBUGACTIONS_H

// Include
//
#include "ZwBase.h"

// Functions
//
void DBGACT_BlinkExtLeds();
void DBGACT_GenerateImpulseToLineSync1();
void DBGACT_GenerateImpulseToLineSync2();
bool DBGACT_ReadStateLineSync1();
bool DBGACT_ReadStateLineSync2();
void DBGACT_SetCurrentRange(uint16_t Range);
void DBGACT_PowerSupplyEnable(bool State);
void DBGACT_SetCurrentCutoff(uint16_t Data);
void DBGACT_SetVoltageCell(uint16_t CellNumber, uint16_t Data);

#endif //__DEBUGACTIONS_H
