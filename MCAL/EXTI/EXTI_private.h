/**************************************/
/* Description : EXTI private File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 03:51:08  13 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef EXTI_PRIV_H
#define EXTI_PRIV_H


typedef union {
	uint8_kt :6;
	uint8_kt ISC2:1;
	uint8_kt :1;
}MCUCSR_ut;

typedef union {
	uint8_kt REG;
		struct{
			uint8_kt ISC0:2;
			uint8_kt ISC1:2;
		};

		struct{
			uint8_kt ISC00:1;
			uint8_kt ISC01:1;
			uint8_kt ISC10:1;
			uint8_kt ISC11:1;
		};

}MCUCR_ut;

typedef union {
	struct{
	uint8_kt :5;
	uint8_kt GIFR:3;
	};
		struct{
			uint8_kt :5;
			uint8_kt INTF2:1;
			uint8_kt INTF0:1;
			uint8_kt INTF1:1;
		};


}GIFR_ut;

typedef union {
	struct{
	uint8_kt :5;
	uint8_kt GICR:3;
	};
		struct{
			uint8_kt :5;
			uint8_kt INT2:1;
			uint8_kt INT0:1;
			uint8_kt INT1:1;
		};


}GICR_ut;

typedef struct {
	MCUCSR_ut MCUCSR;
	MCUCR_ut MCUCR;
	uint32_kt :32;
	GIFR_ut GIFR;
	GICR_ut GICR;
}INT_st;




#define INT ((volatile INT_st*)(0X54))
pf INT0_CallBack;
pf INT1_CallBack;
pf INT2_CallBack;

#endif
