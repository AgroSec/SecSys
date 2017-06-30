#ifndef LOADCELL_H
	#define LOADCELL_H
/*-------------------Type Includes--------------------*/
	#include <stdint.h>
	#include <stdbool.h>
	
	#if HX711_AVAILABLE
	
		#include "hx711_handler.h"
		uint32_t HX711_Calibrate(void);
		int8_t HX711_Check(uint32_t val);
		
	#endif	// HX711_AVAILABLE
#endif	// LOADCELL_H

	// EOF
