/**************************************/
/* Description : LED config h File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 19:24:48  03 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "LED_config.h"
#include  "../../MCAL/DIO/DIO_interface.h"
uint8_kt au8LedConfig[LED_NUM_MAX]={
	DIO_PIN_NUM_10,
	DIO_PIN_NUM_11,
	DIO_PIN_NUM_12,
};

