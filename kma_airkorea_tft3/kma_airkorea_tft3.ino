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

byte omm = 99, oss = 99, owday=99;
byte xcolon = 0, xsecs = 0;
unsigned int colour = 0;

unsigned int udpPort = 2390; // local port to listen for UDP packets 
IPAddress timeServerIP; // time.nist.gov NTP server address 
const char* ntpServerName = "time.bora.net"; 

// 공공 데이터 포털  서비스키 
// https://www.data.go.kr/dataset/15000099/openapi.do 참고 kma
// https://www.data.go.kr/dataset/15000581/openapi.do 참고 에어코리아
String ServiceKey = "8ketBY9wZ%2Fr8aUYmfZiX46zlvcsHSvy5Lw37mjeZmmanq1fZdTBX17SyJ%2BGg1y6n994DZmkX0lMoThAnnxIYRw%3D%3D"; //key는 kma, airkorea동일

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
  wifiMulti.addAP("AndroidHotspot1945", "123454321"); 
  wifiMulti.addAP("U+Net80F3", "5000195634"); 

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

  targetTime = millis() + 1000;
  
ntp_update();
check_kma();
check_air();
timer.setInterval(60000*10,check_kma);   //check every 10minutes
timer.setInterval(60000*30,check_air);   //check every 30minutes
timer.setInterval(60000*60*24,ntp_update); //update every 24hours
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

    if(hh>13) hh=hh-12; //12hour roll-over
    
    // Update day every day
    int wday=weekday();

    if(wday!=owday){
    owday=wday;
    tft.setTextColor(TFT_PINK,TFT_BLACK);

    int xpos_date=0;   
    tft.fillRect(0,115,268,29,TFT_BLACK); //이전정보지우기
    xpos_date+=tft.drawNumber(year(),xpos_date,115, 4); xpos_date+=tft.drawString(". ",xpos_date,115,4);
    xpos_date+=tft.drawNumber(month(),xpos_date,115,4);xpos_date+=tft.drawString(". ",xpos_date,115,4);
    xpos_date+=tft.drawNumber(day(),xpos_date,115,4);xpos_date+=tft.drawString("  ",xpos_date,115,4);
    xpos_date+=tft.drawString(dayStr(weekday()),xpos_date,115,4);
  
    }
    // Update digital time
    tft.setTextSize(1);tft.setTextColor(TFT_YELLOW,TFT_BLACK);
    
    int xpos = 0;
    int ypos = 150; // Top left corner ot clock text, about half way down
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
 // tft.fillRect(0,0,320,109,TFT_BLACK);
 // tft.setCursor(0,1);
//  tft.setTextSize(3);
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
 
        tft.setCursor(200,105);tft.setTextSize(1);tft.println("WiFi not connected!"); 
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
                case 1: strcpy(w_pty_str,"Rain");break; 
                case 2: strcpy(w_pty_str,"Rain");break; 
                case 3: strcpy(w_pty_str,"Snow");break; 
                default:  
                  switch (w_sky) { 
                    case 1: strcpy(w_pty_str," Clear  ");break; 
                    case 2: strcpy(w_pty_str," Clear  ");break; 
                    case 3: strcpy(w_pty_str,"Cloudy  ");break; 
                    case 4: strcpy(w_pty_str,"Cloudy  ");break; 
                    default: strcpy(w_pty_str,"------  ");break; 
                  } 
                break; 
              } 

            Serial.printf("발표시각:%s  온도:%s  습도:%02d  하늘:%02d  강수형태:%02d %s  풍향:%02d %2d  풍속:%s\n", 
                         w_date, w_temp_t,w_reh,w_sky,w_pty,w_pty_str,w_wd,w_wd_t,w_ws_t); 
                          
 //           tft.setCursor(0,1);
            tft.fillRect(0,0,320,79,TFT_BLACK); //화면 지우고 다시 표시,시계영역 제외

            tft.setTextColor(TFT_PINK,TFT_WHITE);
            tft.drawString("  @  ALWAYS    HAPPY !!  @   ",0,0,4);
            
            int xpos_weather=170,ypos_weather=30;
            
            tft.setTextColor(TFT_GREEN,TFT_BLACK);
            tft.drawString("Temp/Humid: ",0,ypos_weather,4);
            
            tft.setTextColor(TFT_WHITE,TFT_BLACK);
            xpos_weather+=tft.drawFloat(w_temp, 1, xpos_weather, ypos_weather, 4);
            xpos_weather+=tft.drawChar('o',xpos_weather,ypos_weather-3,1);
            xpos_weather+=tft.drawString("C    ",xpos_weather,ypos_weather,4);
            xpos_weather+=tft.drawNumber(w_reh,xpos_weather,ypos_weather,4);
            tft.drawString("%  ",xpos_weather,ypos_weather,4);
  
            xpos_weather=168;
            
            tft.setTextColor(TFT_GREEN,TFT_BLACK);
            tft.drawString("Wind/Sky:",0,ypos_weather+25,4);
            tft.setTextColor(TFT_WHITE,TFT_BLACK);
            xpos_weather+=tft.drawFloat(w_ws,1,xpos_weather,ypos_weather+25,4); 
            xpos_weather+=tft.drawString("m/s",xpos_weather,ypos_weather+25+12,1); 
           
            if(w_pty!=0) tft.setTextColor(TFT_RED,TFT_BLACK);
            xpos_weather+=tft.drawString(w_pty_str,xpos_weather+5,ypos_weather+25,4);
            
            xpos_weather=0;
            
            tft.setTextColor(TFT_BLUE,TFT_BLACK);
            xpos_weather+=tft.drawString("Updated at ",xpos_weather,107,1);
            xpos_weather+=tft.drawNumber(hour(),xpos_weather,107,1);xpos_weather+=tft.drawString("h ",xpos_weather,107,1);
            if(minute()<10) xpos_weather+=tft.drawChar('0',xpos_weather,107,1); xpos_weather+=tft.drawNumber(minute(),xpos_weather,107,1);tft.drawChar('m',xpos_weather,107,1);
            
            
          } 
        } else { 
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str()); 
        } 
         
        http.end(); 
         
  //      delay(300000); 
    }
}


