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
#include "pc_display.h"
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
	PC_Display_Message("Driver init done...",0," ");
}

void InitApplications(void) {
	//Function calls to init applications
#if GSM_AVAILABLE
	PowerOnGSM();
#endif
	
#if PIR_AVAILABLE
	Init_PIR();
#endif
	PC_Display_Message("Applications init done...",0," ");
	SendSMS(System_Ready);
}
//EOF
