/*-------------------Driver Includes------------------*/
#include "driverlib/sysctl.h"
/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"

#if TEMP_AVAILABLE
/*------Export interface---Self header Includes-------*/
#include "onewire_handler.h"
/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
#include "PC_Display.h"
/*-----------------Application Includes---------------*/
//#include "inc/hw_gpio.h"
//#include "inc/hw_ints.h"
//#include "inc/hw_memmap.h"
//#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
/*-------------Global Variable Definitions------------*/
// global search state
uint8_t ROM_NO[8];
int16_t LastDiscrepancy;
int16_t LastFamilyDiscrepancy;
int16_t LastDeviceFlag;
uint8_t crc8;
/*-------------Local Variable Definitions-------------*/
#define FALSE 0
#define TRUE 1
/*-------------------Function Definitions-------------*/

/*
 * 1-Wire implementation for MSP430
 *
 * @author: David Siroky <siroky@dasir.cz>
 * @license: MIT
 */

//#####################################################################
//#####################################################################

/// @return: 0 if ok
int onewire_reset(onewire_t *ow)
{
  onewire_line_low(ow);
  delayMicroseconds(550); // 480us minimum
  onewire_line_release(ow);
  delayMicroseconds(70); // slave waits 15-60us
  if (*(ow->port_in) & ow->pin) return 1; // line should be pulled down by slave
  delayMicroseconds(300); // slave TX presence pulse 60-240us
  if (!(*(ow->port_in) & ow->pin)) return 2; // line should be "released" by slave
  return 0;
}

//#####################################################################

void onewire_write_bit(onewire_t *ow, int bit)
{
  delayMicroseconds(2); // recovery, min 1us
  onewire_line_low(ow);
  if (bit)
    delayMicroseconds(6); // max 15us
  else
    delayMicroseconds(64); // min 60us
  onewire_line_release(ow);
  // rest of the write slot
  if (bit)
    delayMicroseconds(64);
  else
    delayMicroseconds(6);
}

//#####################################################################

int onewire_read_bit(onewire_t *ow)
{
  int bit;
  delayMicroseconds(2); // recovery, min 1us
  onewire_line_low(ow);
  delayMicroseconds(5); // hold min 1us
  onewire_line_release(ow);
  delayMicroseconds(6); // 15us window
  bit = *(ow->port_in) & ow->pin;
  delayMicroseconds(60); // rest of the read slot
  return bit;
}

//#####################################################################

void onewire_write_byte(onewire_t *ow, uint8_t byte)
{
  int i;
  for(i = 0; i < 8; i++)
  {
    onewire_write_bit(ow, byte & 1);
    byte >>= 1;
  }
}

//#####################################################################

uint8_t onewire_read_byte(onewire_t *ow)
{
  int i;
  uint8_t byte = 0;
  for(i = 0; i < 8; i++)
  {
    byte >>= 1;
    if (onewire_read_bit(ow)) byte |= 0x80;
  }
  return byte;
}

//#####################################################################

inline void onewire_line_low(onewire_t *ow)
{
  *(ow->port_dir) |= ow->pin;
  *(ow->port_out) &= ~ow->pin;
  *(ow->port_ren) &= ~ow->pin;
}

//#####################################################################

inline void onewire_line_high(onewire_t *ow)
{
  *(ow->port_dir) |= ow->pin;
  *(ow->port_out) |= ow->pin;
  *(ow->port_ren) &= ~ow->pin;
}

//#####################################################################

inline void onewire_line_release(onewire_t *ow)
{
  *(ow->port_dir) &= ~ow->pin; // input
  *(ow->port_ren) |= ow->pin;
  *(ow->port_out) |= ow->pin; // internal resistor pullup
}


#endif	// TEMP_AVAILABLE
