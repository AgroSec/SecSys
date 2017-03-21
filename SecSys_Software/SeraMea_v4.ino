/* Alexandru Gaal:
Sera mea security program main file.
----------------------------------------------------------
Version 1.0 - 2017.03.08
*/
/*--------------------------Include & Defines secion--------------------------*/
#include <SoftwareSerial.h>

#define ALEX_GAAL1 0744424818
#define ALEX_GAAL2 0758438903
#define ORANGE_CLAUDIU_1 0751538300
#define ORANGE_CLAUDIU_2 0749256822

#define SERIAL_DEBUG (0)

#if SERIAL_DEBUG  //If Serial Debug is On, security functions are not used
  #undef SECURITY_FUNCTIONS
#else
  #define SECURITY_FUNCTIONS
#endif

#define PIR_A_INPUT    (2)  //Input pin for PIR A
#define PIR_B_INPUT    (3)  //Input pin for PIR B
#define WIRE_A_INPUT_1 (4)  //Bottom Wire Input pin 1 - triggered by wire cut
#define WIRE_A_INPUT_2 (5)  //Bottom Wire Input pin 2 - triggered by wire pull
#define WIRE_B_INPUT_1 (6)  //Middle Wire
#define WIRE_B_INPUT_2 (7)
#define WIRE_C_INPUT_1 (8)  //Top Wire
#define WIRE_C_INPUT_2 (9)
#define GSM_RX_Pin     (10)  //Pin to receive data from GSM module
#define GSM_TX_Pin     (11)  //Pin to transmit data to GSM module

#define STARTUP_DELAY  (60)  //number of seconds to wait befor startup
#define SMS_SEND_DELAY (5000)  //number of mili seconds to wait after sms sending
#define PIR_READ_DELAY (1000)  //number of mili seconds to wait between PIR reads

#define ULTRA_SHORT_DELAY (10)  //10ms
#define SHORT_DELAY       (50)  //50ms
#define LONG_DELAY        (100)  //100ms
#define ULTRA_LONG_DELAY  (500)  //500ms

SoftwareSerial mySerial(GSM_RX_Pin, GSM_TX_Pin);  //10-RX, 11-TX
/*--------------------Global variables declaration secion---------------------*/
unsigned char Active_System = 1;  //Global variable to activate / deactivate security system
unsigned char Active_Alarm = 1;  //Global variable to activate / deactivate alarm
unsigned char Trigger_Alarm = 0;  //Global variable to trigger alarm

/*-------------------------------Setup secion--------------------------------*/
void setup() {
  unsigned char startup_delay = STARTUP_DELAY;
  
#ifdef SECURITY_FUNCTIONS  //If Serial Debug is OFF
  pinMode(PIR_A_INPUT, INPUT);  //declare as input
  pinMode(PIR_B_INPUT, INPUT);
  
/*
  pinMode(WIRE_A_INPUT_1, INPUT_PULLOP);  //Internal pullup resistor selected, use negative logic
  pinMode(WIRE_A_INPUT_2, INPUT_PULLOP);
  pinMode(WIRE_B_INPUT_1, INPUT_PULLOP);
  pinMode(WIRE_B_INPUT_2, INPUT_PULLOP);
  pinMode(WIRE_C_INPUT_1, INPUT_PULLOP);
  pinMode(WIRE_C_INPUT_2, INPUT_PULLOP);
*/
#endif

  Serial.begin(9600);  //Setting the baud rate of serial communication with serial monitor
  mySerial.begin(9600);  //Setting the baud rate of GSM Module

  //wait for PIR sensors to stabilize
  while(startup_delay){
    delay(2*ULTRA_LONG_DELAY);  //wait 1 second
    startup_delay--; //decrement startup delay by 1 second
  }
  Serial.println("Setup ready!");
}

/*-------------------------Function declaration secion------------------------*/
void Toggle_LED(unsigned long OffTime, unsigned long OnTime){
  unsigned long currentMillis = millis();
  static unsigned long previousMillis = 0;
  static unsigned char ledState = LOW;
  if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    ledState = LOW;  // Turn it off
    previousMillis = currentMillis;  // Remember the time
    digitalWrite(LED_BUILTIN, ledState);  // Update the actual LED
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    ledState = HIGH;  // turn it on
    previousMillis = currentMillis;   // Remember the time
    digitalWrite(LED_BUILTIN, ledState);   // Update the actual LED
  }
}

