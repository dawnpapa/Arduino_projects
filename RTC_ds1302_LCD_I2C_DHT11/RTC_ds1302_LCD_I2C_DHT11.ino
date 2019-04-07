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

// Init the DS1302
// Set pins:  CE(RST), IO(DATA),CLK
DS1302RTC RTC(5, 4, 3);

// Optional connection for RTC module
#define DS1302_GND_PIN 2
#define DS1302_VCC_PIN 1

 // Optional connection for dht11 module
#define dht11_GND_PIN 10
#define dht11_VCC_PIN 11

// Init the LCD
//   initialize the library with the numbers of the interface pins

LiquidCrystal_I2C lcd(0x3F,16,2);

// assign temperature sensor DS18B20

int DS18B20_Pin = 8;       //DS18B20 Signal pin on digital 8
DS18B20 ds(DS18B20_Pin);  // on digital pin 8

// assign humidity sensor dht11
int pin=12; //on digital pin 12

DHT11 dht11(pin);

  
void setup()
{
  // Setup LCD to 16x2 characters
  
  lcd.init();
  lcd.backlight();

    /*시간을 맞춰야할때 주석을 풀어서 설정합니다..
  time_t t;
  tmElements_t tm;
  tm.Year =  CalendarYrToTm(2016);
  tm.Month = 6;
  tm.Day = 25;
  tm.Hour = 22;
  tm.Minute = 23;
  tm.Second = 00; */

  // Activate RTC module
  digitalWrite(DS1302_GND_PIN, LOW);
 pinMode(DS1302_GND_PIN, OUTPUT);

  digitalWrite(DS1302_VCC_PIN, LOW);
  pinMode(DS1302_VCC_PIN, OUTPUT);

  lcd.print("RTC activated");

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


  lcd.init();
  lcd.print("RTC Sync");
  setSyncProvider(RTC.get); // the function to get the time from the RTC
  if(timeStatus() == timeSet)
    lcd.print(" Ok!");
  else
    lcd.print(" FAIL!");
    

  delay ( 2000 );

  setSyncInterval(10000000);
  
}
float temp, humi;
void loop()
{

  // Display time centered on the upper line
  lcd.setCursor(0,0);
  print2digits(year());
  lcd.print("/");
  print2digits(month());
  lcd.print("/");
  print2digits(day());
  
  lcd.setCursor(12, 0);
  lcd.print(dayShortStr(weekday()));
  
  lcd.setCursor(0, 1);
  print2digits(hour());
  lcd.print(":");
  print2digits(minute());
  
  lcd.print(":");
  print2digits(second());
  lcd.print("  ");

  ds.readSensor();
  lcd.print(ds.getTemperature_C(),1);
  lcd.print("C");

  // Warning!
  if(timeStatus() != timeSet) {
    lcd.setCursor(0, 1);
    lcd.print(F("RTC ERROR: SYNC!"));
  }

  delay ( 1000 ); // Wait approx 1 sec

  lcd.setCursor(0, 1);
  print2digits(hour());
  lcd.print(":");
  print2digits(minute());
  
  lcd.print(":");
  print2digits(second());
  lcd.print("  ");

  dht11.read(humi,temp);
  lcd.setCursor(10,1);  
  lcd.print(humi,1);
  lcd.print("%");

  delay ( 1000 ); // Wait approx 1 sec

  if(hour() >=1 && hour() <=5) {
    lcd.noBacklight();
  }
  else
  lcd.backlight();
}

void print2digits(int number) {
  // Output leading zero
  if (number >= 0 && number < 10) {
    lcd.write('0');
  }
  lcd.print(number);
}
