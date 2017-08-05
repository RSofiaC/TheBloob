/*
This code is an adaptation from the Calibration example
 created 29 Oct 2008
 By David A Mellis
 modified 30 Aug 2011
 By Tom Igoe
 http://www.arduino.cc/en/Tutorial/Calibration
 This example code is in the public domain.
 */

// These constants won't change:
// pin that the sensor is attached to
const int sensorPin1 = A3;
const int sensorPin2 = A4;
const int sensorPin3 = A5;
const int sensorPin4 = A0;
//const int sensorPin5 = A1;
const int sensorPin6 = A2;

// pin that the LED is attached to
const int ledPin1 = 11;
const int ledPin2 = 10;
const int ledPin3 = 9;
const int ledPin4 = 6;
//const int ledPin5 = 5;
const int ledPin6 = 3;

// variables:
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
//int sensorValue5 = 0;
int sensorValue6 = 0;


void setup() {
  Serial.begin(9600);
}

int LEDDelay = 0;
void loop() {
  // read the sensor:
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  sensorValue4 = analogRead(sensorPin4);
  //sensorValue5 = analogRead(sensorPin5);
  sensorValue6 = analogRead(sensorPin6);

  // apply the calibration to the sensor reading
  sensorValue1 = map(sensorValue1, 1, 1010, 8, 255);
  sensorValue2 = map(sensorValue2, 1, 1010, 8, 255);
  sensorValue3 = map(sensorValue3, 1, 1000, 8, 255);
  sensorValue4 = map(sensorValue4, 1, 1010, 8, 255);
  //sensorValue5 = map(sensorValue5, 1, 1010, 8, 255);
  sensorValue6 = map(sensorValue6, 1, 1010, 8, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue1 = constrain(sensorValue1, 8, 255);
  sensorValue2 = constrain(sensorValue2, 8, 255);
  sensorValue3 = constrain(sensorValue3, 8, 255);
  sensorValue4 = constrain(sensorValue4, 8, 255);
  //sensorValue5 = constrain(sensorValue5, 8, 255);
  sensorValue6 = constrain(sensorValue6, 8, 255);
  
  //LEDDelay++;
 // if (LEDDelay == 100){
    // fade the LED using the calibrated value:
    analogWrite(ledPin1, sensorValue1);
    analogWrite(ledPin2, sensorValue2);
    analogWrite(ledPin3, sensorValue3);
    analogWrite(ledPin4, sensorValue4);
    //analogWrite(ledPin5, sensorValue5);
    analogWrite(ledPin6, sensorValue6);
    //LEDDelay = 0;
 // }
  

  //Values readable for Max
  Serial.write (1);
  Serial.write (sensorValue1);
  Serial.write (2);
  Serial.write (sensorValue2);
  Serial.write (3);
  Serial.write (sensorValue3);
  Serial.write (4);
  Serial.write (sensorValue4);
  //Serial.write (5);
  //Serial.write (sensorValue5);
  Serial.write (6);
  Serial.write (sensorValue6);
  

//  Serial.println("A");
//  Serial.println(sensorValue1);
//  Serial.println("B");
//  Serial.println(sensorValue2);
//  Serial.println("C");
//  Serial.println(sensorValue3);
//  Serial.println("D");
//  Serial.println(sensorValue4);
//  Serial.println("E");
//  Serial.println(sensorValue5);
  //Serial.println(); 
 
  delay(100);
}
