/**************************************/
/* Description : ADC private h File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 11:03:51  12 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

typedef union{
	unsigned short int  REG;
	struct{
	uint8_kt ADCL;
	uint8_kt ADCH;
	};
}ADCDR_ut;

typedef union{
	uint8_kt REG;
	uint8_kt ADPS:3;
    struct{
        uint8_kt ADPS0:1;
        uint8_kt ADPS1:1;
        uint8_kt ADPS2:1;
        uint8_kt ADIE:1;
        uint8_kt ADIF:1;
        uint8_kt ADATE:1;
        uint8_kt ADSC:1;
        uint8_kt ADEN:1;
    };

}ADCSRA_ut;

typedef union{
	uint8_kt REG;
    uint8_kt MUX:5;
    struct{
        uint8_kt :6;
        uint8_kt REFS:2;
    };
    struct{
        uint8_kt MUX0:1;
        uint8_kt MUX1:1;
        uint8_kt MUX2:1;
        uint8_kt MUX3:1;
        uint8_kt MUX4:1;
        uint8_kt ADLAR:1;
        uint8_kt REFS0:1;
        uint8_kt REFS1:1;
    };

}ADMUX_ut;

typedef union{
	uint8_kt REG;
	struct{
        uint8_kt     :5;
        uint8_kt ADTS:3;
	};
    struct{
        uint8_kt     :5;
        uint8_kt ADTS0:1;
		uint8_kt ADTS1:1;
		uint8_kt ADTS2:1;
    };
}SFIOR_ut;


typedef struct{
	ADCDR_ut ADCDR;
	ADCSRA_ut ADCSRA;
	ADMUX_ut ADMUX;
	uint8_kt RESERVED[41];
	SFIOR_ut SFIOR;
}ADC_st;


#define ADC ((volatile ADC_st*)(0x24))
pf ADC_CallBack=NULL_PTR;
uint16_kt* pu16AsyncValue=NULL_PTR;
#endif
