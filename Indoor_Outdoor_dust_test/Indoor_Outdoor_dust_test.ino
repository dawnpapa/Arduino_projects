#include <ESP8266WiFi.h> 
#include <TFT_eSPI.h> 
#include <WiFiManager.h>
#include <ESP8266HTTPClient.h> 
#include <WiFiUdp.h> 
#include <SimpleTimer.h>
#include <TimeLib.h>
 
#include <SPI.h>
#include "PMS.h"
#include <SoftwareSerial.h>
#include "WifiLocation.h"//for geolocation

//figures or icons to be used
#include "dust25good.h"
#include "dust25normal.h"
#include "dust25bad.h"
#include "dust25worst.h"
#include "dustError.h"

#include "dust10good.h"
#include "dust10normal.h"
#include "dust10bad.h"
#include "dust10worst.h"

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

#include "alert.h" // Out of range alert icon
#include "colors.h" //pre-assigned colors


//////////////RGB888to565/////
uint16_t RGB888to565(uint32_t RGB888){
  uint16_t RGB565 = 0;
  RGB565 = (((RGB888&0xf80000)>>8) + ((RGB888&0xfc00)>>5) + ((RGB888&0xf8)>>3));
  return RGB565;
}

//wificallback
void configModeCallback (WiFiManager *wifiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());

  Serial.println(wifiManager->getConfigPortalSSID());
}

//variable setting
uint32_t dustColor = 0x1B72; //background color of dust region
uint32_t targetTime = 0; 
//
//byte ohh = 99, omm = 99, oss = 99, owday=99;
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

short nx=61, ny=119;//일기예보시 사용
double tmx, tmy; //근처 미세먼지 station찾을때 사용
String stationList[3] = {"영통동","동탄","인계동"};

//야간 LCD back light 어둡게 설정하는 시간 셋팅
char hourDimStart[3] = "0";
char hourDimStop[3] = "6";

char base_date[11], base_time[5], base_datef[11], base_timef[5]; 

