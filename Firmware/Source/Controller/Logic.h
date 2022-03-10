#ifndef LOGIC_H_
#define LOGIC_H_

// Includes
#include "Measurement.h"

// Variables
extern float VoltageTarget;
extern float CurrentCutOff;

// Functions
bool LOGIC_RegulatorCycle(float Voltage);
void LOGIC_StopProcess();
void LOGIC_StartPrepare();
void LOGIC_LoggingProcess(volatile float Voltage);
float LOGIC_GetAverageVoltage();
float LOGIC_GetLastSampledVoltage();
void LOGIC_SetCurrentRange();

#endif /* LOGIC_H_ */
