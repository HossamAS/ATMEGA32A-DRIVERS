/**************************************/
/* Description : TIM0 program File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 12:06:30  16 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "TIM0_config.h"
#include "TIM0_private.h"
#include "TIM0_interface.h"

/*pre-build configuration (pre-processing)*/
void TIM0_vInit(void)
{
	TIM0->TCNT0.REG=COUNTER_INIT_VAL;
	TIM0->OCR0.REG=OUTPUT_COMPARE_REG_INIT_VAL;
	TIM0->TCCR0.WGM0_COM0=WAVEFORM_MODE_PLUS_COMPARE_OUTPUT_MODE;
	TIM0->TIMSK.OCIE0=OUTPUT_COMPARE_MATCH_INTTERRUPT_STATE;
	TIM0->TIMSK.TOIE0=OVERFLOW_INTERRUPT_STATE;
	TIM0->TCCR0.CS0=CLK_PRESCALER;
}
/*post-build configuration*/
ErrorStatus_et TIM0_enuClkPrescaler(uint8_kt u8PrescalerCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u8PrescalerCpy<8)
	{
		TIM0->TCCR0.CS0 =u8PrescalerCpy;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et TIM0_enuWaveformModeAndCompareOutputMode(uint8_kt u8WaveformModeAndCompareOutputModeCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u8WaveformModeAndCompareOutputModeCpy<16)
	{
		TIM0->TCCR0.WGM0_COM0=u8WaveformModeAndCompareOutputModeCpy;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
		return ErrorStatusLoc_e;
}
void TIM0_vOverflowIntEn(void)
{
	TIM0->TIMSK.TOIE0=1;
}
void TIM0_vOverflowIntDis(void)
{
	TIM0->TIMSK.TOIE0=0;
}
void TIM0_vOutputCompareMatchIntEn(void)
{
	TIM0->TIMSK.OCIE0=1;
}
void TIM0_vOutputCompareMatchIntDis(void)
{
	TIM0->TIMSK.OCIE0=0;
}
void TIM0_vSetOverflowIntCallback(pf pfCallback)
{
	OVF0_CallBack=pfCallback;

}
void TIM0_vSetOutputCompareMatchIntCallback(pf pfCallback)
{
	OCM0_CallBack=pfCallback;
}
/*APIs*/
void TIM0_vReadCountVal(uint8_kt * pu8CountValue)
{
	*pu8CountValue=TIM0->TCNT0.REG;
}
void TIM0_vWriteCountVal(uint8_kt  u8CountValueCpy)
{
	TIM0->TCNT0.REG=u8CountValueCpy;
}
void TIM0_vReadOutputCompareVal(uint8_kt * pu8CompareValue)
{
	*pu8CompareValue=TIM0->OCR0.REG;
}
void TIM0_vWriteOutputCompareVal(uint8_kt  u8CompareValueCpy)
{
	TIM0->OCR0.REG=u8CompareValueCpy;
}

void __vector_10(void) __attribute__((signal,used));
void __vector_10(void)
{
	if(OCM0_CallBack!=NULL_PTR)
	{
		OCM0_CallBack();
	}
}
void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	if(OVF0_CallBack!=NULL_PTR)
	{
		OVF0_CallBack();
	}
}
