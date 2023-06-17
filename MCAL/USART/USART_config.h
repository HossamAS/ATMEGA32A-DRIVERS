/**************************************/
/* Description : USART config c File  */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:09:52  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define TRANSMITTER_STATUS                                 USART_EN
#define RECEIVER_STATUS                                    USART_EN
#define DATA_REGISTER_EMPTY_INTTERRUPT_STATUS              USART_DIS
#define TX_COMPLETE_INTTERUPT_STATUS                       USART_DIS
#define RX_COMPLETE_INTERRUPT_STATUS                       USART_DIS
#define CHARACTER_SIZE                                     USART_8_BITS_CHAR
#define DOUBLE_SPEED                                       USART_EN
#define USART_MODE                                         USART_ASYNCHRONOUS
#define PARITY_MODE                                        USART_PARITY_DIS
#define STOP_BITS                                          USART_1_STOP_BITS
#define CLOCK_POLARITY									   USART_SETUP_AT_RISING_EDGE_SAMPLE_AT_FALLING_EDGE
#define MULTI_PROCESSOR_COMMUNICATION_MODE                 USART_DIS
#define BUAD_RATE                                          9600UL
#define CPU_FREQUENCY                                      8000000UL
#define ASYNC_RECEIVEING                                   USART_EN





#endif
