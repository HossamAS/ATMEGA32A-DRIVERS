/**************************************/
/* Description : TIM2 private h File  */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 12:06:30  16 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef TIM2_PRIVATE_H
#define TIM2_PRIVATE_H

typedef union{
		uint8_kt REG;
		struct{
		uint8_kt CS2:3;
		uint8_kt WGM2_COM2:4;
		};
		struct{
			uint8_kt CS20:1;
			uint8_kt CS21:1;
			uint8_kt CS22:1;
			uint8_kt WGM21:1;
			uint8_kt COM20:1;
			uint8_kt COM21:1;
			uint8_kt WGM20:1;
			uint8_kt FOC2:1;
		};



}TCCR0_ut;
typedef union{
		uint8_kt REG;
		struct{
		uint8_kt :6;
		uint8_kt TOIE2:1;
		uint8_kt OCIE2:1;
		};

} TIMSK2_ut;
typedef union{
		uint8_kt REG;
		struct{
		uint8_kt :6;
		uint8_kt TOV2:1;
		uint8_kt OCF2:1;
		};

} TIFR_ut;

typedef union{
		uint8_kt REG;
		struct{
		uint8_kt TCR2UB:1;
		uint8_kt OCR2UB:1;
		uint8_kt TCN2UB:1;
		uint8_kt AS2:1;
		};

} ASSR_ut;

typedef struct{
	ASSR_ut  ASSR;
	uint8_ut OCR2;
	uint8_ut TCNT2;
	TCCR0_ut TCCR2;
	uint8_kt RESERVED[19];
	TIFR_ut  TIFR;
	TIMSK2_ut TIMSK2;
}TIMER2_st;

#define TIM2 (*(volatile TIMER2_st*)(0x42))
pf OVF2_CallBack=NULL_PTR;
pf OCM2_CallBack=NULL_PTR;
#endif
