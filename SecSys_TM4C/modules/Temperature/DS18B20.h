#ifndef DS18B20_H
	#define DS18B20_H
	/*-------------------Type Includes--------------------*/
	//#include <stdint.h>
	//#include <stdbool.h>
	#include "onewire_handler.h"
	#include "inc/hw_memmap.h"
		
	#define PORT_OUT  &(HWREG(GPIO_PORTE_BASE + (GPIO_O_DATA + (GPIO_PIN_1 << 2))));
	#define PORT_IN   &(HWREG(GPIO_PORTE_BASE + (GPIO_O_DATA + (GPIO_PIN_1 << 2))));
	#define PORT_REN  &(HWREG(GPIO_PORTE_BASE + GPIO_O_ODR));
	#define PORT_DIR  &(HWREG(GPIO_PORTE_BASE + GPIO_O_DIR));
	
	#if (TEMPERATURE_RESOLUTION == 9)
		#define T_CONV 92500
		#define CONFIG_REGISTER (0x1F)
	#endif
	#if (TEMPERATURE_RESOLUTION == 10)
		#define T_CONV 187500
		#define CONFIG_REGISTER (0x3F)
	#endif
	#if (TEMPERATURE_RESOLUTION == 11)
		#define T_CONV 375000
		#define CONFIG_REGISTER (0x5F)
	#endif
	#if (TEMPERATURE_RESOLUTION == 12)
		#define T_CONV 750000
		#define CONFIG_REGISTER (0x7F)
	#endif

	void init_DS(void);
	void call_DS(void);
	void OW_select(onewire_t *ow, uint8_t rom[8]);
	void OW_readROM(onewire_t *ow);
	void OW_skip(onewire_t *ow);
	void OW_writeScratchpad(onewire_t *ow, uint8_t TH, uint8_t TL, uint8_t configRegister);
	void OW_readScratchpad(onewire_t *ow);
	void OW_copyScratchpad(onewire_t *ow);	
	void OW_recallEEvalues(onewire_t *ow);
	void OW_skipROM(onewire_t *ow);

#endif	// DS18B20_H
	// EOF
