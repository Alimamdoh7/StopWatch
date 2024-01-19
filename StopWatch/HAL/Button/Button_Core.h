/*
 * Button_Core.h
 *
 * Created: 9/15/2023 10:04:56 AM
 *  Author: alima
 */ 


#ifndef BUTTON_CORE_H_
#define BUTTON_CORE_H_

#include "BIT_MATH.h"
#include "MCU.h"

#define F_CPU 16000000U
#include <util/delay.h>

#define Button_1 0
#define Button_2 1
#define Button_3 2
#define Button_4 3

void Button_Init(void);
uint8 Button_GetValue(uint8 Button);

#endif /* BUTTON_CORE_H_ */