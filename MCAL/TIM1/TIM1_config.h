/**************************************/
/* Description : TIM1 config c File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 17:10:42  23 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM1_CONFIG_H
#define TIM1_CONFIG_H

#define CLK_PRESCALER                              	   TIM1_SYSCLK
#define WAVEFORM_MODE                                  TIM1_FAST_PWM_TOP_OCR1A
#define COMPARE_OUTPUT_MODE_REG_A                      TIM1_TOG_OC1A
#define COMPARE_OUTPUT_MODE_REG_B                      TIM1_DIS_OC1B
#define OVERFLOW_INTERRUPT_STATE                       TIM1_OVF_INT_DIS
#define OUTPUT_COMPARE_MATCH_A_INTTERRUPT_STATE        TIM1_OCMA_INT_DIS
#define OUTPUT_COMPARE_MATCH_B_INTTERRUPT_STATE        TIM1_OCMB_INT_DIS
#define INPUT_CAPTURE_UNIT_INTTERRUPT_STATE            TIM1_ICU_INT_DIS
#define COUNTER_INIT_VAL                               0UL
#define OUTPUT_COMPARE_REG_A_INIT_VAL                  32768UL
#define OUTPUT_COMPARE_REG_B_INIT_VAL                  0UL
#define INPUT_CAPTURE_REG_INIT_VAL                     0UL





#endif
