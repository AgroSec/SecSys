//startup_handler.c
//Service layer

/*-------------------Configuration Includes-----------*/

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
/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
#include "uart_handler.h"
/*-------------Global Variable Definitions------------*/

/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void InitDrivers(void) {
	//Function calls to init drivers
	UART0_Init();
	
#if GSM_AVAILABLE
	UART2_Init();
#endif
	
#if HX711_AVAILABLE
	GPIO_InitPortInput(PortE, GPIO_PIN_2, GPIO_PIN_TYPE_STD_WPU);	// input init for port PE2
	GPIO_InitPortOutput(PortE, GPIO_PIN_3);	// output init for port PE3 - SLK_HX711
	GPIO_InitPortOutput(PortF, GPIO_PIN_2);
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
