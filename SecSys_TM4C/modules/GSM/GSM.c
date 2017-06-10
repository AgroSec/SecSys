/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"
/*------Export interface---Self header Includes------*/
#include "GSM.h"
/*-------------------Driver Includes-----------------*/
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "inc/hw_memmap.h"
/*-----------------Application Includes---------------*/
#include "pc_display.h"

/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
#include "uart_handler.h"
#include "utils\uartstdio.h"
#include "string.h"
#include "stdio.h"

/*-------------------Macro Definitions----------------*/
#define DELETE_ALL_SMS (1)  //Delete all SMS on startup (Disable for testing)
#define RESONSE_MAX_LINE (15)  //Max number of lines for a response message (ussually 12 is enaugh)
#define RESONSE_MAX_LENGHT (160)
#define SHOW_STARTUP_INFO (1)  //Show information during startup
#define SHOW_READING_INFO (0)  //Show message information during reading
#define SHOW_PARSING_INFO (0)  //Show message information during parsing
#define SHOW_FINAL_INFO (1)  //Show message information after processing
#define MESSAGE_READ_REAPEATS (5)  //Read message 5 times to get the valid response

/*-------------Global Variable Definitions------------*/
extern uint32_t Count0_PIRA;  // number of times Task0 loops
extern uint32_t Count1_PIRB;  // number of times Task1 loops
extern uint32_t Count8_Blank; //increments every minute
extern uint32_t PIR_A_Alarm_Nr;
extern uint32_t PIR_B_Alarm_Nr;

bool testDelete = 1;  // Delete messages during processing
int msgCount = 0;  // Hold the int value w/count of new messages
//TODO  // (Set by UART interrupt handler)

// Data from most recent incoming message stored here
char responseLine[RESONSE_MAX_LINE][RESONSE_MAX_LENGHT];  // Use to store UART inputs
static char *msgContent = NULL;  // Message content holder
static char *msgSender = NULL;  // Message sender
static char *msgDate = NULL;  // Message date
static char *msgTime = NULL;  // Message time
static uint8_t msgReadRepeatIndex = 0;
char *GSMcommand[MESSAGE_READ_REAPEATS];

/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void SyncWithGSM(void){
	UARTprintf("AT\n");
	while ((UARTgetc()!='O')&&(UARTgetc()!='K')){}; //Wait for OK response
}
void PowerOnGSM(void){
//  TODO: Keep GSM module reset pin in the following states to reset it.
//  digitalWrite(GSM_Power_Pin, HIGH);
//  delay(1000);
//  digitalWrite(GSM_Power_Pin, LOW);
//  delay(7000);
	uint8_t lineCount = 0;
	SyncWithGSM();
	
	//Setup message format: TEXT
	UARTprintf("AT+CMGF=%u\n",1);
	SysCtlDelay(Millis2Ticks(100));
	
	//Setup message header display: OFF
	UARTprintf("AT+CSDH=%u\n",0);
	SysCtlDelay(Millis2Ticks(100));

	//Setup new message indication: OFF
	//Messages are stored on GSM module, no indication is provided
	//AT+CMGR=1 will read the messages when user triggers GSMprocessMessage(msgNum)
	UARTprintf("AT+CNMI=%u%u%u%u%u\n",0,0,0,0,1);
	SysCtlDelay(Millis2Ticks(100));
	
#if DELETE_ALL_SMS
	UARTprintf("AT+CMGD=1,4\r");
	SysCtlDelay(Millis2Ticks(100));
#endif	

	UARTFlushRx();
	
#if SHOW_STARTUP_INFO
	UART0_SendString((uint8_t*)"GSM init done...");
#endif
}