////////////////ntp_update/////////////////////////////////
void ntp_update() {
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
  
  int xpos_timeup=140;
  tft.setTextColor(TFT_BLUE,TFT_BLACK);
  int d=day(),h=hour(),m=minute();
            xpos_timeup+=tft.drawString("Time Synced at ",xpos_timeup,230,1);
            xpos_timeup+=tft.drawString(monthShortStr(month()),xpos_timeup,230,1);xpos_timeup+=tft.drawChar('.',xpos_timeup,230,1);
            if(d<10) xpos_timeup+=tft.drawChar('0',xpos_timeup,230,1); xpos_timeup+=tft.drawNumber(d,xpos_timeup,230,1);xpos_timeup+=tft.drawString(", ",xpos_timeup,230,1);
            if(h<10) xpos_timeup+=tft.drawChar('0',xpos_timeup,230,1); xpos_timeup+=tft.drawNumber(h,xpos_timeup,230,1);xpos_timeup+=tft.drawString("h ",xpos_timeup,230,1);
            if(m<10) xpos_timeup+=tft.drawChar('0',xpos_timeup,230,1); xpos_timeup+=tft.drawNumber(m,xpos_timeup,230,1);xpos_timeup+=tft.drawChar('m',xpos_timeup,230,1);
}



////////////////////////////////////////////대기정보//////////////
void check_air(){
 // tft.fillRect(0,0,320,109,TFT_BLACK);
 // tft.setCursor(0,1);
//  tft.setTextSize(3);
  tft.setTextColor(TFT_BLUE,TFT_BLACK);
 
    if(wifiMulti.run() != WL_CONNECTED) { 
        Serial.println("WiFi not connected!"); 
 
        tft.setCursor(200,105);tft.setTextSize(1);tft.println("WiFi not connected!"); 
        delay(1000); 
    } 

    if(wifiMulti.run() == WL_CONNECTED) { 
        HTTPClient http; 

        String url = "http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getMsrstnAcctoRltmMesureDnsty?"; 
        url += "stationName=동탄"; //영통동, 동탄 또는 인계동
        url += "&dataTerm=daily"; //daily, month, 3month
        url += "&pageNo=1"; 
        url += "&numOfRows=1"; 
        url += "&ServiceKey="+ServiceKey; //kma와 동일
        url += "&_returnType=json"; // format
        url += "&ver=1.3"; 
         
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
            Serial.println(payload.c_str()); 

            DynamicJsonBuffer jsonBuffer; 
            JsonObject& root = jsonBuffer.parseObject(payload.c_str()); 
            if (!root.success()) { 
              Serial.println("parseObject() failed"); 
              delay(6000*5); 
              return; 
            } 

  /*          int result_code = root["response"]["header"]["resultCode"]; 
            const char* result_msg  = root["response"]["header"]["resultMsg"]; 

            if(result_code != 0) { 
              Serial.printf("ERROR : Result Code %d\n%s\n",result_code,result_msg); 
              delay(6000*5); 
              return; 
            } else { 
              Serial.printf("SUCC : Result Code %d\n%s\n",result_code,result_msg); 
            } 
   */          
              JsonArray& mArray = root["list"]; 
              JsonObject& wdata = jsonBuffer.createObject();
        
              int air_data[5]; 
              
               for(JsonArray::iterator it=mArray.begin(); it!=mArray.end(); ++it) { 
               JsonObject& item = *it; 
               const char* baseTime = item["dataTime"]; 
               const char* pm10grade = item["pm10Grade1h"];
               const char* pm10 = item["pm10Value"]; 
               const char* pm25grade = item["pm25Grade1h"]; 
               const char* pm25 = item["pm25Value"]; 
               const char* o3grade = item["o3Grade"];
               const char* o3=item["o3Value"];

               wdata["dataTime"] = item["dataTime"]; 
               wdata["pm10grade"] = item["pm10Grade1h"];
               wdata["pm10"] = item["pm10Value"]; 
               wdata["pm25grade"] = item["pm25Grade1h"]; 
               wdata["pm25"] = item["pm25Value"]; 
               wdata["o3grade"] = item["o3Grade"];
               wdata["o3"]=item["o3Value"];

               

//               sprintf(w_date, "%s%s", baseDate, baseTime); //w_data에 baseDate과 baseTime을 merge후저장
//               wdata[] = {pm10grade,pm10,pm25grade,pm25,khigrade};
               Serial.printf("%s pm10:%s pm25:%s pm10G:%s pm25G:%s o3G:%s o3:%s\n",baseTime,pm10,pm25,pm10grade,pm25grade,o3grade,o3);
               

            } 
            int pm25=wdata["pm25"];
            int pm25grade=wdata["pm25grade"];
            int pm10=wdata["pm10"];
            int pm10grade=wdata["pm10grade"];
            int o3grade=wdata["o3grade"];
            float o3=wdata["o3"];


         Serial.printf("pm10:%d pm25:%d pm10G:%d pm25G:%d o3G:%d o3:%d\n",pm10,pm25,pm10grade,pm25grade,o3grade,o3);
            int xpos_air=0,ypos_air=80;
            tft.setTextColor(TFT_GREEN,TFT_BLACK);
            xpos_air+=tft.drawString("Dust(PM",xpos_air,ypos_air,4);
            xpos_air+=tft.drawString("2.5/10",xpos_air,ypos_air+8,1);
            xpos_air+=tft.drawString("):",xpos_air,ypos_air,4);
            
            tft.setTextColor(TFT_WHITE,TFT_BLACK);
            xpos_air=155;
            
            char pm10grade_str[20]; char pm25grade_str[20];
            
            switch (pm25grade) { 
                case 1: strcpy(pm25grade_str," Good  ");tft.setTextColor(TFT_WHITE,TFT_BLUE);break; 
                case 2: strcpy(pm25grade_str," Normal");tft.setTextColor(TFT_WHITE,TFT_GREEN);break; 
                case 3: strcpy(pm25grade_str," Bad   ");tft.setTextColor(TFT_WHITE,TFT_YELLOW);break; 
                case 4: strcpy(pm25grade_str," Severe");tft.setTextColor(TFT_WHITE,TFT_RED);break;
                default: strcpy(pm25grade_str,"---    ");tft.setTextColor(TFT_WHITE,TFT_GREY);break;
            }

            xpos_air+=tft.drawNumber(pm25,xpos_air,ypos_air,4);
  //          xpos_air+=tft.drawString(pm25grade_str,xpos_air,ypos_air+12,1);
             
            xpos_air+=tft.drawString("/",xpos_air,ypos_air,4); 
            
             switch (pm10grade) { 
                case 1: strcpy(pm10grade_str," Good  ");tft.setTextColor(TFT_WHITE,TFT_BLUE);break; 
                case 2: strcpy(pm10grade_str," Normal");tft.setTextColor(TFT_WHITE,TFT_GREEN);break; 
                case 3: strcpy(pm10grade_str," Bad   ");tft.setTextColor(TFT_WHITE,TFT_YELLOW);break; 
                case 4: strcpy(pm10grade_str," Severe");tft.setTextColor(TFT_WHITE,TFT_RED);break;
                default: strcpy(pm10grade_str,"----   ");tft.setTextColor(TFT_WHITE,TFT_GREY);break;
              } 

            xpos_air+=tft.drawNumber(pm10,xpos_air,ypos_air,4);
            xpos_air+=tft.drawString(pm10grade_str,xpos_air,ypos_air,4);
            tft.fillRect(xpos_air,ypos_air,100,29,TFT_BLACK); //이전정보지우기
             
             
             //오존정보표시
             int oz_x=293,oz_y=145,sizeC=25;
           switch (o3grade) { 
            
                case 1: tft.fillCircle(oz_x,oz_y,sizeC,TFT_BLUE);tft.setTextColor(TFT_WHITE,TFT_BLUE);break; 
                case 2: tft.fillCircle(oz_x,oz_y,sizeC,TFT_GREEN);tft.setTextColor(TFT_WHITE,TFT_GREEN);break; 
                case 3: tft.fillCircle(oz_x,oz_y,sizeC,TFT_YELLOW);tft.setTextColor(TFT_WHITE,TFT_YELLOW);break; 
                case 4: tft.fillCircle(oz_x,oz_y,sizeC,TFT_RED);tft.setTextColor(TFT_WHITE,TFT_RED);break;
                default: tft.fillCircle(oz_x,oz_y,sizeC,TFT_GREY);tft.setTextColor(TFT_WHITE,TFT_GREY);break;
              } 
            
            tft.drawString("OZ",oz_x-19,oz_y-15,4);
            tft.drawFloat(o3,3,oz_x-14,oz_y+10,1);

            
          }  
        } else { 
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str()); 
        } 
         
        http.end(); 
         
   
    }
}

