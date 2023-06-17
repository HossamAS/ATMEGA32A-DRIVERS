/**************************************/
/* Description : TIM1 program File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 17:10:42  23 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "TIM1_private.h"
#include "TIM1_config.h"
#include "TIM1_interface.h"

/*pre-build configuration (pre-processing)*/
void TIM1_vInit(void)
{
	TIM1.TCCR1B.CS1=CLK_PRESCALER;
	TIM1.TCCR1A.WGM11_10=(uint8_kt)WAVEFORM_MODE;
	TIM1.TCCR1B.WGM13_12=(uint8_kt)(WAVEFORM_MODE>>2);
	TIM1.TCCR1A.COM1B=COMPARE_OUTPUT_MODE_REG_B;
	TIM1.TCCR1A.COM1A=COMPARE_OUTPUT_MODE_REG_A;
    TIM1.TIMSK1.TOIE1=OVERFLOW_INTERRUPT_STATE;
    TIM1.TIMSK1.OCIE1B=OUTPUT_COMPARE_MATCH_B_INTTERRUPT_STATE;
    TIM1.TIMSK1.OCIE1A=OUTPUT_COMPARE_MATCH_A_INTTERRUPT_STATE;
    TIM1.TIMSK1.TICIE1=INPUT_CAPTURE_UNIT_INTTERRUPT_STATE;
    TIM1.TCNT1.REG=COUNTER_INIT_VAL;
    TIM1.OCR1A.REG=OUTPUT_COMPARE_REG_A_INIT_VAL;
    TIM1.OCR1B.REG=OUTPUT_COMPARE_REG_B_INIT_VAL;
    TIM1.ICR1.REG=INPUT_CAPTURE_REG_INIT_VAL;
}
/*run-time configuration*/
ErrorStatus_et TIM1_enuClkPrescaler(uint8_kt u8PrescalerCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u8PrescalerCpy<7)
	{
		TIM1.TCCR1B.CS1=u8PrescalerCpy;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et TIM1_enuWaveformMode(uint8_kt u8WaveformModeCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		if(u8WaveformModeCpy<15)
		{
			TIM1.TCCR1A.WGM11_10=u8WaveformModeCpy;
			TIM1.TCCR1B.WGM13_12=u8WaveformModeCpy>>2;
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
		return ErrorStatusLoc_e;
}
ErrorStatus_et TIM1_enuCompareOutputMode(uint8_kt u8Reg,uint8_kt u8CompareOutputModeCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
			if(u8Reg==OCRA)
			{
				if(u8CompareOutputModeCpy<4)
				{
					TIM1.TCCR1A.COM1A=COMPARE_OUTPUT_MODE_REG_A;
				}
				else
				{
					ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
				}
			}
			else if(u8Reg==OCRB)
			{
				if(u8CompareOutputModeCpy<4&&u8CompareOutputModeCpy!=1)
				{
					TIM1.TCCR1A.COM1B=COMPARE_OUTPUT_MODE_REG_B;
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
ErrorStatus_et TIM1_vICU_EdgeSelect(uint8_kt u8EdgeTypeCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u8EdgeTypeCpy<2)
		{
		 TIM1.TCCR1B.ICES1=u8EdgeTypeCpy;
		}
	else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
	return ErrorStatusLoc_e;
}
void TIM1_vICU_NoiseCancelerDis(void)
{
	TIM1.TCCR1B.ICNC1=0;
}
void TIM1_vICU_NoiseCancelerEn(void)
{
	TIM1.TCCR1B.ICNC1=1;
}
void TIM1_vOverflowIntEn(void)
{
	TIM1.TIMSK1.TOIE1=1;
}
void TIM1_vOverflowIntDis(void)
{
	TIM1.TIMSK1.TOIE1=0;
}
void TIM1_vRegA_OutputCompareMatchIntEn(void)
{
	TIM1.TIMSK1.OCIE1A=1;
}
void TIM1_vRegA_OutputCompareMatchIntDis(void)
{
	TIM1.TIMSK1.OCIE1A=0;
}
void TIM1_vRegB_OutputCompareMatchIntEn(void)
{
	TIM1.TIMSK1.OCIE1B=1;
}
void TIM1_vRegB_OutputCompareMatchIntDis(void)
{
	TIM1.TIMSK1.OCIE1B=0;
}
void TIM1_vIntputCaptureUnitIntDis(void)
{
TIM1.TIMSK1.TICIE1=0;
}
void TIM1_vIntputCaptureUnitIntEn(void)
{
TIM1.TIMSK1.TICIE1=1;
}
void TIM1_vSetOverflowIntCallback(pf pfCallback)
{
	OVF1_CallBack=pfCallback;

}
void TIM1_vSetRegA_OutputCompareMatchIntCallback(pf pfCallback)
{
    OCM1A_CallBack=pfCallback;
}
void TIM1_vSetRegB_OutputCompareMatchIntCallback(pf pfCallback)
{
	OCM1B_CallBack=pfCallback;
}
void TIM1_vSetIntputCaptureUnitIntCallback(pf pfCallback)
{
	ICU1_CallBack=pfCallback;
}
/*APIs*/
void TIM1_vReadCountVal(uint16_kt * pu16CountValue)
{
	* pu16CountValue=TIM1.TCNT1.REG;
}
void TIM1_vWriteCountVal(uint16_kt  u16CountValueCpy)
{
	TIM1.TCNT1.REG=u16CountValueCpy;
}
void TIM1_vReadOutputCompareRegA_Val(uint16_kt * pu16CompareValue)
{
	*pu16CompareValue=TIM1.OCR1A.REG;
}
void TIM1_vWriteOutputCompareRegA_Val(uint16_kt  u16CompareValueCpy)
{
	TIM1.OCR1A.REG=u16CompareValueCpy;
}

void TIM1_vReadOutputCompareRegB_Val(uint16_kt * pu16CompareValue)
{
	*pu16CompareValue=TIM1.OCR1B.REG;
}
void TIM1_vWriteOutputCompareRegB_Val(uint16_kt  u16CompareValueCpy)
{
	TIM1.OCR1B.REG=u16CompareValueCpy;
}

void TIM1_vReadInputCaptureUnitVal(uint16_kt * pu16CompareValue)
{
	*pu16CompareValue=TIM1.ICR1.REG;
}
void TIM1_vWriteInputCaptureUnitVal(uint16_kt  u16CompareValueCpy)
{
	TIM1.ICR1.REG=u16CompareValueCpy;
}

void __vector_6(void) __attribute__((signal,used));
void __vector_6(void)
{
	if(ICU1_CallBack!=NULL_PTR)
	{
		ICU1_CallBack();
	}
}
void __vector_7(void) __attribute__((signal,used));
void __vector_7(void)
{
	if(OCM1A_CallBack!=NULL_PTR)
	{
		OCM1A_CallBack();
	}
}
void __vector_8(void) __attribute__((signal,used));
void __vector_8(void)
{
	if(OCM1B_CallBack!=NULL_PTR)
	{
		OCM1B_CallBack();
	}
}
void __vector_9(void) __attribute__((signal,used));
void __vector_9(void)
{
	if(OVF1_CallBack!=NULL_PTR)
	{
		OVF1_CallBack();
	}
}

