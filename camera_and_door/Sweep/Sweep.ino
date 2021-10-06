/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); //Rx Tx

Servo myservo;  // create servo object to control a servo// twelve servo objects can be created on most boards
    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
  while(!Serial) {
      ;
    }
}

void open() {
  for (int pos = 90; pos <=  180; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  delay(5000);
  for (int pos = 180; pos >= 90; pos -= 1) { // goes from 90 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void loop() {
  if (Serial.available() > 0) {
  if (Serial.read()=='o') {
    Serial.println("Open");
    open();
    }
  }
  
}
