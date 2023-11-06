#include"DIO_PRIVECY.h"
#include"DIO_interface.h"
#include"bit_math.h"
#include"std_types.h"
void DIO_VoidSetPin_Direction(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction){

	if(Copy_u8Direction==INPUT){
			switch(Copy_u8Port){
			case PORT_A:bit_clear(DDRA,Copy_u8Pin);break;
			case PORT_B:bit_clear(DDRB,Copy_u8Pin);break;
			case PORT_C: bit_clear(DDRC,Copy_u8Pin);break;
			case PORT_D:bit_clear(DDRD,Copy_u8Pin);break;

			}


	}
	else if(Copy_u8Direction==OUTPUT){
				switch(Copy_u8Port){
				case PORT_A:bit_set(DDRA,Copy_u8Pin);break;
				case PORT_B:bit_set(DDRB,Copy_u8Pin);break;
				case PORT_C: bit_set(DDRC,Copy_u8Pin);break;
				case PORT_D:bit_set(DDRD,Copy_u8Pin);break;

				}


		}


}
void DIO_VoidSetPin_Value(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value){

	if(Copy_u8Value==PINLOW){
			switch(Copy_u8Port){
			case PORT_A:bit_clear(PORTA,Copy_u8Pin);break;
			case PORT_B:bit_clear(PORTB,Copy_u8Pin);break;
			case PORT_C: bit_clear(PORTC,Copy_u8Pin);break;
			case PORT_D:bit_clear(PORTD,Copy_u8Pin);break;

			}


	}
	else if(Copy_u8Value==PINHIGH){
				switch(Copy_u8Port){
				case PORT_A:bit_set(PORTA,Copy_u8Pin);break;
				case PORT_B:bit_set(PORTB,Copy_u8Pin);break;
				case PORT_C: bit_set(PORTC,Copy_u8Pin);break;
				case PORT_D:bit_set(PORTD,Copy_u8Pin);break;

				}


		}


}
void DIO_VoidGetPin_Value(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_u8pvalue){
	switch(Copy_u8Port){
                case PORT_A:*Copy_u8pvalue=	bit_get(PINA,Copy_u8Pin);break;
                case PORT_B:*Copy_u8pvalue=	bit_get(PINB,Copy_u8Pin);break;
                case PORT_C:*Copy_u8pvalue=	bit_get(PINC,Copy_u8Pin);break;
                case PORT_D:*Copy_u8pvalue=	bit_get(PIND,Copy_u8Pin);break;
	}


}
void DIO_VoidSetport_Direction(u8 Copy_u8Port,u8 Copy_u8Direction){

	switch(Copy_u8Port){
					case PORT_A:DDRA=Copy_u8Direction;break;
					case PORT_B:DDRB=Copy_u8Direction;break;
					case PORT_C: DDRC=Copy_u8Direction;break;
					case PORT_D:DDRD=Copy_u8Direction;break;
	}
}
	void DIO_VoidSetPort_Value(u8 Copy_u8Port,u8 Copy_u8value){
		switch(Copy_u8Port){
						case PORT_A:PORTA=Copy_u8value;break;
						case PORT_B:PORTB=Copy_u8value;break;
						case PORT_C: PORTC=Copy_u8value;break;
						case PORT_D:PORTD=Copy_u8value;break;
	}
	}
	void DIO_VoidGetPort_Value(u8 Copy_u8Port,u8 *Copy_u8pvalue){
	switch(Copy_u8Port){
                case PORT_A:*Copy_u8pvalue=	PINA;break;
                case PORT_B:*Copy_u8pvalue=	PINB;break;
                case PORT_C:*Copy_u8pvalue=	PINC;break;
                case PORT_D:*Copy_u8pvalue=	PIND;break;
	}

	}
void DIO_toggle_PIN(u8 Copy_u8Port,u8 Copy_u8Pin){
	switch(Copy_u8Port){
				case PORT_A:bit_togel(PORTA,Copy_u8Pin);break;
				case PORT_B:bit_togel(PORTB,Copy_u8Pin);break;
				case PORT_C: bit_togel(PORTC,Copy_u8Pin);break;
				case PORT_D:bit_togel(PORTD,Copy_u8Pin);break;

}
}
