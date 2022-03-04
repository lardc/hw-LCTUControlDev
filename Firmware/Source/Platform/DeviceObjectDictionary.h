#ifndef __DEV_OBJ_DIC_H
#define __DEV_OBJ_DIC_H

// Команды
#define ACT_ENABLE_POWER				1	// Включение блока
#define ACT_DISABLE_POWER				2	// Выключение блока
#define ACT_CLR_FAULT					3	// Очистка всех fault
#define ACT_CLR_WARNING					4	// Очистка всех warning

#define ACT_DBG_PULSE_SYNC1				50	// Одиночный импусль в линию SYNC_1
#define ACT_DBG_PULSE_SYNC2				51	// Одиночный импусль в линию SYNC_2
#define ACT_DBG_IS_STATE_SYNC_1			52	// Состояние линии SYNC_1
#define ACT_DBG_IS_STATE_SYNC_2			53	// Состояние линии SYNC_2
#define ACT_DBG_PULSE_EXT_LEDS			54	// Однократное зажигание внешних светодиодов
#define ACT_DBG_SET_CURRENT_RANGE		55	// Установка диапазона по току (0, 1, 2)
#define ACT_DBG_POWER_SUPPLY_EN			56	// Проверка активности источников питания на 500В
#define ACT_DBG_SET_CURRENT_CUTOFF		57	// Установка отсечки по току на всех ячейках DiscreteOpAmp
#define ACT_DBG_SET_VOLTAGE_CELL		58	// Установка напряжения на заданной ячейке

#define ACT_START_PROCESS				100	// Старт измерения
#define ACT_STOP_PROCESS				101	// Стоп измерения
#define ACT_SECOND_START_PROCESS		102	// Команда запуска второго этапа формирования импульса

#define ACT_SAVE_TO_ROM					200	// Сохранение пользовательских данных во FLASH процессора
#define ACT_RESTORE_FROM_ROM			201	// Восстановление данных из FLASH
#define ACT_RESET_TO_DEFAULT			202	// Сброс DataTable в состояние по умолчанию

#define ACT_BOOT_LOADER_REQUEST			320	// Перезапуск процессора с целью перепрограммирования
// -----------------------------

// Регистры
// Сохраняемые регистры
#define REG_PS_ACTIVITY_TIME			0	// Время работы блоков питания для заряда конденсаторов (мс)
#define REG_PULSE_WIDTH					1	// Длительность импульса (мс)
#define REG_PULSE_FRONT_WIDTH			2	// Длительность фронта импульса в (мс)
#define REG_REGULATOR_ALOWED_ERR		3	// Допустимая ошибка регулирования (% * 10)
#define REG_START_DELAY					4	// Задержка начала измерения после выключения заряда конденсаторов
#define REG_FOLLOWING_ERR_CNT_NUM		5	// Значение счетчика FollowingError, при котором выставляется ошибка DF_FOLLOWING_ERR
#define REG_SCOPE_STEP					6	// Сохранение измеренных данных с заданным шагом
#define REG_AFTER_PULSE_PAUSE			7	// Время выдержки перед началом следующего измерения (мс)
#define REG_REGULATOR_QI_MAX			8	// Максимально допустимое значение Qi регулятора
#define REG_MEASURE_ALLOWED_ERR			9	// Допустимая ошибка при измерении (% * 10)
#define REG_MUTE_FOLLOWING_ERR			10	// Выключить слежение за ошибкой DF_FOLOWING_ERROR
#define REG_MUTE_EXCESS_CURRENT			11	// Выключение слежение за отсечкой по току
#define REG_POST_CHARGE_WAIT_TIME		12	// Время ожидания импульса запуска после окончания заряда (мс)
// 13 - 19
#define REG_DAC_V_CELL_K				20	// Коэффициент грубой подстройки К
#define REG_DAC_V_CELL_B				21	// Смещение грубой подстройки B
// 21 - 41
#define REG_ADC_V_RANGE0_P2				41	// Диапазон 0 - Коэффициент тонкой подстройки Р2 х1е6
#define REG_ADC_V_RANGE0_P1				42	// Диапазон 0 - Коэффициент тонкой подстройки Р1 х1000
#define REG_ADC_V_RANGE0_P0				43	// Диапазон 0 - Смещение тонкой подстройки Р0
#define REG_ADC_V_RANGE0_K				44	// Диапазон 0 - Коэффициент грубой подстройки K
#define REG_ADC_V_RANGE0_B				45	// Диапазон 0 - Смещение грубой подстройки B
//
#define REG_ADC_V_RANGE1_P2				46	// Диапазон 1 - Коэффициент тонкой подстройки Р2 х1е6
#define REG_ADC_V_RANGE1_P1				47	// Диапазон 1 - Коэффициент тонкой подстройки Р1 х1000
#define REG_ADC_V_RANGE1_P0				48	// Диапазон 1 - Смещение тонкой подстройки Р0
#define REG_ADC_V_RANGE1_K				49	// Диапазон 1 - Коэффициент грубой подстройки K
#define REG_ADC_V_RANGE1_B				50	// Диапазон 1 - Смещение грубой подстройки B
//
#define REG_ADC_I_RANGE0_P2				51	// Диапазон 0 - Коэффициент тонкой подстройки Р2 х1е6
#define REG_ADC_I_RANGE0_P1				52	// Диапазон 0 - Коэффициент тонкой подстройки Р1 x1000
#define REG_ADC_I_RANGE0_P0				53	// Диапазон 0 - Смещение тонкой подстройки Р0
#define REG_ADC_I_RANGE0_N				54	// Диапазон 0 - Числитель коэффициента грубой подстройки
#define REG_ADC_I_RANGE0_D				55	// Диапазон 0 - Знаменатель коэффициента грубой подстройки
#define REG_ADC_I_RANGE0_B				56	// Диапазон 0 - Смещение тонкой подстройки B
//
#define REG_ADC_I_RANGE1_P2				57	// Диапазон 1 - Коэффициент тонкой подстройки Р2 х1е6
#define REG_ADC_I_RANGE1_P1				58	// Диапазон 1 - Коэффициент тонкой подстройки Р1 x1000
#define REG_ADC_I_RANGE1_P0				59	// Диапазон 1 - Смещение тонкой подстройки Р0
#define REG_ADC_I_RANGE1_N				60	// Диапазон 1 - Числитель коэффициента грубой подстройки
#define REG_ADC_I_RANGE1_D				61	// Диапазон 1 - Знаменатель коэффициента грубой подстройки
#define REG_ADC_I_RANGE1_B				62	// Диапазон 1 - Смещение тонкой подстройки B
//
#define REG_ADC_I_RANGE2_P2				63	// Диапазон 2 - Коэффициент тонкой подстройки Р2 х1е6
#define REG_ADC_I_RANGE2_P1				64	// Диапазон 2 - Коэффициент тонкой подстройки Р1 x1000
#define REG_ADC_I_RANGE2_P0				65	// Диапазон 2 - Смещение тонкой подстройки Р0
#define REG_ADC_I_RANGE2_N				66	// Диапазон 2 - Числитель коэффициента грубой подстройки
#define REG_ADC_I_RANGE2_D				67	// Диапазон 2 - Знаменатель коэффициента грубой подстройки
#define REG_ADC_I_RANGE2_B				68	// Диапазон 2 - Смещение тонкой подстройки B
//
#define REG_ADC_I_RANGE3_P2				69	// Диапазон 3 - Коэффициент тонкой подстройки Р2 х1е6
#define REG_ADC_I_RANGE3_P1				70	// Диапазон 3 - Коэффициент тонкой подстройки Р1 x1000
#define REG_ADC_I_RANGE3_P0				71	// Диапазон 3 - Смещение тонкой подстройки Р0
#define REG_ADC_I_RANGE3_N				72	// Диапазон 3 - Числитель коэффициента грубой подстройки
#define REG_ADC_I_RANGE3_D				73	// Диапазон 3 - Знаменатель коэффициента грубой подстройки
#define REG_ADC_I_RANGE3_B				74	// Диапазон 3 - Смещение тонкой подстройки B
//
#define REG_REGULATOR_Kp				80	// Пропорциональный коэффициент регулятора
#define REG_REGULATOR_Ki				81	// Интегральный коэффициент регулятора

