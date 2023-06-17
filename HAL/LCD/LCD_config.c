/**************************************/
/* Description : LCD config h File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 00:44:06  12 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "../../MCAL/DIO/DIO_interface.h"
LcdConfig_st aLcdConfig_s[LCD_MAX_NUM]=
{
		{
			{
				DIO_PIN_NUM_24,DIO_PIN_NUM_25,DIO_PIN_NUM_26
			}
			,
			{
				LCD_4BIT_MODE,LCD_TWO_LINES,LCD_FONT_5X7,
				LCD_DISPLAY_ON,LCD_CURSOR_ON,LCD_CURSOR_BLINK_ON,
				LCD_LTR,LCD_SHIFT_OFF
			}
			,
			{

					DIO_PIN_NUM_27,DIO_PIN_NUM_28,DIO_PIN_NUM_29,
					DIO_PIN_NUM_30
			}
		}
};
