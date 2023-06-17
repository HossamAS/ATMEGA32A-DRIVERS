/**************************************/
/* Description : USART private c File */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:09:52  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"

pf RXC_CallBack=NULL_PTR;
pf UDRE_CallBack=NULL_PTR;
pf TXC_CallBack=NULL_PTR;

uint8_kt * pu8USART_AsyncByte=NULL_PTR;

