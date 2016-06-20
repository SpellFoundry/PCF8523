#include "Wire.h"


#include "I2Cdev.h"
#include <PCF8523.h>
PCF8523 rtc;
int segundos = 0;

pinMode(18, INPUT);           // set pin to input
digitalWrite(18, HIGH);       // turn on pullup resistors
pinMode(19, INPUT);           // set pin to input
digitalWrite(19, HIGH);       // turn on pullup resistors

void setup(){
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Initializing RTC...");
  rtc.initialize();
    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(rtc.testConnection() ? "PCF8523 connection successful" : "PCF8523 connection failed");
    
}

void loop(){
  segundos = rtc.getSeconds();
  delay(500);
  Serial.print("Segundos: ");
  Serial.println(segundos);
}