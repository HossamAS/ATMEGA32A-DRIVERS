/**************************************/
/* Description : LCD private c File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 00:44:06  12 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

typedef struct{
  struct {
	 uint8_kt  u8Rs;
	 uint8_kt  u8RW;
	 uint8_kt  u8En;
  }LcdCtrlPins_s;
  struct {
	  uint8_kt  u8Mode   			:1;
	  uint8_kt  u8UsedLines			:1;
	  uint8_kt  u8CharFont			:1;
	  uint8_kt  u8DisplayState		:1;
	  uint8_kt  u8CursorState		:1;
	  uint8_kt  u8CursorBlinkState	:1;
	  uint8_kt  u8IncrementMode		:1;
	  uint8_kt  u8ShiftMode			:1;
  }Config_s;
  	  uint8_kt 	au8LcdDataPins[8];
}LcdConfig_st;

ErrorStatus_et LCD_vLcdWriteHelper (uint8_kt u8LcdIndexCpy, uint8_kt u8CmdCpy);
ErrorStatus_et LCD_vLcdReadHelper (uint8_kt u8LcdIndexCpy, uint8_kt * pu8Cmd);
extern LcdConfig_st aLcdConfig_s[LCD_MAX_NUM];
#endif
