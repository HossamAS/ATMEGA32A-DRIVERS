/**************************************/
/* Description : DIO private c File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 06:51:41  02 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "../../LIB/STD_TYPES/STD_TYPES.h"


ErrorStatus_et DetectMultiOccurance(uint8_kt au8Arr[],uint8_kt au8ArrLengthCpy)
{
	uint8_kt u8Index1Loc,u8Index2Loc;
	ErrorStatus_et ErrorState_e=EOK;
	for(u8Index1Loc=0;(EOK==ErrorState_e)&&(u8Index1Loc<au8ArrLengthCpy-1);u8Index1Loc++)
	{
		for(u8Index2Loc=0;(EOK==ErrorState_e)&&(u8Index2Loc<au8ArrLengthCpy);u8Index2Loc++)
			{
				if((au8Arr[u8Index2Loc]==au8Arr[u8Index1Loc])&&(u8Index2Loc!=u8Index1Loc))
				{
					ErrorState_e=MULTI_OCCUR;
				}
			}

	}


	return ErrorState_e;
	
}

