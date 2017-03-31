//cyclic_activity_handler.c
//Service layer

/*-------------------Configuration Includes-----------*/

/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"

/*-------------------HW define Includes--------------*/

/*-------------------Driver Includes-----------------*/

/*------Export interface---Self header Includes------*/
#include "cyclic_activity_handler.h"

/*-------------------Service Includes-----------------*/
#include "uart_handler.h"
/*-------------Global Variable Definitions------------*/

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
}

void CYCL_500ms(void) {
	//Function calls that runs only every 500 ms
}

void CYCL_1000ms(void) {
	//Function calls that runs only every 1000 ms
	UART0_SendString("1 second passed...");
	UART0_SendNewLine();
}
//EOF
