/**************************************/
/* Description : SPI interface File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:09:22  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef SPI_INTERFACESPI_H
#define _INTERFACE_H

/* pre-build configuration (pre-processing)*/
void SPI_vInit(void);
/* run-time configuration */
void SPI_vIntEn(void);
void SPI_vIntDis(void);
void SPI_vEn(void);
void SPI_vDis(void);
ErrorStatus_et SPI_enuDataOrder(uint8_kt u8DataOrderCpy);
ErrorStatus_et SPI_enuAuthority(uint8_kt u8AuthorityCpy);
ErrorStatus_et SPI_enuClkPolarity(uint8_kt u8ClkPolarityCpy);
ErrorStatus_et SPI_enuClkPhase(uint8_kt u8ClkPhaseCpy);
ErrorStatus_et SPI_enuPrescaler(uint8_kt u8PrescalerCpy);
ErrorStatus_et SPI_enuSetCallBack(pf pfCallBack);
/*APIs*/
void SPI_vSendByte(uint8_kt u8ByteCpy);
void SPI_vSyncReadRecievedByte(uint8_kt* pu8Byte);
ErrorStatus_et SPI_vAsyncReadRecievedByte(uint8_kt* pu8Byte);


/************************************configuration options*******************************/
/*Interrupt Status*/
#define SPI_INT_DIS 0
#define SPI_INT_EN  1
/*SPI Status*/
#define SPI_DIS 0
#define SPI_EN  1
/* DataOrder */
#define SPI_MSB_FIRST 0
#define SPI_LSB_FIRST 1
/*Authority*/
#define SPI_SLAVE  0
#define SPI_MASTER 1
/*Clock Polarity*/
#define SPI_RISING_AT_LEADING_EDGE_AND_FALLING_AT_TRAILING_EDGE  0
#define SPI_FALLING_AT_LEADING_EDGE_AND_RISING_AT_TRAILING_EDGE  1
/*Clock Phase*/
#define SPI_SAMPLE_AT_LEADING_EDGE_AND_SETUP_AT_TRAILING_EDGE  0
#define SPI_SETUP_AT_LEADING_EDGE_AND_SAMPLE_AT_TRAILING_EDGE  1
/*Prescaler*/
#define SPI_CLK_PER_4   0
#define SPI_CLK_PER_16  1
#define SPI_CLK_PER_64  2
#define SPI_CLK_PER_128 3
#define SPI_CLK_PER_2   4
#define SPI_CLK_PER_8   5
#define SPI_CLK_PER_32  6






#endif
