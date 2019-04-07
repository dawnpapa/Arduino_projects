#include <Stepper.h>

// 2048:한바퀴(360도), 1024:반바퀴(180도)...
const int stepsPerRevolution = 48; 
// 모터 드라이브에 연결된 핀 IN4, IN2, IN3, IN1
Stepper myStepper=Stepper(stepsPerRevolution,8,9,10,11);           
void setup() {
  Serial.begin(9600);
   
}
void loop() {
  // 시계 반대 방향으로 한바퀴 회전
  myStepper.setSpeed(50);
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(2000);

  // 시계 방향으로 한바퀴 회전
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(2000);
}

