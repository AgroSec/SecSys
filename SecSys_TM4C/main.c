// main.c - ssOS usage example
// Runs on LM4F120/TM4C123 will be ported to MSP432 in next version
// ssOS - stupid simple Operating System
// A very simple real time operating system with minimal features.
// For copyright, configuration and usage read readme.txt

//#include "../inc/tm4c123gh6pm.h"  //AleGaa not needed at the moment
/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"
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

/*-----------------Application Includes---------------*/
#include "GSM.h"
#include "PIR.h"
#include "pc_display.h"

/*-------------Global Variable Definitions------------*/
uint32_t Count0_PIRA;  // number of times Task0 loops
uint32_t Count1_PIRB;  // number of times Task1 loops
uint32_t Count2_Cyclic10ms;   // number of times Task2 loops
uint32_t Count3_Cyclic50ms;   // number of times Task3 loops
uint32_t Count4_Cyclic100ms;  // number of times Task4 loops
uint32_t Count5_Cyclic500ms;  // number of times Task5 loops
uint32_t Count6_Cyclic1000ms; // number of times Task6 loops
uint32_t Count7_PIRA_Process; // number of times Task7 loops
uint32_t Count8_PIRB_Process; // number of times Task8 loops
uint32_t CountIdle;    // number of times Idle_Task loops

uint32_t PIR_A_Trigger_Nr = 0;
uint32_t PIR_B_Trigger_Nr = 0;
uint32_t PIR_A_Alarm_Nr = 0;
uint32_t PIR_B_Alarm_Nr = 0;

int32_t Task7Sync;
int32_t Task8Sync;
//fifo_t FifoA;
int32_t SystemReset; //Semaphore to block startup task
int32_t SerialMonitor; //Semaphore to block serial monitor
int32_t GSMModule; //Semaphore to block GSM module

extern ptcbType PerTask[NUMPERIODIC];
extern PortSema_t SemPortC;
//extern PortSema_t SemPortD;
extern PortSema_t SemPortF;

bool startupReady = True;

/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/

void Task0_PIRA(void){	//Edge triggered task
  Count0_PIRA = 0;
  while(1){
		if(startupReady) {
			OS_Wait(&SemPortC.pin6);  // signaled in ISR
			OS_Sleep(50); //sleep to debounce switch		
			if(GPIOPinRead(GPIO_PORTC_BASE,GPIO_INT_PIN_6)) {   
				Count0_PIRA++;
				Toggle0();
				OS_Wait(&SerialMonitor);
				PC_Display_Message("PIR A Triggered a number of: ",Count0_PIRA," times.");
				OS_Signal(&SerialMonitor);
				PIR_A_Trigger_Nr++;	
				if(PIR_A_Trigger_Nr == 1) OS_Signal(&Task7Sync); //1st trigger in PIR process timeperiod
			}
			OS_EdgeTrigger_Restart(PortC,GPIO_PIN_6);
		}
  }
}
void Task1_PIRB(void){	//Edge triggered task
  Count1_PIRB = 0;
  while(1){
		if(startupReady) {
			OS_Wait(&SemPortC.pin7);  // signaled in ISR
			OS_Sleep(50); //sleep to debounce switch		
			if(GPIOPinRead(GPIO_PORTC_BASE,GPIO_INT_PIN_7)) {
				Count1_PIRB++;
				Toggle1();
				OS_Wait(&SerialMonitor);
					PC_Display_Message("PIR B Triggered a number of: ",Count1_PIRB," times.");
				OS_Signal(&SerialMonitor);
				PIR_B_Trigger_Nr++;
				if(PIR_B_Trigger_Nr == 1) OS_Signal(&Task8Sync); //1st trigger in PIR process timeperiod
			}
			OS_EdgeTrigger_Restart(PortC,GPIO_PIN_7);
		}
  }
}
void Task2_Cyclic10ms(void){  //Periodic task 10ms
  Count2_Cyclic10ms = 0;
  while(1){
		if(startupReady) {
			OS_Wait(&PerTask[0].semaphore);
			CYCL_10ms();
			Count2_Cyclic10ms++;
			Toggle2();
		}
	}
}
void Task3_Cyclic50ms(void){  //Periodic task 50ms
  Count3_Cyclic50ms = 0;
  while(1){
		if(startupReady) {
			OS_Wait(&PerTask[1].semaphore);
			CYCL_50ms();
			Count3_Cyclic50ms++;
			Toggle3();	
		}
	}
}

void Task4_Cyclic100ms(void){  //Periodic task 100ms
	Count4_Cyclic100ms = 0;
  while(1){
		if(startupReady) {
			OS_Wait(&PerTask[2].semaphore);
			CYCL_100ms();
			Count4_Cyclic100ms++;
			Toggle4();	
		}
	}
}

void Task5_Cyclic500ms(void){  //Periodic task 500ms
	Count5_Cyclic500ms = 0;
  while(1){
		if(startupReady) {
			OS_Wait(&PerTask[3].semaphore);
			CYCL_500ms();
			Count5_Cyclic500ms++;
			Toggle5();
		}
	}
}

void Task6_Cyclic1000ms(void){
	Count6_Cyclic1000ms = 0;
	while(1){
		if(startupReady) {
			OS_Wait(&PerTask[4].semaphore);
			CYCL_1000ms();
			Count6_Cyclic1000ms++;
			Toggle6();
		}
	}
}

