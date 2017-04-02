// os_hw.c - ssOS Target HW specific code - Interrupt Service Routines, Target configurations
// ssOS - stupid simple Operating System
// A very simple real time operating system with minimal features.
// For copyright, configuration and usage read readme.txt
/*
Pins with special purposes, need to be unlocked
-----------------------------------------------
PA[1:0] UART0
PA[5:2] SSI0
PB[3:2] I21C0
PC[3:0] JTAG/SWD
PD[7] 	GPIO
PF[0] 	GPIO
*/
/*------OS Includes------*/
#include "os_hw.h"
//#include "profile.h"

extern void (*OS_PeriodicTask[NUM_OS_PERIODIC_TASK])(void);   //array of pointers to void functions, OS embedded periodic tasks, NOT used / application periodic tasks

#ifdef TARGET_TM4C
//TM4C specific code

PortSema_t SemPortA;
PortSema_t SemPortB;
PortSema_t SemPortC;
PortSema_t SemPortD;
PortSema_t SemPortE;
PortSema_t SemPortF;

void GPIOPortC_Handler(void){	 //PortC GPIO interrupt handler
	// step 1 acknowledge by clearing flag
  // step 2 signal semaphore (no need to run scheduler)
  // step 3 disarm interrupt to prevent bouncing to create multiple signals
	uint8_t status;	
	status = GPIOIntStatus(GPIO_PORTC_BASE,false/*true*/);
	switch (status){
		case GPIO_INT_PIN_0:
	//if(status & GPIO_INT_PIN_0) {
		GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_0); //acknowledge by clearing flag
		OS_Signal(&SemPortC.pin0);  //signal semaphore
		GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_0);  //disarm interrupt to prevent bouncing to create multiple signals
		break;
		//}
	//if(status & GPIO_INT_PIN_1) { GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_1); OS_Signal(&SemPortC.pin1); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_1);}
		case GPIO_INT_PIN_1: GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_1); OS_Signal(&SemPortC.pin1); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_1); break;
	//else if(status & GPIO_INT_PIN_2) { GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_2); OS_Signal(&SemPortC.pin2); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_2);}
		case GPIO_INT_PIN_2: GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_2); OS_Signal(&SemPortC.pin2); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_2); break;
	//else if(status & GPIO_INT_PIN_3) { GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_3); OS_Signal(&SemPortC.pin3); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_3);}
		case GPIO_INT_PIN_3: GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_3); OS_Signal(&SemPortC.pin3); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_3); break;
	//else if(status & GPIO_INT_PIN_4) { GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_4); OS_Signal(&SemPortC.pin4); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_4);}
		case GPIO_INT_PIN_4: GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_4); OS_Signal(&SemPortC.pin4); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_4); break;
	//else if(status & GPIO_INT_PIN_5) { GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_5); OS_Signal(&SemPortC.pin5); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_5);}
		case GPIO_INT_PIN_5: GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_5); OS_Signal(&SemPortC.pin5); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_5); break;
	//else if(status & GPIO_INT_PIN_6) { GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_6); OS_Signal(&SemPortC.pin6); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_6);}
		case GPIO_INT_PIN_6: GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_6); OS_Signal(&SemPortC.pin6); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_6); break;
	//else if(status & GPIO_INT_PIN_7) { GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_7); OS_Signal(&SemPortC.pin7); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_7);}
		case GPIO_INT_PIN_7: GPIOIntClear(GPIO_PORTC_BASE,GPIO_INT_PIN_7); OS_Signal(&SemPortC.pin7); GPIOIntDisable(GPIO_PORTC_BASE, GPIO_INT_PIN_7); break;
		default: break;
	}
	OS_Suspend();
}


