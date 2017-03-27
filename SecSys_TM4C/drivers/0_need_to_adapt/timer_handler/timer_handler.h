//timer_handler.h
#ifndef TIME_HDL
#define TIME_HDL

/*-------------------Function Definitions-------------*/
void TIMER_cyclic_1s_init(void);
void TIMER_cyclic_50ms_init(void);
unsigned long TIMER_reload_calculator(unsigned long milli_seconds_requested);

void TIMER_delay(unsigned long delay_time_ms);
void TIMER_delay_No_Int(unsigned long delay_time_ms);

#endif
