#line 1 "RTE\\Device\\TM4C123GH6PM\\system_TM4C123.c"
 








 

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






 
#line 13 "RTE\\Device\\TM4C123GH6PM\\system_TM4C123.c"
#line 1 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\TM4C123.h"
 








 




#line 1 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\TM4C123GH6PM.h"

 





























 





 



 









 

typedef enum {
 
  Reset_IRQn                    = -15,               
  NonMaskableInt_IRQn           = -14,               
  HardFault_IRQn                = -13,               
  MemoryManagement_IRQn         = -12,              
 
  BusFault_IRQn                 = -11,              
 
  UsageFault_IRQn               = -10,               
  SVCall_IRQn                   =  -5,               
  DebugMonitor_IRQn             =  -4,               
  PendSV_IRQn                   =  -2,               
  SysTick_IRQn                  =  -1,               
 
  GPIOA_IRQn                    =   0,               
  GPIOB_IRQn                    =   1,               
  GPIOC_IRQn                    =   2,               
  GPIOD_IRQn                    =   3,               
  GPIOE_IRQn                    =   4,               
  UART0_IRQn                    =   5,               
  UART1_IRQn                    =   6,               
  SSI0_IRQn                     =   7,               
  I2C0_IRQn                     =   8,               
  PWM0_FAULT_IRQn               =   9,               
  PWM0_0_IRQn                   =  10,               
  PWM0_1_IRQn                   =  11,               
  PWM0_2_IRQn                   =  12,               
  QEI0_IRQn                     =  13,               
  ADC0SS0_IRQn                  =  14,               
  ADC0SS1_IRQn                  =  15,               
  ADC0SS2_IRQn                  =  16,               
  ADC0SS3_IRQn                  =  17,               
  WATCHDOG0_IRQn                =  18,               
  TIMER0A_IRQn                  =  19,               
  TIMER0B_IRQn                  =  20,               
  TIMER1A_IRQn                  =  21,               
  TIMER1B_IRQn                  =  22,               
  TIMER2A_IRQn                  =  23,               
  TIMER2B_IRQn                  =  24,               
  COMP0_IRQn                    =  25,               
  COMP1_IRQn                    =  26,               
  SYSCTL_IRQn                   =  28,               
  FLASH_CTRL_IRQn               =  29,               
  GPIOF_IRQn                    =  30,               
  UART2_IRQn                    =  33,               
  SSI1_IRQn                     =  34,               
  TIMER3A_IRQn                  =  35,               
  TIMER3B_IRQn                  =  36,               
  I2C1_IRQn                     =  37,               
  QEI1_IRQn                     =  38,               
  CAN0_IRQn                     =  39,               
  CAN1_IRQn                     =  40,               
  HIB_IRQn                      =  43,               
  USB0_IRQn                     =  44,               
  PWM0_3_IRQn                   =  45,               
  UDMA_IRQn                     =  46,               
  UDMAERR_IRQn                  =  47,               
  ADC1SS0_IRQn                  =  48,               
  ADC1SS1_IRQn                  =  49,               
  ADC1SS2_IRQn                  =  50,               
  ADC1SS3_IRQn                  =  51,               
  SSI2_IRQn                     =  57,               
  SSI3_IRQn                     =  58,               
  UART3_IRQn                    =  59,               
  UART4_IRQn                    =  60,               
  UART5_IRQn                    =  61,               
  UART6_IRQn                    =  62,               
  UART7_IRQn                    =  63,               
  I2C2_IRQn                     =  68,               
  I2C3_IRQn                     =  69,               
  TIMER4A_IRQn                  =  70,               
  TIMER4B_IRQn                  =  71,               
  TIMER5A_IRQn                  =  92,               
  TIMER5B_IRQn                  =  93,               
  WTIMER0A_IRQn                 =  94,               
  WTIMER0B_IRQn                 =  95,               
  WTIMER1A_IRQn                 =  96,               
  WTIMER1B_IRQn                 =  97,               
  WTIMER2A_IRQn                 =  98,               
  WTIMER2B_IRQn                 =  99,               
  WTIMER3A_IRQn                 = 100,               
  WTIMER3B_IRQn                 = 101,               
  WTIMER4A_IRQn                 = 102,               
  WTIMER4B_IRQn                 = 103,               
  WTIMER5A_IRQn                 = 104,               
  WTIMER5B_IRQn                 = 105,               
  SYSEXC_IRQn                   = 106,               
  PWM1_0_IRQn                   = 134,               
  PWM1_1_IRQn                   = 135,               
  PWM1_2_IRQn                   = 136,               
  PWM1_3_IRQn                   = 137,               
  PWM1_FAULT_IRQn               = 138                
} IRQn_Type;




 


 
 
 

 





   

#line 1 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\core_cm4.h"
 




 
















 










#line 35 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\core_cm4.h"

















 




 



 

 









 
#line 85 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\core_cm4.h"

#line 159 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\core_cm4.h"

#line 1 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\cmsis_compiler.h"
 




 
















 




#line 29 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\cmsis_compiler.h"



 
#line 1 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\cmsis_armcc.h"
 




 
















 









 












   
   


 
#line 78 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\cmsis_armcc.h"


 



 





 
 






 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}









 







 







 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}






 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xFFU);
}







 
static __inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  register uint32_t __regBasePriMax      __asm("basepri_max");
  __regBasePriMax = (basePri & 0xFFU);
}






 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}






 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32_t)1U);
}











 
static __inline uint32_t __get_FPSCR(void)
{





   return(0U);

}






 
static __inline void __set_FPSCR(uint32_t fpscr)
{





}





 


 



 




 






 







 






 








 










 










 











 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}








 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 
#line 510 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\cmsis_armcc.h"







 











 












 












 














 














 














 










 









 









 









 

__attribute__((section(".rrx_text"))) static __inline __asm uint32_t __RRX(uint32_t value)
{
  rrx r0, r0
  bx lr
}








 








 








 








 








 








 





   


 



 



#line 777 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\cmsis_armcc.h"











 


#line 35 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\cmsis_compiler.h"




 
#line 208 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\cmsis_compiler.h"




#line 161 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\core_cm4.h"

















 
#line 205 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\core_cm4.h"

 






 
#line 221 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\core_cm4.h"

 




 













 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:16;               
    uint32_t GE:4;                        
    uint32_t _reserved1:7;                
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 





















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:1;                
    uint32_t ICI_IT_1:6;                  
    uint32_t GE:4;                        
    uint32_t _reserved1:4;                
    uint32_t T:1;                         
    uint32_t ICI_IT_2:2;                  
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 

































 
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                     
    uint32_t SPSEL:1;                     
    uint32_t FPCA:1;                      
    uint32_t _reserved0:29;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 









 







 



 
