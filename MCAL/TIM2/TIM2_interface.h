/**************************************/
/* Description : TIM2 interface File  */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 12:06:30  16 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM2_INTERFACE_H
#define TIM2_INTERFACE_H
/*pre-build configuration (pre-processing)*/
void TIM2_vInit(void);
/*post-build configuration*/
ErrorStatus_et TIM2_enuClkPrescaler(uint8_kt u8PrescalerCpy);
ErrorStatus_et TIM2_enuWaveformModeAndCompareOutputMode(uint8_kt u8WaveformModeAndCompareOutputModeCpy);
void TIM2_vAsyncModeEn(void);
void TIM2_vAsyncModeDis(void);
void TIM2_vOverflowIntEn(void);
void TIM2_vOverflowIntDis(void);
void TIM2_vOutputCompareMatchIntEn(void);
void TIM2_vOutputCompareMatchIntDis(void);
void TIM2_vSetOverflowIntCallback(pf pfCallback);
void TIM2_vSetOutputCompareMatchIntCallback(pf pfCallback);
/*APIs*/
void TIM2_vReadCountVal(uint8_kt * pu8CountValue);
void TIM2_vWriteCountVal(uint8_kt  u8CountValueCpy);
void TIM2_vReadOutputCompareVal(uint8_kt * pu8CompareValue);
void TIM2_vWriteOutputCompareVal(uint8_kt  u8CompareValueCpy);

/*===========Configurations=========*/

/*CLK_PRESCALER*/
#define  TIM2_DIS                   0
#define  TIM2_SYSCLK                1
#define  TIM2_SYSCLK_PER_8          2
#define  TIM2_SYSCLK_PER_32         3
#define  TIM2_SYSCLK_PER_64         4
#define  TIM2_SYSCLK_PER_128        5
#define  TIM2_SYSCLK_PER_256        6
#define  TIM2_SYSCLK_PER_1024       7
/*WAVEFORM_MODE_PLUS_COMPARE_OUTPUT_MODE*/

#define TIM2_NORMAL_MODE_DIS_OC2                                                                                          0
#define TIM2_NORMAL_MODE_TOG_OC2                                                                                          2
#define TIM2_NORMAL_MODE_CLR_OC2                                                                                          4
#define TIM2_NORMAL_MODE_SET_OC2                                                                                          6

#define TIM2_CTC_MODE_DIS_OC2                                                                                             1
#define TIM2_CTC_MODE_TOG_OC2                                                                                             3
#define TIM2_CTC_MODE_CLR_OC2                                                                                             5
#define TIM2_CTC_MODE_SET_OC2                                                                                             7

#define TIM2_FAST_PWM_MODE_DIS_OC2                                                                                        8
#define TIM2_FAST_PWM_MODE_CLR_OC2_ON_COMPARE_MATCH_SET_AT_BOTTOM                                                         12
#define TIM2_FAST_PWM_MODE_SET_OC2_ON_COMPARE_MATCH_CLR_AT_BOTTOM                                                         14

#define TIM2_PHASE_CORRECT_PWM_MODE_DIS_OC2                                                                               9
#define TIM2_PHASE_CORRECT_PWM_MODE_CLR_OC2_ON_COMPARE_MATCH_WHEN_UP_COUNTING_SET_OC2_ON_COMPARE_MATCH_WHEN_DOWN_COUNTING 13
#define TIM2_PHASE_CORRECT_PWM_MODE_SET_OC2_ON_COMPARE_MATCH_WHEN_UP_COUNTING_CLR_OC2_ON_COMPARE_MATCH_WHEN_DOWN_COUNTING 15

/*OVERFLOW_INTERRUPT_STATE*/
#define TIM2_OVF_INT_DIS 0
#define TIM2_OVF_INT_EN  1

/*OUTPUT_COMPARE_MATCH_INTTERRUPT_STATE*/
#define TIM2_OCM_INT_DIS 0
#define TIM2_OCM_INT_EN  1

/*ASYNCRONOUS_MODE*/

#define ASYNC_DIS 0
#define ASYNC_EN  1

#endif
