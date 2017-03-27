#ifndef INT_HDL
#define INT_HDL

/*-------------------Function Definitions-------------*/
void Int_Master_Enable(void);
void Int_Master_Disable(void);
void Int_Peripherials_Enable(void);
#endif

/*-------------------Trash code area-----------------*/
//void DisableInterrupts(void); // Disable interrupts
//void EnableInterrupts(void);  // Enable interrupts
//long StartCritical (void);    // previous I bit, disable interrupts
//void EndCritical(long sr);    // restore I bit to previous value
//void WaitForInterrupt(void);  // low power mode
