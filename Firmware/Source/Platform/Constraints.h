﻿#ifndef __CONSTRAINTS_H
#define __CONSTRAINTS_H

// Include
#include "stdinc.h"
#include "DataTable.h"
#include "Global.h"

//Definitions
//
#define PULSE_WIDTH_MIN				1			// (мс)
#define PULSE_WIDTH_MAX				200			// (мс)
#define PULSE_WIDTH_DEF				100			// (мс)
//
#define FRONT_WIDTH_MIN				1			// (мс)
#define FRONT_WIDTH_MAX				200			// (мс)
#define FRONT_WIDTH_DEF				30			// (мс)
//
#define ALOWED_ERROR_MIN			0			// (% * 10)
#define ALOWED_ERROR_MAX			1000		// (% * 10)
#define ALOWED_ERROR_DEF			30			// (% * 10)
//
#define FOLLOWING_ERR_CNT_MIN		0
#define FOLLOWING_ERR_CNT_MAX		1000
#define FOLLOWING_ERR_CNT_DEF		200
//
#define AFTER_PULSE_PAUSE_MIN		1000		// (мс)
#define AFTER_PULSE_PAUSE_MAX		5000		// (мс)
#define AFTER_PULSE_PAUSE_DEF		2000		// (мс)
//
#define COEF_K_MIN					1
#define COEF_K_MAX					INT16U_MAX
#define COEF_K_DEF					1000
//
#define OFFSET_MIN					0
#define OFFSET_MAX					INT16U_MAX
#define OFFSET_DEF					0
//
#define COEF_P2_MIN					0
#define COEF_P2_MAX					INT16U_MAX
#define COEF_P2_DEF					0
//
#define COEF_P1_MIN					0
#define COEF_P1_MAX					INT16U_MAX
#define COEF_P1_DEF					1000
//
#define COEF_P0_MIN					0
#define COEF_P0_MAX					INT16U_MAX
#define COEF_P0_DEF					0
//
#define REGULATOR_KP_MIN			0
#define REGULATOR_KP_MAX			INT16U_MAX
#define REGULATOR_KP_DEF			1000
//
#define REGULATOR_KI_MIN			0
#define REGULATOR_KI_MAX			INT16U_MAX
#define REGULATOR_KI_DEF			0
//
#define NO		0
#define YES		1
//
#define PS_ACTIVITY_TIME_MIN		100			// мс
#define PS_ACTIVITY_TIME_MAX		10000		// мс
#define PS_ACTIVITY_TIME_DEF		1500		// мс
//
#define VOLTAGE_SETPOINT_MIN		100			// В
#define VOLTAGE_SETPOINT_MAX		1500		// В

// Types
typedef struct __TableItemConstraint
{
	Int16U Min;
	Int16U Max;
	Int16U Default;
} TableItemConstraint;

// Variables
extern const TableItemConstraint NVConstraint[DATA_TABLE_NV_SIZE];
extern const TableItemConstraint VConstraint[DATA_TABLE_WP_START - DATA_TABLE_WR_START];

#endif // __CONSTRAINTS_H
