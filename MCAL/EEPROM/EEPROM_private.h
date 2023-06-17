/**************************************/
/* Description : EEPROM private h File*/
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 21:17:13  22 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef EEPROM_PRIVATE_H
#define EEPROM_PRIVATE_H



typedef union{
	uint8_kt REG;
	struct{
		uint8_kt :1;
		uint8_kt EEWE_EEMWE:2;
	};

	struct{
		uint8_kt EERE:1;
		uint8_kt EEWE:1;
		uint8_kt EEMWE:1;
		uint8_kt EERIE:1;
	};
}EECR_ut;
typedef union{
	uint16_kt REG:10;
	struct{
		uint8_kt EEARL;
		uint8_kt EEARH:2;
	};
}EEAR_ut;

typedef union{
	uint8_kt REG;
	struct{
		uint8_kt SPMEN:1;

	};
}SPMCR_1_ut;

typedef struct{
	EECR_ut EECR;
	uint8_ut EEDR;
	EEAR_ut EEAR;
	uint8_kt RECERVED[23];
	SPMCR_1_ut SPMCR;
}EEPROM_st;

#define EEPROM (*(volatile EEPROM_st*)(0x3c))

extern pf EE_RDY_CallBack;









#endif
