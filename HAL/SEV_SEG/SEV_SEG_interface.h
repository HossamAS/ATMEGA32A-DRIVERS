/*****************************************/
/* Description : Sev Seg interface h File*/
/* Author      : hossam                  */
/* Version     : 0.1V                    */
/* Date        : 10:52:34  03 Jan 2023   */
/* History     : 0.1V Initial Creation   */
/*****************************************/




#ifndef SEV_SEG_H
#define SEV_SEG_H

#define COMMON_ANODE   1
#define COMMON_CATHODE  0

#define DOT_ON   1
#define DOT_OFF  0

#define SEV_SEG_ZERO            0
#define SEV_SEG_ONE             1
#define SEV_SEG_TWO             2
#define SEV_SEG_THREE           3
#define SEV_SEG_FOUR            4
#define SEV_SEG_FIVE            5
#define SEV_SEG_SIX             6
#define SEV_SEG_SEVEN           7
#define SEV_SEG_EIGHT           8
#define SEV_SEG_NINE            9
#define SEV_SEG_A               10
#define SEV_SEG_B               11
#define SEV_SEG_C               12
#define SEV_SEG_D               13
#define SEV_SEG_E               14
#define SEV_SEG_F               15
#define SEV_SEG_CLEAR           16

ErrorStatus_et SEV_SEG_enuDisp(uint8_kt u8SevSegIdCpy,uint8_kt u8CommandCpy);


#endif
