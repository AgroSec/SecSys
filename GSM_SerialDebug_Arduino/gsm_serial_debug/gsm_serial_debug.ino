/*--------------------------Include & Defines secion--------------------------*/
#include <SoftwareSerial.h>

#define SERIAL_DEBUG (1)
//Pin definition is correct, DO NOT try to reverse order!!!
#define GSM_TX_Pin     (11)  //Pin to receive data from GSM module  //Checked - OK
#define GSM_RX_Pin     (10)  //Pin to transmit data to GSM module  //Checked - OK
#define BAUDRATE_GSM  (115200)
#define BAUDRATE_PRINT  (115200)
//example: mySerial(TxPin, RxPin);
SoftwareSerial mySerial(10, 11);  //10-TX, 11-RX
/*-------------------------------Setup secion--------------------------------*/
void setup() {
  Serial.begin(BAUDRATE_PRINT);  //Setting the baud rate of serial communication with serial monitor
  mySerial.begin(BAUDRATE_GSM);  //Setting the baud rate of GSM Module
  mySerial.println("AT+CMGF=1\r");  //message format text
  //mySerial.println("AT+CMGD=1,4\r");  //delete all messages
  //mySerial.println("AT+CNMI=0,0,0,0,1\r");  //set message indication mode. details bellow
  //mySerial.println("AT+CMGR=1,0");  //read message with index 1
}

/*-------------------------Function declaration secion------------------------*/
//Function to debug GSM module through serial monitor
//When function content is active, other functions may be necessary to deactivate.
void Serial_Debug() {
#if SERIAL_DEBUG
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available())
  {
    while (Serial.available())
    {
      mySerial.write(Serial.read());
    }
    mySerial.println();
  }
#endif
}

void Send_Sms(){
  mySerial.println("AT+CMGS=\"0751538300\"\r");  //set the mobile number to send the SMS
  mySerial.println("SMS sent");
  mySerial.println((char)26);  //ASCII code of CTRL+Z indicating end of message
  Serial.write("SMS Sent");
  delay(5000);
}

/*--------------------------------Loop secion---------------------------------*/
void loop() {
  Serial_Debug();
  //Send_Sms();
}



