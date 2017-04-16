/*--------------------------Include & Defines secion--------------------------*/
#include <SoftwareSerial.h>

#define SERIAL_DEBUG (1)
//Pin definition is correct, DO NOT try to reverse order!!!
#define GSM_RX_Pin     (10)  //Pin to receive data from GSM module
#define GSM_TX_Pin     (11)  //Pin to transmit data to GSM module


SoftwareSerial mySerial(GSM_RX_Pin, GSM_TX_Pin);  //10-RX, 11-TX
/*-------------------------------Setup secion--------------------------------*/
void setup() {
  Serial.begin(19200);  //Setting the baud rate of serial communication with serial monitor
  mySerial.begin(9600);  //Setting the baud rate of GSM Module
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

/*--------------------------------Loop secion---------------------------------*/
void loop() {
  Serial_Debug();
}



