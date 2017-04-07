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
/*-------------Global Variable Definitions------------*/
extern uint32_t HX711_CalibVal;
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void CYCL_10ms(void) {
	//Function calls that runs only every 10 ms
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
		UART0_SendString("...............Tripped!!");
		UART0_SendNewLine();
	}
	if (check ==  -1) 
	{ // negative value, above sensitivity limit
		UART0_SendString("...............Cut!!");
		UART0_SendNewLine();
	}
	if (check ==  0) 
	{ // nil value, between upper and lower sensitivity limits
		UART0_SendString("...............All good.");
		UART0_SendNewLine();
	}
	
	currentValue = (int32_t)(100.0*((int64_t)currentRead - (int64_t)HX711_CalibVal) / conversionFactor);
	UART0_SendFloat2(currentValue);
	UART0_SendNewLine();
	//GPIO_SetPin(PortE, 1<<3, 1<<3);		// set SLK pin to HIGH for powersave	
#endif
	
}

void CYCL_500ms(void) {
	//Function calls that runs only every 500 ms
}

void CYCL_1000ms(void) {
	//Function calls that runs only every 1000 ms
	UART0_SendString("Calibration value is.........................");
	UART0_SendUDecimal(HX711_CalibVal);
	UART0_SendNewLine();
	
	UART0_SendString("1 second passed...");
	UART0_SendNewLine();

}

//EOF

