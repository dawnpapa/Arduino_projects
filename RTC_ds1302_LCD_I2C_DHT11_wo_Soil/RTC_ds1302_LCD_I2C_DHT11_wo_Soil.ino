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
#include <DS1302RTC.h>
#include <Time.h>
#include <DHT11.h>

// Init the DS1302 RTC module
// Set pins:  CE(RST), IO(DATA),CLK
#define DS1302_GND_PIN 11
#define DS1302_VCC_PIN 12
DS1302RTC RTC(8, 9, 10);

 // Optional connection for dht11 module
#define dht11_GND_PIN 3
#define dht11_VCC_PIN 2
#define dht11_S_PIN 1
DHT11 dht11(dht11_S_PIN);

// assign temperature sensor DS18B20
#define DS18B20_Pin 5      //DS18B20 Signal pin on digital 8
#define DS18B20_GND_PIN 7
#define DS18B20_VCC_PIN 6
DS18B20 ds(DS18B20_Pin); 

// LCD I2C address
LiquidCrystal_I2C lcd(0x3F,16,2);

// Soil sensor & motor assign
// const int soilINPin=A0;
// const int limit=500;
const int motorOutPin=4; //valve pin
// int sensorValue=0; //intiallize sensorValue 

//시간 2자리표시 함수 정의
void print2digits(int number) {
  // Output leading zero
  if (number >= 0 && number < 10) {
    lcd.write('0');
  }
  lcd.print(number);
}

void setup()
{
  // Setup LCD to 16x2 characters
  
  lcd.init();
  lcd.backlight();

  // Soil/Mortor control
  // pinMode(A0,INPUT);
  pinMode(motorOutPin,OUTPUT);



  // Activate RTC module
  digitalWrite(DS1302_GND_PIN, LOW);
  pinMode(DS1302_GND_PIN, OUTPUT);

  digitalWrite(DS1302_VCC_PIN, LOW);
  pinMode(DS1302_VCC_PIN, OUTPUT);

  lcd.print("RTC activated");

      /*시간을 맞춰야할때 주석을 풀어서 설정합니다..
  delay(5000);
  time_t t;
  tmElements_t tm;
  
  tm.Year =  CalendarYrToTm(2016);
  tm.Month = 6;
  tm.Day = 25;
  tm.Hour = 22;
  tm.Minute = 23;
  tm.Second = 00; */

  delay(500);

  // Check clock oscillation  
  lcd.init();
  if (RTC.haltRTC())
    lcd.print("Clock stopped!");
  else
    lcd.print("Clock working.");

  // Check write-protection
  lcd.setCursor(0,1);
  if (RTC.writeEN())
    lcd.print("Write allowed.");
  else
    lcd.print("Write protected.");

  delay ( 2000 );

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
  lcd.print("RTC Sync");
  setSyncProvider(RTC.get); // the function to get the time from the RTC
  if(timeStatus() == timeSet)
    lcd.print(" Ok!");
  else
    lcd.print(" FAIL!");
    

  delay ( 2000 );

  lcd.clear();

  setSyncInterval(10000000);

  
}
float temp, humi;

void loop()
{

/*
//read the soil sensor value
lcd.clear();
sensorValue=analogRead(A0);
lcd.print("Soil Value = ");
lcd.println(sensorValue);

delay(1000);

if ( sensorValue < limit ) {
digitalWrite(motorOutPin,HIGH); //Motor ON
lcd.setCursor(0,1);
lcd.print("Motor working.........");
delay(5000);
digitalWrite(motorOutPin,LOW); //Motor OFF
}

else {
lcd.setCursor(0,1);
lcd.print("Soil is OK !!");
delay(1000);
}
*/


int timelist[]={year(),month(),day(),hour(),minute(),second()};

  // Display time centered on the upper line
  // 년도
  lcd.clear();
  lcd.setCursor(0,0);
  print2digits(timelist[0]);
  lcd.print("/");
  //월
  print2digits(timelist[1]);
  lcd.print("/");
  //일
  print2digits(timelist[2]);
  //요일
  lcd.setCursor(12, 0);
  lcd.print(dayShortStr(weekday()));
  
  //시간 am/pm
  if(timelist[3]>12) {
  lcd.setCursor(0, 1);
  lcd.print("P ");
  print2digits(timelist[3]-12);
  }

  else if(timelist[3]==12) {
  lcd.setCursor(0, 1);
  lcd.print("P ");
  print2digits(timelist[3]);
  }
  
  else {
  lcd.setCursor(0, 1);
  lcd.print("A ");  
  print2digits(timelist[3]);
  }
  
  //분
  lcd.print(":");
  print2digits(timelist[4]);

  //초
  lcd.print(":");
  print2digits(second());
  lcd.print(" ");


// 온도측정
  ds.readSensor();
  lcd.print(ds.getTemperature_C(),1);
  lcd.print("C");

  // Warning!
  if(timeStatus() != timeSet) {
    lcd.setCursor(0, 1);
    lcd.print(F("RTC ERROR: SYNC!"));
  }

  delay ( 920 ); // Wait approx 1 sec

  //습도표시
  if(timelist[3]>12) {
  lcd.setCursor(0, 1);
  lcd.print("P ");
  print2digits(timelist[3]-12);
  }

  else if(timelist[3]==12) {
  lcd.setCursor(0, 1);
  lcd.print("P ");
  print2digits(timelist[3]);
  }
  
  else {
  lcd.setCursor(0, 1);
  lcd.print("A ");  
  print2digits(timelist[3]);
  }
    
  lcd.print(":");
  print2digits(timelist[4]);
  
  lcd.print(":");
  print2digits(second());
  lcd.print(" ");
  

  dht11.read(humi,temp);
  lcd.setCursor(11,1);  
  lcd.print(humi,1);
  lcd.print("%");

  delay ( 920 ); // Wait approx 1 sec

  if(hour() >=1 && hour() <=5) {
    lcd.noBacklight();
  }
  else
  lcd.backlight();

  
  switch(timelist[4]){
   
    case 20:
    lcd.clear();
    lcd.print("Happy Jason!!!");
    lcd.setCursor(0,1);
    lcd.print("Enjoy your life!!!");
    delay(2000);
    lcd.clear();
    break;

    case 40:
    lcd.clear();
    lcd.print("Relax Jason!!!");
    lcd.setCursor(0,1);
    lcd.print("Life's wonderful!!!");
    delay(2000);
    lcd.clear();
    break;

    case 0:
    lcd.clear();
    lcd.print("Positive Jason!!!");
    lcd.setCursor(0,1);
    lcd.print("Goes well!!!");
    delay(2000);
    lcd.clear();
    
    // watering every 1hour
    digitalWrite(motorOutPin,HIGH); //Motor ON
    lcd.setCursor(0,1);
    lcd.print("Watering working.........");
    delay(5000);
    digitalWrite(motorOutPin,LOW); //Motor OFF
    break;

    
    
  }
  
  
  if(timelist[3]=0 && timelist[4]==0 && timelist[5]==0){
  setSyncProvider(RTC.get); // the function to get the time from the RTC
  lcd.clear();
  lcd.print("Time is syncronized!!!");
  delay(1000);
  }
  
  
}

