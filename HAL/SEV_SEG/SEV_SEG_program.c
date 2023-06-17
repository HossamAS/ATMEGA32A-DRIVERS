/***************************************/
/* Description : Sev Seg program c File*/
/* Author      : hossam                */
/* Version     : 0.1V                  */
/* Date        : 10:52:34  03 Jan 2023 */
/* History     : 0.1V Initial Creation */
/***************************************/
#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "SEV_SEG_config.h"
#include "SEV_SEG_interface.h"
#include "SEV_SEG_private.h"

ErrorStatus_et SEV_SEG_enuDisp(uint8_kt u8SevSegIdCpy,uint8_kt u8CommandCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	uint8_kt au8SevSegCommonCathodeCodesLoc[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,
			                                     0x7d,0x07,0x7f,0x6f,0x77,0x7c,
												 0x39,0x5e,0x79,0x71,0x00
	                                            };
	if(SEV_SEG_NUM_MAX>u8SevSegIdCpy)
	{
		if(17>u8CommandCpy)
		{
			if(DOT_ON>=aSevSegConfig_s[u8SevSegIdCpy].u8DotMode)
			{
				if(COMMON_CATHODE==aSevSegConfig_s[u8SevSegIdCpy].u8ConMode)
				{
					ErrorStatusLoc_e = DIO_enuWriteGroupV2(aSevSegConfig_s[u8SevSegIdCpy].au8Pins,
							                              (au8SevSegCommonCathodeCodesLoc[u8CommandCpy])|
														  (aSevSegConfig_s[u8SevSegIdCpy].u8DotMode<<8),
														  8+aSevSegConfig_s[u8SevSegIdCpy].u8DotMode);
				}
				else if(COMMON_ANODE==aSevSegConfig_s[u8SevSegIdCpy].u8ConMode)
				{
					ErrorStatusLoc_e = DIO_enuWriteGroupV2(aSevSegConfig_s[u8SevSegIdCpy].au8Pins,
												          ~((au8SevSegCommonCathodeCodesLoc[u8CommandCpy])|
												            (aSevSegConfig_s[u8SevSegIdCpy].u8DotMode<<8)),
									                      8+aSevSegConfig_s[u8SevSegIdCpy].u8DotMode);
				}
				else
				{
					ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
				}
			}
			else
			{
				ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
			}

		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}

