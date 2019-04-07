/*
  아두이노 프로젝트65 예제4
 */
#define LED 13
#define BUTTON 7


void setup() {
  // initialize digital pin 13 as an output.
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(BUTTON)==HIGH)
  {
    digitalWrite(LED,HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
}
