// Includes
#include "DiscreteOpAmp.h"
#include "LowLevel.h"
#include "ConvertUtils.h"
#include "Global.h"
#include "DataTable.h"

// Variables
Int16U CurrentCutOffRange = 0;


// Functions
//
void DISOPAMP_SetCurrentCutOff(float Current)
{
	if(Current <= DISOPAMP_CURRENT_THRESHOLD_RANGE_0)
	{
		LL_SetCurrentRange0();
		CurrentCutOffRange = CURRENT_RANGE0;
	}
	else if(Current <= DISOPAMP_CURRENT_THRESHOLD_RANGE_1)
	{
		LL_SetCurrentRange1();
		CurrentCutOffRange = CURRENT_RANGE1;
	}
	else if(Current <= DISOPAMP_CURRENT_THRESHOLD_RANGE_2)
	{
		LL_SetCurrentRange2();
		CurrentCutOffRange = CURRENT_RANGE2;
	}
	else
	{
		LL_SetCurrentRange3();
		CurrentCutOffRange = CURRENT_RANGE3;
	}
}
//-----------------------------

void DISOPAMP_SetVoltage(float Voltage)
{
	Int16U CellCounter = 0;

	if(Voltage)
	{
		while(Voltage >= DISOPAMP_CELL_VOLATGE_MAX)
		{
			Voltage -= DISOPAMP_CELL_VOLATGE_MAX;
			CellCounter++;
		}

		if(!CellCounter)
			LL_WriteDACx(CU_VtoDAC(Voltage) | DAC_CHANNEL_B, DISOPAMP_POSITION_CELL0, 1, false);
		else
		{
			LL_WriteDACx(CU_VtoDAC(DISOPAMP_CELL_VOLATGE_MAX) | DAC_CHANNEL_B, DISOPAMP_POSITION_CELL0, CellCounter, false);
			LL_WriteDACx(CU_VtoDAC(Voltage) | DAC_CHANNEL_B, DISOPAMP_POSITION_CELL0 + CellCounter, 1, false);
		}

		if(DISOPAMP_TOTAL_CELL - CellCounter - 1)
			LL_WriteDACx(DAC_CHANNEL_B, DISOPAMP_POSITION_CELL1 + CellCounter, DISOPAMP_TOTAL_CELL - CellCounter - 1, false);

	}
	else
		LL_WriteDACx(DAC_CHANNEL_B, DISOPAMP_POSITION_CELL0, DISOPAMP_TOTAL_CELL, false);

	LL_ToggleLDAC();
}
//-----------------------------

Int16U DISOPAMP_GetCurrentRange()
{
	return CurrentCutOffRange;
}
//-----------------------------




