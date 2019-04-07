#include<Stepper.h>
const int stepsPerRevolution=50;
Stepper myStepper(stepsPerRevolution,11,9,10,8);

void setup() {
  // put your setup code here, to run once:
myStepper.setSpeed(60);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
myStepper.step(200);
delay(5000);
}
