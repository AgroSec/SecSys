//gpio_handler.h
#ifndef GPIO_HDL
#define GPIO_HDL

/*-----------------------OS Includes------------------*/
#include "os_hw.h"

/*-------------------Function Definitions-------------*/
#define GPIO_LOCK_KEY 0x4C4F434B
uint8_t GPIO_InitPortOutput(ports_t port, uint8_t pin);
uint8_t GPIO_SetPin(ports_t port, uint8_t pin, uint8_t status);
uint8_t GPIO_InitPortInput(ports_t port, uint8_t pin, uint16_t resistor);
#endif

//EOF
