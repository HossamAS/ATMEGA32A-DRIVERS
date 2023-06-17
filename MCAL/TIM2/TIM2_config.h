/**************************************/
/* Description : TIM2 config c File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 12:06:30  16 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM2_CONFIG_H
#define TIM2_CONFIG_H


#define CLK_PRESCALER                              	 TIM2_SYSCLK
#define WAVEFORM_MODE_PLUS_COMPARE_OUTPUT_MODE       TIM2_FAST_PWM_MODE_CLR_OC2_ON_COMPARE_MATCH_SET_AT_BOTTOM
#define OVERFLOW_INTERRUPT_STATE                     TIM2_OVF_INT_DIS
#define OUTPUT_COMPARE_MATCH_INTTERRUPT_STATE        TIM2_OCM_INT_DIS
#define COUNTER_INIT_VAL                             0
#define OUTPUT_COMPARE_REG_INIT_VAL                  127
#define ASYNCHRONOUS_OPERATION                       ASYNC_DIS
#endif
