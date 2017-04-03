/*-------------------Driver Includes-----------------*/
#include "driverlib/sysctl.h"
/*-------------------Configuration Includes-----------*/
#include "SecSys_Config.h"
/*------Export interface---Self header Includes------*/
#include "GSM.h"
/*-------------------Service Includes-----------------*/
#include "gpio_handler.h"
#include "uart_handler.h"

/*-------------Global Variable Definitions------------*/
extern uint32_t Count0_PIRA;  // number of times Task0 loops
extern uint32_t Count1_PIRB;  // number of times Task1 loops
extern uint32_t Count7_Blank; //increments every second
extern uint32_t Count8_Blank; //increments every minute
/*-------------Local Variable Definitions-------------*/

/*-------------------Function Definitions-------------*/
void PowerOnGSM(void){
//  TODO
//  digitalWrite(GSM_Power_Pin, HIGH);
//  delay(1000);
//  digitalWrite(GSM_Power_Pin, LOW);
//  delay(7000);
}

void SendSMS(SMS_Message_en message){
	UART2_SendString("AT+CMGS=\"0751538300\"");  //set the mobile number to send the SMS
	//UART2_SendNewLine();
	UART2_SendChar(CR);
	//UART2_SendChar(LF);
	SysCtlDelay(Millis2Ticks(100)); //Interrupts are NOT disabled and OS is NOT stoped during delay!
  switch (message) {
		case PIR_A:
			UART2_SendString("PIR A Triggered ");  //The SMS text you want to send
			//UART2_SendUDecimal(Count0_PIRA);
			//UART2_SendString(" times!!!");
			break;
		case PIR_B:
			UART2_SendString("PIR B Triggered ");
			//UART2_SendUDecimal(Count1_PIRB);
			//UART2_SendString(" times!!!");
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
			UART2_SendUDecimal(Count7_Blank);
			UART2_SendString(" seconds");
			UART2_SendNewLine();
			UART2_SendUDecimal(Count8_Blank*10);
			UART2_SendString(" minutes");
			//TODO
			//Active_System
			//Active_Alarm
			//Wire Guard State
			//PIR State
			break;
		case Wrong_Command:
			//Wrong SMS command received
			UART2_SendString("Wrong Command. (1)Deactivate Security. (2)Deactivate Alarm. (3)Trigger Alarm. (4)Get Status");
			break;
		default:
			UART2_SendString("Something misterious happened");
	}
	UART2_SendChar(SUB);  //ASCII code of CTRL+Z indicating end of message
  //SysCtlDelay(Millis2Ticks(5000)); //Interrupts are NOT disabled and OS is NOT stoped during delay!
	UART0_SendNewLine();
	UART0_SendString("SMS sent with message ID: ");
	UART0_SendChar((uint8_t)message+'0');
	UART0_SendNewLine();	
	
}



unsigned char ReceiveSMS(void){
//  unsigned char message[] = {};
//  unsigned char message_byte = 0;
//  unsigned char message_length = 0;
//  unsigned char i = 0;
//  unsigned char j = 0;
//  unsigned char sender_number[] = {};
//  unsigned char SMS_Received = 0;
//  Serial.write(".");
////  while((GSM_Serial.available())&&(GSM_Serial.read() != '\n')){  //While there is data on serial and it's not the end of the string
////    message_byte = GSM_Serial.read();
////    message[i] = message_byte;
////    i++;
////      //Serial.write(message[i]);
////  }
//  
//  while((GSM_Serial.available())&&(GSM_Serial.read()=='+')) {
//    delay(1);
//    if(GSM_Serial.read()=='C'){
//      delay(1);
//      if(GSM_Serial.read()=='M'){
//        delay(1);
//        if(GSM_Serial.read()=='T'){
//          SMS_Received = 1;
//        }
//      }
//    }
//  }
//  if(SMS_Received == 1){
//    while(GSM_Serial.read() != '\n'){
//      message[i] = GSM_Serial.read();
//      i++;
//    }
//    Serial.write("Message received");
//    Serial.println(); 
//    message_length = i;
//    Serial.write("Message length");
//    Serial.write(message_length);
//    Serial.println();
//    Serial.write("The message is:");
//    for(i=0;i<message_length;i++){
//      Serial.write(message[i]);
//    }
//  }
//  
////  if((message[0]=='+')&&(message[1]=='C')&&(message[2]=='M')&&(message[3]=='T')) { //serial message format confirms receival of SMS

////    for(i = SMS_NUMBER_START_INDEX; i <= SMS_NUMBER_END_INDEX; i++){
////      sender_number[j] = message[i];
////      j++;
////    }
//    //Serial.write("The sender number is");
//    //Serial.write(sender_number[1]);
//  //}
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
