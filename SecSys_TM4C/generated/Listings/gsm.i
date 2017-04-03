#line 1 "modules\\GSM\\GSM.c"
 
#line 1 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"










































#line 1 "F:\\0_Tools\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"
 






 





#line 25 "F:\\0_Tools\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"



#line 44 "..\\..\\TivaWare_C_Series-2.1.1.71\\driverlib/sysctl.h"
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










#line 3 "modules\\GSM\\GSM.c"
 
#line 1 "..\\SecSys_TM4C\\SecSys_Config.h"










#line 17 "..\\SecSys_TM4C\\SecSys_Config.h"
















#line 5 "modules\\GSM\\GSM.c"
 
#line 1 "modules\\GSM\\GSM.h"



 
#line 6 "modules\\GSM\\GSM.h"
#line 7 "modules\\GSM\\GSM.h"
#line 1 "..\\SecSys_TM4C\\custom_types.h"




 





 
#line 18 "..\\SecSys_TM4C\\custom_types.h"

 
typedef struct Xyz
{
	char z;
	char y;
	char x;
} Xyz_st;

typedef enum SMS_Message
{
	PIR_A = 0,
	PIR_B,
	Wire_1_Pull,
	Wire_1_Cut,
	Wire_2_Pull,
	Wire_2_Cut,
	Wire_3_Pull,
	Wire_3_Cut,
	Status,
	Wrong_Command
} SMS_Message_en;




#line 8 "modules\\GSM\\GSM.h"

void PowerOnGSM(void);
void SendSMS(SMS_Message_en message);
unsigned char ReceiveSMS(void);
void ReadSMS(void);



#line 7 "modules\\GSM\\GSM.c"
 
#line 1 ".\\drivers\\gpio_handler\\gpio_handler.h"




 
#line 1 ".\\OS\\os_hw.h"








 
#line 1 ".\\inc\\CortexM.h"





#line 18 ".\\inc\\CortexM.h"







void DisableInterrupts(void); 





void EnableInterrupts(void);  






long StartCritical(void);    






void EndCritical(long sr);    







void WaitForInterrupt(void);  

#line 11 ".\\OS\\os_hw.h"
#line 12 ".\\OS\\os_hw.h"
#line 13 ".\\OS\\os_hw.h"
#line 1 ".\\OS\\os_core.h"








 
#line 1 ".\\inc\\CortexM.h"





#line 18 ".\\inc\\CortexM.h"







void DisableInterrupts(void); 





void EnableInterrupts(void);  






long StartCritical(void);    






void EndCritical(long sr);    







void WaitForInterrupt(void);  

#line 11 ".\\OS\\os_core.h"
#line 12 ".\\OS\\os_core.h"
#line 13 ".\\OS\\os_core.h"
#line 1 ".\\OS\\os_hw.h"





#line 91 ".\\OS\\os_hw.h"


#line 14 ".\\OS\\os_core.h"
#line 1 ".\\OS\\os_config.h"








































#line 51 ".\\OS\\os_config.h"







#line 66 ".\\OS\\os_config.h"


#line 80 ".\\OS\\os_config.h"

#line 98 ".\\OS\\os_config.h"



#line 15 ".\\OS\\os_core.h"




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
									void(*thread2)(void), uint32_t p2,
									void(*thread3)(void), uint32_t p3,
                  void(*thread4)(void), uint32_t p4,
                  void(*thread5)(void), uint32_t p5,
                  void(*thread6)(void), uint32_t p6,
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





#line 14 ".\\OS\\os_hw.h"
#line 15 ".\\OS\\os_hw.h"


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
















#line 34 ".\\OS\\os_hw.h"
#line 1 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_memmap.h"
















































#line 116 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_memmap.h"
                                            

                                            

                                            
#line 141 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_memmap.h"
                                            

                                            
#line 150 "..\\..\\TivaWare_C_Series-2.1.1.71\\inc/hw_memmap.h"

#line 35 ".\\OS\\os_hw.h"
 
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










#line 37 ".\\OS\\os_hw.h"
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

#line 38 ".\\OS\\os_hw.h"
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










#line 39 ".\\OS\\os_hw.h"
#line 40 ".\\OS\\os_hw.h"
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









#line 41 ".\\OS\\os_hw.h"
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










#line 42 ".\\OS\\os_hw.h"


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



