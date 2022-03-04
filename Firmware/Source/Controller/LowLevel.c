// Header
#include "LowLevel.h"
// Include
#include "Board.h"
#include "Delay.h"
#include "Global.h"

// Arrays
void (*LL_CsSyncControl[DISOPAMP_TOTAL_CELL])(bool State) =
{
	&LL_SetStateCS_SYNC1,
	&LL_SetStateCS_SYNC2,
	&LL_SetStateCS_SYNC3,
	&LL_SetStateCS_SYNC4,
	&LL_SetStateCS_SYNC5,
	&LL_SetStateCS_SYNC6,
	&LL_SetStateCS_SYNC7,
	&LL_SetStateCS_SYNC8
};

// Functions
//
void LL_ToggleBoardLED()
{
	GPIO_Toggle(GPIO_INT_LED);
}
//-----------------------------

void LL_SetVoltageRange(bool State)
{
	GPIO_SetState(GPIO_VOLTAGE_RANGE, !State);
}
//-----------------------------

void LL_SetStateExtMsrLed(bool State)
{
	GPIO_SetState(GPIO_EXT_LED2, !State);
}
//-----------------------------

void LL_SetStateLineSync1(bool State)
{
	GPIO_SetState(GPIO_SYNC1_OUT, State);
}
//-----------------------------

void LL_SetStateLineSync2(bool State)
{
	GPIO_SetState(GPIO_SYNC2_OUT, State);
}
//-----------------------------

bool LL_GetStateLineSync1()
{
	return GPIO_GetState(GPIO_SYNC1_IN);
}
//-----------------------------

bool LL_GetStateLineSync2()
{
	return GPIO_GetState(GPIO_SYNC2_IN);
}
//-----------------------------

void LL_PowerSupplyEnable(bool State)
{
	GPIO_SetState(GPIO_PS_EN, State);
}
//-----------------------------

void LL_SetCurrentRange0()
{
	GPIO_SetState(GPIO_R0_M, false);
	GPIO_SetState(GPIO_R1_M, false);
	GPIO_SetState(GPIO_R2_M, false);
}
//-----------------------------

void LL_SetCurrentRange1()
{
	GPIO_SetState(GPIO_R0_M, true);
	GPIO_SetState(GPIO_R1_M, false);
	GPIO_SetState(GPIO_R2_M, false);
}
//-----------------------------

void LL_SetCurrentRange2()
{
	GPIO_SetState(GPIO_R0_M, false);
	GPIO_SetState(GPIO_R1_M, true);
	GPIO_SetState(GPIO_R2_M, false);
}
//-----------------------------

void LL_SetCurrentRange3()
{
	GPIO_SetState(GPIO_R0_M, false);
	GPIO_SetState(GPIO_R1_M, false);
	GPIO_SetState(GPIO_R2_M, true);
}
//-----------------------------

void LL_WriteDACx(Int16U Data, Int16U CellStartNumber, Int16U CellTotal, bool ToggleLDAC)
{
	// Установка линий CS_SYNC в 0
	for(int i = CellStartNumber; i < (CellStartNumber + CellTotal); i++)
		LL_CsSyncControl[i](false);

	SPI_WriteByte(SPI1, Data);

	// Установка линий CS_SYNC в 1
	for(int i = CellStartNumber; i < (CellStartNumber + CellTotal); i++)
		LL_CsSyncControl[i](true);

	if(ToggleLDAC)
		LL_ToggleLDAC();
}
//---------------------

void LL_ToggleLDAC()
{
	GPIO_SetState(GPIO_LDAC, false);
	DELAY_US(1);
	GPIO_SetState(GPIO_LDAC, true);
}
//---------------------

void LL_SetStateCS_SYNC1(bool State)
{
	GPIO_SetState(GPIO_CS_SYNC1, State);
}
//---------------------

void LL_SetStateCS_SYNC2(bool State)
{
	GPIO_SetState(GPIO_CS_SYNC2, State);
}
//---------------------

void LL_SetStateCS_SYNC3(bool State)
{
	GPIO_SetState(GPIO_CS_SYNC3, State);
}
//---------------------

void LL_SetStateCS_SYNC4(bool State)
{
	GPIO_SetState(GPIO_CS_SYNC4, State);
}
//---------------------

void LL_SetStateCS_SYNC5(bool State)
{
	GPIO_SetState(GPIO_CS_SYNC5, State);
}
//---------------------

void LL_SetStateCS_SYNC6(bool State)
{
	GPIO_SetState(GPIO_CS_SYNC6, State);
}
//---------------------

void LL_SetStateCS_SYNC7(bool State)
{
	GPIO_SetState(GPIO_CS_SYNC7, State);
}
//---------------------

void LL_SetStateCS_SYNC8(bool State)
{
	GPIO_SetState(GPIO_CS_SYNC8, State);
}
//---------------------

