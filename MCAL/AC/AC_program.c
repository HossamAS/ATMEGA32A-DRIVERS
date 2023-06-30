/**************************************/
/* Description : AC program File      */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 03:31:39  13 Jun 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "AC_Config.h"
#include "AC_Private.h"
#include "AC_Interface.h"
/*pre-build configuration (preprocessing)*/
void AC_vInit(void)
{
AC->ACSR.ACD=!AC_STATUS;
AC->ACSR.ACIE= AC_INT_STATUS;
AC->ACSR.ACBG= AC_BANDGAP_ON_AIN0_STATUS;
AC->ACSR.ACIC= AC_AS_INPUT_CAPTURE_TRIGGER_SIGNAL_STATUS;
AC->ACSR.ACIS= AC_INT_MODE;
#if( AC_NEGATIVE_INPUT_SOURCE!=AC_AIN1)
AC->SFIOR.ACME=1;
AC->ADCSRA.ADEN=0;
AC->ADMUX.MUX=AC_NEGATIVE_INPUT_SOURCE;
#else
AC->SFIOR.ACME=0;
#endif

}
/*run time configuration*/
inline void AC_vEn(void)
{
	AC->ACSR.ACD=0;
}
inline void AC_vDis(void)
{
	AC->ACSR.ACD=1;
}
inline void AC_vIntEn(void)
{
	AC->ACSR.ACIE=1;
}
inline void AC_vIntDis(void)
{
	AC->ACSR.ACIE=0;
}
inline void AC_vBandGapOnAIN0_En(void)
{
	AC->ACSR.ACBG=1;
}
inline void AC_vBandGapOnAIN0_Dis(void)
{
	AC->ACSR.ACBG=0;
}
inline void AC_vAsInputCaptureTrigSignalEn(void)
{
	AC->ACSR.ACIC=1;
}
inline void AC_vAsInputCaptureTrigSignalDis(void)
{
	AC->ACSR.ACIC=0;
}
ErrorStatus_et AC_enuIntMode(uint8_kt u8ModeCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		if(u8ModeCpy<3&&u8ModeCpy!=1)
		{
			AC->ACSR.ACIS=u8ModeCpy;
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}

			return ErrorStatusLoc_e;
} 
ErrorStatus_et AC_enuNegativeInputSrc(uint8_kt u8SrcCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u8SrcCpy<8)
	{
		AC->SFIOR.ACME=1;
		AC->ADCSRA.ADEN=0;
		AC->ADMUX.MUX=u8SrcCpy;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}

		return ErrorStatusLoc_e;
}
/*APIs*/
void AC_vSyncReadOutput(uint8_kt* pu8UserOutput)
{
	*pu8UserOutput=AC->ACSR.ACO;
}
ErrorStatus_et AC_enuAsyncReadOutput(uint8_kt* pu8UserOutput)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		if(pu8UserOutput!=NULL_PTR)
		{
			pu8Output=pu8UserOutput;
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
		return ErrorStatusLoc_e;
}
ErrorStatus_et AC_enuSetCallBack(pf pfCallBack)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(pfCallBack!=NULL_PTR)
	{
		AC_pfCallBack=pfCallBack;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}
/*interrupt routine*/
void __vector_18(void) __attribute__((signal,used));
void __vector_18(void)
{
#if (AC_ASYNC_STATUS)
	if(pu8Output!=NULL_PTR)
	{
		*pu8Output=AC->ACSR.ACO;
	}
#endif
#if (AC_CALLBACK_STATUS)
	if(AC_pfCallBack!=NULL_PTR)
	{
		AC_pfCallBack();
	}
#endif

}
