//timer_handler.c
//Service layer
/*-------------------Configuration Includes----------*/
#include "compile_switches.h"

/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"

/*-------------------HW define Includes--------------*/
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

/*-------------------Driver Includes-----------------*/
//#include "driverlib/comp.h"
//#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
//#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"

/*------Export interface---Self header Includes------*/
#include "timer_handler.h"

/*-------------------Service Includes-----------------*/
#include "interrupt_handler.h"
#include "system_handler.h"

/*-------------------Function Definitions-------------*/
void TIMER_cyclic_1s_init(void)	//1 second cyclic timer configuration
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);		//Wide Timer 0 enable 
	IntDisable(INT_WTIMER0A);													//Wide Timer 0A disable of interrupts
	TimerIntDisable(WTIMER0_BASE,TIMER_TIMA_TIMEOUT);
	
	TimerDisable(WTIMER0_BASE, TIMER_A);
	TimerClockSourceSet(WTIMER0_BASE, TIMER_CLOCK_SYSTEM);
	TimerConfigure(WTIMER0_BASE, TIMER_CFG_A_PERIODIC);

	TimerLoadSet(WTIMER0_BASE, TIMER_A, TIMER_reload_calculator(1000));	//Set cycle nr for 1000 ms	
	TimerEnable(WTIMER0_BASE, TIMER_A);
	
	TimerIntEnable(WTIMER0_BASE,TIMER_TIMA_TIMEOUT);
	IntPrioritySet(INT_WTIMER0A,(Int_Prio_WTimer0A_1s)<<5); 			//Priority 1 = "001"0.0000
	IntEnable(INT_WTIMER0A);	//Wide Timer 0A enable of interrupts
}

void TIMER_cyclic_50ms_init(void)	//50 mili second cyclic timer configuration
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);	//Timer 0 enable
	IntDisable(INT_TIMER0A);	//Timer 0A disable of interrupts
	TimerIntDisable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
	
	TimerDisable(TIMER0_BASE, TIMER_A);	
	TimerClockSourceSet(TIMER0_BASE, TIMER_CLOCK_SYSTEM);
	TimerConfigure(TIMER0_BASE, TIMER_CFG_A_PERIODIC);
	
	TimerLoadSet(TIMER0_BASE, TIMER_A, TIMER_reload_calculator(50));	//Set cycle nr for 50 ms	
	TimerEnable(TIMER0_BASE, TIMER_A);
	
	TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
	IntPrioritySet(INT_TIMER0A,(Int_Prio_Timer0A_50ms)<<5);	//Priority 0 = "000"0.0000
	IntEnable(INT_TIMER0A);	//Timer 0A enable of interrupts	
}

unsigned long TIMER_reload_calculator(unsigned long milli_seconds_requested)
{
	unsigned long clock_cycle_required = 0;
	unsigned long clock_speed = 0;
	
	clock_speed = SYS_clock_get;	//Get clock speed in Hz
	clock_cycle_required = ((clock_speed / 1000) * milli_seconds_requested) - 1;	//Returns the clock cycles required for the requested time in mili seconds
	return clock_cycle_required;
}

void TIMER_delay(unsigned long delay_time_ms)
{
	unsigned long clock_cycle_required = 0;
	clock_cycle_required = TIMER_reload_calculator(delay_time_ms);
	while(clock_cycle_required)
	{
		clock_cycle_required --;
	}
}
void TIMER_delay_No_Int(unsigned long delay_time_ms)
{
	unsigned long clock_cycle_required = 0;
	Int_Master_Disable();	//Global interrupt disable
	clock_cycle_required = TIMER_reload_calculator(delay_time_ms);
	while(clock_cycle_required)
	{
		clock_cycle_required --;
	}
	Int_Master_Enable();	//Global interrupt enable
}
/*
void WideTimer0A_Handler(void)		//Wide Timer 0 A ISR
{
	unsigned long timer_value=0;
	if(TimerIntStatus(WTIMER0_BASE,false))
	{
		TimerIntClear(WTIMER0_BASE, TIMER_A);
		timer_value = TimerValueGet(WTIMER0_BASE, TIMER_A);
		//CYCL_1_second();
	}
}

void Timer0A_Handler(void)		//Timer 0 A ISR
{
	unsigned long timer_value=0;
	if(TimerIntStatus(TIMER0_BASE,false))
	{
		TimerIntClear(TIMER0_BASE, TIMER_A);
		timer_value = TimerValueGet(TIMER0_BASE, TIMER_A);
		CYCL_50_milisecond();
	}
}
*/