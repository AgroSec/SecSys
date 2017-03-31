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

/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
#include "uart_handler.h"
/*-------------Global Variable Definitions------------*/

/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void InitDrivers(void) {
	//Function calls to init drivers
	UART0_Init();
	UART2_Init();
	GPIO_InitPortOutput(PortF,GPIO_PIN_2);
	UART0_SendString("Driver init done...");
	UART0_SendNewLine();
}

void InitApplications(void) {
	//Function calls to init applications
	UART0_SendString("Applications init done...");
	UART0_SendNewLine();
}
//EOF
