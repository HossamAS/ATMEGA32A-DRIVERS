/**************************************/
/* Description : TIM0 private h File  */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 12:06:30  16 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM0_PRIVATE_H
#define TIM0_PRIVATE_H

typedef union{
	uint8_kt REG;
		struct{
			uint8_kt CS0:3;
			uint8_kt WGM0_COM0:4;

		};
		struct{
			uint8_kt CS00:1;
			uint8_kt CS01:1;
			uint8_kt CS02:1;
			uint8_kt WGM01:1;
			uint8_kt COM00:1;
			uint8_kt COM01:1;
			uint8_kt WGM00:1;
			uint8_kt FOC0:1;
		};



}TCCR0_ut;
typedef union{
	uint8_kt REG;
		struct{
		uint8_kt TOIE0:1;
		uint8_kt OCIE0:1;
		};

} TIMSK_ut;
typedef union{
	uint8_kt REG;
		struct{
		uint8_kt TOV0:1;
		uint8_kt OCF0:1;
		};

} TIFR_ut;

typedef struct{
	uint8_ut TCNT0;
	TCCR0_ut TCCR0;
	uint8_kt RESERVED[4];
	TIFR_ut  TIFR;
	TIMSK_ut TIMSK;
	uint8_kt RESERVED2[2];
	uint8_ut OCR0;
}TIMER0_st;

#define TIM0 ((volatile TIMER0_st*)(0x52))
pf OVF0_CallBack=NULL_PTR;
pf OCM0_CallBack=NULL_PTR;
#endif