void SendSMS(SMS_Message_en message){
	UART2_SendString("AT+CMGS=\"0751538300\"");  //set the mobile number to send the SMS
	//UART2_SendNewLine();
	UART2_SendChar(CR);
	//UART2_SendChar(LF);
	SysCtlDelay(Millis2Ticks(100)); //Interrupts are NOT disabled and OS is NOT stoped during delay!
  switch (message) {
		case PIR_A:
			#if PIR_AVAILABLE
			UART2_SendString("PIR A Trigger Nr: ");  //The SMS text you want to send
			UART2_SendUDecimal(Count0_PIRA);
			UART2_SendNewLine();
			UART2_SendString("PIR A Alarm Nr: ");
			UART2_SendUDecimal(PIR_A_Alarm_Nr);
			#endif
			break;
		case PIR_B:
			#if PIR_AVAILABLE
			UART2_SendString("PIR B Trigger Nr: ");
			UART2_SendUDecimal(Count1_PIRB);
			UART2_SendNewLine();
			UART2_SendString("PIR B Alarm Nr: ");
			UART2_SendUDecimal(PIR_B_Alarm_Nr);
			#endif
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
			//Send security system status
			#if PIR_AVAILABLE
			UART2_SendString("Status:");
			UART2_SendNewLine();
			UART2_SendUDecimal(0);
			UART2_SendString("TODO minutes");
			UART2_SendNewLine();
			UART2_SendString("PIR A ");
			UART2_SendUDecimal(Count0_PIRA);
			UART2_SendNewLine();
			UART2_SendString("PIR B ");
			UART2_SendUDecimal(Count1_PIRB);
			UART2_SendNewLine();
			#endif
			//TODO
			//Active_System
			//Active_Alarm
			//Wire Guard State
			//PIR State
			break;
		case System_Ready:
			//System startup delay completed
			UART2_SendString("System setup ready...");
			break;
		case Wrong_Command:
			//Wrong SMS command received
			UART2_SendString("Wrong Command. (1)Deactivate Security. (2)Deactivate Alarm. (3)Trigger Alarm. (4)Get Status");
			break;
		default:
			UART2_SendString("Something misterious happened");
	}
	UART2_SendChar(SUB);  //ASCII code of CTRL+Z indicating end of message
	PC_Display_Message("SMS sent with message ID: ",(uint8_t)message," ->");
}

void GSMgetCommand(uint8_t *command,uint8_t msgId){
	uint8_t i,j = 0;
	char c;
	GSMprocessMessage(msgId);
}

//*****************************************************************************
//
// PROCESS SMS FOR ENVELOPE AND CONTENT 
//
//*****************************************************************************
void GSMprocessMessage(uint8_t msgNum) {	
	static uint8_t first_execution = 1;
	bool msgPresent = 0;  // Flag to ignore deleted messages
	int lineCount=0;  // Hold the number of lines
	char message[200];
	char continue_reading = 1;
	char index = 0;
	uint32_t time = 500000;
	
	// Start message retrieval/parsing/error checking (runs simultaneously to
	// reduce calls to the SIM module).
	// Request the message and get the lines of the response (includes envelope, nulls, SIM responses)
	//PC_Display_Message("> Processing message :",msgNum," ");
	UARTprintf("AT+CMGR=%u\n",msgNum);
	if(!first_execution) {
		SysCtlDelay(Millis2Ticks(1));
		lineCount = GSMgetResponse();
		// Make sure there's message content, process for envelope and content
		msgPresent = GSMparseMessage(lineCount);

		if (msgPresent) {
			#if SHOW_FINAL_INFO
			PC_Display_Message("> FROM :",0,msgSender);  //TODO: Try to send a BS to delete the 0
			PC_Display_Message("> AT :",0,msgDate);			
			PC_Display_Message("> ON :",0,msgTime);
			PC_Display_Message("> TEXT :",0,msgContent);
			SysCtlDelay(Millis2Ticks(100));		
			UARTprintf("AT+CMGD=1,4\r");
			UARTprintf("AT+CMGDA=\"DEL ALL\"");
			SysCtlDelay(Millis2Ticks(100));
			PC_Display_Message("> Message deleted!!!",0,"");
			#endif
		}
		//else PC_Display_Message("> NOT PRESENT!",0," ");
	}
	first_execution = 0;
}

