/**************************************/
/* Description : TIM2 program File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:21:59  23 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "TIM2_private.h"
#include "TIM2_config.h"
#include "TIM2_interface.h"


/*pre-build configuration (pre-processing)*/
void TIM2_vInit(void)
{
	TIM2.TCNT2.REG=COUNTER_INIT_VAL;
	TIM2.OCR2.REG=OUTPUT_COMPARE_REG_INIT_VAL;
	TIM2.TCCR2.WGM2_COM2=WAVEFORM_MODE_PLUS_COMPARE_OUTPUT_MODE;
	TIM2.TIMSK2.OCIE2=OUTPUT_COMPARE_MATCH_INTTERRUPT_STATE;
	TIM2.TIMSK2.TOIE2=OVERFLOW_INTERRUPT_STATE;
	TIM2.TCCR2.CS2=CLK_PRESCALER;
}
/*post-build configuration*/
ErrorStatus_et TIM2_enuClkPrescaler(uint8_kt u8PrescalerCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u8PrescalerCpy<8)
	{
		TIM2.TCCR2.CS2=u8PrescalerCpy;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et TIM2_enuWaveformModeAndCompareOutputMode(uint8_kt u8WaveformModeAndCompareOutputModeCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u8WaveformModeAndCompareOutputModeCpy<16)
	{
		TIM2.TCCR2.WGM2_COM2=u8WaveformModeAndCompareOutputModeCpy;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
		return ErrorStatusLoc_e;
}
void TIM2_vOverflowIntEn(void)
{
	TIM2.TIMSK2.TOIE2=1;
}
void TIM2_vOverflowIntDis(void)
{
	TIM2.TIMSK2.TOIE2=0;
}
void TIM2_vOutputCompareMatchIntEn(void)
{
	TIM2.TIMSK2.OCIE2=1;
}
void TIM2_vOutputCompareMatchIntDis(void)
{
	TIM2.TIMSK2.OCIE2=0;
}
void TIM2_vSetOverflowIntCallback(pf pfCallback)
{
	OVF2_CallBack=pfCallback;

}
void TIM2_vSetOutputCompareMatchIntCallback(pf pfCallback)
{
	OCM2_CallBack=pfCallback;
}
/*APIs*/
void TIM2_vReadCountVal(uint8_kt * pu8CountValue)
{
	*pu8CountValue=TIM2.TCNT2.REG;
}
void TIM2_vWriteCountVal(uint8_kt  u8CountValueCpy)
{
	TIM2.TCNT2.REG=u8CountValueCpy;
}
void TIM2_vReadOutputCompareVal(uint8_kt * pu8CompareValue)
{
	*pu8CompareValue=TIM2.OCR2.REG;
}
void TIM2_vWriteOutputCompareVal(uint8_kt  u8CompareValueCpy)
{
	TIM2.OCR2.REG=u8CompareValueCpy;
}


void __vector_4(void) __attribute__((signal,used));
void __vector_4(void)
{
	if(OCM2_CallBack!=NULL_PTR)
	{
		OCM2_CallBack();
	}
}



void __vector_5(void) __attribute__((signal,used));
void __vector_5(void)
{
	if(OVF2_CallBack!=NULL_PTR)
	{
		OVF2_CallBack();
	}
}
