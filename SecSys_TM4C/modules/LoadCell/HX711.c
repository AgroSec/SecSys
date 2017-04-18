/*------Export interface---Self header Includes-------*/
#include "HX711.h"
/*-------------------Driver Includes------------------*/
#include "driverlib/sysctl.h"
/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"

#if HX711_AVAILABLE
/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
/*-----------------Application Includes---------------*/

/*-------------Global Variable Definitions------------*/
uint32_t HX711_CalibVal = 0;
uint32_t loggedValues[arraySize];
uint8_t arrayCounter = 0;
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
//  DOUT -  input - PortE, pin 2
//   SLK - output - PortE, pin 3

uint32_t HX711_ReadCount(void){
	uint32_t Count=0;
	uint8_t i=0;
	
	GPIO_SetPin(PortE, 1<<3, 0);		// set SLK to LOW
	Count=0;
	while(GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_2) == GPIO_PIN_2)	// wait for DOUT to go LOW
	{;}
		
	for (i=0;i<24;i++)
	{
			GPIO_SetPin(PortE, 1<<3, 1<<3);				// set SLK to HIGH
			Count=Count<<1;		// shift Count by 1 bit to the left to make room for new read
			GPIO_SetPin(PortE, 1<<3, 0);				// set SLK to LOW
			if(GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_2) == GPIO_PIN_2) Count++;	// if DOUT if HIGH, increment Count (set LSB in Count to 1)
			
	}
	GPIO_SetPin(PortE, 1<<3, 1<<3);					// set SLK to HIGH (25th bit)
	Count=Count^0x800000;	// data is in 2's complement
	GPIO_SetPin(PortE, 1<<3, 0);					// set SLK to LOW (25th bit)
	
	loggedValues[arrayCounter++] = Count;		//save this value
	if (arrayCounter >= 100) arrayCounter = 0;
	
	return(Count);
} 

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

#endif	// HX711_AVAILABLE

// EOF
