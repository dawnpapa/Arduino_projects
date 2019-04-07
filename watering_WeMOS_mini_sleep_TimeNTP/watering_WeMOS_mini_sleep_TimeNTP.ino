
/*
 * Time_NTP.pde
 * Example showing time sync to NTP time source
 *
 * This sketch uses the ESP8266WiFi library
 */
 
#include <TimeLib.h> 
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
// #include <LiquidCrystal_I2C.h>
//#include <DHT.h>
#include <SimpleTimer.h>

#define motorPin 4 //the # of 4 is D2 on WeMOS mini 

int water_int=4; //watering interval in hour
int duration=3; //watering duration in sec for each time

SimpleTimer timer;

const char ssid[] = "SJSLGU";  //  your network SSID (name)
const char pass[] = "123456789b";       // your network password


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

// LiquidCrystal_I2C lcd(0x3F,16,2); //address, lcd type

void setup() 
{
  Serial.begin(115200);
//  lcd.init();
//  lcd.backlight();

//  pinMode(DHTPIN,INPUT);
  pinMode(motorPin,OUTPUT);
  //digitalWrite(motorOutPin,LOW);
  
//  while (!Serial) ; // Needed for Leonardo only
  delay(250);
  Serial.println("Connecting to ");
//  lcd.print("Connecting to ");
//  lcd.setCursor(0,1);
  Serial.print(ssid);
  WiFi.begin(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

//  lcd.clear();
  Serial.print("IP number is ");
//  lcd.setCursor(0,1);
  Serial.println(WiFi.localIP());
  delay(1000);
//  lcd.clear();
  Serial.println("Starting UDP");
  Udp.begin(localPort);
//  lcd.setCursor(0,1);
  Serial.print("Local port: ");
  Serial.println(Udp.localPort());
  delay(1000);
//  lcd.clear();
  Serial.println("waiting for sync");
  setSyncProvider(getNtpTime);
  
//  lcd.setCursor(0,1);
  Serial.println("...OK    ");
  delay(1000);

//////current time//////
  Serial.print("current time is ");
  Serial.print(hour());Serial.print(":");
  Serial.print(minute());Serial.print(":");
  Serial.println(second());
//////sw tick sound for checking wifi connection
digitalWrite(motorPin,HIGH); //Motor ON
delay(500);
digitalWrite(motorPin,LOW); //Motor OFF

////////////////////////////////////deep sleep until o'clock//////////
if(minute()!=0) {
  Serial.print("falling a sleep for ");
  Serial.print((60-minute())*60-(60-second()));
  Serial.println("seconds");
  Serial.println(60-minute()-1);Serial.print("min");
  
  ESP.deepSleep(1000000*1.049*((60-minute())*60-(60-second())));
}


//lcd.clear();
digitalWrite(motorPin,HIGH); //Motor ON
Serial.print("watering......");
delay(500);
digitalWrite(motorPin,LOW); //Motor OFF
//lcd.clear();
delay(1000);
}


void loop()
{  
Serial.print("loop");
if(hour()%water_int==0){
  digitalWrite(motorPin, HIGH);
  Serial.println("watering1");
  delay(duration*1000); //motor ON duration
  digitalWrite(motorPin,LOW);
  delay(1000);
}

  Serial.print("falling a sleep again for ");
  Serial.print((60-minute())*60-(60-second()));
  Serial.println("seconds");
  delay(1000);
  ESP.deepSleep(1000000*1.049*((60-minute())*60-(60-second()))); //unit:usec
}

///////////////////////////////////////////////////
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
//      lcd.setCursor(0,1);
      Serial.print("Sync ...");
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

///////////////////////////////////////////////
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

/////////////////////////////////

