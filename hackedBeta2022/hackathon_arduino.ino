#include <AFMotor.h>
#include <Dabble.h>

AF_DCMotor left_motor(1);

void setup() {
  // put your setup code here, to run once:
  Dabble.begin(38400);  

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