void Process_PIR(){  //function to read and process PIR state
  unsigned char PIR_A_Value = 0;  //variable to hold PIR A input pin value
  unsigned char PIR_B_Value = 0;  //variable to hold PIR B input pin value
  static unsigned char PIR_A_State = LOW;  //initial state of PIR A
  static unsigned char PIR_B_State = LOW;  //initial state of PIR B
  unsigned long currentMillis = millis();
  static unsigned long previousMillisA = 0;
  static unsigned long previousMillisB = 0;
  
  if(currentMillis - previousMillisA >= PIR_READ_DELAY){
    previousMillisA = currentMillis;  // Remember the time  
    //Read pin walues
    PIR_A_Value = digitalRead(PIR_A_INPUT);  //read input value from PIR
    PIR_B_Value = digitalRead(PIR_B_INPUT);
      
    //Process PIR A data
    if ((PIR_A_Value == HIGH)&&(PIR_A_State == LOW)){  //Input was High and current state LOW
      //Trigger conditions met on PIR A
      PIR_A_State = HIGH;  //set current state high
      Serial.println("PIR A Triggered");
      SendSMS(1);
      delay(ULTRA_SHORT_DELAY);
    }
    else if (PIR_A_State == HIGH) {
      PIR_A_State = LOW;
      Serial.println("PIR A Re-Armed");
      delay(ULTRA_SHORT_DELAY);
    }
  }

  if(currentMillis - previousMillisB >= PIR_READ_DELAY){
    previousMillisB = currentMillis;  // Remember the time    
    //Process PIR B data
    if ((PIR_B_Value == HIGH)&&(PIR_B_State == LOW)){  //Input was High and current state LOW
      //Trigger conditions met on PIR B
      PIR_B_State = HIGH;  //set current state high
      Serial.println("PIR B Triggered");
      SendSMS(2);
      delay(ULTRA_SHORT_DELAY);
    }
    else if (PIR_B_State == HIGH) {
      PIR_B_State = LOW;
      Serial.println("PIR B Re-Armed");
      delay(ULTRA_SHORT_DELAY);
    }
  }
}
void Process_Wire_Guard(){
  unsigned char Wire_A1 = 0;  //Variables to read Wire Guard state
  unsigned char Wire_A2 = 0;
  unsigned char Wire_B1 = 0;
  unsigned char Wire_B2 = 0;
  unsigned char Wire_C1 = 0;
  unsigned char Wire_C2 = 0;

  //Read pin walues
  Wire_A1 = !digitalRead(WIRE_A_INPUT_1);  //negate pin read 1 not pressed, 0 pressed, ! changes this
  Wire_A2 = !digitalRead(WIRE_A_INPUT_2);
  Wire_B1 = !digitalRead(WIRE_B_INPUT_1);
  Wire_B2 = !digitalRead(WIRE_B_INPUT_2);
  Wire_C1 = !digitalRead(WIRE_C_INPUT_1);
  Wire_C2 = !digitalRead(WIRE_C_INPUT_2);
  //TODO
}
  
void SendSMS(unsigned char send_message){
  unsigned long currentMillis = millis();
  static unsigned long previousMillis = 0;
  static unsigned char smsState = LOW;
  
  if(currentMillis - previousMillis >= SMS_SEND_DELAY){
    previousMillis = currentMillis;
    mySerial.println("AT+CMGS=\"0751538300\"\r");  //set the mobile number to send the SMS
    delay(ULTRA_LONG_DELAY);
    switch (send_message) {
      case 1:
        mySerial.println("PIR A Triggered");  //The SMS text you want to send
        break;
      case 2:
        mySerial.println("PIR B Triggered");
        break;
      case 80: 
        //Send security system status
        mySerial.println("Security system status:");
        //TODO
        //Active_System
        //Active_Alarm
        //Wire Guard State
        //PIR State
        break;
      case 90:
        //Wrong SMS command received
        mySerial.println("Wrong Command. (1)Deactivate Security. (2)Deactivate Alarm. (3)Trigger Alarm. (4)Get Status");
        break;
      default:
        mySerial.println("Something misterious happened");
    }
    delay(LONG_DELAY);
    mySerial.println((char)26);  //ASCII code of CTRL+Z indicating end of message
    Serial.println("SMS Sent!");
  }

}

unsigned char ReceiveSMS(){
  //TODO!!!
  unsigned char reveive_message = 0;
  //reveive_message = AT command to receive message
  switch (reveive_message) {
    case 0:
      //Do nothing
      break;
    case 1:
      //Deactivate Security System
      Active_System = 0;
      break;
    case 2:
      //Deactivate Alarm
      Active_Alarm = 0;
      break;
    case 3:
      //Trigger Alarm
      Trigger_Alarm = 1;
      break;
    case 4:
      //Get Security Status
      SendSMS(80);
      break;
    default:
      //Wrong message
      SendSMS(90);
  }
}

void Alarm(void){
  if((Trigger_Alarm)&&(Active_Alarm)&&(Active_System)){
    //TODO
  }
}

//Function to debug GSM module through serial monitor
//When function content is active, other functions may be necessary to deactivate.
void Serial_Debug(){
#if SERIAL_DEBUG
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available())
  { 
    while(Serial.available())
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
#ifdef SECURITY_FUNCTIONS  //If Serial Debug is OFF
  if(Active_System){
    Toggle_LED(950,50);
    Process_PIR();
    //Process_Wire_Guard();
  }
#endif
}


