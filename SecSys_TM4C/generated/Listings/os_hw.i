#line 1 "OS\\os_hw.c"













 
 
#line 1 "OS\\os_hw.h"








 
#line 1 ".\\inc\\CortexM.h"





#line 18 ".\\inc\\CortexM.h"







void DisableInterrupts(void); 





void EnableInterrupts(void);  






long StartCritical(void);    






void EndCritical(long sr);    







void WaitForInterrupt(void);  

#line 11 "OS\\os_hw.h"
#line 1 "F:\\0_Tools\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"
 






 





#line 25 "F:\\0_Tools\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"



#line 12 "OS\\os_hw.h"
#line 1 "F:\\0_Tools\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "F:\\0_Tools\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "F:\\0_Tools\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "F:\\0_Tools\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "F:\\0_Tools\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "F:\\0_Tools\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 13 "OS\\os_hw.h"
#line 1 "OS\\os_core.h"








 
#line 1 ".\\inc\\CortexM.h"





#line 18 ".\\inc\\CortexM.h"







void DisableInterrupts(void); 





void EnableInterrupts(void);  






long StartCritical(void);    






void EndCritical(long sr);    







void WaitForInterrupt(void);  

#line 11 "OS\\os_core.h"
#line 12 "OS\\os_core.h"
#line 13 "OS\\os_core.h"
#line 1 "OS\\os_hw.h"





#line 91 "OS\\os_hw.h"


#line 14 "OS\\os_core.h"
#line 1 "OS\\os_config.h"





























#line 38 "OS\\os_config.h"


#line 52 "OS\\os_config.h"



#line 15 "OS\\os_core.h"




struct tcb{  
  int32_t *sp;  
  struct tcb *next;  
	int32_t *blocked;  
	int32_t sleep;  
  uint8_t priority;  
};
typedef struct tcb tcbType;

struct ptcb{	
	int32_t semaphore;
	uint32_t period;
	uint32_t counter;
};
typedef struct ptcb ptcbType;

struct fifo_st{
	uint32_t Fifo[10];
	uint32_t LostData;	
	int32_t CurrentSize;
	int32_t Mutex;
	uint8_t PutI;
	uint8_t GetI;
};
typedef struct fifo_st fifo_t;











void OS_Init(uint8_t clock_Mhz);







int OS_AddThreads(void(*thread0)(void), uint32_t p0,
                  void(*thread1)(void), uint32_t p1,
                  





 
									void(*thread7)(void), uint32_t p7,
                  void(*thread8)(void), uint32_t p8,
                  void(*thread9)(void), uint32_t p9);












int OS_AddPeriodicEventThread(int32_t *semaPt, uint32_t period);







void OS_Launch(uint32_t theTimeSlice);






void OS_Suspend(void);






void OS_Sleep(uint32_t sleepTime);






void OS_InitSemaphore(int32_t *semaPt, int32_t value);







void OS_Wait(int32_t *semaPt);







void OS_Signal(int32_t *semaPt);






void OS_FIFO_Init(fifo_t *fifo);







int OS_FIFO_Put(fifo_t *fifo,uint32_t data);







uint32_t OS_FIFO_Get(fifo_t *fifo);





#line 14 "OS\\os_hw.h"
#line 15 "OS\\os_hw.h"


struct port_sema {
	int32_t pin0;
	int32_t pin1;
	int32_t pin2;
	int32_t pin3;
	int32_t pin4;
	int32_t pin5;
	int32_t pin6;
	int32_t pin7;
};
typedef struct port_sema PortSema_t;




 
#line 1 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_ints.h"
















































#line 58 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_ints.h"






#line 94 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_ints.h"
                                            
#line 170 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_ints.h"






#line 244 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_ints.h"
                                            
#line 283 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_ints.h"






#line 318 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_ints.h"






#line 339 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_ints.h"













#line 475 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_ints.h"
















#line 34 "OS\\os_hw.h"
#line 1 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_memmap.h"
















































#line 116 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_memmap.h"
                                            

                                            

                                            
#line 141 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_memmap.h"
                                            

                                            
#line 150 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_memmap.h"

#line 35 "OS\\os_hw.h"
 
#line 1 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/gpio.h"



























































#line 68 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/gpio.h"

















#line 91 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/gpio.h"







#line 105 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/gpio.h"







#line 119 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/gpio.h"







#line 135 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/gpio.h"






extern void GPIODirModeSet(uint32_t ui32Port, uint8_t ui8Pins,
                           uint32_t ui32PinIO);
extern uint32_t GPIODirModeGet(uint32_t ui32Port, uint8_t ui8Pin);
extern void GPIOIntTypeSet(uint32_t ui32Port, uint8_t ui8Pins,
                           uint32_t ui32IntType);
