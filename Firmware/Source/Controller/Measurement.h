#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_

// Includes
#include "SysConfig.h"
#include "ZwBase.h"

// Definitions
#define PULSE_ARR_MAX_LENGTH					300				// Количество точек оцифровки
//
#define MEASURE_VOLTAGE_RANGE_THRESHOLD			100
#define MEASURE_VOLTAGE_RANGE_QUANTITY			1
#define MEASURE_VOLTAGE_RANGE_0					0
#define MEASURE_VOLTAGE_RANGE_1					1

// Variables
extern Int16U MEASURE_ADC_VoltageRaw[ADC_DMA_BUFF_SIZE];
extern Int16U MEASURE_ADC_CurrentRaw[ADC_DMA_BUFF_SIZE];

// Functions
float MEASURE_SampleVoltage();
void MEASURE_DMABuffersClear();

#endif /* MEASUREMENT_H_ */
