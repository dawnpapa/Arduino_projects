// Timur Maksiomv 2014
//
// A quick demo of how to use DS1302-library to make a quick
// clock using a DS1302 and a 16x2 LCD.
//
// I assume you know how to connect the DS1302 and LCD.
// DS1302:  CE pin    -> Arduino Digital 5
//          I/O pin   -> Arduino Digital 6
//          SCLK pin  -> Arduino Digital 7
//          VCC pin   -> Arduino Digital 13
//          GND pin   -> Arduino Digital 12

#include <LiquidCrystal_I2C.h>
#include<cactus_io_DS18B20.h>

#include <Time.h>
#include <DHT11.h>


 // Optional connection for dht11 module
#define dht11_GND_PIN 8
#define dht11_VCC_PIN 9
#define dht11_S_PIN 10
DHT11 dht11(dht11_S_PIN);

// assign temperature sensor DS18B20
#define DS18B20_Pin 4      //DS18B20 Signal pin on digital 8
#define DS18B20_GND_PIN 2
#define DS18B20_VCC_PIN 3
DS18B20 ds(DS18B20_Pin); 

// LCD I2C address
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  // Setup LCD to 16x2 characters
  
  lcd.init();
  lcd.backlight();

  

  // Activate dht11 module
  digitalWrite(dht11_GND_PIN, LOW);
  pinMode(dht11_GND_PIN, OUTPUT);

  digitalWrite(dht11_VCC_PIN, HIGH);
  pinMode(dht11_VCC_PIN, OUTPUT);

  lcd.clear();
  lcd.home();
  lcd.print("DHT11 activated");
  delay(1000);
  
  // Activate DS18B20 module
  digitalWrite(DS18B20_GND_PIN, LOW);
  pinMode(DS18B20_GND_PIN, OUTPUT);

  digitalWrite(DS18B20_VCC_PIN, HIGH);
  pinMode(DS18B20_VCC_PIN, OUTPUT);
  
  lcd.setCursor(0,1);
  lcd.print("DS18B20 activated");
  
  delay(1000);

  lcd.clear();
  
}
float temp, humi;

void loop()
{

// 온도측정
  ds.readSensor();
  lcd.setCursor(0,0);  
  lcd.print("Temp  :   ");lcd.setCursor(0,0);  
  lcd.print("Temp  :   ");
  lcd.print(ds.getTemperature_C(),1);
  lcd.print("C");

  //습도표시
 
  dht11.read(humi,temp);
  lcd.setCursor(0,1);  
  lcd.print("Humid :   ");
  lcd.print(humi,1);
  lcd.print("%");

  delay ( 5000 ); // Wait approx 1 sec

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
    break;
}
  
}

