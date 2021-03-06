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
#include "LoadCell.h"
#include "pc_display.h"
#include "DS18B20.h"
/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
#include "uart_handler.h"
/*-------------Global Variable Definitions------------*/
#if HX711_AVAILABLE
extern uint32_t HX711_CalibVal;
	extern uint32_t HX711_Calibrate(void);
#endif	// HX711_AVAILABLE
#if TEMP_AVAILABLE
#endif	// TEMP_AVAILABLE
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void InitDrivers(void) {
	//Function calls to init drivers
	UART0_Init();
	PC_Display_Message("System startup in progress...", 0, "");
	
#if GSM_AVAILABLE
	UART2_Init();
	PC_Display_Message("UART 2 Ready...", 0, "");
#endif
	
#if HX711_AVAILABLE
	GPIO_InitPortInput(PortE, GPIO_PIN_2, GPIO_PIN_TYPE_STD_WPU);	// input init for port PE2
	GPIO_InitPortOutput(PortE, GPIO_PIN_3);	// output init for port PE3 - SLK_HX711
	GPIO_InitPortOutput(PortF, GPIO_PIN_2);
	
	PC_Display_Message("Calibrating HX711...", 0, "");
	
	HX711_CalibVal = HX711_Calibrate();
	
	PC_Display_Message("HX711 Calibration value is : ", HX711_CalibVal, "");
#endif
#if TEMP_AVAILABLE
	GPIO_InitPortOutput(OW_port1, OW_pin1);
	GPIO_SetPin(OW_port1, OW_pin1, OW_pin1);
	init_DS();
#endif	// TEMP_AVAILABLE
	PC_Display_Message("Driver init done...",0," ");
}

void InitApplications(void) {
	//Function calls to init applications
#if GSM_AVAILABLE
	PowerOnGSM();
	PC_Display_Message("GSM Ready...", 0, "");
#endif
	
#if PIR_AVAILABLE
	Init_PIR();
	PC_Display_Message("PIR Ready...", 0, "");
	SendSMS(System_Ready);
#endif
	PC_Display_Message("Applications init done...",0," ");

}
//EOF
