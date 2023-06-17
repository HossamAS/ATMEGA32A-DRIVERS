/**************************************/
/* Description : EEPROM program File  */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 21:17:13  22 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"

/*user APIs*/
ErrorStatus_et EEPROM_vWrite(uint16_kt u16AddressCpy,uint8_kt u8ByteCpy)
{

	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u16AddressCpy<1024)
	{
		while(EEPROM.EECR.EEWE);
		while(EEPROM.SPMCR.SPMEN);
		EEPROM.EEAR.REG=u16AddressCpy;
		EEPROM.EEDR.REG=u8ByteCpy;
		EEPROM.EECR.REG=4;
		EEPROM.EECR.REG=2;

	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;


}
ErrorStatus_et EEPROM_vRead(uint16_kt u16AddressCpy,uint8_kt* pu8Byte)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		if(u16AddressCpy<1024)
		{
			while(EEPROM.EECR.EEWE);
			while(EEPROM.SPMCR.SPMEN);
			EEPROM.EEAR.REG=u16AddressCpy;
			EEPROM.EECR.REG=1;
			*pu8Byte=EEPROM.EEDR.REG;
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
		return ErrorStatusLoc_e;
}
