/**************************************/
/* Description : SREG header File     */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 00:17:23  14 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef SREG_H
#define SREG_H
#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "SREG_private.h"


#define SREG_I_EN()     SET_BIT(SREG,7)
#define SREG_I_DIS()    CLR_BIT(SREG,7)




#endif
