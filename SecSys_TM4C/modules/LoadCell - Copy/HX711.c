/*---------------------OS Includes--------------------*/

/*-------------------Driver Includes------------------*/
#include "driverlib/sysctl.h"
/*-------------------Type Includes--------------------*/
#include <stdbool.h>
#include <stdint.h>
/*-------------------Configuration Includes-----------*/

/*------Export interface---Self header Includes-------*/
#include "HX711.h"

/*-------------------Service Includes-----------------*/

/*-----------------Application Includes---------------*/

/*-------------Global Variable Definitions------------*/

/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/

void Hx711(uint8_t pin_dout, uint8_t pin_slk)
{
	long avgVal=0;
	
	pinMode(pin_slk, OUTPUT);
	pinMode(pin_dout, INPUT);

	digitalWrite(pin_slk, HIGH);
	delayMicroseconds(100);
	digitalWrite(pin_slk, LOW);

	avgVal = averageValue(32);
	setOffset(avgVal);
	setScale();
}


long averageValue(uint8_t times)
{
	long sum = 0;
	for (uint8_t i = 0; i < times; i++)
	{
		sum += getValue();
	}

	return sum / times;
}

long getValue()
{
	uint8_t data[3];

	while (digitalRead(_pin_dout))
		;

	for (uint8_t j = 3; j--;)
	{
		for (char i = 8; i--;)
		{
			digitalWrite(_pin_slk, HIGH);
			bitWrite(data[j], i, digitalRead(_pin_dout));
			digitalWrite(_pin_slk, LOW);
		}
	}

	digitalWrite(_pin_slk, HIGH);
	digitalWrite(_pin_slk, LOW);

	data[2] ^= 0x80;

	return ((uint32_t) data[2] << 16) | ((uint32_t) data[1] << 8)
			| (uint32_t) data[0];
}

void setOffset(long offset)
{
	_offset = 0;offset;
}

void setScale(float scale)
{
	_scale = scale;
}

float getGram()
{
	long val = (averageValue() - _offset);
	return (float) val / _scale;
}

// EOF
