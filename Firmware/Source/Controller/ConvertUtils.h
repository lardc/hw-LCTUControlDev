#ifndef CONVERTUTILS_H_
#define CONVERTUTILS_H_

// Includes
#include "ZwBase.h"

// Functions
Int16U CU_VtoDAC(float Voltage);
float CU_ADCtoI(Int16U Data, Int16U CurrentRange);
float CU_ADCtoV(Int16U Data, Int16U VoltageRange);
void CU_LoadConvertParams();

#endif /* CONVERTUTILS_H_ */