typedef struct
{
  volatile uint32_t ISER[8U];                
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];                
        uint32_t RSERVED1[24U];
  volatile uint32_t ISPR[8U];                
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];                
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];                
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];                
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                    
}  NVIC_Type;

 



 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
  volatile uint32_t VTOR;                    
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
  volatile uint8_t  SHP[12U];                
  volatile uint32_t SHCSR;                   
  volatile uint32_t CFSR;                    
  volatile uint32_t HFSR;                    
  volatile uint32_t DFSR;                    
  volatile uint32_t MMFAR;                   
  volatile uint32_t BFAR;                    
  volatile uint32_t AFSR;                    
  volatile const  uint32_t PFR[2U];                 
  volatile const  uint32_t DFR;                     
  volatile const  uint32_t ADR;                     
  volatile const  uint32_t MMFR[4U];                
  volatile const  uint32_t ISAR[5U];                
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;                   
} SCB_Type;

 















 






























 



 





















 









 


















 










































 









 


















 





















 


















 









 















 







 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const  uint32_t ICTR;                    
  volatile uint32_t ACTLR;                   
} SCnSCB_Type;

 



 















 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 







 



 
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                  
    volatile  uint16_t   u16;                 
    volatile  uint32_t   u32;                 
  }  PORT [32U];                          
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;                     
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;                     
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;                     
        uint32_t RESERVED3[29U];
  volatile  uint32_t IWR;                     
  volatile const  uint32_t IRR;                     
  volatile uint32_t IMCR;                    
        uint32_t RESERVED4[43U];
  volatile  uint32_t LAR;                     
  volatile const  uint32_t LSR;                     
        uint32_t RESERVED5[6U];
  volatile const  uint32_t PID4;                    
  volatile const  uint32_t PID5;                    
  volatile const  uint32_t PID6;                    
  volatile const  uint32_t PID7;                    
  volatile const  uint32_t PID0;                    
  volatile const  uint32_t PID1;                    
  volatile const  uint32_t PID2;                    
  volatile const  uint32_t PID3;                    
  volatile const  uint32_t CID0;                    
  volatile const  uint32_t CID1;                    
  volatile const  uint32_t CID2;                    
  volatile const  uint32_t CID3;                    
} ITM_Type;

 



 



























 



 



 



 









   







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t CYCCNT;                  
  volatile uint32_t CPICNT;                  
  volatile uint32_t EXCCNT;                  
  volatile uint32_t SLEEPCNT;                
  volatile uint32_t LSUCNT;                  
  volatile uint32_t FOLDCNT;                 
  volatile const  uint32_t PCSR;                    
  volatile uint32_t COMP0;                   
  volatile uint32_t MASK0;                   
  volatile uint32_t FUNCTION0;               
        uint32_t RESERVED0[1U];
  volatile uint32_t COMP1;                   
  volatile uint32_t MASK1;                   
  volatile uint32_t FUNCTION1;               
        uint32_t RESERVED1[1U];
  volatile uint32_t COMP2;                   
  volatile uint32_t MASK2;                   
  volatile uint32_t FUNCTION2;               
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP3;                   
  volatile uint32_t MASK3;                   
  volatile uint32_t FUNCTION3;               
} DWT_Type;

 






















































 



 



 



 



 



 



 



























   







 



 
typedef struct
{
  volatile uint32_t SSPSR;                   
  volatile uint32_t CSPSR;                   
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;                    
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;                    
        uint32_t RESERVED2[131U];
  volatile const  uint32_t FFSR;                    
  volatile uint32_t FFCR;                    
  volatile const  uint32_t FSCR;                    
        uint32_t RESERVED3[759U];
  volatile const  uint32_t TRIGGER;                 
  volatile const  uint32_t FIFO0;                   
  volatile const  uint32_t ITATBCTR2;               
        uint32_t RESERVED4[1U];
  volatile const  uint32_t ITATBCTR0;               
  volatile const  uint32_t FIFO1;                   
  volatile uint32_t ITCTRL;                  
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;                
  volatile uint32_t CLAIMCLR;                
        uint32_t RESERVED7[8U];
  volatile const  uint32_t DEVID;                   
  volatile const  uint32_t DEVTYPE;                 
} TPI_Type;

 



 



 












 






 



 





















 



 





















 



 



 


















 






   








 



 
typedef struct
{
  volatile const  uint32_t TYPE;                    
  volatile uint32_t CTRL;                    
  volatile uint32_t RNR;                     
  volatile uint32_t RBAR;                    
  volatile uint32_t RASR;                    
  volatile uint32_t RBAR_A1;                 
  volatile uint32_t RASR_A1;                 
  volatile uint32_t RBAR_A2;                 
  volatile uint32_t RASR_A2;                 
  volatile uint32_t RBAR_A3;                 
  volatile uint32_t RASR_A3;                 
} MPU_Type;

 









 









 



 









 






























 








 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile uint32_t FPCCR;                   
  volatile uint32_t FPCAR;                   
  volatile uint32_t FPDSCR;                  
  volatile const  uint32_t MVFR0;                   
  volatile const  uint32_t MVFR1;                   
} FPU_Type;

 



























 



 












 
























 












 







 



 
typedef struct
{
  volatile uint32_t DHCSR;                   
  volatile  uint32_t DCRSR;                   
  volatile uint32_t DCRDR;                   
  volatile uint32_t DEMCR;                   
} CoreDebug_Type;

 




































 






 







































 







 






 







 


 







 

 
#line 1552 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\core_cm4.h"

#line 1561 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\core_cm4.h"









 










 


 



 





 

#line 1609 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0-Beta12\\CMSIS\\Include\\core_cm4.h"


















 
static __inline void __NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);              

  reg_value  =  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;                                                    
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));  
  reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U)                      );               
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR =  reg_value;
}






 
static __inline uint32_t __NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}







 
static __inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}







 
static __inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetActive(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}










 
static __inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               = (uint8_t)((priority << (8U - 3)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 3)) & (uint32_t)0xFFUL);
  }
}










 
static __inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               >> (8U - 3)));
  }
  else
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] >> (8U - 3)));
  }
}












 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(3)) ? (uint32_t)(3) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(3)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(3));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
         );
}












 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(3)) ? (uint32_t)(3) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(3)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(3));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority     = (Priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}










 
static __inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
    uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
    vectors[(int32_t)IRQn + 16] = vector;
}









 
static __inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
    uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
    return vectors[(int32_t)IRQn + 16];
}





 
static __inline void NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = (uint32_t)((0x5FAUL << 16U)    |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U)    );          
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 


 





 








 
static __inline uint32_t SCB_GetFPUType(void)
{
  uint32_t mvfr0;

  mvfr0 = ((FPU_Type *) ((0xE000E000UL) + 0x0F30UL) )->MVFR0;
  if      ((mvfr0 & ((0xFUL << 4U) | (0xFUL << 8U))) == 0x020U)
  {
    return 1U;            
  }
  else
  {
    return 0U;            
  }
}


 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 3) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 



 





 

extern volatile int32_t ITM_RxBuffer;                               










 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&       
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL               ) != 0UL)   )      
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __nop();
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}







 
static __inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;                            

  if (ITM_RxBuffer != ((int32_t)0x5AA55AA5U))
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = ((int32_t)0x5AA55AA5U);        
  }

  return (ch);
}







 
static __inline int32_t ITM_CheckChar (void)
{

  if (ITM_RxBuffer == ((int32_t)0x5AA55AA5U))
  {
    return (0);                               
  }
  else
  {
    return (1);                               
  }
}

 










#line 168 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\TM4C123GH6PM.h"
#line 1 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\system_TM4C123.h"
 





















 









#line 34 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\system_TM4C123.h"

extern uint32_t SystemCoreClock;      










 
extern void SystemInit (void);









 
extern void SystemCoreClockUpdate (void);





#line 169 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\TM4C123GH6PM.h"


 
 
 




 


 

  #pragma push
  #pragma anon_unions
#line 196 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\TM4C123GH6PM.h"



 
 
 




 

typedef struct {                                     
  volatile uint32_t  LOAD;                               
  volatile uint32_t  VALUE;                              
  volatile uint32_t  CTL;                                
  volatile  uint32_t  ICR;                                
  volatile uint32_t  RIS;                                
  volatile uint32_t  MIS;                                
  volatile const  uint32_t  RESERVED[256];
  volatile uint32_t  TEST;                               
  volatile const  uint32_t  RESERVED1[505];
  volatile uint32_t  LOCK;                               
} WATCHDOG0_Type;


 
 
 




 

