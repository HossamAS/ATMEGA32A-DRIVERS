/**************************************/
/* Description : AC config c File     */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 03:31:39  13 Jun 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef AC_CONFIG_H
#define AC_CONFIG_H

#define AC_STATUS                                 AC_EN
#define AC_INT_STATUS                             AC_EN
#define AC_BANDGAP_ON_AIN0_STATUS                 AC_DIS
#define AC_AS_INPUT_CAPTURE_TRIGGER_SIGNAL_STATUS AC_DIS
#define AC_INT_MODE                               AC_OUTPUT_TOG
#define AC_NEGATIVE_INPUT_SOURCE                  AC_ADC0 /*warning: choosing any another option except AC_AIN1 will disable the ADC module*/
#define AC_ASYNC_STATUS                           AC_EN
#define AC_CALLBACK_STATUS                        AC_DIS
#endif
