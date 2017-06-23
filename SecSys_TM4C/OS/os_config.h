// os_config.h - ssOS configuration defines
// ssOS - stupid simple Operating System
// A very simple real time operating system with minimal features.
// For copyright, configuration and usage read readme.txt

#ifndef __OS_CFG_H
#define __OS_CFG_H  1

// *******************************************************************************************************
// ************************************* ssOS Configuration section **************************************
// *******************************************************************************************************
//Uncomment the target define you are using
//Leave other target defines commented!!!
#define TARGET_TM4C
//#define TARGET_MSP432

//If PROFILE_DEBUG is set, specific pins are toggled at every task execution
//Use only for OS task scheduler debugging, since these pins can be used by applications as well
//If that is the case, deactivate the application while debugging the OS
// The following pins were selected to be Profile pins:
// J3.27/PE1 Profile 0
// J3.28/PE2 Profile 1
// J3.29/PE3 Profile 2
// J3.30/PF1 Profile 3
// J2.18/PE0 Profile 4
// J4.36/PC5 Profile 5
// J4.34/PC7 Profile 6
#define PROFILE_DEBUG (0)

//Define the frequency of the scheduler, in version 1.2 only 1000 Hz is supported
#define THREADFREQ 1000   // frequency in Hz

//Define number of threads and number of periodic event threads
#define NUMTHREADS  13  // maximum number of threads
#define NUMPERIODIC NUMTHREADS // number of periodic threads
//for less chance of human configuration error, it's defined to be equal to nr of threads in the OS
//however it will take up more memory at compile time

//Task priority definition: 0 - Highest priorty, 254 - Lowest priority
//Idle_Task must have the lowest priority
#define STARTUP_PRIO (0)
#define TASK0_PRIO (5)
#define TASK1_PRIO (5)
#define TASK2_PRIO (10)
#define TASK3_PRIO (100)
#define TASK4_PRIO (150)
#define TASK5_PRIO (200)
#define TASK6_PRIO (250)
#define BLANK_TASK_PRIO (253)
#define IDLE_TASK_PRIO (254)

//Number of OS embedded periodic tasks, DO NOT modify this if you are not changing the OS.
//This needed for OS to run (i.e. runsleep, runperiodicevents)
//Do not confuse with application periodic tasks
#define NUM_OS_PERIODIC_TASK 2 

//Configure the OS
#define STACKSIZE 100  // number of 32-bit words in stack per thread
#define FSIZE 10  // general FIFO size
#define STARTUP_DELAY 10
#define INT_PRIO_PIN (0)  //HW pin interrupt priority for external HW events
#define INT_PRIO_PERIODIC_EV (1)  //Timer interrupt priority for periodic events
#define INT_PRIO_SLEEP (3)  //Timer interrupt priority for sleep decrementing
#define RUN_PERIODIC_FREQ (1000)  //The frequency the runperiodicevents scheduler is called
#define RUN_SLEEP_FREQ  (1000)  //The frequency the runsleep sleep counter is called

//Configure HW port unlock registers, DO NOT change for TM4C controller
#define GPIO_PORTA_LOCK_R       (*((volatile uint32_t *)0x40004520))
#define GPIO_PORTA_CR_R         (*((volatile uint32_t *)0x40004524))
#define GPIO_PORTB_LOCK_R       (*((volatile uint32_t *)0x40005520))
#define GPIO_PORTB_CR_R         (*((volatile uint32_t *)0x40005524))
#define GPIO_PORTC_LOCK_R       (*((volatile uint32_t *)0x40006520))
#define GPIO_PORTC_CR_R         (*((volatile uint32_t *)0x40006524))
#define GPIO_PORTD_LOCK_R       (*((volatile uint32_t *)0x40007520))
#define GPIO_PORTD_CR_R         (*((volatile uint32_t *)0x40007524))
#define GPIO_PORTE_LOCK_R       (*((volatile uint32_t *)0x40024520))
#define GPIO_PORTE_CR_R         (*((volatile uint32_t *)0x40024524))
#define GPIO_PORTF_LOCK_R       (*((volatile uint32_t *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile uint32_t *)0x40025524))

#if PROFILE_DEBUG		
	#define Toggle0() (Profile_Toggle0())
	#define Toggle1() (Profile_Toggle1())
	#define Toggle2() (Profile_Toggle2())
	#define Toggle3() (Profile_Toggle3())
	#define Toggle4() (Profile_Toggle4())
	#define Toggle5() (Profile_Toggle5())
 	#define Toggle6() (Profile_Toggle6())
#else
	#define Toggle0()
	#define Toggle1()
	#define Toggle2()
	#define Toggle3()
	#define Toggle4()
	#define Toggle5()
	#define Toggle6()
#endif	

#endif
//EOF
