/**************************************/
/* Description : AC private h File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 03:31:39  13 Jun 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef AC_PRIVATE_H
#define AC_PRIVATE_H

typedef union{
	uint8_kt REG;
	struct{
		uint8_kt :3;
		uint8_kt ACME:1;
	};
}SFIOR_ut;



typedef union{
	uint8_kt REG;
	uint8_kt ACIS:2;
	struct{
		uint8_kt ACIS0:1;
		uint8_kt ACIS1:1;
		uint8_kt ACIC:1;
		uint8_kt ACIE:1;
		uint8_kt ACI:1;
		uint8_kt ACO:1;
		uint8_kt ACBG:1;
		uint8_kt ACD:1;

	};
}ACSR_ut;
typedef union{
	uint8_kt REG;
    uint8_kt MUX:3;
    struct{
        uint8_kt MUX0:1;
        uint8_kt MUX1:1;
        uint8_kt MUX2:1;
    };

}ADMUX_ut;
typedef union{
	uint8_kt REG;
    struct{
        uint8_kt :7;
        uint8_kt ADEN:1;
    };
}ADCSRA_ut;
typedef struct{
	ADCSRA_ut ADCSRA;
	ADMUX_ut ADMUX;
	ACSR_ut ACSR;
	uint8_kt RESERVED[39];
	SFIOR_ut SFIOR;
}AC_st;


#define AC  ((volatile AC_st*)(0x26))
extern pf AC_pfCallBack;
extern uint8_kt *pu8Output;


#endif
