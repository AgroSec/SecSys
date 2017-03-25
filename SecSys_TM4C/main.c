// main.c - ssOS usage example
// Runs on LM4F120/TM4C123 will be ported to MSP432 in next version
// ssOS - stupid simple Operating System
// A very simple real time operating system with minimal features.
// For copyright, configuration and usage read readme.txt

//#include "../inc/tm4c123gh6pm.h"  //AleGaa not needed at the moment

/*---------------------OS Includes--------------------*/
#include "os_hw.h"
#include "os_core.h"
#include "os_config.h"
#include "profile.h"
/*-------------------Service Includes-----------------*/
#include "uart_handler.h"


// runs each thread 2 ms
uint32_t Count0_PIRA;   // number of times Task0 loops
uint32_t Count1_PIRB;   // number of times Task1 loops
uint32_t Count2;   // number of times Task2 loops
uint32_t Count3;   // number of times Task3 loops
uint32_t Count4;   // number of times Task4 loops
uint32_t Count5;   // number of times Task5 loops
uint32_t Count6;   // number of times Task6 loops
uint32_t Count7_SerialStatus;   // number of times Task7 loops
uint32_t Count8_SerialCommand;  // number of times Task8 loops
uint32_t CountIdle;  // number of times Idle_Task loops

int32_t Task78Sync;
int32_t Task87Sync;
int32_t SerialMonitor; //Semaphore to block serial monitor

fifo_t FifoA;

extern ptcbType PerTask[NUMPERIODIC];
extern PortSema_t SemPortC;
extern PortSema_t SemPortD;
extern PortSema_t SemPortF;

void Task0_PIRA(void){	//Edge triggered task
  Count0_PIRA = 0;
  while(1){
		OS_Wait(&SemPortC.pin6); // signaled in OS on button touch
		OS_Sleep(50); //sleep to debounce switch		
		if(GPIOPinRead(GPIO_PORTC_BASE,GPIO_INT_PIN_6)) {   
			Count0_PIRA++;
		}
		OS_EdgeTrigger_Restart(PortC,GPIO_PIN_6);
  }
}
void Task1_PIRB(void){	//Edge triggered task
  Count1_PIRB = 0;
  while(1){
		OS_Wait(&SemPortC.pin7); // signaled in OS on button touch
		OS_Sleep(50); //sleep to debounce switch		
		if(GPIOPinRead(GPIO_PORTC_BASE,GPIO_INT_PIN_7)) {   
			Count1_PIRB++;
		}
		OS_EdgeTrigger_Restart(PortC,GPIO_PIN_7);
  }
}
void Task2(void){		//Edge triggered task PF0
  Count2 = 0;
  while(1){
		OS_Wait(&SemPortF.pin0); // signaled in OS on button touch
		OS_Sleep(50); //sleep to debounce switch		
		if(!GPIOPinRead(GPIO_PORTF_BASE,GPIO_INT_PIN_0)) {   
			Profile_Toggle2();
			Count2++;
		}
		OS_EdgeTrigger_Restart(PortF,GPIO_PIN_0);
		/*
		Count2++;
		Profile_Toggle2();
		OS_Sleep(50);
		*/
	}
}
void Task3(void){	 //response to task PF4
  Count3 = 0;
  while(1){
		OS_Wait(&SemPortF.pin4); // signaled in OS on button touch
		OS_Sleep(50); //sleep to debounce switch		
		if(!GPIOPinRead(GPIO_PORTF_BASE,GPIO_INT_PIN_4)) {   
			Profile_Toggle3();
			Count3++;
		}
		OS_EdgeTrigger_Restart(PortF,GPIO_PIN_4);
		/*
		Count3++;
		//Profile_Toggle3();
		OS_Sleep(100);
		*/
	}
}

void Task4(void){	 //Edge triggered task PD6
	Count4 = 0;
  while(1){
		OS_Wait(&SemPortD.pin6); // signaled in OS on button touch
		OS_Sleep(50); //sleep to debounce switch		
		if(!GPIOPinRead(GPIO_PORTD_BASE,GPIO_INT_PIN_6)) {   
			Profile_Toggle4();
			Count4++;
		}
		OS_EdgeTrigger_Restart(PortD,GPIO_PIN_6);
		
		//Count4++;
		//Profile_Toggle4();
		//OS_Sleep(150);
	}
}

void Task5(void){	 //response to task PD7
	Count5 = 0;
  while(1){
		OS_Wait(&SemPortD.pin7); // signaled in OS on button touch
		OS_Sleep(50); //sleep to debounce switch		
		if(!GPIOPinRead(GPIO_PORTD_BASE,GPIO_INT_PIN_7)) {   
			Profile_Toggle5();
			Count5++;
		}
		OS_EdgeTrigger_Restart(PortD,GPIO_INT_PIN_7);
		
		//Count5++;
		//Profile_Toggle5();
		//OS_Sleep(300);
	}
}

void Task6(void){
	Count6 = 0;
	while(1){
		Count6++;
		//Profile_Toggle6();
		OS_Sleep(500);
	}
}

void Task7_SerialStatus(void){
	Count7_SerialStatus = 0;
	while(1){
		OS_Wait(&SerialMonitor);
		Count7_SerialStatus++;
		UART0_SendString("System status is: ");
		UART0_SendNewLine();
		OS_Sleep(5000);
		OS_Signal(&SerialMonitor);		
	}
}

void Task8_SerialCommand(void){
	uint32_t command = 0;
	while(1){
		OS_Wait(&SerialMonitor);
		UART0_SendNewLine();
		UART0_SendString("Please input any command: ");
		command = UART0_GetUDecimal();
		UART0_SendNewLine();
	}
}

void Idle_Task(void){
  CountIdle = 0;
  while(1){
    CountIdle++;
  }
}

int main(void){
	//2
	OS_Init(80);  // initialize, disable interrupts
	
	Profile_Init();  // enable digital I/O on profile pins
	
	//3
	OS_InitSemaphore(&SemPortC.pin6,0);
	OS_InitSemaphore(&SemPortC.pin7,0);
	OS_InitSemaphore(&SerialMonitor,1);

	//OS_InitSemaphore(&SemPortF.pin0,0);
	//OS_InitSemaphore(&SemPortF.pin4,0);
	
	//4	
	OS_EdgeTrigger_Init(PortC,GPIO_PIN_6|GPIO_PIN_7,INT_PRIO_PIN,GPIO_RISING_EDGE,GPIO_PIN_TYPE_STD_WPD);
	//OS_EdgeTrigger_Init(PortF,GPIO_PIN_0|GPIO_PIN_4,INT_PRIO_PIN,GPIO_FALLING_EDGE,GPIO_PIN_TYPE_STD_WPU);
	
	//5
	OS_AddPeriodicEventThread(&PerTask[0].semaphore, 10);
	//OS_AddPeriodicEventThread(&PerTask[1].semaphore, 50);
	
	//6
  OS_AddThreads(&Task0_PIRA, 15,
	              &Task1_PIRB, 15,
								&Task7_SerialStatus,250,
                &Task8_SerialCommand,200,
	              &Idle_Task,254);	//Idle task is lowest priority
	//7
	/*OS_FIFO_Init(&FifoA);
	//8
	OS_InitSemaphore(&Task78Sync,0);
	OS_InitSemaphore(&Task87Sync,0);*/
  //9
	UART0_Init();
	
	OS_Launch(SysCtlClockGet()/THREADFREQ); // doesn't return, interrupts enabled in here
  return 0;  // this never executes
}
//EOF