typedef struct {                                     
  volatile const  uint32_t  RESERVED[255];
  volatile uint32_t  DATA;                               
  volatile uint32_t  DIR;                                
  volatile uint32_t  IS;                                 
  volatile uint32_t  IBE;                                
  volatile uint32_t  IEV;                                
  volatile uint32_t  IM;                                 
  volatile uint32_t  RIS;                                
  volatile uint32_t  MIS;                                
  volatile  uint32_t  ICR;                                
  volatile uint32_t  AFSEL;                              
  volatile const  uint32_t  RESERVED1[55];
  volatile uint32_t  DR2R;                               
  volatile uint32_t  DR4R;                               
  volatile uint32_t  DR8R;                               
  volatile uint32_t  ODR;                                
  volatile uint32_t  PUR;                                
  volatile uint32_t  PDR;                                
  volatile uint32_t  SLR;                                
  volatile uint32_t  DEN;                                
  volatile uint32_t  LOCK;                               
  volatile uint32_t  CR;                                 
  volatile uint32_t  AMSEL;                              
  volatile uint32_t  PCTL;                               
  volatile uint32_t  ADCCTL;                             
  volatile uint32_t  DMACTL;                             
} GPIOA_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  CR0;                                
  volatile uint32_t  CR1;                                
  volatile uint32_t  DR;                                 
  volatile uint32_t  SR;                                 
  volatile uint32_t  CPSR;                               
  volatile uint32_t  IM;                                 
  volatile uint32_t  RIS;                                
  volatile uint32_t  MIS;                                
  volatile  uint32_t  ICR;                                
  volatile uint32_t  DMACTL;                             
  volatile const  uint32_t  RESERVED[1000];
  volatile uint32_t  CC;                                 
} SSI0_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  DR;                                 
  
  union {
    volatile uint32_t  ECR_UART_ALT;                     
    volatile uint32_t  RSR;                              
  };
  volatile const  uint32_t  RESERVED[4];
  volatile uint32_t  FR;                                 
  volatile const  uint32_t  RESERVED1;
  volatile uint32_t  ILPR;                               
  volatile uint32_t  IBRD;                               
  volatile uint32_t  FBRD;                               
  volatile uint32_t  LCRH;                               
  volatile uint32_t  CTL;                                
  volatile uint32_t  IFLS;                               
  volatile uint32_t  IM;                                 
  volatile uint32_t  RIS;                                
  volatile uint32_t  MIS;                                
  volatile  uint32_t  ICR;                                
  volatile uint32_t  DMACTL;                             
  volatile const  uint32_t  RESERVED2[22];
  volatile uint32_t  _9BITADDR;                          
  volatile uint32_t  _9BITAMASK;                         
  volatile const  uint32_t  RESERVED3[965];
  volatile uint32_t  PP;                                 
  volatile const  uint32_t  RESERVED4;
  volatile uint32_t  CC;                                 
} UART0_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  MSA;                                
  
  union {
    volatile uint32_t  MCS_I2C0_ALT;                     
    volatile uint32_t  MCS;                              
  };
  volatile uint32_t  MDR;                                
  volatile uint32_t  MTPR;                               
  volatile uint32_t  MIMR;                               
  volatile uint32_t  MRIS;                               
  volatile uint32_t  MMIS;                               
  volatile  uint32_t  MICR;                               
  volatile uint32_t  MCR;                                
  volatile uint32_t  MCLKOCNT;                           
  volatile const  uint32_t  RESERVED;
  volatile uint32_t  MBMON;                              
  volatile const  uint32_t  RESERVED1[2];
  volatile uint32_t  MCR2;                               
  volatile const  uint32_t  RESERVED2[497];
  volatile uint32_t  SOAR;                               
  
  union {
    volatile uint32_t  SCSR_I2C0_ALT;                    
    volatile uint32_t  SCSR;                             
  };
  volatile uint32_t  SDR;                                
  volatile uint32_t  SIMR;                               
  volatile uint32_t  SRIS;                               
  volatile uint32_t  SMIS;                               
  volatile  uint32_t  SICR;                               
  volatile uint32_t  SOAR2;                              
  volatile uint32_t  SACKCTL;                            
  volatile const  uint32_t  RESERVED3[487];
  volatile uint32_t  PP;                                 
  volatile uint32_t  PC;                                 
} I2C0_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  CTL;                                
  volatile uint32_t  SYNC;                               
  volatile uint32_t  ENABLE;                             
  volatile uint32_t  INVERT;                             
  volatile uint32_t  FAULT;                              
  volatile uint32_t  INTEN;                              
  volatile uint32_t  RIS;                                
  volatile uint32_t  ISC;                                
  volatile uint32_t  STATUS;                             
  volatile uint32_t  FAULTVAL;                           
  volatile uint32_t  ENUPD;                              
  volatile const  uint32_t  RESERVED[5];
  volatile uint32_t  _0_CTL;                             
  volatile uint32_t  _0_INTEN;                           
  volatile uint32_t  _0_RIS;                             
  volatile uint32_t  _0_ISC;                             
  volatile uint32_t  _0_LOAD;                            
  volatile uint32_t  _0_COUNT;                           
  volatile uint32_t  _0_CMPA;                            
  volatile uint32_t  _0_CMPB;                            
  volatile uint32_t  _0_GENA;                            
  volatile uint32_t  _0_GENB;                            
  volatile uint32_t  _0_DBCTL;                           
  volatile uint32_t  _0_DBRISE;                          
  volatile uint32_t  _0_DBFALL;                          
  volatile uint32_t  _0_FLTSRC0;                         
  volatile uint32_t  _0_FLTSRC1;                         
  volatile uint32_t  _0_MINFLTPER;                       
  volatile uint32_t  _1_CTL;                             
  volatile uint32_t  _1_INTEN;                           
  volatile uint32_t  _1_RIS;                             
  volatile uint32_t  _1_ISC;                             
  volatile uint32_t  _1_LOAD;                            
  volatile uint32_t  _1_COUNT;                           
  volatile uint32_t  _1_CMPA;                            
  volatile uint32_t  _1_CMPB;                            
  volatile uint32_t  _1_GENA;                            
  volatile uint32_t  _1_GENB;                            
  volatile uint32_t  _1_DBCTL;                           
  volatile uint32_t  _1_DBRISE;                          
  volatile uint32_t  _1_DBFALL;                          
  volatile uint32_t  _1_FLTSRC0;                         
  volatile uint32_t  _1_FLTSRC1;                         
  volatile uint32_t  _1_MINFLTPER;                       
  volatile uint32_t  _2_CTL;                             
  volatile uint32_t  _2_INTEN;                           
  volatile uint32_t  _2_RIS;                             
  volatile uint32_t  _2_ISC;                             
  volatile uint32_t  _2_LOAD;                            
  volatile uint32_t  _2_COUNT;                           
  volatile uint32_t  _2_CMPA;                            
  volatile uint32_t  _2_CMPB;                            
  volatile uint32_t  _2_GENA;                            
  volatile uint32_t  _2_GENB;                            
  volatile uint32_t  _2_DBCTL;                           
  volatile uint32_t  _2_DBRISE;                          
  volatile uint32_t  _2_DBFALL;                          
  volatile uint32_t  _2_FLTSRC0;                         
  volatile uint32_t  _2_FLTSRC1;                         
  volatile uint32_t  _2_MINFLTPER;                       
  volatile uint32_t  _3_CTL;                             
  volatile uint32_t  _3_INTEN;                           
  volatile uint32_t  _3_RIS;                             
  volatile uint32_t  _3_ISC;                             
  volatile uint32_t  _3_LOAD;                            
  volatile uint32_t  _3_COUNT;                           
  volatile uint32_t  _3_CMPA;                            
  volatile uint32_t  _3_CMPB;                            
  volatile uint32_t  _3_GENA;                            
  volatile uint32_t  _3_GENB;                            
  volatile uint32_t  _3_DBCTL;                           
  volatile uint32_t  _3_DBRISE;                          
  volatile uint32_t  _3_DBFALL;                          
  volatile uint32_t  _3_FLTSRC0;                         
  volatile uint32_t  _3_FLTSRC1;                         
  volatile uint32_t  _3_MINFLTPER;                       
  volatile const  uint32_t  RESERVED1[432];
  volatile uint32_t  _0_FLTSEN;                          
  volatile const  uint32_t  _0_FLTSTAT0;                        
  volatile const  uint32_t  _0_FLTSTAT1;                        
  volatile const  uint32_t  RESERVED2[29];
  volatile uint32_t  _1_FLTSEN;                          
  volatile const  uint32_t  _1_FLTSTAT0;                        
  volatile const  uint32_t  _1_FLTSTAT1;                        
  volatile const  uint32_t  RESERVED3[30];
  volatile const  uint32_t  _2_FLTSTAT0;                        
  volatile const  uint32_t  _2_FLTSTAT1;                        
  volatile const  uint32_t  RESERVED4[30];
  volatile const  uint32_t  _3_FLTSTAT0;                        
  volatile const  uint32_t  _3_FLTSTAT1;                        
  volatile const  uint32_t  RESERVED5[397];
  volatile uint32_t  PP;                                 
} PWM0_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  CTL;                                
  volatile uint32_t  STAT;                               
  volatile uint32_t  POS;                                
  volatile uint32_t  MAXPOS;                             
  volatile uint32_t  LOAD;                               
  volatile uint32_t  TIME;                               
  volatile uint32_t  COUNT;                              
  volatile uint32_t  SPEED;                              
  volatile uint32_t  INTEN;                              
  volatile uint32_t  RIS;                                
  volatile uint32_t  ISC;                                
} QEI0_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  CFG;                                
  volatile uint32_t  TAMR;                               
  volatile uint32_t  TBMR;                               
  volatile uint32_t  CTL;                                
  volatile uint32_t  SYNC;                               
  volatile const  uint32_t  RESERVED;
  volatile uint32_t  IMR;                                
  volatile uint32_t  RIS;                                
  volatile uint32_t  MIS;                                
  volatile  uint32_t  ICR;                                
  volatile uint32_t  TAILR;                              
  volatile uint32_t  TBILR;                              
  volatile uint32_t  TAMATCHR;                           
  volatile uint32_t  TBMATCHR;                           
  volatile uint32_t  TAPR;                               
  volatile uint32_t  TBPR;                               
  volatile uint32_t  TAPMR;                              
  volatile uint32_t  TBPMR;                              
  volatile uint32_t  TAR;                                
  volatile uint32_t  TBR;                                
  volatile uint32_t  TAV;                                
  volatile uint32_t  TBV;                                
  volatile uint32_t  RTCPD;                              
  volatile uint32_t  TAPS;                               
  volatile uint32_t  TBPS;                               
  volatile uint32_t  TAPV;                               
  volatile uint32_t  TBPV;                               
  volatile const  uint32_t  RESERVED1[981];
  volatile uint32_t  PP;                                 
} TIMER0_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  CFG;                                
  volatile uint32_t  TAMR;                               
  volatile uint32_t  TBMR;                               
  volatile uint32_t  CTL;                                
  volatile uint32_t  SYNC;                               
  volatile const  uint32_t  RESERVED;
  volatile uint32_t  IMR;                                
  volatile uint32_t  RIS;                                
  volatile uint32_t  MIS;                                
  volatile  uint32_t  ICR;                                
  volatile uint32_t  TAILR;                              
  volatile uint32_t  TBILR;                              
  volatile uint32_t  TAMATCHR;                           
  volatile uint32_t  TBMATCHR;                           
  volatile uint32_t  TAPR;                               
  volatile uint32_t  TBPR;                               
  volatile uint32_t  TAPMR;                              
  volatile uint32_t  TBPMR;                              
  volatile uint32_t  TAR;                                
  volatile uint32_t  TBR;                                
  volatile uint32_t  TAV;                                
  volatile uint32_t  TBV;                                
  volatile uint32_t  RTCPD;                              
  volatile uint32_t  TAPS;                               
  volatile uint32_t  TBPS;                               
  volatile uint32_t  TAPV;                               
  volatile uint32_t  TBPV;                               
  volatile const  uint32_t  RESERVED1[981];
  volatile uint32_t  PP;                                 
} WTIMER0_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  ACTSS;                              
  volatile uint32_t  RIS;                                
  volatile uint32_t  IM;                                 
  volatile uint32_t  ISC;                                
  volatile uint32_t  OSTAT;                              
  volatile uint32_t  EMUX;                               
  volatile uint32_t  USTAT;                              
  volatile uint32_t  TSSEL;                              
  volatile uint32_t  SSPRI;                              
  volatile uint32_t  SPC;                                
  volatile uint32_t  PSSI;                               
  volatile const  uint32_t  RESERVED;
  volatile uint32_t  SAC;                                
  volatile uint32_t  DCISC;                              
  volatile uint32_t  CTL;                                
  volatile const  uint32_t  RESERVED1;
  volatile uint32_t  SSMUX0;                             
  volatile uint32_t  SSCTL0;                             
  volatile uint32_t  SSFIFO0;                            
  volatile uint32_t  SSFSTAT0;                           
  volatile uint32_t  SSOP0;                              
  volatile uint32_t  SSDC0;                              
  volatile const  uint32_t  RESERVED2[2];
  volatile uint32_t  SSMUX1;                             
  volatile uint32_t  SSCTL1;                             
  volatile uint32_t  SSFIFO1;                            
  volatile uint32_t  SSFSTAT1;                           
  volatile uint32_t  SSOP1;                              
  volatile uint32_t  SSDC1;                              
  volatile const  uint32_t  RESERVED3[2];
  volatile uint32_t  SSMUX2;                             
  volatile uint32_t  SSCTL2;                             
  volatile uint32_t  SSFIFO2;                            
  volatile uint32_t  SSFSTAT2;                           
  volatile uint32_t  SSOP2;                              
  volatile uint32_t  SSDC2;                              
  volatile const  uint32_t  RESERVED4[2];
  volatile uint32_t  SSMUX3;                             
  volatile uint32_t  SSCTL3;                             
  volatile uint32_t  SSFIFO3;                            
  volatile uint32_t  SSFSTAT3;                           
  volatile uint32_t  SSOP3;                              
  volatile uint32_t  SSDC3;                              
  volatile const  uint32_t  RESERVED5[786];
  volatile  uint32_t  DCRIC;                              
  volatile const  uint32_t  RESERVED6[63];
  volatile uint32_t  DCCTL0;                             
  volatile uint32_t  DCCTL1;                             
  volatile uint32_t  DCCTL2;                             
  volatile uint32_t  DCCTL3;                             
  volatile uint32_t  DCCTL4;                             
  volatile uint32_t  DCCTL5;                             
  volatile uint32_t  DCCTL6;                             
  volatile uint32_t  DCCTL7;                             
  volatile const  uint32_t  RESERVED7[8];
  volatile uint32_t  DCCMP0;                             
  volatile uint32_t  DCCMP1;                             
  volatile uint32_t  DCCMP2;                             
  volatile uint32_t  DCCMP3;                             
  volatile uint32_t  DCCMP4;                             
  volatile uint32_t  DCCMP5;                             
  volatile uint32_t  DCCMP6;                             
  volatile uint32_t  DCCMP7;                             
  volatile const  uint32_t  RESERVED8[88];
  volatile uint32_t  PP;                                 
  volatile uint32_t  PC;                                 
  volatile uint32_t  CC;                                 
} ADC0_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  ACMIS;                              
  volatile uint32_t  ACRIS;                              
  volatile uint32_t  ACINTEN;                            
  volatile const  uint32_t  RESERVED;
  volatile uint32_t  ACREFCTL;                           
  volatile const  uint32_t  RESERVED1[3];
  volatile uint32_t  ACSTAT0;                            
  volatile uint32_t  ACCTL0;                             
  volatile const  uint32_t  RESERVED2[6];
  volatile uint32_t  ACSTAT1;                            
  volatile uint32_t  ACCTL1;                             
  volatile const  uint32_t  RESERVED3[990];
  volatile uint32_t  PP;                                 
} COMP_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  CTL;                                
  volatile uint32_t  STS;                                
  volatile uint32_t  ERR;                                
  volatile uint32_t  BIT;                                
  volatile uint32_t  INT;                                
  volatile uint32_t  TST;                                
  volatile uint32_t  BRPE;                               
  volatile const  uint32_t  RESERVED;
  volatile uint32_t  IF1CRQ;                             
  
  union {
    volatile uint32_t  IF1CMSK_CAN0_ALT;                 
    volatile uint32_t  IF1CMSK;                          
  };
  volatile uint32_t  IF1MSK1;                            
  volatile uint32_t  IF1MSK2;                            
  volatile uint32_t  IF1ARB1;                            
  volatile uint32_t  IF1ARB2;                            
  volatile uint32_t  IF1MCTL;                            
  volatile uint32_t  IF1DA1;                             
  volatile uint32_t  IF1DA2;                             
  volatile uint32_t  IF1DB1;                             
  volatile uint32_t  IF1DB2;                             
  volatile const  uint32_t  RESERVED1[13];
  volatile uint32_t  IF2CRQ;                             
  
  union {
    volatile uint32_t  IF2CMSK_CAN0_ALT;                 
    volatile uint32_t  IF2CMSK;                          
  };
  volatile uint32_t  IF2MSK1;                            
  volatile uint32_t  IF2MSK2;                            
  volatile uint32_t  IF2ARB1;                            
  volatile uint32_t  IF2ARB2;                            
  volatile uint32_t  IF2MCTL;                            
  volatile uint32_t  IF2DA1;                             
  volatile uint32_t  IF2DA2;                             
  volatile uint32_t  IF2DB1;                             
  volatile uint32_t  IF2DB2;                             
  volatile const  uint32_t  RESERVED2[21];
  volatile uint32_t  TXRQ1;                              
  volatile uint32_t  TXRQ2;                              
  volatile const  uint32_t  RESERVED3[6];
  volatile uint32_t  NWDA1;                              
  volatile uint32_t  NWDA2;                              
  volatile const  uint32_t  RESERVED4[6];
  volatile uint32_t  MSG1INT;                            
  volatile uint32_t  MSG2INT;                            
  volatile const  uint32_t  RESERVED5[6];
  volatile uint32_t  MSG1VAL;                            
  volatile uint32_t  MSG2VAL;                            
} CAN0_Type;


 
 
 




 

