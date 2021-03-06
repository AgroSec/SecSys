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
#include "hx711_handler.h"
/*-----------------Application Includes---------------*/
#include "LoadCell.h"
#include "PIR.h"
#include "GSM.h"
#include "pc_display.h"
#include "DS18B20.h"

/*-----------------Macro Definitions------------------*/
#define PF3_ON	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,GPIO_PIN_3);
#define PF3_OFF	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,0);
#define PF2_ON	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,GPIO_PIN_2);
#define PF2_OFF	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0);
#define PF1_ON	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_PIN_1);
#define PF1_OFF	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0);
/*-------------Global Variable Definitions------------*/
extern int32_t GSMModule;
#if HX711_AVAILABLE
extern uint32_t HX711_CalibVal;
	extern uint32_t HX711_ReadCount(void);
	extern int8_t HX711_Check(uint32_t val);
#endif	// HX711_AVAILABLE
#if TEMP_AVAILABLE
#endif	// HX711_AVAILABLE
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void CYCL_10ms(void) {
	//Function calls that runs only every 10 ms
	//CheckForSMS();
}

void CYCL_50ms(void) {
	//Function calls that runs only every 50 ms
	PF1_OFF
}

void CYCL_100ms(void) {
	//Function calls that runs only every 100 ms
	
		static uint32_t loopvar = 1;
#if HX711_AVAILABLE
	uint32_t currentRead = HX711_ReadCount();
	int8_t check = HX711_Check(currentRead);
	int32_t currentValue;
	
	if (check ==  1) 
	{ // positive value, above sensitivity limit
			PC_Display_Message_FP(">>>Tripped!!", -32767, 0, "");
			#if GSM_AVAILABLE
					if(!(loopvar % 10))	// execute each second
					{
							SendSMS(Wire_1_Pull);
	}
			#endif	// GSM_AVAILABLE
		}
	if (check ==  -1) 
	{ // negative value, above sensitivity limit
			PC_Display_Message_FP(">>>Cut!!", -32767, 0, "");
			#if GSM_AVAILABLE
					if(!(loopvar % 10))	// execute each second
					{
							SendSMS(Wire_1_Cut);
	}
			#endif	// GSM_AVAILABLE
		}
	if (check ==  0) 
	{ // nil value, between upper and lower sensitivity limits
			PC_Display_Message_FP(">>All good.", -32767, 0, "");
	}
	
	currentValue = (int32_t)(100.0*((int64_t)currentRead - (int64_t)HX711_CalibVal) / conversionFactor);
		PC_Display_Message_FP("", currentValue, 2, "");
	//GPIO_SetPin(PortE, 1<<3, 1<<3);		// set SLK pin to HIGH for powersave	
#endif
	
		loopvar++;
}

void CYCL_500ms(void) 
{
	//Function calls that runs only every 500 ms
}

void CYCL_1000ms(void)
{
	static uint32_t counter = 1;
	//Function calls that runs only every 1000 ms
	PF1_ON
	PC_Display_Message("Seconds passed: ", counter, " ");

	if(!(counter%2)) {
		//Every 2 second code
		#if GSM_AVAILABLE
			OS_Wait(&GSMModule);
			GSMprocessMessage(1);  //Read SMS
			OS_Signal(&GSMModule);
		#endif	// GSM_AVAILABLE
	}
	if(!(counter%3)) {
		//Every 3 second code
	}
	if(!(counter%6)) {
		//Every 10 second code
		//GSMprocessMessage(1);
	}
	#if TEMP_AVAILABLE	
	DisableInterrupts();
		call_DS();
	EnableInterrupts();
	#endif	// TEMP_AVAILABLE
#if PIR_AVAILABLE
	if(!counter%PIR_TRIGGERS_TIMEFRAME) {  //this case is 10 seconds
		//Every PIR_TRIGGERS_TIMEFRAME nr of second code
		Process_PIR();
	}
#endif
#if GSM_AVAILABLE
	if(!counter%600){  //every 10 minutes
		OS_Wait(&GSMModule);
		SendSMS(Status);
		OS_Signal(&GSMModule);
	}
	counter++;
#endif	// GSM_AVAILABLE
}
//EOF
