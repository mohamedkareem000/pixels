#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include"std_types.h"
#include"DIO_PRIVECY.h"
typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
} ET_PORT;
typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
} ET_PIN;
typedef enum{
	INPUT,
	OUTPUT
}ET_DIRCT;
typedef enum{
	PINLOW,
	PINHIGH
}ET_STATUS;
//set diraction of pin
void DIO_VoidSetPin_Direction(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction);
// set value of pin
void DIO_VoidSetPin_Value(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);
//get value of pin
void DIO_VoidGetPin_Value(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_u8pvalue);
//set port diraction
void DIO_VoidSetport_Direction(u8 Copy_u8Port,u8 Copy_u8Direction);
//set port value
void DIO_VoidSetPort_Value(u8 Copy_u8Port,u8 Copy_u8value);
// getting port value
void DIO_VoidGetPort_Value(u8 Copy_u8Port,u8 *Copy_u8pvalue);
void DIO_toggle_PIN(u8 Copy_u8Port,u8 Copy_u8Pin);
#endif
