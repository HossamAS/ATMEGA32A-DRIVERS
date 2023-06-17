/**************************************/
/* Description : LED interface h File */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 10:06:53  03 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

ErrorStatus_et LED_enuOn(uint8_kt u8LedIdCpy);
ErrorStatus_et LED_enuOff(uint8_kt u8LedIdCpy);
ErrorStatus_et LED_enuTog(uint8_kt u8LedIdCpy);

#endif
