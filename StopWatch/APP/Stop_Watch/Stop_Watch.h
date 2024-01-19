/*
 * Stop_Watch.h
 *
 * Created: 1/19/2024 3:44:19 AM
 *  Author: alima
 */ 


#ifndef STOP_WATCH_H_
#define STOP_WATCH_H_

#include "PORT_Core.h"
#include "LCD_Core.h"
#include "Button_Core.h"
#include "Buzzer_Core.h"

#define String_Size 10U

void App (void);
void Drivers_Init (void);
void Project_Init (void);
void Seconds_CountDown (void);
void Time_Finished (void);
void Button1_Functionality (void);
void Button2_Functionality (void);
void Button3_Functionality (void);
void Button4_Functionality (void);



#endif /* STOP_WATCH_H_ */