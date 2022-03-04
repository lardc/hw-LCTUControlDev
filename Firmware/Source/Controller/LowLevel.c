// Header
#include "LowLevel.h"
// Include
#include "Board.h"
#include "Delay.h"
#include "Global.h"

// Functions
//
void LL_ToggleBoardLED()
{
	GPIO_Toggle(GPIO_LED);
}
//-----------------------------

void LL_SetStateLineSync(bool State)
{
	GPIO_SetState(GPIO_SYNC, State);
}
//-----------------------------

void LL_SetCurrentRange0()
{
	GPIO_SetState(GPIO_OPAMP_R0, false);
	GPIO_SetState(GPIO_OPAMP_R1, false);
	GPIO_SetState(GPIO_OPAMP_R2, false);
}
//-----------------------------

void LL_SetCurrentRange1()
{
	GPIO_SetState(GPIO_OPAMP_R0, true);
	GPIO_SetState(GPIO_OPAMP_R1, false);
	GPIO_SetState(GPIO_OPAMP_R2, false);
}
//-----------------------------

void LL_SetCurrentRange2()
{
	GPIO_SetState(GPIO_OPAMP_R0, false);
	GPIO_SetState(GPIO_OPAMP_R1, true);
	GPIO_SetState(GPIO_OPAMP_R2, false);
}
//-----------------------------

void LL_SetCurrentRange3()
{
	GPIO_SetState(GPIO_OPAMP_R0, false);
	GPIO_SetState(GPIO_OPAMP_R1, false);
	GPIO_SetState(GPIO_OPAMP_R2, true);
}
//-----------------------------

void LL_WriteDACx(Int16U Data)
{
	GPIO_SetState(GPIO_OPAMP_SYNC, false);
	SPI_WriteByte(SPI1, Data);
	GPIO_SetState(GPIO_OPAMP_SYNC, true);

	LL_ToggleLDAC();
}
//---------------------

void LL_ToggleLDAC()
{
	GPIO_SetState(GPIO_OPAMP_LDAC, false);
	DELAY_US(1);
	GPIO_SetState(GPIO_OPAMP_LDAC, true);
}
//---------------------
