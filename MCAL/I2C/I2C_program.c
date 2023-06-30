/**************************************/
/* Description : I2C program File     */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:10:06  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/

#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "I2C_private.h"
#include "util/delay.h"
#include "I2C_config.h"
#include "I2C_interface.h"

/*Pre-build configuration (preprocessor)*/

void TWI_vInit(void)
{
	TWI.TWAR.TWGCE=TWI_GENERAL_CALL_RECOGNITION_STATUS;
	TWI.TWSR.TWPS=TWI_PRESCALER;
#if(TWI_PRESCALER==TWI_PRESCALER_1)
	TWI.TWBR.REG=(uint8_kt)((((float32_kt)(TWI_CPU_FREQUENCY)/TWI_SCL_FREQUENCY)-16.0f)/2.0f);
#elif(TWI_PRESCALER==TWI_PRESCALER_4)
	TWI.TWBR.REG=(uint8_kt)((((float32_kt)(TWI_CPU_FREQUENCY)/TWI_SCL_FREQUENCY)-16.0f)/8.0f);
#elif(TWI_PRESCALER==TWI_PRESCALER_16)
	TWI.TWBR.REG=(uint8_kt)((((float32_kt)(TWI_CPU_FREQUENCY)/TWI_SCL_FREQUENCY)-16.0f)/32.0f);
#elif(TWI_PRESCALER==TWI_PRESCALER_64)
	TWI.TWBR.REG=(uint8_kt)((((float32_kt)(TWI_CPU_FREQUENCY/TWI_SCL_FREQUENCY))-16.0f)/128.0f);
#endif
	TWI.TWCR.TWEA=TWI_ACKNOWLEDGE_STATUS;
	TWI.TWCR.TWEN=TWI_STATUS;
	TWI.TWCR.TWIE=TWI_INTERRUPT_STATUS;

}



/*run-time configuration*/

inline void TWI_vEn(void)
{
	TWI.TWCR.TWEN=1;
}
inline void TWI_vDis(void)
{
	TWI.TWCR.TWEN=0;
}
inline void TWI_vGeneralCallRecognitionEn(void)
{
	TWI.TWAR.TWGCE=1;
}
inline void TWI_vGeneralCallRecognitionDis(void)
{
	TWI.TWAR.TWGCE=0;
}
inline void TWI_vIntEn(void)
{
	TWI.TWCR.TWIE=1;
}
inline void TWI_vIntDis(void)
{
	TWI.TWCR.TWIE=0;
}
inline void TWI_vSetAcknowledge(void)
{
	TWI.TWCR.TWEA=1;
}
inline void TWI_vSetNotAcknowledge(void)
{
	TWI.TWCR.TWEA=0;
}
ErrorStatus_et TWI_enuSetPrescaler(uint8_kt u8PrescalerCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
    if(u8PrescalerCpy<4)
    {
    	TWI.TWSR.TWPS=u8PrescalerCpy;
    }
    else
    {
    	ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
    }
    return ErrorStatusLoc_e;
}
ErrorStatus_et TWI_enuSetSCL_Freqency(uint32_kt u32SCL_FreqencyCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	    if(u32SCL_FreqencyCpy<=400000UL)
	    {
			if(TWI.TWSR.TWPS==TWI_PRESCALER_1)
			{
				TWI.TWBR.REG=(uint8_kt)(((TWI_CPU_FREQUENCY/TWI_SCL_FREQUENCY)-16UL)/2);
			}
			else if(TWI.TWSR.TWPS==TWI_PRESCALER_4)
			{
				TWI.TWBR.REG=(uint8_kt)(((TWI_CPU_FREQUENCY/TWI_SCL_FREQUENCY)-16UL)/8);
			}
			else if(TWI.TWSR.TWPS==TWI_PRESCALER_16)
			{
				TWI.TWBR.REG=(uint8_kt)(((TWI_CPU_FREQUENCY/TWI_SCL_FREQUENCY)-16UL)/32);
			}
			else
			{
				TWI.TWBR.REG=(uint8_kt)(((TWI_CPU_FREQUENCY/TWI_SCL_FREQUENCY)-16UL)/128);
			}

	    }
	    else
	    {
	    	ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	    }
	    return ErrorStatusLoc_e;
}



