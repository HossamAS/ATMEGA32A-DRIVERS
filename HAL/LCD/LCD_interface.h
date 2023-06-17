/**************************************/
/* Description : LCD interface h File */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 00:44:06  12 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"




/*PRE_BUILD CONFIGURATION (LINKING)*/
ErrorStatus_et LCD_vInit (void);
/*MOST USED APIs*/
ErrorStatus_et LCD_enuSendCmd (uint8_kt u8LcdIndexCpy, uint8_kt u8CmdCpy);
ErrorStatus_et LCD_vDispChar (uint8_kt u8LcdIndexCpy, uint8_kt u8CharCpy);
ErrorStatus_et LCD_vSelectDispPos (uint8_kt u8LcdIndexCpy, uint8_kt u8PosCpy);
ErrorStatus_et LCD_vReadDispChar (uint8_kt u8LcdIndexCpy, uint8_kt * pu8CharCpy);
ErrorStatus_et LCD_vReadBfAndAddress (uint8_kt u8LcdIndexCpy, uint8_kt * pu8BfAndAddressCpy);
/*ADVANCED APIs*/
ErrorStatus_et LCD_enuClearDisp (uint8_kt u8LcdIndexCpy);
ErrorStatus_et LCD_enuRetHome(uint8_kt u8LcdIndexCpy);
ErrorStatus_et LCD_enuDispString(uint8_kt u8LcdIndexCpy,uint8_kt* pu8String);
ErrorStatus_et LCD_enuDispArr(uint8_kt u8LcdIndexCpy,uint8_kt* pu8Arr,uint8_kt u8LengthCpy);
/*==========options===============*/
#define LCD_4BIT_MODE    0
#define LCD_8BIT_MODE    1

#define LCD_ONE_LINE    0
#define LCD_TWO_LINES   1

#define LCD_FONT_5X7    0
#define LCD_FONT_5X11   1

#define LCD_DISPLAY_OFF 0
#define LCD_DISPLAY_ON  1

#define LCD_CURSOR_OFF       0
#define LCD_CURSOR_ON        1


#define LCD_CURSOR_BLINK_OFF       0
#define LCD_CURSOR_BLINK_ON        1

#define LCD_RTL        0
#define LCD_LTR        1

#define LCD_SHIFT_OFF      0
#define LCD_SHIFT_ON       1





#endif
