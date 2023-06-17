/**************************************/
/* Description : TIM1 interface File  */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 17:10:42  23 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM1_INTERFACE_H
#define TIM1_INTERFACE_H
/*pre-build configuration (pre-processing)*/
void TIM1_vInit(void);
/*post-build configuration*/
ErrorStatus_et TIM1_enuClkPrescaler(uint8_kt u8PrescalerCpy);
ErrorStatus_et TIM1_enuWaveformMode(uint8_kt u8WaveformModeCpy);
ErrorStatus_et TIM1_enuCompareOutputMode(uint8_kt u8Reg,uint8_kt u8CompareOutputModeCpy);
ErrorStatus_et TIM1_vICU_EdgeSelect(uint8_kt u8EdgeTypeCpy);
void TIM1_vICU_NoiseCancelerDis(void);
void TIM1_vICU_NoiseCancelerEn(void);
void TIM1_vOverflowIntEn(void);
void TIM1_vOverflowIntDis(void);
void TIM1_vOutputCompareMatchIntEn(void);
void TIM1_vOutputCompareMatchIntDis(void);
void TIM1_vSetOverflowIntCallback(pf pfCallback);
void TIM1_vSetOutputCompareMatchIntCallback(pf pfCallback);
/*APIs*/
void TIM1_vReadCountVal(uint16_kt * pu16CountValue);
void TIM1_vWriteCountVal(uint16_kt  u16CountValueCpy);
void TIM1_vReadOutputCompareVal(uint16_kt * pu16CompareValue);
void TIM1_vWriteOutputCompareVal(uint16_kt  u16CompareValueCpy);
/*===========Configurations=========*/

/*CLK_PRESCALER*/
#define  TIM1_DIS                   0
#define  TIM1_SYSCLK                1
#define  TIM1_SYSCLK_PER_8          2
#define  TIM1_SYSCLK_PER_32         3
#define  TIM1_SYSCLK_PER_64         4
#define  TIM1_SYSCLK_PER_128        5
#define  TIM1_SYSCLK_PER_256        6
#define  TIM1_SYSCLK_PER_1024       7
/*WAVEFORM_MODE*/

#define TIM1_NORMAL_TOP_0XFFFF                            0
													      
#define TIM1_PWM_PHASE_CORRECT_TOP_0X00FF                 1
#define TIM1_PWM_PHASE_CORRECT_TOP_0X01FF                 2
#define TIM1_PWM_PHASE_CORRECT_TOP_OX3FF                  3
													      
#define TIM1_CTC_TOP_OCR1A                                4
#define TIM1_CTC_TOP_ICR1                                 12
													      
#define TIM1_FAST_PWM_TOP_0x00FF                          5
#define TIM1_FAST_PWM_TOP_0x01FF                          6
#define TIM1_FAST_PWM_TOP_0x03FF                          7
#define TIM1_FAST_PWM_TOP_OCR1A                           15
#define TIM1_FAST_PWM_TOP_ICR1                            14

#define TIM1_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_OCR1A	  11												      
#define TIM1_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_ICR1     10 
    


/*COMPARE_OUTPUT_MODE*/

#define TIM1_DIS_OC1A  0
#define TIM1_TOG_OC1A  1  
#define TIM1_CLR_OC1A  2
#define TIM1_SET_OC1A  3

#define TIM1_DIS_OC1B  0
#define TIM1_CLR_OC1B  2
#define TIM1_SET_OC1B  3

/*OVERFLOW_INTERRUPT_STATE*/
#define TIM1_OVF_INT_DIS 0
#define TIM1_OVF_INT_EN  1

/*OUTPUT_COMPARE_MATCH_A_INTTERRUPT_STATE*/
#define TIM1_OCMA_INT_DIS 0
#define TIM1_OCMA_INT_EN  1

/*OUTPUT_COMPARE_MATCH_B_INTTERRUPT_STATE*/
#define TIM1_OCMB_INT_DIS 0
#define TIM1_OCMB_INT_EN  1

/*INPUT_CAPTURE_UNIT_INTTERRUPT_STATE*/
#define TIM1_ICU_INT_DIS 0
#define TIM1_ICU_INT_EN  1

/* OUTPUT SELECTION*/
#define  OCRA 0
#define  OCRB 1




#endif
