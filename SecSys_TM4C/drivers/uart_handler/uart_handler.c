/*------------------Project Includes-----------------*/
#include <math.h>
#include "uart_handler.h"
#include "pc_display.h"
#include "os_config.h"
#include "os_core.h"
/*-------------------Driver Includes-----------------*/
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
/*-------------------HW define Includes--------------*/
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "utils/uartstdio.h"
/*-------------------Macro Definitions----------------*/
// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1

#define BAUD_RATE (115200)
#define GSM_BAUD_RATE (115200)
#define GSM_UART_PORT (2)

#define UART2_INT_PRIO (2)

#define GPIO_PORTD_LOCK_R       (*((volatile uint32_t *)0x40007520))
#define GPIO_PORTD_CR_R         (*((volatile uint32_t *)0x40007524))

/*-------------Global Variable Definitions------------*/
extern int32_t SMSReceived;
uint32_t Baud_Rate_Read = 0;
uint32_t GSM_Baud_Rate_Read = 0;
extern void UARTStdioIntHandler(void);

//*****************************************************************************
//
// UART0 SPECIFIC FUNCTIONS
//
//*****************************************************************************
void UART0_Init(void){
	uint32_t uart_config_read = 0;
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);  //Enable clock on UART0
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);  //Enable clock on port A  //PA0 and PA1 is hard wired to debugger and USB
	UARTDisable(UART0_BASE);  //Disable UART0 while configuration
	
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1); //AleGaa PA0
	UARTClockSourceSet(UART0_BASE, UART_CLOCK_SYSTEM);  //Set the clock source for UART0
	//Next: Set the BAUD RATE, and configure UART0 with 8 data bits, 1 stop bit and no parity bit
	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), BAUD_RATE, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |UART_CONFIG_PAR_NONE));  
	UARTFIFOEnable(UART0_BASE);  //Enable the UART FIFO
	UARTEnable(UART0_BASE);  //Enable UART0
	UARTConfigGetExpClk(UART0_BASE, SysCtlClockGet(), &Baud_Rate_Read, &uart_config_read);  //Get the Baud Rate
}

void UART0_SendChar(uint8_t data){
	UARTCharPut(UART0_BASE, data);
}

void UART0_SendString(uint8_t *pt){
	while(*pt) { //While not the end of the string
		UART0_SendChar(*pt);  //display current character
		pt++;  //move to next character
	}
}

void UART0_SendUDecimal(uint32_t n){
// This function uses recursion to convert an unsigned decimal number
//   of unspecified length as an ASCII string
	if(n >= 10){
		UART0_SendUDecimal(n/10);
		n = n%10;
  }
  UART0_SendChar(n+'0'); /* n is between 0 and 9 */
}

void UART0_SendNumeric(int32_t n, uint16_t digits)
{	// function used to send numbers to uart0;
	// accepts signed integers and also floating 
	// point (by using and integer multiplied by 10^digits)
	if (n < 0) 
		UART0_SendChar('-');

	if (digits <= 0)
		UART0_SendUDecimal(n);
	else 
	{
		UART0_SendUDecimal(n / (uint32_t)pow(10, digits));
		UART0_SendChar('.');
		UART0_SendUDecimal(n % (uint32_t)pow(10, digits));		
	}
}

void UART0_SendUHex(uint32_t number){
// This function uses recursion to convert the number of
//   unspecified length as an ASCII string
  if(number >= 0x10){
    UART0_SendUHex(number/0x10);
    UART0_SendUHex(number%0x10);
  }
  else{
    if(number < 0xA){
      UART0_SendChar(number+'0');
     }
    else{
      UART0_SendChar((number-0x0A)+'A');
    }
  }
}

void UART0_SendNewLine(void){
  UART0_SendChar(CR);
  UART0_SendChar(LF);
}

uint8_t UART0_GetChar(void){
	return (uint8_t)UARTCharGet(UART0_BASE);
}

//------------UART0_GetString------------
// Accepts ASCII characters from the serial port
//    and adds them to a string until <enter> is typed
//    or until max length of the string is reached.
// It echoes each character as it is inputted.
// If a backspace is inputted, the string is modified
//    and the backspace is echoed
// terminates the string with a null character
// uses busy-waiting synchronization on RDRF
// Input: pointer to empty buffer, size of buffer
// Output: Null terminated string
// -- Modified by Agustinus Darmawan + Mingjie Qiu --
void UART0_GetString(uint8_t *bufPt, uint16_t max) {
int length=0;
char character;
  character = UART0_GetChar();
  while(character != CR){
    if(character == BS){
      if(length){
        bufPt--;
        length--;
        UART0_SendChar(BS);
      }
    }
    else if(length < max){
      *bufPt = character;
      bufPt++;
      length++;
      UART0_SendChar(character);
    }
    character = UART0_GetChar();
  }
  *bufPt = 0;
}

