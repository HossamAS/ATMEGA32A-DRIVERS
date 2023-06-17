/**************************************/
/* Description : I2C interface File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:10:06  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

/**************************************/
/* Description : I2C program File     */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 16:10:06  18 May 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/



/*Pre-build configuration (preprocessor)*/

void TWI_vInit(void);

/*run-time configuration*/

void TWI_vEn(void);
void TWI_vDis(void);
void TWI_vGeneralCallRecognitionEn(void);
void TWI_vGeneralCallRecognitionDis(void);
void TWI_vInterruptEn(void);
void TWI_vInterruptDis(void);
void TWI_vSetAcknowledge(void);
void TWI_vSetNotAcknowledge(void);
ErrorStatus_et TWI_enuSetPrescaler(uint8_kt u8PrescalerCpy);
ErrorStatus_et TWI_enuSetSCL_Freqency(uint32_kt u32SCL_FreqencyCpy);

/*MASTER APIs*/
ErrorStatus_et TWI_vSyncMasterTransmit(uint8_kt u8SlaveAddressCpy,uint8_kt* au8Data,uint8_kt u8DataLengthCpy,uint8_kt* pu8OperationStatus,uint8_kt StopConditionStatus);
ErrorStatus_et TWI_vSyncMasterReceive(uint8_kt u8SlaveAddressCpy,uint8_kt* au8Data,uint8_kt u8DataLengthCpy,uint8_kt* pu8OperationStatus,uint8_kt StopConditionStatus);

/*slave APIs*/
void TWI_vSyncSlaveTransmit(uint8_kt* au8Data,uint8_kt u8DataLengthCpy,uint8_kt* pu8OperationStatus);
void TWI_vSyncSlaveReceive(uint8_kt* au8Data,uint8_kt u8DataLengthCpy,uint8_kt* pu8OperationStatus);
ErrorStatus_et TWI_SetOwnedAddress(uint8_kt u8OwnedAddressCpy);


ErrorStatus_et TWI_vSetCallBack(pf pfCallBack);
/***************************options**********************************/
/*status enable and disable*/
#define TWI_DIS 0
#define TWI_EN  1
/*prescaler*/
#define TWI_PRESCALER_1  0
#define TWI_PRESCALER_4  1
#define TWI_PRESCALER_16 2
#define TWI_PRESCALER_64 3
/*command*/
#define TWI_READ   1
#define TWI_WRITE  0
/*operation status*/

#define TWI_START_CONDITION_TRANSMITTED    		         				    			1
#define TWI_REPEATED_START_CONDITION_TRANSMITTED        								2
#define TWI_SLA_W_TRANSMITTED_ACK_RECEIVED          					 				3
#define TWI_SLA_W_TRANSMITTED_NACK_RECEIVED          									4
#define TWI_MASTER_DATA_BYTE_TRANSMITTED_ACK_RECEIVED 	    							5
#define TWI_MASTER_DATA_BYTE_TRANSMITTED_NACK_RECEIVED         		        			6
#define TWI_ARBITRATION_LOST_SLA_R_OR_NACK										   		7
#define TWI_SLA_R_TRANSMITTED_ACK_RECEIVED     			 				    			8
#define TWI_SLA_R_TRANSMITTED_NACK_RECEIVED   			  				    			9
#define TWI_DATA_BYTE_RECEIVED_ACK_TRANSMITTED  		   				    			10
#define TWI_DATA_BYTE_RECEIVED_NACK_TRANSMITTED 		   				    			11
#define TWI_SLA_W_RECEIVED_ACK_TRANSMITTED												12
#define TWI_ARBITRATION_LOST_SLA_W_RECEIVED_ACK_TRANSMITTED 							13
#define TWI_GENERAL_CALL_ADDRESS_RECEIVED_ACK_TRANSMITTED   							14
#define TWI_ARBITRATION_LOST_GENERAL_CALL_ADDRESS_RECEIVED_ACK_TRANSMITTED  			15
#define TWI_PREVIOUSLY_ADDRESSED_WITH_SLA_W_DATA_BYTE_RECEIVED_ACK_TRANSMITTED 			16
#define TWI_PREVIOUSLY_ADDRESSED_WITH_SLA_W_DATA_BYTE_RECEIVED_NACK_TRANSMITTED  		17
#define TWI_PREVIOUSLY_ADDRESSED_WITH_GENERAL_CALL_DATA_BYTE_RECEIVED_ACK_TRANSMITTED	18
#define TWI_PREVIOUSLY_ADDRESSED_WITH_GENERAL_CALL_DATA_BYTE_RECEIVED_NACK_TRANSMITTED  19
#define TWI_STOP_CONDITION_OR_REPEATED_START_RECEIVED                                   20
#define TWI_SLA_R_RECEIVED_ACK_TRANSMITTED  											21
#define TWI_ARBITRATION_LOST_SLA_R_RECEIVED_ACK_TRANSMITTED                             22
#define TWI_SLAVE_DATA_BYTE_TRANSMITTED_ACK_RECEIVED                                    23
#define TWI_SLAVE_DATA_BYTE_TRANSMITTED_NACK_RECEIVED                                   24
#define TWI_LAST_DATA_BYTE_TRANSMITTED_ACK_RECEIVED										25



#endif
