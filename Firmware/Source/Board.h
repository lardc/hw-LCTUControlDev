#ifndef __BOARD_H
#define __BOARD_H

#include "stm32f30x.h"

#include "ZwRCC.h"
#include "ZwGPIO.h"
#include "ZwNCAN.h"
#include "ZwTIM.h"
#include "ZwDAC.h"
#include "ZwDMA.h"
#include "ZwADC.h"
#include "ZwEXTI.h"
#include "ZwSCI.h"
#include "ZwIWDG.h"
#include "ZwNFLASH.h"
#include "ZwSPI.h"

// Определения для выходных портов
GPIO_PortPinSettingMacro GPIO_LDAC				= {GPIOA, Pin_4};
GPIO_PortPinSettingMacro GPIO_VOLTAGE_RANGE		= {GPIOA, Pin_8};
GPIO_PortPinSettingMacro GPIO_EXT_LED2			= {GPIOB, Pin_15};
GPIO_PortPinSettingMacro GPIO_R0_M				= {GPIOB, Pin_2};
GPIO_PortPinSettingMacro GPIO_R1_M				= {GPIOB, Pin_0};
GPIO_PortPinSettingMacro GPIO_R2_M				= {GPIOB, Pin_1};
GPIO_PortPinSettingMacro GPIO_SYNC1_OUT			= {GPIOA, Pin_15};
GPIO_PortPinSettingMacro GPIO_SYNC2_OUT			= {GPIOB, Pin_3};
GPIO_PortPinSettingMacro GPIO_INT_LED			= {GPIOB, Pin_6};
GPIO_PortPinSettingMacro GPIO_CS_SYNC1			= {GPIOB, Pin_14};
GPIO_PortPinSettingMacro GPIO_CS_SYNC2			= {GPIOB, Pin_13};
GPIO_PortPinSettingMacro GPIO_CS_SYNC3			= {GPIOB, Pin_12};
GPIO_PortPinSettingMacro GPIO_CS_SYNC4			= {GPIOB, Pin_11};
GPIO_PortPinSettingMacro GPIO_CS_SYNC5			= {GPIOB, Pin_10};
GPIO_PortPinSettingMacro GPIO_CS_SYNC6			= {GPIOA, Pin_1};
GPIO_PortPinSettingMacro GPIO_CS_SYNC7			= {GPIOA, Pin_2};
GPIO_PortPinSettingMacro GPIO_CS_SYNC8			= {GPIOA, Pin_3};
GPIO_PortPinSettingMacro GPIO_PS_EN				= {GPIOB, Pin_7};

// Определения для входных портов
GPIO_PortPinSettingMacro GPIO_SYNC1_IN			= {GPIOB, Pin_4};
GPIO_PortPinSettingMacro GPIO_SYNC2_IN			= {GPIOB, Pin_5};

// Определения для портов альтернативных функций
GPIO_PortPinSettingMacro GPIO_ALT_CAN_RX		= {GPIOA, Pin_11};
GPIO_PortPinSettingMacro GPIO_ALT_CAN_TX		= {GPIOA, Pin_12};
GPIO_PortPinSettingMacro GPIO_ALT_UART1_TX		= {GPIOA, Pin_9};
GPIO_PortPinSettingMacro GPIO_ALT_UART1_RX		= {GPIOA, Pin_10};
GPIO_PortPinSettingMacro GPIO_ALT_SPI1_CLK		= {GPIOA, Pin_5};
GPIO_PortPinSettingMacro GPIO_ALT_SPI1_DAT		= {GPIOA, Pin_7};

#endif // __BOARD_H
