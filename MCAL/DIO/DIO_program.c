/**************************************/
/* Description : DIO c File           */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 06:51:41  02 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"




void DIO_vInit(void)
{
	GPIO->A.DDR.REG=CONC(DIO_DIR_PIN7,DIO_DIR_PIN6,DIO_DIR_PIN5,DIO_DIR_PIN4,DIO_DIR_PIN3,DIO_DIR_PIN2,DIO_DIR_PIN1,DIO_DIR_PIN0);
	GPIO->B.DDR.REG=CONC(DIO_DIR_PIN15,DIO_DIR_PIN14,DIO_DIR_PIN13,DIO_DIR_PIN12,DIO_DIR_PIN11,DIO_DIR_PIN10,DIO_DIR_PIN9,DIO_DIR_PIN8);
	GPIO->C.DDR.REG=CONC(DIO_DIR_PIN23,DIO_DIR_PIN22,DIO_DIR_PIN21,DIO_DIR_PIN20,DIO_DIR_PIN19,DIO_DIR_PIN18,DIO_DIR_PIN17,DIO_DIR_PIN16);
	GPIO->D.DDR.REG=CONC(DIO_DIR_PIN31,DIO_DIR_PIN30,DIO_DIR_PIN29,DIO_DIR_PIN28,DIO_DIR_PIN27,DIO_DIR_PIN26,DIO_DIR_PIN25,DIO_DIR_PIN24);
	
	GPIO->A.ODR.REG=CONC((((DIO_IP_ATTACH_PIN7) &&(!DIO_DIR_PIN7 ))||((DIO_DIR_PIN7) &&(DIO_INIT_OP_VAL_PIN7) )),
	          (((DIO_IP_ATTACH_PIN6) &&(!DIO_DIR_PIN6 ))||((DIO_DIR_PIN6) &&(DIO_INIT_OP_VAL_PIN6) )),
			  (((DIO_IP_ATTACH_PIN5) &&(!DIO_DIR_PIN5 ))||((DIO_DIR_PIN5) &&(DIO_INIT_OP_VAL_PIN5) )),
			  (((DIO_IP_ATTACH_PIN4) &&(!DIO_DIR_PIN4 ))||((DIO_DIR_PIN4) &&(DIO_INIT_OP_VAL_PIN4) )),
			  (((DIO_IP_ATTACH_PIN3) &&(!DIO_DIR_PIN3 ))||((DIO_DIR_PIN3) &&(DIO_INIT_OP_VAL_PIN3) )),
			  (((DIO_IP_ATTACH_PIN2) &&(!DIO_DIR_PIN2 ))||((DIO_DIR_PIN2) &&(DIO_INIT_OP_VAL_PIN2) )),
			  (((DIO_IP_ATTACH_PIN1) &&(!DIO_DIR_PIN1 ))||((DIO_DIR_PIN1) &&(DIO_INIT_OP_VAL_PIN1) )),
			  (((DIO_IP_ATTACH_PIN0) &&(!DIO_DIR_PIN0 ))||((DIO_DIR_PIN0) &&(DIO_INIT_OP_VAL_PIN0) )));
			                         
	GPIO->B.ODR.REG=CONC((((DIO_IP_ATTACH_PIN15)&&(!DIO_DIR_PIN15))||((DIO_DIR_PIN15)&&(DIO_INIT_OP_VAL_PIN15))),
	          (((DIO_IP_ATTACH_PIN14)&&(!DIO_DIR_PIN14))||((DIO_DIR_PIN14)&&(DIO_INIT_OP_VAL_PIN14))),
			  (((DIO_IP_ATTACH_PIN13)&&(!DIO_DIR_PIN13))||((DIO_DIR_PIN13)&&(DIO_INIT_OP_VAL_PIN13))),
			  (((DIO_IP_ATTACH_PIN12)&&(!DIO_DIR_PIN12))||((DIO_DIR_PIN12)&&(DIO_INIT_OP_VAL_PIN12))),
			  (((DIO_IP_ATTACH_PIN11)&&(!DIO_DIR_PIN11))||((DIO_DIR_PIN11)&&(DIO_INIT_OP_VAL_PIN11))),
			  (((DIO_IP_ATTACH_PIN10)&&(!DIO_DIR_PIN10))||((DIO_DIR_PIN10)&&(DIO_INIT_OP_VAL_PIN10))),
			  (((DIO_IP_ATTACH_PIN9 )&&(!DIO_DIR_PIN9 ))||((DIO_DIR_PIN9 )&&(DIO_INIT_OP_VAL_PIN9 ) )),
			  (((DIO_IP_ATTACH_PIN8 )&&(!DIO_DIR_PIN8 ))||((DIO_DIR_PIN8 )&&(DIO_INIT_OP_VAL_PIN8 ) )));
			                         
	GPIO->C.ODR.REG=CONC((((DIO_IP_ATTACH_PIN23)&&(!DIO_DIR_PIN23))||((DIO_DIR_PIN23)&&(DIO_INIT_OP_VAL_PIN23))),
	          (((DIO_IP_ATTACH_PIN22)&&(!DIO_DIR_PIN22))||((DIO_DIR_PIN22)&&(DIO_INIT_OP_VAL_PIN22))),
			  (((DIO_IP_ATTACH_PIN21)&&(!DIO_DIR_PIN21))||((DIO_DIR_PIN21)&&(DIO_INIT_OP_VAL_PIN21))),
			  (((DIO_IP_ATTACH_PIN20)&&(!DIO_DIR_PIN20))||((DIO_DIR_PIN20)&&(DIO_INIT_OP_VAL_PIN20))),
			  (((DIO_IP_ATTACH_PIN19)&&(!DIO_DIR_PIN19))||((DIO_DIR_PIN19)&&(DIO_INIT_OP_VAL_PIN19))),
			  (((DIO_IP_ATTACH_PIN18)&&(!DIO_DIR_PIN18))||((DIO_DIR_PIN18)&&(DIO_INIT_OP_VAL_PIN18))),
			  (((DIO_IP_ATTACH_PIN17)&&(!DIO_DIR_PIN17))||((DIO_DIR_PIN17)&&(DIO_INIT_OP_VAL_PIN17))),
			  (((DIO_IP_ATTACH_PIN16)&&(!DIO_DIR_PIN16))||((DIO_DIR_PIN16)&&(DIO_INIT_OP_VAL_PIN16))));
			                                         
	GPIO->D.ODR.REG=CONC((((DIO_IP_ATTACH_PIN31)&&(!DIO_DIR_PIN31))||((DIO_DIR_PIN31)&&(DIO_INIT_OP_VAL_PIN31))),
	          (((DIO_IP_ATTACH_PIN30)&&(!DIO_DIR_PIN30))||((DIO_DIR_PIN30)&&(DIO_INIT_OP_VAL_PIN30))),
			  (((DIO_IP_ATTACH_PIN29)&&(!DIO_DIR_PIN29))||((DIO_DIR_PIN29)&&(DIO_INIT_OP_VAL_PIN29))),
			  (((DIO_IP_ATTACH_PIN28)&&(!DIO_DIR_PIN28))||((DIO_DIR_PIN28)&&(DIO_INIT_OP_VAL_PIN28))),
			  (((DIO_IP_ATTACH_PIN27)&&(!DIO_DIR_PIN27))||((DIO_DIR_PIN27)&&(DIO_INIT_OP_VAL_PIN27))),
			  (((DIO_IP_ATTACH_PIN26)&&(!DIO_DIR_PIN26))||((DIO_DIR_PIN26)&&(DIO_INIT_OP_VAL_PIN26))),
			  (((DIO_IP_ATTACH_PIN25)&&(!DIO_DIR_PIN25))||((DIO_DIR_PIN25)&&(DIO_INIT_OP_VAL_PIN25))),
			  (((DIO_IP_ATTACH_PIN24)&&(!DIO_DIR_PIN24))||((DIO_DIR_PIN24)&&(DIO_INIT_OP_VAL_PIN24))));

	
}
ErrorStatus_et DIO_enuPinDir   (uint8_kt u8PinNumCpy,uint8_kt u8DirCpy)
{
	ErrorStatus_et  ErrorStatusLoc_e=EOK;
	if((u8PinNumCpy>=0)&&(u8PinNumCpy<=7))
	{
        if(DIO_OUTPUT==u8DirCpy)
		{
			SET_BIT(GPIO->A.DDR.REG,u8PinNumCpy);
		}
        else if(DIO_INPUT==u8DirCpy)
		{
			CLR_BIT(GPIO->A.DDR.REG,u8PinNumCpy);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}	
	}
	else if((u8PinNumCpy>=8)&&(u8PinNumCpy<=15))
	{
        if(DIO_OUTPUT==u8DirCpy)
		{
			SET_BIT(GPIO->B.DDR.REG,u8PinNumCpy%8);
		}
        else if(DIO_INPUT==u8DirCpy)
		{
			CLR_BIT(GPIO->B.DDR.REG,u8PinNumCpy%8);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}	       
	}
	else if((u8PinNumCpy>=16)&&(u8PinNumCpy<=23))
	{     
        if(DIO_OUTPUT==u8DirCpy)
		{
			SET_BIT(GPIO->C.DDR.REG,u8PinNumCpy%8);
		}
        else if(DIO_INPUT==u8DirCpy)
		{
			CLR_BIT(GPIO->C.DDR.REG,u8PinNumCpy%8);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
	}
	else if((u8PinNumCpy>=24)&&(u8PinNumCpy<=31))
	{
        if(DIO_OUTPUT==u8DirCpy)
		{
			SET_BIT(GPIO->D.DDR.REG,u8PinNumCpy%8);
		}
        else if(DIO_INPUT==u8DirCpy)
		{
			CLR_BIT(GPIO->D.DDR.REG,u8PinNumCpy%8);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}	
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
	
}
ErrorStatus_et DIO_enuPinAttach(uint8_kt u8PinNumCpy,uint8_kt u8PinAttachStateCpy)
{
	
	ErrorStatus_et  ErrorStatusLoc_e=EOK;
	if((u8PinNumCpy>=9)&&(u8PinNumCpy<=7))
	{
        if(DIO_ENABLE==u8PinAttachStateCpy)
		{
			SET_BIT(GPIO->A.ODR.REG,u8PinNumCpy);
		}
        else if(DIO_DISABLE==u8PinAttachStateCpy)
		{
			CLR_BIT(GPIO->A.ODR.REG,u8PinNumCpy);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}	
	}
	else if((u8PinNumCpy>=8)&&(u8PinNumCpy<=15))
	{
        if(DIO_ENABLE==u8PinAttachStateCpy)
		{
			SET_BIT(GPIO->B.ODR.REG,u8PinNumCpy%8);
		}
        else if(DIO_DISABLE==u8PinAttachStateCpy)
		{
			CLR_BIT(GPIO->B.ODR.REG,u8PinNumCpy%8);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}	 
	}
	else if((u8PinNumCpy>=16)&&(u8PinNumCpy<=23))
	{ 
        if(DIO_ENABLE==u8PinAttachStateCpy)
		{
			SET_BIT(GPIO->C.ODR.REG,u8PinNumCpy%8);
		}
        else if(DIO_DISABLE==u8PinAttachStateCpy)
		{
			CLR_BIT(GPIO->C.ODR.REG,u8PinNumCpy%8);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}	
	}
	else if((u8PinNumCpy>=24)&&(u8PinNumCpy<=31))
	{
        if(DIO_ENABLE==u8PinAttachStateCpy)
		{
			SET_BIT(GPIO->C.ODR.REG,u8PinNumCpy%8);
		}
        else if(DIO_DISABLE==u8PinAttachStateCpy)
		{
			CLR_BIT(GPIO->C.ODR.REG,u8PinNumCpy%8);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}	
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
	
}
ErrorStatus_et DIO_enuWrite    (uint8_kt u8PinNumCpy,uint8_kt u8PinValueCpy)
{
	
	ErrorStatus_et  ErrorStatusLoc_e=EOK;
	if((u8PinNumCpy>=0)&&(u8PinNumCpy<=7))
	{
        if(DIO_HIGH==u8PinValueCpy)
		{
			SET_BIT(GPIO->A.ODR.REG,u8PinNumCpy);
		}
        else if(DIO_LOW==u8PinValueCpy)
		{
			CLR_BIT(GPIO->A.ODR.REG,u8PinNumCpy);
		}
		else
		{

			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}	
	}
	else if((u8PinNumCpy>=8)&&(u8PinNumCpy<=15))
	{
        if(DIO_HIGH==u8PinValueCpy)
		{
			SET_BIT(GPIO->B.ODR.REG,u8PinNumCpy%8);
		}
        else if(DIO_LOW==u8PinValueCpy)
		{
			CLR_BIT(GPIO->B.ODR.REG,u8PinNumCpy%8);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}	 
	}
	else if((u8PinNumCpy>=16)&&(u8PinNumCpy<=23))
	{ 
        if(DIO_HIGH==u8PinValueCpy)
		{
			SET_BIT(GPIO->C.ODR.REG,u8PinNumCpy%8);
		}
        else if(DIO_LOW==u8PinValueCpy)
		{
			CLR_BIT(GPIO->C.ODR.REG,u8PinNumCpy%8);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}	
	}
	else if((u8PinNumCpy>=24)&&(u8PinNumCpy<=31))
	{
        if(DIO_HIGH==u8PinValueCpy)
		{
			SET_BIT(GPIO->D.ODR.REG,u8PinNumCpy%8);
		}
        else if(DIO_LOW==u8PinValueCpy)
		{
			CLR_BIT(GPIO->D.ODR.REG,u8PinNumCpy%8);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}	
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
	
}
ErrorStatus_et DIO_enuRead     (uint8_kt u8PinNumCpy,uint8_kt *pu8PinValue)
{
	
	ErrorStatus_et  ErrorStatusLoc_e=EOK;
	if(pu8PinValue!=NULL_PTR)
	{
		if((u8PinNumCpy>=0)&&(u8PinNumCpy<=7))
		{

				*pu8PinValue=READ_BIT(GPIO->A.IDR.REG,u8PinNumCpy);
			
		}
		else if((u8PinNumCpy>=8)&&(u8PinNumCpy<=15))
		{
		   
				*pu8PinValue=READ_BIT(GPIO->B.IDR.REG,u8PinNumCpy%8);
			
		}
		else if((u8PinNumCpy>=16)&&(u8PinNumCpy<=23))
		{ 
			
				*pu8PinValue=READ_BIT(GPIO->C.IDR.REG,u8PinNumCpy%8);
			
		}
		else if((u8PinNumCpy>=24)&&(u8PinNumCpy<=31))
		{
				*pu8PinValue=READ_BIT(GPIO->D.IDR.REG,u8PinNumCpy%8);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
	}
	else
	{
		ErrorStatusLoc_e=PARAM_NULL_PTR;
	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et DIO_enuToggle   (uint8_kt u8PinNumCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if((u8PinNumCpy>=0)&&(u8PinNumCpy<=7))
		{

				TOG_BIT(GPIO->A.ODR.REG,u8PinNumCpy);
			
		}
		else if((u8PinNumCpy>=8)&&(u8PinNumCpy<=15))
		{
		   
				TOG_BIT(GPIO->B.ODR.REG,u8PinNumCpy%8);
			
		}
		else if((u8PinNumCpy>=16)&&(u8PinNumCpy<=23))
		{ 
			
				TOG_BIT(GPIO->C.ODR.REG,u8PinNumCpy%8);
			
		}
		else if((u8PinNumCpy>=24)&&(u8PinNumCpy<=31))
		{
				TOG_BIT(GPIO->D.ODR.REG,u8PinNumCpy%8);
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
	return ErrorStatusLoc_e;
}

ErrorStatus_et DIO_enuWriteGroup (uint8_kt au8PinsNums[],uint8_kt au8PinsValues[],uint8_kt u8TotalPinsCpy)
{
	ErrorStatus_et  ErrorStatusLoc_e=EOK;
	uint8_kt u8IndexLoc;
	ErrorStatusLoc_e=DetectMultiOccurance(au8PinsNums,u8TotalPinsCpy);
	if(EOK==ErrorStatusLoc_e)
	{
		if(u8TotalPinsCpy<=32)
		{

			for(u8IndexLoc=0;u8IndexLoc<u8TotalPinsCpy;u8IndexLoc++)
			{
				ErrorStatusLoc_e= DIO_enuWrite (au8PinsNums[u8IndexLoc],au8PinsValues[u8IndexLoc]);
				if(ErrorStatusLoc_e!=EOK)
				{
					break;
				}
			}
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
	}
	else
	{
		
	}
	return ErrorStatusLoc_e;
	
}

ErrorStatus_et DIO_enuReadGroup  (uint8_kt au8PinsNums[],uint8_kt au8PinsValues[],uint8_kt u8TotalPinsCpy)
{
	ErrorStatus_et  ErrorStatusLoc_e=EOK;
	uint8_kt u8IndexLoc;
	ErrorStatusLoc_e=DetectMultiOccurance(au8PinsNums,u8TotalPinsCpy);
	if(EOK==ErrorStatusLoc_e)
	{
		if(u8TotalPinsCpy<=32)
		{
			for(u8IndexLoc=0;u8IndexLoc<u8TotalPinsCpy;u8IndexLoc++)
			{
				ErrorStatusLoc_e=DIO_enuRead (au8PinsNums[u8IndexLoc],&au8PinsValues[u8IndexLoc]);
				if(ErrorStatusLoc_e!=EOK)
				{
					break;
				}
			}
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
	}
	else
	{
		
	}
	return ErrorStatusLoc_e;
	
}

ErrorStatus_et DIO_enuToggleGroup(uint8_kt au8PinsNums[],uint8_kt u8TotalPinsCpy)
{
	ErrorStatus_et  ErrorStatusLoc_e=EOK;
	uint8_kt u8IndexLoc;
	ErrorStatusLoc_e=DetectMultiOccurance(au8PinsNums,u8TotalPinsCpy);
	if(EOK==ErrorStatusLoc_e)
	{
		if(u8TotalPinsCpy<=32)
		{
			for(u8IndexLoc=0;u8IndexLoc<u8TotalPinsCpy;u8IndexLoc++)
			{
				ErrorStatusLoc_e=DIO_enuToggle (au8PinsNums[u8IndexLoc]);
				if(ErrorStatusLoc_e!=EOK)
				{
					break;
				}
			}
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
	}
	else
	{
		
	}
	return ErrorStatusLoc_e;
}

ErrorStatus_et DIO_enuWritePort (Port_et PortIdCpy_e,uint8_kt u8ValueCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(PORTA==PortIdCpy_e)
	{
		GPIO->A.ODR.REG=u8ValueCpy;
	}
	else if(PORTB==PortIdCpy_e)
	{
		GPIO->B.ODR.REG=u8ValueCpy;
	}
	else if(PORTC==PortIdCpy_e)
	{
		GPIO->C.ODR.REG=u8ValueCpy;
	}
	else if(PORTD==PortIdCpy_e)
	{
		GPIO->D.ODR.REG=u8ValueCpy;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et DIO_enuReadPort  (Port_et PortIdCpy_e,uint8_kt *pu8Value)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(PORTA==PortIdCpy_e)
	{
		*pu8Value=GPIO->A.IDR.REG;
	}
	else if(PORTB==PortIdCpy_e)
	{
		*pu8Value=GPIO->B.IDR.REG;
	}
	else if(PORTC==PortIdCpy_e)
	{
		*pu8Value=GPIO->C.IDR.REG;
	}
	else if(PORTD==PortIdCpy_e)
	{
		*pu8Value=GPIO->D.IDR.REG;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et DIO_enuTogglePort(Port_et PortIdCpy_e)
{
	
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(PORTA==PortIdCpy_e)
	{
		GPIO->A.ODR.REG^=0xFF;
	}
	else if(PORTB==PortIdCpy_e)
	{
		GPIO->B.ODR.REG=0xFF;
	}
	else if(PORTC==PortIdCpy_e)
	{
		GPIO->C.ODR.REG=0xFF;
	}
	else if(PORTD==PortIdCpy_e)
	{
		GPIO->D.ODR.REG=0xFF;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}

void DIO_enuWriteDIO (uint32_kt  u32DoValueCpy)
{
	GPIO->A.ODR.REG=(uint8_kt)(u32DoValueCpy);
	u32DoValueCpy>>=8;
	GPIO->B.ODR.REG=(uint8_kt)(u32DoValueCpy);
	u32DoValueCpy>>=8;
	GPIO->C.ODR.REG=(uint8_kt)(u32DoValueCpy);
	u32DoValueCpy>>=8;
	GPIO->D.ODR.REG=(uint8_kt)(u32DoValueCpy);
}
ErrorStatus_et DIO_enuReadDIO  (uint32_kt *Pu32DiValue)
{
	ErrorStatus_et  ErrorStatusLoc_e=EOK;
	if(NULL_PTR==Pu32DiValue)
	{
		*Pu32DiValue=GPIO->A.ODR.REG;
		*Pu32DiValue<<=8;
		*Pu32DiValue|=GPIO->B.ODR.REG;
		*Pu32DiValue<<=8;
		*Pu32DiValue|=GPIO->C.ODR.REG;
		*Pu32DiValue<<=8;
		*Pu32DiValue|=GPIO->D.ODR.REG;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_NULL_PTR;
	}
	return ErrorStatusLoc_e;
}
void DIO_enuClrDIO()
{
	GPIO->A.ODR.REG=0;
	GPIO->B.ODR.REG=0;
	GPIO->C.ODR.REG=0;
	GPIO->D.ODR.REG=0;
}
void DIO_enuToggleDIO()
{
	GPIO->A.ODR.REG^=0xFF;
	GPIO->B.ODR.REG^=0xFF;
	GPIO->C.ODR.REG^=0xFF;
	GPIO->D.ODR.REG^=0xFF;
}




ErrorStatus_et  DIO_enuWriteGroupV2(uint8_kt au8PinsNums[],uint32_kt u32PinsValues,uint8_kt u8TotalPinsCpy)/*a function that writes the state of a group of output pins*/
{
	ErrorStatus_et  ErrorStatusLoc_e=EOK;
	uint8_kt u8IndexLoc;
	ErrorStatusLoc_e=DetectMultiOccurance(au8PinsNums,u8TotalPinsCpy);
	if(EOK==ErrorStatusLoc_e)
	{
		if(u8TotalPinsCpy<=32)
		{

			for(u8IndexLoc=0;(EOK==ErrorStatusLoc_e)&&(u8IndexLoc<u8TotalPinsCpy);u8IndexLoc++)
			{
				DIO_enuWrite (au8PinsNums[u8IndexLoc],READ_BIT(u32PinsValues,u8IndexLoc));
			}
		}
		else
		{

			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
	}
	else
	{

	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et   DIO_enuReadGroupV2(uint8_kt au8PinsNums[],uint32_kt *pu32PinsValues,uint8_kt u8TotalPinsCpy)/*a function that reads the state of a group of input pins*/
{
	ErrorStatus_et  ErrorStatusLoc_e=EOK;
	uint8_kt u8IndexLoc;
	uint8_kt u8TmpLoc=0;
	ErrorStatusLoc_e=DetectMultiOccurance(au8PinsNums,u8TotalPinsCpy);
	if(EOK==ErrorStatusLoc_e)
	{
		if(u8TotalPinsCpy<=32)
		{
			for(u8IndexLoc=0;u8IndexLoc<u8TotalPinsCpy;u8IndexLoc++)
			{
				ErrorStatusLoc_e=DIO_enuRead (au8PinsNums[u8IndexLoc],&u8TmpLoc);
				*pu32PinsValues<<=1;
				*pu32PinsValues|=u8TmpLoc;
				if(ErrorStatusLoc_e!=EOK)
				{
					break;
				}
			}
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
	}
	else
	{

	}
	return ErrorStatusLoc_e;

}
