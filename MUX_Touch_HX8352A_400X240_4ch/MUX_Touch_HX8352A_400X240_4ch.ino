// the regular Adafruit "TouchScreen.h" library only works on AVRs
//HX8352A용 변경사항
//1. opensmart library에서
//1.mcufriend_kbv.cpp에서 #define SUPPORT_8252A를 활성화하고 #define SUPPORT_8352B를 죽임
//2. mcufriend_shield.h에서 #define USE_SPECIAL활성화함
//3. mcufriend_special.h에서 #define USE_OPENSMART_SHIELD_PINOUT을 추가해줌

// different mcufriend shields have Touchscreen on different pins
// and rotation.
// Run the UTouch_calibr_kbv sketch for calibration of your shield
//#define TOUCH_ORIENTATION  LANDSCAPE //PORTRAIT

#include <Adafruit_GFX.h>    // Core graphics library
#include <UTFTGLUE.h>
#include <Wire.h> //temperature sensor
#include <LM75.h>  //temperature sensor
#include <Time.h>
#include <Fonts/ARIALN5pt7b.h>
#include <Fonts/ARIALN6pt7b.h>
#include <Fonts/ARIALN7pt7b.h>

UTFTGLUE tft(0x9488,A2,A1,A3,A4,A0);

LM75 sensor;  // initialize an LM75 object

#include <TouchScreen.h>

// most mcufriend shields use these pins and Portrait mode:
uint8_t YP = A1;  // must be an analog pin, use "An" notation!
uint8_t XM = A2;  // must be an analog pin, use "An" notation!
uint8_t YM = 7;   // can be a digital pin
uint8_t XP = 6;   // can be a digital pin
uint8_t SwapXY = 0;

//touch screen 보정치 portrait case
uint16_t TS_LEFT = 900;//y-axis top 8352B와 LEFT/RT, TOP/BOT가 바뀜
uint16_t TS_RT  = 220; //y-axis bottom
uint16_t TS_TOP = 940;//x-axis
uint16_t TS_BOT = 200;//x-axis
char *name = "Unknown controller";

// pin definition for relays
const int ctrl0 = 2;      // bias for ctrl 0
const int ctrl1 = 3;      // bias for ctrl 1
const int ctrl2 = 4;      // bias for ctrl 2
const int ctrl3 = 8;      // bias for ctrl 3

int ModeSelected=0; //default mode
int prjSelected=0;  //default project
char mode1[30],mode2[30],mode3[30],mode4[30],mode5[30],mode6[30],mode7[30],mode8[30];
char mode9[30],mode10[30],mode11[30],mode12[30],mode13[30],mode14[30],mode15[30],mode16[30];

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
TSPoint tp;

#define MINPRESSURE 100
#define MAXPRESSURE 1500

#define SWAP(a, b) {uint16_t tmp = a; a = b; b = tmp;}

int16_t BOXSIZE;
int16_t PENRADIUS = 3;
uint16_t identifier, oldcolor, currentcolor;
uint8_t Orientation = 2;    //0/2.PORTRAIT 1/3.landscape 8352B는 0임
int row=300/16; //displaying span
int l1x=5,l1y=70; //1st line position to display mode list
uint32_t timenow,timeold;
float temperature;

// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


