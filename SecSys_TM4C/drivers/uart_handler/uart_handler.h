#ifndef UART_HDL
#define UART_HDL

/*--------------------Type Includes------------------*/
#include "stdbool.h"
#include "stdint.h"
/*-------------------Macro Definitions----------------*/
// standard ASCII symbols
#define CR   0x0D  //Cariege return
#define LF   0x0A  //Line feed
#define BS   0x08  //Backspace
#define ESC  0x1B
#define SP   0x20
#define DEL  0x7F
#define SUB  0x1A //Ctrl+Z

/*-----------External function definisions-----------*/
//UART0 functions
void UART0_Init(void);
void UART0_SendChar(uint8_t data);
void UART0_SendString(uint8_t *pt);
void UART0_SendUDecimal(uint32_t n);
void UART0_SendNumeric(int32_t n, uint16_t digits);
void UART0_SendUHex(uint32_t number);
void UART0_SendNewLine(void);
uint8_t UART0_GetChar(void);
void UART0_GetString(uint8_t *bufPt, uint16_t max);
uint32_t UART0_GetUDecimal(void);
uint32_t UART0_GetUHex(void);

//UART2 functions
void UART2_Init(void);
#endif
//EOF