void GPIOPortD_Handler(void){	 //PortD GPIO interrupt handler
	// step 1 acknowledge by clearing flag
  // step 2 signal semaphore (no need to run scheduler)
  // step 3 disarm interrupt to prevent bouncing to create multiple signals
	uint8_t status;	
	status = GPIOIntStatus(GPIO_PORTD_BASE,/*false*/true);
	if(status & GPIO_INT_PIN_0) {
		GPIOIntClear(GPIO_PORTD_BASE,GPIO_INT_PIN_0); //acknowledge by clearing flag
		OS_Signal(&SemPortD.pin0);  //signal semaphore
		GPIOIntDisable(GPIO_PORTD_BASE, GPIO_INT_PIN_0);  //disarm interrupt to prevent bouncing to create multiple signals
	}
	if(status & GPIO_INT_PIN_1) { GPIOIntClear(GPIO_PORTD_BASE,GPIO_INT_PIN_1); OS_Signal(&SemPortD.pin1); GPIOIntDisable(GPIO_PORTD_BASE, GPIO_INT_PIN_1);}
	if(status & GPIO_INT_PIN_2) { GPIOIntClear(GPIO_PORTD_BASE,GPIO_INT_PIN_2); OS_Signal(&SemPortD.pin2); GPIOIntDisable(GPIO_PORTD_BASE, GPIO_INT_PIN_2);}
	if(status & GPIO_INT_PIN_3) {	GPIOIntClear(GPIO_PORTD_BASE,GPIO_INT_PIN_3); OS_Signal(&SemPortD.pin3); GPIOIntDisable(GPIO_PORTD_BASE, GPIO_INT_PIN_3);}
	if(status & GPIO_INT_PIN_4) { GPIOIntClear(GPIO_PORTD_BASE,GPIO_INT_PIN_4); OS_Signal(&SemPortD.pin4); GPIOIntDisable(GPIO_PORTD_BASE, GPIO_INT_PIN_4);}
	if(status & GPIO_INT_PIN_5) {	GPIOIntClear(GPIO_PORTD_BASE,GPIO_INT_PIN_5); OS_Signal(&SemPortD.pin5); GPIOIntDisable(GPIO_PORTD_BASE, GPIO_INT_PIN_5);}
	if(status & GPIO_INT_PIN_6) { GPIOIntClear(GPIO_PORTD_BASE,GPIO_INT_PIN_6); OS_Signal(&SemPortD.pin6); GPIOIntDisable(GPIO_PORTD_BASE, GPIO_INT_PIN_6);}
	if(status & GPIO_INT_PIN_7) {	GPIOIntClear(GPIO_PORTD_BASE,GPIO_INT_PIN_7); OS_Signal(&SemPortD.pin7); GPIOIntDisable(GPIO_PORTD_BASE, GPIO_INT_PIN_7);}
  OS_Suspend();
}

void GPIOPortF_Handler(void){	 //PortF GPIO interrupt handler
	uint8_t status;	
	status = GPIOIntStatus(GPIO_PORTF_BASE,/*false*/true);
	if(status & GPIO_INT_PIN_0) {
		GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_0); //acknowledge by clearing flag
		OS_Signal(&SemPortF.pin0);  //signal semaphore	
		GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_0);  //disarm interrupt to prevent bouncing to create multiple signals	
	}
	if(status & GPIO_INT_PIN_1) {	GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_1); OS_Signal(&SemPortF.pin1); GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_1);}
	if(status & GPIO_INT_PIN_2) {	GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_2); OS_Signal(&SemPortF.pin2); GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_2);}
	if(status & GPIO_INT_PIN_3) { GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_3); OS_Signal(&SemPortF.pin3); GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_3);}
	if(status & GPIO_INT_PIN_4) { GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_4); OS_Signal(&SemPortF.pin4); GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);}
  OS_Suspend();
}

