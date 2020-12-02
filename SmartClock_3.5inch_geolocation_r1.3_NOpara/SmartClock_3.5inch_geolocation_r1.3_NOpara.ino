#include <ESP8266WiFi.h> 
#include <TFT_eSPI.h> 
#include <WiFiManager.h>
#include <ESP8266HTTPClient.h> 
#include <WiFiUdp.h> 
//#include <ArduinoJson.h> 
#include <SimpleTimer.h>
#include <TimeLib.h> 

#include "WifiLocation.h"//for geolocation

//figures or icons to be used
#include "ozongood.h"
#include "ozonnormal.h"
#include "ozonbad.h"
#include "ozonworst.h"
#include "ozonna.h"

#include "dust25good.h"
#include "dust25normal.h"
#include "dust25bad.h"
#include "dust25worst.h"
#include "dust25na.h"
#include "dustError.h"

#include "dust10good.h"
#include "dust10normal.h"
#include "dust10bad.h"
#include "dust10worst.h"
#include "dust10na.h"

#include "Clear.h"
#include "Cloudy1.h"
#include "Cloudy2.h"
#include "Rain.h"
#include "Snow.h"

//my own figure to show
#include "jeewon.h"
#include "Happy.h"
#include "taeyul.h"

//Fonts to be used
#include "SquadaOne_Regular70pt7b.h"
#include "SquadaOne_Regular26pt7b.h"
#include "SquadaOne_Regular20pt7b.h"
#include "SquadaOne_Regular19pt7b.h"
#include "SquadaOne_Regular18pt7b.h"
#include "SquadaOne_Regular16pt7b.h"
#include "SquadaOne_Regular14pt7b.h"
#include "SquadaOne_Regular6pt7b.h"
#include "Dhurjati_Regular12pt7b.h"
#include "GreatVibes_Regular18pt7b.h"

//////////////RGB888to565/////
uint16_t RGB888to565(uint32_t RGB888){
  uint16_t RGB565 = 0;
  RGB565 = (((RGB888&0xf80000)>>8) + ((RGB888&0xfc00)>>5) + ((RGB888&0xf8)>>3));
  return RGB565;
}

//variable setting
uint32_t titleColor = RGB888to565(0x2F5597);//0x2167; //background color of title region
uint32_t timeColor = 0x39C7;//0x4A69; //background color of time region
uint32_t dustColor = 0x1B72; //background color of dust region

uint32_t hotColor30 = RGB888to565(0xff0404);///0xE1C1;//background color of tempature region when 30C<=t
uint32_t hotColor28 = RGB888to565(0xee9f0f);//0x35E8;//background color of tempature region when 28<=t<30C
uint32_t mildColor = 0x09DC;//background color of tempature region when 20<t<28C,blue color
uint32_t mildColor20 = RGB888to565(0x193982);//background color of tempature region when 10<t<=20C
uint32_t coldColor10 = RGB888to565(0x091E53);//0x04DE;//background color of tempature region when 0<t<=10C
uint32_t coldColor0 = RGB888to565(0x020202);//091E53);//0x09DC;//background color of tempature region when t<=0C

uint32_t targetTime = 0; 
byte ohh = 99, omm = 99, oss = 99, owday=99;
short udpPort = 2390; // local port to listen for UDP packets 
const char* ntpServerName = "time.google.com"; 

// 공공 데이터 포털  서비스키 
// https://www.data.go.kr/dataset/15000099/openapi.do kma 공공데이터 API 신청
// https://www.data.go.kr/dataset/15000581/openapi.do 에어코리아 API 신청, 측정소정보조회서비스 & 대기오염정보조회서비스
String ServiceKey = "8ketBY9wZ%2Fr8aUYmfZiX46zlvcsHSvy5Lw37mjeZmmanq1fZdTBX17SyJ%2BGg1y6n994DZmkX0lMoThAnnxIYRw%3D%3D";

//google map api 서비스키, geolocation
//https://cloud.google.com/maps-platform/ api신청
const char* googleApiKey = "AIzaSyCRZQekWNKbqgTLDyhuvgTpXsYLtPk4kFc";
WifiLocation location(googleApiKey);

short nx=61, ny=119;
double tmx, tmy; 
String stationList[3] = {"영통동","동탄","인계동"};

//야간 LCD back light 어둡게 설정하는 시간 셋팅
char hourDimStart[3] = "0";
char hourDimStop[3] = "6";

char base_date[11]; 
char base_time[5]; 
char base_datef[11]; 
char base_timef[5]; 

