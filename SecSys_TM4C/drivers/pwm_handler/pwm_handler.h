//pwm_handler.h
//Service layer
#ifndef PWM_HDL
#define PWM_HDL

void PWM_motor_init(unsigned long PWM_Period);
void PWM_right_motor_duty_cycle(unsigned long PWM_duty_cycle);
void PWM_left_motor_duty_cycle(unsigned long PWM_duty_cycle);
void PWM_Red_led_init(unsigned long PWM_Period);
void PWM_Red_led_toggle(void);

//void PWM_motor_reverse_stop(void);
//void PWM_set_duty_cycle(unsigned long PWM_Base, unsigned long PWM_Generator, unsigned long PWM_Output, unsigned long PWM_duty_cycle);
//void PWM_motor_reverse_init(unsigned long PWM_Period, unsigned short PWM_duty_cycle);
#endif 
