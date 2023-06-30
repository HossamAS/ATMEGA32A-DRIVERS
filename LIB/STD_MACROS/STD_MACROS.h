/***************************************/
/* Description : STD_Macros header File*/
/* Author      : hossam                */
/* Version     : 0.1V                  */
/* Date        : 02:24:01  02 Jan 2023 */
/* History     : 0.1V Initial Creation */
/***************************************/




#ifndef STD_MACROS_H
#define STD_MACROS_H

#define SET_BIT(Reg,BitNum)          ((Reg)|=1ul<<(BitNum))
#define CLR_BIT(Reg,BitNum)          ((Reg)&=~(1ul<<(BitNum)))
#define TOG_BIT(Reg,BitNum)          ((Reg)^=(1ul<<(BitNum)))

#define TOG_BIT_FLD(Bit)             ((Bit)^=1)
					         
#define READ_BIT(Reg,BitNum)         (((Reg)>>(BitNum))&1)
#define WRITE_BIT(Reg,BitNum,State)  (if((State)==1){SET_BIT(Reg,BitNum);}else{CLR_BIT(Reg,BitNum);})

#define ROT_L(Reg,BitNum)            (((Reg)<<(BitNum))|((Reg)>>(sizeof(Reg)-(BitNum))))
#define ROT_R(Reg,BitNum)            (((Reg)>>(BitNum))|((Reg)<<(sizeof(Reg)-(BitNum))))


#endif