void Task7_ProcessPIRA(void){
	Count7_PIRA_Process = 0;
	while(1){
		if(startupReady) {
			OS_Wait(&Task7Sync);  //Wait for first PIR trigger in timeframe
			Toggle0();  //Process task starts
			OS_Sleep(PIR_TRIGGERS_TIMEFRAME*1000);  //Sleep for PIR_TRIGGERS_TIMEFRAME seconds
			Count7_PIRA_Process++;
			if(PIR_A_Trigger_Nr >= PIR_TRIGGERS_TO_ALARM){  //Check if it's necessary to raise alarm
				PIR_A_Alarm_Nr++;
				OS_Wait(&GSMModule); 
				SendSMS(PIR_A);
				OS_Signal(&GSMModule); 
				PC_Display_Message("PIR A Alarm raised: ",PIR_A_Alarm_Nr," times.");
			}
			PIR_A_Trigger_Nr = 0
			Toggle0();  //Process task ends
		}
	}
}

void Task8_ProcessPIRB(void){
Count8_PIRB_Process = 0;
	while(1){
		if(startupReady) {
			OS_Wait(&Task8Sync);
			Toggle1();
			OS_Sleep(PIR_TRIGGERS_TIMEFRAME*1000);  //Sleep for PIR_TRIGGERS_TIMEFRAME seconds
			Count8_PIRB_Process++;
			if(PIR_B_Trigger_Nr >= PIR_TRIGGERS_TO_ALARM){  //Check if it's necessary to raise alarm
				PIR_B_Alarm_Nr++;
				OS_Wait(&GSMModule);
				SendSMS(PIR_B);
				OS_Signal(&GSMModule); 
				PC_Display_Message("PIR B Alarm raised: ",PIR_B_Alarm_Nr," times.");
			}
			PIR_B_Trigger_Nr = 0
			Toggle1();
		}
	}
}

void Task9_BlankTask(void){
	while(1){
		if(startupReady) {
			OS_Wait(&SemPortF.pin0);  // signaled in OS on button touch
			OS_Sleep(50);  //sleep to debounce switch		
			if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_INT_PIN_0)!=GPIO_PIN_0) {
				PC_Display_Message("Task 9 - SMS send test started",0,"");
				OS_Wait(&GSMModule);
				SendSMS(PIR_A);
				OS_Signal(&GSMModule);
				PC_Display_Message("Task 9 - SMS send test executed",0,"");
			}
			OS_EdgeTrigger_Restart(PortF,GPIO_PIN_0);
		}
	}
}

void Task10_BlankTask(void){
	while(1){
		if(startupReady) {
			OS_Wait(&SemPortF.pin4);  // signaled in OS on button touch
			OS_Sleep(50);  //sleep to debounce switch		
			if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_INT_PIN_4)!=GPIO_PIN_4) { 
				PC_Display_Message("Task 10 - SMS receive test started",0,"");
				OS_Wait(&GSMModule);			
				GSMprocessMessage(1);
				OS_Signal(&GSMModule);
				PC_Display_Message("Task 10 - SMS receive test executed",0,"");
			}
			OS_EdgeTrigger_Restart(PortF,GPIO_PIN_0);
		}
	}
}

void Task11_BlankTask(void){
	while(1){
		if(startupReady) {
			//do nothing
		}
		else {  // not ready
			//InitApplications();
			//startupReady = True;
		}
	}
	//OS_Wait(&SystemReset);
	//InitDrivers();
	//InitApplications();
}
void Idle_Task(void){
  CountIdle = 0;
  while(1){
		if(startupReady) {
			CountIdle++;
		}
	}
}

int main(void){
	//2
	
	InitDrivers();
	EnableInterrupts();
	InitApplications();
	DisableInterrupts();
	
	OS_Init(80);  // initialize, disable interrupts
	
	Profile_Init();  // enable digital I/O on profile pins
	
	//3
	OS_InitSemaphore(&SemPortF.pin0,0);
	OS_InitSemaphore(&SemPortF.pin4,0);
	OS_InitSemaphore(&SerialMonitor,1);
	OS_InitSemaphore(&SystemReset,1);
	
#if GSM_AVAILABLE	
	OS_InitSemaphore(&GSMModule,1);
#endif
	
	//4	
#if PIR_AVAILABLE
	OS_InitSemaphore(&SemPortC.pin6,0);
	OS_InitSemaphore(&SemPortC.pin7,0);
	OS_EdgeTrigger_Init(PortC,GPIO_PIN_6|GPIO_PIN_7,INT_PRIO_PIN,GPIO_RISING_EDGE,GPIO_PIN_TYPE_STD_WPD);
	OS_InitSemaphore(&Task7Sync,0);
	OS_InitSemaphore(&Task8Sync,0);
#endif

	OS_EdgeTrigger_Init(PortF,GPIO_PIN_0|GPIO_PIN_4,INT_PRIO_PIN,GPIO_FALLING_EDGE,GPIO_PIN_TYPE_STD_WPU);
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
								&Task7_ProcessPIRA,BLANK_TASK_PRIO,
                &Task8_ProcessPIRB,BLANK_TASK_PRIO,
								&Task9_BlankTask ,TASK0_PRIO,
								&Task10_BlankTask ,TASK0_PRIO,
								&Task11_BlankTask, BLANK_TASK_PRIO,
	              &Idle_Task,IDLE_TASK_PRIO);	//Idle task is lowest priority
	//7
	//OS_FIFO_Init(&FifoA);
	//8

  //9
	OS_Launch(SysCtlClockGet()/THREADFREQ); // doesn't return, interrupts enabled in here
  return 0;  // this never executes
}
//EOF
