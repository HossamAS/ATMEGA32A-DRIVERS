/**************************************/
/* Description : Sev Seg config h File*/
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 10:52:34  03 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/


#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SEV_SEG_config.h"
#include "SEV_SEG_interface.h"
#include "SEV_SEG_private.h"

SevSegConfig_st aSevSegConfig_s[SEV_SEG_NUM_MAX]={
		{
				{
					    /*a*/           /*b*/           /*c*/					
					DIO_PIN_NUM_0,	DIO_PIN_NUM_1,	DIO_PIN_NUM_2,
					    /*d*/           /*e*/           /*f*/
					DIO_PIN_NUM_3,	DIO_PIN_NUM_4,	DIO_PIN_NUM_5,
					    /*g*/        /*Common*/       /*dot*/
					DIO_PIN_NUM_6,	DIO_PIN_NUM_7,  DIO_PIN_NUM_8
				},
					COMMON_CATHODE,

					DOT_ON
		},
		{
				{
					    /*a*/           /*b*/           /*c*/
					DIO_PIN_NUM_9,	DIO_PIN_NUM_10,	DIO_PIN_NUM_11,
					    /*d*/           /*e*/           /*f*/
					DIO_PIN_NUM_12,	DIO_PIN_NUM_13,	DIO_PIN_NUM_14,
					    /*g*/        /*Common*/
					DIO_PIN_NUM_15, DIO_PIN_NUM_16
				},
					COMMON_CATHODE,

					DOT_OFF
		},

};
