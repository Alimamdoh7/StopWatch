/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LCD_Core.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LCD_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_Init(void)
{
	#if (LCD_OPERATION_MODE == 4)
	/*LCD 4 BIT MODE COMMANDS*/
	LCD_WriteCommand(0X33);
	LCD_WriteCommand(0X32);
	LCD_WriteCommand(0X28);
	/************************/
	/*COMMANDS FOR LCD*/
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0X01);
	LCD_WriteCommand(0X06);
	LCD_WriteCommand(0X02);
	/***********************/
	
	
	#elif  (LCD_OPERATION_MODE == 8)
	
	#endif
	_delay_ms(5);
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WriteCommand(uint8 cmd)
{
	DIO_WriteChannel(LCD_RS_PIN , PIN_LOW);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	DIO_WriteChannel(LCD_D4_PIN , GET_BIT(cmd , 4));
	DIO_WriteChannel(LCD_D5_PIN , GET_BIT(cmd , 5));
	DIO_WriteChannel(LCD_D6_PIN , GET_BIT(cmd , 6));
	DIO_WriteChannel(LCD_D7_PIN , GET_BIT(cmd , 7));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	DIO_WriteChannel(LCD_D4_PIN , GET_BIT(cmd , 0));
	DIO_WriteChannel(LCD_D5_PIN , GET_BIT(cmd , 1));
	DIO_WriteChannel(LCD_D6_PIN , GET_BIT(cmd , 2));
	DIO_WriteChannel(LCD_D7_PIN , GET_BIT(cmd , 3));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	_delay_ms(5);
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WriteChar(uint8 Data)
{
	DIO_WriteChannel(LCD_RS_PIN , PIN_HIGH);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	DIO_WriteChannel(LCD_D4_PIN , GET_BIT(Data , 4));
	DIO_WriteChannel(LCD_D5_PIN , GET_BIT(Data , 5));
	DIO_WriteChannel(LCD_D6_PIN , GET_BIT(Data , 6));
	DIO_WriteChannel(LCD_D7_PIN , GET_BIT(Data , 7));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	DIO_WriteChannel(LCD_D4_PIN , GET_BIT(Data , 0));
	DIO_WriteChannel(LCD_D5_PIN , GET_BIT(Data , 1));
	DIO_WriteChannel(LCD_D6_PIN , GET_BIT(Data , 2));
	DIO_WriteChannel(LCD_D7_PIN , GET_BIT(Data , 3));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	_delay_ms(5);
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WriteString(uint8* str)
{
	uint8 i=0;
	while(str[i]!='\0')
	{
		LCD_WriteChar(str[i]);
		i++;
	}
	_delay_ms(5);
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WriteInteger(sint32 num)
{
	 sint32 temp = 1;
	 if(num == 0)
	 {
		 LCD_WriteChar('0');
	 }

	 else if(num < 0)
	 {
		 LCD_WriteChar('-');
		 num *= -1;
	 }
 	
	 while(num > 0)
	 {
	 	 temp = ((temp*10) + (num%10));
	 	 num /= 10;
	 }
	 
	 while(temp > 1 )
	 {
	 	 LCD_WriteChar(((temp%10)+48));
	 	 temp /= 10;
	 }
	
	 _delay_ms(5);
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_GoTo(uint8 Row, uint8 Column)
{
	uint8 LCD_Loc[2]={0X80 , 0XC0};
	LCD_WriteCommand(LCD_Loc[Row] + Column);
	_delay_ms(5);
}


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_Clear(void)
{
	//command to clear LCD
	LCD_WriteCommand(0X01);
	_delay_ms(5);
}




/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
