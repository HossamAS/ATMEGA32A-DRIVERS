/**************************************/
/* Description : ADC program File     */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 11:03:51  12 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "../../MCAL/SREG/SREG_interface.h"
/*pre-build configuration(preprocessing)*/
void ADC_vInit(void)
{
	ADC->ADMUX.MUX=(ADC_INIT_CHANNEL);
	ADC->ADMUX.ADLAR=ADC_ADJUST_RESULT_STATE;
	ADC->ADMUX.REFS=ADC_VREF_SRC;
#if (ADC_AUTO_TRIG_INIT_SRC==ADC_SINGLE_CONVERSION)

#else
   ADC->SFIOR.ADTS=ADC_AUTO_TRIG_INIT_SRC;
   ADC->ADCSRA.ADATE=1;
#endif
	ADC->ADCSRA.ADPS=ADC_INIT_PRESCALER;
	ADC->ADCSRA.ADIE=ADC_INT_INIT_STATE;
	ADC->ADCSRA.ADEN=ADC_INIT_STATE;

}
/*post-build configuration*/

ErrorStatus_et ADC_enuChannel(uint8_kt u8ChannelCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u8ChannelCpy<8)
	{
		ADC->ADMUX.MUX=u8ChannelCpy;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et ADC_enuPrescaler(uint8_kt u8PrescalerCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		if(u8PrescalerCpy<8)
		{
			ADC->ADCSRA.ADPS=u8PrescalerCpy;
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
		return ErrorStatusLoc_e;
}
ErrorStatus_et ADC_enuAutoTrigSrc(uint8_kt u8AutoTrigSrcCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
			if(u8AutoTrigSrcCpy<8)
			{
				ADC->SFIOR.ADTS=u8AutoTrigSrcCpy;
			}
			else
			{
				ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
			}
			return ErrorStatusLoc_e;
}
ErrorStatus_et ADC_vSetCallBack(pf pfCallBackCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(pfCallBackCpy!=NULL_PTR)
	{
	ADC_CallBack=pfCallBackCpy;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_NULL_PTR;
	}
	return ErrorStatusLoc_e;
}

void ADC_vEn(void)
{
   ADC->ADCSRA.ADEN=1; // @suppress("Field cannot be resolved")
}
void ADC_vDis(void)
{
	ADC->ADCSRA.ADEN=0;
}

void ADC_vAutoTrigEn(void)
{
	ADC->ADCSRA.ADATE=1;
}
void ADC_vAutoTrigDis(void)
{
	ADC->ADCSRA.ADATE=0;
}

void ADC_vIntEn(void)
{
	ADC->ADCSRA.ADIE=1;
}
void ADC_vIntDis(void)
{
	ADC->ADCSRA.ADIE=0;
}
/*Run time APIs*/

void ADC_vSyncSingleRead(uint16_kt* u16ValueCpy)
{
	ADC->ADCSRA.ADSC=1;
	while(ADC->ADCSRA.ADIF);
	ADC->ADCSRA.ADIF=1;
	*u16ValueCpy=ADC->ADCDR.REG;
}
void ADC_vStartConv(void)
{
	ADC->ADCSRA.ADSC=1;
}
void ADC_vSyncAutoRead(uint16_kt* u16ValueCpy)
{
	while(ADC->ADCSRA.ADIF);
	ADC->ADCSRA.ADIF=1;
	*u16ValueCpy=ADC->ADCDR.REG;
}

void ADC_vAsyncRead(uint16_kt* u16ValueCpy)
{
	pu16AsyncValue=u16ValueCpy;
	ADC->ADCSRA.ADSC=1;
}

void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{
#if (ADC_ASYNC_STATE==ADC_EN)
	if(pu16AsyncValue!=NULL_PTR)
	{
		*pu16AsyncValue=ADC->ADCDR.REG;
	}
#endif
#if (ADC_CALLBACK_STATE==ADC_EN)
	if(ADC_CallBack!=NULL_PTR)
	{
		ADC_CallBack();
	}
#endif
}
