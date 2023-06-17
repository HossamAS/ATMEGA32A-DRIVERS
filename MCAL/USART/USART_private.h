/**************************************/
/* Description : USART private h File */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:09:52  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef union{
	uint8_kt REG;
	struct{
		uint8_kt TXB8:1;
		uint8_kt RXB8:1;
		uint8_kt UCSZ2:1;
		uint8_kt TXEN:1;
		uint8_kt RXEN:1;
		uint8_kt UDRIE:1;
		uint8_kt TXCIE:1;
		uint8_kt RXCIE:1;
	};
}UCSRB_ut;

typedef union{
	uint8_kt REG;
	struct{
		uint8_kt MPCM:1;
		uint8_kt U2X:1;
		uint8_kt PE:1;
		uint8_kt DOR:1;
		uint8_kt FE:1;
		uint8_kt UDRE:1;
		uint8_kt TXC:1;
		uint8_kt RXC:1;
	};

}UCSRA_ut;
typedef union{
	uint8_kt REG;
	struct{
		uint8_kt :1;
		uint8_kt UCSZ0_1:2;
		uint8_kt :1;
		uint8_kt UPM:2;
	};
		struct{
			uint8_kt UCPOL:1;
			uint8_kt UCSZ0:1;
			uint8_kt UCSZ1:1;
			uint8_kt USBS:1;
			uint8_kt UPM0:1;
			uint8_kt UPM1:1;
			uint8_kt UMSEL:1;
			uint8_kt URSEL:1;
		};
}UCSRC_ut;
typedef union{
	uint8_kt REG;
	uint8_kt Bits8_to_11:4;
	struct{
		uint8_kt Bit8:1;
		uint8_kt Bit9:1;
		uint8_kt Bit10:1;
		uint8_kt Bit11:1;
		uint8_kt :3;
		uint8_kt URSEL:1;
	};
}UBRRH_ut;


typedef struct{
	uint8_ut UBRRL;
	UCSRB_ut UCSRB;
	UCSRA_ut UCSRA;
	uint8_ut UDR;
	uint8_kt Recerved[19];
	union{
		UCSRC_ut UCSRC;
		UBRRH_ut UBRRH;
	};

}USART_st;


#define USART (*(volatile USART_st*)(0x29))

pf RXC_CallBack=NULL_PTR;
pf UDRE_CallBack=NULL_PTR;
pf TXC_CallBack=NULL_PTR;

uint8_kt * pu8USART_AsyncByte=NULL_PTR;
#endif
