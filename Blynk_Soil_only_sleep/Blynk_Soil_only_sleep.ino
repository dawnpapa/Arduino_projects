#define BLYNK_PRINT Serial   
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <TimeLib.h>

int soil; //soil sensor value

char auth[] = "579d76c974ea48fa927461a5c591619a"; //1번째 token
//char auth[] = "abdfeb7143924b188d32ebb0925a832d";  //2번째  token
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

  pinMode(A0,INPUT); //soil sensor
  digitalWrite(16,HIGH);// reset안정성 확보를 위해 선언
   
  Blynk.begin(auth, "SJSLGU", "123456789b"); 

   while(WiFi.status()!=WL_CONNECTED){
  delay(500);
  Serial.println(".");
 }
  
   Serial.println("Connecting to Blynk");

 // Wait until connected
  while (Blynk.connect() == false);
  
  Serial.print("Blynk connected!");
  Serial.println(WiFi.localIP());
  delay(1000);

  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(Udp.localPort());
  delay(1000);

  Serial.println("waiting for Time sync");
  setSyncProvider(getNtpTime);

 // lcd.init();
  
  timer.setInterval(5000L, sendUptime);
  timer.setInterval(10000L, digitalClockDisplay);
  timer.setInterval(60000L, sleep); //배터리 손실줄이기 위해 1분간 동작후 30분 sleep사용
}
 
void loop()
{
  Blynk.run();
  timer.run();
  
  delay(200); 
  
}

///////////////////////////////////////////////
void sendUptime()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
   //Read the Temp and Humidity from DHT
 // h = dht11.readHumidity();
 // t = dht11.readTemperature();
  soil=analogRead(A0);
// int motor=digitalRead(16);
  
//  Blynk.virtualWrite(10, t); // virtual pin 10번에 온도정보를 보낸다
//  Blynk.virtualWrite(11, h); // virtual pin 11번에 습도정보를 보낸다
//  Blynk.virtualWrite(14,motor*1000);//원격 조정 모터가 제대로 작동되는지 웹에서 확인
  Blynk.virtualWrite(4,hour()*10000+minute()*100+second()); //virtual pin4번에 시간정보를 보낸다.
  Blynk.virtualWrite(16, soil);
  Serial.println(soil);
//  Serial.println(motor);

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

*/
//////////////////////////
void digitalClockDisplay(){
  // digital clock display of the time
  
  Serial.print(year());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(day());
  Serial.print(" ");
  Serial.println(dayShortStr(weekday()));
  Serial.print(hour());
  Serial.print("/");
  Serial.print(minute());
  Serial.print("/");
  Serial.println(second());

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
      
      Serial.println("Time sync OK");
      delay(1000);
      
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

void sleep() {
  Serial.println("sleep");
  
  ESP.deepSleep(60000000*30); //unit:usec RST 과 GPIO16(mini는 D0)을 연결
}
//////////////////////////////////////////
/*void notifyUptime()
{
  long uptime = millis() / 60000L;
  Blynk.notify(String("Running for ") + uptime + " minutes.");
}
*/