const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message 
byte packetBuffer[ NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets 

// Libraries assign
IPAddress timeServerIP; 
SimpleTimer timer;
TFT_eSPI tft = TFT_eSPI();
WiFiUDP udp;   
WiFiManager wifiManager;

void setup() { 
  
  pinMode(D1,OUTPUT);
  digitalWrite(D1,HIGH);
  
  Serial.begin(115200); 
  
  tft.init();
  tft.setRotation(3);
  tft.setSwapBytes(true);
  tft.fillScreen(TFT_BLACK);
  
  tft.setTextSize(1);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK); 
  tft.setFreeFont(&Dhurjati_Regular12pt7b);

  //WiFi setup guide to show
  int xpos_intr=5, ypos_intr=5;
  tft.drawString("If this is the first time to connect your WiFi,",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
  tft.drawString("setup your WiFi information using your smartphone",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight();
  tft.drawString("1. Go to your wifi setup on the smartphone menu",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
  tft.drawString("2. Scan you wifi around you",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
  tft.drawString("3. Find and click 'Jason's Device'",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
  tft.drawString("4. Click http://192.168.4.1 or AP management",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
  tft.drawString("5. Click Configure WiFi",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
  tft.drawString("6. Click AP name you want, and insert AP password",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
  tft.drawString("7. Click Save",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
  tft.drawString("This setup is needed only one time when changing AP",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight();
  tft.setTextColor(TFT_WHITE, TFT_BLACK); 
  tft.drawString("If you have any difficulties,",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
  tft.drawString("Please contact iksanman@hotmail.com",xpos_intr,ypos_intr);

  

  //WiFi setup using wifiManager
  //WiFiManagerParameter custom_hourDimStart("DimStarthour","Dimming start hour in 24h format",hourDimStart,3);
  //WiFiManagerParameter custom_hourDimStop("DimStophour","Dimming stop  hour in 24h format",hourDimStop,3);

  //wifiManager.addParameter(&custom_hourDimStart);
  //wifiManager.addParameter(&custom_hourDimStop);
  
  //reset settings - for testing
  //wifiManager.resetSettings();
  
  wifiManager.autoConnect("Jason's Device");
  //if you get here you have connected to the WiFi
  Serial.println("WiFi connected... :)");
  
  //strcpy(hourDimStart, custom_hourDimStart.getValue());
  //strcpy(hourDimStop, custom_hourDimStop.getValue());

  Serial.printf("hourDimStart: %d\n",atoi(hourDimStart));
  Serial.printf("hourDimStop: %d\n",atoi(hourDimStop));


  ////geolocation from google map/////
  location_t loc = location.getGeoFromWiFi();

  Serial.println("Location request data");
  Serial.println(location.getSurroundingWiFiJson());
  Serial.println("Latitude: " + String(loc.lat, 7));
  Serial.println("Longitude: " + String(loc.lon, 7));
  Serial.println("Accuracy: " + String(loc.accuracy));
  /////end of geolocation/////
  
  tmx=loc.lon, tmy=loc.lat;
  double dnx=loc.lon, dny=loc.lat;

  Geo2xy(&dnx, &dny); //경도위도를 x,y 좌표로 변경, 일기예보용
  nx=(int)dnx, ny=(int)dny;
  Geo2Tm(&tmx, &tmy); //경도위도를 TM좌표계로 변경, 미세먼지용
  
  Serial.println("N_X: "+String(nx)+"  N_Y: "+String(ny));
  Serial.println("TM_X: "+String(tmx)+"  TM_Y: "+String(tmy));
  
  findNstation();//nx, ny를이용하여 근처 측정소 이름 찾음

  //Starting UDP
  udp.begin(udpPort); 
  Serial.print("Local port: "); 
  Serial.println(udp.localPort()); 
  
  ////////disiplay frame initiallization//////////////
  tft.fillScreen(TFT_BLACK);  //refresh screen
  tft.fillRect(0,0,480,34,titleColor); //타이틀영역 초기화
  tft.pushImage(0,34,cleanWidth,cleanHeight,clean);//날씨영역 초기화
  tft.fillRect(147,34,480-146,166-34,timeColor); //hhmm 영역 초기화
  tft.fillRect(147,166,333,78,mildColor); //온도영역 초기화
  tft.fillRect(147,166+77,480-146,320-166-77,dustColor); //먼지 오존 영역 초기화
  //tft.pushImage(0,0,taeyulWidth,taeyulHeight,taeyul);//지원세찬 대문이름  
  //tft.pushImage(5,0,jeewonWidth,jeewonHeight,jeewon);//지원이화이팅 대문이름 
  tft.pushImage(0,3,happyWidth,happyHeight,happy);//행복한우리집 대문이름 
 
  //initial data update
  ntp_update();
  check_kma();
  check_air();

  //update interval
  timer.setInterval(60000*10,check_kma);   //check every 10minutes
  timer.setInterval(60000*21,check_air);   //check every 30minutes
  timer.setInterval(60000*60*6,ntp_update); //update every 6hours
  
} 

void loop() { 
  time_display();
  timer.run();   
} 

//////////////////////////시간표시//////////////////////////////////////
void time_display(){
  
  uint8_t  ss = second(), mm = minute(), hh = hour(), wday=weekday(); //0~6
      
  int xdate=255,ydate=1,ydateEnd=33;  
  
  int xpos = 150, ypos = 42, yEnd=145+15, xadd=4; // time;Top left corner ot clock text
  int xsecs =420, ysecs=ypos+10, ysecsEnd=104, xCenter=xpos+(xsecs-xpos)/2-3, xEnd=xsecs-1;
  int xapm=xsecs, yapm=ysecsEnd+1; 

  if(wday!=owday){ //하루에 한번씩
    owday=wday;
    
    //tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE,titleColor);
    // tft.setTextDatum(TL_DATUM);//text allign to TC
    
    tft.setFreeFont(&SquadaOne_Regular19pt7b);
    //tft.setCursor(xpos_date,ypos_date);
    tft.fillRect(xdate,0,480-xdate,ydateEnd,titleColor); //date이전정보지우기
    xdate+=tft.drawNumber(year(),xdate,ydate); xdate+=tft.drawChar('.',xdate,ydateEnd-5);
    
    if (month() < 10) xdate+=tft.drawNumber(0,xdate,ydate);
    xdate+=tft.drawNumber(month(),xdate,ydate);
    xdate+=tft.drawChar('.',xdate,ydateEnd-5);
    
    if (day() < 10) xdate+=tft.drawNumber(0,xdate,ydate);
    xdate+=tft.drawNumber(day(),xdate,ydate);
    xdate+=tft.drawChar(' ',xdate,ydateEnd-5);
    
    tft.drawString(dayShortStr(weekday()),xdate,ydate);
  }
        
  if (hh != ohh) { //1시간에 한번씩
    
    ohh = hh;
    tft.setTextPadding(0);
    tft.setFreeFont(&SquadaOne_Regular26pt7b);
    tft.setTextColor(TFT_YELLOW, timeColor);
    tft.fillRect(xapm,yapm,480-xapm,yEnd-yapm,timeColor); //am pm이전정보지우기0x0087
    
    if (hh >= 12) tft.drawString("PM", xapm, yapm); // Draw PM
    else tft.drawString("AM", xapm, yapm); // Draw AM
  
    ///시간에 따른 디스플레이 밝기 조절
    if (atoi(hourDimStart) > atoi(hourDimStop)) {
      if (hh >= atoi(hourDimStart) || hh < atoi(hourDimStop)) analogWrite(D1,80);
      else digitalWrite(D1,HIGH);
    }
    else {
      if (hh >= atoi(hourDimStart) && hh < atoi(hourDimStop)) analogWrite(D1,80);
      else digitalWrite(D1,HIGH);
    }
    
    
  }
  
  // hh:mm시간 업데이트
  if (mm != omm) { // 1분에 한번
    omm = mm;
    //hh = hour();
    if (hh > 12) hh = hh-12; //roll-over 12hour
    
    //tft.setTextSize(1);
    tft.setTextColor(TFT_YELLOW,timeColor);
    tft.setFreeFont(&SquadaOne_Regular70pt7b);
    tft.setTextPadding(0);
    tft.setTextColor(TFT_YELLOW,timeColor);
  
    tft.fillRect(xpos,ypos,xEnd-xpos+1,yEnd-ypos,timeColor); //hhmm이전정보지우기
    
    char hh_t[10]; 
    dtostrf(hh, 0, 0, hh_t); 
    // Draw hours and minutes
    xadd += tft.drawRightString(hh_t,xCenter-xadd,ypos,1);             // Draw hours
    if (hh < 10) tft.drawRightString("0",xCenter-xadd,ypos,1); // Add hours leading zero for 24 hr clock
    
    tft.setFreeFont(&SquadaOne_Regular26pt7b);
    tft.setTextPadding(10);
    tft.drawChar('.',xCenter,ypos+75,1);
    xCenter += tft.drawChar('.', xCenter,ypos+40);
    
    tft.setTextPadding(0);
    tft.setFreeFont(&SquadaOne_Regular70pt7b);
    if (mm < 10) xCenter += tft.drawNumber(0,xCenter,ypos); // Add minutes leading zero
    tft.drawNumber(mm,xCenter,ypos);             // Draw minutes
  }
      
  if (ss != oss) {  // 1초에 한번씩
    oss = ss;
    //sec 업데이트
    tft.setTextPadding(0);
    tft.setFreeFont(&SquadaOne_Regular26pt7b);
    tft.setTextColor(TFT_YELLOW, timeColor);
    tft.fillRect(xsecs,ysecs,480-xsecs,yapm-ysecs-1,timeColor); //sec이전정보지우기
    if (ss < 10) xsecs += tft.drawNumber(0, xsecs, ysecs); // Add leading zero
    tft.drawNumber(ss, xsecs, ysecs);                     // Draw secondsxpos = xsecs;    
  }
}



//////////////////////////////////////////////////////////////////
////////////////////////////////////////////날씨정보//////////////
void check_kma(){
   //           온도습도바람정보표시
  int xtemp=150,ytemp=198,xtempEnd=220+25,ytempEnd=240;//온도정보영역
  int xhumid=260,yhumid=ytemp,xhumidEnd=318+20,yhumidEnd=ytempEnd;//습도정보영역
  int xwind=370,ywind=ytemp,xwindEnd=427,ywindEnd=ytempEnd;//바람정보영역
 /* 
  tft.setTextColor(TFT_WHITE);
  tft.setFreeFont(&Dhurjati_Regular12pt7b);
  //tft.setFreeFont(&Dhurjati_Regular12pt7b);
  tft.drawString("TEMPERATURE",153,170);tft.drawString("o",xtempEnd+3,ytemp-10);
  tft.drawString("HUMIDITY",310,170);
  tft.drawString("WIND",410,170);
  tft.setFreeFont(&SquadaOne_Regular14pt7b);
  tft.drawString("C",xtempEnd+14,ytemp);
  tft.drawString("%RH",xhumidEnd,yhumid);
  tft.drawString("m/s",xwindEnd+2,ywind); */
  
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(1);
  
  char time_string[20]; 
   time_t t = now(); 
   sprintf(time_string, "현재 : %d-%02d-%02d %02d:%02d:%02d", year(t), month(t), day(t), hour(t), minute(t), second(t)); 
   Serial.println(time_string);  
      
     t = t-60*40; //초단기실황고려, base_time:매시정각, 40분이전
   sprintf(time_string, "기준 : %d-%02d-%02d %02d:%02d:%02d", year(t), month(t), day(t), hour(t), minute(t), second(t)); 
   sprintf(base_date, "%d%02d%02d", year(t), month(t), day(t)); 
   sprintf(base_time, "%02d00", hour(t)); 
   Serial.println(t);
   Serial.println(time_string); 
   Serial.println(base_date); 
   Serial.println(base_time); 
   //초단기예보시간고려 
   t=t+60*25-60*30; //base_time:매시30분,api:15분후제공
   sprintf(base_datef, "%d%02d%02d", year(t), month(t), day(t)); 
   sprintf(base_timef, "%02d30", hour(t));
   
   HTTPClient http; 
   
//------------------------초단기실황 ----
        String url = "http://apis.data.go.kr/1360000/VilageFcstInfoService/getUltraSrtNcst?"; 
        url += "ServiceKey="+ServiceKey; 
 //       url += "&ServiceKey=SERVICE_KEY"; 
        url += "&base_date="+String(base_date); 
        url += "&base_time="+String(base_time); 
        url += "&nx="+(String)nx; 
        url += "&ny="+(String)ny; //화성시 반월동 61,119, 서초구양재동 61,125, 동백 63,120 신길3동 59,125 내손2동 60,123
        url += "&numOfRows=10"; 
        url += "&pageNo=1"; 
        //url += "&dataType=json"; 
//----------------초단기예보--
       String url2 = "http://apis.data.go.kr/1360000/VilageFcstInfoService/getUltraSrtFcst?"; 
        url2 += "ServiceKey="+ServiceKey; 
 //       url += "&ServiceKey=SERVICE_KEY"; 
        url2 += "&base_date="+String(base_datef); 
        url2 += "&base_time="+String(base_timef); 
        url2 += "&nx="+(String)nx; 
        url2 += "&ny="+(String)ny; //화성시 반월동 61,119, 서초구양재동 61,125, 동백 63,120 신길3동 59,125
        url2 += "&numOfRows=10"; 
        url2 += "&pageNo=2"; 
        //url2 += "&dataType=json";       
 //--------------------        
        http.begin(url); 
        Serial.printf("[HTTP] URL: %s\n",url.c_str()); 
         
        // start connection and send HTTP header 
        int httpCode;
        for(int i=0;i<10;i++){
          httpCode = http.GET();
          Serial.printf("waiting http response..code:%d\n",httpCode);
          if(httpCode > 0) break;
        }
        // httpCode will be negative on error 
        if(httpCode > 0) { 
          // HTTP header has been send and Server response header has been handled 
          Serial.printf("[HTTP] GET... code: %d\n", httpCode); 
           
          // file found at server 
          if(httpCode == HTTP_CODE_OK) { 
            String payload = http.getString(); 
            http.end();
            
            //---------초단기예보--
            http.begin(url2);
            Serial.printf("[HTTP] URL2: %s\n",url2.c_str());
            for(int i=0;i<5;i++){
              httpCode = http.GET();
              Serial.println("waiting http response..");
              if(httpCode > 0) break;
              
            }
            Serial.printf("[HTTP] GET... code2: %d\n", httpCode);
            String payload2=http.getString();
  
            Serial.printf("payload: %s\n",payload.c_str());
            Serial.printf("payload2: %s\n",payload2.c_str()); 

            int result_code = findString(payload,"<resultCode>","</resultCode>").toInt(); 
            String result_msg  = findString(payload,"<resultMsg>","</resultMsg>"); 

            if(result_code != 0) { 
              Serial.printf("ERROR : Result Code %d\n%s\n",result_code,result_msg.c_str()); 
              delay(6000*5); 
              return; 
            } else { 
              Serial.printf("SUCC : Result Code %d\n%s\n",result_code,result_msg.c_str()); 
            } 
            
            char w_date[20]; // 발표일 
             //----------------초단기실황-
            String payload_temp = payload.substring(payload.indexOf("T1H"),payload.indexOf("T1H")+120);
            String payload_reh = payload.substring(payload.indexOf("REH"),payload.indexOf("REH")+120);
            String payload_pty = payload.substring(payload.indexOf("PTY"),payload.indexOf("PTY")+120);
            String payload_rn1 = payload.substring(payload.indexOf("RN1"),payload.indexOf("RN1")+120);
            String payload_ws = payload.substring(payload.indexOf("WSD"),payload.indexOf("WSD")+120);
            Serial.printf("payload_temp: %s\n",payload_temp.c_str());
            Serial.printf("payload_reh: %s\n",payload_reh.c_str());
            Serial.printf("payload_pty: %s\n",payload_pty.c_str());
            Serial.printf("payload_rn1: %s\n",payload_rn1.c_str());
            Serial.printf("payload_ws: %s\n",payload_ws.c_str());
             

            ////----초단기예보--
            int sky_start = payload2.indexOf("SKY");
            Serial.println(sky_start);
            payload2 = payload2.substring(sky_start,sky_start+100);
            Serial.printf("payload2_sky: %s\n",payload2.c_str()); 
            
            
            float w_temp = findString(payload_temp,"<obsrValue>","</obsrValue>").toFloat(); // 온도
            
            ///////refresh temp region depending on the temperature
            if(w_temp >=30) tft.fillRect(147,166,333,78,hotColor30);
            else if(w_temp >= 28) tft.fillRect(147,166,333,78,hotColor28);
            else if(w_temp <= 0) tft.fillRect(147,166,333,78,coldColor0);
            else if(w_temp <= 10) tft.fillRect(147,166,333,78,coldColor10);
            else if(w_temp <= 20) tft.fillRect(147,166,333,78,mildColor20);
            else tft.fillRect(147,166,333,78,mildColor);
            
            tft.setTextColor(TFT_WHITE);
            tft.setFreeFont(&Dhurjati_Regular12pt7b);
            //tft.setFreeFont(&Dhurjati_Regular12pt7b);
            tft.drawString("TEMPERATURE",153,170);tft.drawString("o",xtempEnd+3,ytemp-10);
            tft.drawString("HUMIDITY",305,170);
            tft.drawString("WIND",410,170);
            tft.setFreeFont(&SquadaOne_Regular14pt7b);
            tft.drawString("C",xtempEnd+14,ytemp);
            tft.drawString("%RH",xhumidEnd,yhumid);
            tft.drawString("m/s",xwindEnd+2,ywind);
            
            int w_reh = findString(payload_reh,"<obsrValue>","</obsrValue>").toInt(); // 습도 
            int w_sky = findString(payload2,"<fcstValue>","</fcstValue>").toInt(); // 하늘 맑음(1), 구름조금(2삭제), 구름많음(3), 흐림(4) 
            int w_pty = findString(payload_pty,"<obsrValue>","</obsrValue>").toInt(); 
            // 강수형태(PTY) 코드 : 없음(0), 비(1), 비/눈(2), 눈(3) ,소나기(4추가)
            float w_rn1 = findString(payload_rn1,"<obsrValue>","</obsrValue>").toInt(); // 1시간 강수량
            float w_ws = findString(payload_ws,"<obsrValue>","</obsrValue>").toFloat(); // 풍속 

            Serial.printf("SKY: %d\n",w_sky);

            char w_temp_t[10]; 
            dtostrf(w_temp, 0, 1, w_temp_t);  
            char w_ws_t[10],w_rn1_t[10],w_reh_t[10];//,w_s06_t[10]; 
            dtostrf(w_ws, 0, 0, w_ws_t);dtostrf(w_reh,0,0,w_reh_t); //데이타를 스트링으로 변환(0,1이면 소수첫째자리까지)
            dtostrf(w_rn1, 0, 0, w_rn1_t);
            sprintf(w_rn1_t,"%s %s",w_rn1_t,"mm/h");//w_rn1_t에 w_rn1+mm/1h합치기

            char w_pty_str[20]; 

            ///날씨정보디스플레이
            int xpos_sky=0,ypos_sky=35,ypos_rn=275;
            int xpos_weather=24, ypos_weather=35+30;
            
            tft.setTextColor(TFT_WHITE);//,0x0087);
            tft.setFreeFont(&SquadaOne_Regular16pt7b);
            switch (w_pty) { 
                case 1: strcpy(w_pty_str,"Rain");
                  tft.pushImage(xpos_sky,ypos_sky,cleanWidth,cleanHeight,clean);
                  tft.pushImage(xpos_weather,ypos_weather,rainWidth,rainHeight,rain);
                  tft.drawCentreString(w_rn1_t,74,ypos_rn+10,1);break; 
                
                case 2: strcpy(w_pty_str,"Rain");
                  tft.pushImage(xpos_sky,ypos_sky,cleanWidth,cleanHeight,clean);
                  tft.pushImage(xpos_weather,ypos_weather,rainWidth,rainHeight,rain);
                  tft.drawCentreString(w_rn1_t,74,ypos_rn+10,1);break; 
                
                case 3: strcpy(w_pty_str,"Snow");
                  tft.pushImage(xpos_sky,ypos_sky,cleanWidth,cleanHeight,clean);
                  tft.pushImage(xpos_weather,ypos_weather,snowWidth,snowHeight,snow);
                  tft.setFreeFont(&GreatVibes_Regular18pt7b);
                  tft.drawCentreString("by Jason",74,ypos_rn,1);
                  break; 

                case 4: strcpy(w_pty_str,"Shower");
                  tft.pushImage(xpos_sky,ypos_sky,cleanWidth,cleanHeight,clean);
                  tft.pushImage(xpos_weather,ypos_weather,rainWidth,rainHeight,rain);
                  tft.drawCentreString(w_rn1_t,74,ypos_rn+10,1);break;
                
                default:  //강수형태가 0인경우
                  switch (w_sky) { 
                    case 1: strcpy(w_pty_str,"Clear");
                      tft.pushImage(xpos_sky,ypos_sky,cleanWidth,cleanHeight,clean);
                      break;
                    
                    case 3: strcpy(w_pty_str,"Cloudy");
                      tft.pushImage(xpos_sky,ypos_sky,cleanWidth,cleanHeight,clean);
                      tft.pushImage(xpos_weather,ypos_weather,cloudy1Width,cloudy1Height,cloudy1);
                      break; //기상1,3,4만 제공으로 변경됨
                    
                    case 4: strcpy(w_pty_str,"Dark");
                      tft.pushImage(xpos_sky,ypos_sky,cleanWidth,cleanHeight,clean);
                      tft.pushImage(xpos_weather,ypos_weather,cloudy2Width,cloudy2Height,cloudy2);
                      break; 
                    
                    default: strcpy(w_pty_str,"------");
                      break; 
                  }
                  
                  tft.setFreeFont(&GreatVibes_Regular18pt7b);
                  tft.drawCentreString("by Jason",74,ypos_rn,1); 
                  break; 
              } 

            Serial.printf("발표시각:%s  온도:%s  습도:%02d  하늘:%d  강수형태:%d %s  1시간강수량:%s  풍속:%s\n", 
                         w_date, w_temp_t,w_reh,w_sky,w_pty,w_pty_str,w_rn1_t,w_ws_t); 
                          

            
//            tft.pushImage(147,166,frametempWidth,frametempHeight,frametemp);//온도 습도 바람 영역 초기화
            
            //tft.fillRect(xtemp,ytemp,xtempEnd-xtemp,ytempEnd-ytemp,0x08EA); //이전 온도 지우고 다시 표시
            tft.setFreeFont(&SquadaOne_Regular26pt7b);
            tft.setTextColor(TFT_WHITE);
            tft.drawRightString(w_temp_t, xtempEnd, ytemp, 1);
            
            tft.setFreeFont(&SquadaOne_Regular26pt7b);
            tft.setTextColor(TFT_WHITE);           
            tft.drawRightString(w_reh_t,xhumidEnd-5,yhumid,1);

            tft.setFreeFont(&SquadaOne_Regular26pt7b);
            tft.setTextColor(TFT_WHITE);  
            tft.drawRightString(w_ws_t,xwindEnd-2,ywind,1);
    
          } 
        } else { 
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str()); 
        } 
         
        http.end(); 
         
}


//////////////////////////////////////////////////////////
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
 
}


/////////////////////////////////////////////////////////////
////////////////////////////////////////////대기정보//////////////
void check_air(){
  
  //tft.fillRect(147,166+77,480-146,320-166-77,dustColor); //먼지 오존 영역 초기화
  tft.setTextColor(TFT_BLUE,TFT_BLACK);
  tft.setTextSize(1);
 
  HTTPClient http; 

  int pm10Grade1h;
  String pm10Value;
  int pm25Grade1h;
  String pm25Value;
  int o3Grade;
  float o3Value;
  
  for(int i=0;i<3;i++) {
    String url = "http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getMsrstnAcctoRltmMesureDnsty?"; 
    url += "stationName="+stationList[i]; 
    url += "&dataTerm=daily"; //daily, month, 3month
    url += "&pageNo=1"; 
    url += "&numOfRows=1"; 
    url += "&ServiceKey="+ServiceKey; //kma와 동일
    url += "&ver=1.3";
     
    http.begin(url); 
    Serial.printf("[HTTP] URL: %s\n",url.c_str()); 
     
    // start connection and send HTTP header 
    //int httpCode = http.GET(); 
    int httpCode;
    for(int i=0;i<3;i++){
      httpCode = http.GET();
      Serial.printf("waiting air http response..code:%d\n",httpCode);
      if(httpCode > 0) break;
    }
     
    // httpCode will be negative on error 
    if(httpCode > 0) { 
      // HTTP header has been send and Server response header has been handled 
      Serial.printf("[HTTP] GET... code: %d\n", httpCode); 
           
      // file found at server 
      if(httpCode == HTTP_CODE_OK) { 
        String payload = http.getString(); 
        Serial.println(payload); 

        http.end(); 

        //int air_data[5]; 

        String baseTime = findString(payload,F("<dataTime>"),F("</dataTime>"));
        pm10Grade1h = findString(payload,F("<pm10Grade1h>"),F("</pm10Grade1h>")).toInt();
        pm10Value = findString(payload,F("<pm10Value>"),F("</pm10Value>"));
        pm25Grade1h = findString(payload,F("<pm25Grade1h>"),F("</pm25Grade1h>")).toInt();
        pm25Value = findString(payload,F("<pm25Value>"),F("</pm25Value>"));
        o3Grade = findString(payload,F("<o3Grade>"),F("</o3Grade>")).toInt();
        o3Value = findString(payload,F("<o3Value>"),F("</o3Value>")).toFloat();
        
        Serial.printf("baseTime: %s\npm10Grade1h: %d\npm10Value: %s\npm25Grade1h: %d\npm25Value: %s\no3Grade: %d\no3Value: %03f\n", 
        baseTime.c_str(),pm10Grade1h,pm10Value.c_str(),pm25Grade1h,pm25Value.c_str(),o3Grade,o3Value);
   
        if(pm25Grade1h > 0 && pm25Grade1h < 5 && pm10Grade1h >0 && pm10Grade1h <5){
          Serial.printf("Successfully got data from station # %s",stationList[i].c_str());
          //tft.drawString("#"+(String)i,5,30);
          break;
        }
      }
    }
    else Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str()); 
  }        
  ///end of for loop///

    
  int xpos_air10=154,ypos_air10=251;//,xpos_air10End=255,ypos_air10End=279;
  int xpos_air25=262,ypos_air25=251;//,xpos_air25End=363,ypos_air25End=279;
             
    //PM10  정보표시
  tft.setFreeFont(&SquadaOne_Regular16pt7b);
  switch (pm10Grade1h) { 
      case 1: tft.setTextColor(TFT_BLUE);
        tft.pushImage(xpos_air10,ypos_air10,dust10goodWidth,dust10goodHeight,dust10good);
        break; 
      
      case 2: tft.setTextColor(TFT_WHITE);
        tft.pushImage(xpos_air10,ypos_air10,dust10normalWidth,dust10normalHeight,dust10normal);
        break; 
      
      case 3: tft.setTextColor(TFT_PURPLE);
        tft.pushImage(xpos_air10,ypos_air10,dust10badWidth,dust10badHeight,dust10bad);
        break;
      
      case 4: tft.setTextColor(TFT_WHITE);
        tft.pushImage(xpos_air10,ypos_air10,dust10worstWidth,dust10worstHeight,dust10worst);
        break;
      
      default: tft.setTextColor(TFT_WHITE);
        pm10Value="--";
        tft.pushImage(xpos_air10,ypos_air10,dustErrorWidth,dustErrorHeight,dustError);
        break;
      
    } 

    tft.drawCentreString(pm10Value,xpos_air10+80,ypos_air10+5,1);//pm10 값 표시
   
   
  ///PM2.5정보표시
  
  switch (pm25Grade1h) { 
      case 1: tft.setTextColor(TFT_BLUE);
        tft.pushImage(xpos_air25,ypos_air25,dust25goodWidth,dust25goodHeight,dust25good);
        break;
       
      case 2: tft.setTextColor(TFT_WHITE);
        tft.pushImage(xpos_air25,ypos_air25,dust25normalWidth,dust25normalHeight,dust25normal);
        break;
       
      case 3: tft.setTextColor(TFT_PURPLE);
        tft.pushImage(xpos_air25,ypos_air25,dust25badWidth,dust25badHeight,dust25bad);
        break; 
      
      case 4: ;tft.setTextColor(TFT_WHITE);
        tft.pushImage(xpos_air25,ypos_air25,dust25worstWidth,dust25worstHeight,dust25worst);
        break;
      
      default:tft.setTextColor(TFT_WHITE);
        pm25Value="--";
        tft.pushImage(xpos_air25,ypos_air25,dustErrorWidth,dustErrorHeight,dustError);
        break;
    }

  tft.drawCentreString(pm25Value,xpos_air25+80,ypos_air25+5,1);//pm2.5 값표시

   //오존정보표시
  tft.setFreeFont(&SquadaOne_Regular14pt7b);
  int oz_x=369,oz_y=251;
  
  switch (o3Grade) { 
  
      case 1: tft.setTextColor(TFT_BLUE);
        tft.pushImage(oz_x,oz_y,ozongoodWidth,ozongoodHeight,ozongood);
        break; 
      
      case 2: tft.setTextColor(TFT_WHITE);
        tft.pushImage(oz_x,oz_y,ozonnormalWidth,ozonnormalHeight,ozonnormal);
        break; 
      
      case 3: tft.setTextColor(TFT_PURPLE);
        tft.pushImage(oz_x,oz_y,ozonbadWidth,ozonbadHeight,ozonbad);
        break; 
      
      case 4: tft.setTextColor(TFT_WHITE);
        tft.pushImage(oz_x,oz_y,ozonworstWidth,ozonworstHeight,ozonworst);
        break;
      
      default: tft.setTextColor(TFT_WHITE);
        //tft.pushImage(oz_x,oz_y,ozonnaWidth,ozonnaHeight,ozonna);
        break;
    } 
  
  tft.drawFloat(o3Value,2,oz_x+55,oz_y+5,1); 
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

////////////Geolocation///////////
void Geo2Tm(double *plon, double *plat)
{
    double lon, lat;
    lon = *plon;
    lat = *plat;
    lon = lon * PI / 180;
    lat = lat * PI / 180;
    int m_arScaleFactor = 1;
    double m_arLonCenter = 2.21661859489632;
    double m_arLatCenter = 0.663225115757845;
    float m_arFalseNorthing = 500000.0;
    float m_arFalseEasting = 200000.0;

    double x, y;
    double m_dDstInd;
    float m_arMajor = 6378137.0;
    double m_arMinor = 6356752.3142;

    double delta_lon; // Delta longitude (Given longitude - center longitude)
    double sin_phi, cos_phi; // sin and cos value
    double al, als; // temporary values
    double b, c, t, tq; // temporary values
    double con, n, ml; // cone constant, small m

    double temp = m_arMinor / m_arMajor;

    double m_dSrcEs = 1.0 - temp * temp;
    double m_dDstEs = 1.0 - temp * temp;
    double m_dDstEsp = m_dDstEs / (1.0 - m_dDstEs);
    double m_dDstE0 = 1.0 - 0.25 * m_dDstEs * (1.0 + m_dDstEs / 16.0 * (3.0 + 1.25 * m_dDstEs));
    double m_dDstE1 = 0.375 * m_dDstEs * (1.0 + 0.25 * m_dDstEs * (1.0 + 0.46875 * m_dDstEs));
    double m_dDstE2 = 0.05859375 * m_dDstEs * m_dDstEs * (1.0 + 0.75 * m_dDstEs);
    double m_dDstE3 = m_dDstEs * m_dDstEs * m_dDstEs * (35.0 / 3072.0);
    double m_dDstMl0 = m_arMajor * (m_dDstE0 * m_arLatCenter - m_dDstE1 * sin(2.0 * m_arLatCenter) + 
    m_dDstE2 * sin(4.0 * m_arLatCenter) - m_dDstE3 * sin(6.0 * m_arLatCenter));

    m_dDstInd = 0.0;

    delta_lon = lon - m_arLonCenter;
    sin_phi = sin(lat);
    cos_phi = cos(lat);

    b = 0;
    x = 0.5 * m_arMajor * m_arScaleFactor * log((1.0 + b) / (1.0 - b));
    con = acos(cos_phi * cos(delta_lon) / sqrt(1.0 - b * b));

    al = cos_phi * delta_lon;
    als = al * al;
    c = m_dDstEsp * cos_phi * cos_phi;
    tq = tan(lat);
    t = tq * tq;
    con = 1.0 - m_dDstEs * sin_phi * sin_phi;
    n = m_arMajor / sqrt(con);
    ml = m_arMajor * (m_dDstE0 * lat - m_dDstE1 * sin(2.0 * lat) + m_dDstE2 * sin(4.0 * lat) - m_dDstE3 * sin(6.0 * lat));

    x = m_arScaleFactor * n * al * (1.0 + als / 6.0 * (1.0 - t + c + als / 20.0 * (5.0 - 18.0 * t + t * t + 
    72.0 * c - 58.0 * m_dDstEsp))) + m_arFalseEasting;
    y = m_arScaleFactor * (ml - m_dDstMl0 + n * tq * (als * (0.5 + als / 24.0 * (5.0 - t + 9.0 * c + 4.0 * c * c + als / 30.0 * 
    (61.0 - 58.0 * t + t * t + 600.0 * c - 330.0 * m_dDstEsp))))) + m_arFalseNorthing;
    *plon = x;
    *plat = y;
} 


/////좌표계변환/////
void Geo2xy(double *px, double *py)
{
    double x, y;
    x = *px;
    y = *py;
    
    x = 17.713*x - 2189.1;
    y = 21.66*y -686.82;
    Serial.printf("x: %d, y: %d\n",x,y);

    *px = (int)x;
    *py = (int)y;
}

////find near stations for dust////
void findNstation() {
  
    String stationUrl = "http://openapi.airkorea.or.kr/openapi/services/rest/MsrstnInfoInqireSvc/getNearbyMsrstnList?";
    stationUrl += "tmX=" + String(tmx);
    stationUrl += "&tmY="+ String(tmy);
    stationUrl +="&ServiceKey=" +ServiceKey;

    HTTPClient http;
    http.begin(stationUrl);
    Serial.printf("[HTTP] URL: %s\n",stationUrl.c_str()); 
         
        // start connection and send HTTP header 
        int httpCode = http.GET();
         
        // httpCode will be negative on error 
        if(httpCode > 0) { 
          // HTTP header has been send and Server response header has been handled 
          Serial.printf("[HTTP] GET... code: %d\n", httpCode); 
           
          // file found at server 
          if(httpCode == HTTP_CODE_OK) { 
            String payload = http.getString(); 
            Serial.println(payload);  

            int stationName_start = 0;
            int stationName_end = 0;

            for(int i = 0; i < 3; i++){
              stationName_start = payload.indexOf(F("<stationName>"), stationName_start);
              stationName_end = payload.indexOf(F("</stationName>"), stationName_start);
              stationList[i] = payload.substring(stationName_start + 13, stationName_end);
              Serial.println(stationList[i]);
              stationName_start = stationName_end;
            }
          }
        }
}

//////////////////
String findString(String str, String findStart, String findEnd){
  int index_start = str.indexOf(findStart);
  int index_end = str.indexOf(findEnd);
  String findValue = str.substring(index_start +findStart.length(), index_end);
  return findValue;
}



