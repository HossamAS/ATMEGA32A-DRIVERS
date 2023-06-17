/**************************************/
/* Description : LCD private c File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 05:45:07  17 Jun 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "util/delay.h"


#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"



 ErrorStatus_et LCD_vLcdWriteHelper(uint8_kt u8LcdIndexCpy, uint8_kt u8CmdCpy)
{
	ErrorStatus_et ErrorStatusLoc_e = EOK;

	if(LCD_8BIT_MODE == aLcdConfig_s[u8LcdIndexCpy].Config_s.u8Mode)
	{
		ErrorStatusLoc_e = DIO_enuWriteGroupV2(aLcdConfig_s[u8LcdIndexCpy].au8LcdDataPins, u8CmdCpy, 8);
	}

	else
	{
		ErrorStatusLoc_e = DIO_enuWriteGroupV2(aLcdConfig_s[u8LcdIndexCpy].au8LcdDataPins, u8CmdCpy >> 4, 4);

		if(EOK == ErrorStatusLoc_e)
		{
			ErrorStatusLoc_e = DIO_enuWrite(aLcdConfig_s[u8LcdIndexCpy].LcdCtrlPins_s.u8En, DIO_HIGH);

			if(EOK != ErrorStatusLoc_e)
			{
				return ErrorStatusLoc_e;
			}

			_delay_ms(1);
			DIO_enuWrite(aLcdConfig_s[u8LcdIndexCpy].LcdCtrlPins_s.u8En, DIO_LOW);
			_delay_ms(5);
			ErrorStatusLoc_e = DIO_enuWriteGroupV2(aLcdConfig_s[u8LcdIndexCpy].au8LcdDataPins, u8CmdCpy, 4);
		}
	}

	if(EOK == ErrorStatusLoc_e)
	{
		ErrorStatusLoc_e = DIO_enuWrite(aLcdConfig_s[u8LcdIndexCpy].LcdCtrlPins_s.u8En, DIO_HIGH);

		if(EOK != ErrorStatusLoc_e)
		{
			return ErrorStatusLoc_e;
		}

		_delay_ms(1);
		DIO_enuWrite(aLcdConfig_s[u8LcdIndexCpy].LcdCtrlPins_s.u8En, DIO_LOW);
		_delay_ms(5);
	}

	return ErrorStatusLoc_e;
}

 ErrorStatus_et LCD_vLcdReadHelper(uint8_kt u8LcdIndexCpy, uint8_kt *pu8Cmd)
{
	ErrorStatus_et ErrorStatusLoc_e = EOK;
	ErrorStatusLoc_e = DIO_enuWrite(aLcdConfig_s[u8LcdIndexCpy].LcdCtrlPins_s.u8En, DIO_HIGH);

	if(EOK != ErrorStatusLoc_e)
	{
		return ErrorStatusLoc_e;
	}

	_delay_ms(1);
	DIO_enuWrite(aLcdConfig_s[u8LcdIndexCpy].LcdCtrlPins_s.u8En, DIO_LOW);
	_delay_ms(5);

	if(LCD_8BIT_MODE == aLcdConfig_s[u8LcdIndexCpy].Config_s.u8Mode)
	{
		ErrorStatusLoc_e = DIO_enuReadGroupV2(aLcdConfig_s[u8LcdIndexCpy].au8LcdDataPins, (uint32_kt *)pu8Cmd, 8);
	}

	else
	{
		ErrorStatusLoc_e = DIO_enuReadGroupV2(aLcdConfig_s[u8LcdIndexCpy].au8LcdDataPins, (uint32_kt *) pu8Cmd, 4);

		if(EOK == ErrorStatusLoc_e)
		{
			*pu8Cmd <<= 4;
			DIO_enuWrite(aLcdConfig_s[u8LcdIndexCpy].LcdCtrlPins_s.u8En, DIO_HIGH);
			_delay_ms(1);
			DIO_enuWrite(aLcdConfig_s[u8LcdIndexCpy].LcdCtrlPins_s.u8En, DIO_LOW);
			_delay_ms(5);
			ErrorStatusLoc_e = DIO_enuReadGroupV2(aLcdConfig_s[u8LcdIndexCpy].au8LcdDataPins, (uint32_kt *) pu8Cmd, 4);
		}
	}


	return ErrorStatusLoc_e;
}