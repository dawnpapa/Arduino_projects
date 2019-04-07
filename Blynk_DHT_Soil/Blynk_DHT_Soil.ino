#define BLYNK_PRINT Serial   
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>
#define DHTPIN 2 //pin gpio 4 in sensor
#define DHTTYPE DHT11
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,20,4);
//#define VCC 12
//#define GND 13
 
DHT dht(DHTPIN, DHTTYPE);
 
char auth[] = "579d76c974ea48fa927461a5c591619a";  
SimpleTimer timer;
 

void setup()
{
  Serial.begin(115200); 
  //pinMode(VCC,OUTPUT);
 // pinMode(GND,OUTPUT);
 // digitalWrite(VCC,HIGH);
 // digitalWrite(GND,LOW);
   
   Blynk.begin(auth, "SJSLGU", "123456789b"); 
 
  timer.setInterval(1000L, sendUptime);
}
 
void loop()
{
  Blynk.run();
  timer.run();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print(t);Serial.print("C");
  Serial.println(h);Serial.print("%");
//  delay(1000);
}

void sendUptime()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
   //Read the Temp and Humidity from DHT
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  Blynk.virtualWrite(10, t); // virtual pin 
  Blynk.virtualWrite(11, h); // virtual pin 
  Blynk.virtualWrite(2,millis()/100);

}
 

