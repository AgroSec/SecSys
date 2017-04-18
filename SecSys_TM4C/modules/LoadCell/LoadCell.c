/*-------------------Driver Includes------------------*/
#include "driverlib/sysctl.h"
/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"
/*------Export interface---Self header Includes-------*/

#if HX711_AVAILABLE

#include "LoadCell.h"
/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
#include "hx711_handler.h"
/*-----------------Application Includes---------------*/

/*-------------Global Variable Definitions------------*/
extern uint32_t HX711_CalibVal;
extern uint32_t loggedValues[arraySize];
extern uint8_t arrayCounter;

#include "LoadCell.h"
uint32_t HX711_Calibrate(void)
{	// first calibration, at system startup
	uint8_t i;
	uint32_t meanValue=0;
	for(i=0; i<arraySize; i++)
	{
		meanValue += HX711_ReadCount();
	}
	
	meanValue/=arraySize;
	
	return meanValue;
}

int8_t HX711_Check(uint32_t val)
{	// check whether the wire is touched or not
	uint8_t i;
	uint32_t meanValue=0;
	
	for (i=0; i<arraySize; i++)
	{
		meanValue += loggedValues[i];		//compute saved values
	}
	meanValue /= arraySize;
	
	HX711_CalibVal = meanValue;		// recalibrate on the fly
	
	if ((int32_t)(val-meanValue) > tripSensitivity) return  1;	// positive value, above sensitivity limit
	if ((int32_t)(val-meanValue) < -cutSensitivity) return -1;	// negative value, above sensitivity limit
	return 0;		// ok - nil value, between upper and lower sensitivity limits
}

#endif
