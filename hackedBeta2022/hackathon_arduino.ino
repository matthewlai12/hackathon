#include <AFMotor.h>
#include <Dabble.h>
AF_DCMotor left_motor(1);

// bluetooth control code
#include <SoftwareSerial.h>
SoftwareSerial HC06(10, 11);
int LED = 12;


void setup() {
  // put your setup code here, to run once:
  Dabble.begin(38400);  

  // bluetooth control code
  HC06.begin(9600);
  pinMode(LED,OUTPUT)

}

void loop() {
  // put your main code here, to run repeatedly:
  Dabble.processInput();
  if GamePad.isUpPressed() {
    left_motor.setSpeed(255);
    left_motor.run(FORWARD);
    left_motor.run(RELEASE);
  }


  // bluetooth control code
  if (HC06.available() > 0)
  {
    char recieve = HC06.read();
    if (recieve == '1')
    {
    digitalWrite(12,HIGH);
    }
    else digitalWrite(12,LOW);
  }
  
}
