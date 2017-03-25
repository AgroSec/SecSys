//gpio_handler.h
#ifndef GPIO_HDL
#define GPIO_HDL
/*-------------------Type Includes-------------------*/
#include "custom_types.h"
/*-------------------Function Definitions-------------*/
void GPIO_steering_switch_init(void);
void GPIO_red_led_init(void);
void GPIO_red_led_toggle(void);
void GPIO_lcd_init(void);
void GPIO_lcd_DC(unsigned char DC);
void GPIO_lcd_RST(unsigned char RST);
void GPIO_motor_direction_init(void);
void GPIO_motor_direction_select(Motor_Direction_en direction);
void GPIO_accelerometer_CS_init(void);
void GPIO_accelerometer_CS_select(unsigned char CS);
#endif

//EOF
