/**************************************/
/* Description : USART interface File */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:09:52  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H




/*pre-build configuration (preprocessor)*/
void USART_vInit(void);
/*run-time configuration*/
void USART_vTransmitter_En(void);
void USART_vTransmitter_Dis(void);
void USART_vReceiver_En(void);
void USART_vReceiver_Dis(void);
void USART_vDataRegEmptyInt_En(void);
void USART_vDataRegEmptyInt_Dis(void);
void USART_vTX_CompleteInt_En(void);
void USART_vTX_CompleteInt_Dis(void);
void USART_vRX_CompleteInt_En(void);
void USART_vRX_CompleteInt_Dis(void);
void USART_vDoubleSpeed_En(void);
void USART_vDoubleSpeed_Dis(void);
void USART_vMultiProcessorComMode_En(void);
void USART_vMultiProcessorComMode_Dis(void);
ErrorStatus_et USART_enuCharSize(uint8_kt u8CharSizeCpy);
ErrorStatus_et USART_enuParityMode(uint8_kt u8ParityModeCpy);
ErrorStatus_et USART_enuMode(uint8_kt u8ModeCpy);
ErrorStatus_et USART_enuStopBits(uint8_kt u8StopBitsCpy);
ErrorStatus_et USART_enuClkPolarity(uint8_kt u8ClkPolarityCpy);
void USART_enuBaudRate(uint16_kt u16BaudRateCpy);
/*APIs*/
void USART_vSendChar(uint8_kt u8CharCpy);
void USART_vSyncReceiveChar(uint8_kt* pu8Char);
ErrorStatus_et USART_enuAsyncReceiveChar(uint8_kt* pu8Char);



/**************************configuration options**************************/
/*USART modes*/
#define USART_ASYNCHRONOUS 0
#define USART_SYNCHRONOUS  1

/*parity mode*/
#define USART_PARITY_DIS     0
#define USART_EVEN_PARITY_EN 2
#define USART_ODD_PARITY_EN  3

/*character size*/
#define USART_5_BITS_CHAR  0
#define USART_6_BITS_CHAR  1
#define USART_7_BITS_CHAR  2
#define USART_8_BITS_CHAR  3
#define USART_9_BITS_CHAR  7

/*stop bits size*/
#define USART_1_STOP_BITS  0
#define USART_2_STOP_BITS  1

/*clock polarity*/
#define USART_SETUP_AT_RISING_EDGE_SAMPLE_AT_FALLING_EDGE 0
#define USART_SETUP_AT_FALLING_EDGE_SAMPLE_AT_RISING_EDGE 1

/*enable and disable options*/
#define USART_DIS 0
#define USART_EN  1
/*UCSRC or UBRRH register select*/
#define USART_SELECT_UBRRH 0
#define USART_SELECT_UCSRC 1



#endif