#line 84 ".\\OS\\os_hw.h"

uint8_t OS_EdgeTrigger_Restart(ports_t port, uint8_t pin);
uint8_t OS_EdgeTrigger_Init(ports_t port, uint8_t pin, uint8_t priority, uint8_t type, uint8_t resistor);
uint32_t OS_Clock_Init(uint8_t clock_Mhz);
uint8_t OS_Timer_Init(timers_t timer, uint32_t freqency, uint8_t priority);
void OS_SysTick_Init(uint32_t time);



#line 7 ".\\drivers\\gpio_handler\\gpio_handler.h"

 
uint8_t GPIO_InitPortOutput(ports_t port, uint8_t pin);
uint8_t GPIO_SetPin(ports_t port, uint8_t pin, uint8_t status);



#line 9 "modules\\GSM\\GSM.c"
#line 1 ".\\drivers\\uart_handler\\uart_handler.h"



 
#line 6 ".\\drivers\\uart_handler\\uart_handler.h"
#line 7 ".\\drivers\\uart_handler\\uart_handler.h"

 



#line 19 ".\\drivers\\uart_handler\\uart_handler.h"



 

void UART0_Init(void);
void UART0_SendChar(uint8_t data);
void UART0_SendString(uint8_t *pt);
void UART0_SendUDecimal(uint32_t n);
void UART0_SendUHex(uint32_t number);
void UART0_SendNewLine(void);
uint8_t UART0_GetChar(void);
void UART0_GetString(uint8_t *bufPt, uint16_t max);
uint32_t UART0_GetUDecimal(void);
uint32_t UART0_GetUHex(void);


void UART2_Init(void);
void UART2_SendChar(uint8_t data);
void UART2_SendString(uint8_t *pt);
void UART2_SendUDecimal(uint32_t n);
void UART2_SendUHex(uint32_t number);
void UART2_SendNewLine(void);
uint8_t UART2_GetChar(void);
void UART2_GetString(uint8_t *bufPt, uint16_t max);
uint32_t UART2_GetUDecimal(void);
uint32_t UART2_GetUHex(void);


#line 10 "modules\\GSM\\GSM.c"

 
extern uint32_t Count0_PIRA;  
extern uint32_t Count1_PIRB;  
extern uint32_t Count7_Blank; 
extern uint32_t Count8_Blank; 
 

 
void PowerOnGSM(void){





}

void SendSMS(SMS_Message_en message){
	UART2_SendString("AT+CMGS=\"0751538300\"");  
	
	UART2_SendChar(0x0D);
	
	SysCtlDelay((((SysCtlClockGet() / 1000) * (100)) - 1)); 
  switch (message) {
		case PIR_A:
			UART2_SendString("PIR A Triggered ");  
			
			
			break;
		case PIR_B:
			UART2_SendString("PIR B Triggered ");
			
			
			break;
		case Wire_1_Pull:
			UART2_SendString("Wire 1 Pulled");
			break;
		case Wire_1_Cut:
			UART2_SendString("Wire 1 Cut");
			break;
		case Wire_2_Pull:
			UART2_SendString("Wire 2 Pulled");
			break;
		case Wire_2_Cut:
			UART2_SendString("Wire 2 Cut");
			break;
		case Wire_3_Pull:
			UART2_SendString("Wire 3 Pulled");
			break;
		case Wire_3_Cut:
			UART2_SendString("Wire 3 Cut");
			break;
		case Status: 
			
			UART2_SendString("Status:");
			UART2_SendNewLine();
			UART2_SendUDecimal(Count7_Blank);
			UART2_SendString(" seconds");
			UART2_SendNewLine();
			UART2_SendUDecimal(Count8_Blank*10);
			UART2_SendString(" minutes");
			
			
			
			
			
			break;
		case Wrong_Command:
			
			UART2_SendString("Wrong Command. (1)Deactivate Security. (2)Deactivate Alarm. (3)Trigger Alarm. (4)Get Status");
			break;
		default:
			UART2_SendString("Something misterious happened");
	}
	UART2_SendChar(0x1A);  
  
	UART0_SendNewLine();
	UART0_SendString("SMS sent with message ID: ");
	UART0_SendChar((uint8_t)message+'0');
	UART0_SendNewLine();	
	
}



unsigned char ReceiveSMS(void){





















































	return 0;
}

void ReadSMS(void){
































}