extern uint32_t GPIOIntTypeGet(uint32_t ui32Port, uint8_t ui8Pin);
extern void GPIOPadConfigSet(uint32_t ui32Port, uint8_t ui8Pins,
                             uint32_t ui32Strength, uint32_t ui32PadType);
extern void GPIOPadConfigGet(uint32_t ui32Port, uint8_t ui8Pin,
                             uint32_t *pui32Strength, uint32_t *pui32PadType);
extern void GPIOIntEnable(uint32_t ui32Port, uint32_t ui32IntFlags);
extern void GPIOIntDisable(uint32_t ui32Port, uint32_t ui32IntFlags);
extern uint32_t GPIOIntStatus(uint32_t ui32Port, _Bool bMasked);
extern void GPIOIntClear(uint32_t ui32Port, uint32_t ui32IntFlags);
extern void GPIOIntRegister(uint32_t ui32Port, void (*pfnIntHandler)(void));
extern void GPIOIntUnregister(uint32_t ui32Port);
extern int32_t GPIOPinRead(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinWrite(uint32_t ui32Port, uint8_t ui8Pins, uint8_t ui8Val);
extern void GPIOPinConfigure(uint32_t ui32PinConfig);
extern void GPIOPinTypeADC(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeCAN(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeComparator(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeComparatorOutput(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeEPI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeEthernetLED(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeEthernetMII(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeGPIOInput(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeGPIOOutput(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeGPIOOutputOD(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeI2C(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeI2CSCL(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeLCD(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypePWM(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeQEI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeSSI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeTimer(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeUART(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeUSBAnalog(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeUSBDigital(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeWakeHigh(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeWakeLow(uint32_t ui32Port, uint8_t ui8Pins);
extern uint32_t GPIOPinWakeStatus(uint32_t ui32Port);
extern void GPIODMATriggerEnable(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIODMATriggerDisable(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOADCTriggerEnable(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOADCTriggerDisable(uint32_t ui32Port, uint8_t ui8Pins);










#line 37 "OS\\os_hw.h"
#line 1 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"















































#line 213 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 384 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 555 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 726 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 875 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 1024 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 1250 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 1399 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 1625 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 1774 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 2000 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 2171 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 2342 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 2513 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 2684 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 2833 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 2982 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 3208 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 3357 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 3583 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 3732 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 3958 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 4136 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 4314 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 4492 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 4646 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 4880 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 5034 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 5268 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 5422 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 5656 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 5880 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 6104 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 6288 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 6593 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 6777 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 7082 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 7313 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 7544 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 7733 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 8046 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"









































































#line 8125 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"

#line 8132 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"










#line 8148 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"

#line 8155 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"













































#line 8208 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"

#line 8216 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"

























#line 8548 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 8857 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 9166 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 9483 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 9886 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 10338 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 10749 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 11209 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 11669 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 12041 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 12536 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 12930 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 13455 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 13811 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 14167 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 14671 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 15197 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 15732 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 16267 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 16639 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 17134 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 17528 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 18053 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 18409 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 18765 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 19269 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 19804 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 20378 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"






#line 20952 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/pin_map.h"

#line 38 "OS\\os_hw.h"
#line 1 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/interrupt.h"


































































extern _Bool IntMasterEnable(void);
extern _Bool IntMasterDisable(void);
extern void IntRegister(uint32_t ui32Interrupt, void (*pfnHandler)(void));
extern void IntUnregister(uint32_t ui32Interrupt);
extern void IntPriorityGroupingSet(uint32_t ui32Bits);
extern uint32_t IntPriorityGroupingGet(void);
extern void IntPrioritySet(uint32_t ui32Interrupt,
                           uint8_t ui8Priority);
extern int32_t IntPriorityGet(uint32_t ui32Interrupt);
extern void IntEnable(uint32_t ui32Interrupt);
extern void IntDisable(uint32_t ui32Interrupt);
extern uint32_t IntIsEnabled(uint32_t ui32Interrupt);
extern void IntPendSet(uint32_t ui32Interrupt);
extern void IntPendClear(uint32_t ui32Interrupt);
extern void IntPriorityMaskSet(uint32_t ui32PriorityMask);
extern uint32_t IntPriorityMaskGet(void);
extern void IntTrigger(uint32_t ui32Interrupt);










#line 39 "OS\\os_hw.h"
#line 1 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"










































#line 44 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"
#line 45 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"





















#line 143 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"








#line 158 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"








#line 174 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"







#line 188 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"
                                            





















#line 217 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"







#line 388 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"







#line 465 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"

















#line 489 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"








                                            

                                            











#line 519 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"






#line 538 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"















#line 559 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"


























extern uint32_t SysCtlSRAMSizeGet(void);
extern uint32_t SysCtlFlashSizeGet(void);
extern uint32_t SysCtlFlashSectorSizeGet(void);
extern _Bool SysCtlPeripheralPresent(uint32_t ui32Peripheral);
extern _Bool SysCtlPeripheralReady(uint32_t ui32Peripheral);
extern void SysCtlPeripheralPowerOn(uint32_t ui32Peripheral);
extern void SysCtlPeripheralPowerOff(uint32_t ui32Peripheral);
extern void SysCtlPeripheralReset(uint32_t ui32Peripheral);
extern void SysCtlPeripheralEnable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralDisable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralSleepEnable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralSleepDisable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralDeepSleepEnable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralDeepSleepDisable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralClockGating(_Bool bEnable);
extern void SysCtlIntRegister(void (*pfnHandler)(void));
extern void SysCtlIntUnregister(void);
extern void SysCtlIntEnable(uint32_t ui32Ints);
extern void SysCtlIntDisable(uint32_t ui32Ints);
extern void SysCtlIntClear(uint32_t ui32Ints);
extern uint32_t SysCtlIntStatus(_Bool bMasked);
extern void SysCtlLDOSleepSet(uint32_t ui32Voltage);
extern uint32_t SysCtlLDOSleepGet(void);
extern void SysCtlLDODeepSleepSet(uint32_t ui32Voltage);
extern uint32_t SysCtlLDODeepSleepGet(void);
extern void SysCtlSleepPowerSet(uint32_t ui32Config);
extern void SysCtlDeepSleepPowerSet(uint32_t ui32Config);
extern void SysCtlReset(void);
extern void SysCtlSleep(void);
extern void SysCtlDeepSleep(void);
extern uint32_t SysCtlResetCauseGet(void);
extern void SysCtlResetCauseClear(uint32_t ui32Causes);
extern void SysCtlBrownOutConfigSet(uint32_t ui32Config,
                                    uint32_t ui32Delay);
extern void SysCtlDelay(uint32_t ui32Count);
extern void SysCtlMOSCConfigSet(uint32_t ui32Config);
extern uint32_t SysCtlPIOSCCalibrate(uint32_t ui32Type);
extern void SysCtlClockSet(uint32_t ui32Config);
extern uint32_t SysCtlClockGet(void);
extern void SysCtlDeepSleepClockSet(uint32_t ui32Config);
extern void SysCtlDeepSleepClockConfigSet(uint32_t ui32Div,
                                          uint32_t ui32Config);
extern void SysCtlPWMClockSet(uint32_t ui32Config);
extern uint32_t SysCtlPWMClockGet(void);
extern void SysCtlIOSCVerificationSet(_Bool bEnable);
extern void SysCtlMOSCVerificationSet(_Bool bEnable);
extern void SysCtlPLLVerificationSet(_Bool bEnable);
extern void SysCtlClkVerificationClear(void);
extern void SysCtlGPIOAHBEnable(uint32_t ui32GPIOPeripheral);
extern void SysCtlGPIOAHBDisable(uint32_t ui32GPIOPeripheral);
extern void SysCtlUSBPLLEnable(void);
extern void SysCtlUSBPLLDisable(void);
extern uint32_t SysCtlClockFreqSet(uint32_t ui32Config,
                                   uint32_t ui32SysClock);
extern void SysCtlResetBehaviorSet(uint32_t ui32Behavior);
extern uint32_t SysCtlResetBehaviorGet(void);
extern void SysCtlClockOutConfig(uint32_t ui32Config, uint32_t ui32Div);
extern void SysCtlAltClkConfig(uint32_t ui32Config);
extern uint32_t SysCtlNMIStatus(void);
extern void SysCtlNMIClear(uint32_t ui32Status);
extern void SysCtlVoltageEventConfig(uint32_t ui32Config);
extern uint32_t SysCtlVoltageEventStatus(void);
extern void SysCtlVoltageEventClear(uint32_t ui32Status);










#line 40 "OS\\os_hw.h"
#line 1 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/timer.h"




























































                                            


                                            
#line 86 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/timer.h"
                                             



                                             

                                             

                                             

                                             

                                             

                                             

                                             



                                             

                                             

                                             

                                             

                                             

                                             








#line 136 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/timer.h"

























#line 185 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/timer.h"
















#line 210 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/timer.h"







#line 226 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/timer.h"

















extern void TimerEnable(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerDisable(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerConfigure(uint32_t ui32Base, uint32_t ui32Config);
extern void TimerControlLevel(uint32_t ui32Base, uint32_t ui32Timer,
                              _Bool bInvert);
extern void TimerControlTrigger(uint32_t ui32Base, uint32_t ui32Timer,
                                _Bool bEnable);
extern void TimerControlEvent(uint32_t ui32Base, uint32_t ui32Timer,
                              uint32_t ui32Event);
extern void TimerControlStall(uint32_t ui32Base, uint32_t ui32Timer,
                              _Bool bStall);
extern void TimerControlWaitOnTrigger(uint32_t ui32Base, uint32_t ui32Timer,
                                      _Bool bWait);
extern void TimerRTCEnable(uint32_t ui32Base);
extern void TimerRTCDisable(uint32_t ui32Base);
extern void TimerPrescaleSet(uint32_t ui32Base, uint32_t ui32Timer,
                             uint32_t ui32Value);
extern uint32_t TimerPrescaleGet(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerPrescaleMatchSet(uint32_t ui32Base, uint32_t ui32Timer,
                                  uint32_t ui32Value);
extern uint32_t TimerPrescaleMatchGet(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerLoadSet(uint32_t ui32Base, uint32_t ui32Timer,
                         uint32_t ui32Value);
extern uint32_t TimerLoadGet(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerLoadSet64(uint32_t ui32Base, uint64_t ui64Value);
extern uint64_t TimerLoadGet64(uint32_t ui32Base);
extern uint32_t TimerValueGet(uint32_t ui32Base, uint32_t ui32Timer);
extern uint64_t TimerValueGet64(uint32_t ui32Base);
extern void TimerMatchSet(uint32_t ui32Base, uint32_t ui32Timer,
                          uint32_t ui32Value);
extern uint32_t TimerMatchGet(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerMatchSet64(uint32_t ui32Base, uint64_t ui64Value);
extern uint64_t TimerMatchGet64(uint32_t ui32Base);
extern void TimerIntRegister(uint32_t ui32Base, uint32_t ui32Timer,
                             void (*pfnHandler)(void));
extern void TimerIntUnregister(uint32_t ui32Base, uint32_t ui32Timer);
extern void TimerIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void TimerIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags);
extern uint32_t TimerIntStatus(uint32_t ui32Base, _Bool bMasked);
extern void TimerIntClear(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void TimerSynchronize(uint32_t ui32Base, uint32_t ui32Timers);
extern uint32_t TimerClockSourceGet(uint32_t ui32Base);
extern void TimerClockSourceSet(uint32_t ui32Base, uint32_t ui32Source);
extern uint32_t TimerADCEventGet(uint32_t ui32Base);
extern void TimerADCEventSet(uint32_t ui32Base, uint32_t ui32ADCEvent);
extern uint32_t TimerDMAEventGet(uint32_t ui32Base);
extern void TimerDMAEventSet(uint32_t ui32Base, uint32_t ui32DMAEvent);
extern void TimerUpdateMode(uint32_t ui32Base, uint32_t ui32Timer,
                            uint32_t ui32Config);









#line 41 "OS\\os_hw.h"
#line 1 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/systick.h"


























































extern void SysTickEnable(void);
extern void SysTickDisable(void);
extern void SysTickIntRegister(void (*pfnHandler)(void));
extern void SysTickIntUnregister(void);
extern void SysTickIntEnable(void);
extern void SysTickIntDisable(void);
extern void SysTickPeriodSet(uint32_t ui32Period);
extern uint32_t SysTickPeriodGet(void);
extern uint32_t SysTickValueGet(void);










#line 42 "OS\\os_hw.h"


enum tm4c_ports {
	PortA = 0,
	PortB,
	PortC,
	PortD,
	PortE,
	PortF
};
typedef enum tm4c_ports	ports_t;

enum tm4c_timers {
	Timer0A = 0, 
	Timer1A = 1,
	Timer2A = 2,
	Timer3A = 3,
	Timer4A = 4,
	Timer5A = 5,
	WTimer0A = 10,  
	WTimer1A = 11,
	WTimer2A = 12,
	WTimer3A = 13,
	WTimer4A = 14,
	WTimer5A = 15,
};
typedef enum tm4c_timers	timers_t;



#line 84 "OS\\os_hw.h"

uint8_t OS_EdgeTrigger_Restart(ports_t port, uint8_t pin);
uint8_t OS_EdgeTrigger_Init(ports_t port, uint8_t pin, uint8_t priority, uint8_t type, uint8_t resistor);
uint32_t OS_Clock_Init(uint8_t clock_Mhz);
uint8_t OS_Timer_Init(timers_t timer, uint32_t freqency, uint8_t priority);
void OS_SysTick_Init(uint32_t time);



#line 17 "OS\\os_hw.c"


extern void (*OS_PeriodicTask[2])(void);   




PortSema_t SemPortA;
PortSema_t SemPortB;
PortSema_t SemPortC;
PortSema_t SemPortD;
PortSema_t SemPortE;
PortSema_t SemPortF;

void GPIOPortC_Handler(void){	 
	
  
  
	uint8_t status;	
	status = GPIOIntStatus(0x40006000, 1);
	if(status & 0x00000001) {
		GPIOIntClear(0x40006000,0x00000001); 
		OS_Signal(&SemPortC.pin0);  
		GPIOIntDisable(0x40006000, 0x00000001);  
	}
	if(status & 0x00000002) { GPIOIntClear(0x40006000,0x00000002); OS_Signal(&SemPortC.pin1); GPIOIntDisable(0x40006000, 0x00000002);}
	if(status & 0x00000004) { GPIOIntClear(0x40006000,0x00000004); OS_Signal(&SemPortC.pin2); GPIOIntDisable(0x40006000, 0x00000004);}
	if(status & 0x00000008) {	GPIOIntClear(0x40006000,0x00000008); OS_Signal(&SemPortC.pin3); GPIOIntDisable(0x40006000, 0x00000008);}
	if(status & 0x00000010) { GPIOIntClear(0x40006000,0x00000010); OS_Signal(&SemPortC.pin4); GPIOIntDisable(0x40006000, 0x00000010);}
	if(status & 0x00000020) {	GPIOIntClear(0x40006000,0x00000020); OS_Signal(&SemPortC.pin5); GPIOIntDisable(0x40006000, 0x00000020);}
	if(status & 0x00000040) { GPIOIntClear(0x40006000,0x00000040); OS_Signal(&SemPortC.pin6); GPIOIntDisable(0x40006000, 0x00000040);}
	if(status & 0x00000080) {	GPIOIntClear(0x40006000,0x00000080); OS_Signal(&SemPortC.pin7); GPIOIntDisable(0x40006000, 0x00000080);}
  OS_Suspend();
}


void GPIOPortD_Handler(void){	 
	
  
  
	uint8_t status;	
	status = GPIOIntStatus(0x40007000, 1);
	if(status & 0x00000001) {
		GPIOIntClear(0x40007000,0x00000001); 
		OS_Signal(&SemPortD.pin0);  
		GPIOIntDisable(0x40007000, 0x00000001);  
	}
	if(status & 0x00000002) { GPIOIntClear(0x40007000,0x00000002); OS_Signal(&SemPortD.pin1); GPIOIntDisable(0x40007000, 0x00000002);}
	if(status & 0x00000004) { GPIOIntClear(0x40007000,0x00000004); OS_Signal(&SemPortD.pin2); GPIOIntDisable(0x40007000, 0x00000004);}
	if(status & 0x00000008) {	GPIOIntClear(0x40007000,0x00000008); OS_Signal(&SemPortD.pin3); GPIOIntDisable(0x40007000, 0x00000008);}
	if(status & 0x00000010) { GPIOIntClear(0x40007000,0x00000010); OS_Signal(&SemPortD.pin4); GPIOIntDisable(0x40007000, 0x00000010);}
	if(status & 0x00000020) {	GPIOIntClear(0x40007000,0x00000020); OS_Signal(&SemPortD.pin5); GPIOIntDisable(0x40007000, 0x00000020);}
	if(status & 0x00000040) { GPIOIntClear(0x40007000,0x00000040); OS_Signal(&SemPortD.pin6); GPIOIntDisable(0x40007000, 0x00000040);}
	if(status & 0x00000080) {	GPIOIntClear(0x40007000,0x00000080); OS_Signal(&SemPortD.pin7); GPIOIntDisable(0x40007000, 0x00000080);}
  OS_Suspend();
}

void GPIOPortF_Handler(void){	 
	uint8_t status;	
	status = GPIOIntStatus(0x40025000, 1);
	if(status & 0x00000001) {
		GPIOIntClear(0x40025000,0x00000001); 
		OS_Signal(&SemPortF.pin0);  
		GPIOIntDisable(0x40025000, 0x00000001);  
	}
	if(status & 0x00000002) {	GPIOIntClear(0x40025000,0x00000002); OS_Signal(&SemPortF.pin1); GPIOIntDisable(0x40025000, 0x00000002);}
	if(status & 0x00000004) {	GPIOIntClear(0x40025000,0x00000004); OS_Signal(&SemPortF.pin2); GPIOIntDisable(0x40025000, 0x00000004);}
	if(status & 0x00000008) { GPIOIntClear(0x40025000,0x00000008); OS_Signal(&SemPortF.pin3); GPIOIntDisable(0x40025000, 0x00000008);}
	if(status & 0x00000010) { GPIOIntClear(0x40025000,0x00000010); OS_Signal(&SemPortF.pin4); GPIOIntDisable(0x40025000, 0x00000010);}
  OS_Suspend();
}





uint8_t OS_EdgeTrigger_Init(ports_t port, uint8_t pin, uint8_t priority, uint8_t type, uint8_t resistor){
	switch (port) {
		case PortA:  
			
			(*((volatile uint32_t *)0x40004520)) = 0x4C4F434B;  
			(*((volatile uint32_t *)0x40004524)) |= 0xFF;  
			break;
		case PortB:  
			
			break;
		case PortC:  
			
			SysCtlPeripheralEnable(0xf0000802);
			while(!SysCtlPeripheralReady(0xf0000802));
			if(pin & (0x00000001|0x00000002|0x00000004|0x00000008)){
				(*((volatile uint32_t *)0x40006520)) = 0x4C4F434B; 
			}
			(*((volatile uint32_t *)0x40006524)) |= 0xFF;  
			IntDisable(18);
			GPIOIntDisable(0x40006000,pin);
			GPIOPinTypeGPIOInput(0x40006000, pin);
			GPIOIntTypeSet(0x40006000, pin, type);
			GPIODirModeSet(0x40006000, pin, 0x00000000);
			GPIOPadConfigSet(0x40006000, pin, 0x00000001,resistor);
			GPIOIntEnable(0x40006000, pin);
			IntPrioritySet(18,(priority<<5));
			IntEnable(18);		
			break;
		case PortD:  
			SysCtlPeripheralEnable(0xf0000803);
			while(!SysCtlPeripheralReady(0xf0000803));
			if(pin && 0x00000080) { (*((volatile uint32_t *)0x40007520)) = 0x4C4F434B; } 
			(*((volatile uint32_t *)0x40007524)) |= 0xFF;  
			IntDisable(19);
			GPIOIntDisable(0x40007000,pin);
			GPIOPinTypeGPIOInput(0x40007000, pin);
			GPIOIntTypeSet(0x40007000, pin, type);
			GPIODirModeSet(0x40007000, pin, 0x00000000);
			GPIOPadConfigSet(0x40007000, pin, 0x00000001,resistor);
			GPIOIntEnable(0x40007000, pin);
			IntPrioritySet(19,(priority<<5));
			IntEnable(19);
			break;
		case PortE:  
			break;
		case PortF:  
			SysCtlPeripheralEnable(0xf0000805);	
			while(!SysCtlPeripheralReady(0xf0000805));
			if(pin && 0x00000001) { (*((volatile uint32_t *)0x40025520)) = 0x4C4F434B; } 
			(*((volatile uint32_t *)0x40025524)) |= 0x1F;  
			
			IntDisable(46);  
			GPIOIntDisable(0x40025000,pin);  
			GPIOPinTypeGPIOInput(0x40025000, pin);  
			GPIOIntTypeSet(0x40025000, pin, type);  
			GPIODirModeSet(0x40025000, pin, 0x00000000);  
			GPIOPadConfigSet(0x40025000, pin, 0x00000001,resistor); 
			GPIOIntEnable(0x40025000, pin);  
			IntPrioritySet(46,(priority<<5)); 
			IntEnable(46); 
			break;		
		default:
			return 0;  
	}
	return 1;  
}






uint8_t OS_EdgeTrigger_Restart(ports_t port, uint8_t pin){
	
	
	
	switch (port) {
		case PortA:  
			break;
		case PortB:  
			break;
		case PortC:  
			break;
		case PortD:  
			GPIOIntEnable(0x40007000, pin);  
			IntEnable(19); 
			break;
		case PortE:  
			break;
		case PortF:  
			GPIOIntEnable(0x40025000, pin);  
			IntEnable(46); 
			break;		
		default:
			return 0;  
	}
	return 1;  
}





uint32_t OS_Clock_Init(uint8_t clock_Mhz){
	unsigned long check_freq_hz = 0;
	unsigned long init_freq_hz = 0;	
	switch (clock_Mhz) {
		case 13:  
			SysCtlClockSet(0x07400000 | 0x00000000 | 0x00000540 | 0x00000000);  
			check_freq_hz = 13333333;
			break;
		case 16:  
			SysCtlClockSet(0x07800000 | 0x00000010 | 0x00003800);  
			check_freq_hz = 16000000;
			break;
		case 20:  
			SysCtlClockSet(0x04C00000 | 0x00000000 | 0x00000540 | 0x00000000);
			
			
			
			
			
			check_freq_hz = 20000000;
			break;
		case 40:  
			SysCtlClockSet(0x02400000 | 0x00000000 | 0x00000540 | 0x00000000);  
			check_freq_hz = 40000000;
			break;
		case 45:  
			SysCtlClockSet(0xC2000000 | 0x00000000 | 0x00000540 | 0x00000000);  
			check_freq_hz = 44444444;
			break;
		case 50:  
			SysCtlClockSet(0x01C00000 | 0x00000000 | 0x00000540 | 0x00000000);  
			check_freq_hz = 50000000;
			break;
		case 66:  
			SysCtlClockSet(0x01400000 | 0x00000000 | 0x00000540 | 0x00000000);  
			check_freq_hz = 66666666;
			break;
		case 80:  
			SysCtlClockSet(0xC1000000 | 0x00000000 | 0x00000540 | 0x00000000); 
			check_freq_hz = 80000000;
			init_freq_hz = SysCtlClockGet();
			break;		
		default:
			return 0;  
	}
	
	return (check_freq_hz == init_freq_hz);  
	






























 
}






uint8_t OS_Timer_Init(timers_t timer, uint32_t freqency, uint8_t priority){
	uint32_t reload_value = 0;
  int32_t status; 
  status = StartCritical(); 
	reload_value = ((SysCtlClockGet() / freqency) - 1);
	switch (timer) {
		case Timer0A:
			SysCtlPeripheralEnable(0xf0000400);	
			IntDisable(35);	
			TimerIntDisable(0x40030000,0x00000001);
			TimerDisable(0x40030000, 0x000000ff);	
			TimerClockSourceSet(0x40030000, 0x00000000);
			TimerConfigure(0x40030000, 0x00000022);
			TimerLoadSet(0x40030000, 0x000000ff, reload_value);	
			TimerEnable(0x40030000, 0x000000ff);
			TimerIntEnable(0x40030000,0x00000001);
			IntPrioritySet(35,(priority)<<5);	
			IntEnable(35);	
			break;
		case Timer1A:
			SysCtlPeripheralEnable(0xf0000401);	
			IntDisable(37);	
			TimerIntDisable(0x40031000,0x00000001);
			TimerDisable(0x40031000, 0x000000ff);	
			TimerClockSourceSet(0x40031000, 0x00000000);
			TimerConfigure(0x40031000, 0x00000022);
			TimerLoadSet(0x40031000, 0x000000ff, reload_value);	
			TimerEnable(0x40031000, 0x000000ff);
			TimerIntEnable(0x40031000,0x00000001);
			IntPrioritySet(37,(priority)<<5);	
			IntEnable(37);	
			break;
		case Timer2A:
			SysCtlPeripheralEnable(0xf0000402);	
			IntDisable(39);	
			TimerIntDisable(0x40032000,0x00000001);
			TimerDisable(0x40032000, 0x000000ff);	
			TimerClockSourceSet(0x40032000, 0x00000000);
			TimerConfigure(0x40032000, 0x00000022);
			TimerLoadSet(0x40032000, 0x000000ff, reload_value);	
			TimerEnable(0x40032000, 0x000000ff);
			TimerIntEnable(0x40032000,0x00000001);
			IntPrioritySet(39,(priority)<<5);	
			IntEnable(39);	
			break;
		case Timer3A:
			SysCtlPeripheralEnable(0xf0000403);	
			IntDisable(51);	
			TimerIntDisable(0x40033000,0x00000001);
			TimerDisable(0x40033000, 0x000000ff);	
			TimerClockSourceSet(0x40033000, 0x00000000);
			TimerConfigure(0x40033000, 0x00000022);
			TimerLoadSet(0x40033000, 0x000000ff, reload_value);	
			TimerEnable(0x40033000, 0x000000ff);
			TimerIntEnable(0x40033000,0x00000001);
			IntPrioritySet(51,(priority)<<5);	
			IntEnable(51);	
			break;
		case Timer4A:
			SysCtlPeripheralEnable(0xf0000404);	
			IntDisable(86);	
			TimerIntDisable(0x40034000,0x00000001);
			TimerDisable(0x40034000, 0x000000ff);	
			TimerClockSourceSet(0x40034000, 0x00000000);
			TimerConfigure(0x40034000, 0x00000022);
			TimerLoadSet(0x40034000, 0x000000ff, reload_value);	
			TimerEnable(0x40034000, 0x000000ff);
			TimerIntEnable(0x40034000,0x00000001);
			IntPrioritySet(86,(priority)<<5);	
			IntEnable(86);	
			break;
		case Timer5A:
			SysCtlPeripheralEnable(0xf0000405);	
			IntDisable(108);	
			TimerIntDisable(0x40035000,0x00000001);
			TimerDisable(0x40035000, 0x000000ff);	
			TimerClockSourceSet(0x40035000, 0x00000000);
			TimerConfigure(0x40035000, 0x00000022);
			TimerLoadSet(0x40035000, 0x000000ff, reload_value);	
			TimerEnable(0x40035000, 0x000000ff);
			TimerIntEnable(0x40035000,0x00000001);
			IntPrioritySet(108,(priority)<<5);	
			IntEnable(108);	
			break;
		case WTimer0A:  
			SysCtlPeripheralEnable(0xf0005c00);  
			IntDisable(110);  
			TimerIntDisable(0x40036000,0x00000001);
			TimerDisable(0x40036000, 0x000000ff);
			TimerClockSourceSet(0x40036000, 0x00000000);
			TimerConfigure(0x40036000, 0x00000022);
			TimerLoadSet(0x40036000, 0x000000ff, reload_value);	
			TimerEnable(0x40036000, 0x000000ff);
			TimerIntEnable(0x40036000,0x00000001);
			IntPrioritySet(110,(priority)<<5);  
			IntEnable(110);	
			break;
		case WTimer1A:
			SysCtlPeripheralEnable(0xf0005c01);  
			IntDisable(112);  
			TimerIntDisable(0x40037000,0x00000001);
			TimerDisable(0x40037000, 0x000000ff);
			TimerClockSourceSet(0x40037000, 0x00000000);
			TimerConfigure(0x40037000, 0x00000022);
			TimerLoadSet(0x40037000, 0x000000ff, reload_value);	
			TimerEnable(0x40037000, 0x000000ff);
			TimerIntEnable(0x40037000,0x00000001);
			IntPrioritySet(112,(priority)<<5);  
			IntEnable(112);	
			break;
		case WTimer2A:
			SysCtlPeripheralEnable(0xf0005c02);  
			IntDisable(114);  
			TimerIntDisable(0x4004C000,0x00000001);
			TimerDisable(0x4004C000, 0x000000ff);
			TimerClockSourceSet(0x4004C000, 0x00000000);
			TimerConfigure(0x4004C000, 0x00000022);
			TimerLoadSet(0x4004C000, 0x000000ff, reload_value);	
			TimerEnable(0x4004C000, 0x000000ff);
			TimerIntEnable(0x4004C000,0x00000001);
			IntPrioritySet(114,(priority)<<5);  
			IntEnable(114);	
			break;
		case WTimer3A:
			SysCtlPeripheralEnable(0xf0005c03);  
			IntDisable(116);  
			TimerIntDisable(0x4004D000,0x00000001);
			TimerDisable(0x4004D000, 0x000000ff);
			TimerClockSourceSet(0x4004D000, 0x00000000);
			TimerConfigure(0x4004D000, 0x00000022);
			TimerLoadSet(0x4004D000, 0x000000ff, reload_value);	
			TimerEnable(0x4004D000, 0x000000ff);
			TimerIntEnable(0x4004D000,0x00000001);
			IntPrioritySet(116,(priority)<<5);  
			IntEnable(116);	
			break;
		case WTimer4A:
			SysCtlPeripheralEnable(0xf0005c04);  
			IntDisable(118);  
			TimerIntDisable(0x4004E000,0x00000001);
			TimerDisable(0x4004E000, 0x000000ff);
			TimerClockSourceSet(0x4004E000, 0x00000000);
			TimerConfigure(0x4004E000, 0x00000022);
			TimerLoadSet(0x4004E000, 0x000000ff, reload_value);	
			TimerEnable(0x4004E000, 0x000000ff);
			TimerIntEnable(0x4004E000,0x00000001);
			IntPrioritySet(118,(priority)<<5);  
			IntEnable(118);	
			break;
		case WTimer5A:
			SysCtlPeripheralEnable(0xf0005c05);  
			IntDisable(120);  
			TimerIntDisable(0x4004F000,0x00000001);
			TimerDisable(0x4004F000, 0x000000ff);
			TimerClockSourceSet(0x4004F000, 0x00000000);
			TimerConfigure(0x4004F000, 0x00000022);
			TimerLoadSet(0x4004F000, 0x000000ff, reload_value);	
			TimerEnable(0x4004F000, 0x000000ff);
			TimerIntEnable(0x4004F000,0x00000001);
			IntPrioritySet(120,(priority)<<5);  
			IntEnable(120);	
			break;
		default:
			return 0;  
	}
	EndCritical(status);
	return 1;  
}

void Timer0A_Handler(void)		
{
	
	
}

void Timer1A_Handler(void)		
{
	
	
}

void WideTimer0A_Handler(void)		
{
	TimerIntClear(0x40036000, 0x000000ff);
	
	(*OS_PeriodicTask[0])();
}

void WideTimer1A_Handler(void)		
{
	TimerIntClear(0x40037000, 0x000000ff);
	
	(*OS_PeriodicTask[1])();
}

void OS_SysTick_Init(uint32_t time)
{
	








 
}








