
/*
 * Time_NTP.pde
 * Example showing time sync to NTP time source
 *
 * This sketch uses the ESP8266WiFi library
 */
 
#include <TimeLib.h> 
//#include <ESP8266WiFi.h>
//#include <WiFiUdp.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 5
#define DHTTYPE DHT22
#define gnd 7
#define vcc 6

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27,16,2); //address, lcd type

void setup() 
{
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  pinMode(DHTPIN,INPUT);
  pinMode(gnd,OUTPUT);
  pinMode(vcc,OUTPUT);

  digitalWrite(gnd,LOW);
  digitalWrite(vcc,HIGH);


}

void loop()
{  

 float h=dht.readHumidity();
 float t=dht.readTemperature();

  lcd.setCursor(0,0);  
  lcd.print("Temp  :   ");
  lcd.print(t,1);
  lcd.print("C");

  lcd.setCursor(0,1);

    lcd.print("Humid :   ");
    lcd.print(h,1);
    lcd.print("%");
  
      
  delay(1000);

 //물주기와 응원메시지
switch(minute()){
   
    case 20:
    delay(1000);
    lcd.clear();
    lcd.print("Happy Jason!!!");
    lcd.setCursor(0,1);
    lcd.print("Enjoy your life!!!");
    delay(2000);
    lcd.clear();
    break;

    case 40:
    delay(1000);
    lcd.clear();
    lcd.print("Relax Jason!!!");
    lcd.setCursor(0,1);
    lcd.print("Life's wonderful!!!");
    delay(2000);
    lcd.clear();
    break;

    case 0:
    delay(1000);
    lcd.clear();
    lcd.print("Positive Jason!!!");
    lcd.setCursor(0,1);
    lcd.print("Goes well!!!");
    delay(2000);
    lcd.clear();
    
}
}

