//ssi_handler.c
//Service layer

/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"

/*-------------------HW define Includes--------------*/
#include "inc/hw_memmap.h"

/*-------------------Driver Includes-----------------*/
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/ssi.h"
#include "driverlib/sysctl.h"

/*-------------------Service Includes-----------------*/
#include "system_handler.h"

/*------Export interface---Self header Includes------*/
#include "ssi_handler.h"

/*-------------------Macro Definitions----------------*/
#define LCD_DataRate		(3125000)
#define LCD_DataWidth		(8)
#define Shift_Register_DataRate		(xyz)
#define Shift_Register_DataWidth	(xyz)

/*-------------------Function Definitions-------------*/
void SSI_lcd_init(void)
{
	unsigned long input_clock, input_clock1;
	//unsigned long clock_divider = 6;
	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);		//SSI 0 enable 
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);	//Port A enable
	
	SSIDisable(SSI0_BASE);												 //Disable SSI0

	GPIOPinConfigure(GPIO_PA2_SSI0CLK);		//PA2 - Clock
	GPIOPinConfigure(GPIO_PA3_SSI0FSS);		//PA3 - Slave Select
	GPIOPinConfigure(GPIO_PA5_SSI0TX);		//PA5 - TX
	GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_5);	// Configure PA2,PA3 and PA5 as SSI
	
	SSIClockSourceSet(SSI0_BASE, SSI_CLOCK_SYSTEM);	// Set the SSI clock source
	//SSI_CLOCK_SYSTEM for system clock, SSI_CLOCK_PIOSC for PIOSC precision internal oscilator
	//input_clock1 = SSIClockSourceGet(SSI0_BASE);		// Get the clock source of the SSI, NOT the clock speed
	
	//Peripherial base, Input clock, Frame format, Mode, Bit Data Rate,	Data Width	
	SSIConfigSetExpClk(SSI0_BASE, SYS_clock_get, SSI_FRF_MOTO_MODE_0, SSI_MODE_MASTER, LCD_DataRate ,LCD_DataWidth);
	SSIEnable(SSI0_BASE);				//Enable SSI
}
/*
void SSI_shift_register_init(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);		//SSI 3 enable 
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);	//Port D enable
	
	SSIDisable(SSI3_BASE);												//Disable SSI3
	GPIOPinConfigure(GPIO_PD0_SSI3CLK);		//PD0 - Clock
	GPIOPinConfigure(GPIO_PD1_SSI3FSS);		//PD1 - Slave Select
	GPIOPinConfigure(GPIO_PD2_SSI3RX);		//PD2 - RX
	GPIOPinConfigure(GPIO_PD3_SSI3TX);		//PD3 - TX
	
	SSIClockSourceSet(SSI3_BASE, SSI_CLOCK_SYSTEM);	// Set the SSI clock source
	//SSI_CLOCK_SYSTEM for system clock, SSI_CLOCK_PIOSC for PIOSC precision internal oscilator
	
	//Peripherial base, Input clock, Frame format, Mode, Bit Data Rate,	Data Width	
	//SSIConfigSetExpClk(SSI3_BASE, SYS_clock_get, SSI_FRF_MOTO_MODE_0, SSI_MODE_MASTER, Shift_Register_DataRate ,Shift_Register_DataWidth);
}
*/
void SSI_write(unsigned char message)
{
	SSIDataPut(SSI0_BASE,message);
}

