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
#define GSM_Power_Pin  (12)  //Pin used to power on GSM module via software

#define STARTUP_DELAY  (60)  //number of seconds to wait befor startup
#define SMS_SEND_DELAY (5000)  //number of mili seconds to wait after sms sending
#define PIR_READ_DELAY (1000)  //number of mili seconds to wait between PIR reads

#define ULTRA_SHORT_DELAY (10)  //10ms
#define SHORT_DELAY       (50)  //50ms
#define LONG_DELAY        (100)  //100ms
#define ULTRA_LONG_DELAY  (500)  //500ms

SoftwareSerial mySerial(GSM_RX_Pin, GSM_TX_Pin);  //10-RX, 11-TX
/*--------------------Global variables declaration secion---------------------*/
enum enum_sms_messages {
  No_Message,
  PIR_A,
  PIR_B,
  Wire_1_Pull,
  Wire_1_Cut,
  Wire_2_Pull,
  Wire_2_Cut,
  Wire_3_Pull,
  Wire_3_Cut,
  Status,
  Wrong_Command
} ;
typedef enum_sms_messages sms_messages;
unsigned char Active_System = 1;  //Global variable to activate / deactivate security system
unsigned char Active_Alarm = 1;  //Global variable to activate / deactivate alarm
unsigned char Trigger_Alarm = 0;  //Global variable to trigger alarm

/*-------------------------------Setup secion--------------------------------*/
void setup() {
  //unsigned long currentMillis = 0;
  
#ifdef SECURITY_FUNCTIONS  //If Serial Debug is OFF
  pinMode(PIR_A_INPUT, INPUT);  //declare as input
  pinMode(PIR_B_INPUT, INPUT);
  pinMode(GSM_Power_Pin, OUTPUT);
  
/*
  pinMode(WIRE_A_INPUT_1, INPUT_PULLOP);  //Internal pullup resistor selected, use negative logic
  pinMode(WIRE_A_INPUT_2, INPUT_PULLOP);
  pinMode(WIRE_B_INPUT_1, INPUT_PULLOP);
  pinMode(WIRE_B_INPUT_2, INPUT_PULLOP);
  pinMode(WIRE_C_INPUT_1, INPUT_PULLOP);
  pinMode(WIRE_C_INPUT_2, INPUT_PULLOP);
*/
#endif

  PowerOnGSM();
  Serial.begin(9600);  //Setting the baud rate of serial communication with serial monitor
  mySerial.begin(9600);  //Setting the baud rate of GSM Module
  mySerial.println("AT+CMGF=1\r");  //convert the message style to text
  
  mySerial.println("AT+CSQ");  //Signal Quality Report
  //delay(2000);
  //ShowSerialData();
  mySerial.println("AT+CREG?");  //Attach or Detach  from Gprs Service
  //delay(2000);
  //ShowSerialData();
  mySerial.println("AT+CMGF=1");  //convert the message style to text
  //delay(2000);
  //ShowSerialData();
  mySerial.println("AT+CNMI=1,2,0,0,0");  //set SMS receive indications
  //delay(2000);
  //ShowSerialData();
  
//  while(startup_delay){
//    delay(2*ULTRA_LONG_DELAY);  //wait 1 second
//    startup_delay--; //decrement startup delay by 1 second
//  }

  //wait for PIR sensors to stabilize
#ifdef SECURITY_FUNCTIONS
  //currentMillis = millis();
  while(millis() < STARTUP_DELAY*1000){
    //currentMillis = millis();    
  }
#endif
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
      SendSMS(PIR_A);
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
      SendSMS(PIR_B);
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

  if(Wire_A1) {SendSMS(Wire_1_Pull);}
  if(Wire_A2) {SendSMS(Wire_1_Cut);}
  if(Wire_B1) {SendSMS(Wire_2_Pull);}
  if(Wire_B2) {SendSMS(Wire_2_Cut);}
  if(Wire_C1) {SendSMS(Wire_3_Pull);}
  if(Wire_C2) {SendSMS(Wire_3_Cut);}
}

void PowerOnGSM(void){
  digitalWrite(GSM_Power_Pin, HIGH);
  delay(1000);
  digitalWrite(GSM_Power_Pin, LOW);
  delay(7000);
}

void SendSMS(enum_sms_messages message){
  unsigned long currentMillis = millis();
  static unsigned long previousMillis = 0;
  static unsigned char smsState = LOW;
  
  if(currentMillis - previousMillis >= SMS_SEND_DELAY){
    previousMillis = currentMillis;
    mySerial.println("AT+CMGS=\"0751538300\"\r");  //set the mobile number to send the SMS
    delay(ULTRA_LONG_DELAY);
    switch (message) {
      case PIR_A:
        mySerial.println("PIR A Triggered");  //The SMS text you want to send
        break;
      case PIR_B:
        mySerial.println("PIR B Triggered");
        break;
      case Wire_1_Pull:
        mySerial.println("Wire 1 Pulled");
        break;
      case Wire_1_Cut:
        mySerial.println("Wire 1 Cut");
        break;
      case Wire_2_Pull:
        mySerial.println("Wire 2 Pulled");
        break;
      case Wire_2_Cut:
        mySerial.println("Wire 2 Cut");
        break;
      case Wire_3_Pull:
        mySerial.println("Wire 3 Pulled");
        break;
      case Wire_3_Cut:
        mySerial.println("Wire 3 Cut");
        break;
      case Status: 
        //Send security system status
        mySerial.println("Security system status:");
        //TODO
        //Active_System
        //Active_Alarm
        //Wire Guard State
        //PIR State
        break;
      case Wrong_Command:
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
      SendSMS(Status);
      break;
    default:
      //Wrong message
      SendSMS(Wrong_Command);
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
  Toggle_LED(150,150);
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


