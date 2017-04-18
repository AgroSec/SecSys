#ifndef HX711_H
/*-------------------Type Includes--------------------*/
#include <stdint.h>
#include <stdbool.h>
	#define HX711_H 1
	#if HX711_AVAILABLE
		//#include <stdint.h>
		
		#define arraySize 50								// how many last values to track
		#define tripSensitivityGrams 3			//increase value to make it less sensitive
		#define cutSensitivityGrams 50			//increase value to make it less sensitive		
		#define conversionFactor 2427.44 		// factor for converting to grams
		
		#define tripSensitivity (tripSensitivityGrams * conversionFactor)
		#define cutSensitivity (cutSensitivityGrams * conversionFactor)

		uint32_t HX711_ReadCount(void);
		uint32_t HX711_Calibrate(void);
		int8_t HX711_Check(uint32_t val);
	#endif	// HX711_AVAILABLE
#endif	// HX711_H

	// EOF
