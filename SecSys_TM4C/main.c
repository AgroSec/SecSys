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
#include "startup_handler.h"
#include "cyclic_activity_handler.h"
//#include "gpio_handler.h"
#include "uart_handler.h"
#include "GSM.h"

uint32_t Count0_PIRA;  // number of times Task0 loops
uint32_t Count1_PIRB;  // number of times Task1 loops
uint32_t Count2_Cyclic10ms;   // number of times Task2 loops
uint32_t Count3_Cyclic50ms;   // number of times Task3 loops
uint32_t Count4_Cyclic100ms;  // number of times Task4 loops
uint32_t Count5_Cyclic500ms;  // number of times Task5 loops
uint32_t Count6_Cyclic1000ms; // number of times Task6 loops
uint32_t Count7_Blank; // number of times Task7 loops
uint32_t Count8_Blank; // number of times Task8 loops
uint32_t CountIdle;    // number of times Idle_Task loops

int32_t Task78Sync;
int32_t Task87Sync;
int32_t SerialMonitor; //Semaphore to block serial monitor
int32_t GSMModule; //Semaphore to block GSM module

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
			Toggle0();
			OS_Wait(&SerialMonitor);
			UART0_SendString("PIR A Triggered a number of: ");
			UART0_SendUDecimal(Count0_PIRA);
			UART0_SendString(" times.");
			UART0_SendNewLine();
			OS_Signal(&SerialMonitor);
			OS_Wait(&GSMModule);
			SendSMS(PIR_A);
			OS_Signal(&GSMModule);
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
			Toggle1();
			OS_Wait(&SerialMonitor);
			UART0_SendString("PIR B Triggered a number of: ");
			UART0_SendUDecimal(Count1_PIRB);
			UART0_SendString(" times.");
			UART0_SendNewLine();
			OS_Signal(&SerialMonitor);
			OS_Wait(&GSMModule);
			SendSMS(PIR_B);
			OS_Signal(&GSMModule);
		}
		OS_EdgeTrigger_Restart(PortC,GPIO_PIN_7);
  }
}
void Task2_Cyclic10ms(void){  //Periodic task 10ms
  Count2_Cyclic10ms = 0;
	uint8_t LED_Status = 0;
  while(1){
		OS_Wait(&PerTask[0].semaphore);
		CYCL_10ms();
		Count2_Cyclic10ms++;
		Toggle2();
	}
}
void Task3_Cyclic50ms(void){  //Periodic task 50ms
  Count3_Cyclic50ms = 0;
  while(1){
		OS_Wait(&PerTask[1].semaphore);
		CYCL_50ms();
		Count3_Cyclic50ms++;
		Toggle3();	
	}
}

void Task4_Cyclic100ms(void){  //Periodic task 100ms
	Count4_Cyclic100ms = 0;
  while(1){
		OS_Wait(&PerTask[2].semaphore);
		CYCL_100ms();
		Count4_Cyclic100ms++;
		Toggle4();	
	}
}

void Task5_Cyclic500ms(void){  //Periodic task 500ms
	Count5_Cyclic500ms = 0;
  while(1){
		OS_Wait(&PerTask[3].semaphore);
		CYCL_500ms();
		Count5_Cyclic500ms++;
		Toggle5();
	}
}

void Task6_Cyclic1000ms(void){
	Count6_Cyclic1000ms = 0;
	while(1){
		OS_Wait(&PerTask[4].semaphore);
		CYCL_1000ms();
		Count6_Cyclic1000ms++;
		Toggle6();
	}
}

void Task7_BlankTask(void){
	Count7_Blank = 0;
	while(1){
		Count7_Blank++;
		Toggle0();
		OS_Sleep(1000);
	}
}

void Task8_BlankTask(void){
Count8_Blank = 0;
	while(1){
		Count8_Blank++;
		Toggle1();
		OS_Sleep(60000);
		SendSMS(Status);
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
	OS_InitSemaphore(&GSMModule,1);

	//OS_InitSemaphore(&SemPortF.pin0,0);
	//OS_InitSemaphore(&SemPortF.pin4,0);
	
	//4	
	OS_EdgeTrigger_Init(PortC,GPIO_PIN_6|GPIO_PIN_7,INT_PRIO_PIN,GPIO_RISING_EDGE,GPIO_PIN_TYPE_STD_WPD);
	//OS_EdgeTrigger_Init(PortF,GPIO_PIN_0|GPIO_PIN_4,INT_PRIO_PIN,GPIO_FALLING_EDGE,GPIO_PIN_TYPE_STD_WPU);
	
	//5
	OS_AddPeriodicEventThread(&PerTask[0].semaphore, 10);
	OS_AddPeriodicEventThread(&PerTask[1].semaphore, 50);
	OS_AddPeriodicEventThread(&PerTask[2].semaphore, 100);
	OS_AddPeriodicEventThread(&PerTask[3].semaphore, 500);
	OS_AddPeriodicEventThread(&PerTask[4].semaphore, 1000);
	
	//6
  OS_AddThreads(&Task0_PIRA, TASK0_PRIO,
	              &Task1_PIRB, TASK1_PRIO,
								&Task2_Cyclic10ms,  TASK2_PRIO,
								&Task3_Cyclic50ms,  TASK3_PRIO,
								&Task4_Cyclic100ms, TASK4_PRIO,
								&Task5_Cyclic500ms, TASK5_PRIO,
								&Task6_Cyclic1000ms,TASK6_PRIO,
								&Task7_BlankTask,BLANK_TASK_PRIO,
                &Task8_BlankTask,BLANK_TASK_PRIO,
	              &Idle_Task,IDLE_TASK_PRIO);	//Idle task is lowest priority
	//7
	/*OS_FIFO_Init(&FifoA);
	//8
	OS_InitSemaphore(&Task78Sync,0);
	OS_InitSemaphore(&Task87Sync,0);*/
  //9
	InitDrivers();
	InitApplications();
	
	OS_Launch(SysCtlClockGet()/THREADFREQ); // doesn't return, interrupts enabled in here
  return 0;  // this never executes
}
//EOF
