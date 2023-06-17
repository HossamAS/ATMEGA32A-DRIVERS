# ATMEGA32A-DRIVERS
###### this is the most used MCAL and HAL drivers based on atmega32a 
the drivers structed based on SIX files:
                1-DRIVER_private.c
                2-DRIVER_private.h
                3-DRIVER_config.c
                4-DRIVER_config.h
                5-DRIVER_interface.h
                6-DRIVER_program.h

1-DRIVER_private.c : used to implement the driver private functions, variables or callback functions which can be used in program file only by "the developer" (like static).


2-DRIVER_private.h : used to implement the driver casted register using struct and union Pattern or to implement the prototype of private functions, variables or callback functions those can be used in program file only (like static). 


3-DRIVER_config.c: used to implement the linking time configuration struct or array of structs that can be configured by the "user". 


4-DRIVER_config.h: used to implement the pre-build configuration which are the preprocessor directives that can be configured by the "user". 


5-DRIVER_interface.h:used to implement the prototypes of the APIs and configuration preprocessor parameters that can be used by the "user" in the configuration files or estimating the limitation of the input parameters for each API to avoid PARAM_OUT_OF_RANGE state.


6-DRIVER_program.h:used to implement the core APIs and ISRs by the "developer".


notes:
 
   1-the user can write to the configuration files only and use the interface parameters as pathing parameters to the arguments of the APIs to avoid PARAM_OUT_OF_RANGE or PARAM_NULL_PTR error states as return values.
  
   2-the HAL drivers uses mix between link-time, pre-build configuration type,and run-time configuration APIs.
 
   3-the MCAL drivers uses pre-build configuration type and run-time configuration APIs.
 
   4-the drivers have the including of the files based on the current structure of the folders so please be careful to avoid "there are no such file" preprocessing error.
                     
