
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "UART.h"



void main(void)
{
	DIO_SetPinDirection(PORTD,PIN0,INPUT);
	DIO_SetPinDirection(PORTD,PIN1,OUTPUT);
    DIO_SetPinDirection(PORTA,PIN0,INPUT);
    DIO_SetPinValue(PORTA,PIN0,HIGH);
 u8 recive;

	UART_Init();
	while(1)
	{
		recive=DIO_GetPinValue(PORTA,PIN0);
		if(recive==1){
		UART_SendChar('1');
		}
		else{

			UART_SendChar('0');
		}
	}
}
