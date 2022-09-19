#include <Arduino.h>

/* I Akshpreet Singh Punj, 000820040 certify that this material is my original work. 
No other person's work has been used without due acknowledgement. 
I have not made my work available to anyone else." */

void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop() {
  // defining the variables
  int iVal;
  double temperature;
  String judgement;

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);

  // print value to the USB port
  
  // Serial.println("Digitized Value = " + String(iVal));

  // double analogVoltage = iVal * 3.3 / 1024;

  // Calculating the temperature
  temperature = (50 / 3.3) * (iVal * 3.3 / 1024); 

  // Checking the temperature value
  if(temperature < 10){
    judgement = "Cold!";
  } else if (temperature >= 10 && temperature < 15){
    judgement = "Cool!";
  } else if (temperature >= 15 && temperature < 25){
    judgement = "Perfect";
  } else if (temperature >= 25 && temperature < 30){
    judgement = "Warm";
  } else if (temperature >= 30 && temperature < 35){
    judgement = "Hot";
  } else {
    judgement = "Too Hot!";
  }

  // Serial.println("Digitized Value of " + String(iVal) + " is equivalent to an Analog Voltage = " + String(analogVoltage) + "V");

  // Printing the temperature and judgement every 2 seconds
  Serial.println("Digitized output of " + String(iVal) + " is equivalent to a temperature input of " + String(temperature) + " deg. C, which is " + judgement);

  // wait 2 seconds (2000 ms)
  delay(2000);
}