//------------UART0_GetUDecimal------------
// InUDec accepts ASCII input in unsigned decimal format
//     and converts to a 32-bit unsigned number
//     valid range is 0 to 4294967295 (2^32-1)
// Input: none
// Output: 32-bit unsigned number
// If you enter a number above 4294967295, it will return an incorrect value
// Backspace will remove last digit typed
uint32_t UART0_GetUDecimal(void){
uint32_t number=0, length=0;
char character;
  character = UART0_GetChar();
  while(character != CR){ // accepts until <enter> is typed
// The next line checks that the input is a digit, 0-9.
// If the character is not 0-9, it is ignored and not echoed
    if((character>='0') && (character<='9')) {
      number = 10*number+(character-'0');   // this line overflows if above 4294967295
      length++;
      UART0_SendChar(character);
    }
// If the input is a backspace, then the return number is
// changed and a backspace is outputted to the screen
    else if((character==BS) && length){
      number /= 10;
      length--;
      UART0_SendChar(character);
    }
    character = UART0_GetChar();
  }
  return number;
}

//---------------------UART0_GetUHex----------------------------------------
// Accepts ASCII input in unsigned hexadecimal (base 16) format
// Input: none
// Output: 32-bit unsigned number
// No '$' or '0x' need be entered, just the 1 to 8 hex digits
// It will convert lower case a-f to uppercase A-F
//     and converts to a 16 bit unsigned number
//     value range is 0 to FFFFFFFF
// If you enter a number above FFFFFFFF, it will return an incorrect value
// Backspace will remove last digit typed
uint32_t UART0_GetUHex(void){
uint32_t number=0, digit, length=0;
char character;
  character = UART0_GetChar();
  while(character != CR){
    digit = 0x10; // assume bad
    if((character>='0') && (character<='9')){
      digit = character-'0';
    }
    else if((character>='A') && (character<='F')){
      digit = (character-'A')+0xA;
    }
    else if((character>='a') && (character<='f')){
      digit = (character-'a')+0xA;
    }
// If the character is not 0-9 or A-F, it is ignored and not echoed
    if(digit <= 0xF){
      number = number*0x10+digit;
      length++;
      UART0_SendChar(character);
    }
// Backspace outputted and return value changed if a backspace is inputted
    else if((character==BS) && length){
      number /= 0x10;
      length--;
      UART0_SendChar(character);
    }
    character = UART0_GetChar();
  }
  return number;
}

//*****************************************************************************
//
// UART2 SPECIFIC FUNCTIONS
// UART2 is configured to use the utils/uartstdio.h library
// this library has to be configured to work in BUFFERED mode
// ex. SW fifo between application and HW UART fifo
// To send data use: UARTprintf("string to send");
// To receive data use: UARTgets(stringVar ,sizeof(stringVar));
//
//*****************************************************************************
void UART2_Init(void){
	uint32_t uart_config_read = 0;
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);  //Enable clock on UART2
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);  //Enable clock on port D  //PD6 and PD7 will be RX and TX to GSM module
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART2));  //wait for UART2 to initialize
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));  //wait for PortD to initialize
	
	GPIO_PORTD_LOCK_R = 0x4C4F434B;  //Unlock GPIO PD7
	GPIO_PORTD_CR_R |= 0xC0;  //Allow changes to PD6,7
	
	IntDisable(INT_UART2);
	UARTIntDisable(UART2_BASE,UART_INT_RX|UART_INT_TX|UART_INT_RT);  //Disable UART2 Interrupts
	UARTDisable(UART2_BASE);  //Disable UART2 while configuration
	
	GPIOPinConfigure(GPIO_PD6_U2RX);  //PCTL
	GPIOPinConfigure(GPIO_PD7_U2TX);
	GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);  //DIR, PAD, 
	
	UARTClockSourceSet(UART2_BASE, UART_CLOCK_SYSTEM);  //Set the clock source for UART2
	//Next: Set the BAUD RATE, and configure UART2 with 8 data bits, 1 stop bit and no parity bit
	UARTParityModeSet(UART2_BASE, UART_CONFIG_PAR_NONE);
	UARTFIFOEnable(UART2_BASE);  //Enable the UART FIFO

	UARTStdioConfig(GSM_UART_PORT, GSM_BAUD_RATE, SysCtlClockGet());
	UARTEchoSet(false);
	UARTIntRegister(UART2_BASE,&UARTStdioIntHandler);
	UARTConfigGetExpClk(UART2_BASE, SysCtlClockGet(), &GSM_Baud_Rate_Read, &uart_config_read);  //Get the Baud Rate
}

void UART2_DirectSendChar(uint8_t data){
	UARTCharPut(UART2_BASE, data);
}

void UART2_DirectSendString(uint8_t *pt){
	while(*pt) { //While not the end of the string
		UART2_DirectSendChar(*pt);  //send current character
		pt++;  //move to next character
	}
}

//EOF
