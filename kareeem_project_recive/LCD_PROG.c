
#include"STD_TYPES.h"
#include <util/delay.h>
#include"DIO_interface.h"
#include"LCD_configur.h"
#include"LCD_interface.h"


void LCD_VOIDINIT(void){
	DIO_VoidSetport_Direction(LCD_ctrl_port,255);
	DIO_VoidSetport_Direction(LCD_data_port,255);
	_delay_ms(50);
   LCD_VOIDSEND_COMMAND(0b00111000);
	_delay_ms(1);
	LCD_VOIDSEND_COMMAND(0b00001100);

	_delay_ms(1);
	LCD_VOIDSEND_COMMAND(1);
	_delay_ms(1);
	LCD_VOIDSEND_COMMAND(0b00000110);
		_delay_ms(1);


}
void LCD_VOIDSEND_COMMAND(u8 Copy_u8CommendLcd){
	/*set pin rs  low to active send command*/
	DIO_VoidSetPin_Value(LCD_ctrl_port,LCD_rs_pin,PINLOW);
	/*set pin rw low to active write*/
	DIO_VoidSetPin_Value(LCD_ctrl_port,LCD_rw_pin,PINLOW);
	/*   send command to lcd */
	DIO_VoidSetPort_Value(LCD_data_port,Copy_u8CommendLcd);
	/*  make pulse to lcd   */
	DIO_VoidSetPin_Value(LCD_ctrl_port,LCD_e_pin,PINHIGH);
	_delay_ms(2);
	DIO_VoidSetPin_Value(LCD_ctrl_port,LCD_e_pin,PINLOW);
}

void LCD_VOIDSEND_CHAR(u8 Copy_u8CharLcd){
	/*set pin rs  low to active send char*/
	DIO_VoidSetPin_Value(LCD_ctrl_port,LCD_rs_pin,PINHIGH);
	/*set pin rw low to active write*/
	DIO_VoidSetPin_Value(LCD_ctrl_port,LCD_rw_pin,PINLOW);
	/*   send char to lcd */
	DIO_VoidSetPort_Value(LCD_data_port,Copy_u8CharLcd);
	/*  make pulse to lcd   */
	DIO_VoidSetPin_Value(LCD_ctrl_port,LCD_e_pin,PINHIGH);
	_delay_ms(2);
	DIO_VoidSetPin_Value(LCD_ctrl_port,LCD_e_pin,PINLOW);
}
void LCD_VOIDSEND_STRING(u8 *Copy_u8StringLcd){
	/*make iteration to loop in string*/
	u8 iteration=0;
	/*if char of string==/0 close loop */
	while(Copy_u8StringLcd[iteration]!='\0'){
	LCD_VOIDSEND_CHAR(Copy_u8StringLcd[iteration]);
     iteration++;
     if(iteration==15){LCD_voidposition(LCD_COLUM2,LCD_ROW0);}
	}
}
void LCD_voidposition(u8 num_u8colum,u8 num_u8row){
	if(num_u8colum==LCD_COLUM1){
	LCD_VOIDSEND_COMMAND((0X80)+num_u8row);
	}
	else if(num_u8colum==LCD_COLUM2){
		LCD_VOIDSEND_COMMAND((0X80)+64+num_u8row);
		}

}
void LCD_PRINT_EXTRACHAR(u8 *exter_char, u8 copy_patternblock ,u8 num_u8colum,u8 num_u8row){
	u8 CGRAM_ADDREESS=0;
	u8 iteriation;
	CGRAM_ADDREESS=copy_patternblock*8;
	LCD_VOIDSEND_COMMAND(CGRAM_ADDREESS+64);
	for(iteriation=0;iteriation<8;iteriation++){

		LCD_VOIDSEND_CHAR(exter_char[iteriation]);


	}

	LCD_voidposition(num_u8colum,num_u8row);
	LCD_VOIDSEND_CHAR(copy_patternblock);


}
void LCD_voidDisplayNumber(s32 copy_s32number)
{

    if (copy_s32number == 0) {
        LCD_VOIDSEND_CHAR('0');
        return;
    }


    s32 divisor = 1;
    s32 temp = copy_s32number;

    while (temp / 10 != 0) {
        divisor *= 10;
        temp /= 10;
    }

    while (divisor != 0) {
        s32 digit = copy_s32number / divisor;
        LCD_VOIDSEND_CHAR('0' + digit);
        copy_s32number %= divisor;
        divisor /= 10;

}
}
