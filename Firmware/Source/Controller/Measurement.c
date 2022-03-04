// Includes
#include "Measurement.h"
#include "ConvertUtils.h"
#include "Board.h"
#include "DiscreteOpAmp.h"
#include "Global.h"
#include "LowLevel.h"

// Variables
Int16U MEASURE_ADC_VoltageRaw[ADC_DMA_BUFF_SIZE];
Int16U MEASURE_ADC_CurrentRaw[ADC_DMA_BUFF_SIZE];
Int16U MEASURE_VoltageRange = 0;

// Functions prototypes
Int16U MEASURE_DMAExtractX(Int16U* InputArray, Int16U ArraySize);
Int16U MEASURE_DMAExtractVoltage();
Int16U MEASURE_DMAExtractCurrent();
void MEASURE_StartNewSampling();

// Functions
//
void MEASURE_SampleParams(volatile MeasureSample* Sample)
{
	Sample->Voltage = MEASURE_SampleVoltage();
	Sample->Current = MEASURE_SampleCurrent();

	MEASURE_StartNewSampling();
}
//-----------------------------------------------

float MEASURE_SampleVoltage()
{
	return CU_ADCtoV(MEASURE_DMAExtractVoltage(), MEASURE_VoltageRange);
}
//-----------------------------------------------

float MEASURE_SampleCurrent()
{
	return CU_ADCtoI(MEASURE_DMAExtractCurrent(), DISOPAMP_GetCurrentRange());
}
//-----------------------------------------------

Int16U MEASURE_DMAExtractX(Int16U* InputArray, Int16U ArraySize)
{
	Int32U AverageData = 0;

	for(int i = 0; i < ArraySize; i++)
		AverageData += *(InputArray + i);

	return (Int16U)((float)AverageData / ArraySize);
}
//-----------------------------------------------

Int16U MEASURE_DMAExtractVoltage()
{
	return MEASURE_DMAExtractX(&MEASURE_ADC_VoltageRaw[1], ADC_DMA_BUFF_SIZE - 1);
}
//-----------------------------------------------

Int16U MEASURE_DMAExtractCurrent()
{
	return MEASURE_DMAExtractX(&MEASURE_ADC_CurrentRaw[1], ADC_DMA_BUFF_SIZE - 1);
}
//-----------------------------------------------

void MEASURE_DMABuffersClear()
{
	for(int i = 0; i < ADC_DMA_BUFF_SIZE; i++)
	{
		MEASURE_ADC_VoltageRaw[i] = 0;
		MEASURE_ADC_CurrentRaw[i] = 0;
	}
}
//-----------------------------------------------

void MEASURE_StartNewSampling()
{
	DMA_TransferCompleteReset(DMA1, DMA_TRANSFER_COMPLETE);
	DMA_TransferCompleteReset(DMA2, DMA_TRANSFER_COMPLETE);
	ADC_SamplingStart(ADC1);
}
//-----------------------------------------------

void MEASURE_SetVoltageRange(float Voltage)
{
	if(Voltage <= MEASURE_VOLTAGE_RANGE_THRESHOLD)
		MEASURE_VoltageRange = MEASURE_VOLTAGE_RANGE_0;
	else
		MEASURE_VoltageRange = MEASURE_VOLTAGE_RANGE_1;

	LL_SetVoltageRange(MEASURE_VoltageRange);
}
//-----------------------------------------------