void setup(void)
{
    uint16_t tmp;
    tft.begin(9600);
    Wire.begin();
    Serial.begin(9600);

    tft.reset();
    identifier = tft.readID();
    //    if (identifier == 0) identifier = 0x9341;
    if (0) {
    } else if (identifier == 0x0154) {
        name = "S6D0154";
        TS_LEFT = 914; TS_RT = 181; TS_TOP = 957; TS_BOT = 208;
    } else if (identifier == 0x7783) {
        name = "ST7781";
        TS_LEFT = 865; TS_RT = 155; TS_TOP = 942; TS_BOT = 153;
        SwapXY = 1;
    } else if (identifier == 0x7789) {
        name = "ST7789V";
        YP = A2; XM = A1; YM = 7; XP = 6;
        TS_LEFT = 906; TS_RT = 169; TS_TOP = 161; TS_BOT = 919;
    } else if (identifier == 0x9320) {
        name = "ILI9320";
        YP = A3; XM = A2; YM = 9; XP = 8;
        TS_LEFT = 902; TS_RT = 137; TS_TOP = 941; TS_BOT = 134;
    } else if (identifier == 0x9325) {
        name = "ILI9325";
        TS_LEFT = 900; TS_RT = 103; TS_TOP = 96; TS_BOT = 904;
    } else if (identifier == 0x9325) {
        name = "ILI9325 Green Dog";
        TS_LEFT = 900; TS_RT = 130; TS_TOP = 940; TS_BOT = 130;
    } else if (identifier == 0x9327) {
        name = "ILI9327";
        TS_LEFT = 899; TS_RT = 135; TS_TOP = 935; TS_BOT = 79;
        SwapXY = 1;
    } else if (identifier == 0x9329) {
        name = "ILI9329";
        TS_LEFT = 143; TS_RT = 885; TS_TOP = 941; TS_BOT = 131;
        SwapXY = 1;
    } else if (identifier == 0x9341) {
        name = "ILI9341 BLUE";
        TS_LEFT = 920; TS_RT = 139; TS_TOP = 944; TS_BOT = 150;
        SwapXY = 0;
    } else if (identifier == 0) {
        name = "ILI9341 DealExtreme";
        TS_LEFT = 893; TS_RT = 145; TS_TOP = 930; TS_BOT = 135;
        SwapXY = 1;
    } else if (identifier == 0 || identifier == 0x9341) {
        name = "ILI9341";
        TS_LEFT = 128; TS_RT = 911; TS_TOP = 105; TS_BOT = 908;
        SwapXY = 1;
    } else if (identifier == 0x9486) {
        name = "ILI9486";
        TS_LEFT = 904; TS_RT = 170; TS_TOP = 950; TS_BOT = 158;
    } else if (identifier == 0x9488) {
        name = "ILI9488";
        TS_LEFT = 904; TS_RT = 170; TS_TOP = 950; TS_BOT = 158;
    } else if (identifier == 0xB509) {
        name = "R61509V";
        TS_LEFT = 889; TS_RT = 149; TS_TOP = 106; TS_BOT = 975;
        SwapXY = 1;
    } else {
        name = "unknown";
    }

    Serial.print(identifier);
    
    switch (Orientation) {      // adjust for different aspects
        case 0:   break;        //no change,  calibrated for PORTRAIT
        case 1:   tmp = TS_LEFT, TS_LEFT = TS_BOT, TS_BOT = TS_RT, TS_RT = TS_TOP, TS_TOP = tmp;  break;
        case 2:   SWAP(TS_LEFT, TS_RT);  SWAP(TS_TOP, TS_BOT); break;
        case 3:   tmp = TS_LEFT, TS_LEFT = TS_TOP, TS_TOP = TS_RT, TS_RT = TS_BOT, TS_BOT = tmp;  break;
    }
//Relay control/////
    pinMode(ctrl0,OUTPUT);
    pinMode(ctrl1,OUTPUT);
    pinMode(ctrl2,OUTPUT);
    pinMode(ctrl3,OUTPUT);

    ts = TouchScreen(XP, YP, XM, YM, 300);     //call the constructor AGAIN with new values.
    tft.begin(identifier);
//    show_Serial();
    tft.setRotation(Orientation);
    tft.fillScreen(BLACK);
//    show_tft();

//    BOXSIZE = tft.width();
    
    tft.setTextColor(YELLOW,BLACK);
    tft.setTextSize(2);
    tft.print("SELECT PROJECT",30,1);  

    tft.setTextSize(1);
    tft.setTextColor(WHITE);
    tft.print("JMS's 4th Edition 2019",85,370);
    tft.print("FBAR SEOUL KOREA",120,380);

//버튼생성
    tft.setColor(255,230,0);
    tft.fillCircle(205,170,30);
    tft.fillCircle(205,300,30);
    tft.setColor(100,250,100);
    tft.fillCircle(205,235,30);
    tft.setTextSize(3);
    tft.setTextColor(WHITE);
    tft.print("UP",192,160);
    tft.print("#5",192,225);
    tft.print("DN",192,290);
    
   
 
    prjChange();
    modeChange();
    
}

