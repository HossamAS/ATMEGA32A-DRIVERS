/**************************************/
/* Description : Keypad config h File */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 01:37:24  09 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "../../MCAL/DIO/DIO_interface.h"

KeypadConfig_st au8KeypadConfig_s[KEYPAD_MAX_NUM]={
    /*Keypad 0 Config*/
	{
/*Outputs pins 	  ROW0            ROW1            ROW2            ROW3       */
			{ DIO_PIN_NUM_0 , DIO_PIN_NUM_1 , DIO_PIN_NUM_2 , DIO_PIN_NUM_3  },
/*Inputs pins     COLUMN0         COLUMN1         COLUMN2         COLUMN3    */
			{ DIO_PIN_NUM_4 , DIO_PIN_NUM_5 , DIO_PIN_NUM_6 , DIO_PIN_NUM_7  }
		,
		   /*ROW NUM*/
			4
		,
		   /*COLUMN NUM*/
			4
		,
		{
			/*KEYPAD MATREX*/
			{ '7' , '8' , '9' , '/'  },
			{ '4' , '5' , '6' , 'X'  },
			{ '1' , '2' , '3' , '-'  },
			{ '.' , '0' , '=' , '+'  }
		}


	}
//	,
	/*Keypad 1 Config*/
//	{
/*Input pins 	  ROW0            ROW1            ROW2            ROW3       */
//			{ DIO_PIN_NUM_16, DIO_PIN_NUM_17, DIO_PIN_NUM_18, DIO_PIN_NUM_19 },
/*Output pins     COLUMN0         COLUMN1         COLUMN2    */
//			{ DIO_PIN_NUM_20, DIO_PIN_NUM_21, DIO_PIN_NUM_22 }
//		,
			/*ROW NUM*/
//			4
//		,
		   /*COLUMN NUM*/
//			3
//		,
//		{
			/*KEYPAD MATREX*/
//			{ 'A' , 'B' , 'C'},
//			{ 'D' , 'E' , 'F'},
//			{ '^' , '~' , '!'},
//			{ '&' , '|' , '%'}
//		}

//	}
	
	
};
