// Header
#include "DebugActions.h"

// Include
//
#include "LowLevel.h"
#include "Board.h"
#include "Delay.h"
#include "Controller.h"
#include "DataTable.h"
#include "DiscreteOpAmp.h"

// Definitions
//
#define DBG_CURRENT_RANGE_0		0
#define DBG_CURRENT_RANGE_1		1
#define DBG_CURRENT_RANGE_2		2
#define DBG_CURRENT_RANGE_3		3

// Functions
//
void DBGACT_GenerateImpulseToLineSync()
{
	LL_SetStateLineSync(true);
	CONTROL_DelayMs(100);
	LL_SetStateLineSync(false);
}
//-----------------------------

void DBGACT_SetCurrentRange(uint16_t Range)
{
	switch(Range)
	{
		case DBG_CURRENT_RANGE_0:
			LL_SetCurrentRange0();
			break;

		case DBG_CURRENT_RANGE_1:
			LL_SetCurrentRange1();
			break;

		case DBG_CURRENT_RANGE_2:
			LL_SetCurrentRange2();
			break;

		case DBG_CURRENT_RANGE_3:
			LL_SetCurrentRange3();
			break;
	}
}
//-----------------------------

void DBGACT_SetCurrentCutoff(uint16_t Data)
{
	LL_WriteDACx(Data & ~DAC_CHANNEL_B);
}
//-----------------------------

void DBGACT_OpAmpSetVoltage(uint16_t Data)
{
	LL_WriteDACx(Data | DAC_CHANNEL_B);
}
//-----------------------------
