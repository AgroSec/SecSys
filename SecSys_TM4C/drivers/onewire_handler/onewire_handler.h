#ifndef ONEWIRE_HANDLER_H
	#define ONEWIRE_HANDLER_H
	/*-------------------Type Includes--------------------*/
	#include <stdint.h>
	//#include <stdbool.h>	
	#include "driverlib/rom.h"

	#define delayMicroseconds(x) (ROM_SysCtlDelay(x * 25))
	
	#define OW_parasitic_power 0

typedef struct {
				volatile uint8_t *port_out;
				const volatile uint8_t *port_in;
				volatile uint8_t *port_ren;
				volatile uint8_t *port_dir;
				int pin;
			} onewire_t;

	int16_t OWFirst(onewire_t *ow);
	int16_t OWNext(onewire_t *ow);
	int16_t OWVerify(onewire_t *ow);
	void OWTargetSetup(uint8_t family_code);
	void OWFamilySkipSetup(void);
	int16_t OWReset(onewire_t *ow);
	void OWWriteByte(onewire_t *ow, uint8_t byte);
	void OWWriteBit(onewire_t *ow, uint8_t bit);
	uint8_t OWReadByte(onewire_t *ow);
	uint8_t OWReadBit(onewire_t *ow);
	int16_t OWSearch(onewire_t *ow);
	uint8_t docrc8( uint8_t *addr, uint8_t len);			
	void onewire_line_low(onewire_t *ow);
	void onewire_line_high(onewire_t *ow);
	void onewire_line_release(onewire_t *ow);

#endif	// ONEWIRE_HANDLER_H

// EOF
