//startup_handler.c
//Service layer

/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"
/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"
/*-------------------HW define Includes--------------*/

/*-------------------Driver Includes-----------------*/

/*------Export interface---Self header Includes------*/
#include "startup_handler.h"
/*-----------------Application Includes---------------*/
#include "GSM.h"
#include "PIR.h"
#include "HX711.h"
/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
#include "uart_handler.h"
/*-------------Global Variable Definitions------------*/
extern uint32_t HX711_CalibVal;
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void InitDrivers(void) {
	//Function calls to init drivers
	UART0_Init();
	UART0_SendString("System startup in progress...");
	UART0_SendNewLine();
	
#if GSM_AVAILABLE
	UART2_Init();
#endif
	
#if HX711_AVAILABLE
	GPIO_InitPortInput(PortE, GPIO_PIN_2, GPIO_PIN_TYPE_STD_WPU);	// input init for port PE2
	GPIO_InitPortOutput(PortE, GPIO_PIN_3);	// output init for port PE3 - SLK_HX711
	GPIO_InitPortOutput(PortF, GPIO_PIN_2);
	
	UART0_SendString("Calibrating HX711...");
	UART0_SendNewLine();
	
	HX711_CalibVal = HX711_Calibrate();
	
	UART0_SendString("HX711 Calibration value is : ");
	UART0_SendUDecimal(HX711_CalibVal);
	UART0_SendNewLine();
#endif
	
	UART0_SendString("Driver init done...");
	UART0_SendNewLine();
}

void InitApplications(void) {
	//Function calls to init applications
#if GSM_AVAILABLE
	PowerOnGSM();
#endif
	
#if PIR_AVAILABLE
	Init_PIR();
#endif
	
	UART0_SendString("Applications init done...");
	UART0_SendNewLine();
}
//EOF
