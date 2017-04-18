bool testDelete =   0;              // Delete messages during processing
int msgCount = 0;                   // Hold the int value w/count of new messages
                                    // (Set by UART interrupt handler)

// Data from most recent incoming message stored here
char responseLine[10][75];          // Use to store UART inputs
char *msgContent =  NULL;           // Message content holder
char *msgSender =   NULL;           // Message sender
char *msgDate =     NULL;           // Message date
char *msgTime =     NULL;           // Message time

//*****************************************************************************
//
// PROCESS SMS FOR ENVELOPE AND CONTENT 
//
//*****************************************************************************
void 
GSMprocessMessage( int msgNum )
{
    bool msgPresent[4] = {0000};    // Flag to ignore deleted messages
    bool msgVerify = false;         // Flag for message error checking
    char msgErrorCheck[4][225];     // Holder for message error checking
    int lineCount;                  // Hold the number of lines
    int oLoop;                      // Counter for outside error checking loop
    int iLoop;                      // Counter for inside error checking loop

    // Start message retrieval/parsing/error checking (runs simultaneously to
    // reduce calls to the SIM module).
    for ( oLoop=0; oLoop<3; oLoop++ )
    {
        // Request the message and get the lines of the response (includes 
        // envelope, nulls, SIM responses)
        UART1printf("AT+CMGR=%u\r\n",msgNum);
        lineCount = GSMgetResponse();

        // Delay for a bit, needed when processing multiple messages (maybe?)
        ROM_SysCtlDelay(ROM_SysCtlClockGet()/160);

        // Make sure there's message content, process for envelope and content
        msgPresent[oLoop] = GSMparseMessage( lineCount );

        // If there is a message, store it, see if it matches previous retrieval loop
        if (msgPresent[oLoop])
        {
            // Store the message to one big string
            strcpy(msgErrorCheck[oLoop], msgSender);
            strcat(msgErrorCheck[oLoop], msgDate);
            strcat(msgErrorCheck[oLoop], msgTime);
            strcat(msgErrorCheck[oLoop], msgContent);

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
    UART0printf("\n\r>>> MESSAGE %u:",msgNum);
    if ( msgPresent[oLoop] && msgVerify ) {
        UART0printf("\n\r> FROM: %s ON: %s AT: %s",msgSender,msgDate,msgTime);
        UART0printf("\n\r> TEXT: %s",msgContent);
    }
    else if ( !msgPresent[oLoop] ) { UART0printf("\n\r> NOT PRESENT!"); }
    else { UART0printf("\n\r> COULD NOT VERIFY!"); }

    // Delete the message
    if ( testDelete && msgPresent ){
        UART1printf("AT+CMGD=%u\r\n",msgNum);
        GSMgetResponse();
        UART0printf ( "\n\r>>> MESSAGE %u DELETED",msgNum );
    }
}

//*****************************************************************************
//
// STORE A GSM RESPONSE TO ARRAY responseLine[]
//
//*****************************************************************************
int 
GSMgetResponse(void)
{
    bool readResponse = true;       // Keeps the loop open while getting message
    int readLine = 1;               // Counts the lines of the message
    char *GSMresponse = NULL;       // Use to grab input
    static char g_cInput[128];      // String input to a UART

    while ( readResponse )
    {
        // Grab a line
        UART1gets(g_cInput,sizeof(g_cInput));

        // Stop after newline
        GSMresponse = strtok(g_cInput,"\n");
        strcpy(responseLine[readLine], GSMresponse);

        // If this line says OK we've got the whole message
        if ( strncmp(responseLine[readLine],"OK",2) == 0 ){readResponse = false;}
        else { readLine++; }
    }
    return readLine;
}

//*****************************************************************************
//
// PARSE GSM MESSAGE FOR ENVELOPE AND MESSAGE CONTENT
// Stores message envelope and constant to global variables, OR returns true
// for message present, false for no message
//
//*****************************************************************************
bool
GSMparseMessage( int lineCount )
{
    int activeLine = 1;             // Counter for line being processed
    char *msgEnvelope = NULL;       // Message envelope holder
    const char commaCh[] = ",";     // Comma character

    // Clear out the old message
    msgContent = NULL;

    // Parse the new message
    while ( activeLine < lineCount+1 )
    {
        // CASE FOR ENVELOPE (which will look like:)
        // +CMGR: "REC READ","+13158078555","","15/10/08,13:18:40-20"
        if ( strstr(responseLine[activeLine],"+CMGR:") != '\0' )
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
            strncpy(msgSender,msgSender+2,11);
            msgSender[11] = '\0';

            // Store the date (with null terminator)
            strncpy(msgDate,msgDate+1,8);
            msgDate[8] = '\0';

            // Store the time (with null terminator)
            strncpy(msgTime,msgTime,8);
            msgTime[8] = '\0';
        }

        // CASE FOR MESSAGE CONTENT
        // If we already found the envelope, and the line's not blank...
        else if ( msgEnvelope != NULL && responseLine[activeLine] != NULL )
        {
            // ... and we haven't found any content, this is the first line.
            if (msgContent == NULL) { msgContent = responseLine[activeLine]; }

            // ... otherwise, add a space and append this line.
            else if ( activeLine + 2 <= lineCount ) {
                strcat(msgContent, " ");
                strcat(msgContent, responseLine[activeLine]);
            }
        }

        // Proceed to next line
        activeLine++;
    }
    // If we didn't find an envelope, there's no message
    if (msgEnvelope == NULL) { return false; }

    // Otherwise, return true.
    else { return true; }
}

//*****************************************************************************
//
// MAIN FUNCTION
// Waits for message notification from UART interrupt, and initiates processing
//
//*****************************************************************************
int 
main (void)
{
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
    }