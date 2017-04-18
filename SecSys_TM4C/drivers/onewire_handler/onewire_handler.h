#ifndef ONEWIRE_HANDLER_H
	#define ONEWIRE_HANDLER_H
	/*-------------------Type Includes--------------------*/
	#include <stdint.h>
	#include <stdbool.h>	

	int16_t OWFirst();
	int16_t OWNext();
	int16_t OWVerify();
	void OWTargetSetup(uint8_t family_code);
	void OWFamilySkipSetup();
	int16_t OWReset();
	void OWWriteByte(uint8_t byte_value);
	void OWWriteBit(uint8_t bit_value);
	uint8_t OWReadBit();
	int16_t OWSearch();
	uint8_t docrc8(uint8_t value);

#endif	// ONEWIRE_HANDLER_H
	// EOF
	