/**************************************/
/* Description : SPI private h File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:09:22  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef union{
	uint8_kt REG;
	uint8_kt SPR:2;
	struct{
		uint8_kt SPR0:1;
		uint8_kt SPR1:1;
		uint8_kt CPHA:1;
		uint8_kt CPOL:1;
		uint8_kt MSTR:1;
		uint8_kt DORD:1;
		uint8_kt SPE:1;
		uint8_kt SPIE:1;

	};
}SPCR_ut;

typedef union{
	uint8_kt REG;
	struct{
		uint8_kt SPI2X:1;
		uint8_kt :5;
		uint8_kt WCOL:1;
		uint8_kt SPIF:1;
	};
}SPSR_ut;

typedef struct{
	SPCR_ut  SPCR;
	SPSR_ut  SPSR;
	uint8_ut SPDR;
}SPI_st;


#define SPI (*(volatile SPI_st*)(0x2D))


extern pf STC_CallBack;
extern uint8_kt * pu8SPI_AsyncByte;




#endif