typedef struct {                                     
  volatile uint8_t   FADDR;                              
  volatile uint8_t   POWER;                              
  volatile uint16_t  TXIS;                               
  volatile uint16_t  RXIS;                               
  volatile uint16_t  TXIE;                               
  volatile uint16_t  RXIE;                               
  
  union {
    volatile uint8_t   IS_USB0_ALT;                      
    volatile uint8_t   IS;                               
  };
  
  union {
    volatile uint8_t   IE_USB0_ALT;                      
    volatile uint8_t   IE;                               
  };
  volatile uint16_t  FRAME;                              
  volatile uint8_t   EPIDX;                              
  volatile uint8_t   TEST;                               
  volatile const  uint32_t  RESERVED[4];
  volatile uint32_t  FIFO0;                              
  volatile uint32_t  FIFO1;                              
  volatile uint32_t  FIFO2;                              
  volatile uint32_t  FIFO3;                              
  volatile uint32_t  FIFO4;                              
  volatile uint32_t  FIFO5;                              
  volatile uint32_t  FIFO6;                              
  volatile uint32_t  FIFO7;                              
  volatile const  uint32_t  RESERVED1[8];
  volatile uint8_t   DEVCTL;                             
  volatile const  uint8_t   RESERVED2;
  volatile uint8_t   TXFIFOSZ;                           
  volatile uint8_t   RXFIFOSZ;                           
  volatile uint16_t  TXFIFOADD;                          
  volatile uint16_t  RXFIFOADD;                          
  volatile const  uint16_t  RESERVED3[9];
  volatile uint8_t   CONTIM;                             
  volatile uint8_t   VPLEN;                              
  volatile const  uint8_t   RESERVED4;
  volatile uint8_t   FSEOF;                              
  volatile uint8_t   LSEOF;                              
  volatile const  uint8_t   RESERVED5;
  volatile uint8_t   TXFUNCADDR0;                        
  volatile const  uint8_t   RESERVED6;
  volatile uint8_t   TXHUBADDR0;                         
  volatile uint8_t   TXHUBPORT0;                         
  volatile const  uint32_t  RESERVED7;
  volatile uint8_t   TXFUNCADDR1;                        
  volatile const  uint8_t   RESERVED8;
  volatile uint8_t   TXHUBADDR1;                         
  volatile uint8_t   TXHUBPORT1;                         
  volatile uint8_t   RXFUNCADDR1;                        
  volatile const  uint8_t   RESERVED9;
  volatile uint8_t   RXHUBADDR1;                         
  volatile uint8_t   RXHUBPORT1;                         
  volatile uint8_t   TXFUNCADDR2;                        
  volatile const  uint8_t   RESERVED10;
  volatile uint8_t   TXHUBADDR2;                         
  volatile uint8_t   TXHUBPORT2;                         
  volatile uint8_t   RXFUNCADDR2;                        
  volatile const  uint8_t   RESERVED11;
  volatile uint8_t   RXHUBADDR2;                         
  volatile uint8_t   RXHUBPORT2;                         
  volatile uint8_t   TXFUNCADDR3;                        
  volatile const  uint8_t   RESERVED12;
  volatile uint8_t   TXHUBADDR3;                         
  volatile uint8_t   TXHUBPORT3;                         
  volatile uint8_t   RXFUNCADDR3;                        
  volatile const  uint8_t   RESERVED13;
  volatile uint8_t   RXHUBADDR3;                         
  volatile uint8_t   RXHUBPORT3;                         
  volatile uint8_t   TXFUNCADDR4;                        
  volatile const  uint8_t   RESERVED14;
  volatile uint8_t   TXHUBADDR4;                         
  volatile uint8_t   TXHUBPORT4;                         
  volatile uint8_t   RXFUNCADDR4;                        
  volatile const  uint8_t   RESERVED15;
  volatile uint8_t   RXHUBADDR4;                         
  volatile uint8_t   RXHUBPORT4;                         
  volatile uint8_t   TXFUNCADDR5;                        
  volatile const  uint8_t   RESERVED16;
  volatile uint8_t   TXHUBADDR5;                         
  volatile uint8_t   TXHUBPORT5;                         
  volatile uint8_t   RXFUNCADDR5;                        
  volatile const  uint8_t   RESERVED17;
  volatile uint8_t   RXHUBADDR5;                         
  volatile uint8_t   RXHUBPORT5;                         
  volatile uint8_t   TXFUNCADDR6;                        
  volatile const  uint8_t   RESERVED18;
  volatile uint8_t   TXHUBADDR6;                         
  volatile uint8_t   TXHUBPORT6;                         
  volatile uint8_t   RXFUNCADDR6;                        
  volatile const  uint8_t   RESERVED19;
  volatile uint8_t   RXHUBADDR6;                         
  volatile uint8_t   RXHUBPORT6;                         
  volatile uint8_t   TXFUNCADDR7;                        
  volatile const  uint8_t   RESERVED20;
  volatile uint8_t   TXHUBADDR7;                         
  volatile uint8_t   TXHUBPORT7;                         
  volatile uint8_t   RXFUNCADDR7;                        
  volatile const  uint8_t   RESERVED21;
  volatile uint8_t   RXHUBADDR7;                         
  volatile uint8_t   RXHUBPORT7;                         
  volatile const  uint16_t  RESERVED22[33];
  
  union {
    volatile  uint8_t   CSRL0_USB0_ALT;                   
    volatile  uint8_t   CSRL0;                            
  };
  volatile  uint8_t   CSRH0;                              
  volatile const  uint32_t  RESERVED23;
  volatile uint8_t   COUNT0;                             
  volatile const  uint8_t   RESERVED24;
  volatile uint8_t   TYPE0;                              
  volatile uint8_t   NAKLMT;                             
  volatile const  uint32_t  RESERVED25;
  volatile uint16_t  TXMAXP1;                            
  
  union {
    volatile uint8_t   TXCSRL1_USB0_ALT;                 
    volatile uint8_t   TXCSRL1;                          
  };
  volatile uint8_t   TXCSRH1;                            
  volatile uint16_t  RXMAXP1;                            
  
  union {
    volatile uint8_t   RXCSRL1_USB0_ALT;                 
    volatile uint8_t   RXCSRL1;                          
  };
  
  union {
    volatile uint8_t   RXCSRH1_USB0_ALT;                 
    volatile uint8_t   RXCSRH1;                          
  };
  volatile uint16_t  RXCOUNT1;                           
  volatile uint8_t   TXTYPE1;                            
  
  union {
    volatile uint8_t   TXINTERVAL1_USB0_ALT;             
    volatile uint8_t   TXINTERVAL1;                      
  };
  volatile uint8_t   RXTYPE1;                            
  
  union {
    volatile uint8_t   RXINTERVAL1_USB0_ALT;             
    volatile uint8_t   RXINTERVAL1;                      
  };
  volatile const  uint16_t  RESERVED26;
  volatile uint16_t  TXMAXP2;                            
  
  union {
    volatile uint8_t   TXCSRL2_USB0_ALT;                 
    volatile uint8_t   TXCSRL2;                          
  };
  volatile uint8_t   TXCSRH2;                            
  volatile uint16_t  RXMAXP2;                            
  
  union {
    volatile uint8_t   RXCSRL2_USB0_ALT;                 
    volatile uint8_t   RXCSRL2;                          
  };
  
  union {
    volatile uint8_t   RXCSRH2_USB0_ALT;                 
    volatile uint8_t   RXCSRH2;                          
  };
  volatile uint16_t  RXCOUNT2;                           
  volatile uint8_t   TXTYPE2;                            
  
  union {
    volatile uint8_t   TXINTERVAL2_USB0_ALT;             
    volatile uint8_t   TXINTERVAL2;                      
  };
  volatile uint8_t   RXTYPE2;                            
  
  union {
    volatile uint8_t   RXINTERVAL2_USB0_ALT;             
    volatile uint8_t   RXINTERVAL2;                      
  };
  volatile const  uint16_t  RESERVED27;
  volatile uint16_t  TXMAXP3;                            
  
  union {
    volatile uint8_t   TXCSRL3_USB0_ALT;                 
    volatile uint8_t   TXCSRL3;                          
  };
  volatile uint8_t   TXCSRH3;                            
  volatile uint16_t  RXMAXP3;                            
  
  union {
    volatile uint8_t   RXCSRL3_USB0_ALT;                 
    volatile uint8_t   RXCSRL3;                          
  };
  
  union {
    volatile uint8_t   RXCSRH3_USB0_ALT;                 
    volatile uint8_t   RXCSRH3;                          
  };
  volatile uint16_t  RXCOUNT3;                           
  volatile uint8_t   TXTYPE3;                            
  
  union {
    volatile uint8_t   TXINTERVAL3_USB0_ALT;             
    volatile uint8_t   TXINTERVAL3;                      
  };
  volatile uint8_t   RXTYPE3;                            
  
  union {
    volatile uint8_t   RXINTERVAL3_USB0_ALT;             
    volatile uint8_t   RXINTERVAL3;                      
  };
  volatile const  uint16_t  RESERVED28;
  volatile uint16_t  TXMAXP4;                            
  
  union {
    volatile uint8_t   TXCSRL4_USB0_ALT;                 
    volatile uint8_t   TXCSRL4;                          
  };
  volatile uint8_t   TXCSRH4;                            
  volatile uint16_t  RXMAXP4;                            
  
  union {
    volatile uint8_t   RXCSRL4_USB0_ALT;                 
    volatile uint8_t   RXCSRL4;                          
  };
  
  union {
    volatile uint8_t   RXCSRH4_USB0_ALT;                 
    volatile uint8_t   RXCSRH4;                          
  };
  volatile uint16_t  RXCOUNT4;                           
  volatile uint8_t   TXTYPE4;                            
  
  union {
    volatile uint8_t   TXINTERVAL4_USB0_ALT;             
    volatile uint8_t   TXINTERVAL4;                      
  };
  volatile uint8_t   RXTYPE4;                            
  
  union {
    volatile uint8_t   RXINTERVAL4_USB0_ALT;             
    volatile uint8_t   RXINTERVAL4;                      
  };
  volatile const  uint16_t  RESERVED29;
  volatile uint16_t  TXMAXP5;                            
  
  union {
    volatile uint8_t   TXCSRL5_USB0_ALT;                 
    volatile uint8_t   TXCSRL5;                          
  };
  volatile uint8_t   TXCSRH5;                            
  volatile uint16_t  RXMAXP5;                            
  
  union {
    volatile uint8_t   RXCSRL5_USB0_ALT;                 
    volatile uint8_t   RXCSRL5;                          
  };
  
  union {
    volatile uint8_t   RXCSRH5_USB0_ALT;                 
    volatile uint8_t   RXCSRH5;                          
  };
  volatile uint16_t  RXCOUNT5;                           
  volatile uint8_t   TXTYPE5;                            
  
  union {
    volatile uint8_t   TXINTERVAL5_USB0_ALT;             
    volatile uint8_t   TXINTERVAL5;                      
  };
  volatile uint8_t   RXTYPE5;                            
  
  union {
    volatile uint8_t   RXINTERVAL5_USB0_ALT;             
    volatile uint8_t   RXINTERVAL5;                      
  };
  volatile const  uint16_t  RESERVED30;
  volatile uint16_t  TXMAXP6;                            
  
  union {
    volatile uint8_t   TXCSRL6_USB0_ALT;                 
    volatile uint8_t   TXCSRL6;                          
  };
  volatile uint8_t   TXCSRH6;                            
  volatile uint16_t  RXMAXP6;                            
  
  union {
    volatile uint8_t   RXCSRL6_USB0_ALT;                 
    volatile uint8_t   RXCSRL6;                          
  };
  
  union {
    volatile uint8_t   RXCSRH6_USB0_ALT;                 
    volatile uint8_t   RXCSRH6;                          
  };
  volatile uint16_t  RXCOUNT6;                           
  volatile uint8_t   TXTYPE6;                            
  
  union {
    volatile uint8_t   TXINTERVAL6_USB0_ALT;             
    volatile uint8_t   TXINTERVAL6;                      
  };
  volatile uint8_t   RXTYPE6;                            
  
  union {
    volatile uint8_t   RXINTERVAL6_USB0_ALT;             
    volatile uint8_t   RXINTERVAL6;                      
  };
  volatile const  uint16_t  RESERVED31;
  volatile uint16_t  TXMAXP7;                            
  
  union {
    volatile uint8_t   TXCSRL7_USB0_ALT;                 
    volatile uint8_t   TXCSRL7;                          
  };
  volatile uint8_t   TXCSRH7;                            
  volatile uint16_t  RXMAXP7;                            
  
  union {
    volatile uint8_t   RXCSRL7_USB0_ALT;                 
    volatile uint8_t   RXCSRL7;                          
  };
  
  union {
    volatile uint8_t   RXCSRH7_USB0_ALT;                 
    volatile uint8_t   RXCSRH7;                          
  };
  volatile uint16_t  RXCOUNT7;                           
  volatile uint8_t   TXTYPE7;                            
  
  union {
    volatile uint8_t   TXINTERVAL7_USB0_ALT;             
    volatile uint8_t   TXINTERVAL7;                      
  };
  volatile uint8_t   RXTYPE7;                            
  
  union {
    volatile uint8_t   RXINTERVAL7_USB0_ALT;             
    volatile uint8_t   RXINTERVAL7;                      
  };
  volatile const  uint16_t  RESERVED32[195];
  volatile uint16_t  RQPKTCOUNT1;                        
  volatile const  uint16_t  RESERVED33;
  volatile uint16_t  RQPKTCOUNT2;                        
  volatile const  uint16_t  RESERVED34;
  volatile uint16_t  RQPKTCOUNT3;                        
  volatile const  uint16_t  RESERVED35;
  volatile uint16_t  RQPKTCOUNT4;                        
  volatile const  uint16_t  RESERVED36;
  volatile uint16_t  RQPKTCOUNT5;                        
  volatile const  uint16_t  RESERVED37;
  volatile uint16_t  RQPKTCOUNT6;                        
  volatile const  uint16_t  RESERVED38;
  volatile uint16_t  RQPKTCOUNT7;                        
  volatile const  uint16_t  RESERVED39[17];
  volatile uint16_t  RXDPKTBUFDIS;                       
  volatile uint16_t  TXDPKTBUFDIS;                       
  volatile const  uint32_t  RESERVED40[47];
  volatile uint32_t  EPC;                                
  volatile uint32_t  EPCRIS;                             
  volatile uint32_t  EPCIM;                              
  volatile uint32_t  EPCISC;                             
  volatile uint32_t  DRRIS;                              
  volatile uint32_t  DRIM;                               
  volatile  uint32_t  DRISC;                              
  volatile uint32_t  GPCS;                               
  volatile const  uint32_t  RESERVED41[4];
  volatile uint32_t  VDC;                                
  volatile uint32_t  VDCRIS;                             
  volatile uint32_t  VDCIM;                              
  volatile uint32_t  VDCISC;                             
  volatile const  uint32_t  RESERVED42;
  volatile uint32_t  IDVRIS;                             
  volatile uint32_t  IDVIM;                              
  volatile uint32_t  IDVISC;                             
  volatile uint32_t  DMASEL;                             
  volatile const  uint32_t  RESERVED43[731];
  volatile uint32_t  PP;                                 
} USB0_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  EESIZE;                             
  volatile uint32_t  EEBLOCK;                            
  volatile uint32_t  EEOFFSET;                           
  volatile const  uint32_t  RESERVED;
  volatile uint32_t  EERDWR;                             
  volatile uint32_t  EERDWRINC;                          
  volatile uint32_t  EEDONE;                             
  volatile uint32_t  EESUPP;                             
  volatile uint32_t  EEUNLOCK;                           
  volatile const  uint32_t  RESERVED1[3];
  volatile uint32_t  EEPROT;                             
  volatile uint32_t  EEPASS0;                            
  volatile uint32_t  EEPASS1;                            
  volatile uint32_t  EEPASS2;                            
  volatile uint32_t  EEINT;                              
  volatile const  uint32_t  RESERVED2[3];
  volatile uint32_t  EEHIDE;                             
  volatile const  uint32_t  RESERVED3[11];
  volatile uint32_t  EEDBGME;                            
  volatile const  uint32_t  RESERVED4[975];
  volatile uint32_t  PP;                                 
} EEPROM_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  RIS;                                
  volatile uint32_t  IM;                                 
  volatile uint32_t  MIS;                                
  volatile  uint32_t  IC;                                 
} SYSEXC_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  RTCC;                               
  volatile uint32_t  RTCM0;                              
  volatile const  uint32_t  RESERVED;
  volatile uint32_t  RTCLD;                              
  volatile uint32_t  CTL;                                
  volatile uint32_t  IM;                                 
  volatile uint32_t  RIS;                                
  volatile uint32_t  MIS;                                
  volatile uint32_t  IC;                                 
  volatile uint32_t  RTCT;                               
  volatile uint32_t  RTCSS;                              
  volatile const  uint32_t  RESERVED1;
  volatile uint32_t  DATA;                               
} HIB_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  FMA;                                
  volatile uint32_t  FMD;                                
  volatile uint32_t  FMC;                                
  volatile uint32_t  FCRIS;                              
  volatile uint32_t  FCIM;                               
  volatile uint32_t  FCMISC;                             
  volatile const  uint32_t  RESERVED[2];
  volatile uint32_t  FMC2;                               
  volatile const  uint32_t  RESERVED1[3];
  volatile uint32_t  FWBVAL;                             
  volatile const  uint32_t  RESERVED2[51];
  volatile uint32_t  FWBN;                               
  volatile const  uint32_t  RESERVED3[943];
  volatile uint32_t  FSIZE;                              
  volatile uint32_t  SSIZE;                              
  volatile const  uint32_t  RESERVED4;
  
  union {
    volatile uint32_t  ROMSWMAP_FLASH_CTRL_ALT;          
    volatile uint32_t  ROMSWMAP;                         
  };
  volatile const  uint32_t  RESERVED5[72];
  volatile uint32_t  RMCTL;                              
  volatile const  uint32_t  RESERVED6[55];
  volatile uint32_t  BOOTCFG;                            
  volatile const  uint32_t  RESERVED7[3];
  volatile uint32_t  USERREG0;                           
  volatile uint32_t  USERREG1;                           
  volatile uint32_t  USERREG2;                           
  volatile uint32_t  USERREG3;                           
  volatile const  uint32_t  RESERVED8[4];
  volatile uint32_t  FMPRE0;                             
  volatile uint32_t  FMPRE1;                             
  volatile uint32_t  FMPRE2;                             
  volatile uint32_t  FMPRE3;                             
  volatile const  uint32_t  RESERVED9[124];
  volatile uint32_t  FMPPE0;                             
  volatile uint32_t  FMPPE1;                             
  volatile uint32_t  FMPPE2;                             
  volatile uint32_t  FMPPE3;                             
} FLASH_CTRL_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  DID0;                               
  volatile uint32_t  DID1;                               
  volatile uint32_t  DC0;                                
  volatile const  uint32_t  RESERVED;
  volatile uint32_t  DC1;                                
  volatile uint32_t  DC2;                                
  volatile uint32_t  DC3;                                
  volatile uint32_t  DC4;                                
  volatile uint32_t  DC5;                                
  volatile uint32_t  DC6;                                
  volatile uint32_t  DC7;                                
  volatile uint32_t  DC8;                                
  volatile uint32_t  PBORCTL;                            
  volatile const  uint32_t  RESERVED1[3];
  volatile uint32_t  SRCR0;                              
  volatile uint32_t  SRCR1;                              
  volatile uint32_t  SRCR2;                              
  volatile const  uint32_t  RESERVED2;
  volatile uint32_t  RIS;                                
  volatile uint32_t  IMC;                                
  volatile uint32_t  MISC;                               
  volatile uint32_t  RESC;                               
  volatile uint32_t  RCC;                                
  volatile const  uint32_t  RESERVED3[2];
  volatile uint32_t  GPIOHBCTL;                          
  volatile uint32_t  RCC2;                               
  volatile const  uint32_t  RESERVED4[2];
  volatile uint32_t  MOSCCTL;                            
  volatile const  uint32_t  RESERVED5[32];
  volatile uint32_t  RCGC0;                              
  volatile uint32_t  RCGC1;                              
  volatile uint32_t  RCGC2;                              
  volatile const  uint32_t  RESERVED6;
  volatile uint32_t  SCGC0;                              
  volatile uint32_t  SCGC1;                              
  volatile uint32_t  SCGC2;                              
  volatile const  uint32_t  RESERVED7;
  volatile uint32_t  DCGC0;                              
  volatile uint32_t  DCGC1;                              
  volatile uint32_t  DCGC2;                              
  volatile const  uint32_t  RESERVED8[6];
  volatile uint32_t  DSLPCLKCFG;                         
  volatile const  uint32_t  RESERVED9;
  volatile uint32_t  SYSPROP;                            
  volatile uint32_t  PIOSCCAL;                           
  volatile uint32_t  PIOSCSTAT;                          
  volatile const  uint32_t  RESERVED10[2];
  volatile uint32_t  PLLFREQ0;                           
  volatile uint32_t  PLLFREQ1;                           
  volatile uint32_t  PLLSTAT;                            
  volatile const  uint32_t  RESERVED11[7];
  volatile uint32_t  SLPPWRCFG;                          
  volatile uint32_t  DSLPPWRCFG;                         
  volatile uint32_t  DC9;                                
  volatile const  uint32_t  RESERVED12[3];
  volatile uint32_t  NVMSTAT;                            
  volatile const  uint32_t  RESERVED13[4];
  volatile uint32_t  LDOSPCTL;                           
  volatile const  uint32_t  RESERVED14;
  volatile uint32_t  LDODPCTL;                           
  volatile const  uint32_t  RESERVED15[80];
  volatile uint32_t  PPWD;                               
  volatile uint32_t  PPTIMER;                            
  volatile uint32_t  PPGPIO;                             
  volatile uint32_t  PPDMA;                              
  volatile const  uint32_t  RESERVED16;
  volatile uint32_t  PPHIB;                              
  volatile uint32_t  PPUART;                             
  volatile uint32_t  PPSSI;                              
  volatile uint32_t  PPI2C;                              
  volatile const  uint32_t  RESERVED17;
  volatile uint32_t  PPUSB;                              
  volatile const  uint32_t  RESERVED18[2];
  volatile uint32_t  PPCAN;                              
  volatile uint32_t  PPADC;                              
  volatile uint32_t  PPACMP;                             
  volatile uint32_t  PPPWM;                              
  volatile uint32_t  PPQEI;                              
  volatile const  uint32_t  RESERVED19[4];
  volatile uint32_t  PPEEPROM;                           
  volatile uint32_t  PPWTIMER;                           
  volatile const  uint32_t  RESERVED20[104];
  volatile uint32_t  SRWD;                               
  volatile uint32_t  SRTIMER;                            
  volatile uint32_t  SRGPIO;                             
  volatile uint32_t  SRDMA;                              
  volatile const  uint32_t  RESERVED21;
  volatile uint32_t  SRHIB;                              
  volatile uint32_t  SRUART;                             
  volatile uint32_t  SRSSI;                              
  volatile uint32_t  SRI2C;                              
  volatile const  uint32_t  RESERVED22;
  volatile uint32_t  SRUSB;                              
  volatile const  uint32_t  RESERVED23[2];
  volatile uint32_t  SRCAN;                              
  volatile uint32_t  SRADC;                              
  volatile uint32_t  SRACMP;                             
  volatile uint32_t  SRPWM;                              
  volatile uint32_t  SRQEI;                              
  volatile const  uint32_t  RESERVED24[4];
  volatile uint32_t  SREEPROM;                           
  volatile uint32_t  SRWTIMER;                           
  volatile const  uint32_t  RESERVED25[40];
  volatile uint32_t  RCGCWD;                             
  volatile uint32_t  RCGCTIMER;                          
  volatile uint32_t  RCGCGPIO;                           
  volatile uint32_t  RCGCDMA;                            
  volatile const  uint32_t  RESERVED26;
  volatile uint32_t  RCGCHIB;                            
  volatile uint32_t  RCGCUART;                          
 
  volatile uint32_t  RCGCSSI;                            
  volatile uint32_t  RCGCI2C;                            
  volatile const  uint32_t  RESERVED27;
  volatile uint32_t  RCGCUSB;                            
  volatile const  uint32_t  RESERVED28[2];
  volatile uint32_t  RCGCCAN;                            
  volatile uint32_t  RCGCADC;                            
  volatile uint32_t  RCGCACMP;                           
  volatile uint32_t  RCGCPWM;                            
  volatile uint32_t  RCGCQEI;                            
  volatile const  uint32_t  RESERVED29[4];
  volatile uint32_t  RCGCEEPROM;                         
  volatile uint32_t  RCGCWTIMER;                         
  volatile const  uint32_t  RESERVED30[40];
  volatile uint32_t  SCGCWD;                             
  volatile uint32_t  SCGCTIMER;                          
  volatile uint32_t  SCGCGPIO;                           
  volatile uint32_t  SCGCDMA;                            
  volatile const  uint32_t  RESERVED31;
  volatile uint32_t  SCGCHIB;                            
  volatile uint32_t  SCGCUART;                          
 
  volatile uint32_t  SCGCSSI;                            
  volatile uint32_t  SCGCI2C;                            
  volatile const  uint32_t  RESERVED32;
  volatile uint32_t  SCGCUSB;                            
  volatile const  uint32_t  RESERVED33[2];
  volatile uint32_t  SCGCCAN;                            
  volatile uint32_t  SCGCADC;                            
  volatile uint32_t  SCGCACMP;                           
  volatile uint32_t  SCGCPWM;                            
  volatile uint32_t  SCGCQEI;                            
  volatile const  uint32_t  RESERVED34[4];
  volatile uint32_t  SCGCEEPROM;                         
  volatile uint32_t  SCGCWTIMER;                        
 
  volatile const  uint32_t  RESERVED35[40];
  volatile uint32_t  DCGCWD;                             
  volatile uint32_t  DCGCTIMER;                         
 
  volatile uint32_t  DCGCGPIO;                           
  volatile uint32_t  DCGCDMA;                            
  volatile const  uint32_t  RESERVED36;
  volatile uint32_t  DCGCHIB;                            
  volatile uint32_t  DCGCUART;                          
 
  volatile uint32_t  DCGCSSI;                            
  volatile uint32_t  DCGCI2C;                            
  volatile const  uint32_t  RESERVED37;
  volatile uint32_t  DCGCUSB;                            
  volatile const  uint32_t  RESERVED38[2];
  volatile uint32_t  DCGCCAN;                            
  volatile uint32_t  DCGCADC;                            
  volatile uint32_t  DCGCACMP;                           
  volatile uint32_t  DCGCPWM;                            
  volatile uint32_t  DCGCQEI;                            
  volatile const  uint32_t  RESERVED39[4];
  volatile uint32_t  DCGCEEPROM;                         
  volatile uint32_t  DCGCWTIMER;                        
 
  volatile const  uint32_t  RESERVED40[104];
  volatile uint32_t  PRWD;                               
  volatile uint32_t  PRTIMER;                            
  volatile uint32_t  PRGPIO;                             
  volatile uint32_t  PRDMA;                              
  volatile const  uint32_t  RESERVED41;
  volatile uint32_t  PRHIB;                              
  volatile uint32_t  PRUART;                             
  volatile uint32_t  PRSSI;                              
  volatile uint32_t  PRI2C;                              
  volatile const  uint32_t  RESERVED42;
  volatile uint32_t  PRUSB;                              
  volatile const  uint32_t  RESERVED43[2];
  volatile uint32_t  PRCAN;                              
  volatile uint32_t  PRADC;                              
  volatile uint32_t  PRACMP;                             
  volatile uint32_t  PRPWM;                              
  volatile uint32_t  PRQEI;                              
  volatile const  uint32_t  RESERVED44[4];
  volatile uint32_t  PREEPROM;                           
  volatile uint32_t  PRWTIMER;                           
} SYSCTL_Type;


 
 
 




 

