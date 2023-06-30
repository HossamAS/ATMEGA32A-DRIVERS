/**************************************/
/* Description : SREG program File    */
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 02:11:08  01 Jul 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/


#include "../../LIB/STD_MACROS/STD_MACROS.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "SREG_private.h"

inline void SREG_IntEn(void)
{
	SET_BIT(SREG,7);
}
inline void SREG_IntDis(void)
{
	CLR_BIT(SREG,7);
}

