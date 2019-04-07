#define BLYNK_PRINT Serial   
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
//#include <ESP8266_Lib.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>
#include <TimeLib.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,4);

#define DHTPIN 4 //pin gpio 4 in sensor
#define DHTTYPE DHT22
#define motorPin 16  // #2 on WeMos D1

int water_int=1; //watering interval in hour
int duration=3; //watering duration in sec for each time
int limit=300; //soil value to waterint
int full=600;  //soil value to stop watering
int max_repeat=5; //max time to watering (duration*max_repeat)
//센서의 full값에 도달하지 않아도 반복횟수만큼 모터 동작후 멈춤(안전장치)
int soil; //soil sensor value
float h, t; //humidity, temperature

DHT dht(DHTPIN, DHTTYPE);
DHT dht11(12,DHT11);//DHT11
 
char auth[] = "579d76c974ea48fa927461a5c591619a";  
SimpleTimer timer;
 
// NTP Servers:
IPAddress timeServer(132, 163, 4, 101); // time-a.timefreq.bldrdoc.gov
// IPAddress timeServer(132, 163, 4, 102); // time-b.timefreq.bldrdoc.gov
// IPAddress timeServer(132, 163, 4, 103); // time-c.timefreq.bldrdoc.gov


const int timeZone = 9;     // Korea Time
//const int timeZone = -5;  // Eastern Standard Time (USA)
//const int timeZone = -4;  // Eastern Daylight Time (USA)
//const int timeZone = -8;  // Pacific Standard Time (USA)
//const int timeZone = -7;  // Pacific Daylight Time (USA)


WiFiUDP Udp;
unsigned int localPort = 8888;  // local port to listen for UDP packets


// Keep this flag not to re-sync on every reconnection
bool isFirstConnect = true;
/*
// This function will run every time Blynk connection is established
BLYNK_CONNECTED() {
  if (isFirstConnect) {
    // Request Blynk server to re-send latest values for all pins
    Blynk.syncAll();

    // You can also update individual virtual pins like this:
    //Blynk.syncVirtual(V0, V1, V4);

    isFirstConnect = false;
  }

  // Let's write your hardware uptime to Virtual Pin 2
  int value = millis() / 1000;
//  Blynk.virtualWrite(V2, value);
}
*/

void setup()
{
  Serial.begin(115200); 
  lcd.init();
  lcd.backlight();
  
  pinMode(motorPin, OUTPUT);
  pinMode(14,OUTPUT);//DHT11 vcc
  pinMode(16,OUTPUT);//DHT22 gnd
  pinMode(5,OUTPUT);//DHT22 vcc
  pinMode(A0,INPUT); //soil sensor
  
  digitalWrite(motorPin, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Initial Watering");
  delay(1000);  //starting pumping time
  
  digitalWrite(motorPin,LOW);
  digitalWrite(14,HIGH);//DHT11 vcc
//  digitalWrite(16,LOW);//DHT22 gnd
//  digitalWrite(5,HIGH);//DHT22 vcc
   
   Blynk.begin(auth, "SJSLGU", "123456789b"); 

   while(WiFi.status()!=WL_CONNECTED){
  delay(500);
  Serial.println(".");
 }
  
   Serial.println("Connect to Blynk");



 // Wait until connected
  while (Blynk.connect() == false);
  
  lcd.setCursor(0,1);
  lcd.print("Blynk connected!");
  lcd.print(WiFi.localIP());
  delay(1000);

  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(Udp.localPort());
  delay(1000);

  Serial.println("waiting for Time sync");
  setSyncProvider(getNtpTime);

  lcd.init();
  
  timer.setInterval(5000L, sendUptime);
//  timer.setInterval(10000L, notifyUptime);
 timer.setInterval(60000L,soilCheck);
 
}
 
void loop()
{
  Blynk.run();
  timer.run();
  
  digitalClockDisplay();
  
  lcd.setCursor(0,2);
  lcd.print(t,0);  lcd.print("C  ");
  lcd.print(h,0);  lcd.print("%  ");

  lcd.setCursor(0,3);
  lcd.print("soil= ");lcd.print(soil);lcd.print("  ");
  
  delay(200); 
  
}

///////////////////////////////////////////////
void sendUptime()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
   //Read the Temp and Humidity from DHT
  h = dht11.readHumidity();
  t = dht11.readTemperature();
  soil=analogRead(A0);
  
  Blynk.virtualWrite(10, t); // virtual pin 10번에 온도정보를 보낸다
  Blynk.virtualWrite(11, h); // virtual pin 11번에 습도정보를 보낸다
  Blynk.virtualWrite(13,digitalRead(motorPin)*1000); //원격조정되는 모터 ON/OFF여부확인
  Blynk.virtualWrite(2,hour()*10000+minute()*100+second()); //virtual pin2번에 시간정보를 보낸다.
  Blynk.virtualWrite(12, soil);

}

