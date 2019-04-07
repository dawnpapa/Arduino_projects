#include <Wire.h>
#include <TimeLib.h> 
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <SimpleTimer.h>

#define DHTPIN 13 //
#define DHTTYPE DHT22
#define motorOutPin 5 //physical output pin will be D2 @WeMOS mini

SimpleTimer timer;

DHT dht(DHTPIN, DHTTYPE);

const char ssid[] = "selfmath";  //  your network SSID (name)
const char pass[] = "01090437295";       // your network password


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

LiquidCrystal_I2C lcd(0x27,16,2); //address, lcd type

void setup() 
{
  Wire.begin(D3,D4); //LCD SDA,SCL pin assign

  dht.begin();
  
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  pinMode(DHTPIN,INPUT);
  pinMode(motorOutPin,OUTPUT);

  //DHT bias
  pinMode(14,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(14,LOW);
  digitalWrite(12,HIGH);

  //
  digitalWrite(motorOutPin,LOW);
  

  lcd.print("Connecting to ");
  lcd.setCursor(0,1);
  lcd.print(ssid);
  WiFi.begin(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    lcd.print(".");
    if(millis()>=20000)
    break;
  }

  lcd.clear();
  lcd.print("IP number is ");
  lcd.setCursor(0,1);
  lcd.print(WiFi.localIP());
  delay(1000);
  lcd.clear();
  lcd.println("Starting UDP");
  Udp.begin(localPort);
  lcd.setCursor(0,1);
  lcd.print("Local port: ");
  lcd.println(Udp.localPort());
  delay(1000);
  lcd.clear();
  lcd.println("waiting for sync");
  setSyncProvider(getNtpTime);
  
  lcd.setCursor(0,1);
  lcd.print("OK    ");
  delay(1000);

lcd.clear();
digitalWrite(motorOutPin,HIGH); //Motor ON
lcd.print("watering......");
delay(3000);
digitalWrite(motorOutPin,LOW); //Motor OFF
lcd.clear();



///////////////////////////////////
timer.setInterval(2000, checkDHT); //in msec units
timer.setInterval(500000, lcdinit);
timer.setInterval(1000*60*60*8, watering); //watering interval

}

time_t prevDisplay = 0; // when the digital clock was displayed



void loop()
{  
  if (timeStatus() != timeNotSet) {
    if (now() != prevDisplay) { //update the display only if time has changed
      prevDisplay = now();
      digitalClockDisplay();  
    }
  }
  
  timer.run();
    
  delay(100);

 //물주기와 응원메시지
switch(minute()){
   
    case 20:
    delay(1000);
    lcd.clear();
    lcd.print("Positive Luke!!!");
    lcd.setCursor(0,1);
    lcd.print("Goes well!!!");
    delay(2000);
    lcd.clear();
    break;

    case 40:
    delay(1000);
    lcd.clear();
    lcd.print("Relax Luke!!!");
    lcd.setCursor(0,1);
    lcd.print("Life's wonderful!!!");
    delay(2000);
    lcd.clear();
    break;

    case 0:
    delay(1000);
    lcd.clear();
    lcd.print("Contraturations !!!");
    lcd.setCursor(0,1);
    lcd.print("Be happy, Luke !!!");
    delay(2000);
    lcd.clear();

    break;  
}
}

//watering 
void watering(){
   // watering every hours
    digitalWrite(motorOutPin,HIGH); //Motor ON
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Watering working.........");
    delay(3000); //pumping duration
    digitalWrite(motorOutPin,LOW); //Motor OFF
    lcd.init();
}


///////////////////////////////////////////////////////
void digitalClockDisplay(){
  // digital clock display of the time
  lcd.setCursor(0,0);
  lcd.print(year());
  lcd.print("/");
  lcd.print(month());
  lcd.print("/");
  lcd.print(day());
  lcd.setCursor(11,0);
  lcd.print(dayShortStr(weekday()));
 // lcd.print(" ");  

  lcd.setCursor(0,1);
  if(hour()<12){
    if(hour()<10){
    lcd.print("A ");
    lcd.print(hour());
    }
    else{
    lcd.print("A");
    lcd.print(hour());
    }
    }

  else if(hour()>12){
    if(hour()-12<10){
    lcd.print("P ");
    lcd.print(hour()-12);
    }
    else{
    lcd.print("P");
    lcd.print(hour()-12);
    }
  }
  else{
    lcd.print("P");
    lcd.print(hour());
  }
  printDigits(minute());
  printDigits(second());
  lcd.print(" ");
 
  if(hour() >=1 && hour() <=5) {
    lcd.noBacklight();
  }
  else
  lcd.backlight();
}


////////////////////////////////////////////////////
void printDigits(int digits){
  // utility for digital clock display: prints preceding colon and leading 0
  lcd.print(":");
  if(digits < 10)
    lcd.print('0');
    lcd.print(digits);
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
      lcd.setCursor(0,1);
      lcd.print("Sync ...");
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
void checkDHT()
{
//  float h=dht.readHumidity();
  float t=dht.readTemperature();
  
  lcd.setCursor(11,1);  
  lcd.print(t,1);
  lcd.print("C");
/*
  lcd.setCursor(13,0);
  
  if(h<9.5){
    lcd.print(" ");
    lcd.print(h,0);
    lcd.print("%");
  }
  else{
   lcd.print(h,0);
   lcd.print("%");
  } */
}

//////////////////////////
void lcdinit()
{
  lcd.init();
  
}

