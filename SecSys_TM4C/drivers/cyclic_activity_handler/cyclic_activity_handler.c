//cyclic_activity_handler.c
//Service layer

/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"
/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"
#include <math.h>
/*-------------------HW define Includes--------------*/

/*-------------------Driver Includes-----------------*/

/*------Export interface---Self header Includes------*/
#include "cyclic_activity_handler.h"

/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
#include "uart_handler.h"
/*-----------------Application Includes---------------*/
#include "HX711.h"
#include "PIR.h"
#include "GSM.h"
#include "pc_display.h"
/*-------------Global Variable Definitions------------*/
extern int32_t GSMModule;
extern uint32_t HX711_CalibVal;
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void CYCL_10ms(void) {
	//Function calls that runs only every 10 ms
	//CheckForSMS();
}

void CYCL_50ms(void) {
	//Function calls that runs only every 50 ms
}

void CYCL_100ms(void) {
	//Function calls that runs only every 100 ms
	
#if HX711_AVAILABLE
	uint32_t currentRead = HX711_ReadCount();
	int8_t check = HX711_Check(currentRead);
	int32_t currentValue;
	
	if (check ==  1) 
	{ // positive value, above sensitivity limit
		PC_Display_Message("...............Tripped!!", 0, "");
	}
	if (check ==  -1) 
	{ // negative value, above sensitivity limit
		PC_Display_Message("...............Cut!!", 0, "");
	}
	if (check ==  0) 
	{ // nil value, between upper and lower sensitivity limits
		PC_Display_Message("...............All good.", 0, "");
	}
	
	currentValue = (int32_t)(100.0*((int64_t)currentRead - (int64_t)HX711_CalibVal) / conversionFactor);
	PC_Display_Message("", currentValue, "");
	//GPIO_SetPin(PortE, 1<<3, 1<<3);		// set SLK pin to HIGH for powersave	
#endif
	
}

void CYCL_500ms(void) {
	//Function calls that runs only every 500 ms
}

void CYCL_1000ms(void) {
	static uint32_t counter = 1;
	//Function calls that runs only every 1000 ms
	PC_Display_Message("Seconds passed: ", counter, " ");

	if(!counter%2) {
		//Every 2 second code
	}
	if(!counter%3) {
		//Every 3 second code
	}
#if PIR_AVAILABLE
	if(!counter%PIR_TRIGGERS_TIMEFRAME) {  //this case is 5 seconds
		//Every PIR_TRIGGERS_TIMEFRAME nr of second code
		Process_PIR();
	}
#endif
	if(!counter%600){  //every 10 minutes
		OS_Wait(&GSMModule);
		SendSMS(Status);
		OS_Signal(&GSMModule);
	}
	counter++;
}
//EOF
