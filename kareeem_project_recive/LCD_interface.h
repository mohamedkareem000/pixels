#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_
#include"STD_TYPES.h"
#include"LCD_configur.h"
enum{
	LCD_COLUM1=1,
	LCD_COLUM2
};
enum{
	LCD_ROW0,
	LCD_ROW1,
	LCD_ROW2,
	LCD_ROW3,
	LCD_ROW4,
	LCD_ROW5,
	LCD_ROW6,
	LCD_ROW7,
	LCD_ROW8,
	LCD_ROW9,
	LCD_ROW10,
	LCD_ROW11,
	LCD_ROW12,
	LCD_ROW13,
	LCD_ROW14,
	LCD_ROW15
};
void LCD_VOIDINIT(void);
void LCD_VOIDSEND_COMMAND(u8 Copy_u8CommendLcd);
void LCD_VOIDSEND_CHAR(u8 Copy_u8CharLcd);
void LCD_VOIDSEND_STRING(u8 *Copy_u8StringLcd);
void LCD_voidposition(u8 num_u8colum,u8 num_u8row);
void LCD_PRINT_EXTRACHAR(u8 *exter_char, u8 copy_patternblock ,u8 num_u8colum,u8 num_u8row);
void LCD_voidDisplayNumber(s32 copy_s32number);
#endif
