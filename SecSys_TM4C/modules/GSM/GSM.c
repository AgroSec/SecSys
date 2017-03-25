//#include "GSM.h"

//void PowerOnGSM(void){
//  digitalWrite(GSM_Power_Pin, HIGH);
//  delay(1000);
//  digitalWrite(GSM_Power_Pin, LOW);
//  delay(7000);
//}

//void SendSMS(enum_sms_messages message){
//  unsigned long currentMillis = millis();
//  static unsigned long previousMillis = 0;
//  
//  if(currentMillis - previousMillis >= SMS_SEND_DELAY){
//    previousMillis = currentMillis;
//    GSM_Serial.println("AT+CMGS=\"0751538300\"\r");  //set the mobile number to send the SMS
//    delay(ULTRA_LONG_DELAY);
//    switch (message) {
//      case PIR_A:
//        GSM_Serial.println("PIR A Triggered");  //The SMS text you want to send
//        break;
//      case PIR_B:
//        GSM_Serial.println("PIR B Triggered");
//        break;
//      case Wire_1_Pull:
//        GSM_Serial.println("Wire 1 Pulled");
//        break;
//      case Wire_1_Cut:
//        GSM_Serial.println("Wire 1 Cut");
//        break;
//      case Wire_2_Pull:
//        GSM_Serial.println("Wire 2 Pulled");
//        break;
//      case Wire_2_Cut:
//        GSM_Serial.println("Wire 2 Cut");
//        break;
//      case Wire_3_Pull:
//        GSM_Serial.println("Wire 3 Pulled");
//        break;
//      case Wire_3_Cut:
//        GSM_Serial.println("Wire 3 Cut");
//        break;
//      case Status: 
//        //Send security system status
//        GSM_Serial.println("Security system status:");
//        //TODO
//        //Active_System
//        //Active_Alarm
//        //Wire Guard State
//        //PIR State
//        break;
//      case Wrong_Command:
//        //Wrong SMS command received
//        GSM_Serial.println("Wrong Command. (1)Deactivate Security. (2)Deactivate Alarm. (3)Trigger Alarm. (4)Get Status");
//        break;
//      default:
//        GSM_Serial.println("Something misterious happened");
//    }
//    delay(LONG_DELAY);
//    GSM_Serial.println((char)26);  //ASCII code of CTRL+Z indicating end of message
//    Serial.println("SMS Sent!");
//  }
//}


//unsigned char ReceiveSMS(void){
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
//}

//void ReadSMS(void){
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
//}