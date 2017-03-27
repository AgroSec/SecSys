//system_hander.h
//Service layer
#ifndef SYS_HDL
#define SYS_HDL
/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"

/*-------------------Driver Includes-----------------*/
#include "driverlib/sysctl.h"

/*-------------------Macro Definitions----------------*/
#define SYS_clock_get SysCtlClockGet()		//Macro for getting clock speed

/*-------------------Function Definitions-------------*/
void SYS_clock_init(void);
void SYS_startup(void);
#endif
