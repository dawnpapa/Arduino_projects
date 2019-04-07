#define BLYNK_PRINT Serial   
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>
#define DHTPIN 4 //pin gpio 4 in sensor
#define DHTTYPE DHT11  
 
DHT dht(DHTPIN, DHTTYPE);
 
char auth[] = "579d76c974ea48fa927461a5c591619a";  
SimpleTimer timer;
 
void sendUptime()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
   //Read the Temp and Humidity from DHT
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  Blynk.virtualWrite(10, t); // virtual pin 
  Blynk.virtualWrite(11, h); // virtual pin 
  Blynk.virtualWrite(2,millis()/1000);
  Serial.print(t);
  Serial.println(h);
}
 
void setup()
{
  Serial.begin(9600); 
   Blynk.begin(auth, "SJSLGU", "123456789b"); 
 
  timer.setInterval(1000L, sendUptime);
}
 
void loop()
{
  Blynk.run();
  timer.run();
}