/*static helping functions*/
static void TWI_vWaitingTheOperation(void)
{
	while(TWI.TWCR.TWINT==0);
}
static void TWI_vSendStartCondition(void)
{
	 TWI.TWCR.TWSTO=0;
	 TWI.TWCR.TWSTA=1;
	 TWI.TWCR.TWINT=1;
	TWI_vWaitingTheOperation();
}
static void TWI_vSendStopCondition(void)
{
	 TWI.TWCR.TWSTA=0;
	 TWI.TWCR.TWSTO=1;
	 TWI.TWCR.TWINT=1;
}
static void TWI_vStartOperateDataReg(void)
{
    TWI.TWCR.TWSTA=0;
    TWI.TWCR.TWSTO=0;
    TWI.TWCR.TWINT=1;
    TWI_vWaitingTheOperation();
}

static uint8_kt TWI_u8ReadTheOperationStatus(void)
{
	return TWI.TWSR.TWS;
}
static ErrorStatus_et TWI_vSendOrientedSlaveAddressWithCommand(uint8_kt SlaveAddress,uint8_kt Command)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if((SlaveAddress<128)&&(Command<2))
		{
			TWI.TWDR.REG=SlaveAddress+Command;
			TWI_vStartOperateDataReg();
			TWI_vWaitingTheOperation();
		}
	else
		{
			ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
		}
	return ErrorStatusLoc_e;
}
static void TWI_vSendData(uint8_kt u8DataCpy)
{
	TWI.TWDR.REG=u8DataCpy;
	TWI_vStartOperateDataReg();

}
static uint8_kt TWI_u8ReceiveData(void)
{
	TWI_vStartOperateDataReg();
	return TWI.TWDR.REG;
}

/*MASTER APIs*/

ErrorStatus_et TWI_vSyncMasterTransmit(uint8_kt u8SlaveAddressCpy,uint8_kt* au8Data,uint8_kt u8DataLengthCpy,uint8_kt* pu8OperationStatus,uint8_kt StopConditionStatus)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	uint8_kt u8IndexLoc;
	/*Send start condition*/
		TWI_vSendStartCondition();
	    *pu8OperationStatus=TWI_u8ReadTheOperationStatus();
		if((*pu8OperationStatus!=TWI_START_CONDITION_TRANSMITTED)&&(*pu8OperationStatus!=TWI_REPEATED_START_CONDITION_TRANSMITTED))
		{
			return ErrorStatusLoc_e;
		}
	/*Send sla+W*/
		ErrorStatusLoc_e=TWI_vSendOrientedSlaveAddressWithCommand(u8SlaveAddressCpy, TWI_WRITE);
		if(ErrorStatusLoc_e!=EOK)
		{
			return ErrorStatusLoc_e;
		}
		*pu8OperationStatus=TWI_u8ReadTheOperationStatus();
		if(*pu8OperationStatus!=TWI_SLA_W_TRANSMITTED_ACK_RECEIVED)
		{
				return ErrorStatusLoc_e;
		}
	/*Send data*/

		for(u8IndexLoc=0;u8IndexLoc<u8DataLengthCpy;u8IndexLoc++)
		{
			TWI_vSendData(au8Data[u8IndexLoc]);
			*pu8OperationStatus=TWI_u8ReadTheOperationStatus();
			if(*pu8OperationStatus!=TWI_MASTER_DATA_BYTE_TRANSMITTED_ACK_RECEIVED)
			{
				return ErrorStatusLoc_e;
			}
		}
	/*Send stop condition*/
		if(StopConditionStatus==TWI_EN)
					{
						TWI_vSendStopCondition();
					}
					else if(StopConditionStatus>TWI_EN)
					{
						ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
					}

					return ErrorStatusLoc_e;
}
ErrorStatus_et TWI_vSyncMasterReceive(uint8_kt u8SlaveAddressCpy,uint8_kt* au8Data,uint8_kt u8DataLengthCpy,uint8_kt* pu8OperationStatus,uint8_kt StopConditionStatus)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
		uint8_kt u8IndexLoc;

		/*Send start condition*/
			TWI_vSendStartCondition();
			*pu8OperationStatus=TWI_u8ReadTheOperationStatus();
			if(*pu8OperationStatus!=TWI_START_CONDITION_TRANSMITTED)
			{
				return ErrorStatusLoc_e;
			}

		/*Send sla+R*/
			ErrorStatusLoc_e=TWI_vSendOrientedSlaveAddressWithCommand(u8SlaveAddressCpy, TWI_READ);
			if(ErrorStatusLoc_e==PARAM_OUT_OF_RANGE)
			{
				return ErrorStatusLoc_e;
			}
			*pu8OperationStatus=TWI_u8ReadTheOperationStatus();
			if(*pu8OperationStatus!=TWI_SLA_R_TRANSMITTED_ACK_RECEIVED)
			{
					return ErrorStatusLoc_e;
			}
			TWI_vSetAcknowledge();
		/*receive data*/
			for(u8IndexLoc=0;u8IndexLoc<u8DataLengthCpy-1;u8IndexLoc++)
			{
				au8Data[u8IndexLoc]=TWI_u8ReceiveData();
				*pu8OperationStatus=TWI_u8ReadTheOperationStatus();
				if(*pu8OperationStatus!=TWI_DATA_BYTE_RECEIVED_ACK_TRANSMITTED)
				{
						return ErrorStatusLoc_e;
				}
			}
			TWI_vSetNotAcknowledge();
			au8Data[u8IndexLoc]=TWI_u8ReceiveData();
		/*Send stop condition*/
			if(StopConditionStatus==TWI_EN)
			{
				TWI_vSendStopCondition();
			}
			else if(StopConditionStatus==TWI_DIS)
			{

			}
			else
			{
				ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
			}
			return ErrorStatusLoc_e;
}