typedef struct {                                     
  volatile uint32_t  STAT;                               
  volatile  uint32_t  CFG;                                
  volatile uint32_t  CTLBASE;                            
  volatile uint32_t  ALTBASE;                            
  volatile uint32_t  WAITSTAT;                           
  volatile  uint32_t  SWREQ;                              
  volatile uint32_t  USEBURSTSET;                        
  volatile  uint32_t  USEBURSTCLR;                        
  volatile uint32_t  REQMASKSET;                         
  volatile  uint32_t  REQMASKCLR;                         
  volatile uint32_t  ENASET;                             
  volatile  uint32_t  ENACLR;                             
  volatile uint32_t  ALTSET;                             
  volatile  uint32_t  ALTCLR;                             
  volatile uint32_t  PRIOSET;                            
  volatile  uint32_t  PRIOCLR;                            
  volatile const  uint32_t  RESERVED[3];
  volatile uint32_t  ERRCLR;                             
  volatile const  uint32_t  RESERVED1[300];
  volatile uint32_t  CHASGN;                             
  volatile uint32_t  CHIS;                               
  volatile const  uint32_t  RESERVED2[2];
  volatile uint32_t  CHMAP0;                             
  volatile uint32_t  CHMAP1;                             
  volatile uint32_t  CHMAP2;                             
  volatile uint32_t  CHMAP3;                             
} UDMA_Type;


 

  #pragma pop
