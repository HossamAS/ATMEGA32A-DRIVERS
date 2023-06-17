/**************************************/
/* Description : DIO header File      */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 06:51:41  02 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef DIO_H
#define DIO_H

#define DIO_HIGH  1
#define DIO_LOW   0

#define DIO_INPUT  0
#define DIO_OUTPUT 1

#define DIO_ENABLE  1
#define DIO_DISABLE 0

typedef enum
{
PORTA,
PORTB,
PORTC,
PORTD
}Port_et;

#define DIO_PIN_NUM_0   0
#define DIO_PIN_NUM_1   1
#define DIO_PIN_NUM_2   2
#define DIO_PIN_NUM_3   3
#define DIO_PIN_NUM_4   4
#define DIO_PIN_NUM_5   5
#define DIO_PIN_NUM_6   6
#define DIO_PIN_NUM_7   7
#define DIO_PIN_NUM_8   8
#define DIO_PIN_NUM_9   9
#define DIO_PIN_NUM_10  10
#define DIO_PIN_NUM_11  11
#define DIO_PIN_NUM_12  12
#define DIO_PIN_NUM_13  13
#define DIO_PIN_NUM_14  14
#define DIO_PIN_NUM_15  15
#define DIO_PIN_NUM_16  16
#define DIO_PIN_NUM_17  17
#define DIO_PIN_NUM_18  18
#define DIO_PIN_NUM_19  19
#define DIO_PIN_NUM_20  20
#define DIO_PIN_NUM_21  21
#define DIO_PIN_NUM_22  22
#define DIO_PIN_NUM_23  23
#define DIO_PIN_NUM_24  24
#define DIO_PIN_NUM_25  25
#define DIO_PIN_NUM_26  26
#define DIO_PIN_NUM_27  27
#define DIO_PIN_NUM_28  28
#define DIO_PIN_NUM_29  29
#define DIO_PIN_NUM_30  30
#define DIO_PIN_NUM_31  31


/*pre-build Configuration*/
void DIO_vInit(void);/*a function to initialize all DIO pins*/
/*post-build Configuration*/
ErrorStatus_et    DIO_enuPinDir(uint8_kt u8PinNumCpy,uint8_kt u8DirCpy);/*a function to initialize the directions of a specific output pin*/
ErrorStatus_et DIO_enuPinAttach(uint8_kt u8PinNumCpy,uint8_kt u8PinAttachStateCpy);/*a function to initialize the Pin Attachment State of a specific intput pin*/
/*APIs*/
/* 1- Main APIs */
ErrorStatus_et  DIO_enuWrite(uint8_kt u8PinNumCpy,uint8_kt u8PinValueCpy);/*a function that writes the state of a specific output pin*/
ErrorStatus_et   DIO_enuRead(uint8_kt u8PinNumCpy,uint8_kt  *pu8PinValue);/*a function that reads the state of a specific intput pin*/
ErrorStatus_et DIO_enuToggle(uint8_kt u8PinNumCpy);/*a function that toggle the state of a specific output pin*/
/* 2- Derived APIs */
ErrorStatus_et  DIO_enuWriteGroup(uint8_kt au8PinsNums[],uint8_kt au8PinsValues[],uint8_kt u8TotalPinsCpy);/*a function that writes the state of a group of output pins*/
ErrorStatus_et   DIO_enuReadGroup(uint8_kt au8PinsNums[],uint8_kt au8PinsValues[],uint8_kt u8TotalPinsCpy);/*a function that reads the state of a group of input pins*/
ErrorStatus_et DIO_enuToggleGroup(uint8_kt au8PinsNums[],uint8_kt u8TotalPinsCpy);/*a function that toggle the state of a group of output pins*/

ErrorStatus_et  DIO_enuWriteGroupV2(uint8_kt au8PinsNums[],uint32_kt u32PinsValues,uint8_kt u8TotalPinsCpy);/*a function that writes the state of a group of output pins*/
ErrorStatus_et   DIO_enuReadGroupV2(uint8_kt au8PinsNums[],uint32_kt *pu32PinsValues,uint8_kt u8TotalPinsCpy);/*a function that reads the state of a group of input pins*/


ErrorStatus_et   DIO_enuWritePort( Port_et PortNumCpy_e,uint8_kt  u8PinValueCpy);/*a function that writes the state of a port output pins*/
ErrorStatus_et    DIO_enuReadPort( Port_et PortNumCpy_e,uint8_kt   *pu8PinValue);/*a function that reads the state of a port input pins*/
ErrorStatus_et  DIO_enuTogglePort( Port_et PortNumCpy_e);/*a function that toggle the state of a port output pins*/
								 
          void    DIO_enuWriteDIO(uint32_kt u8DoValueCpy);/*a function that writes the state of all DIO output pins*/
ErrorStatus_et     DIO_enuReadDIO(uint32_kt   *u8DiValue);/*a function that reads the state of all DIO input pins*/
          void   DIO_enuToggleDIO(void);/*a function that toggle the state of all DIO output pins*/
          void      DIO_enuClrDIO(void);/*a function that Clear the state of all DIO output pins*/





#endif
