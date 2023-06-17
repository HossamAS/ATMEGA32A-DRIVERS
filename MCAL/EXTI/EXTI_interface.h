/**************************************/
/* Description : EXTI interface File  */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 03:51:08  13 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef INT0_H
#define INT0_H

#define INT_LOW_LEVEL 				 0
#define INT_ANY_LOGICAL_CHANGE		 1
#define INT_FALLING_EDGE			 2
#define INT_RISING_EDGE 			 3

void INT_vInit(void);
ErrorStatus_et INT_vEnable(uint8_kt u8IntNum);
ErrorStatus_et INT_vDisable(uint8_kt u8IntNum);
ErrorStatus_et INT_enuIntSense(uint8_kt u8IntNum,uint8_kt u8SenseCpy);
ErrorStatus_et INT_enuSetCallBack(uint8_kt u8IntNum,pf pfCallBackCpy);


#endif