#line 1535 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\TM4C123GH6PM.h"




 
 
 

#line 1601 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\TM4C123GH6PM.h"


 
 
 

#line 1665 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\TM4C123GH6PM.h"


   
   
   








#line 99 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\TM4C123.h"
#line 120 "F:\\0_Tools\\Keil_v5\\ARM\\PACK\\Keil\\TM4C_DFP\\1.1.0\\Device\\Include\\TM4C123\\TM4C123.h"

#line 14 "RTE\\Device\\TM4C123GH6PM\\system_TM4C123.c"




 





























































































































































































































#line 253 "RTE\\Device\\TM4C123GH6PM\\system_TM4C123.c"

#line 262 "RTE\\Device\\TM4C123GH6PM\\system_TM4C123.c"




 









  
#line 416 "RTE\\Device\\TM4C123GH6PM\\system_TM4C123.c"




 
uint32_t SystemCoreClock = ((400000000UL) / (((( ((4 - 1) << 23) | (1 << 22) | (1 << 20) | (7 << 17) | (0 << 13) | (0 << 11) | (21 << 6) | (0 << 4) | (1 << 1) | (0 << 1))>>23) & (0x0F)) + 1) / 2);   




 



 
__inline static uint32_t getOscClk (uint32_t xtal, uint32_t oscSrc) {
  uint32_t oscClk = (16000000UL);

  switch (oscSrc) {                       
    case 0:                               
      switch (xtal) {                     
        case 0x0:
          oscClk = 1000000UL;
          break;
        case 0x1:
          oscClk = 1843200UL;
          break;
        case 0x2:
          oscClk = 2000000UL;
          break;
        case 0x3:
          oscClk = 2457600UL;
          break;
        case 0x4:
          oscClk = 3579545UL;
          break;
        case 0x5:
          oscClk = 3686400UL;
          break;
        case 0x6:
          oscClk = 4000000UL;
          break;
        case 0x7:
          oscClk = 4096000UL;
          break;
        case 0x8:
          oscClk = 4915200UL;
          break;
        case 0x9:
          oscClk = 5000000UL;
          break;
        case 0xA:
          oscClk = 5120000UL;
          break;
        case 0xB:
          oscClk = 6000000UL;
          break;
        case 0xC:
          oscClk = 6144000UL;
          break;
        case 0xD:
          oscClk = 7372800UL;
          break;
        case 0xE:
          oscClk = 8000000UL;
          break;
        case 0xF:
          oscClk = 8192000UL;
          break;
        case 0x10:
          oscClk = 10000000UL;
          break;
        case 0x11:
          oscClk = 12000000UL;
          break;
        case 0x12:
          oscClk = 12288000UL;
          break;
        case 0x13:
          oscClk = 13560000UL;
          break;
        case 0x14:
          oscClk = 14318180UL;
          break;
        case 0x15:
          oscClk = 16000000UL;
          break;
        case 0x16:
          oscClk = 16384000UL;
          break;
       }
      break;
    case 1:                          
      oscClk = (16000000UL);
      break;
    case 2:                          
      oscClk = (16000000UL)/4;
      break;
    case 3:                          
      oscClk = ( 30000UL);
      break;
  }

  return oscClk;
}

