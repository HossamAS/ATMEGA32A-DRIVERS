/**************************************/
/* Description : SPI program File     */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:09:22  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"
/* pre-build configuration (pre-processing)*/
void SPI_vInit(void)
{
	SPI.SPCR.SPR=SPI_PRESCALER&3;
	SPI.SPSR.SPI2X=SPI_PRESCALER&&4;
	SPI.SPCR.CPHA=CLOCK_PHASE;
	SPI.SPCR.CPOL=CLOCK_POLARITY;
	SPI.SPCR.MSTR=AUTHORITY_MODE;
	SPI.SPCR.DORD=DATA_ORDER;
	SPI.SPCR.SPE=SPI_STATUS;
	SPI.SPCR.SPIE=SPI_INT_STATUS;
}
/* run-time configuration */
void SPI_vIntEn(void)
{
	SPI.SPCR.SPIE=1;
}
void SPI_vIntDis(void)
{
	SPI.SPCR.SPIE=0;
}
void SPI_vEn(void)
{
	SPI.SPCR.SPE=1;
}
void SPI_vDis(void)
{
	SPI.SPCR.SPE=0;
}
ErrorStatus_et SPI_enuDataOrder(uint8_kt u8DataOrderCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u8DataOrderCpy<2)
	{
		SPI.SPCR.DORD=u8DataOrderCpy;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et SPI_enuAuthority(uint8_kt u8AuthorityCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		if(u8AuthorityCpy<2)
		{
			SPI.SPCR.MSTR=u8AuthorityCpy;
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
		return ErrorStatusLoc_e;
}
ErrorStatus_et SPI_enuClkPolarity(uint8_kt u8ClkPolarityCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
			if(u8ClkPolarityCpy<2)
			{
				SPI.SPCR.CPOL=u8ClkPolarityCpy;
			}
			else
			{
				ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
			}
			return ErrorStatusLoc_e;
}
ErrorStatus_et SPI_enuClkPhase(uint8_kt u8ClkPhaseCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		if(u8ClkPhaseCpy<2)
		{
			SPI.SPCR.CPHA=u8ClkPhaseCpy;
		}
		else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
		return ErrorStatusLoc_e;
}
ErrorStatus_et SPI_enuPrescaler(uint8_kt u8PrescalerCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
			if(u8PrescalerCpy<8)
			{
				SPI.SPCR.SPR=u8PrescalerCpy&3;
				SPI.SPSR.SPI2X=u8PrescalerCpy&&4;
			}
			else
			{
				ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
			}
			return ErrorStatusLoc_e;
}
ErrorStatus_et SPI_enuSetCallBack(pf pfCallBack)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
				if(pfCallBack!=NULL_PTR)
				{
					STC_CallBack=pfCallBack;
				}
				else
				{
					ErrorStatusLoc_e=PARAM_NULL_PTR;
				}
	return ErrorStatusLoc_e;
}
/*APIs*/

void SPI_vSendByte(uint8_kt u8ByteCpy)/*AS MASTER ONLY*/
{
	SPI.SPDR.REG=u8ByteCpy;
	while(SPI.SPSR.SPIF==0);
}
void SPI_vSyncReadRecievedByte(uint8_kt* pu8Byte)
{
	while(SPI.SPSR.SPIF==0);
	*pu8Byte=SPI.SPDR.REG;
}
ErrorStatus_et SPI_vAsyncReadRecievedByte(uint8_kt* pu8Byte)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
					if(pu8Byte!=NULL_PTR)
					{
						pu8SPI_AsyncByte=pu8Byte;
					}
					else
					{
						ErrorStatusLoc_e=PARAM_NULL_PTR;
					}
		return ErrorStatusLoc_e;

}


void __vector_12(void) __attribute__((signal,used));
void __vector_12(void)
{
	if(STC_CallBack!=NULL_PTR)
	{
		STC_CallBack();
	}
	if(pu8SPI_AsyncByte!=NULL_PTR)
	{
	   *pu8SPI_AsyncByte=SPI.SPDR.REG;
	}
}

