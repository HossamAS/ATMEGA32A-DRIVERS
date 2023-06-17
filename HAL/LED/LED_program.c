/**************************************/
/* Description : LED program c File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 10:06:53  03 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"

#include "../../MCAL/DIO/DIO_interface.h"

ErrorStatus_et LED_enuOn(uint8_kt u8LedIdCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(LED_NUM_MAX>u8LedIdCpy)
	  {
		ErrorStatusLoc_e= DIO_enuWrite(au8LedConfig[u8LedIdCpy],DIO_HIGH);	
	  }
	else
	  {
		ErrorStatusLoc_e= PARAM_OUT_OF_RANGE;  
	  }
    return ErrorStatusLoc_e;
}
ErrorStatus_et LED_enuOff(uint8_kt u8LedIdCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(LED_NUM_MAX>u8LedIdCpy)
	  {
		ErrorStatusLoc_e= DIO_enuWrite(au8LedConfig[u8LedIdCpy],DIO_LOW);	
	  }
	else
	  {
		ErrorStatusLoc_e= PARAM_OUT_OF_RANGE;
	  }
    return ErrorStatusLoc_e;
}
ErrorStatus_et LED_enuTog(uint8_kt u8LedIdCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(LED_NUM_MAX>u8LedIdCpy)
	  {
		ErrorStatusLoc_e= DIO_enuToggle(au8LedConfig[u8LedIdCpy]);	
	  }
	else
	  {
		ErrorStatusLoc_e= PARAM_OUT_OF_RANGE;
	  }
    return ErrorStatusLoc_e;
}
