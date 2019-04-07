#include <stdint.h> 
#include <ESP8266WiFi.h> 
#include <ESP8266WiFiMulti.h> 
#include <ESP8266HTTPClient.h> 
#include <WiFiUdp.h> 
#include <Wire.h> 
#include <Time.h> 
#include <TimeLib.h> 
#include <ArduinoJson.h> 
#include <SimpleTimer.h>


#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

#define TFT_GREY 0x5AEB

SimpleTimer timer;

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

uint32_t targetTime = 0; 

byte omm = 99, oss = 99;
byte xcolon = 0, xsecs = 0;
unsigned int colour = 0;

unsigned int udpPort = 2390; // local port to listen for UDP packets 
IPAddress timeServerIP; // time.nist.gov NTP server address 
const char* ntpServerName = "time.bora.net"; 

// 공공 데이터 포털  서비스키 
// https://www.data.go.kr/dataset/15000099/openapi.do 참고 
String ServiceKey = "dgnkojzymo%2Fz%2Bj%2FMu9Nc7i0UV%2BKhPPVAfIT%2B1UB715v%2FNdzVb%2Fmt7fcOqpLOweT8Yjeh%2FyysP%2BEeihaHUK410g%3D%3D"; 
char base_date[11]; 
char base_time[5]; 

const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message 
byte packetBuffer[ NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets 

WiFiUDP udp; 

ESP8266WiFiMulti wifiMulti; 

void setup() { 
  Serial.begin(115200); 
  
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  tft.setTextSize(1);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK); 
   
  wifiMulti.addAP("SJSLGU", "123456789b"); 
//  wifiMulti.addAP("ssid_from_AP_2", "your_password_for_AP_2"); 
//  wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3"); 

  Serial.println(""); 
  Serial.print("Connecting Wifi ."); 
  while(wifiMulti.run() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("."); 
  } 
  Serial.println(""); 
  Serial.println("WiFi connected"); 

  Serial.println("Starting UDP"); 
  udp.begin(udpPort); 
  Serial.print("Local port: "); 
  Serial.println(udp.localPort()); 

  //get a random server from the pool 
  WiFi.hostByName(ntpServerName, timeServerIP);  
  sendNTPpacket(timeServerIP); // send an NTP packet to a time server 
  // wait to see if a reply is available 
  delay(1000); 

   Serial.print("NTP Wait ."); 
  int cb = udp.parsePacket(); 
  while(!cb) { 
    WiFi.hostByName(ntpServerName, timeServerIP);  
    sendNTPpacket(timeServerIP); // send an NTP packet to a time server 
    delay(1000); 
    Serial.print("."); 
    cb = udp.parsePacket(); 
  } 
  Serial.println(""); 
  Serial.print("packet received, length="); 
  Serial.println(cb); 
  // We've received a packet, read the data from it 
  udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer 

  //the timestamp starts at byte 40 of the received packet and is four bytes, 
  // or two words, long. First, esxtract the two words: 

  unsigned long highWord = word(packetBuffer[40], packetBuffer[41]); 
  unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]); 
  // combine the four bytes (two words) into a long integer 
  // this is NTP time (seconds since Jan 1 1900): 
  unsigned long secsSince1900 = highWord << 16 | lowWord; 
  Serial.print("Seconds since Jan 1 1900 = " ); 
  Serial.println(secsSince1900); 

  // now convert NTP time into everyday time: 
  Serial.print("Unix time = "); 
  // Unix time starts on Jan 1 1970. In seconds, that's 2208988800: 
  const unsigned long seventyYears = 2208988800UL; 
  // subtract seventy years: 
  unsigned long epoch = secsSince1900 - seventyYears; 
  // print Unix time: 
  Serial.println(epoch); 
  epoch = epoch + 9*3600; // 한국시  +9 

  // print the hour, minute and second: 
  Serial.print("The Seoul time is ");       // UTC is the time at Greenwich Meridian (GMT) 
  Serial.print((epoch  % 86400L) / 3600); // print the hour (86400 equals secs per day) 
  Serial.print(':'); 
  if ( ((epoch % 3600) / 60) < 10 ) { 
    // In the first 10 minutes of each hour, we'll want a leading '0' 
    Serial.print('0'); 
  } 
  Serial.print((epoch  % 3600) / 60); // print the minute (3600 equals secs per minute) 
  Serial.print(':'); 
  if ( (epoch % 60) < 10 ) { 
    // In the first 10 seconds of each minute, we'll want a leading '0' 
    Serial.print('0'); 
  } 
  Serial.println(epoch % 60); // print the second 
  setTime((time_t)epoch); 

   targetTime = millis() + 1000;

