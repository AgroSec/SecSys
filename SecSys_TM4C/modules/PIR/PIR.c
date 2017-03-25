#include "PIR.h"

void Process_PIR(){  //function to read and process PIR state
  unsigned char PIR_A_Value = 0;  //variable to hold PIR A input pin value
  unsigned char PIR_B_Value = 0;  //variable to hold PIR B input pin value
  static unsigned char PIR_A_State = 0;  //initial state of PIR A
  static unsigned char PIR_B_State = 0;  //initial state of PIR B
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