// ******** OS_EdgeTrigger_Init ************
// Initialize a button, to signal on edge interrupt
// Inputs:  port , pin, priority, type, resistor
// Outputs: 1 if config is successfull, 0 if not
uint8_t OS_EdgeTrigger_Init(ports_t port, uint8_t pin, uint8_t priority, uint8_t type, uint8_t resistor){
	switch (port) {
		case PortA:  //PortA 
			//Need to unlock
			GPIO_PORTA_LOCK_R = 0x4C4F434B;  //Unlock GPIO Port D
			GPIO_PORTA_CR_R |= pin;  //Allow changes to PD7-0
			break;
		case PortB:  //PortB
			//Need to unlock
			break;
		case PortC:  //PortC
			//Need to unlock
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
			while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));
			if(pin & (GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3)){
				GPIO_PORTC_LOCK_R = 0x4C4F434B; //Unlock GPIO PC0-3 if necessary
			}
			GPIO_PORTC_CR_R |= pin;  //Allow changes to selected pis
			IntDisable(INT_GPIOC);
			GPIOIntDisable(GPIO_PORTC_BASE,pin);
			GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, pin);
			GPIOIntTypeSet(GPIO_PORTC_BASE, pin, type);
			GPIODirModeSet(GPIO_PORTC_BASE, pin, GPIO_DIR_MODE_IN);
			GPIOPadConfigSet(GPIO_PORTC_BASE, pin, GPIO_STRENGTH_2MA,resistor);
			GPIOIntEnable(GPIO_PORTC_BASE, pin);
			IntPrioritySet(INT_GPIOC,(priority<<5));
			IntEnable(INT_GPIOC);		
			break;
		case PortD:  //PortD	
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
			while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));
			if(pin & GPIO_PIN_7) { GPIO_PORTD_LOCK_R = 0x4C4F434B; } //Unlock GPIO PD7 if necessary
			GPIO_PORTD_CR_R |= pin;  //Allow changes to pin
			IntDisable(INT_GPIOD);
			GPIOIntDisable(GPIO_PORTD_BASE,pin);
			GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, pin);
			GPIOIntTypeSet(GPIO_PORTD_BASE, pin, type);
			GPIODirModeSet(GPIO_PORTD_BASE, pin, GPIO_DIR_MODE_IN);
			GPIOPadConfigSet(GPIO_PORTD_BASE, pin, GPIO_STRENGTH_2MA,resistor);
			GPIOIntEnable(GPIO_PORTD_BASE, pin);
			IntPrioritySet(INT_GPIOD,(priority<<5));
			IntEnable(INT_GPIOD);
			break;
		case PortE:  //PortE
			break;
		case PortF:  //PortF*/
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);	//Enable clock on port F
			while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
			if(pin && GPIO_PIN_0) { GPIO_PORTF_LOCK_R = 0x4C4F434B; } //Unlock GPIO PF0 if necessary
			GPIO_PORTF_CR_R |= pin;  //Allow changes to PF4-0
			
			IntDisable(INT_GPIOF);  //GPIO Port F disable of interrupts
			GPIOIntDisable(GPIO_PORTF_BASE,pin);  //Disable GPIO pin interrupt
			GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, pin);  //Set GPIO Input
			GPIOIntTypeSet(GPIO_PORTF_BASE, pin, type);  //Set Low level interrupt type
			GPIODirModeSet(GPIO_PORTF_BASE, pin, GPIO_DIR_MODE_IN);  //Set direction input
			GPIOPadConfigSet(GPIO_PORTF_BASE, pin, GPIO_STRENGTH_2MA,resistor); //Configure PUR
			GPIOIntEnable(GPIO_PORTF_BASE, pin);  //Enable GPIO pin interrupt
			IntPrioritySet(INT_GPIOF,(priority<<5)); //Priority 2 = "010"0.0000
			IntEnable(INT_GPIOF); //GPIO Port F enable of interrupts
			break;		
		default:
			return 0;  //error
	}
	return 1;  //OK
}

