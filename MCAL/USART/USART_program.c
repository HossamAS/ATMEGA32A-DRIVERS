/**************************************/
/* Description : USART program File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:09:52  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "USART_private.h"
#include "USART_interface.h"
#include "USART_config.h"



/*pre-build configuration (preprocessor)*/
void USART_vInit(void)
{
	uint16_kt u16UBRR_Loc;
	USART.UCSRC.URSEL=USART_SELECT_UCSRC;
	USART.UCSRB.TXEN=TRANSMITTER_STATUS;
	USART.UCSRB.RXEN=RECEIVER_STATUS;
	USART.UCSRA.UDRE=DATA_REGISTER_EMPTY_INTTERRUPT_STATUS;
	USART.UCSRA.TXC=TX_COMPLETE_INTTERUPT_STATUS;
	USART.UCSRA.RXC=RX_COMPLETE_INTERRUPT_STATUS;
	USART.UCSRC.UCSZ0_1=CHARACTER_SIZE;
	USART.UCSRB.UCSZ2=CHARACTER_SIZE>>2;
	USART.UCSRC.UMSEL=USART_MODE;
	USART.UCSRC.UPM=PARITY_MODE;
	USART.UCSRC.USBS=STOP_BITS;
	USART.UCSRC.UCPOL=CLOCK_POLARITY;
	USART.UCSRA.MPCM=MULTI_PROCESSOR_COMMUNICATION_MODE;
	USART.UCSRA.U2X=DOUBLE_SPEED;
	#if((DOUBLE_SPEED==USART_EN)&&(USART_MODE==USART_ASYNCHRONOUS))
	u16UBRR_Loc=((CPU_FREQUENCY/(8UL*BUAD_RATE))-1);
	#elif((DOUBLE_SPEED==USART_DIS)&&(USART_MODE==USART_ASYNCHRONOUS))
	u16UBRR_Loc=((CPU_FREQUENCY/(16UL*BUAD_RATE))-1);
	#else
	u16UBRR_Loc=((CPU_FREQUENCY/(2UL*BUAD_RATE))-1);
	#endif
	USART.UBRRL.REG=u16UBRR_Loc;
	USART.UCSRC.URSEL=USART_SELECT_UBRRH;
	USART.UBRRH.Bits8_to_11=u16UBRR_Loc>>8;
}
/*run-time configuration*/
void USART_vTransmitter_En(void)
{
	USART.UCSRB.TXEN=1;
}
void USART_vTransmitter_Dis(void)
{
	USART.UCSRB.TXEN=0;
}
void USART_vReceiver_En(void)
{
	USART.UCSRB.RXEN=1;
}
void USART_vReceiver_Dis(void)
{
	USART.UCSRB.RXEN=0;
}
void USART_vDataRegEmptyInt_En(void)
{
	USART.UCSRA.UDRE=1;
}
void USART_vDataRegEmptyInt_Dis(void)
{
	USART.UCSRA.UDRE=0;
}
void USART_vTX_CompleteInt_En(void)
{
	USART.UCSRA.TXC=1;
}
void USART_vTX_CompleteInt_Dis(void)
{
	USART.UCSRA.TXC=0;
}
void USART_vRX_CompleteInt_En(void)
{
	USART.UCSRA.RXC=1;
}
void USART_vRX_CompleteInt_Dis(void)
{
	USART.UCSRA.RXC=0;
}
void USART_vDoubleSpeed_En(void)
{
	USART.UCSRA.U2X=1;
}
void USART_vDoubleSpeed_Dis(void)
{
	USART.UCSRA.U2X=0;
}
void USART_vMultiProcessorComMode_En(void)
{
	USART.UCSRA.MPCM=1;
}
void USART_vMultiProcessorComMode_Dis(void)
{
	USART.UCSRA.MPCM=0;
}
ErrorStatus_et USART_enuCharSize(uint8_kt u8CharSizeCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u8CharSizeCpy<4||u8CharSizeCpy==7)
	{
		USART.UCSRC.UPM=u8CharSizeCpy;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et USART_enuParityMode(uint8_kt u8ParityModeCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		if(u8ParityModeCpy<4)
		{
			USART.UCSRC.UPM=u8ParityModeCpy;
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
		return ErrorStatusLoc_e;
}
ErrorStatus_et USART_enuMode(uint8_kt u8ModeCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		if(u8ModeCpy<2)
		{
			USART.UCSRC.UMSEL=u8ModeCpy;
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
		return ErrorStatusLoc_e;
}
ErrorStatus_et USART_enuStopBits(uint8_kt u8StopBitsCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		if(u8StopBitsCpy<2)
		{
			USART.UCSRC.USBS=u8StopBitsCpy;
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
		return ErrorStatusLoc_e;
}
ErrorStatus_et USART_enuClkPolarity(uint8_kt u8ClkPolarityCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		if(u8ClkPolarityCpy<2)
		{
			USART.UCSRC.UCPOL=u8ClkPolarityCpy;
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
		return ErrorStatusLoc_e;
}
void USART_enuBaudRate(uint16_kt u16BaudRateCpy)
{
	uint16_kt u16UBRR_Loc;
	if( USART.UCSRC.UMSEL==USART_ASYNCHRONOUS && USART.UCSRA.U2X==USART_EN )
	{
		u16UBRR_Loc=((CPU_FREQUENCY/(8UL*BUAD_RATE))-1);
	}
	else if(USART.UCSRC.UMSEL==USART_ASYNCHRONOUS && USART.UCSRA.U2X==USART_DIS)
	{
		u16UBRR_Loc=((CPU_FREQUENCY/(16UL*BUAD_RATE))-1);
	}
	else
	{
		USART.UCSRA.U2X=USART_DIS;
		u16UBRR_Loc=((CPU_FREQUENCY/(2UL*BUAD_RATE))-1);
	}
	USART.UBRRL.REG=u16UBRR_Loc;
	USART.UCSRC.URSEL=USART_SELECT_UBRRH;
	USART.UBRRH.Bits8_to_11=u16UBRR_Loc>>8;
}
ErrorStatus_et USART_vTXC_SetCallBack(pf pfCallBack)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
				if(pfCallBack!=NULL_PTR)
				{
					TXC_CallBack=pfCallBack;
				}
				else
				{
					ErrorStatusLoc_e=PARAM_NULL_PTR;
				}
				return ErrorStatusLoc_e;
}
ErrorStatus_et USART_vRXC_SetCallBack(pf pfCallBack)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
					if(pfCallBack!=NULL_PTR)
					{
						RXC_CallBack=pfCallBack;
					}
					else
					{
						ErrorStatusLoc_e=PARAM_NULL_PTR;
					}
					return ErrorStatusLoc_e;
}
ErrorStatus_et USART_vUDRE_SetCallBack(pf pfCallBack)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
					if(pfCallBack!=NULL_PTR)
					{
						UDRE_CallBack=pfCallBack;
					}
					else
					{
						ErrorStatusLoc_e=PARAM_NULL_PTR;
					}
					return ErrorStatusLoc_e;
}
/*APIs*/
void USART_vSendChar(uint8_kt u8CharCpy)
{
	while(USART.UCSRA.UDRE==0);
	USART.UDR.REG=u8CharCpy;
}
void USART_vSyncReceiveChar(uint8_kt* pu8Char)
{
	while(USART.UCSRA.RXC==0);
	*pu8Char=USART.UDR.REG;
}
ErrorStatus_et USART_enuAsyncReceiveChar(uint8_kt* pu8Char)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
			if(pu8Char!=NULL_PTR)
			{
				pu8USART_AsyncByte=pu8Char;
			}
			else
			{
				ErrorStatusLoc_e=PARAM_NULL_PTR;
			}
			return ErrorStatusLoc_e;

}



void __vector_13(void) __attribute__((signal,used));
void __vector_13(void)
{

#if(ASYNC_RECEIVEING==TWI_EN)
	if(pu8USART_AsyncByte!=NULL_PTR)
	{
		*pu8USART_AsyncByte=USART.UDR.REG;
	}
#endif
	if(RXC_CallBack!=NULL_PTR)
			{
				RXC_CallBack();
			}
}

void __vector_14(void) __attribute__((signal,used));
void __vector_14(void)
{
	if(UDRE_CallBack!=NULL_PTR)
		{
			UDRE_CallBack();
		}
}

void __vector_15(void) __attribute__((signal,used));
void __vector_15(void)
{
	if(TXC_CallBack!=NULL_PTR)
		{
			TXC_CallBack();
		}
}

