check_kma();
timer.setInterval(60000*10,check_kma);   
} 


 
void loop() { 

  time_display();
  timer.run();
  
    
} 
////////////////////////////////////////////////////////////////////
// send an NTP request to the time server at the given address////// 
unsigned long sendNTPpacket(IPAddress& address) 
{ 
//  Serial.println("sending NTP packet..."); 
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
  udp.beginPacket(address, 123); //NTP requests are to port 123 
  udp.write(packetBuffer, NTP_PACKET_SIZE); 
  udp.endPacket(); 
}
//////////////////////////시간표시//////////////////////////////////////
void time_display(){
  
uint8_t hh = hour(), mm = minute(), ss = second(); 
   if (targetTime < millis()) {
    // Set next update for 1 second later
    targetTime = millis() + 1000;

    // Adjust the time values by adding 1 second
    ss++;              // Advance second
    if (ss == 60) {    // Check for roll-over
      ss = 0;          // Reset seconds to zero
      omm = mm;        // Save last minute time for display update
      mm++;            // Advance minute
      if (mm > 59) {   // Check for roll-over
        mm = 0;
        hh++;          // Advance hour
        if (hh > 23) { // Check for 24hr roll-over (could roll-over on 13)
          hh = 0;      // 0 for 24 hour clock, set to 1 for 12 hour clock
        }
      }
    }


    // Update digital time
    tft.setTextSize(3);
    tft.setTextColor(TFT_YELLOW,TFT_BLACK);
    tft.setCursor(0,110);
    tft.print(year());tft.print(".");tft.print(month());tft.print(".");tft.print(day());tft.print(" ");tft.print(dayShortStr(weekday()));
    tft.setTextSize(1);
    
    int xpos = 0;
    int ypos = 140; // Top left corner ot clock text, about half way down
    int ysecs = ypos + 24;

    if (omm != mm) { // Redraw hours and minutes time every minute
      omm = mm;
      // Draw hours and minutes
      if (hh < 10) xpos += tft.drawChar('0', xpos, ypos, 8); // Add hours leading zero for 24 hr clock
      xpos += tft.drawNumber(hh, xpos, ypos, 8);             // Draw hours
      xcolon = xpos; // Save colon coord for later to flash on/off later
      xpos += tft.drawChar(':', xpos, ypos - 8, 8);
      if (mm < 10) xpos += tft.drawChar('0', xpos, ypos, 8); // Add minutes leading zero
      xpos += tft.drawNumber(mm, xpos, ypos, 8);             // Draw minutes
      xsecs = xpos; // Sae seconds 'x' position for later display updates
    }
    if (oss != ss) { // Redraw seconds time every second
      oss = ss;
      xpos = xsecs;

      if (ss % 2) { // Flash the colons on/off
        tft.setTextColor(0x39C4, TFT_BLACK);        // Set colour to grey to dim colon
        tft.drawChar(':', xcolon, ypos - 8, 8);     // Hour:minute colon
        xpos += tft.drawChar(':', xsecs, ysecs, 6); // Seconds colon
        tft.setTextColor(TFT_YELLOW, TFT_BLACK);    // Set colour back to yellow
      }
      else {
        tft.drawChar(':', xcolon, ypos - 8, 8);     // Hour:minute colon
        xpos += tft.drawChar(':', xsecs, ysecs, 6); // Seconds colon
      }

      //Draw seconds
      if (ss < 10) xpos += tft.drawChar('0', xpos, ysecs, 6); // Add leading zero
      tft.drawNumber(ss, xpos, ysecs, 6);                     // Draw seconds
    }
  }
}
////////////////////////////////////////////날씨정보//////////////
void check_kma(){
  tft.setCursor(0,0);
  tft.setTextSize(3);
  tft.setTextColor(TFT_BLUE,TFT_BLACK);
  char time_string[20]; 
   time_t t = now(); 
   sprintf(time_string, "현재 : %d-%02d-%02d %02d:%02d:%02d", year(t), month(t), day(t), hour(t), minute(t), second(t)); 
   Serial.println(time_string); 

   t = t-60*40; 
   sprintf(time_string, "기준 : %d-%02d-%02d %02d:%02d:%02d", year(t), month(t), day(t), hour(t), minute(t), second(t)); 
   sprintf(base_date, "%d%02d%02d", year(t), month(t), day(t)); 
   sprintf(base_time, "%02d00", hour(t)); 
   Serial.println(time_string); 
   Serial.println(base_date); 
   Serial.println(base_time); 
   
    if(wifiMulti.run() != WL_CONNECTED) { 
        Serial.println("WiFi not connected!"); 
 
        tft.println("WiFi not connected!"); 
        delay(1000); 
    } 

    if(wifiMulti.run() == WL_CONNECTED) { 
        HTTPClient http; 

        String url = "http://newsky2.kma.go.kr/service/SecndSrtpdFrcstInfoService2/ForecastGrib?"; 
        url += "ServiceKey="+ServiceKey; 
        url += "&ServiceKey=SERVICE_KEY"; 
        url += "&base_date="+String(base_date); 
        url += "&base_time="+String(base_time); 
        url += "&nx=61"; 
        url += "&ny=119"; //화성시 반월동 61,119, 서초구양재동 61,125
        url += "&numOfRows=100"; 
        url += "&pageNo=1"; 
        url += "&_type=json"; 
         
        http.begin(url); 
        Serial.printf("[HTTP] URL: %s\n",url.c_str()); 
         
        // start connection and send HTTP header 
        int httpCode = http.GET(); 
         
        // httpCode will be negative on error 
        if(httpCode > 0) { 
          // HTTP header has been send and Server response header has been handled 
          Serial.printf("[HTTP] GET... code: %d\n", httpCode); 
           
          // file found at server 
          if(httpCode == HTTP_CODE_OK) { 
            String payload = http.getString(); 
            Serial.printf(payload.c_str()); 

            DynamicJsonBuffer jsonBuffer; 
            JsonObject& root = jsonBuffer.parseObject(payload.c_str()); 
            if (!root.success()) { 
              Serial.println("parseObject() failed"); 
              delay(6000*5); 
              return; 
            } 

            int result_code = root["response"]["header"]["resultCode"]; 
            const char* result_msg  = root["response"]["header"]["resultMsg"]; 

            if(result_code != 0) { 
              Serial.printf("ERROR : Result Code %d\n%s\n",result_code,result_msg); 
              delay(6000*5); 
              return; 
            } else { 
              Serial.printf("SUCC : Result Code %d\n%s\n",result_code,result_msg); 
            } 
             
            JsonArray& mArray = root["response"]["body"]["items"]["item"]; 
            JsonObject& wdata = jsonBuffer.createObject(); 
            char w_date[20]; // 발표일 
             
            for(JsonArray::iterator it=mArray.begin(); it!=mArray.end(); ++it) { 
               JsonObject& item = *it; 
               const char* key = item["category"]; 
               const char* val = item["obsrValue"]; 
               const char* baseDate = item["baseDate"]; 
               const char* baseTime = item["baseTime"]; 
               sprintf(w_date, "%s%s", baseDate, baseTime); 
               wdata[key] = val; 
               Serial.printf("%s %s %s\n",w_date,key,val); 
            } 
            float w_temp = wdata["T1H"]; // 온도 
            int w_reh = wdata["REH"]; // 습도 
            int w_sky = wdata["SKY"]; // 하늘 맑음(1), 구름조금(2), 구름많음(3), 흐림(4) 
            int w_pty = wdata["PTY"]; // 강수형태(PTY) 코드 : 없음(0), 비(1), 비/눈(2), 눈(3) 
            int w_wd = wdata["VEC"]; // 풍향 
            float w_ws = wdata["WSD"]; // 풍속 

            char w_temp_t[10]; 
            dtostrf(w_temp, 0, 1, w_temp_t);  
            char w_ws_t[10]; 
            dtostrf(w_ws, 0, 1, w_ws_t);  
             
            int w_wd_t = (w_wd + 22.5)/45; 
            char w_pty_str[20]; 
            switch (w_pty) { 
                case 1: strcpy(w_pty_str,"     Rain");break; 
                case 2: strcpy(w_pty_str,"Snow/Rain");break; 
                case 3: strcpy(w_pty_str,"     Snow");break; 
                default:  
                  switch (w_sky) { 
                    case 1: strcpy(w_pty_str,"       Clear");break; 
                    case 2: strcpy(w_pty_str,"Partly Cloudy");break; 
                    case 3: strcpy(w_pty_str,"Mostly Cloudy");break; 
                    case 4: strcpy(w_pty_str,"       Cloudy");break; 
                    default: strcpy(w_pty_str,"----- ------");break; 
                  } 
                break; 
              } 

            Serial.printf("발표시각:%s  온도:%s  습도:%02d  하늘:%02d  강수형태:%02d %s  풍향:%02d %2d  풍속:%s\n", 
                         w_date, w_temp_t,w_reh,w_sky,w_pty,w_pty_str,w_wd,w_wd_t,w_ws_t); 
                          
            
            tft.setTextColor(TFT_GREEN,TFT_BLACK);tft.print("Temper");tft.setTextSize(2);tft.print("ature:  ");tft.setTextSize(3);
            tft.setTextColor(TFT_WHITE,TFT_BLACK);tft.print(w_temp_t); tft.setTextSize(2);tft.print("o");tft.setTextSize(3);tft.println("C"); 
            tft.setTextColor(TFT_GREEN,TFT_BLACK);tft.print("Humidity:  ");tft.setTextColor(TFT_WHITE,TFT_BLACK);tft.print(w_reh);tft.println("%");
            tft.setTextColor(TFT_GREEN,TFT_BLACK);tft.print("Wind:      ");tft.setTextColor(TFT_WHITE,TFT_BLACK);tft.print(w_ws_t); tft.println("m/s");            
//            tft.println("%sms      ",w_ws_t); 
            tft.setTextColor(TFT_GREEN);tft.print("Sky:");tft.setTextColor(TFT_WHITE,TFT_BLACK);
            if(w_pty!=0) tft.setTextColor(TFT_RED,TFT_BLACK);tft.println(w_pty_str);
        
          } 
        } else { 
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str()); 
        } 
         
        http.end(); 
         
  //      delay(300000); 
    }
}

