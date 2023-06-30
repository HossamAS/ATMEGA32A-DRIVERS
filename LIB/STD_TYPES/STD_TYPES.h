/**************************************/
/* Description : STD_Types header File*/
/* Author      : hossam               */
/* Version     : 0.1V                 */
/* Date        : 02:39:51  02 Jan 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned      char             uint8_kt;
typedef   signed 	  char              int8_kt;
typedef unsigned     short int        uint16_kt;
typedef   signed     short int         int16_kt;
typedef unsigned      long int        uint32_kt;
typedef   signed      long int         int32_kt;
typedef unsigned long long int        uint64_kt;
typedef   signed long long int         int64_kt;
typedef    double                     float32_kt;
typedef   long double                 float64_kt;

typedef enum{
EOK,
ENOK,
PARAM_OUT_OF_RANGE,
PARAM_NULL_PTR,
MULTI_OCCUR
}ErrorStatus_et;

typedef void (*pf)(void);
#define NULL_PTR (void*)0 

typedef union{
uint8_kt REG;
struct{
	uint8_kt Bit0:1;
	uint8_kt Bit1:1;
	uint8_kt Bit2:1;
	uint8_kt Bit3:1;
	uint8_kt Bit4:1;
	uint8_kt Bit5:1;
	uint8_kt Bit6:1;
	uint8_kt Bit7:1;
};
}uint8_ut;

typedef union{
uint16_kt REG;
struct{
	uint16_kt Bit0:1;
	uint16_kt Bit1:1;
	uint16_kt Bit2:1;
	uint16_kt Bit3:1;
	uint16_kt Bit4:1;
	uint16_kt Bit5:1;
	uint16_kt Bit6:1;
	uint16_kt Bit7:1;
	uint16_kt Bit8:1;
	uint16_kt Bit9:1;
	uint16_kt Bit10:1;
	uint16_kt Bit11:1;
	uint16_kt Bit12:1;
	uint16_kt Bit13:1;
	uint16_kt Bit14:1;
	uint16_kt Bit15:1;

};
}uint16_ut;

typedef union{
uint32_kt REG;
struct{
	uint32_kt Bit0:1;
	uint32_kt Bit1:1;
	uint32_kt Bit2:1;
	uint32_kt Bit3:1;
	uint32_kt Bit4:1;
	uint32_kt Bit5:1;
	uint32_kt Bit6:1;
	uint32_kt Bit7:1;
	uint32_kt Bit8:1;
	uint32_kt Bit9:1;
	uint32_kt Bit10:1;
	uint32_kt Bit11:1;
	uint32_kt Bit12:1;
	uint32_kt Bit13:1;
	uint32_kt Bit14:1;
	uint32_kt Bit15:1;
	uint32_kt Bit16:1;
	uint32_kt Bit17:1;
	uint32_kt Bit18:1;
	uint32_kt Bit19:1;
	uint32_kt Bit20:1;
	uint32_kt Bit21:1;
	uint32_kt Bit22:1;
	uint32_kt Bit23:1;
	uint32_kt Bit24:1;
	uint32_kt Bit25:1;
	uint32_kt Bit26:1;
	uint32_kt Bit27:1;
	uint32_kt Bit28:1;
	uint32_kt Bit29:1;
	uint32_kt Bit30:1;
	uint32_kt Bit31:1;
};
}uint32_ut;


typedef union{
uint64_kt REG;
struct{
	uint64_kt Bit0:1;
	uint64_kt Bit1:1;
	uint64_kt Bit2:1;
	uint64_kt Bit3:1;
	uint64_kt Bit4:1;
	uint64_kt Bit5:1;
	uint64_kt Bit6:1;
	uint64_kt Bit7:1;
	uint64_kt Bit8:1;
	uint64_kt Bit9:1;
	uint64_kt Bit10:1;
	uint64_kt Bit11:1;
	uint64_kt Bit12:1;
	uint64_kt Bit13:1;
	uint64_kt Bit14:1;
	uint64_kt Bit15:1;
	uint64_kt Bit16:1;
	uint64_kt Bit17:1;
	uint64_kt Bit18:1;
	uint64_kt Bit19:1;
	uint64_kt Bit20:1;
	uint64_kt Bit21:1;
	uint64_kt Bit22:1;
	uint64_kt Bit23:1;
	uint64_kt Bit24:1;
	uint64_kt Bit25:1;
	uint64_kt Bit26:1;
	uint64_kt Bit27:1;
	uint64_kt Bit28:1;
	uint64_kt Bit29:1;
	uint64_kt Bit30:1;
	uint64_kt Bit31:1;
	uint64_kt Bit32:1;
	uint64_kt Bit33:1;
	uint64_kt Bit34:1;
	uint64_kt Bit35:1;
	uint64_kt Bit36:1;
	uint64_kt Bit37:1;
	uint64_kt Bit38:1;
	uint64_kt Bit39:1;
	uint64_kt Bit40:1;
	uint64_kt Bit41:1;
	uint64_kt Bit42:1;
	uint64_kt Bit43:1;
	uint64_kt Bit44:1;
	uint64_kt Bit45:1;
	uint64_kt Bit46:1;
	uint64_kt Bit47:1;
	uint64_kt Bit48:1;
	uint64_kt Bit49:1;
	uint64_kt Bit50:1;
	uint64_kt Bit51:1;
	uint64_kt Bit52:1;
	uint64_kt Bit53:1;
	uint64_kt Bit54:1;
	uint64_kt Bit55:1;
	uint64_kt Bit56:1;
	uint64_kt Bit57:1;
	uint64_kt Bit58:1;
	uint64_kt Bit59:1;
	uint64_kt Bit60:1;
	uint64_kt Bit61:1;
	uint64_kt Bit62:1;
	uint64_kt Bit63:1;
};
}uint64_ut;





typedef union{
int8_kt REG;
struct{
	uint8_kt Bit0:1;
	uint8_kt Bit1:1;
	uint8_kt Bit2:1;
	uint8_kt Bit3:1;
	uint8_kt Bit4:1;
	uint8_kt Bit5:1;
	uint8_kt Bit6:1;
	uint8_kt Bit7:1;
};
}int8_ut;

typedef union{
int16_kt REG;
struct{
	uint16_kt Bit0:1;
	uint16_kt Bit1:1;
	uint16_kt Bit2:1;
	uint16_kt Bit3:1;
	uint16_kt Bit4:1;
	uint16_kt Bit5:1;
	uint16_kt Bit6:1;
	uint16_kt Bit7:1;
	uint16_kt Bit8:1;
	uint16_kt Bit9:1;
	uint16_kt Bit10:1;
	uint16_kt Bit11:1;
	uint16_kt Bit12:1;
	uint16_kt Bit13:1;
	uint16_kt Bit14:1;
	uint16_kt Bit15:1;

};
}int16_ut;

typedef union{
int32_kt REG;
struct{
	uint32_kt Bit0:1;
	uint32_kt Bit1:1;
	uint32_kt Bit2:1;
	uint32_kt Bit3:1;
	uint32_kt Bit4:1;
	uint32_kt Bit5:1;
	uint32_kt Bit6:1;
	uint32_kt Bit7:1;
	uint32_kt Bit8:1;
	uint32_kt Bit9:1;
	uint32_kt Bit10:1;
	uint32_kt Bit11:1;
	uint32_kt Bit12:1;
	uint32_kt Bit13:1;
	uint32_kt Bit14:1;
	uint32_kt Bit15:1;
	uint32_kt Bit16:1;
	uint32_kt Bit17:1;
	uint32_kt Bit18:1;
	uint32_kt Bit19:1;
	uint32_kt Bit20:1;
	uint32_kt Bit21:1;
	uint32_kt Bit22:1;
	uint32_kt Bit23:1;
	uint32_kt Bit24:1;
	uint32_kt Bit25:1;
	uint32_kt Bit26:1;
	uint32_kt Bit27:1;
	uint32_kt Bit28:1;
	uint32_kt Bit29:1;
	uint32_kt Bit30:1;
	uint32_kt Bit31:1;
};
}int32_ut;


typedef union{
int64_kt REG;
struct{
	uint64_kt Bit0:1;
	uint64_kt Bit1:1;
	uint64_kt Bit2:1;
	uint64_kt Bit3:1;
	uint64_kt Bit4:1;
	uint64_kt Bit5:1;
	uint64_kt Bit6:1;
	uint64_kt Bit7:1;
	uint64_kt Bit8:1;
	uint64_kt Bit9:1;
	uint64_kt Bit10:1;
	uint64_kt Bit11:1;
	uint64_kt Bit12:1;
	uint64_kt Bit13:1;
	uint64_kt Bit14:1;
	uint64_kt Bit15:1;
	uint64_kt Bit16:1;
	uint64_kt Bit17:1;
	uint64_kt Bit18:1;
	uint64_kt Bit19:1;
	uint64_kt Bit20:1;
	uint64_kt Bit21:1;
	uint64_kt Bit22:1;
	uint64_kt Bit23:1;
	uint64_kt Bit24:1;
	uint64_kt Bit25:1;
	uint64_kt Bit26:1;
	uint64_kt Bit27:1;
	uint64_kt Bit28:1;
	uint64_kt Bit29:1;
	uint64_kt Bit30:1;
	uint64_kt Bit31:1;
	uint64_kt Bit32:1;
	uint64_kt Bit33:1;
	uint64_kt Bit34:1;
	uint64_kt Bit35:1;
	uint64_kt Bit36:1;
	uint64_kt Bit37:1;
	uint64_kt Bit38:1;
	uint64_kt Bit39:1;
	uint64_kt Bit40:1;
	uint64_kt Bit41:1;
	uint64_kt Bit42:1;
	uint64_kt Bit43:1;
	uint64_kt Bit44:1;
	uint64_kt Bit45:1;
	uint64_kt Bit46:1;
	uint64_kt Bit47:1;
	uint64_kt Bit48:1;
	uint64_kt Bit49:1;
	uint64_kt Bit50:1;
	uint64_kt Bit51:1;
	uint64_kt Bit52:1;
	uint64_kt Bit53:1;
	uint64_kt Bit54:1;
	uint64_kt Bit55:1;
	uint64_kt Bit56:1;
	uint64_kt Bit57:1;
	uint64_kt Bit58:1;
	uint64_kt Bit59:1;
	uint64_kt Bit60:1;
	uint64_kt Bit61:1;
	uint64_kt Bit62:1;
	uint64_kt Bit63:1;
};
}int64_ut;















typedef union{
float32_kt REG;
struct{
	uint32_kt Bit0:1;
	uint32_kt Bit1:1;
	uint32_kt Bit2:1;
	uint32_kt Bit3:1;
	uint32_kt Bit4:1;
	uint32_kt Bit5:1;
	uint32_kt Bit6:1;
	uint32_kt Bit7:1;
	uint32_kt Bit8:1;
	uint32_kt Bit9:1;
	uint32_kt Bit10:1;
	uint32_kt Bit11:1;
	uint32_kt Bit12:1;
	uint32_kt Bit13:1;
	uint32_kt Bit14:1;
	uint32_kt Bit15:1;
	uint32_kt Bit16:1;
	uint32_kt Bit17:1;
	uint32_kt Bit18:1;
	uint32_kt Bit19:1;
	uint32_kt Bit20:1;
	uint32_kt Bit21:1;
	uint32_kt Bit22:1;
	uint32_kt Bit23:1;
	uint32_kt Bit24:1;
	uint32_kt Bit25:1;
	uint32_kt Bit26:1;
	uint32_kt Bit27:1;
	uint32_kt Bit28:1;
	uint32_kt Bit29:1;
	uint32_kt Bit30:1;
	uint32_kt Bit31:1;
};
}float32_ut;
typedef union{
float64_kt REG;
struct{
	uint64_kt Bit0:1;
	uint64_kt Bit1:1;
	uint64_kt Bit2:1;
	uint64_kt Bit3:1;
	uint64_kt Bit4:1;
	uint64_kt Bit5:1;
	uint64_kt Bit6:1;
	uint64_kt Bit7:1;
	uint64_kt Bit8:1;
	uint64_kt Bit9:1;
	uint64_kt Bit10:1;
	uint64_kt Bit11:1;
	uint64_kt Bit12:1;
	uint64_kt Bit13:1;
	uint64_kt Bit14:1;
	uint64_kt Bit15:1;
	uint64_kt Bit16:1;
	uint64_kt Bit17:1;
	uint64_kt Bit18:1;
	uint64_kt Bit19:1;
	uint64_kt Bit20:1;
	uint64_kt Bit21:1;
	uint64_kt Bit22:1;
	uint64_kt Bit23:1;
	uint64_kt Bit24:1;
	uint64_kt Bit25:1;
	uint64_kt Bit26:1;
	uint64_kt Bit27:1;
	uint64_kt Bit28:1;
	uint64_kt Bit29:1;
	uint64_kt Bit30:1;
	uint64_kt Bit31:1;
	uint64_kt Bit32:1;
	uint64_kt Bit33:1;
	uint64_kt Bit34:1;
	uint64_kt Bit35:1;
	uint64_kt Bit36:1;
	uint64_kt Bit37:1;
	uint64_kt Bit38:1;
	uint64_kt Bit39:1;
	uint64_kt Bit40:1;
	uint64_kt Bit41:1;
	uint64_kt Bit42:1;
	uint64_kt Bit43:1;
	uint64_kt Bit44:1;
	uint64_kt Bit45:1;
	uint64_kt Bit46:1;
	uint64_kt Bit47:1;
	uint64_kt Bit48:1;
	uint64_kt Bit49:1;
	uint64_kt Bit50:1;
	uint64_kt Bit51:1;
	uint64_kt Bit52:1;
	uint64_kt Bit53:1;
	uint64_kt Bit54:1;
	uint64_kt Bit55:1;
	uint64_kt Bit56:1;
	uint64_kt Bit57:1;
	uint64_kt Bit58:1;
	uint64_kt Bit59:1;
	uint64_kt Bit60:1;
	uint64_kt Bit61:1;
	uint64_kt Bit62:1;
	uint64_kt Bit63:1;
};
}float64_ut;



#endif
