
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define  UBRRL  *((volatile u8*)0x29)
#define  UBRRH  *((volatile u8*)0x40)
#define  UCSRC  *((volatile u8*)0x40)
#define  UCSRB  *((volatile u8*)0x2A)
#define  UCSRA  *((volatile u8*)0x2B)
#define  UDR    *((volatile u8*)0x2C)


void UART_Init(void)
{
  // Set BaudRate -> 9600/8MhZ
  UBRRL = 51;
  UBRRH = 0;
  // Set Frame Format -> 8 data, 1 stop, No Parity
  UCSRC = 0x86;
  // Enable RX and TX
  UCSRB = 0x18;
}

void UART_SendChar(u8 data)
{
  // Wait until transmission Register Empty
  while((UCSRA&0x20) == 0x00);
  UDR = data;
}

u8 UART_GetChar(void)
{
  u8 Result;
  // Wait until Reception Complete
  while((UCSRA&0x80) == 0x00);
  Result = UDR;
  
  /* Clear Flag */
  SET_BIT(UCSRA,7);
  return Result;
  
}