//*****************************************************************************
//
// STORE A GSM RESPONSE TO ARRAY responseLine[]
//
//*****************************************************************************
uint8_t GSMgetResponse(void) {
bool readResponse = true;  // Keeps the loop open while getting message
int readLine = 0;  // Counts the lines of the message
char g_cInput[RESONSE_MAX_LENGHT];  // String input to a UART
	
	while(readResponse&&(readLine<RESONSE_MAX_LINE)) {  //TODO, do not hardcode, use macro
		// Grab a line
		if(UARTRxBytesAvail() > 2) UARTgets(g_cInput,sizeof(g_cInput));  //TODO test smaller FIFI levels
		// Stop after: \n, \r, ESC, LF, CR, 
#if SHOW_READING_INFO
		PC_Display_Message(">>> Line nr: ", readLine, g_cInput);
#endif
		strcpy(responseLine[readLine],g_cInput);
		
		// If this line says OK or ERROR we've got the whole message
		if((strncmp(responseLine[readLine],"OK",2)==0)||
			 (strncmp(responseLine[readLine],"ERROR",5)==0)){
			readResponse = false;
		}
		else readLine++;
	}
	return (readLine+1);
}

//*****************************************************************************
//
// PARSE GSM MESSAGE FOR ENVELOPE AND MESSAGE CONTENT
// Stores message envelope and constant to global variables, OR returns true
// for message present, false for no message
//
//*****************************************************************************
bool GSMparseMessage(uint8_t lineCount) {
uint8_t activeLine = 0;  // Counter for line being processed
char *msgEnvelope = NULL;  // Message envelope holder

	msgContent = NULL; // Clear out the old message
	// Parse the new message
	while (activeLine < lineCount) //lineCount is larger by 1 than responseLine [index]
	{
		// CASE FOR ENVELOPE (which will look like:)
		// +CMGR: "REC READ","+40758438903","","17/04/12,22:53:48+12"
		if ( strstr(responseLine[activeLine],"+CMGR:") != '\0' )  //if message received
		{
			// Start parsing
			msgEnvelope = responseLine[activeLine];
				
			msgSender = strtok(msgEnvelope,",");  // Go to first comma, skipping status
			msgSender = strtok(NULL,",");  // Grab the number	
			msgSender += 3;  // Skip the prefix from the phone number and qautation marks
			msgSender[10] = '\0';  // Store the number (with null terminator)

			msgDate = strtok(NULL,",");  // Go to next comma, skipping phonebook entry
			msgDate = strtok(NULL,",");  // Grab the date
			msgDate += 1;  //remove qautation marks
			msgDate[8] = '\0';  // Store the date (with null terminator)
			
			msgTime = strtok(NULL,",");  // Grab the time
			msgTime[8] = '\0';  // Store the time (with null terminator)
		}

		// CASE FOR MESSAGE CONTENT
		// If we already found the envelope, and the line's not blank...
		else if ( msgEnvelope != NULL && responseLine[activeLine] != NULL )
		{
			if((responseLine[activeLine] != "\n")&&
				 (responseLine[activeLine] != "\0")&&
				 (responseLine[activeLine] != " ")) {
				// ... and we haven't found any content, this is the first line.
				if (msgContent == NULL) msgContent = responseLine[activeLine];

				// ... otherwise, add a space and append this line.
				else if ( activeLine + 2 <= lineCount ) {  //+2 because of emply line before OK and last line with OK.
					strcat(msgContent, " ");
					strcat(msgContent, responseLine[activeLine]);
				}
			}
		}
		activeLine++; // Proceed to next line
	}
#if SHOW_PARSING_INFO			
	PC_Display_Message("> Envelope is: ",0,msgEnvelope);			
	PC_Display_Message(">>> Sender is: ",0,msgSender);			
	PC_Display_Message(">>> Date is: ",0,msgDate);			
	PC_Display_Message(">>> Time is: ",0,msgTime);
	PC_Display_Message(">>> Content is: ",0,msgContent);
#endif		

	if (msgEnvelope == NULL) { // If we didn't find an envelope, there's no message
		return false;
	}
	else { 	// Otherwise, return true.
		return true;
	}
}
//EOF
