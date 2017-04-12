/*---------------------OS Includes--------------------*/
//#include "os_hw.h"
#include "os_core.h"

/*-------------------Driver Includes-----------------*/
#include "driverlib/sysctl.h"

/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"

/*-----------------Application Includes---------------*/
#include "PIR.h"

/*-------------------Service Includes-----------------*/
#include "uart_handler.h"

/*-------------Global Variable Definitions------------*/

extern uint32_t PIR_A_Trigger_Nr;
extern uint32_t PIR_B_Trigger_Nr;
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void Process_PIR(void){  //function to read and process PIR state
/*	if(PIR_A_Trigger_Nr >= PIR_TRIGGERS_TO_ALARM){  //Check if it's necessary to raise alarm
		PIR_A_Alarm_Nr++;
		SendSMS(PIR_A);
		PC_Display_Message("PIR A Alarm raised: ", PIR_A_Alarm_Nr, " times.");
	}
	PIR_A_Trigger_Nr = 0;  //Reset the trigger counter
	if(PIR_B_Trigger_Nr >= PIR_TRIGGERS_TO_ALARM){
		PIR_B_Alarm_Nr++;
		SendSMS(PIR_B);
		PC_Display_Message("PIR B Alarm raised: ", PIR_B_Alarm_Nr, " times.");
	}
	PIR_B_Trigger_Nr = 0;*/
}

void Init_PIR(void){ 
	SysCtlDelay(Millis2Ticks(PIR_STARTUP_DELAY*1000));  //delay to stabilize PIR at power on
}
//EOF