#define REG_VOLTAGE_SETPOINT			128	// Уставка по напряжению, В х 10
#define REG_CURRENT_CUTOFF_L			129	// Ограничение по току (старшая часть), мкА х 10
#define REG_CURRENT_CUTOFF_H			130	// Ограничение по току (младшая часть), мкА х 10

// Несохраняемы регистры чтения-записи
#define REG_DBG							150	// Регистр режима Отладки 1
#define REG_DBG_CELL_NUM				151	// Регистр режима Отладки 2

// Регистры только чтение
#define REG_DEV_STATE					192	// Регистр состояния
#define REG_FAULT_REASON				193	// Регистр Fault
#define REG_DISABLE_REASON				194	// Регистр Disable
#define REG_WARNING						195	// Регистр Warning
#define REG_PROBLEM						196	// Регистр Problem
#define REG_OP_RESULT					197	// Регистр результата операции
#define REG_SUB_STATE					198	// Регистр вспомогательного состояния

#define REG_RESULT_VOLTAGE				200	// Достигнутое напряжение во время теста (В * 10)
#define REG_RESULT_CURRENT_L			201	// Измеренный ток (старшая часть), при заданном напряжении (мкА * 10)
#define REG_RESULT_CURRENT_H			202	// Измеренный ток (младшая часть), при заданном напряжении (мкА * 10)
//
#define REG_MEASURE_ERR_FLAG			205	// Флаг, выставляемый при достижении ошибки регулирования заданного значения
#define REG_TARGET_VOLTAGE_FLAG			206	// Флаг выхода напряжения на уставку
// -----------------------------
#define REG_FWINFO_SLAVE_NID			256	// Device CAN slave node ID
#define REG_FWINFO_MASTER_NID			257	// Device CAN master node ID (if presented)
// 258 - 259
#define REG_FWINFO_STR_LEN				260	// Length of the information string record
#define REG_FWINFO_STR_BEGIN			261	// Begining of the information string record


// Operation results
#define OPRESULT_NONE					0	// No information or not finished
#define OPRESULT_OK						1	// Operation was successful
#define OPRESULT_FAIL					2	// Operation failed

//  Fault and disable codes
#define DF_NONE							0

// Problem
#define PROBLEM_NONE					0
#define PROBLEM_FOLOWING_ERROR			1

//  Warning
#define WARNING_NONE					0
#define WARNING_CURRENT_CUTOFF			1

//  User Errors
#define ERR_NONE						0
#define ERR_CONFIGURATION_LOCKED		1	//  Устройство защищено от записи
#define ERR_OPERATION_BLOCKED			2	//  Операция не может быть выполнена в текущем состоянии устройства
#define ERR_DEVICE_NOT_READY			3	//  Устройство не готово для смены состояния
#define ERR_WRONG_PWD					4	//  Неправильный ключ

// Endpoints
#define EP_VOLTAGE						1
#define EP_CURRENT						2
#define EP_REGULATOR_ERR				3

#endif //  __DEV_OBJ_DIC_H