// ******** OS_EdgeTrigger_Restart ************
// restart button1 to signal on a falling edge interrupt
// rearm interrupt
// Inputs:  port, pin
// Outputs: 1 if config is successfull, 0 if not
uint8_t OS_EdgeTrigger_Restart(ports_t port, uint8_t pin){
	//arm interrupt
	//enable in NVIC
	//clear flags	???
	switch (port) {
		case PortA:  //PortA 
			break;
		case PortB:  //PortB
			break;
		case PortC:  //PortC
			GPIOIntEnable(GPIO_PORTC_BASE, pin);  //Enable GPIO pin interrupt
			IntEnable(INT_GPIOC); //GPIO Port D enable of interrupts
			break;
		case PortD:  //PortD
			GPIOIntEnable(GPIO_PORTD_BASE, pin);  //Enable GPIO pin interrupt
			IntEnable(INT_GPIOD); //GPIO Port D enable of interrupts
			break;
		case PortE:  //PortE
			break;
		case PortF:  //PortF
			GPIOIntEnable(GPIO_PORTF_BASE, pin);  //Enable GPIO pin interrupt
			IntEnable(INT_GPIOF); //GPIO Port F enable of interrupts
			break;		
		default:
			return 0;  //error
	}
	return 1;  //OK
}

// ******** OS_Clock_Init ************
// init the system clock to the desired speed in Mhz
// Inputs:  Desired frequency, MHz (Version 1.2 allows 13, 16, 20, 40, 45, 50, 66, 80 Mhz
// Outputs: System clock if config is successfull, 0 if not
uint32_t OS_Clock_Init(uint8_t clock_Mhz){
	unsigned long check_freq_hz = 0;
	unsigned long init_freq_hz = 0;	
	switch (clock_Mhz) {
		case 13:  //13.33 Mhz
			SysCtlClockSet(SYSCTL_SYSDIV_15 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);  // Configure to run at 13.33 MHz from the PLL using a 16 MHz crystal as the input.
			check_freq_hz = 13333333;
			break;
		case 16:  //16 MHz 
			SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_OSC_INT | SYSCTL_USE_OSC);  //Sets the use of PIOSC (precision internal oscilator) as clock source, 16 MHz
			check_freq_hz = 16000000;
			break;
		case 20:  //20 MHz
			SysCtlClockSet(SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
			// Set the clocking to run directly from the PLL at 20 MHz.
			// sets the system clock divider to 10 (200 MHz PLL divide by 10 = 20 MHz)
			// sets the system clock to use the PLL
			// uses the main oscillator
			// configures for use of 16 MHz crystal/oscillator input
			check_freq_hz = 20000000;
			break;
		case 40:  //40 Mhz
			SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);  // Setup the system clock to run at 40 Mhz from PLL with crystal reference
			check_freq_hz = 40000000;
			break;
		case 45:  //45 Mhz
			SysCtlClockSet(SYSCTL_SYSDIV_4_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);  // Setup the system clock to run at 40 Mhz from PLL with crystal reference
			check_freq_hz = 44444444;
			break;
		case 50:  //50 Mhz
			SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);  // Setup the system clock to run at 50 Mhz from PLL with crystal reference
			check_freq_hz = 50000000;
			break;
		case 66:  //66 Mhz
			SysCtlClockSet(SYSCTL_SYSDIV_3 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);  // Setup the system clock to run at 66 Mhz from PLL with crystal reference
			check_freq_hz = 66666666;
			break;
		case 80:  //80 Mhz
			SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN); //80 Mhz
			check_freq_hz = 80000000;
			init_freq_hz = SysCtlClockGet();
			break;		
		default:
			return 0;  //error
	}
	
	return (check_freq_hz == init_freq_hz);  //OK
	/*
	This function configures the clocking of the device. The input crystal frequency, oscillator to be
	used, use of the PLL, and the system clock divider are all configured with this function.
	The ui32Config parameter is the logical OR of several different values, many of which are
	grouped into sets where only one can be chosen.
	
	The system clock divider is chosen with one of the following values: SYSCTL_SYSDIV_1,
	SYSCTL_SYSDIV_2, SYSCTL_SYSDIV_3, ... SYSCTL_SYSDIV_64.
	The use of the PLL is chosen with either SYSCTL_USE_PLL or SYSCTL_USE_OSC.
	The external crystal frequency is chosen with one of the following values:
	SYSCTL_XTAL_4MHZ, SYSCTL_XTAL_4_09MHZ, SYSCTL_XTAL_4_91MHZ,
	SYSCTL_XTAL_5MHZ, SYSCTL_XTAL_5_12MHZ, SYSCTL_XTAL_6MHZ,
	SYSCTL_XTAL_6_14MHZ, SYSCTL_XTAL_7_37MHZ, SYSCTL_XTAL_8MHZ,
	SYSCTL_XTAL_8_19MHZ, SYSCTL_XTAL_10MHZ, SYSCTL_XTAL_12MHZ,
	SYSCTL_XTAL_12_2MHZ, SYSCTL_XTAL_13_5MHZ, SYSCTL_XTAL_14_3MHZ,
	SYSCTL_XTAL_16MHZ, SYSCTL_XTAL_16_3MHZ, SYSCTL_XTAL_18MHZ,
	SYSCTL_XTAL_20MHZ, SYSCTL_XTAL_24MHZ, or SYSCTL_XTAL_25MHz. Values
	below SYSCTL_XTAL_5MHZ are not valid when the PLL is in operation.
	The oscillator source is chosen with one of the following values: SYSCTL_OSC_MAIN,
	SYSCTL_OSC_INT, SYSCTL_OSC_INT4, SYSCTL_OSC_INT30, or SYSCTL_OSC_EXT32.
	SYSCTL_OSC_EXT32 is only available on devices with the hibernate module, and then only
	when the hibernate module has been enabled.
	The internal and main oscillators are disabled with the SYSCTL_INT_OSC_DIS and
	SYSCTL_MAIN_OSC_DIS flags, respectively. The external oscillator must be enabled in order
	to use an external clock source. Note that attempts to disable the oscillator used to clock the
	device is prevented by the hardware.
	To clock the system from an external source (such as an external crystal oscillator), use
	SYSCTL_USE_OSC j SYSCTL_OSC_MAIN. To clock the system from the main oscillator,
	use SYSCTL_USE_OSC j SYSCTL_OSC_MAIN. To clock the system from the PLL, use
	SYSCTL_USE_PLL j SYSCTL_OSC_MAIN, and select the appropriate crystal with one of
	the SYSCTL_XTAL_xxx values.
	*/
}

