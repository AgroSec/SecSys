//system_handler.c
//Service layer

/*-------------------Configuration Includes-----------*/
#include "compile_switches.h"
/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"

/*-------------------HW define Includes--------------*/

/*-------------------Driver Includes-----------------*/
#include "driverlib/sysctl.h"

/*------Export interface---Self header Includes------*/
#include "system_handler.h"

/*-------------------Service Includes----------------*/
#include "adc_handler.h"
#include "comparator_handler.h"
#include "gpio_handler.h"
#include "interrupt_handler.h"
#include "pwm_handler.h"
#include "timer_handler.h"
#include "UART.h"
/*-------------------Application Includes----------------*/
#include "accelerometer_handler.h"
#include "cyclic_activity_handler.h"
#include "lcd_handler.h"
#include "motion_handler.h"
/*-------------------Macro Definitions----------------*/

/*-------------Global Variable Definitions------------*/

/*-------------------Function Definitions-------------*/
void SYS_clock_init(void)
{
	//SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_OSC_INT | SYSCTL_USE_OSC);	//Sets the use of PIOSC (precision internal oscilator) as clock source, 16 MHz
	//SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ| SYSCTL_OSC_MAIN);    // Setup the system clock to run at 50 Mhz from PLL with crystal reference
	//SysCtlClockSet(SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);	//
		
										// Set the clocking to run directly from the PLL at 20 MHz.
										// The following code:
										// -sets the system clock divider to 10 (200 MHz PLL divide by 10 = 20 MHz)
										// -sets the system clock to use the PLL
										// -uses the main oscillator
										// -configures for use of 16 MHz crystal/oscillator input
		
	//SysCtlClockSet(SYSCTL_SYSDIV_15 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ| SYSCTL_OSC_MAIN);	// Configure to run at 13.33 MHz from the PLL using a 16 MHz crystal as the input.
	/*
	This function configures the clocking of the device. The input crystal frequency, oscillator to be
	used, use of the PLL, and the system clock divider are all configured with this function.
	The ui32Config parameter is the logical OR of several different values, many of which are
	grouped into sets where only one can be chosen.
	
	The system clock divider is chosen with one of the following values: SYSCTL_SYSDIV_1,
	SYSCTL_SYSDIV_2, SYSCTL_SYSDIV_3, ... SYSCTL_SYSDIV_64.
	The use of the PLL is chosen with either SYSCTL_USE_PLL or SYSCTL_USE_OSC.
	The external crystal frequency is chosen with one of the following values:
	SYSCTL_XTAL_4MHZ, SYSCTL_XTAL_4_09MHZ, SYSCTL_XTAL_4_91MHZ,
	SYSCTL_XTAL_5MHZ, SYSCTL_XTAL_5_12MHZ, SYSCTL_XTAL_6MHZ,
	SYSCTL_XTAL_6_14MHZ, SYSCTL_XTAL_7_37MHZ, SYSCTL_XTAL_8MHZ,
	SYSCTL_XTAL_8_19MHZ, SYSCTL_XTAL_10MHZ, SYSCTL_XTAL_12MHZ,
	SYSCTL_XTAL_12_2MHZ, SYSCTL_XTAL_13_5MHZ, SYSCTL_XTAL_14_3MHZ,
	SYSCTL_XTAL_16MHZ, SYSCTL_XTAL_16_3MHZ, SYSCTL_XTAL_18MHZ,
	SYSCTL_XTAL_20MHZ, SYSCTL_XTAL_24MHZ, or SYSCTL_XTAL_25MHz. Values
	below SYSCTL_XTAL_5MHZ are not valid when the PLL is in operation.
	The oscillator source is chosen with one of the following values: SYSCTL_OSC_MAIN,
	SYSCTL_OSC_INT, SYSCTL_OSC_INT4, SYSCTL_OSC_INT30, or SYSCTL_OSC_EXT32.
	SYSCTL_OSC_EXT32 is only available on devices with the hibernate module, and then only
	when the hibernate module has been enabled.
	The internal and main oscillators are disabled with the SYSCTL_INT_OSC_DIS and
	SYSCTL_MAIN_OSC_DIS flags, respectively. The external oscillator must be enabled in order
	to use an external clock source. Note that attempts to disable the oscillator used to clock the
	device is prevented by the hardware.
	To clock the system from an external source (such as an external crystal oscillator), use
	SYSCTL_USE_OSC j SYSCTL_OSC_MAIN. To clock the system from the main oscillator,
	use SYSCTL_USE_OSC j SYSCTL_OSC_MAIN. To clock the system from the PLL, use
	SYSCTL_USE_PLL j SYSCTL_OSC_MAIN, and select the appropriate crystal with one of
	the SYSCTL_XTAL_xxx values.
	*/
}
void SYS_startup(void)
{
/*
	#endif
	
	#if !Full_SW //Initialize modules under development
		//COMP_mic_input_init();		//Disabled temporarly	
		//PWM_Red_led_init(1000);		//Initialize PWM for Red led blink
		//TIMER_cyclic_50ms_init();			//Initialize 50 mili second timer
		//TIMER_cyclic_1s_init();				//Initialize 1 second timer	
		//ADC_Light_sensor_init();				//Initialize ADC for light sensors	
		//ADC_Temperature_sensor_init();	//Initialize ADC for temperature sensor
		//Accelerometer_init();
	#endif

	clock2 = SYS_clock_get;		//clock after modules initialized
	if(clock1 == clock2)			//just to check if clock speed is changed in other modules
	{
		Int_Master_Enable();		//Global interrupt enable
	}*/
}
//EOF