void SystemCoreClockUpdate (void)             
{
    uint32_t rcc, rcc2;

     
    rcc  = ((SYSCTL_Type *) 0x400FE000UL)->RCC;
    rcc2 = ((SYSCTL_Type *) 0x400FE000UL)->RCC2;

  
    if (rcc2 & (1UL<<31)) {                              
  
      if (rcc2 & (1UL<<11)) {                            
        SystemCoreClock = getOscClk (((rcc>>6) & 0x0F),((rcc2>>4) & 0x07));
      } else {
        SystemCoreClock = (400000000UL);
      }
      if (rcc & (1UL<<22)) {                             
        if (rcc2 & (1UL<<11)) {
          SystemCoreClock = SystemCoreClock / (((rcc2>>23) & (0x3F)) + 1);
        } else {
          SystemCoreClock = SystemCoreClock / (((rcc2>>23) & (0x3F)) + 1) / 2;
        }
      }
    } else {
  
      if (rcc & (1UL<<11)) {                               
        SystemCoreClock = getOscClk (((rcc>>6) & 0x1F),((rcc>>4) & 0x03));
      } else {
        SystemCoreClock = (400000000UL);
      }
  
      if (rcc & (1UL<<22)) {                             
  
        if (rcc & (1UL<<11)) {                             
  
          SystemCoreClock = SystemCoreClock / (((rcc>>23) & (0x0F)) + 1);
        } else {
          SystemCoreClock = SystemCoreClock / (((rcc>>23) & (0x0F)) + 1) / 2;
        }
      }
    }
}









 
void SystemInit (void)
{

    uint32_t i;


   






    ((SYSCTL_Type *) 0x400FE000UL)->RCC2 = 0x07802810;     
    ((SYSCTL_Type *) 0x400FE000UL)->RCC  = 0x078E3AD1;     

    ((SYSCTL_Type *) 0x400FE000UL)->RCC  = (( ((4 - 1) << 23) | (1 << 22) | (1 << 20) | (7 << 17) | (0 << 13) | (0 << 11) | (21 << 6) | (0 << 4) | (1 << 1) | (0 << 1))  | (1UL<<11) | (1UL<<13)) & ~(1UL<<22);  
    ((SYSCTL_Type *) 0x400FE000UL)->RCC2 = (( (0 << 31) | ((4 - 1) << 23) | (0 << 13) | (0 << 11) | (0 << 4)) | (1UL<<11) | (1UL<<13));               
    for (i = 0; i < 1000; i++);    

    ((SYSCTL_Type *) 0x400FE000UL)->RCC  = (( ((4 - 1) << 23) | (1 << 22) | (1 << 20) | (7 << 17) | (0 << 13) | (0 << 11) | (21 << 6) | (0 << 4) | (1 << 1) | (0 << 1))  | (1UL<<11)) & ~(1UL<<22);              
    ((SYSCTL_Type *) 0x400FE000UL)->RCC2 = (( (0 << 31) | ((4 - 1) << 23) | (0 << 13) | (0 << 11) | (0 << 4)) | (1UL<<11));                           
    for (i = 0; i < 1000; i++);    

    ((SYSCTL_Type *) 0x400FE000UL)->RCC  = (( ((4 - 1) << 23) | (1 << 22) | (1 << 20) | (7 << 17) | (0 << 13) | (0 << 11) | (21 << 6) | (0 << 4) | (1 << 1) | (0 << 1))  | (1<<11));                             

    if ( (((( ((4 - 1) << 23) | (1 << 22) | (1 << 20) | (7 << 17) | (0 << 13) | (0 << 11) | (21 << 6) | (0 << 4) | (1 << 1) | (0 << 1))  & (1UL<<13)) == 0) && ((( (0 << 31) | ((4 - 1) << 23) | (0 << 13) | (0 << 11) | (0 << 4)) & (1UL<<31)) == 0)) ||
         (((( (0 << 31) | ((4 - 1) << 23) | (0 << 13) | (0 << 11) | (0 << 4)) & (1UL<<13)) == 0) && ((( (0 << 31) | ((4 - 1) << 23) | (0 << 13) | (0 << 11) | (0 << 4)) & (1UL<<31)) != 0))   ) {
      while ((((SYSCTL_Type *) 0x400FE000UL)->RIS & (1UL<<6)) != (1UL<<6));                  
    }

    ((SYSCTL_Type *) 0x400FE000UL)->RCC  = (( ((4 - 1) << 23) | (1 << 22) | (1 << 20) | (7 << 17) | (0 << 13) | (0 << 11) | (21 << 6) | (0 << 4) | (1 << 1) | (0 << 1)));                                        
    ((SYSCTL_Type *) 0x400FE000UL)->RCC2 = (( (0 << 31) | ((4 - 1) << 23) | (0 << 13) | (0 << 11) | (0 << 4)));                                       
    for (i = 0; i < 10000; i++);    


}
