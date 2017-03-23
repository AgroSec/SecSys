Versioning:
-----------------------------
1.0: Initial launch version.
		21.10.2016 - Gaal Alexandru
		Round robin scheduler
		Blocked and sleeping main threads
		Periodic threads / events
		FIFO
		Main thread syncronization
		
1.1: New features added.
		27.11.2016 - Gaal Alexandru
		Priority scheduler implemented (replaced Round robin)
		HW layer added in os_hw.c & os_hw.h
		External event threads added by GPIO interrupts.
		
1.2: Replaced BSP support
		05.01.2017 - Gaal Alexandru
		New clock init
		New timer init & handling
		Usable timers: A and WideA times can be initialized but ISR have to be written.
		Reserved timers 0A and 1A for OS Core functions. Do not use them.
		B and WideB timers can't be used

Copyright & License:
-----------------------------
1) Gaal Alexandru:
This RTOS was developed during the course UTAustinX: UT.RTBN.12.01x Realtime Bluetooth Networks.
Some of the code was copied from the examples mentioned in 2)
You may use, edit, run or distribute this file as long as the copyright notice remains.

2) Reference & Source:
This example accompanies the book
   "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2016

   "Embedded Systems: Real-Time Operating Systems for ARM Cortex-M Microcontrollers",
   ISBN: 978-1466468863, , Jonathan Valvano, copyright (c) 2016
   Programs 4.4 through 4.12, section 4.2

Copyright 2016 by Jonathan W. Valvano, valvano@mail.utexas.edu
You may use, edit, run or distribute this file
as long as the above copyright notice remains
THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
For more information about my classes, my research, and my books, see
http://users.ece.utexas.edu/~valvano/

Configuration instructions:
-----------------------------
1) Include "os_core.h" and "os_hw.h" in your project
2) In os_core.h edit number of threads and specify number of periodic threads: NUMTHREADS & NUMPERIODIC
3) Maximum frequency for periodic threads is 1000Hz.
4) Configure OS_AddThreads so it will take NUMTHREADS main threads. 
   Update function definition and circular list, last member points to first member.


main.c usage example:
-----------------------------
1) The OS implementation in main.c has 8 main threads of which four are external HW event threads and two are periodic event threads.
2) Init the OS with "OS_Init(Clock)", clock is in MHz
3) For the external HW event threads a semaphore must be initialized with the HW port and pin number.
   Ex. Use: "OS_InitSemaphore(&SemPortD.pin6,0);" for portD pin6
   The external HW event threads have to wait on this semaphore with: "OS_Wait(&SemPortF.pin0);"
4) Register / init HW port and pins for external HW interrupt events. 
   Ex. OS_EdgeTrigger_Init(PortD,GPIO_PIN_6|GPIO_PIN_7,0,GPIO_FALLING_EDGE,GPIO_PIN_TYPE_STD_WPU);
   Select type of interrupt desired, pull-up/down. Details are bellow in this file.
5) OS_AddPeriodicEventThread registers the periodic event threads with the desired period in this case 10ms and 20ms.
   Ex. OS_AddPeriodicEventThread(&PerTask[x].semaphore, yyms);
   PerTask[x].semaphore is an already defined semaphore.
   The periodic event threads have to wait on this semaphore with: "OS_Wait(&PerTask[x].semaphore);"
6) OS_AddThreads registers the threads, always make sure to have one idle thread (not blocked and not sleeping)
   More threads are possible, just modify NUMTHREADS in os_core.c and make sure to register all and reconfigure the linked list in OS_AddThreads.
7) Initialize any necessary FIFO with "OS_FIFO_Init(&FifoA);"
   FifoA has to be declared as a global variable of type "fifo_t".
   In this example Task0 is a producer and puts data to Fifo A with "OS_FIFO_Put(&FifoA,Count0);"
   Task1 is a consumer and get data from Fifo A with "Count1 = OS_FIFO_Get(&FifoA);"
8) OS_Launch will launch the OS, use the arguments as in the example.

PS:Threads can be synchronized via two semaphores (ex. Task34Sync and Task43Sync).
   This semaphore has to be declared as a global variable and initialized with value of 0.
   One thread will signal the semaphore and the other thread will wait for that semaphore.
   See version 1.0 of ssOS for implementation example.

Debugging:
-----------------------------
1) By logic analyser / osciloscope:
	The Profile.c and profile.h 3rd party files define debugging pins to measure with scope / logic analyser
	The following pins were selected to be Profile pins:
		J3.27/PE1 Profile 0
		J3.28/PE2 Profile 1
		J3.29/PE3 Profile 2
		J3.30/PF1 Profile 3
		J2.18/PE0 Profile 4
		J4.36/PC5 Profile 5
		J4.34/PC7 Profile 6

2) With the debugger:
	Count0;   // number of times Task0 is called
	Count1;   // number of times Task1 is called
	Count2;   // number of times Task2 is called
	etc...

ssOS configs:
-----------------------------
Edge interrupt level setting:
uint8_t OS_EdgeTrigger_Init(uint8_t port, uint8_t pin, uint8_t priority, uint8_t type)

port:
	#define PortA	(0);
	#define	PortB	(1);
	#define PortC	(2);
	#define	PortD	(3);
	#define PortE	(4);
	#define	PortF	(5);

pin:
	#define	Pin0	(0x01)
	#define Pin1	(0x02)
	#define Pin2	(0x04)
	#define Pin3	(0x08)
	#define Pin4	(0x10)
	#define Pin5	(0x20)
	#define Pin6	(0x40)
	#define	Pin7	(0x80)
	
priority:
	0 - highest
	7 - lowest
	
type:
	#define GPIO_FALLING_EDGE       0x00000000  // Interrupt on falling edge
	#define GPIO_RISING_EDGE        0x00000004  // Interrupt on rising edge
	#define GPIO_BOTH_EDGES         0x00000001  // Interrupt on both edges
	#define GPIO_LOW_LEVEL          0x00000002  // Interrupt on low level
	#define GPIO_HIGH_LEVEL         0x00000006  // Interrupt on high level
	#define GPIO_DISCRETE_INT       0x00010000  // Interrupt for individual pins

resistor:
	#define GPIO_PIN_TYPE_STD       0x00000008  // Push-pull
	#define GPIO_PIN_TYPE_STD_WPU   0x0000000A  // Push-pull with weak pull-up
	#define GPIO_PIN_TYPE_STD_WPD   0x0000000C  // Push-pull with weak pull-down
	#define GPIO_PIN_TYPE_OD        0x00000009  // Open-drain
	#define GPIO_PIN_TYPE_ANALOG    0x00000000  // Analog comparator
	#define GPIO_PIN_TYPE_WAKE_HIGH 0x00000208  // Hibernate wake, high
	#define GPIO_PIN_TYPE_WAKE_LOW  0x00000108  // Hibernate wake, low