void loop()
{
    uint16_t xpos, ypos;  //screen coordinates
    tp = ts.getPoint();   //tp.x, tp.y are ADC values

    // if sharing pins, you'll need to fix the directions of the touchscreen pins
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    pinMode(XP, OUTPUT);
    pinMode(YM, OUTPUT);
    //    digitalWrite(XM, HIGH);
    //    digitalWrite(YP, HIGH); 

    /*/Temperature Sensor
    timenow=millis()/1000;
    //Serial.print(minute());Serial.print("M ");Serial.print(second());Serial.println("S");
    if(timenow>(timeold+60)) {
      sensor.shutdown(false);
    temperature=sensor.temp();
     
      Serial.print("Current temp: ");
      Serial.print(temperature);
      Serial.println(" C");
      
      sensor.shutdown(true); */
      
    
    
    // we have some minimum pressure we consider 'valid'
    // pressure of 0 means no pressing!

    if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
        // is controller wired for Landscape ? or are we oriented in Landscape?
        if (SwapXY != (Orientation & 1)) SWAP(tp.x, tp.y);
        // scale from 0->1023 to tft.width  i.e. left = 0, rt = width
        // most mcufriend have touch (with icons) that extends below the TFT
        // screens without icons need to reserve a space for "erase"
        // scale the ADC values from ts.getPoint() to screen values e.g. 0-239
        xpos = map(tp.x, TS_LEFT, TS_RT, 0, tft.width());
        ypos = map(tp.y, TS_TOP, TS_BOT, 0, tft.height());

        Serial.print("x");Serial.print(xpos);Serial.print("y");Serial.println(ypos);
        
        Serial.println(tp.z);

        // PROJECT SELECT
 
        if (ypos > 15 && xpos<240 && xpos>2 && ypos<36) {               //티치스크린 메뉴선택

            if (xpos > 184) {
                prjSelected = 2;
               
            } else if (xpos > 79 ) {
                prjSelected = 1;
                
            } else if (xpos > 2) {
                prjSelected = 0;
                
            }
            
            
            
            //prjChange실행
            prjChange();
            modeChange();


        }
//INFO

        if (ypos > 55 && xpos<240 && xpos>184 && ypos<80) {
          prjSelected=3;
           //prjChange실행
            prjChange();
            modeChange();
        } 

        // mode 버튼선택

            if (xpos > 165 && xpos<230 && ypos>150 && ypos<193) { //up button
              if(ModeSelected==0) ModeSelected=16;
              ModeSelected=(ModeSelected-1)%16;
              modeChange();
              
            }

            if (xpos > 165 && xpos<230 && ypos>283 && ypos<332) { //down button
              ModeSelected=(ModeSelected+1)%16;
              modeChange();
            }

            if (xpos > 165 && xpos<230 && ypos>217 && ypos<269) { //#5 button
              ModeSelected=4;
              modeChange();
            }

    }
}

 //////PROJECT변경을 명령하는 함수선언
