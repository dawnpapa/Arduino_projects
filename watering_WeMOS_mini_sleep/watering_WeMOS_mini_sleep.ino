
#include <TimeLib.h>

const int motorPin=4;      //the number of 4  is D2 on Wemos mini
int hour_current;
int hour_old=0;
int water_int=70; //watering interval in minute, max 70min
int duration=3; //watering duration in sec for each time
void setup() {
  pinMode(motorPin, OUTPUT);
  
Serial.begin(115200);

  digitalWrite(motorPin, HIGH);
  Serial.println("watering");
  delay(1000);  //starting pumping time
  digitalWrite(motorPin,LOW);
  delay(10000);
  
}

void loop() {
  
//  hour_current = second(); //current hour after turning on
// int residue=hour_current%1;   //ON every 8hours

//  if(hour_current!=hour_old) {

  digitalWrite(motorPin, HIGH);
  Serial.println("watering1");
  delay(duration*1000); //motor ON duration
  digitalWrite(motorPin,LOW);
//  }
  
  hour_old=hour_current;
  Serial.print(hour_current);
//  Serial.println(minute());
  Serial.println(second());
  delay(1000);
 ESP.deepSleep(1000000*60*water_int); //unit:usec
 delay(500);
}


