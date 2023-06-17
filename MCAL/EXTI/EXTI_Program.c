/**************************************/
/* Description : EXTI program File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 03:51:08  13 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void INT_vInit(void)
{
INT->MCUCR.ISC0=INT0_SENSE_MODE;
INT->MCUCR.ISC1=INT1_SENSE_MODE;
INT->MCUCSR.ISC2=INT2_SENSE_MODE&1;
}

ErrorStatus_et INT_vEnable(uint8_kt u8IntNum)
{
   ErrorStatus_et ErrorStatusLoc_e=EOK;
	   switch(u8IntNum)
	   {
	   case 0:	INT->GICR.INT0=1;break;
	   case 1:	INT->GICR.INT1=1;break;
	   case 2:	INT->GICR.INT2=1;break;
	   default:	ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;break;
	   }
   return ErrorStatusLoc_e;
}
ErrorStatus_et INT_vDisable(uint8_kt u8IntNum)
{
	 ErrorStatus_et ErrorStatusLoc_e=EOK;
		   switch(u8IntNum)
		   {
		   case 0:	INT->GICR.INT0=0;break;
		   case 1:	INT->GICR.INT1=0;break;
		   case 2:	INT->GICR.INT2=0;break;
		   default:	ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;break;
		   }
	   return ErrorStatusLoc_e;
}
ErrorStatus_et INT_enuIntSense(uint8_kt u8IntNum,uint8_kt u8SenseCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(4>u8SenseCpy)
	{
		 switch(u8IntNum)
				   {
				   case 0:	INT->MCUCR.ISC0=u8SenseCpy;break;
				   case 1:	INT->MCUCR.ISC1=u8SenseCpy;break;
				   case 2:	INT->MCUCSR.ISC2=u8SenseCpy;break;
				   default:	ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;break;
				   }
	}
	else
	{
		ErrorStatusLoc_e = PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et INT_enuSetCallBack(uint8_kt u8IntNum,pf pfCallBackCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(NULL_PTR==pfCallBackCpy)
	{
		ErrorStatusLoc_e=PARAM_NULL_PTR;
	}
	else
	{
		 switch(u8IntNum)
						   {
						   case 0:	INT0_CallBack=pfCallBackCpy;break;
						   case 1:	INT1_CallBack=pfCallBackCpy;break;
						   case 2:	INT2_CallBack=pfCallBackCpy;break;
						   default:	ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;break;
						   }
	}
	return ErrorStatusLoc_e;
}


void __vector_1 (void) __attribute__((signal,used));
void __vector_1 (void)
{
	if(INT0_CallBack!=NULL_PTR)
	{
		INT0_CallBack();
	}
}
void __vector_2 (void) __attribute__((signal,used));
void __vector_2 (void)
{

	if(INT1_CallBack!=NULL_PTR)
	{
		INT1_CallBack();
	}
}
void __vector_3 (void) __attribute__((signal,used));
void __vector_3 (void)
{

	if(INT2_CallBack!=NULL_PTR)
	{
		INT2_CallBack();
	}
}