void prjChange(){

  //refresh mode list
    tft.setFont();//revert to default font
    
    tft.setColor(BLACK);
    tft.fillRect(l1x,l1y,170,l1y+row*16);
    
  
  //initial color menu
    tft.setColor(WHITE);
    tft.fillRoundRect(1,20,70,50);
    tft.fillRoundRect(80,20,170,50);
    tft.fillRoundRect(180,20,240,50);
    tft.fillRoundRect(180,60,240,90);

    
        tft.setTextColor(BLACK);
        tft.setTextSize(2);
  
        tft.print("PINOT",5,30);   
        tft.print("RAINIER",85,30);  
        tft.print("HLS",195,30);  
        tft.print("INFO",190,70);
        
  
  switch (prjSelected) {
        
    case 0:        
        tft.setColor(YELLOW);
        tft.setTextColor(RED);
        tft.fillRoundRect(1,20,70,50); 
        tft.print("PINOT",5,30);
        strcpy(mode1,"01. HIGH ISOLATION");//000
        strcpy(mode2,"02. HPX + B41");//0001
        strcpy(mode3,"03. SPX + B41");//0010
        strcpy(mode4,"04. B7 ONLY");//0011
        strcpy(mode5,"05. SPX + B7");//0100
        strcpy(mode6,"06. HPX ONLY");//0101
        strcpy(mode7,"07. HPX + B7");//0110
        strcpy(mode8,"08. B41 ONLY");//0111
        strcpy(mode9,"09. NA");
        strcpy(mode10,"10. NA");
        strcpy(mode11,"11. NA");
        strcpy(mode12,"12. NA");
        strcpy(mode13,"13. NA");
        strcpy(mode14,"14. NA");
        strcpy(mode15,"15. NA");
        strcpy(mode16,"16. NA");
       break;
       
    case 1:
        tft.setColor(YELLOW);
        tft.setTextColor(RED);
        tft.fillRoundRect(80,20,170,50);
        tft.print("RAINIER",85,30);
        strcpy(mode1,"01. HIGH ISOLATION");
        strcpy(mode2,"02. SPX + B7");
        strcpy(mode3,"03. SPX + B41");
        strcpy(mode4,"04. B39 + B41");
        strcpy(mode5,"05. HPX + B7");
        strcpy(mode6,"06. HPX + B41");
        strcpy(mode7,"07. HPX ONLY");
        strcpy(mode8,"08. HPX + B7 ANT2");
        strcpy(mode9,"09. HPX + B41 ANT2");
        strcpy(mode10,"10. HPX + B41 ANT2");
        strcpy(mode11,"11. NA");
        strcpy(mode12,"12. NA");
        strcpy(mode13,"13. NA");
        strcpy(mode14,"14. NA");
        strcpy(mode15,"15. NA");
        strcpy(mode16,"16. NA");
        break;

    case 2:
        tft.setColor(YELLOW);
        tft.setTextColor(RED);
        tft.fillRoundRect(180,20,240,50);
        tft.print("HLS",195,30);
        strcpy(mode1,"01. HIGH ISOLATION");
        strcpy(mode2,"02. SPX + B7");
        strcpy(mode3,"03. SPX + B41");
        strcpy(mode4,"04. B39 + B41");
        strcpy(mode5,"05. HPX + B7");
        strcpy(mode6,"06. HPX + B41");
        strcpy(mode7,"07. HPX ONLY");
        strcpy(mode8,"08. HPX + B7 ANT2");
        strcpy(mode9,"09. HPX+B41(ANT2,SPX_CA)");
        strcpy(mode10,"10. HPX+B41(ANT2,B39_CA)");
        strcpy(mode11,"11. B41 ONLY");
        strcpy(mode12,"12. HPX+B41(ANT2,B41ONLY)");
        strcpy(mode13,"13. NA");
        strcpy(mode14,"14. NA");
        strcpy(mode15,"15. NA");
        strcpy(mode16,"16. NA");
       break;

    case 3:
        tft.setColor(YELLOW);
        tft.setTextColor(RED);
        tft.fillRoundRect(180,60,240,90);
        tft.print("INFO",190,70);
        strcpy(mode1,"01. CTL3/2/1/0=0000");
        strcpy(mode2,"02. CTL3/2/1/0=0001");
        strcpy(mode3,"03. CTL3/2/1/0=0010");
        strcpy(mode4,"04. CTL3/2/1/0=0011");
        strcpy(mode5,"05. CTL3/2/1/0=0100");
        strcpy(mode6,"06. CTL3/2/1/0=0101");
        strcpy(mode7,"07. CTL3/2/1/0=0110");
        strcpy(mode8,"08. CTL3/2/1/0=0111");
        strcpy(mode9,"09. CTL3/2/1/0=1000");
        strcpy(mode10,"10. CTL3/2/1/0=1001");
        strcpy(mode11,"11. CTL3/2/1/0=1010");
        strcpy(mode12,"12. CTL3/2/1/0=1011");
        strcpy(mode13,"13. CTL3/2/1/0=1100");
        strcpy(mode14,"14. CTL3/2/1/0=1101");
        strcpy(mode15,"15. CTL3/2/1/0=1110");
        strcpy(mode16,"16. CTL3/2/1/0=1111");
       break;
           
  }
}
 
 //////모드변경을 명령하는 함수선언
