
#include <Servo.h>
Servo myservo;
int i;
void setup() {
  myservo.attach(9);
  pinMode(3,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(100);
  delay(3000);
  myservo.write(0);
  delay(1000);
 /* for(i=0;i<=180;i=i+10)
  {
    myservo.write(i);
    delay(1000);
  } 
  myservo.write(0);
  delay(2000);
  analogWrite(3,100);
  delay(300);
  digitalWrite(3,LOW); */
}
