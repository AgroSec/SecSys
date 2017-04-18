/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"
/*------Export interface---Self header Includes------*/
#include "GSM.h"
/*-------------------Driver Includes-----------------*/
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
/*-----------------Application Includes---------------*/
#include "pc_display.h"

/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
#include "uart_handler.h"
#include "string.h"
#include "stdio.h"

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
char responseLine[6][160];  // Use to store UART inputs
static char *msgContent =  NULL;  // Message content holder
static char *msgSender =   NULL;  // Message sender
static char *msgDate =     NULL;  // Message date
static char *msgTime =     NULL;  // Message time

/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void SendCommandValue(uint8_t *str, uint32_t value){
	UART2_SendString(str);
	UART2_SendUDecimal(value);
	//TODO: Try also 	UART2_SendChar(LF);
	UART2_SendChar(CR);
}

void SendCommandString(uint8_t *str1, uint8_t *str2){
	UART2_SendString(str1);
	UART2_SendString(str2);
	//TODO: Try also 	UART2_SendChar(LF);
	UART2_SendChar(CR);
}

void PowerOnGSM(void){
//  TODO: Keep GSM module reset pin in the following states to reset it.
//  digitalWrite(GSM_Power_Pin, HIGH);
//  delay(1000);
//  digitalWrite(GSM_Power_Pin, LOW);
//  delay(7000);
	
	//SendCommandValue("AT+CMGF=",1);  //message format text
	UART2_SendString("AT+CMGF=1");  //message format text
	UART2_SendChar(CR);
	SysCtlDelay(Millis2Ticks(100)); //Interrupts are NOT disabled and OS is NOT stoped during delay!	
	
	UART2_SendString("AT+CMGD=1,4");  //delete all messages
	UART2_SendChar(CR);
	SysCtlDelay(Millis2Ticks(100));
	
	UART2_SendString("AT+CSDH=0");  //do not show complete message header
	UART2_SendChar(CR);
	SysCtlDelay(Millis2Ticks(100));
	
	UART2_SendString("AT+CNMI=0,0,0,0,1");  //set new message indication mode
	//Messages are stored on GSM module, no indication is provided
	//AT+CMGR=1,0 will read the messages in a cyclic manner
	UART2_SendChar(CR);
	SysCtlDelay(Millis2Ticks(100));
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







//*****************************************************************************
//
// PROCESS SMS FOR ENVELOPE AND CONTENT 
//
//*****************************************************************************
void 
GSMprocessMessage( uint8_t msgNum )
{
    bool msgPresent[4] = {0000};  // Flag to ignore deleted messages
    bool msgVerify = false;  // Flag for message error checking
    char msgErrorCheck[4][300];  // Holder for message error checking
    int lineCount=0;  // Hold the number of lines
    int oLoop;  // Counter for outside error checking loop
    int iLoop;  // Counter for inside error checking loop

    // Start message retrieval/parsing/error checking (runs simultaneously to
    // reduce calls to the SIM module).
    for ( oLoop=0; oLoop<3; oLoop++ )
    {
			// Request the message and get the lines of the response (includes 
			// envelope, nulls, SIM responses)
			SendCommandValue("AT+CMGR=",msgNum);
			SysCtlDelay(Millis2Ticks(1));
			lineCount = GSMgetResponse();

			// Delay for a bit, needed when processing multiple messages (maybe?)
			SysCtlDelay(Millis2Ticks(1));;

			// Make sure there's message content, process for envelope and content
			msgPresent[oLoop] = GSMparseMessage( lineCount );

			// If there is a message, store it, see if it matches previous retrieval loop
			if (msgPresent[oLoop])
			{
				// Store the message to one big string
				sprintf(msgErrorCheck[oLoop], "%s%s%s%s", msgSender, msgDate, msgTime, msgContent);

				// Check that string against previous copies from outer loop
				for ( iLoop = 0; iLoop < oLoop; iLoop++ ) 
				{
					if (strstr(msgErrorCheck[oLoop],msgErrorCheck[iLoop]) != NULL){

						// Set a flag to use for exiting outer loop
						msgVerify = true;

						// Exit inner loop
						break;
					}
				}
			}

			// If there's no message, exit retrieval loop
			else { break; }

			// If we verified the message, exit retrieval loop
			if (msgVerify) { break; }
    }

    // Show the user what we found
		PC_Display_Message("\n\r>>> MESSAGE :",msgNum," ");
    //UART0printf("\n\r>>> MESSAGE %u:",msgNum);
    if ( msgPresent[oLoop] && msgVerify ) {
			PC_Display_Message("> FROM :",0,msgSender);  //TODO: Try to send a BS to delete the 0
			PC_Display_Message("> AT :",0,msgDate);			
			PC_Display_Message("> ON :",0,msgTime);
			PC_Display_Message("> TEXT :",0,msgContent);			
			//UART0printf("\n\r> FROM: %s ON: %s AT: %s",msgSender,msgDate,msgTime);
			//UART0printf("\n\r> TEXT: %s",msgContent);
    }
    else if (!msgPresent[oLoop]) { 
			PC_Display_Message("> NOT PRESENT!",0,"");
			//UART0printf("\n\r> NOT PRESENT!");
		}
    else {
			PC_Display_Message("> COULD NOT VERIFY! ",0," ");
			//UART0printf("\n\r> COULD NOT VERIFY!");
		}

    // Delete the message
    if ( testDelete && !(*msgPresent) ){
			SendCommandValue("AT+CMGD=",msgNum);
			//UART1printf("AT+CMGD=%u\r\n",msgNum);
			GSMgetResponse();
			PC_Display_Message(">>> MESSAGE ",msgNum," DELETED");
			//UART0printf ( "\n\r>>> MESSAGE %u DELETED",msgNum );
    }
}

//*****************************************************************************
//
// STORE A GSM RESPONSE TO ARRAY responseLine[]
//
//*****************************************************************************
uint8_t GSMgetResponse(void) {
bool readResponse = true;  // Keeps the loop open while getting message
uint8_t readLine = 0;  // Counts the lines of the message
char *GSMresponse = NULL;  // Use to grab input TODO, allocate statically memory
//char GSMresponse[160] = "";  // Use to grab input TODO, allocate statically memory
static char g_cInput[160];  // String input to a UART
	while(readResponse&&(readLine<6)) {
		// Grab a line
		UART2_GetString(g_cInput,sizeof(g_cInput));  //grabs string untill character != CR or LF
		//UART1gets(g_cInput,sizeof(g_cInput));

		// Stop after newline
		GSMresponse = strtok(g_cInput,"\n");  //TODO test what is the output of this line
		strcpy(responseLine[readLine],/*g_cInput*/ GSMresponse);

		// If this line says OK we've got the whole message
		if ( strncmp(responseLine[readLine],"OK",2) == 0 ){readResponse = false;}
		else { readLine++; }
	}
	return (readLine+1);  //because [0] is first line #LOL
}

//*****************************************************************************
//
// PARSE GSM MESSAGE FOR ENVELOPE AND MESSAGE CONTENT
// Stores message envelope and constant to global variables, OR returns true
// for message present, false for no message
//
//*****************************************************************************
bool GSMparseMessage(uint8_t lineCount) {
uint8_t activeLine = 1;             // Counter for line being processed
uint8_t *msgEnvelope = NULL;       // Message envelope holder
const uint8_t commaCh[] = ",";     // Comma character

	// Clear out the old message
	msgContent = NULL;

	// Parse the new message
	while ( activeLine < lineCount+1 )
	{
			// CASE FOR ENVELOPE (which will look like:)
			// +CMGR: "REC READ","+13158078555","","15/10/08,13:18:40-20"
			if ( strstr(responseLine[activeLine],"+CMGR:") != '\0' )  //if message received
			{
					// Start parsing
					msgEnvelope = responseLine[activeLine];

					// Go to first comma, skipping status
					msgSender = strtok(msgEnvelope,",");

					// Grab the number
					msgSender = strtok(NULL,commaCh);

					// Go to next comma, skipping phonebook entry
					msgDate = strtok(NULL,commaCh);

					// Grab the date
					msgDate = strtok(NULL,commaCh);

					// Grab the time
					msgTime = strtok(NULL,commaCh);

					// Store the number (with null terminator)
					//strncpy(msgSender,msgSender+2,11);
					msgSender += 2;  // Skip the "+1" prefix from the phone number.
					msgSender[10] = '\0';  //TODO try index [11] if 10 fails

					// Store the date (with null terminator)
					//strncpy(msgDate,msgDate+1,8);
					msgDate[8] = '\0';

					// Store the time (with null terminator)
					//strncpy(msgTime,msgTime,8);
					msgTime[8] = '\0';
			}

			// CASE FOR MESSAGE CONTENT
			// If we already found the envelope, and the line's not blank...
			else if ( msgEnvelope != NULL && responseLine[activeLine] != NULL )
			{
					// ... and we haven't found any content, this is the first line.
					if (msgContent == NULL) { msgContent = responseLine[activeLine]; }

					// ... otherwise, add a space and append this line.
					else if ( activeLine + 2 <= lineCount ) {  //TODO see why +2 ???
							strcat(msgContent, " ");
							strcat(msgContent, responseLine[activeLine]);
					}
			}
			// Proceed to next line
			activeLine++;
	}
	if (msgEnvelope == NULL) { // If we didn't find an envelope, there's no message
		return false;
	}
	else { 	// Otherwise, return true.
		return true;
	}
}

//*****************************************************************************
//
// MAIN FUNCTION
// Waits for message notification from UART interrupt, and initiates processing
//
//*****************************************************************************
/*
int main (void){
    int msgOpen = 0;                    // Message being processed

    while(1){
        // Process new messages.
        while (msgCount > 0)
        {
            // Start working on the oldest message
            msgOpen = msgCount;
            msgCount--;

            // Process message for envelope and content
            GSMprocessMessage(msgOpen);
        }
    }*/
