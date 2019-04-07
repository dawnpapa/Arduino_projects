
#include <TimeLib.h>

const int motorPin=4;      //the number of motor pin on Wemos mini is D2
int hour_current;
int hour_old=0;

void setup() {
  pinMode(motorPin, OUTPUT);
  
//Serial.begin(115200);

  digitalWrite(motorPin, HIGH);
//  Serial.println("watering");
  delay(5000);  //starting pumping time
  digitalWrite(motorPin,LOW);
  
  
}

void loop() {
  
  hour_current = hour(); //current hour after turning on
// int residue=hour_current%1;   //ON every 8hours

  if(hour_current!=hour_old) {

  digitalWrite(motorPin, HIGH);
//Serial.println("watering1");
  delay(5000); //motor ON duration
  digitalWrite(motorPin,LOW);
  }
  
  hour_old=hour_current;
//  Serial.print(hour_current);
//  Serial.println(hour_current);
//  Serial.println(minute());
//  Serial.println(second());
  delay(1000);
}


