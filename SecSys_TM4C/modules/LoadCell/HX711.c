/*---------------------OS Includes--------------------*/

/*-------------------Driver Includes------------------*/
#include "driverlib/sysctl.h"
/*-------------------Type Includes--------------------*/
#include <stdint.h>
/*-------------------Configuration Includes-----------*/

/*------Export interface---Self header Includes-------*/
#include "HX711.h"

/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
/*-----------------Application Includes---------------*/

/*-------------Global Variable Definitions------------*/

/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
//  DOUT -  input - PortE, pin 2
//   SLK - output - PortE, pin 3
//  GPIO_SetPin(ports_t port, uint8_t pin, uint8_t status)
//  GPIOPinRead(GPIO_PORTE_BASE,GPIO_INT_PIN_2);

uint32_t ReadCount(void){
	uint32_t Count=0;
	uint8_t i=0;
	
	GPIO_SetPin(PortE, 1<<3, 0);		// set SLK to LOW
	Count=0;
	while(GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_2) == GPIO_PIN_2)	// wait for DOUT to go LOW
	{;}
		
	for (i=0;i<24;i++)
	{
			GPIO_SetPin(PortE, 1<<3, 1<<3);				// set SLK to HIGH
			Count=Count<<1;		// shift Count by 1 bit to the left to make room for new read
			GPIO_SetPin(PortE, 1<<3, 0);				// set SLK to LOW
			if(GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_2) == GPIO_PIN_2) Count++;	// if DOUT if HIGH, increment Count (set LSB in Count to 1)
			
	}
	GPIO_SetPin(PortE, 1<<3, 1<<3);					// set SLK to HIGH (25th bit)
	Count=Count^0x800000;	// data is in 2's complement
	GPIO_SetPin(PortE, 1<<3, 0);					// set SLK to LOW (25th bit)
	return(Count);
} 

// EOF