/*////////////////////////////////////////////////////////////////// 
 BLYNK_WRITE(1)
{
   water_int = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("V1 Slider value is: ");
  Serial.println(water_int);
//  analogWrite(1,water_int);

}

 BLYNK_WRITE(0)
{
   duration= param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("V0 Slider value is: ");
  Serial.println(duration);
//  analogWrite(0,duration);

}

*//////////////////////////////////////////////////////////////////////
//soil sensor를 check해서 limit값보다 작으면 물주기 시작
void soilCheck(){
  int cycle=0;
  
if(soil<=limit){
  while(soil>full||cycle<max_repeat){ //soil sensor값이 full 값에 도달하거나 max_repeat만큼 반복할때까지 물주기
  digitalWrite(motorPin, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("watering now");
  delay(1000*duration); //motor ON for duration time
  cycle=cycle+1;
  soil=analogRead(A0);
  }
  
  digitalWrite(motorPin,LOW);
  lcd.clear();
  lcd.print("Stop ...");
  delay(2000);
}
}
//////////////////////////
void digitalClockDisplay(){
  // digital clock display of the time
  
  lcd.setCursor(0,0);
  lcd.print(year());
  lcd.print("/");
  lcd.print(month());
  lcd.print("/");
  lcd.print(day());
  lcd.print(" ");
  lcd.print(dayShortStr(weekday())); lcd.print("   ");

  int si=hour();
  int bun=minute();
  int cho=second();
  
  lcd.setCursor(0,1);
  if(si<12) lcd.print ("AM ");
  else lcd.print("PM ");

  if(si<13){
    if(si<10) lcd.print("0");
    lcd.print(si);
  }
  else{
    if(si%13<9) lcd.print("0");
    lcd.print(si%13+1);
  }
  
  lcd.print(":");
  if(bun<10) lcd.print("0");
  lcd.print(bun);
  lcd.print(":");
  if(cho<10) lcd.print("0");
  lcd.print(cho);
//심야시간 에너지 절약
if(si>=0&&si<6) lcd.noBacklight();
else lcd.backlight();
    
}

//////////////////////////////////////////////////////////////////////////////////////////////
/*-------- NTP code ----------*/

const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets

time_t getNtpTime()
{
  while (Udp.parsePacket() > 0) ; // discard any previously received packets
  Serial.println("Transmit NTP Request");
  sendNTPpacket(timeServer);
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int size = Udp.parsePacket();
    if (size >= NTP_PACKET_SIZE) {
      Serial.println("Receive NTP Response");
 
      Serial.println("Sync ...");
      
      lcd.clear();
      lcd.print("Time sync OK");
      delay(1000);
      lcd.clear();
      
      Udp.read(packetBuffer, NTP_PACKET_SIZE);  // read packet into the buffer
      unsigned long secsSince1900;
      // convert four bytes starting at location 40 to a long integer
      secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
    }
  }
  Serial.println("No NTP Response :-(");
  return 0; // return 0 if unable to get the time
}


/////////////////////////////////////////////////////////////
// send an NTP request to the time server at the given address
void sendNTPpacket(IPAddress &address)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;
  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:                 
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}

//////////////////////////////////////////
/*void notifyUptime()
{
  long uptime = millis() / 60000L;
  Blynk.notify(String("Running for ") + uptime + " minutes.");
}
*/


