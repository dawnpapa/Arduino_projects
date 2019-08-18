//new TFT_eSPI적요 drawIcon대신 tft.drawImage로 변경
//reference: https://mybtechprojects.tech/serial-communication-between-nodemcu-and-arduino/

#include <stdint.h> 
#include <Wire.h> 
#include <Time.h> 
#include <TimeLib.h> 
#include <ArduinoJson.h> 
//#include <SimpleTimer.h>
//#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include <SoftwareSerial.h>
#include <Adafruit_GFX.h>
#include <UTFTGLUE.h>
#include <TouchScreen.h>
#include <MCUFRIEND_kbv.h>
//----------------------------------------|
// TFT Breakout  -- Arduino UNO / Mega2560 / OPEN-SMART UNO Black
// GND              -- GND
// 3V3               -- 3.3V
// CS                 -- A3
// RS                 -- A2
// WR                -- A1
// RD                 -- A0
// RST                -- RESET
// LED                -- GND
// DB0                -- 8
// DB1                -- 9
// DB2                -- 10
// DB3                -- 11
// DB4                -- 4
// DB5                -- 13
// DB6                -- 6
// DB7                -- 7

MCUFRIEND_kbv tft;

//figures to import
#include "Temp.h"
#include "Dust.h"
#include "Dust2.h"
#include "DustN.h"
#include "NoDust.h"
#include "Clear.h"
#include "Cloudy1.h"
#include "Cloudy2.h"
#include "Rain.h"
#include "Snow.h"
#include "sojung.h"
#include "joonyoung.h"
#include "Little.h"
#include "Happy.h"
#include "Wind.h"
#include "bad.h"
#include "good.h"
#include "normal.h"
#include "severe.h"
#include "happy2.h"

#define TFT_GREY 0x5AEB

SoftwareSerial s(6,7);////(Rx, Tx)

uint32_t targetTime = 0; 

byte omm = 99, oss = 99, owday=99;
byte xcolon = 0, xsecs = 0;
unsigned int colour = 0;

char base_date[11]; 
char base_time[5]; 
char base_datef[11]; 
char base_timef[5]; 

void setup() { 
  Serial.begin(115200); 
  s.begin(9600);
  while(!Serial) continue;
  Serial.print("serial begin");

  /*
  tft.init();
  tft.setRotation(1);
  tft.setSwapBytes(true);
  tft.fillScreen(TFT_BLACK);

  tft.setTextSize(1);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK); 

    tft.println("If this is first time to connect your wifi, ");
    tft.println("set up your wifi information using your smartphone\n");
    
    tft.println("1. go to your wifi setup with your smartphone\n");
    tft.println("2. scan you wifi around you\n");
    tft.println("3. find and click 'Jason's Device'\n");
    tft.println("4. click the http://192.168.4.1\n");
    tft.println("5. click Configure WiFi\n");
    tft.println("6. click an AP name you want, and insert AP password\n");
    tft.println("7. click Save\n");
 
    tft.println("This setup is needed only for the case of first changing AP\n\n");
    tft.setTextColor(TFT_WHITE, TFT_BLACK); 
    tft.println("Please contact iksanman@hotmail.com if you have any difficulty");
*/

if(s.available()>0){
    Serial.println(s.read());
}

    
  
////////대문 문구//////////////
  //           tft.setTextColor(TFT_PINK,TFT_WHITE);
 //           tft.drawString("  @  ALWAYS    HAPPY !!  @   ",0,0,4); //대문이름
 //          tft.pushImage(5,0,littleWidth,littleHeight,little);//리틀존 대문이름
  //           tft.pushImage(5,0,happy2Width,happy2Height,happy2);//행복한우리집 대문이름         
  //          tft.pushImage(5,0,joonyoungWidth,joonyoungHeight,joonyoung);//준영이네
  //           tft.pushImage(5,0,sojungWidth,sojungHeight,sojung);//소정이네



  targetTime = millis() + 1000;

}

void loop() { 
  Serial.println(s.read());
  delay(1000);
  
 
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
  if (root == JsonObject::invalid())
    return;
 
  Serial.println("JSON received and parsed");
  root.prettyPrintTo(Serial);
  Serial.print("Data 1 ");
  Serial.println("");
  int data1=root["data1"];
  Serial.print(data1);
  Serial.print("   Data 2 ");
  int data2=root["data2"];
  Serial.print(data2);
  Serial.println("");
  Serial.println("---------------------xxxxx--------------------");
  
}
