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
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/

//--------------------------------------------------------------------------

void call_DS18B20(void)
{
	onewire_t ow;
  //uint8_t id[8];
	int16_t rslt, i, cnt;
 
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
		PC_Display_Message_FP("....", ROM_NO[i], -1, "");
	PC_Display_Message_FP("", ++cnt, 0, "");
	rslt = OWNext(&ow);
	}
}
/*
//
// Do a ROM select
//
void OneWire::select( uint8_t rom[8])
{
    int i;

    write(0x55);           // Choose ROM

    for( i = 0; i < 8; i++) write(rom[i]);
}

//
// Do a ROM skip
//
void OneWire::skip()
{
    write(0xCC);           // Skip ROM
}

*/
/*
void search(onewire_t *ow, uint8_t *id, int depth, int reset)
{
  int i, b1, b2;
	
	if (depth == 64)
  {
    // we have all 64 bit in this search branch
    PC_Display_Message_FP("OW found: ", -32767, 0, "");
    for (i = 0; i < 8; i++) 
			PC_Display_Message_FP("", id[i], -1, "");
    
    return;
  }
 
  if (reset)
  {
    if (onewire_reset(ow) != 0) 
		{ 
			PC_Display_Message_FP("OW reset failed. ", -32767, 0, "");
			return; 
		}
    onewire_write_byte(ow, 0xF0); // search ROM command
 
    // send currently recognized bits
    for (i = 0; i < depth; i++)
    {
      b1 = onewire_read_bit(ow);
      b2 = onewire_read_bit(ow);
      onewire_write_bit(ow, id[i / 8] & (1 << (i % 8)));
    }
  }
 
  // check another bit
  b1 = onewire_read_bit(ow);
  b2 = onewire_read_bit(ow);
  if (b1 && b2) return; // no response to search
  if (!b1 && !b2) // two devices with different bits on this position
  {
    // check devices with this bit = 0
    onewire_write_bit(ow, 0);
    id[depth / 8] &= ~(1 << (depth % 8));
    search(ow, id, depth + 1, 0);
    // check devices with this bit = 1
    id[depth / 8] |= 1 << (depth % 8);
    search(ow, id, depth + 1, 1); // different branch, reset must be issued
  } else if (b1) {
    // devices have 1 on this position
    onewire_write_bit(ow, 1);
    id[depth / 8] |= 1 << (depth % 8);
    search(ow, id, depth + 1, 0);
  } else if (b2) {
    // devices have 0 on this position
    onewire_write_bit(ow, 0);
    id[depth / 8] &= ~(1 << (depth % 8));
    search(ow, id, depth + 1, 0);
  }
}
 */

#endif	// TEMP_AVAILABLE
// EOF
