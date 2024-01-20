/*
 * Button_Core.c
 *
 * Created: 9/15/2023 10:04:44 AM
 *  Author: AliMamdoh
 */ 

/*Matrix mode Buttons PD2,PD3,PD4,PD5*/

#include "Button_Core.h"

void Button_Init(void)
{
	CLR_BIT(DDRD,2); //Input
	CLR_BIT(DDRD,3); //Input
	CLR_BIT(DDRD,4); //Input
	CLR_BIT(DDRD,5); //Input
}
uint8 Button_GetValue(uint8 Button)
{
	//uint8 Temp=0;
	uint8 Button_Val=1;
	switch (Button)
	{
		case Button_1:
		Button_Val=GET_BIT(PIND,2);
	   /* while(Temp==0)
	    {
		Temp= GET_BIT(PIND,2);
	    }*/
	     _delay_ms(30);
		 break;
		 
		 case Button_2:
		 Button_Val=GET_BIT(PIND,3);
		  /* while(Temp==0)
	    {
		Temp= GET_BIT(PIND,2);
	    }*/
		 _delay_ms(30);
		 break;
		 
		 case Button_3:
		 Button_Val=GET_BIT(PIND,4);
		   /* while(Temp==0)
	    {
		Temp= GET_BIT(PIND,2);
	    }*/
		 _delay_ms(30);
		 break;
		 
		 case Button_4:
		 Button_Val=GET_BIT(PIND,5);
		  /* while(Temp==0)
	    {
		Temp= GET_BIT(PIND,2);
	    }*/
		 _delay_ms(30);
		 break;
		 default:
		 break;
	}
	
	return Button_Val;
}