void modeChange(){

  //tft.setFont(&FreeSansBold6pt7b);
        //refresh mode list
    tft.setColor(BLACK);
    tft.fillRect(l1x,l1y,155,l1y+row*16);
    
    //initial color menu
        tft.setTextColor(CYAN,BLACK);
        tft.setTextSize(1);
        tft.setFont(&ARIALN7pt7b);
        tft.print(mode1,l1x,l1y);
        tft.print(mode2,l1x,l1y+row*1);
        tft.print(mode3,l1x,l1y+row*2);
        tft.print(mode4,l1x,l1y+row*3);
        tft.print(mode5,l1x,l1y+row*4);
        tft.print(mode6,l1x,l1y+row*5);
        tft.print(mode7,l1x,l1y+row*6);
        tft.print(mode8,l1x,l1y+row*7);
        tft.print(mode9,l1x,l1y+row*8);
        tft.print(mode10,l1x,l1y+row*9);
        tft.print(mode11,l1x,l1y+row*10);
        tft.print(mode12,l1x,l1y+row*11);
        tft.print(mode13,l1x,l1y+row*12);
        tft.print(mode14,l1x,l1y+row*13);
        tft.print(mode15,l1x,l1y+row*14);
        tft.print(mode16,l1x,l1y+row*15);

        
  
  switch (ModeSelected) {
        
    case 0:        
        tft.setTextColor(RED,YELLOW);
        tft.print(mode1,l1x,l1y);
    
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,LOW);
       digitalWrite(ctrl3,LOW);
       
       break;
       
    case 1:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode2,l1x,l1y+row*1);
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,LOW);
       digitalWrite(ctrl3,LOW);
       break;

    case 2:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode3,l1x,l1y+row*2);
        
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,LOW);
       digitalWrite(ctrl3,LOW);
       break;
       
    case 3:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode4,l1x,l1y+row*3);
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,LOW);
       digitalWrite(ctrl3,LOW);
       break;
       
    case 4:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode5,l1x,l1y+row*4);
        
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,HIGH);
       digitalWrite(ctrl3,LOW);
       break;
       
    case 5:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode6,l1x,l1y+row*5);
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,HIGH);
       digitalWrite(ctrl3,LOW);
       break;
       
    case 6:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode7,l1x,l1y+row*6);
        
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,HIGH);
       digitalWrite(ctrl3,LOW);
       break;
       
    case 7:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode8,l1x,l1y+row*7);
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,HIGH);
       digitalWrite(ctrl3,LOW);
       break;

    case 8:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode9,l1x,l1y+row*8);
    
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,LOW);
       digitalWrite(ctrl3,HIGH);
       break;
       
    case 9:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode10,l1x,l1y+row*9);
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,LOW);
       digitalWrite(ctrl3,HIGH);
       break;

    case 10:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode11,l1x,l1y+row*10);
        
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,LOW);
       digitalWrite(ctrl3,HIGH);
       break;
       
    case 11:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode12,l1x,l1y+row*11);
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,LOW);
       digitalWrite(ctrl3,HIGH);
       break;
       
    case 12:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode13,l1x,l1y+row*12);
        
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,HIGH);
       digitalWrite(ctrl3,HIGH);
       break;
       
    case 13:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode14,l1x,l1y+row*13);
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,HIGH);
       digitalWrite(ctrl3,HIGH);
       break;
       
    case 14:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode15,l1x,l1y+row*14);
        
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,HIGH);
       digitalWrite(ctrl3,HIGH);
       break;
       
    case 15:
        tft.setTextColor(RED,YELLOW);
        tft.print(mode16,l1x,l1y+row*15);
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,HIGH);
       digitalWrite(ctrl3,HIGH);
       break;

      
  }

   tft.setFont();
}