// ******** OS_Timer_Init ************
// Init desired system timer at desired frequency in Hz
// Inputs:  Selected timer (rev 1.2 allows only TimerA and WTimerA, Timer module 0 - 5, totally 12 timers)
//          Desired frequency, MHz
// Outputs: 1 if config is successfull, 0 if not
uint8_t OS_Timer_Init(timers_t timer, uint32_t freqency, uint8_t priority){
	uint32_t reload_value = 0;
  int32_t status; //I bit status
  status = StartCritical(); //Disable Interrupts
	reload_value = ((SysCtlClockGet() / freqency) - 1);
	switch (timer) {
		case Timer0A:
			SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);	//Timer 0 enable
			IntDisable(INT_TIMER0A);	//Timer 0A disable of interrupts
			TimerIntDisable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(TIMER0_BASE, TIMER_A);	
			TimerClockSourceSet(TIMER0_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(TIMER0_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(TIMER0_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(TIMER0_BASE, TIMER_A);
			TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_TIMER0A,(priority)<<5);	//Priority 3 = "011"0.0000
			IntEnable(INT_TIMER0A);	//Timer 0A enable of interrupts	
			break;
		case Timer1A:
			SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);	//Timer 0 enable
			IntDisable(INT_TIMER1A);	//Timer 0A disable of interrupts
			TimerIntDisable(TIMER1_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(TIMER1_BASE, TIMER_A);	
			TimerClockSourceSet(TIMER1_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(TIMER1_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(TIMER1_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(TIMER1_BASE, TIMER_A);
			TimerIntEnable(TIMER1_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_TIMER1A,(priority)<<5);	//Priority 3 = "011"0.0000
			IntEnable(INT_TIMER1A);	//Timer 0A enable of interrupts	
			break;
		case Timer2A:
			SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);	//Timer 0 enable
			IntDisable(INT_TIMER2A);	//Timer 0A disable of interrupts
			TimerIntDisable(TIMER2_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(TIMER2_BASE, TIMER_A);	
			TimerClockSourceSet(TIMER2_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(TIMER2_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(TIMER2_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(TIMER2_BASE, TIMER_A);
			TimerIntEnable(TIMER2_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_TIMER2A,(priority)<<5);	//Priority 3 = "011"0.0000
			IntEnable(INT_TIMER2A);	//Timer 0A enable of interrupts	
			break;
		case Timer3A:
			SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);	//Timer 0 enable
			IntDisable(INT_TIMER3A);	//Timer 0A disable of interrupts
			TimerIntDisable(TIMER3_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(TIMER3_BASE, TIMER_A);	
			TimerClockSourceSet(TIMER3_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(TIMER3_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(TIMER3_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(TIMER3_BASE, TIMER_A);
			TimerIntEnable(TIMER3_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_TIMER3A,(priority)<<5);	//Priority 3 = "011"0.0000
			IntEnable(INT_TIMER3A);	//Timer 0A enable of interrupts	
			break;
		case Timer4A:
			SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER4);	//Timer 0 enable
			IntDisable(INT_TIMER4A);	//Timer 0A disable of interrupts
			TimerIntDisable(TIMER4_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(TIMER4_BASE, TIMER_A);	
			TimerClockSourceSet(TIMER4_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(TIMER4_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(TIMER4_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(TIMER4_BASE, TIMER_A);
			TimerIntEnable(TIMER4_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_TIMER4A,(priority)<<5);	//Priority 3 = "011"0.0000
			IntEnable(INT_TIMER4A);	//Timer 0A enable of interrupts	
			break;
		case Timer5A:
			SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER5);	//Timer 0 enable
			IntDisable(INT_TIMER5A);	//Timer 0A disable of interrupts
			TimerIntDisable(TIMER5_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(TIMER5_BASE, TIMER_A);	
			TimerClockSourceSet(TIMER5_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(TIMER5_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(TIMER5_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(TIMER5_BASE, TIMER_A);
			TimerIntEnable(TIMER5_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_TIMER5A,(priority)<<5);	//Priority 3 = "011"0.0000
			IntEnable(INT_TIMER5A);	//Timer 0A enable of interrupts	
			break;
		case WTimer0A:  // 32/64 bit
			SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);  //Wide Timer 0 enable 
			IntDisable(INT_WTIMER0A);  //Wide Timer 0A disable of interrupts
			TimerIntDisable(WTIMER0_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(WTIMER0_BASE, TIMER_A);
			TimerClockSourceSet(WTIMER0_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(WTIMER0_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(WTIMER0_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(WTIMER0_BASE, TIMER_A);
			TimerIntEnable(WTIMER0_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_WTIMER0A,(priority)<<5);  //Priority 1 = "001"0.0000
			IntEnable(INT_WTIMER0A);	//Wide Timer 0A enable of interrupts
			break;
		case WTimer1A:
			SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER1);  //Wide Timer 0 enable 
			IntDisable(INT_WTIMER1A);  //Wide Timer 0A disable of interrupts
			TimerIntDisable(WTIMER1_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(WTIMER1_BASE, TIMER_A);
			TimerClockSourceSet(WTIMER1_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(WTIMER1_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(WTIMER1_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(WTIMER1_BASE, TIMER_A);
			TimerIntEnable(WTIMER1_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_WTIMER1A,(priority)<<5);  //Priority 1 = "001"0.0000
			IntEnable(INT_WTIMER1A);	//Wide Timer 0A enable of interrupts
			break;
		case WTimer2A:
			SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER2);  //Wide Timer 0 enable 
			IntDisable(INT_WTIMER2A);  //Wide Timer 0A disable of interrupts
			TimerIntDisable(WTIMER2_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(WTIMER2_BASE, TIMER_A);
			TimerClockSourceSet(WTIMER2_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(WTIMER2_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(WTIMER2_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(WTIMER2_BASE, TIMER_A);
			TimerIntEnable(WTIMER2_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_WTIMER2A,(priority)<<5);  //Priority 1 = "001"0.0000
			IntEnable(INT_WTIMER2A);	//Wide Timer 0A enable of interrupts
			break;
		case WTimer3A:
			SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER3);  //Wide Timer 0 enable 
			IntDisable(INT_WTIMER3A);  //Wide Timer 0A disable of interrupts
			TimerIntDisable(WTIMER3_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(WTIMER3_BASE, TIMER_A);
			TimerClockSourceSet(WTIMER3_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(WTIMER3_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(WTIMER3_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(WTIMER3_BASE, TIMER_A);
			TimerIntEnable(WTIMER3_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_WTIMER3A,(priority)<<5);  //Priority 1 = "001"0.0000
			IntEnable(INT_WTIMER3A);	//Wide Timer 0A enable of interrupts
			break;
		case WTimer4A:
			SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER4);  //Wide Timer 0 enable 
			IntDisable(INT_WTIMER4A);  //Wide Timer 0A disable of interrupts
			TimerIntDisable(WTIMER4_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(WTIMER4_BASE, TIMER_A);
			TimerClockSourceSet(WTIMER4_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(WTIMER4_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(WTIMER4_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(WTIMER4_BASE, TIMER_A);
			TimerIntEnable(WTIMER4_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_WTIMER4A,(priority)<<5);  //Priority 1 = "001"0.0000
			IntEnable(INT_WTIMER4A);	//Wide Timer 0A enable of interrupts
			break;
		case WTimer5A:
			SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER5);  //Wide Timer 0 enable 
			IntDisable(INT_WTIMER5A);  //Wide Timer 0A disable of interrupts
			TimerIntDisable(WTIMER5_BASE,TIMER_TIMA_TIMEOUT);
			TimerDisable(WTIMER5_BASE, TIMER_A);
			TimerClockSourceSet(WTIMER5_BASE, TIMER_CLOCK_SYSTEM);
			TimerConfigure(WTIMER5_BASE, TIMER_CFG_A_PERIODIC);
			TimerLoadSet(WTIMER5_BASE, TIMER_A, reload_value);	//Set cycle nr desired freqency
			TimerEnable(WTIMER5_BASE, TIMER_A);
			TimerIntEnable(WTIMER5_BASE,TIMER_TIMA_TIMEOUT);
			IntPrioritySet(INT_WTIMER5A,(priority)<<5);  //Priority 1 = "001"0.0000
			IntEnable(INT_WTIMER5A);	//Wide Timer 0A enable of interrupts
			break;
		default:
			return 0;  //error
	}
	EndCritical(status);
	return 1;  //OK
}

void Timer0A_Handler(void)		//Timer 0A ISR
{
	//TimerIntClear(TIMER0_BASE, TIMER_A);
	//(*OS_PeriodicTask[0])();
}

void Timer1A_Handler(void)		//Timer 1A ISR
{
	//TimerIntClear(TIMER1_BASE, TIMER_A);
	//(*OS_PeriodicTask[1])();
}

void WideTimer0A_Handler(void)		//Wide Timer 0A ISR
{
	TimerIntClear(WTIMER0_BASE, TIMER_A);
	//Profile_Toggle5();
	(*OS_PeriodicTask[0])();
}

void WideTimer1A_Handler(void)		//Wide Timer 1A ISR
{
	TimerIntClear(WTIMER1_BASE, TIMER_A);
	//Profile_Toggle6();
	(*OS_PeriodicTask[1])();
}

void OS_SysTick_Init(uint32_t time)
{
	/*
	IntDisable(INT_SYSCTL);
	SysTickIntDisable();
	SysTickDisable();
	SysTickPeriodSet(time-1);
	SysTickEnable();
	SysTickIntEnable();
	IntPrioritySet(INT_SYSCTL,(7)<<5);	//Priority 3 = "011"0.0000
	IntEnable(INT_SYSCTL);	//Timer 0A enable of interrupts	
	*/
}

#endif //TARGET_TM4C

#ifdef TARGET_MSP432
//MSP432 specific code
#endif //TARGET_TM4C

//EOF
