#ifndef HX711_HANDLER_H
	#define HX711_HANDLER_H
/*-------------------Type Includes--------------------*/
	#include <stdint.h>
	#include <stdbool.h>	
	#if HX711_AVAILABLE
	
		#define arraySize 50								// how many last values to track
		#define tripSensitivityGrams 3			// increase value to make it less sensitive
		#define cutSensitivityGrams 50			// increase value to make it less sensitive		
		#define conversionFactor 2427.44 		// factor for converting to grams
		
		#define tripSensitivity (tripSensitivityGrams * conversionFactor)
		#define cutSensitivity (cutSensitivityGrams * conversionFactor)

		uint32_t HX711_ReadCount(void);
	#endif	// HX711_AVAILABLE
#endif	// HX711_HANDLER_H

	// EOF
