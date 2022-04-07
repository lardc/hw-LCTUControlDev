// Includes
#include "DiscreteOpAmp.h"
#include "LowLevel.h"
#include "ConvertUtils.h"
#include "Global.h"
#include "DataTable.h"

// Functions
//

void DISOPAMP_SetVoltage(float Voltage)
{
	LL_WriteDACx(CU_VtoDAC(DISOPAMP_CELL_VOLATGE_MAX) | DAC_CHANNEL_B);
}
//-----------------------------




