/**************************************/
/* Description : TIM0 interface File  */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 12:06:30  16 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM0_INTERFACE_H
#define TIM0_INTERFACE_H
/*pre-build configuration (pre-processing)*/
void TIM0_vInit(void);
/*post-build configuration*/
ErrorStatus_et TIM0_enuClkPrescaler(uint8_kt u8PrescalerCpy);
ErrorStatus_et TIM0_enuWaveformModeAndCompareOutputMode(uint8_kt u8WaveformModeAndCompareOutputModeCpy);
void TIM0_vOverflowIntEn(void);
void TIM0_vOverflowIntDis(void);
void TIM0_vOutputCompareMatchIntEn(void);
void TIM0_vOutputCompareMatchIntDis(void);
void TIM0_vSetOverflowIntCallback(pf pfCallback);
void TIM0_vSetOutputCompareMatchIntCallback(pf pfCallback);
/*APIs*/
void TIM0_vReadCountVal(uint8_kt * pu8CountValue);
void TIM0_vWriteCountVal(uint8_kt  u8CountValueCpy);
void TIM0_vReadOutputCompareVal(uint8_kt * pu8CompareValue);
void TIM0_vWriteOutputCompareVal(uint8_kt  u8CompareValueCpy);
/*===========Configurations=========*/

/*CLK_PRESCALER*/
#define  TIM0_DIS                   0
#define  TIM0_SYSCLK                1
#define  TIM0_SYSCLK_PER_8          2
#define  TIM0_SYSCLK_PER_64         3
#define  TIM0_SYSCLK_PER_256        4
#define  TIM0_SYSCLK_PER_1024       5
#define  TIM0_EXTCLK_FALLING_EDGE   6
#define  TIM0_EXTCLK_RAISING_EDGE   7
/*WAVEFORM_MODE_PLUS_COMPARE_OUTPUT_MODE*/

#define TIM0_NORMAL_MODE_DIS_OC0                                                                                          0
#define TIM0_NORMAL_MODE_TOG_OC0                                                                                          2
#define TIM0_NORMAL_MODE_CLR_OC0                                                                                          4
#define TIM0_NORMAL_MODE_SET_OC0                                                                                          6

#define TIM0_CTC_MODE_DIS_OC0                                                                                             1
#define TIM0_CTC_MODE_TOG_OC0                                                                                             3
#define TIM0_CTC_MODE_CLR_OC0                                                                                             5
#define TIM0_CTC_MODE_SET_OC0                                                                                             7

#define TIM0_FAST_PWM_MODE_DIS_OC0                                                                                        8
#define TIM0_FAST_PWM_MODE_CLR_OC0_ON_COMPARE_MATCH_SET_AT_BOTTOM                                                         12
#define TIM0_FAST_PWM_MODE_SET_OC0_ON_COMPARE_MATCH_CLR_AT_BOTTOM                                                         14

#define TIM0_PHASE_CORRECT_PWM_MODE_DIS_OC0                                                                               9
#define TIM0_PHASE_CORRECT_PWM_MODE_CLR_OC0_ON_COMPARE_MATCH_WHEN_UP_COUNTING_SET_OC0_ON_COMPARE_MATCH_WHEN_DOWN_COUNTING 13
#define TIM0_PHASE_CORRECT_PWM_MODE_SET_OC0_ON_COMPARE_MATCH_WHEN_UP_COUNTING_CLR_OC0_ON_COMPARE_MATCH_WHEN_DOWN_COUNTING 15

/*OVERFLOW_INTERRUPT_STATE*/
#define TIM0_OVF_INT_DIS 0
#define TIM0_OVF_INT_EN  1

/*OUTPUT_COMPARE_MATCH_INTTERRUPT_STATE*/
#define TIM0_OCM_INT_DIS 0
#define TIM0_OCM_INT_EN  1


#endif
