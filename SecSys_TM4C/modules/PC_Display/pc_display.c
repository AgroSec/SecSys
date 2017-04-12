/*-------------------Driver Includes-----------------*/
/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"
/*------Export interface---Self header Includes------*/
#include "pc_display.h"
/*-------------------Service Includes-----------------*/
#include "uart_handler.h"

/*-------------Global Variable Definitions------------*/

/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void PC_Display_Message(uint8_t *string1, uint32_t value, uint8_t *string2){
#if SERIAL_DEBUG_ACTIVE
	UART0_SendString(string1);
	UART0_SendUDecimal(value);
	UART0_SendString(string2);
	UART0_SendNewLine();
#endif
}
//EOF
