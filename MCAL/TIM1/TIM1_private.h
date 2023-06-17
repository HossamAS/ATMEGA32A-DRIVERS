/**************************************/
/* Description : TIM1 private h File  */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 17:10:42  23 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM1_PRIVATE_H
#define TIM1_PRIVATE_H

typedef union
{
	uint8_kt REG;
	struct{
		uint8_kt CS1:3;
		uint8_kt WGM13_12:2;
	};
	struct{
		uint8_kt CS10:1;
		uint8_kt CS11:1;
		uint8_kt CS12:1;
		uint8_kt WGM12:1;
		uint8_kt WGM13:1;
		uint8_kt :1;
		uint8_kt ICES1:1;
		uint8_kt ICNC1:1;
	};
}TCCR1B_ut;
typedef union
{
	uint8_kt REG;
	struct{
		uint8_kt WGM11_10:2;
		uint8_kt :2;
		uint8_kt COM1B:2;
		uint8_kt COM1A:2;
	};
	struct{
	 uint8_kt WGM10:1;
	 uint8_kt WGM11:1;
	 uint8_kt FOC1B:1;
	 uint8_kt FOC1A:1;
	 uint8_kt COM1B0:1;
	 uint8_kt COM1B1:1;
	 uint8_kt COM1A0:1;
	 uint8_kt COM1A1:1;
	};
}TCCR1A_ut;
typedef union{
	uint8_kt REG;
		struct{
		uint8_kt :2;
		uint8_kt TOIE1:1;
		uint8_kt OCIE1B:1;
		uint8_kt OCIE1A:1;
		uint8_kt TICIE1:1;
		};

} TIMSK1_ut;
typedef union{
	uint8_kt REG;
		struct{
		uint8_kt :2;
		uint8_kt TOV1:1;
		uint8_kt OCF1B:1;
		uint8_kt OCIE1A:1;
		uint8_kt TICIE1:1;
		};

} TIFR_ut;
typedef union{
	uint16_kt REG;
		struct{
		uint8_ut ICR1L;
		uint8_ut ICR1H;
		};

} ICR1_ut;

typedef union{
	uint16_kt REG;
		struct{
		uint8_ut OCR1BL;
		uint8_ut OCR1BH;
		};

} OCR1B_ut;
typedef union{
	uint16_kt REG;
		struct{
		uint8_ut OCR1AL;
		uint8_ut OCR1AH;
		};

} OCR1A_ut;
typedef union{
	uint16_kt REG;
		struct{
		uint8_ut TCNT1L;
		uint8_ut TCNT1H;
		};

} TCNT1_ut;
typedef struct{
	ICR1_ut    ICR1;        
	OCR1B_ut   OCR1B;       
	OCR1A_ut   OCR1A;       
	TCNT1_ut   TCNT1;       
	TCCR1B_ut  TCCR1B;      
	TCCR1A_ut  TCCR1A;      
	uint8_kt RESERVED[8];   
	TIFR_ut    TIFR;        
	TIMSK1_ut   TIMSK1;
}TIM1_st;

#define TIM1 (*(volatile TIM1_st*)(0x46))

extern pf OVF1_CallBack;
extern pf OCM1A_CallBack;
extern pf OCM1B_CallBack;
extern pf ICU1_CallBack;
































#endif
