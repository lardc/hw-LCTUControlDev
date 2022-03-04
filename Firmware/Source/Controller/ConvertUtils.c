// Includes
//
#include "ConvertUtils.h"
#include "Global.h"
#include "LowLevel.h"
#include "DataTable.h"
#include "Measurement.h"

// Definitions
#define DAC_MAX_VAL		0x0FFF

// Structs
typedef struct __DisOpAmpConvertParams
{
	float K;
	Int16S B;
}DisOpAmpConvertParams;

typedef struct __MeasurementConvertParams
{
	float P2;
	float P1;
	float P0;
	float K;
	float B;
}MeasurementConvertParams;

// Variables
DisOpAmpConvertParams DisOpAmpVParams;
DisOpAmpConvertParams DisOpAmpIParams[DISOPAMP_CURRENT_RANGE_QUANTITY];
MeasurementConvertParams MeasureVParams[MEASURE_VOLTAGE_RANGE_QUANTITY];
MeasurementConvertParams MeasureIParams[DISOPAMP_CURRENT_RANGE_QUANTITY];
//

// Functions prototypes
Int16U CU_XtoDAC(float Value, DisOpAmpConvertParams Coefficients);
float CU_ADCtoX(Int16U Data, MeasurementConvertParams* Coefficients);


// Functions
//
Int16U CU_XtoDAC(float Value, DisOpAmpConvertParams Coefficients)
{
	Value = (Value + Coefficients.B) * Coefficients.K;

	if(Value < 0)
		Value = 0;

	return (Int16U)Value;
}
//-----------------------------

Int16U CU_VtoDAC(float Voltage)
{
	Int16U Temp;

	Temp = CU_XtoDAC(Voltage, DisOpAmpVParams);

	if (Temp > DAC_MAX_VAL)
		return DAC_MAX_VAL;
	else
		return Temp;
}
//-----------------------------

float CU_ADCtoX(Int16U Data, MeasurementConvertParams* Coefficients)
{
	float Temp;

	Temp = Data * Coefficients->K + Coefficients->B;
	Temp = Temp * Temp * Coefficients->P2 + Temp * Coefficients->P1 + Coefficients->P0;

	return Temp;
}
//-----------------------------

float CU_ADCtoI(Int16U Data, Int16U CurrentRange)
{
	return CU_ADCtoX(Data, &MeasureIParams[CurrentRange]);
}
//-----------------------------

float CU_ADCtoV(Int16U Data, Int16U VoltageRange)
{
	return CU_ADCtoX(Data, &MeasureVParams[VoltageRange]);
}
//-----------------------------

void CU_LoadConvertParams()
{
	// Параметры преобразования напряжения
	DisOpAmpVParams.K = (float)DataTable[REG_DAC_V_CELL_K] / 1000;
	DisOpAmpVParams.B = (Int16S)DataTable[REG_DAC_V_CELL_B];

	MeasureVParams[MEASURE_VOLTAGE_RANGE_0].P2 = (float)(Int16S)DataTable[REG_ADC_V_RANGE0_P2] / 1e6;
	MeasureVParams[MEASURE_VOLTAGE_RANGE_0].P1 = (float)DataTable[REG_ADC_V_RANGE0_P1] / 1000;
	MeasureVParams[MEASURE_VOLTAGE_RANGE_0].P0 = (float)((Int16S)DataTable[REG_ADC_V_RANGE0_P0]) / 10;
	MeasureVParams[MEASURE_VOLTAGE_RANGE_0].K = (float)DataTable[REG_ADC_V_RANGE0_K] / 10000;
	MeasureVParams[MEASURE_VOLTAGE_RANGE_0].B = (Int16S)DataTable[REG_ADC_V_RANGE0_B] / 10;

	MeasureVParams[MEASURE_VOLTAGE_RANGE_1].P2 = (float)(Int16S)DataTable[REG_ADC_V_RANGE1_P2] / 1e6;
	MeasureVParams[MEASURE_VOLTAGE_RANGE_1].P1 = (float)DataTable[REG_ADC_V_RANGE1_P1] / 1000;
	MeasureVParams[MEASURE_VOLTAGE_RANGE_1].P0 = (float)((Int16S)DataTable[REG_ADC_V_RANGE1_P0]) / 10;
	MeasureVParams[MEASURE_VOLTAGE_RANGE_1].K = (float)DataTable[REG_ADC_V_RANGE1_K] / 1000;
	MeasureVParams[MEASURE_VOLTAGE_RANGE_1].B = (Int16S)DataTable[REG_ADC_V_RANGE1_B] / 10;
}
//-----------------------------

