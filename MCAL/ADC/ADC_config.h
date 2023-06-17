/**************************************/
/* Description : ADC config c File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 11:03:51  12 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

#define ADC_VREF_SRC                     ADC_AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF
#define ADC_ADJUST_RESULT_STATE          ADC_RIGHT_ADJUST
#define ADC_INIT_CHANNEL                 ADC_DIFF_POS_ADC0_NEG_ADC1_GAIN_10X
#define ADC_INIT_STATE					 ADC_EN
#define ADC_INT_INIT_STATE               ADC_EN
#define ADC_AUTO_TRIG_INIT_SRC           ADC_FREE_RUNNING_MODE
#define ADC_INIT_PRESCALER               ADC_FACTOR_128
#define ADC_ASYNC_STATE                  ADC_EN
#define ADC_CALLBACK_STATE				 ADC_EN
#endif