const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message 
byte packetBuffer[ NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets 

// this is the only external variable used by the graph
boolean first = true;
//double ox , oy1, oy2, oy3;
unsigned long omm=0;
static int recordInterval = 1;//recording interval minute
static int minTohour=60;//unit:minute
static int xmax=0,xmaxtemp=0;
//pms variables
byte dust10[601],dust25[601],dust1[601];

boolean range_error = 0;
boolean offlineMode = 0;

// Libraries assign
TFT_eSPI tft = TFT_eSPI();
IPAddress timeServerIP; 
SimpleTimer timer;
WiFiUDP udp;   
WiFiManager wifiManager;
SoftwareSerial mySerial(4, 12); // D2RX, D6TX

PMS pms(mySerial);
PMS::DATA data;


void setup() {

  /*for(int i=0;i<=601;i++){
    dust10[i] = 0;
    dust25[i] = 0;
    dust1[i] = 0;
  }*/
  
  pinMode(D1,OUTPUT);
  digitalWrite(D1,HIGH); 
  
  tft.init();
  tft.setRotation(3);
  tft.setSwapBytes(true);
  tft.fillScreen(BLACK); 
  
  Serial.begin(115200);
  mySerial.begin(9600);  // D2,D6 pin on ESP-12E Development Board
  
  tft.setTextSize(1);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK); 
  tft.setFreeFont(&Dhurjati_Regular12pt7b);

  //WiFi setup guide to show
  int xpos_intr=5, ypos_intr=5;
  tft.drawString("If this is the first time to connect your WiFi,",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
  tft.drawString("setup your WiFi information using your smartphone",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
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
  tft.setTextColor(TFT_RED, TFT_BLACK); 
  tft.drawString("After 60sec without setup, it runs Offline-Mode",xpos_intr,ypos_intr);
  
  ypos_intr += tft.fontHeight()/2;
  tft.setTextColor(TFT_WHITE, TFT_BLACK); 
  tft.drawString("If you have any difficulties,",xpos_intr,ypos_intr);
  ypos_intr += tft.fontHeight()/2;
  tft.drawString("Please contact iksanman@hotmail.com",xpos_intr,ypos_intr);

  //wifiManager.resetSettings();
  wifiManager.setConfigPortalTimeout(20);//setConfigPortalTimeout,setTimeout
  //wifiManager.setAPCallback(configModeCallback);
  
  if(wifiManager.startConfigPortal("Jason's Device")){//Online-mode, startConfigPortal,autoConnect
    //if you get here you have connected to the WiFi
    Serial.println("WiFi connected... :)");
    tft.fillScreen(TFT_BLACK);
    tft.drawString("WiFi connected !",100,200,4);
    
    ////geolocation from google map/////
    location_t loc = location.getGeoFromWiFi();
    tmx=loc.lon, tmy=loc.lat;
    double dnx=loc.lon, dny=loc.lat;
  
    Serial.println("Location request data");
    Serial.println(location.getSurroundingWiFiJson());
    Serial.println("Latitude: " + String(tmy, 7));
    Serial.println("Longitude: " + String(tmx, 7));
    Serial.println("Accuracy: " + String(loc.accuracy));
    /////end of geolocation/////
  
    Geo2xy(&dnx, &dny); //경도위도를 x,y 좌표로 변경, 일기예보용
    nx=(int)dnx, ny=(int)dny;
    Geo2Tm(&tmx, &tmy); //경도위도를 TM좌표계로 변경, 미세먼지용
    
    Serial.println("N_X: "+String(nx)+"  N_Y: "+String(ny));
    Serial.println("TM_X: "+String(tmx)+"  TM_Y: "+String(tmy));
    
    tft.fillScreen(TFT_BLACK);
    tft.drawString("Latitude:"+ String(tmy,7),100,100,4);
    tft.drawString("Longitude:"+ String(tmx,7),100,130,4);
    tft.drawString("nx:"+ String(nx),100,180,4);
    tft.drawString("ny:"+ String(ny),100,210,4);
    delay(5000);
    
    findNstation();///nx, ny를이용하여 근처 측정소 이름 찾음
  
    //Starting UDP
    udp.begin(udpPort); 
    Serial.print("Local port: "); 
    Serial.println(udp.localPort()); 
    
    tft.fillScreen(TFT_BLACK);
    tft.drawString("Running ONline-Mode",100,200,4);
    delay(2000);
    
    //tft.fillRect(0,0,480-146,320-166-77,dustColor); //먼지 오존 영역 초기화
    //initial data update
    ntp_update();
    //check_kma();
    check_air();
    //update interval
    //timer.setInterval(60000*10,check_kma);   //check every 10minutes
    timer.setInterval(60000*21,check_air);   //check every 30minutes
    timer.setInterval(60000*60*6,ntp_update); //update every 6hours
  } 
  else {
    Serial.println("failed to connect and hit timeout");
    tft.fillScreen(TFT_BLACK);
    tft.drawString("Running OFFline-Mode",100,200,4);
    delay(2000);
    offlineMode = 1;
  }
  

  //tft.fillScreen(TFT_BLACK);
  Serial.printf("hourDimStart: %d\n",atoi(hourDimStart));
  Serial.printf("hourDimStop: %d\n",atoi(hourDimStop));
}


void loop(void) {
  if(!offlineMode) timer.run();
  
  int x, y1, y2, y3, ystep;
  int xpos = 120, ypos = 5, gap = 6, radius = 56;
  if(offlineMode) xpos = 60;
  unsigned long mm = millis()/1000/60;
  static uint16_t y1sum=0, y2sum=0, y3sum=0;
  static uint16_t y1avg,y2avg,y3avg,count=0;
  double xunit,xstep;
  String xtime;
  byte hh = hour();
  
  ///시간에 따른 디스플레이 밝기 조절
  if(!offlineMode){
    if (atoi(hourDimStart) > atoi(hourDimStop)) {
    if (hh >= atoi(hourDimStart) || hh < atoi(hourDimStop)) analogWrite(D1,80);
    else digitalWrite(D1,HIGH);
    }
    else {
      if (hh >= atoi(hourDimStart) && hh < atoi(hourDimStop)) analogWrite(D1,80);
      else digitalWrite(D1,HIGH);
    }
  }
  
  
  
  if(pms.read(data)){
    count ++;
    Serial.print("\nNow: ");Serial.println(mm);
    Serial.print("count: ");Serial.println(count);
    dust10[0]=data.PM_AE_UG_10_0;
    y1sum = y1sum + dust10[0];
    y1avg =y1sum/count;
    //Serial.print("PM 10 (ug/m3): ");
    //Serial.println(dust10[0]);
    //Serial.println(y1avg);

    dust25[0]=data.PM_AE_UG_2_5;
    y2sum = y2sum + dust25[0];
    y2avg =y2sum/count;
    //Serial.print("PM 2.5 (ug/m3): ");
    //Serial.println(dust25[0]);
    //Serial.println(y2avg);

    dust1[0]=data.PM_AE_UG_1_0;
    y3sum = y3sum + dust1[0];
    y3avg =y3sum/count;
    //Serial.print("PM 1.0 (ug/m3): ");
    //Serial.println(dust1[0]);
    //Serial.println(y3avg);
    
    xpos = gap +ringMeter(dust10[0], 0, 151, xpos, ypos, radius, "PM10", BLUE2RED,YELLOW); // Draw analogue meter
    xpos = gap +ringMeter(dust25[0], 0, 76, xpos, ypos, radius, "PM2.5", BLUE2RED,CYAN); // Draw analogue meter
    xpos = gap +ringMeter(dust1[0], 0, 76, xpos, ypos, radius, "PM1.0", BLUE2RED,GREEN); // Draw analogue meter
    
    dust10[0] =y1avg;
    dust25[0] =y2avg;
    dust1[0] =y3avg;

    ///data logging////
    if(mm >= omm + recordInterval || first){
      first=false;
      Serial.println("recording to graph...");
      /*//label
      tft.setTextSize(1);
      tft.setTextColor(YELLOW, BLACK);
      tft.drawString("PM10",430,80,2);
      tft.setTextColor(CYAN, BLACK);
      tft.drawString("PM2.5",430,95,2);
      tft.setTextColor(GREEN, BLACK);
      tft.drawString("PM1.0",430,110,2);*/

      tft.setTextColor(WHITE, BLACK);
      tft.drawString("Realtime Dust Monitoring",xpos-170,120,2);
      
      int ymax=0;
      int xmax2=0;
      xmax = mm/recordInterval/10*10 +10;//10분단위로 
      xmax = min(xmax,600);//max 600분까지만 표시
      for (x = 0; x <= xmax; x++){
        y1 = dust10[(int)x];
        y2 = dust25[(int)x];
        y3 = dust1[(int)x];
        ymax = max(ymax,(int)y1);
        ymax = max(ymax,(int)y2); 
        ymax = max(ymax,(int)y3);
      }
        ymax = ymax/10*10+10;
        ymax = max(ymax,60);
        if(ymax >= 200) {
          ymax =ymax/40*40+40;
          ystep = 40;
        }
        else if(ymax >=100){
          ymax =ymax/20*20+20;
          ystep = 20;
        }
        else ystep =10;
        Serial.print("ymax: ");Serial.println(ymax);
        Serial.print("xmax: ");Serial.println(xmax);
        
      for (x = 0; x <= xmax; x++){
        y1 = dust10[(int)x];
        y2 = dust25[(int)x];
        y3 = dust1[(int)x];
        
        if(xmax >= minTohour){
          xunit = (float)x/60;//converting to hour unit
          xtime = "Time(hour)";
          xmax2 = (mm/60*60+60)/60;
          Serial.println(xmax2);
          xmax2 = min(xmax2,10);
          if(xmax2 >=5) xstep = 1;
          else xstep = 0.5;
        }
        else {
          xunit = x;//minute unit
          xtime = "Time(minute)";
          xmax2=xmax;
          if(xmax < 40) xstep = xmax/10;
          else xstep = 10;
        }
        
        Graph3y(tft, xunit, y1, y2, y3, 40, 288, 410, 150, xmax2, 0, -xstep, 0, ymax, ystep, 
        "", xtime, "", GREY, RED, YELLOW, CYAN, GREEN, WHITE, BLACK,x);
        
      }
    
      for(int i=xmax;i>0;i=i-1){
        dust10[i]=dust10[i-1];
        dust25[i]=dust25[i-1];
        dust1[i]=dust1[i-1];
        
      } 
      omm = mm;
      count = 0;
      y1sum =0, y2sum=0,y3sum=0;
    }
  }

}

// #########################################################################
//  History graph
// #########################################################################
void Graph3y(TFT_eSPI &d, double x, double y1,double y2,double y3,double gx, double gy, double w, double h, double xlo, 
double xhi, double xinc, double ylo, double yhi, double yinc, String title, String xlabel, String ylabel, 
unsigned int gcolor, unsigned int acolor, unsigned int p1color, unsigned int p2color, unsigned int p3color, 
unsigned int tcolor, unsigned int bcolor, unsigned int firstData) {

  double ydiv, xdiv;
  static double ox , oy1, oy2, oy3;
  // initialize old x and old y in order to draw the first point of the graph
  // but save the transformed value
  // note my transform funcition is the same as the map function, except the map uses long and we need doubles
  //static double ox = (x - xlo) * ( w) / (xhi - xlo) + gx;
  //static double oy = (y - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  double i;
  double temp;
  int rot, newrot;
  
  if(firstData == 0){
    d.fillRect(gx-40,gy-h-10,w+45,h+40+10,BLACK);//refresh graph region
    d.fillRect(gx,gy-h,w,h,DKBLUE);
    ////// draw y scale
    for ( i = ylo; i <= yhi; i += yinc) {
      // compute the transform
      temp =  (i - ylo) * (gy - h - gy) / (yhi - ylo) + gy;

      if (i == 0) {
        d.drawLine(gx, temp, gx + w, temp, acolor);
      }
      else {
        d.drawLine(gx, temp, gx + w, temp, gcolor);
      }

      d.setTextSize(1);
      d.setTextColor(tcolor, bcolor);
      tft.setFreeFont(&SquadaOne_Regular6pt7b);
      d.setCursor(gx - 20, temp);
      // precision is default Arduino--this could really use some format control
      d.drawNumber((int)i,gx-20, temp,2);
    }
    
    /////// draw x scale
    for (i = xlo; i >= xhi; i += xinc) {

      // compute the transform

      temp =  (i - xlo) * ( w) / (xhi - xlo) + gx;
      if (i == 0) {
        d.drawLine(temp, gy, temp, gy - h, acolor);
      }
      else {
        d.drawLine(temp, gy, temp, gy - h, gcolor);
      }

      d.setTextSize(1);
      d.setTextColor(tcolor, bcolor);
      d.setCursor(temp, gy + 10);
      // precision is default Arduino--this could really use some format control
      if(xmax >= minTohour) d.drawFloat(i,1,temp,gy +10,2);
      else d.drawNumber((int)i,temp,gy+10,2);
    }

    ///////now draw the labels
    d.setTextSize(2);
    d.setTextColor(tcolor, bcolor);
    d.setCursor(gx , gy - h - 30);
    d.drawString(title,gx,gy-h-30,2);

    d.setTextSize(1);
    d.setTextColor(tcolor, bcolor);
    d.setCursor(gx , gy + 20);
    d.drawString(xlabel,gx+w/2 , gy + 24,2);

    d.setTextSize(1);
    d.setTextColor(acolor, bcolor);
    d.setCursor(gx - 30, gy - h - 10);
    d.drawString(ylabel,gx - 30, gy - h - 10,2);
  }

  // //첫번째 데이터에 이전 데이터와 선긋지 않도록 oxy를  xy값과 일치 시킴 
  if (firstData == 0) {
    ox = (x - xlo) * ( w) / (xhi - xlo) + gx;
    oy1 = (y1 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
    oy2 = (y2 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
    oy3 = (y3 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  }

  //graph drawn now plot the data
  // the entire plotting code are these few lines...
  // recall that ox and oy are initialized as static above
  x =  (x - xlo) * ( w) / (xhi - xlo) + gx;
  y1 =  (y1 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  y2 =  (y2 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  y3 =  (y3 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  d.drawLine(ox, oy1, x, y1, p1color);
  d.drawLine(ox, oy2, x, y2, p2color);
  d.drawLine(ox, oy3, x, y3, p3color);
  d.drawLine(ox, oy1 + 1, x, y1 + 1, p1color);
  d.drawLine(ox, oy1 - 1, x, y1 - 1, p1color);
  d.drawLine(ox, oy2 + 1, x, y2 + 1, p2color);
  d.drawLine(ox, oy2 - 1, x, y2 - 1, p2color);
  d.drawLine(ox, oy3 + 1, x, y3 + 1, p3color);
  d.drawLine(ox, oy3 - 1, x, y3 - 1, p3color);
  //Serial.printf("\n#%00d ox: %.1f, oy1:%.1f,oy2:%.1f,oy3:%.1f",fData,ox,oy1,oy2,oy3);
  //Serial.printf("\n x: %.1f,  y1:%.1f, y2:%.1f, y3:%.1f",x,y1,y2,y3);
  
  ox = x;
  oy1 = y1; oy2 = y2; oy3 = y3;

}

/*
  End of graphing functioin
*/
// #########################################################################
//  Draw the meter on the screen, returns x coord of righthand side
// #########################################################################
int ringMeter(int value, int vmin, int vmax, int x, int y, int r, const char *units, byte scheme,int labelColor)
{
  // Minimum value of r is about 52 before value text intrudes on ring
  // drawing the text first is an option
  
  x += r; y += r;   // Calculate coords of centre of ring

  int w = r / 3;    // Width of outer ring is 1/4 of radius
  
  int angle = 150;  // Half the sweep angle of meter (300 degrees)

  int v = map(value, vmin, vmax, -angle, angle); // Map the value to an angle v

  byte seg = 3; // Segments are 3 degrees wide = 100 segments for 300 degrees
  byte inc = 6; // Draw segments every 3 degrees, increase to 6 for segmented ring

  // Variable to save "value" text colour from scheme and set default
  int colour = TFT_BLUE;
 
  // Draw colour blocks every inc degrees
  for (int i = -angle+inc/2; i < angle-inc/2; i += inc) {
    // Calculate pair of coordinates for segment start
    float sx = cos((i - 90) * 0.0174532925);
    float sy = sin((i - 90) * 0.0174532925);
    uint16_t x0 = sx * (r - w) + x;
    uint16_t y0 = sy * (r - w) + y;
    uint16_t x1 = sx * r + x;
    uint16_t y1 = sy * r + y;

    // Calculate pair of coordinates for segment end
    float sx2 = cos((i + seg - 90) * 0.0174532925);
    float sy2 = sin((i + seg - 90) * 0.0174532925);
    int x2 = sx2 * (r - w) + x;
    int y2 = sy2 * (r - w) + y;
    int x3 = sx2 * r + x;
    int y3 = sy2 * r + y;

    if (i < v) { // Fill in coloured segments with 2 triangles
      switch (scheme) {
        case 0: colour = TFT_RED; break; // Fixed colour
        case 1: colour = TFT_GREEN; break; // Fixed colour
        case 2: colour = TFT_BLUE; break; // Fixed colour
        case 3: {
          if(i<=0) colour = rainbow(map(i, -angle, 0, 0, 90)); 
          else colour = rainbow(map(i, 0, angle, 90, 127));
          break; // Full spectrum blue to red
        }
        case 4: colour = rainbow(map(i, -angle, angle, 70, 127)); break; // Green to red (high temperature etc)
        case 5: colour = rainbow(map(i, -angle, angle, 127, 63)); break; // Red to green (low battery etc)
        default: colour = TFT_BLUE; break; // Fixed colour
      }
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, colour);
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, colour);
      //text_colour = colour; // Save the last colour drawn
    }
    else // Fill in blank segments
    {
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, TFT_GREY);
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, TFT_GREY);
    }
  }
  // Convert value to a string
  char buf[10];
  byte len = 3; if (value > 999) len = 5;
  dtostrf(value, len, 0, buf);
  buf[len] = ' '; buf[len+1] = 0; // Add blanking space and terminator, helps to centre text too!
  // Set the text colour to default
  tft.setTextSize(1);

  if (value<vmin || value>vmax) {
    drawAlert(x,y+r-20,50,1);
  }
  else {
    drawAlert(x,y+r-20,50,0);
  }

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  // Uncomment next line to set the text colour to the last segment value!
  tft.setTextColor(colour, TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  // Print value, if the meter is large then use big font 8, othewise use 4
  if (r > 84) {
    tft.setTextPadding(55*3); // Allow for 3 digits each 55 pixels wide
    tft.drawString(buf, x, y, 8); // Value in middle
  }
  else {
    tft.setTextPadding(3 * 14); // Allow for 3 digits each 14 pixels wide
    tft.drawString(buf, x, y, 4); // Value in middle
  }
  tft.setTextSize(1);
  tft.setTextPadding(0);
  // Print units, if the meter is large then use big font 4, othewise use 2
  tft.setTextColor(labelColor, TFT_BLACK);
  if (r > 84) tft.drawString(units, x, y + 60, 4); // Units display
  else tft.drawString(units, x, y + 15, 2); // Units display

  // Calculate and return right hand side x coordinate
  return x + r;
}

void drawAlert(int x, int y , int side, boolean draw)
{
  if (draw && !range_error) {
    drawIcon(alert, x - alertWidth/2, y - alertHeight/2, alertWidth, alertHeight);
    range_error = 1;
  }
  else if (!draw) {
    tft.fillRect(x - alertWidth/2, y - alertHeight/2, alertWidth, alertHeight, TFT_BLACK);
    range_error = 0;
  }
}

// #########################################################################
// Return a 16 bit rainbow colour
// #########################################################################
unsigned int rainbow(byte value)
{
  // Value is expected to be in range 0-127
  // The value is converted to a spectrum colour from 0 = blue through to 127 = red

  byte red = 0; // Red is the top 5 bits of a 16 bit colour value
  byte green = 0;// Green is the middle 6 bits
  byte blue = 0; // Blue is the bottom 5 bits

  byte quadrant = value / 32;

  if (quadrant == 0) {
    blue = 31;
    green = 2 * (value % 32);
    red = 0;
  }
  if (quadrant == 1) {
    blue = 31 - (value % 32);
    green = 63;
    red = 0;
  }
  if (quadrant == 2) {
    blue = 0;
    green = 63;
    red = value % 32;
  }
  if (quadrant == 3) {
    blue = 0;
    green = 63 - 2 * (value % 32);
    red = 31;
  }
  return (red << 11) + (green << 5) + blue;
}


//====================================================================================
// This is the function to draw the icon stored as an array in program memory (FLASH)
//====================================================================================

// To speed up rendering we use a 64 pixel buffer
#define BUFF_SIZE 64

// Draw array "icon" of defined width and height at coordinate x,y
// Maximum icon size is 255x255 pixels to avoid integer overflow

void drawIcon(const unsigned short* icon, int16_t x, int16_t y, int8_t width, int8_t height) {

  uint16_t  pix_buffer[BUFF_SIZE];   // Pixel buffer (16 bits per pixel)

  tft.startWrite();

  // Set up a window the right size to stream pixels into
  tft.setAddrWindow(x, y, width, height);

  // Work out the number whole buffers to send
  uint16_t nb = ((uint16_t)height * width) / BUFF_SIZE;

  // Fill and send "nb" buffers to TFT
  for (int i = 0; i < nb; i++) {
    for (int j = 0; j < BUFF_SIZE; j++) {
      pix_buffer[j] = pgm_read_word(&icon[i * BUFF_SIZE + j]);
    }
    tft.pushColors(pix_buffer, BUFF_SIZE);
  }

  // Work out number of pixels not yet sent
  uint16_t np = ((uint16_t)height * width) % BUFF_SIZE;

  // Send any partial buffer left over
  if (np) {
    for (int i = 0; i < np; i++) pix_buffer[i] = pgm_read_word(&icon[nb * BUFF_SIZE + i]);
    tft.pushColors(pix_buffer, np);
  }

  tft.endWrite();
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
          Serial.printf("Successfully got data from station # %s\n",stationList[i].c_str());
          //tft.drawString("#"+(String)i,5,30);
          break;
        }
      }
    }
    else Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str()); 
  }        
  ///end of for loop///

    
  int xpos_air10=0,ypos_air10=0;
  int xpos_air25=0,ypos_air25=62;
             
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

   /*/오존정보표시
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
  
  tft.drawFloat(o3Value,2,oz_x+55,oz_y+5,1); */
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
    Serial.printf("x: %f, y: %f\n",x,y);

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

/////////////////////////////////////////////////////////////
////////////////////////////////////////////대기정보 https://aqicn.org/json-api/doc///////////////
void check_air_waqi(){
  
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
  String waqikey="68e5a661e9c5eb93a50e38450ee43d49fbe3b9ba";
  
  for(int i=0;i<3;i++) {
    String url = "https://api.waqi.info/feed/geo:"; 
    url += String(tmy, 7); 
    url += ";"+String(tmx, 7);
    url += "/?token="+ waqikey;
     
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

        String baseTime = findString(payload,F("time"),F("tz"));
        //pm10Grade1h = findString(payload,F("<pm10Grade1h>"),F("</pm10Grade1h>")).toInt();
        pm10Value = findString(payload,F("pm10"),F("</pm10Value>"));
        pm25Grade1h = findString(payload,F("<pm25Grade1h>"),F("</pm25Grade1h>")).toInt();
        pm25Value = findString(payload,F("<pm25Value>"),F("</pm25Value>"));
        o3Grade = findString(payload,F("<o3Grade>"),F("</o3Grade>")).toInt();
        o3Value = findString(payload,F("<o3Value>"),F("</o3Value>")).toFloat();
        
        Serial.printf("baseTime: %s\npm10Grade1h: %d\npm10Value: %s\npm25Grade1h: %d\npm25Value: %s\no3Grade: %d\no3Value: %03f\n", 
        baseTime.c_str(),pm10Grade1h,pm10Value.c_str(),pm25Grade1h,pm25Value.c_str(),o3Grade,o3Value);
   
        if(pm25Grade1h > 0 && pm25Grade1h < 5 && pm10Grade1h >0 && pm10Grade1h <5){
          Serial.printf("Successfully got data from station # %s\n",stationList[i].c_str());
          //tft.drawString("#"+(String)i,5,30);
          break;
        }
      }
    }
    else Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str()); 
  }        
  ///end of for loop///

    
  int xpos_air10=0,ypos_air10=0;//,xpos_air10End=255,ypos_air10End=279;
  int xpos_air25=0,ypos_air25=62;//,xpos_air25End=363,ypos_air25End=279;
             
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

   /*/오존정보표시
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
  
  tft.drawFloat(o3Value,2,oz_x+55,oz_y+5,1); */
}
         
 
