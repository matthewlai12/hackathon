#include <AFMotor.h>
#include <Dabble.h>
AF_DCMotor left_motor(1);

// bluetooth control code
#include "SoftwareSerial.h"
SoftwareSerial serial_connection(10, 11);
#define BUFFER_SIZE 64;
char inData[BUFFER_SIZE];
char inChar=-1;
int count=0;
int i=0;



void setup() {
  // put your setup code here, to run once:
  Dabble.begin(38400);  

  // bluetooth control code
  Serial.begin(9600);
  serial_connection.begin(9600);
  serial_connection.println("Ready!!");
  Serial.println("Started");
  

}

void loop() {
  // put your main code here, to run repeatedly:
  Dabble.processInput();
  if GamePad.isUpPressed() {
    left_motor.setSpeed(255);
    left_motor.run(FORWARD);
    left_motor.run(RELEASE);
  }
  
}
