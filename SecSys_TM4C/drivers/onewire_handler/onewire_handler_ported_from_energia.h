#ifndef ONEWIRE_HANDLER_H
	#define ONEWIRE_HANDLER_H
	/*-------------------Type Includes--------------------*/
	#include <stdint.h>
	#include <stdbool.h>	

	#define OW_port1 PortE
	#define OW_portbase1 GPIO_PORTE_BASE
	#define OW_pin1 GPIO_PIN_1		//port PE1
	
	#define delayMicroseconds(x) (SysCtlDelay(x * 12.5 +x))
	
	#define OW_parasitic_power 0

	int16_t OWFirst(void);
	int16_t OWNext(void);
	int16_t OWVerify(void);
	void OWTargetSetup(uint8_t family_code);
	void OWFamilySkipSetup(void);
	int16_t OWReset(void);
	void OWWriteByte(uint8_t byte_value);
	void OWWriteBit(uint8_t bit_value);
	uint8_t OWReadBit(void);
	int16_t OWSearch(void);
	uint8_t docrc8(uint8_t value);

#endif	// ONEWIRE_HANDLER_H

// EOF
