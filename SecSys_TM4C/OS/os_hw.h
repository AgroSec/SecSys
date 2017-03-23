// os_hw.h - ssOS Target HW specific code - Interrupt Service Routines, Target configurations
// ssOS - stupid simple Operating System
// A very simple real time operating system with minimal features.
// For copyright, configuration and usage read readme.txt

#ifndef __OSHW_H
#define __OSHW_H  1

/*------------------- Includes-------------------*/
#include "CortexM.h"
#include "stdbool.h"
#include "stdint.h"
#include "os_core.h"
#include "os_config.h"
//#include "../inc/tm4c123gh6pm.h"   //AleGaa not needed at the moment

struct port_sema {
	int32_t pin0;
	int32_t pin1;
	int32_t pin2;
	int32_t pin3;
	int32_t pin4;
	int32_t pin5;
	int32_t pin6;
	int32_t pin7;
};
typedef struct port_sema PortSema_t;

#ifdef TARGET_TM4C
//TM4C specific code

/*-------------------HW define Includes--------------*/
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
/*-------------------Driver Includes-----------------*/
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/systick.h"


enum tm4c_ports {
	PortA = 0,
	PortB,
	PortC,
	PortD,
	PortE,
	PortF
};
typedef enum tm4c_ports	ports_t;

enum tm4c_timers {
	Timer0A = 0, // 16/32 bit
	Timer1A = 1,
	Timer2A = 2,
	Timer3A = 3,
	Timer4A = 4,
	Timer5A = 5,
	WTimer0A = 10,  // 32/64 bit
	WTimer1A = 11,
	WTimer2A = 12,
	WTimer3A = 13,
	WTimer4A = 14,
	WTimer5A = 15,
};
typedef enum tm4c_timers	timers_t;

#endif //TARGET_TM4C

#ifdef TARGET_MSP432
//MSP432 specific code
#include "BSP_MSP432.h"

#define Port1	(0);
#define	Port2	(1);
#define Port3	(2);
#define	Port4	(3);
#define Port5	(4);
#define	Port6	(5);

#endif //TARGET_TM4C

uint8_t OS_EdgeTrigger_Restart(ports_t port, uint8_t pin);
uint8_t OS_EdgeTrigger_Init(ports_t port, uint8_t pin, uint8_t priority, uint8_t type, uint8_t resistor);
uint32_t OS_Clock_Init(uint8_t clock_Mhz);
uint8_t OS_Timer_Init(timers_t timer, uint32_t freqency, uint8_t priority);
void OS_SysTick_Init(uint32_t time);
#endif

//EOF
