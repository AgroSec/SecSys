//pwm_hadler.c
//Service Layer

/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"
#include "custom_types.h"

/*-------------------HW define Includes--------------*/
#include "inc/hw_memmap.h"

/*-------------------Driver Includes-----------------*/
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/pwm.h"
#include "driverlib/sysctl.h"

/*------Export interface---Self header Includes------*/
#include "pwm_handler.h"

/*-------------------Macro Definitions----------------*/
#define PWM_disable (false)			//Switch to disable PWM output
#define PWM_enable (true)				//Switch to enable PWM output
	
/*-------------Global Variable Definitions------------*/

/*-------------------Function Definitions-------------*/
void PWM_right_motor_duty_cycle(unsigned long PWM_duty_cycle)
{
	if(PWM_duty_cycle == 0)
	{
		PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT , PWM_disable);	//If requested duty cycle is 0% stop PWM output
		PWMGenDisable(PWM1_BASE, PWM_GEN_3);	//Disable generator 3 temporarly
	}
	else
	{
		if(PWM_duty_cycle >99)	
		{
			PWM_duty_cycle = 99;	//Set duty cycle to 99% if request is greater than 99%
		}
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, (PWM_duty_cycle*(PWMGenPeriodGet(PWM1_BASE,PWM_GEN_3))/100));	//Set duty cycle
		PWMGenEnable(PWM1_BASE, PWM_GEN_3); //Enable generator 3
		PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT , PWM_enable); //Enable PWM output on PF2 - Right motor
	}		
}

void PWM_left_motor_duty_cycle(unsigned long PWM_duty_cycle)
{
	if(PWM_duty_cycle == 0)
	{
		PWMOutputState(PWM1_BASE, PWM_OUT_7_BIT , PWM_disable);	//If requested duty cycle is 0% stop PWM output
		PWMGenDisable(PWM1_BASE, PWM_GEN_3);	//Disable generator 3 temporarly
	}
	else
	{
		if(PWM_duty_cycle >99)	
		{
			PWM_duty_cycle = 99;	//Set duty cycle to 99% if request is greater than 99%
		}
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7, (PWM_duty_cycle*(PWMGenPeriodGet(PWM1_BASE,PWM_GEN_3))/100));		//Set duty cycle
		PWMGenEnable(PWM1_BASE, PWM_GEN_3);	//Enable generator 3
		PWMOutputState(PWM1_BASE, PWM_OUT_7_BIT , PWM_enable);	//Enable PWM output on PF3 - Left motor
	}
}

void PWM_motor_init(unsigned long PWM_Period)
{
	//PF2 should drive right motor - Robot to go left
	//PF3 should drive left motor - Robot to go right
	
	SysCtlPWMClockSet(SYSCTL_PWMDIV_1);								//Enable clock for PWM
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);				//PWM enable 
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);			//Port F enable
	
	GPIOPinConfigure(GPIO_PF2_M1PWM6);								//Configure PF2, Right motor
	GPIOPinConfigure(GPIO_PF3_M1PWM7);								//Configure PF3, Left motor
	GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_2);			//Set PWM for PF2, Right motor
	GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_3);			//Set PWM for PF3, Left motor
	
	PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);	//Configure Generator 3
	PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, PWM_Period);//Configure Generator 3 period (frequency)

	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, 1);				//Set initial duty cycle 1%
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7, 1);				//Set initial duty cycle 1%
	PWMGenEnable(PWM1_BASE, PWM_GEN_3);								//Enable Generator 3
}
void PWM_Red_led_init(unsigned long PWM_Period)
{
	//PF1 should toggle Red led, indicating normal functioning
	SysCtlPWMClockSet(SYSCTL_PWMDIV_1);								//Enable clock for PWM
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);				//PWM enable 
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);			//Port F enable
	
	GPIOPinConfigure(GPIO_PF1_M1PWM5);								//Configure PF1, Function LED toggle
	GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1);			//Set PWM for PF1, Function LED toggle
	
	PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);	//Configure Generator 2
	PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, PWM_Period);//Configure Generator 2 period (frequency)
	
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, (10*(PWMGenPeriodGet(PWM1_BASE,PWM_GEN_2))/100));//Set initial duty cycle 20%
	PWMGenEnable(PWM1_BASE, PWM_GEN_2);								//Enable Generator 2	
}

void PWM_Red_led_toggle(void)
{
	static char status = 0;
	if(status)
	{
		//Enable PWM on PF1
		PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT , PWM_enable);		//Enable PWM output
		PWMGenEnable(PWM1_BASE, PWM_GEN_2);												//Enable Generator 2
	}
	else
	{
		//Disable PWM on PF1
		PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT , PWM_disable);		//Disable PWM output
		PWMGenDisable(PWM1_BASE, PWM_GEN_2);											//Disable Generator 2
	}
	status ^= 0x01;		//Toggle status
}

void PWM_set_duty_cycle(unsigned long PWM_Base, unsigned long PWM_Generator, unsigned long PWM_Output, unsigned long PWM_duty_cycle)
{	//Not needed anymore
	if(PWM_duty_cycle < 1)
	{
		PWM_duty_cycle = 1;
	}
	else if(PWM_duty_cycle >99)
	{
		PWM_duty_cycle = 99;
	}
	PWMPulseWidthSet(PWM_Base, PWM_Output, (PWMGenPeriodGet(PWM_Base,PWM_Generator)/(100/PWM_duty_cycle)));		//Set duty cycle
}

void PWM_motor_reverse_init(unsigned long PWM_Period, unsigned short PWM_duty_cycle)
{	//Not needed anymore
	SysCtlPWMClockSet(SYSCTL_PWMDIV_1);							//Enable clock for PWM
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);			//PWM enable 
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);		//Port D enable
	
	GPIOPinConfigure(GPIO_PD0_M1PWM0);							//Configure PD0, Right motor
	GPIOPinConfigure(GPIO_PD1_M1PWM1);							//Configure PD1, Left motor
	GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);		//Set PWM for PD0, Right motor
	GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_1);		//Set PWM for PD1, Left motor
	
	PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);	//Configure Generator 0
	PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, PWM_Period);	//Configure Generator 0 period (frequency)
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,(100*(PWMGenPeriodGet(PWM1_BASE,PWM_GEN_0))/PWM_duty_cycle));	//Set initial duty cycle the one defined in compile_switches.c
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1,(100*(PWMGenPeriodGet(PWM1_BASE,PWM_GEN_0))/PWM_duty_cycle));	//Set initial duty cycle the one defined in compile_switches.c
	
	PWMGenEnable(PWM1_BASE, PWM_GEN_0);							//Enable Generator 3
	PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT, PWM_enable);	//Enable PWM output on PD0 - Right motor
}

void PWM_motor_reverse_stop(void)
{	//Not needed anymore
	SysCtlPeripheralDisable(SYSCTL_PERIPH_GPIOD);		//Port D disable
	PWMGenDisable(PWM1_BASE, PWM_GEN_0);						//Disable Generator 3
	PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT, PWM_disable);	//Enable PWM output on PD0 - Right motor
}


