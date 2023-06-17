/**************************************/
/* Description : EEPROM interface File*/
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 21:17:13  22 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

/*user APIs*/
ErrorStatus_et EEPROM_vWrite(uint16_kt u16AddressCpy,uint8_kt u8ByteCpy);
ErrorStatus_et EEPROM_vRead(uint16_kt u16AddressCpy,uint8_kt* pu8Byte);
#endif
