/**************************************/
/* Description : AC interface File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 03:31:39  13 Jun 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef AC_INTERFACE_H
#define AC_INTERFACE_H

/*pre-build configuration (preprocessing)*/
void AC_vInit(void);
/*run time configuration*/
void AC_vEn(void);
void AC_vDis(void);
void AC_vIntEn(void);
void AC_vIntDis(void);
void AC_vBandGapOnAIN0_En(void);
void AC_vBandGapOnAIN0_Dis(void);
void AC_vAsInputCaptureTrigSignalEn(void);
void AC_vAsInputCaptureTrigSignalDis(void);
ErrorStatus_et AC_enuIntMode(uint8_kt u8ModeCpy); 
ErrorStatus_et AC_enuNegativeInputSrc(uint8_kt u8SrcCpy);/*warning: choosing any another option except AC_AIN1 will disable the ADC module*/
/*APIs*/
void AC_vSyncReadOutput(uint8_kt* pu8Output);
ErrorStatus_et AC_enuAsyncReadOutput(uint8_kt* pu8Output);
ErrorStatus_et AC_enuSetCallBack(pf pfCallBack);

/*********************OPTIONS******************************/
/*STATUS*/
#define AC_EN 1
#define AC_DIS 0
/*AC_INT_MODE*/
#define AC_OUTPUT_TOG            0
#define AC_Output_FALLING_EDGE   2
#define AC_Output_RISING_EDGE    3
/*AC_NEGATIVE_INPUT_SOURCE*/
#define AC_ADC0   0
#define AC_ADC1   1
#define AC_ADC2   2
#define AC_ADC3   3
#define AC_ADC4   4
#define AC_ADC5   5
#define AC_ADC6   6
#define AC_ADC7   7
#define AC_AIN1   8







#endif
