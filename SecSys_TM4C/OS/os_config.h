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

//Define the frequency of the scheduler, in version 1.2 only 1000 Hz is supported
#define THREADFREQ 1000   // frequency in Hz

//Define number of threads and number of periodic event threads
#define NUMTHREADS  4  // maximum number of threads
#define NUMPERIODIC 2 // maximum number of periodic threads

//Number of OS embedded periodic tasks, DO NOT modify this if you are not changing the OS.
//This needed for OS to run (i.e. runsleep, runperiodicevents)
//Do not confuse with application periodic tasks
#define NUM_OS_PERIODIC_TASK 2 

//Configure the OS
#define STACKSIZE   100      // number of 32-bit words in stack per thread
#define FSIZE 10  // general FIFO size
#define STARTUP_DELAY 10
#define INT_PRIO_PIN (0)  //HW pin interrupt priority for external HW events
#define INT_PRIO_PERIODIC_EV (1)  //Timer interrupt priority for periodic events
#define INT_PRIO_SLEEP (3)  //Timer interrupt priority for sleep decrementing
#define RUN_PERIODIC_FREQ (1000)  //The frequency the runperiodicevents scheduler is called
#define RUN_SLEEP_FREQ  (1000)  //The frequency the runsleep sleep counter is called

//Configure HW port unlock registers, DO NOY change for TM4C controller
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

#endif
//EOF
