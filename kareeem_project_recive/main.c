
#include "bit_math.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "UART.h"
#include "LCD_interface.h"
#include <util/delay.h>
u8 recieve ;

void main(void)
{
	DIO_VoidSetPin_Direction(PORT_D,PIN0,PINLOW);
	DIO_VoidSetPin_Direction(PORT_D,PIN1,PINHIGH);
	UART_Init();
	 LCD_VOIDINIT();

	while(1)
	{

		recieve=UART_GetChar();
		if(recieve == '1')
		{

			LCD_VOIDSEND_STRING("  GAS DETECTED");
		 _delay_ms(100);
		 LCD_VOIDSEND_COMMAND(1);
		}
		else if(recieve == '0')
		{
			LCD_VOIDSEND_STRING(" GAS NOT DETECTED");
			 _delay_ms(100);
			 LCD_VOIDSEND_COMMAND(1);
		}
	}
}
