/**************************************/
/* Description : I2C config c File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:10:06  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

#define TWI_STATUS                                         TWI_EN
#define TWI_INTERRUPT_STATUS                               TWI_DIS
#define TWI_GENERAL_CALL_RECOGNITION_STATUS                TWI_DIS
#define TWI_ACKNOWLEDGE_STATUS                             TWI_EN
#define TWI_PRESCALER                                      TWI_PRESCALER_1
#define TWI_SCL_FREQUENCY                                  100000UL
#define TWI_CPU_FREQUENCY                                  8000000UL




#endif
