#include <Time.h>
#include <TimeLib.h>

#include <DS1302RTC.h>


 
// Set pins:  CE(reset),IO(dat),CLK
DS1302RTC RTC(8, 9, 10);
 
// Optional connection for RTC module
#define DS1302_GND_PIN 11
#define DS1302_VCC_PIN 12
 
void setup()
{
 
  // Setup Serial connection
  Serial.begin(9600);
  
  Serial.println("DS1302RTC Read Test");
  Serial.println("-------------------");
  
  // Activate RTC module
  digitalWrite(DS1302_GND_PIN, LOW);
  pinMode(DS1302_GND_PIN, OUTPUT);
 
  digitalWrite(DS1302_VCC_PIN, LOW);
  pinMode(DS1302_VCC_PIN, OUTPUT);
  
  Serial.println("RTC module activated");
  Serial.println();
  delay(500);
  
  if (RTC.haltRTC()) {
    Serial.println("The DS1302 is stopped.  Please run the SetTime");
    Serial.println("example to initialize the time and begin running.");
    Serial.println();
  }
  if (!RTC.writeEN()) {
    Serial.println("The DS1302 is write protected. This normal.");
    Serial.println();
  }
 
 time_t t;
 tmElements_t tm;
 
        
  delay(5000);
 
  
  //시간을 맞춰야할때 주석을 풀어서 설정합니다..
  
  tm.Year =  CalendarYrToTm(2016);
  tm.Month = 9;
  tm.Day = 3;
  tm.Hour = 15;
  tm.Minute = 32;
  tm.Second = 00;
  
  t = makeTime(tm); 
  if(RTC.set(t) == 0) { // Success
    setTime(t);
    Serial.print("RTC set to: ");
    printDateTime(t);
    Serial.println("");
  }
  else
    Serial.println("RTC set failed!");


}
 
 
void loop()
{
  tmElements_t tm;
  
  Serial.print("UNIX Time: ");
  Serial.print(RTC.get());
 
  if (! RTC.read(tm)) {
    Serial.print("  Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (Y-M-D) = ");
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.write('-');
    Serial.print(tm.Month);
    Serial.write('-');
    Serial.print(tm.Day);
    Serial.print(", DoW = ");
    Serial.print(tm.Wday);
    Serial.println();
  } else {
    Serial.println("DS1302 read error!  Please check the circuitry.");
    Serial.println();
    delay(9000);
  }
  
  // Wait one second before repeating :)
  delay (1000);
}
 
void print2digits(int number) {
  if (number >= 0 && number < 10)
    Serial.write('0');
  Serial.print(number);
}
 
 
//print date and time to Serial
void printDateTime(time_t t)
{
    printDate(t);
    Serial.print(' ');
    printTime(t);
}
 
//print time to Serial
void printTime(time_t t)
{
    printI00(hour(t), ':');
    printI00(minute(t), ':');
    printI00(second(t), ' ');
}
 
//print date to Serial
void printDate(time_t t)
{
    printI00(day(t), 0);
    Serial.print(monthShortStr(month(t)));
    Serial.print(year(t));
}
 
//Print an integer in "00" format (with leading zero),
//followed by a delimiter character to Serial.
//Input value assumed to be between 0 and 99.
void printI00(int val, char delim)
{
    if (val < 10) Serial.print('0');
    Serial.print(val);
    if (delim > 0) Serial.print(delim);
    return;
}
