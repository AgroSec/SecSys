#ifndef UART_HDL
#define UART_HDL

/*--------------------Type Includes------------------*/
#include "stdbool.h"
#include "stdint.h"

/*-------------------Macro Definitions----------------*/
// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1
// standard ASCII symbols
#define CR   0x0D
#define LF   0x0A
#define BS   0x08
#define ESC  0x1B
#define SP   0x20
#define DEL  0x7F
#define SUB  0x1A //Ctrl+Z

#define BAUD_RATE (115200)
#define GSM_BAUD_RATE (9600) //TODO test with faster baud rates
/*-----------External function definisions-----------*/
//UART0 functions
void UART0_Init(void);
void UART0_SendChar(uint8_t data);
void UART0_SendString(uint8_t *pt);
void UART0_SendUDecimal(uint32_t n);
void UART0_SendDecimal(int32_t n);
void UART0_SendFloat2(int32_t n);
void UART0_SendFloat3(int32_t n);
void UART0_SendUHex(uint32_t number);
void UART0_SendNewLine(void);
uint8_t UART0_GetChar(void);
void UART0_GetString(uint8_t *bufPt, uint16_t max);
uint32_t UART0_GetUDecimal(void);
uint32_t UART0_GetUHex(void);

//UART2 functions
void UART2_Init(void);
void UART2_SendChar(uint8_t data);
void UART2_SendString(uint8_t *pt);
void UART2_SendUDecimal(uint32_t n);
void UART2_SendDecimal(int32_t n);
void UART2_SendUHex(uint32_t number);
void UART2_SendNewLine(void);
uint8_t UART2_GetChar(void);
void UART2_GetString(uint8_t *bufPt, uint16_t max);
uint32_t UART2_GetUDecimal(void);
uint32_t UART2_GetUHex(void);
#endif
//EOF
