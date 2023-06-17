/**************************************/
/* Description : I2C private h File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:10:06  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

typedef union{
	uint8_kt REG;
	struct{
		uint8_kt TWPS:2;
		uint8_kt :1;
		uint8_kt TWS:5;
	};
	struct{
		uint8_kt TWPS0:1;
		uint8_kt TWPS1:1;
		uint8_kt :1;
		uint8_kt TWS3:1;
		uint8_kt TWS4:1;
		uint8_kt TWS5:1;
		uint8_kt TWS6:1;
		uint8_kt TWS7:1;
	};
}TWSR_ut;
typedef union{
	uint8_kt REG;
	struct{
		uint8_kt :1;
		uint8_kt TWA:7;
	};
	struct{
		uint8_kt TWGCE:1;
		uint8_kt TWA0:1;
		uint8_kt TWA1:1;
		uint8_kt TWA2:1;
		uint8_kt TWA3:1;
		uint8_kt TWA4:1;
		uint8_kt TWA5:1;
		uint8_kt TWA6:1;
	};
}TWAR_ut;

typedef union{
	uint8_kt REG;
	struct{
		uint8_kt TWIE:1;
		uint8_kt :1;
		uint8_kt TWEN:1;
		uint8_kt TWWC:1;
		uint8_kt TWSTO:1;
		uint8_kt TWSTA:1;
		uint8_kt TWEA:1;
		uint8_kt TWINT:1;
	};
}TWCR_ut;

typedef struct{
	uint8_ut TWBR;
	TWSR_ut  TWSR;
	TWAR_ut  TWAR;
	uint8_ut TWDR;
	uint8_kt RESERVED[50];
	TWCR_ut TWCR;
}TWI_st;

#define TWI (*(volatile TWI_st*)(0X20))


pf TWI_CallBack=NULL_PTR;
uint8_kt * u8TWI_Data=NULL_PTR;








#endif
