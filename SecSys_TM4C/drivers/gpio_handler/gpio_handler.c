//gpio_handler.c
//Service layer
/*-------------------Configuration Includes-----------*/
//#include "compile_switches.h"
/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"
//#include "custom_types.h"
/*-------------------HW define Includes--------------*/
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

/*-------------------Driver Includes-----------------*/
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

/*------Export interface---Self header Includes------*/
#include "gpio_handler.h"

/*-------------------Macro Definitions----------------*/
//#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
//#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))

/*-------------------Function Definitions-------------*/
uint8_t GPIO_InitPortOutput(ports_t port, uint8_t pin){
	switch (port) {
		case PortA:  //PortA 
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);  //Enable clock on port A
			while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));
			GPIO_PORTA_LOCK_R = 0x4C4F434B;  //Unlock GPIO Port D
			GPIO_PORTA_CR_R |= 0xFF;  //Allow changes to PD7-0
		
			GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, pin);  //Set as GPIO Output
			GPIODirModeSet(GPIO_PORTA_BASE, pin, GPIO_DIR_MODE_OUT);  //Set direction Output
			GPIOPadConfigSet(GPIO_PORTA_BASE, pin, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD); //Configure pin
			GPIOPinWrite(GPIO_PORTA_BASE, pin, 0);
			break;
		
		case PortB:  //PortB
			//Need to unlock
			GPIOPinWrite(GPIO_PORTB_BASE, pin, 0);
			break;
		
		case PortC:  //PortC
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);  //Enable clock on port C
			while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));
			if(pin & (GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3)){
				GPIO_PORTC_LOCK_R = 0x4C4F434B; //Unlock GPIO PC0-3 if necessary
			}
			GPIO_PORTC_CR_R |= 0xFF;  //Allow changes to PC7-0

			GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, pin);
			GPIODirModeSet(GPIO_PORTC_BASE, pin, GPIO_DIR_MODE_OUT);
			GPIOPadConfigSet(GPIO_PORTC_BASE, pin, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD);
			GPIOPinWrite(GPIO_PORTC_BASE, pin, 0);
			break;
			
		case PortD:  //PortD	
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);  //Enable clock on port D
			while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));
			//TODO unlock
		
			GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, pin);  //Set as GPIO Output
			GPIODirModeSet(GPIO_PORTD_BASE, pin, GPIO_DIR_MODE_OUT);  //Set direction Output
			GPIOPadConfigSet(GPIO_PORTD_BASE, pin, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD);  //Configure pin
			GPIOPinWrite(GPIO_PORTD_BASE, pin, 0);
			break;
		
		case PortE:  //PortE
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);  //Enable clock on port E
			while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE));
			if(pin && GPIO_PIN_0) { GPIO_PORTE_LOCK_R = 0x4C4F434B; } //Unlock GPIO PE0 if necessary
			GPIO_PORTE_CR_R |= pin;  //Allow changes to PE4-0
			
			GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, pin);
			GPIODirModeSet(GPIO_PORTE_BASE, pin, GPIO_DIR_MODE_OUT);  //Set direction Output
			GPIOPadConfigSet(GPIO_PORTE_BASE, pin, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD); //Configure pin
			//GPIOPinWrite(GPIO_PORTE_BASE, pin, 0);	// MiSU patch
			break;
		
		case PortF:  //PortF*/
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);	//Enable clock on port F
			while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
			if(pin && GPIO_PIN_0) { GPIO_PORTF_LOCK_R = 0x4C4F434B; } //Unlock GPIO PF0 if necessary
			GPIO_PORTF_CR_R |= 0x1F;  //Allow changes to PF4-0
			
			GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, pin);  //Set GPIO Input
			GPIODirModeSet(GPIO_PORTF_BASE, pin, GPIO_DIR_MODE_OUT);  //Set direction input
			GPIOPadConfigSet(GPIO_PORTF_BASE, pin, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD); //Configure pin
			GPIOPinWrite(GPIO_PORTF_BASE, pin, 0);
			break;		
			
		default:
			return 0;  //error
	}
	return 1;  //OK
}

uint8_t GPIO_SetPin(ports_t port, uint8_t pin, uint8_t status){
	switch (port) {
		//TODO: Check if port is initialized and pin is set for output
		case PortA:  //PortA 
			GPIOPinWrite(GPIO_PORTA_BASE, pin, status);
			break;
		case PortB:  //PortB
			GPIOPinWrite(GPIO_PORTB_BASE, pin, status);
			break;
		case PortC:  //PortC
			GPIOPinWrite(GPIO_PORTC_BASE, pin, status);
			break;
		case PortD:  //PortD	
			GPIOPinWrite(GPIO_PORTD_BASE, pin, status);
			break;
		case PortE:  //PortE
			GPIOPinWrite(GPIO_PORTE_BASE, pin, status);
			break;
		case PortF:  //PortF
			GPIOPinWrite(GPIO_PORTF_BASE, pin, status);
			break;		
		default:
			return 0;  //error
	}
	return 1;  //OK
}

uint8_t GPIO_InitPortInput(ports_t port, uint8_t pin, uint8_t resistor)
{
			
			switch (port) {
		//TODO: Check if port is initialized and pin is set for output
		case PortA:  //PortA 
			
			break;
		case PortB:  //PortB
			
			break;
		case PortC:  //PortC
			
			break;
		case PortD:  //PortD	
			
			break;
		case PortE:  //PortE
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);	//Enable clock on port E
			while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE));
			if(pin && GPIO_PIN_0) { GPIO_PORTE_LOCK_R = 0x4C4F434B; } //Unlock GPIO PF0 if necessary
			GPIO_PORTE_CR_R |= pin;  //Allow changes to PF4-0
			
			GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, pin);  //Set GPIO Input
			GPIODirModeSet(GPIO_PORTE_BASE, pin, GPIO_DIR_MODE_IN);  //Set direction input
			GPIOPadConfigSet(GPIO_PORTE_BASE, pin, GPIO_STRENGTH_2MA,resistor); //Configure PUR
			break;
		case PortF:  //PortF
			
			break;		
		default:
			return 0;  //error
	}
	return 1;  //OK
}

//EOF
