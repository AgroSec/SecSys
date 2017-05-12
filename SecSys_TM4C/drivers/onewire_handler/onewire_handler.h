#ifndef ONEWIRE_HANDLER_H
	#define ONEWIRE_HANDLER_H
	/*-------------------Type Includes--------------------*/
	#include <stdint.h>
	#include <stdbool.h>	

	#define OW_port1 PortE
	#define OW_portbase1 GPIO_PORTE_BASE
	#define OW_pin1 GPIO_PIN_1		//port PE1
	
	#define delayMicroseconds(x) (SysCtlDelay(x * 12.5 +x))
	
	#define OW_parasitic_power 0
	
	/*
	#define CYCLES_PER_US 8L // depends on the CPU speed
	#define CYCLES_PER_MS (CYCLES_PER_US * 1000L)

	#define DELAY_US(x) __delay_cycles((x * CYCLES_PER_US))
	#define DELAY_MS(x) __delay_cycles((x * CYCLES_PER_MS))
	*/

/*
 * 1-Wire implementation for MSP430
 *
 * @author: David Siroky <siroky@dasir.cz>
 * @license: MIT
 */

typedef struct {
    volatile uint8_t *port_out;
    const volatile uint8_t *port_in;
    volatile uint8_t *port_ren;
    volatile uint8_t *port_dir;
    int pin;
  } onewire_t;

//########################################################################

int onewire_reset(onewire_t *ow);
void onewire_write_bit(onewire_t *ow, int bit);
int onewire_read_bit(onewire_t *ow);
void onewire_write_byte(onewire_t *ow, uint8_t byte);
uint8_t onewire_read_byte(onewire_t *ow);
void onewire_line_low(onewire_t *ow);
void onewire_line_high(onewire_t *ow);
void onewire_line_release(onewire_t *ow);


#endif	// ONEWIRE_HANDLER_H

// EOF