/*slave APIs*/

void TWI_vSyncSlaveTransmit(uint8_kt* au8Data,uint8_kt u8DataLengthCpy,uint8_kt* pu8OperationStatus)
{
	uint8_kt u8IndexLoc;
	/*wait for own address call*/
	TWI_vSetAcknowledge();
	while(TWI_u8ReadTheOperationStatus()!=TWI_SLA_R_RECEIVED_ACK_TRANSMITTED);

	/*data*/
		for(u8IndexLoc=0;u8IndexLoc<u8DataLengthCpy;u8IndexLoc++)
		{
			TWI_vSendData(au8Data[u8IndexLoc]);
			*pu8OperationStatus=TWI_u8ReadTheOperationStatus();
			if(*pu8OperationStatus!=TWI_SLAVE_DATA_BYTE_TRANSMITTED_ACK_RECEIVED)
			{
				break;
			}
		}
}
void TWI_vSyncSlaveReceive(uint8_kt* au8Data,uint8_kt u8DataLengthCpy,uint8_kt* pu8OperationStatus)
{
	uint8_kt u8IndexLoc;
	/*wait for own address call*/
	TWI_vSetAcknowledge();
	while(TWI_u8ReadTheOperationStatus()!=TWI_SLA_W_RECEIVED_ACK_TRANSMITTED);
	/*data*/
		for(u8IndexLoc=0;u8IndexLoc<u8DataLengthCpy;u8IndexLoc++)
		{
			au8Data[u8IndexLoc]=TWI_u8ReceiveData();
			*pu8OperationStatus=TWI_u8ReadTheOperationStatus();
			if(*pu8OperationStatus!=TWI_PREVIOUSLY_ADDRESSED_WITH_SLA_W_DATA_BYTE_RECEIVED_ACK_TRANSMITTED)
			{
				break;
			}
		}
}

ErrorStatus_et TWI_SetOwnedAddress(uint8_kt u8OwnedAddressCpy)
{
	ErrorStatus_et ErrorStatusLoc_e=EOK;
	if(u8OwnedAddressCpy<128)
	 {
		TWI.TWAR.TWA=u8OwnedAddressCpy;
	 }
	else
	{
		ErrorStatusLoc_e=PARAM_OUT_OF_RANGE;
	}
	return ErrorStatusLoc_e;
}
ErrorStatus_et TWI_vSetCallBack(pf pfCallBack)
{
	ErrorStatus_et ErrorStatusLoc_e = EOK;
	if(pfCallBack!=NULL_PTR)
	{
		TWI_CallBack=pfCallBack;
	}
	else
	{
		ErrorStatusLoc_e=PARAM_NULL_PTR;
	}
	return ErrorStatusLoc_e;
}
void __vector_19(void) __attribute__((signal,used));
void __vector_19(void)
{
	if(TWI_CallBack!=NULL_PTR)
	{
		TWI_CallBack();
	}
}








