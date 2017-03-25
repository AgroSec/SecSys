//interrupt_handler.c
/*-------------------Configuration Includes-----------*/
#include "compile_switches.h"

/*-------------------Type Includes-------------------*/
#include "stdbool.h"
#include "stdint.h"

/*-------------------HW define Includes--------------*/
#include "inc/hw_memmap.h"

/*-------------------Driver Includes-----------------*/
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/i2c.h"
#include "driverlib/interrupt.h"
#include "driverlib/comp.h"
#include "driverlib/timer.h"

/*------Export interface---Self header Includes------*/
#include "interrupt_handler.h"
#include "motion_handler.h"
#include "cyclic_activity_handler.h"
#include "i2c_handler.h"

/*-------------Global Variable Definitions------------*/
unsigned long comp0_interrupt_flag = 0;	//Global variable used to measure in debugger time till backwards motion is active
unsigned long X_acceleration = 0;	//X acceleration 8 bit value
unsigned long Y_acceleration = 0;	//Y acceleration 8 bit value
unsigned long Z_acceleration = 0;	//Z acceleration 8 bit value

/*-------------------Function Definitions-------------*/
void Int_Master_Enable(void)
{
	IntMasterEnable();		//Allow processor to respond to interrupts
}
void Int_Master_Disable(void)
{
	IntMasterDisable();		//Allow processor to respond to interrupts
}
/*void GPIOPortF_Handler(void) 	//GPIO port F ISR
//Not needed anymore, done by OS
{
	unsigned long Light_sensor_status = 0;
	Light_sensor_status = GPIOIntStatus(GPIO_PORTF_BASE,false);
	GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_0 | GPIO_INT_PIN_4);
	if((Light_sensor_status&(GPIO_INT_PIN_0 | GPIO_INT_PIN_4)) == (GPIO_INT_PIN_0 | GPIO_INT_PIN_4))
	{
		//Go Straight ahead
		Motion_Cruise();
	}
	else if(Light_sensor_status & GPIO_INT_PIN_4)
	{
		//Go Right
		Motion_Go_Right();
	}
	else if(Light_sensor_status & GPIO_INT_PIN_0)
	{
		//Go Left
		Motion_Go_Left();
	}
}*/
void Comp0_Handler(void)			//Analog comparator 0 ISR
{
	comp0_interrupt_flag = 1;
	if(ComparatorIntStatus(COMP_BASE,0,false))
	{
		ComparatorIntClear(COMP_BASE,0);
		Motion_Go_Back();		
	}
}




/*void I2C0_Handler(void)
{
	unsigned long X_acc = 0, Y_acc = 0, Z_acc = 0;
	if(I2CMasterIntStatus(I2C0_BASE,false))
	{
		I2CMasterIntClear(I2C0_BASE);
		//Perform a read from I2C
		
		//X_acc = I2C_Read(Acc_Slave_Adress,Acc_X8bit_Reg_Adress);
		//Y_acc = I2C_Read(Acc_Slave_Adress,Acc_Y8bit_Reg_Adress);
		//Z_acc = I2C_Read(Acc_Slave_Adress,Acc_Z8bit_Reg_Adress);
		
		//X_acceleration = X_acc;
		//Y_acceleration = Y_acc;
		//Z_acceleration = Z_acc;
	}
}*/

//EOF


