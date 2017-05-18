/*---------------------OS Includes--------------------*/

/*-------------------Driver Includes------------------*/

/*-------------------Configuration Includes-----------*/

/*-------------------Service Includes-----------------*/
#include "onewire_handler.h"
#include "hw_gpio.h"

#include "inc/hw_types.h"
/*------Export interface---Self header Includes-------*/
#include "DS18B20.h"
#if TEMP_AVAILABLE

/*-----------------Application Includes---------------*/
#include "pc_display.h"
/*-------------Global Variable Definitions------------*/
extern uint8_t ROM_NO[];
uint8_t FirstRun = 1;
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/

//--------------------------------------------------------------------------

void call_DS18B20(void)
{
	onewire_t ow;
  uint8_t type_s, cfg, scratchpad[9];
	int16_t rslt, i, cnt, raw = 0, tempCelsius = 0;
 
  ow.port_out = (uint8_t *)PORT_OUT;
  ow.port_in  = (uint8_t *)PORT_IN;
  ow.port_ren = (uint8_t *)PORT_REN;
  ow.port_dir = (uint8_t *)PORT_DIR;
  ow.pin = (GPIO_PIN_1);
 
  //search(&ow, id, 0, 1);
	
	cnt = 0;
	rslt = OWFirst(&ow);
	while (rslt)
	{
	// print device found
	for (i = 7; i >= 0; i--)
		{
		PC_Display_Message_FP("....", ROM_NO[i], -1, "");
		}
		
		switch (ROM_NO[0]) 
			{	// print to UART the device type and select proper handling (DS1820 and DS18S20 offer only 9-bit resolution)
			case 0x10:
				PC_Display_Message_FP("  Chip = DS18S20", -32767, 0, "");  // or old DS1820
				type_s = 1;
				break;
			case 0x28:
				PC_Display_Message_FP("  Chip = DS18B20", -32767, 0, "");
				type_s = 0;
				break;
			case 0x22:
				PC_Display_Message_FP("  Chip = DS1822", -32767, 0, "");
				type_s = 0;
				break;
			default:
				PC_Display_Message_FP("Device is not a DS18x20 family device.", -32767, 0, "");
				return;
			} 
			
			OWReset(&ow);						// reset bus
			OW_select(&ow, ROM_NO);	// select the current device
			
			if (FirstRun)
			{	
				/*
				PC_Display_Message_FP("First run. Programming devices with value:", CONFIG_REGISTER, -1, "");
				// read current configuration
				OW_readScratchpad(&ow);
				for (i=0; i<9; i++)
				{
					scratchpad[i] = OWReadByte(&ow);
				}
				
				for (i=0; i<9; i++)
				{
					PC_Display_Message_FP("scratchpad: ", scratchpad[i], -1, "");
				}				
				
				// set DS18B20 resolution to the one defined globally
				OW_writeScratchpad(&ow, scratchpad[2], scratchpad[3], CONFIG_REGISTER);
				
				OWReset(&ow);						// reset bus
				OW_select(&ow, ROM_NO);	// select the current device
				
				OW_readScratchpad(&ow);
				for (i=0; i<9; i++)
				{
					scratchpad[i] = OWReadByte(&ow);
				}
				
				for (i=0; i<9; i++)
				{
					PC_Display_Message_FP("scratchpad: ", scratchpad[i], -1, "");
				}		
				
				OW_copyScratchpad(&ow);
				delayMicroseconds(10000);
				OWReset(&ow);						// reset bus
				*/
			}
			else
			{
				OWWriteByte(&ow, 0x44);	// start conversion			
				delayMicroseconds(T_CONV);
				OWReset(&ow);
				OW_select(&ow, ROM_NO);
				OW_readScratchpad(&ow);
				for (i=0; i<9; i++)
				{
					scratchpad[i] = OWReadByte(&ow);
					//PC_Display_Message_FP("scratchpad: ", scratchpad[i], -1, "");
				}
				//check crc
				raw = (scratchpad[1] << 8) | scratchpad[0];
				
				if (type_s)
				{
					raw <<= 3;	// 9 bit resolution for DS1820 and DS18S20
					if (scratchpad[7] == 0x10)
					{	// byte "count remain" gives full 12 bit resolution
						raw = (raw & 0xFFF0) + 12 - scratchpad[6];
					}
				}
				else
				{
					cfg = (scratchpad[4] & 0x60);
					
					if (cfg == 0x00)
						raw = raw& ~7;			// 9 bit resolution, 93.75 ms
					else if (cfg == 0x20)
							raw = raw & ~3;		// 10 bit res, 187.5 ms
						else if (cfg == 0x40)
								raw = raw & ~1;	// 11 bit res, 375 ms
					//// default is 12 bit resolution, 750 ms conversion time
				
				}
				tempCelsius = (int16_t)((float)(1000.0 * raw / 16.0 ));
				PC_Display_Message_FP("current temp: ", tempCelsius, 3, " *C");				
			}			
			
	PC_Display_Message_FP("device number: ", ++cnt, 0, "");
	rslt = OWNext(&ow);
	}	
	
	PC_Display_Message_FP("No more addresses.", -32767, 0, "");
	FirstRun = 0;


}

//
// Do a ROM select
//
void OW_select(onewire_t *ow, uint8_t rom[8])
{
    int i;

    OWWriteByte(ow, 0x55);           // Choose (or match) ROM

    for( i = 0; i < 8; i++) OWWriteByte(ow, rom[i]);
}

//
// Do a ROM read
//
void OW_readROM(onewire_t *ow)	// this is not to be used on a multidrop bus (bus with more than one slave)
{
    OWWriteByte(ow, 0x33);           // Read ROM
}

//
// Do a ROM skip
//
void OW_skip(onewire_t *ow)	// this is not to be used on a multidrop bus (bus with more than one slave)
{
    OWWriteByte(ow, 0xCC);           // Skip ROM
}

//
// Do a write to Scratchpad
//
void OW_writeScratchpad(onewire_t *ow, uint8_t TH, uint8_t TL, uint8_t configRegister)
{
    OWWriteByte(ow, 0x4E);						// send command to write to SP
		OWWriteByte(ow, TH);							// TH - temperature high threshold
		OWWriteByte(ow, TL);							// TL - temperature low threshold
		OWWriteByte(ow, configRegister);	// configuration register (for setting conversion resolution)
}

//
// Do a read from Scratchpad
//
void OW_readScratchpad(onewire_t *ow)
{
    OWWriteByte(ow, 0xBE);						// send command to read from SP; this should be followed by reading 8+1 Bytes from the bus. Last Byte is CRC.
}																			// If not all locations are to be read, the master may issue a reset to terminate reading at any time.

//
// Do a copy from Scratchpad to non-volatile memory
//
void OW_copyScratchpad(onewire_t *ow)
{
    OWWriteByte(ow, 0x48);           // copy SP to non-volatile mem; operation takes about 10ms.
}

#endif	// TEMP_AVAILABLE
// EOF
