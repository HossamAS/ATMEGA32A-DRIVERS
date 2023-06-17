/**************************************/
/* Description : DIO private c File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 06:51:41  02 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef DIO_PRIV_H
#define DIO_PRIV_H


typedef struct {
	uint8_ut IDR;
	uint8_ut DDR;
	uint8_ut ODR;
}DIO_st;
typedef struct {
	DIO_st D;
	DIO_st C;
	DIO_st B;
	DIO_st A;
}GPIO_st;



#define GPIO ((volatile GPIO_st*)(0x30))

/*
#define DDRA  *((volatile uint8_kt*)(0x3A))
#define DDRB  *((volatile uint8_kt*)(0x37))
#define DDRC  *((volatile uint8_kt*)(0x34))
#define DDRD  *((volatile uint8_kt*)(0x31))
									 
#define IDRA  *((volatile uint8_kt*)(0x39))
#define IDRB  *((volatile uint8_kt*)(0x36))
#define IDRC  *((volatile uint8_kt*)(0x33))
#define IDRD  *((volatile uint8_kt*)(0x30))
									 
#define ODRA  *((volatile uint8_kt*)(0x3B))
#define ODRB  *((volatile uint8_kt*)(0x38))
#define ODRC  *((volatile uint8_kt*)(0x35))
#define ODRD  *((volatile uint8_kt*)(0x32))
*/
#define CONC(Bit7,Bit6,Bit5,Bit4,Bit3,Bit2,Bit1,Bit0)  ((Bit7<<7)|(Bit6<<6)|(Bit5<<5)|(Bit4<<4)|(Bit3<<3)|(Bit2<<2)|(Bit1<<1)|Bit0)

ErrorStatus_et DetectMultiOccurance(uint8_kt au8Arr[],uint8_kt au8ArrLengthCpy);

#endif
