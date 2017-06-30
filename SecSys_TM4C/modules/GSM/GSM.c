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
#define SEND_SMS (1)  //Disable SMS Sending
#define RECEIVE_SMS (0)  //Disable SMS Receiving
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
extern int16_t Global_Temp1;
extern int16_t Global_Temp2;

bool testDelete = 1;  // Delete messages during processing

#if RECEIVE_SMS
// Data from most recent incoming message stored here
char responseLine[RESONSE_MAX_LINE][RESONSE_MAX_LENGHT];  // Use to store UART inputs
static char *msgContent = NULL;  // Message content holder
static char *msgSender = NULL;  // Message sender
static char *msgDate = NULL;  // Message date
static char *msgTime = NULL;  // Message time
#endif

/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void SyncWithGSM(void){
	UARTprintf("AT\n");
	while ((UARTgetc()!='O')&&(UARTgetc()!='K')){}; //Wait for OK response
}
void PowerOnGSM(void){
	/*
	TODO: Keep GSM module reset pin in the following states to reset it.
	GSM_Power_Pin = High -> wait 1 second
	GSM_Power_Pin = Low -> WaitForInterrupt 7 seconds
	*/
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
	UARTprintf("AT+CMGD=1,4\n");
	SysCtlDelay(Millis2Ticks(100));
#endif	

	UARTFlushRx();
	
#if SHOW_STARTUP_INFO
	UART0_SendString((uint8_t*)"GSM init done...");
#endif
}

void SendSMS(SMS_Message_en message){
	#if SEND_SMS
	UARTprintf("AT+CMGF=\"%s\"\n",ORANGE_300);  //set the mobile number to send the SMS
	SysCtlDelay(Millis2Ticks(100)); //Interrupts are NOT disabled and OS is NOT stoped during delay!
	switch (message) {
		#if PIR_AVAILABLE		
		case PIR_A:
			UARTprintf("PIR A Trigger Nr: %d\n",Count0_PIRA);
			UARTprintf("PIR A Alarm Nr: %d\n",PIR_A_Alarm_Nr);	
			break;
		case PIR_B:
			UARTprintf("PIR B Trigger Nr: %d\n",Count1_PIRB);
			UARTprintf("PIR B Alarm Nr: %d\n",PIR_B_Alarm_Nr);
			break;
		#endif
		
		#if HX711_AVAILABLE
		case Wire_1_Pull:
			UARTprintf("Wire 1 Pulled\n");
			break;
		case Wire_1_Cut:
			UARTprintf("Wire 1 Cut\n");
			break;
		case Wire_2_Pull:
			UARTprintf("Wire 2 Pulled\n");
			break;
		case Wire_2_Cut:
			UARTprintf("Wire 2 Cut\n");
			break;
		case Wire_3_Pull:
			UARTprintf("Wire 3 Pulled\n");
			break;
		case Wire_3_Cut:
			UARTprintf("Wire 3 Cut\n");
			break;
		#endif
		
		case Status: 
			//Send security system status
			UARTprintf("Status:\n");
			
			#if PIR_AVAILABLE
			//Report number of alarms
			UARTprintf("PIR A: %d\n",PIR_A_Alarm_Nr);
			UARTprintf("PIR B: %d\n",PIR_B_Alarm_Nr);
			#endif
			
			#if TEMP_AVAILABLE
			//Report temperature readings
			//TODO replace Temp* with global variable from temperature reading 
			UARTprintf("Temp 1: %d *C\n", Global_Temp1);
			UARTprintf("Temp 2: %d *C\n", Global_Temp2);
			#endif
	
			#if HX711_AVAILABLE
			//Report Wire Guard State
			//TODO report number of triggers
			#endif
		
			//Active_System
			//Active_Alarm
			break;
		case System_Ready:
			//System startup delay completed
			UARTprintf("System setup ready...");
			break;
		case Wrong_Command:
			//Wrong SMS command received
			UARTprintf("Wrong Command. (1)Deactivate Security. (2)Deactivate Alarm. (3)Trigger Alarm. (4)Get Status");
			break;
		default:
			UARTprintf("Something misterious happened");
	}
	//UART2_SendChar(SUB);  //ASCII code of CTRL+Z indicating end of message
	UARTprintf("%c",SUB);
	PC_Display_Message("SMS sent with message ID: ",(uint8_t)message," ->");
	#endif
}

void GSMgetCommand(uint8_t *command,uint8_t msgId){
	GSMprocessMessage(msgId);
}

//*****************************************************************************
//
// PROCESS SMS FOR ENVELOPE AND CONTENT 
//
//*****************************************************************************
void GSMprocessMessage(uint8_t msgNum) {
	#if RECEIVE_SMS
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
			UARTprintf("AT+CMGD=1,4\n");  //AleGaa maybe \r
			UARTprintf("AT+CMGDA=\"DEL ALL\"\n");
			SysCtlDelay(Millis2Ticks(100));
			PC_Display_Message("> Message deleted!!!",0,"");
			#endif
		}
		//else PC_Display_Message("> NOT PRESENT!",0," ");
	}
	first_execution = 0;
	#endif
}

//*****************************************************************************
//
// STORE A GSM RESPONSE TO ARRAY responseLine[]
//
//*****************************************************************************
uint8_t GSMgetResponse(void) {
	#if RECEIVE_SMS
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
	#else
	return 0;
	#endif
}

//*****************************************************************************
//
// PARSE GSM MESSAGE FOR ENVELOPE AND MESSAGE CONTENT
// Stores message envelope and constant to global variables, OR returns true
// for message present, false for no message
//
//*****************************************************************************
bool GSMparseMessage(uint8_t lineCount) {
	#if RECEIVE_SMS
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
	#else
	return false;
	#endif
}
//EOF
