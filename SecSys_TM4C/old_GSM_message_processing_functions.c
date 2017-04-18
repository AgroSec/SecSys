void ResetMessage(void){
	uint16_t i = 0;
	for(i=0;i<GSM_MESSAGE_SIZE;i++){
		GSM_Message[i]=0x00;
	}
}

uint8_t CheckForSMS(void){
	uint8_t result = 0;
	
	while(UARTCharsAvail(UART2_BASE)){
		if(UART2_GetChar()!='+') {
			SysCtlDelay(Millis2Ticks(1));
			if(UART2_GetChar()=='C'){  //2nd condition
				//delay(1);
				SysCtlDelay(Millis2Ticks(1));
				if(UART2_GetChar()=='M'){  //3rd condition
					//delay(1);
					SysCtlDelay(Millis2Ticks(1));
					if(UART2_GetChar()=='T'){  //4th condition
						SysCtlDelay(Millis2Ticks(1));
						//SMS_Received = 1;  //Serial data confirms receival of SMS message
						result = ReceiveSMS();
					}
				}
			}
		}
	}
	return result;
}

//	result = (uint8_t)UARTCharGetNonBlocking(UART2_BASE);
	
/*	
  while(UART2_GetChar()!='+'){ //1st condition
		//Wait until '+' is received
	}
  //if(UART2_GetChar()=='+') {  //1st condition
    //delay(1);
	SysCtlDelay(Millis2Ticks(100));
	if(UART2_GetChar()=='C'){  //2nd condition
		//delay(1);
		SysCtlDelay(Millis2Ticks(100));
		if(UART2_GetChar()=='M'){  //3rd condition
			//delay(1);
			SysCtlDelay(Millis2Ticks(100));
			if(UART2_GetChar()=='T'){  //4th condition
				SysCtlDelay(Millis2Ticks(100));
				//SMS_Received = 1;  //Serial data confirms receival of SMS message
				result = ReceiveSMS();
			}
		}
	}
	return result;
}*/

unsigned char ReceiveSMS(void){
  uint8_t message_data[160] = "";  //GSM message data, without header
	uint8_t message_length = 0;
  uint16_t i = 0;
  uint16_t j = 0;
  unsigned char SMS_Received = 0;
	/*
  if(UART2_GetChar()=='+') {  //1st condition
    //delay(1);
		SysCtlDelay(Millis2Ticks(100));
    if(UART2_GetChar()=='C'){  //2nd condition
      //delay(1);
			SysCtlDelay(Millis2Ticks(100));
      if(UART2_GetChar()=='M'){  //3rd condition
        //delay(1);
				SysCtlDelay(Millis2Ticks(100));
        if(UART2_GetChar()=='T'){  //4th condition
					SysCtlDelay(Millis2Ticks(100));
          SMS_Received = 1;  //Serial data confirms receival of SMS message
        }
      }
    }
  }
	*/
	
	SMS_Received = 1;  //Temporary TODO
  if(SMS_Received == 1){
    while(UART2_GetChar() != '\n'){
      GSM_Message[i] = UART2_GetChar();
      i++;
    }
    message_length = i;
		PC_Display_Message("Message received width", message_length," character length.");
		PC_Display_Message("The message is", 0,GSM_Message);
	
		i=0;
		while(GSM_Message[i]!=CR) {  //Serch for end of message header
			i++;
		}
		i++;
		if(GSM_Message[i]==LF){  //End of message header
			i++;
			j=0;
			while(GSM_Message[i] != '\n'){
				message_data[j] = GSM_Message[i];  //Copy message data
				j++;
				i++;
			}
			PC_Display_Message("The SMS data length is: ",j," characters");
			PC_Display_Message("The SMS data is: ",0,message_data);
		}
		ReadSMS(message_data);  //send message data for reading / parsing
		return 1;  //Message received
	}
	else {
		return 0;  //No message received
	}
}

void ReadSMS(uint8_t *message_data){
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