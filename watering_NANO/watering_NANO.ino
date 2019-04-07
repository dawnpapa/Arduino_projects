
#include <TimeLib.h>

const int motorPin=2;      //the number of motor pin, physical pin # on WeMOS is 8
const int led=13; //led indicator
int hour_current;
int hour_old=0;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(led,OUTPUT);
  
//Serial.begin(115200);

  digitalWrite(motorPin, HIGH);
  digitalWrite(led,HIGH);
//  Serial.println("watering");
  delay(5000);  //starting pumping time
  digitalWrite(motorPin,LOW);
  digitalWrite(led,LOW);
  
  
}

void loop() {
  
  hour_current = hour(); //current hour after turning on

// watering every hours  
  if(hour_current!=hour_old) {

  digitalWrite(motorPin, HIGH);
  digitalWrite(led,HIGH);
//  Serial.println("watering1");
  delay(5000); //motor ON time
  digitalWrite(motorPin,LOW);
  digitalWrite(led,LOW);
  }
  
  hour_old=hour_current;
//  Serial.print(hour_current);
  delay(1000);
}

