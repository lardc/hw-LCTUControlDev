#ifndef DISCRETEOPAMP_H_
#define DISCRETEOPAMP_H_

// Includes
#include "ZwBase.h"

// Definitions
#define CURRENT_RANGE0		0
#define CURRENT_RANGE1		1
#define CURRENT_RANGE2		2
#define CURRENT_RANGE3		3

// Functions
void DISOPAMP_SetCurrentCutOff(float Current);
void DISOPAMP_SetVoltage(float Voltage);
Int16U DISOPAMP_GetCurrentRange();

#endif /* DISCRETEOPAMP_H_ */
