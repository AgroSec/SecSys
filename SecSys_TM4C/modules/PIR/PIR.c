/*---------------------OS Includes--------------------*/
//#include "os_hw.h"
#include "os_core.h"

/*-------------------Driver Includes-----------------*/
#include "driverlib/sysctl.h"

/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"

/*------Export interface---Self header Includes------*/
#include "PIR.h"

/*-------------------Service Includes-----------------*/
#include "uart_handler.h"

/*-----------------Application Includes---------------*/
#include "GSM.h"

/*-------------Global Variable Definitions------------*/
uint8_t PIR_Trigger_Source = 0;

/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void Process_PIR(void){  //function to read and process PIR state
	static uint32_t PIR_A_TriggerNr = 0;
	static uint32_t PIR_B_TriggerNr = 0;
	if(PIR_Trigger_Source == 'A'){
		PIR_A_TriggerNr++;
		//TODO
	}
	else if(PIR_Trigger_Source == 'B'){
		PIR_B_TriggerNr++;
		//TODO
	}
}

void Init_PIR(void){ 
	SysCtlDelay(Millis2Ticks(PIR_STARTUP_DELAY*1000));  //delay to stabilize PIR at power on
}
//EOF
