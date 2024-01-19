/*
 * Stop_Watch.c
 *
 * Created: 1/19/2024 3:44:07 AM
 *  Author: alima
 */ 

#include "Stop_Watch.h"

uint8 Button1_Val=1 , Button2_Val=1 , Button3_Val=1 ,  Button4_Val=1;
uint8 i=0 , j=0;
uint8 Arr[String_Size]="Time's Up";


void App (void)
{
	 Button1_Val=Button_GetValue(Button_1);
	 Button2_Val=Button_GetValue(Button_2);
	 Button3_Val=Button_GetValue(Button_3);
	 Button4_Val=Button_GetValue(Button_4);
	 
	 if (Button1_Val==0) //Increase Minutes Button
	 {
		 Button1_Functionality();
	 }
	 else if (Button2_Val==0) //Increase Seconds Button
	 {
		 Button2_Functionality();
	 }
	 else if (Button3_Val==0) //Timer ON Button
	 {
		 Button3_Functionality();
	 }
	 else if(Button4_Val==0)  //Reset Button
	 {
		 Button4_Functionality();
	 }
}
void Drivers_Init (void)
{
	PORT_Init();
	LCD_Init();
}

void Project_Init (void)
{
	Drivers_Init();
	LCD_GoTo(0,0);
	LCD_WriteString("MIN : SEC");
	LCD_GoTo(1,0);
	LCD_WriteInteger(i);
	LCD_GoTo(1,4);
	LCD_WriteChar(':');
	LCD_GoTo(1,6);
	LCD_WriteInteger(j);
}

void Button1_Functionality (void)
{
	LCD_Clear();
	i++;
	LCD_GoTo(0,0);
	LCD_WriteString("MIN : SEC");
	LCD_GoTo(1,0);
	LCD_WriteInteger(i);
	LCD_GoTo(1,4);
	LCD_WriteChar(':');
	LCD_GoTo(1,6);
	LCD_WriteInteger(j);
}

void Button2_Functionality (void)
{
	if (j<59) //Making Sure Seconds Don't exceed 59
	{
		LCD_Clear();
		j++;
		LCD_GoTo(0,0);
		LCD_WriteString("MIN : SEC");
		LCD_GoTo(1,0);
		LCD_WriteInteger(i);
		LCD_GoTo(1,4);
		LCD_WriteChar(':');
		LCD_GoTo(1,6);
		LCD_WriteInteger(j);
	}
}

void Button3_Functionality (void)
{
	_delay_ms(1000);
	Seconds_CountDown();
	while(i!=0)
	{
		if(j==0)
		{
			LCD_Clear();
			i--;
			j=59;
			LCD_GoTo(0,0);
			LCD_WriteString("MIN : SEC");
			LCD_GoTo(1,0);
			LCD_WriteInteger(i);
			LCD_GoTo(1,4);
			LCD_WriteChar(':');
			LCD_GoTo(1,6);
			LCD_WriteInteger(j);
			_delay_ms(1000);
			Seconds_CountDown();
		}
	}
	if (i==0 && j==0) //When Time is 0:0 Turn On Buzzer
	{
		
		Time_Finished();
		LCD_Clear();
		i=0;
		j=0;
		LCD_GoTo(0,0);
		LCD_WriteString("MIN : SEC");
		LCD_GoTo(1,0);
		LCD_WriteInteger(i);
		LCD_GoTo(1,4);
		LCD_WriteChar(':');
		LCD_GoTo(1,6);
		LCD_WriteInteger(j);
	}
}

void Button4_Functionality (void)
{
	LCD_Clear();
	i=0;
	j=0;
	LCD_GoTo(0,0);
	LCD_WriteString("MIN : SEC");
	LCD_GoTo(1,0);
	LCD_WriteInteger(i);
	LCD_GoTo(1,4);
	LCD_WriteChar(':');
	LCD_GoTo(1,6);
	LCD_WriteInteger(j);
	Buzzer_OFF();
}

void Seconds_CountDown (void)
{
	while(j!=0)
	{
		LCD_Clear();
		j--;
		LCD_GoTo(0,0);
		LCD_WriteString("MIN : SEC");
		LCD_GoTo(1,0);
		LCD_WriteInteger(i);
		LCD_GoTo(1,4);
		LCD_WriteChar(':');
		LCD_GoTo(1,6);
		LCD_WriteInteger(j);
		_delay_ms(1000);      // Decrease J Every 1 sec
	}
}

void Time_Finished (void)
{
	LCD_Clear();
	LCD_WriteString(Arr);
	Buzzer_ON();
	LED_ON();
	_delay_ms(2000);
	Buzzer_OFF();
	LED_OFF();
	_delay_ms(1000);
	Buzzer_ON();
	LED_ON();
	_delay_ms(2000);
	Buzzer_OFF();
	LED_OFF();
}