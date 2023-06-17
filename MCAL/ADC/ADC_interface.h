/**************************************/
/* Description : ADC interface File   */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 11:03:51  12 Mar 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


/*pre-build configuration(pre-processing)*/
void ADC_vInit(void);

/*run-time configuration*/

ErrorStatus_et ADC_enuChannel(uint8_kt u8ChannelCpy);

ErrorStatus_et ADC_enuPrescaler(uint8_kt u8PrescalerCpy);

ErrorStatus_et ADC_enuAutoTrigSrc(uint8_kt u8AutoTrigSrcCpy);

ErrorStatus_et ADC_vSetCallBack(pf pfCallBackCpy);


void ADC_vEn(void);

void ADC_vDis(void);


void ADC_vAutoTrigEn(void);

void ADC_vAutoTrigDis(void);


void ADC_vIntEn(void);

void ADC_vIntDis(void);

/*APIs*/

void ADC_vSyncSingleRead(uint16_kt* u16ValueCpy);

void ADC_vSyncAutoRead(uint16_kt* u16ValueCpy);

void ADC_vAsyncRead(uint16_kt* u16ValueCpy);

void ADC_vStartConv(void);

/**********************************options************************************/

/******voltage reference mode*********/
#define ADC_AREF 0
#define ADC_AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF  1
#define ADC_INTERNAL_2_56V_WITH_EXTERNAL_CAPACITOR_AT_AREF 3

/****** ADC Left Adjust Result mode*********/
#define ADC_RIGHT_ADJUST 0
#define ADC_LEFT_ADJUST  1

/******ADC channels*********/
#define ADC_SINGLE_ADC0                       0
#define ADC_SINGLE_ADC1                       1
#define ADC_SINGLE_ADC2                       2
#define ADC_SINGLE_ADC3                       3
#define ADC_SINGLE_ADC4                       4
#define ADC_SINGLE_ADC5                       5
#define ADC_SINGLE_ADC6                       6
#define ADC_SINGLE_ADC7                       7
#define ADC_DIFF_POS_ADC0_NEG_ADC0_GAIN_10X   8  
#define ADC_DIFF_POS_ADC1_NEG_ADC0_GAIN_10X   9
#define ADC_DIFF_POS_ADC0_NEG_ADC0_GAIN_200X  10  
#define ADC_DIFF_POS_ADC1_NEG_ADC0_GAIN_200X  11       
#define ADC_DIFF_POS_ADC2_NEG_ADC2_GAIN_10X   12      
#define ADC_DIFF_POS_ADC3_NEG_ADC2_GAIN_10X   13   
#define ADC_DIFF_POS_ADC2_NEG_ADC2_GAIN_200X  14    
#define ADC_DIFF_POS_ADC3_NEG_ADC2_GAIN_200X  15    
#define ADC_DIFF_POS_ADC0_NEG_ADC1_GAIN_10X   16  
#define ADC_DIFF_POS_ADC1_NEG_ADC1_GAIN_10X   17   
#define ADC_DIFF_POS_ADC2_NEG_ADC1_GAIN_10X   18   
#define ADC_DIFF_POS_ADC3_NEG_ADC1_GAIN_10X   19   
#define ADC_DIFF_POS_ADC4_NEG_ADC1_GAIN_10X   20
#define ADC_DIFF_POS_ADC5_NEG_ADC1_GAIN_10X   21 
#define ADC_DIFF_POS_ADC6_NEG_ADC1_GAIN_10X   22 
#define ADC_DIFF_POS_ADC7_NEG_ADC1_GAIN_10X   23 
#define ADC_DIFF_POS_ADC0_NEG_ADC2_GAIN_10X   24 
#define ADC_DIFF_POS_ADC1_NEG_ADC2_GAIN_10X   25
#define ADC_DIFF_POS_ADC2_NEG_ADC2_GAIN_10X_  26
#define ADC_DIFF_POS_ADC3_NEG_ADC2_GAIN_10X_  27
#define ADC_DIFF_POS_ADC4_NEG_ADC2_GAIN_10X   28 
#define ADC_DIFF_POS_ADC5_NEG_ADC2_GAIN_10X   29 
#define ADC_DIFF_POS_ADC3_NEG_ADC2_GAIN_10X__ 30
#define ADC_SINGLE_1_22V                      31
#define ADC_SINGLE_0V                         32
   
/******ADC STATE*********/
#define ADC_DIS 0
#define ADC_EN  1
/******ADC PRESCALER*********/
#define ADC_FACTOR_2     0
#define ADC_FACTOR_4     2
#define ADC_FACTOR_8     3
#define ADC_FACTOR_16    4
#define ADC_FACTOR_32    5
#define ADC_FACTOR_64    6
#define ADC_FACTOR_128   7
/******ADC TRIGGER SOURCE*********/
#define ADC_FREE_RUNNING_MODE              0
#define ADC_ANALOG_COMPARATOR              1
#define ADC_EXTERNAL_INTERRUPT_REQUEST_0   2
#define ADC_TIMER0_COMPARE_MATCH           3
#define ADC_TIMER0_OVERFLOW                4
#define ADC_TIMER1_COMPARE_MATCH_B         5
#define ADC_TIMER1_OVERFLOW                6
#define ADC_TIMER1_CAPTURE_EVENT           7
#define ADC_SINGLE_CONVERSION              8

#endif
