#ifndef DS18B20_H
	#define DS18B20_H 1
	/*-------------------Type Includes--------------------*/
	#include <stdint.h>
	#include <stdbool.h>
	#include "onewire_handler.h"	
		
	#define PORT_OUT  &(HWREG(GPIO_PORTE_BASE + (GPIO_O_DATA + (GPIO_PIN_1 << 2))));
	#define PORT_IN   &(HWREG(GPIO_PORTE_BASE + (GPIO_O_DATA + (GPIO_PIN_1 << 2))));
	#define PORT_REN  &(HWREG(GPIO_PORTE_BASE + GPIO_O_ODR));
	#define PORT_DIR  &(HWREG(GPIO_PORTE_BASE + GPIO_O_DIR));
	
	void call_DS18B20(void);
		
	//void search(onewire_t *ow, uint8_t *id, int depth, int reset);
		
#endif	// DS18B20_H
	// EOF
