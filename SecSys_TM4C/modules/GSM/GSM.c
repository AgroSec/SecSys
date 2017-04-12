/*-------------------Driver Includes-----------------*/
#include "driverlib/sysctl.h"
/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"
/*------Export interface---Self header Includes------*/
#include "GSM.h"
/*-----------------Application Includes---------------*/
#include "pc_display.h"

/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
#include "uart_handler.h"

/*-------------Global Variable Definitions------------*/
extern uint32_t Count0_PIRA;  // number of times Task0 loops
extern uint32_t Count1_PIRB;  // number of times Task1 loops
extern uint32_t Count8_Blank; //increments every minute
extern uint32_t PIR_A_Alarm_Nr;
extern uint32_t PIR_B_Alarm_Nr;
uint8_t GSM_Message[GSM_MESSAGE_SIZE] = {};
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void PowerOnGSM(void){
//  TODO
//  digitalWrite(GSM_Power_Pin, HIGH);
//  delay(1000);
//  digitalWrite(GSM_Power_Pin, LOW);
//  delay(7000);
}

void ResetMessage(void){
	uint8_t i = 0;
	for(i=0;i<GSM_MESSAGE_SIZE;i++){
		GSM_Message[i]=0x00;
	}
}

void SendSMS(SMS_Message_en message){
	UART2_SendString("AT+CMGS=\"0751538300\"");  //set the mobile number to send the SMS
	//UART2_SendNewLine();
	UART2_SendChar(CR);
	//UART2_SendChar(LF);
	SysCtlDelay(Millis2Ticks(100)); //Interrupts are NOT disabled and OS is NOT stoped during delay!
  switch (message) {
		case PIR_A:
			UART2_SendString("PIR A Trigger Nr: ");  //The SMS text you want to send
			UART2_SendUDecimal(Count0_PIRA);
			UART2_SendNewLine();
			UART2_SendString("PIR A Alarm Nr: ");
			UART2_SendUDecimal(PIR_A_Alarm_Nr);
			break;
		case PIR_B:
			UART2_SendString("PIR B Trigger Nr: ");
			UART2_SendUDecimal(Count1_PIRB);
			UART2_SendNewLine();
			UART2_SendString("PIR B Alarm Nr: ");
			UART2_SendUDecimal(PIR_B_Alarm_Nr);
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



unsigned char ReceiveSMS(void){
  //uint8_t message[] = {};
  //uint8_t message_byte = 0;
  uint8_t message_length = 0;
  uint8_t i = 0;
  uint8_t j = 0;
  unsigned char sender_number[] = {};
  unsigned char SMS_Received = 0;
  Serial.write(".");
//  while((GSM_Serial.available())&&(GSM_Serial.read() != '\n')){  //While there is data on serial and it's not the end of the string
//    message_byte = GSM_Serial.read();
//    message[i] = message_byte;
//    i++;
//      //Serial.write(message[i]);
//  }
  
  while((GSM_Serial.available())&&(UART2_GetChar()=='+')) {
    //delay(1);
    if(UART2_GetChar()=='C'){
      //delay(1);
      if(UART2_GetChar()=='M'){
        //delay(1);
        if(UART2_GetChar()=='T'){
          SMS_Received = 1;
        }
      }
    }
  }
  if(SMS_Received == 1){
    while(UART2_GetChar() != '\n'){
      GSM_Message[i] = UART2_GetChar();
      i++;
    }
    message_length = i;
		PC_Display_Message("Message received width", message_length," character length.");
		PC_Display_Message("The message is", 0,GSM_Message);
		
  }
  
//  if((message[0]=='+')&&(message[1]=='C')&&(message[2]=='M')&&(message[3]=='T')) { //serial message format confirms receival of SMS

//    for(i = SMS_NUMBER_START_INDEX; i <= SMS_NUMBER_END_INDEX; i++){
//      sender_number[j] = message[i];
//      j++;
//    }
    //Serial.write("The sender number is");
    //Serial.write(sender_number[1]);
  //}
	return 0;
}

void ReadSMS(void){
//  unsigned long currentMillis = millis();
//  static unsigned long previousMillis = 0;
//  unsigned char reveive_message = 0;
//  
//  if(currentMillis - previousMillis >= SMS_READ_DELAY){
//    previousMillis = currentMillis;
//    reveive_message = ReceiveSMS();
//    switch (reveive_message) {
//      case 0:
//        //Do nothing
//        break;
//      case 1:
//        //Deactivate Security System
//        Active_System = 0;
//        break;
//      case 2:
//        //Deactivate Alarm
//        Active_Alarm = 0;
//        break;
//      case 3:
//        //Trigger Alarm
//        Trigger_Alarm = 1;
//        break;
//      case 4:
//        //Get Security Status
//        SendSMS(Status);
//        break;
//      default:
//        //Wrong message
//        SendSMS(Wrong_Command);
//    }
//  }
}
