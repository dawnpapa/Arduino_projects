// the regular Adafruit "TouchScreen.h" library only works on AVRs

// different mcufriend shields have Touchscreen on different pins
// and rotation.
// Run the UTouch_calibr_kbv sketch for calibration of your shield

#include <Adafruit_GFX.h>    // Core graphics library
//#include <Adafruit_TFTLCD.h> // Hardware-specific library
//Adafruit_TFTLCD tft(A3, A2, A1, A0, A4);
#include <MCUFRIEND_kbv.h> //mcu friend에서 만든 lcd shield용 library
MCUFRIEND_kbv tft;       // hard-wired for UNO shields anyway.
#include <TouchScreen.h>

#if defined(__SAM3X8E__)
#undef __FlashStringHelper::F(string_literal)
#define F(string_literal) string_literal
#endif

// These are the pins for some typical shields!
// S6D0154: YP=A1, XM=A2, YM=7, XP=6
// ST7783 : YP=A2, XM=A1, YM=6, XP=7
// ILI9320: YP=A2, XM=A3, YM=8, XP=9
// ILI9325: YP=A1, XM=A2, YM=7, XP=6
// ILI9325BG: YP=A2, XM=A1, YM=6, XP=7
// ILI9341: YP=A2, XM=A1, YM=7, XP=6
// ILI9488: YP=A1, XM=A2, YM=7, XP=6
// R65109V: YP=A2, XM=A1, YM=6, XP=7

// most mcufriend shields use these pins and Portrait mode:
uint8_t YP = A1;  // must be an analog pin, use "An" notation!
uint8_t XM = A2;  // must be an analog pin, use "An" notation!
uint8_t YM = 7;   // can be a digital pin
uint8_t XP = 6;   // can be a digital pin
uint8_t SwapXY = 1;

//touch screen 보정치
uint16_t TS_LEFT = 842;
uint16_t TS_RT  = 265;
uint16_t TS_TOP = 905;
uint16_t TS_BOT = 172;
char *name = "Unknown controller";

// pin definition for relays
const int ctrl0 = 2;      // bias for ctrl 0
const int ctrl1 = 3;      // bias for ctrl 1
const int ctrl2 = 4;      // bias for ctrl 2

int ModeSelected=0; //assign 8 modes

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
TSPoint tp;

#define MINPRESSURE 20
#define MAXPRESSURE 1000

#define SWAP(a, b) {uint16_t tmp = a; a = b; b = tmp;}

int16_t BOXSIZE;
int16_t PENRADIUS = 3;
uint16_t identifier, oldcolor, currentcolor;
uint8_t Orientation = 1;    //PORTRAIT
int row=200/8;

// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
/*
void show_Serial(void)
{
    Serial.print(F("Found "));
    Serial.print(name);
    Serial.println(F(" LCD driver"));
    Serial.print(F("ID=0x"));
    Serial.println(identifier, HEX);
    Serial.println("Screen is " + String(tft.width()) + "x" + String(tft.height()));
    Serial.println("Calibration is: ");
    Serial.println("LEFT = " + String(TS_LEFT) + " RT  = " + String(TS_RT));
    Serial.println("TOP  = " + String(TS_TOP)  + " BOT = " + String(TS_BOT));
    Serial.print("Wiring is: ");
    Serial.println(SwapXY ? "SWAPXY" : "PORTRAIT");
    Serial.println("YP=" + String(YP)  + " XM=" + String(XM));
    Serial.println("YM=" + String(YM)  + " XP=" + String(XP));
}

void show_tft(void)
{
    tft.setCursor(0, 0);
    tft.setTextSize(2);
    tft.print(F("Found "));
    tft.print(name);
    tft.println(F(" LCD"));
    tft.setTextSize(1);
    tft.print(F("ID=0x"));
    tft.println(identifier, HEX);
    tft.println("Screen is " + String(tft.width()) + "x" + String(tft.height()));
    tft.println("Calibration is: ");
    tft.println("LEFT = " + String(TS_LEFT) + " RT  = " + String(TS_RT));
    tft.println("TOP  = " + String(TS_TOP)  + " BOT = " + String(TS_BOT));
    tft.print("\nWiring is: ");
    if (SwapXY) {
        tft.setTextColor(CYAN);
        tft.setTextSize(2);
    }
    tft.println(SwapXY ? "SWAPXY" : "PORTRAIT");
    tft.println("YP=" + String(YP)  + " XM=" + String(XM));
    tft.println("YM=" + String(YM)  + " XP=" + String(XP));
    tft.setTextSize(2);
    tft.setTextColor(RED);
    tft.setCursor((tft.width() - 48) / 2, (tft.height() * 2) / 4);
    tft.print("EXIT");
    tft.setTextColor(YELLOW, BLACK);
    tft.setCursor(0, (tft.height() * 6) / 8);
    tft.print("Touch screen for loc");
    while (1) {
        tp = ts.getPoint();
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        pinMode(XP, OUTPUT);
        pinMode(YM, OUTPUT);
        if (tp.z < MINPRESSURE || tp.z > MAXPRESSURE) continue;
        if (tp.x > 450 && tp.x < 570  && tp.y > 450 && tp.y < 570) break;
        tft.setCursor(0, (tft.height() * 3) / 4);
        tft.print("tp.x=" + String(tp.x) + " tp.y=" + String(tp.y) + "   ");
    }
}
*/

void setup(void)
{
    uint16_t tmp;
    tft.begin(9600);

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

//    Serial.begin(9600);
    ts = TouchScreen(XP, YP, XM, YM, 300);     //call the constructor AGAIN with new values.
    tft.begin(identifier);
//    show_Serial();
    tft.setRotation(Orientation);
    tft.fillScreen(BLACK);
//    show_tft();

//    BOXSIZE = tft.width();
    tft.fillScreen(BLACK);
    
    tft.setTextColor(YELLOW,BLACK);
    tft.setCursor(27,0);
    tft.setTextSize(3);
    tft.print("MUX CONTROL");
    tft.setCursor(255,12);
    tft.setTextSize(1);
    tft.setTextColor(WHITE,BLUE);
    tft.print("CTRL");
    tft.setCursor(253,25);
    tft.print("0 1 2");
    
    tft.setTextColor(MAGENTA,BLACK);
    tft.setCursor(210,232);
    tft.print("JMS's 2nd Edition");
   
 

    modeChange();
    
/*    tft.fillRect(BOXSIZE, 0, BOXSIZE, BOXSIZE, YELLOW);
    tft.fillRect(BOXSIZE * 2, 0, BOXSIZE, BOXSIZE, GREEN);
    tft.fillRect(BOXSIZE * 3, 0, BOXSIZE, BOXSIZE, CYAN);
    tft.fillRect(BOXSIZE * 4, 0, BOXSIZE, BOXSIZE, BLUE);
    tft.fillRect(BOXSIZE * 5, 0, BOXSIZE, BOXSIZE, MAGENTA);

    tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
    currentcolor = RED;
    delay(1000);
    */
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

        // are we in 메뉴선택 box area ?
 
        if (ypos > 38) {               //티치스크린 메뉴선택

            if (ypos > row*7+38) {
                ModeSelected = 7;
               
            } else if (ypos > row*6+38) {
                ModeSelected = 6;
                
            } else if (ypos > row*5+38) {
                ModeSelected = 5;
                
            } else if (ypos > row*4+38) {
                ModeSelected = 4;
                
            } else if (ypos > row*3+38) {
                ModeSelected = 3;
                
            } else if (ypos > row*2+38) {
                ModeSelected = 2;
                
            } else if (ypos > row*1+38) {
                ModeSelected = 1;
                
            } else if (ypos > row*0+38) {
                ModeSelected = 0;
                
            }

            //modeChange실행
            modeChange();


        }
 /*       // are we in drawing area ?
        if (((ypos - PENRADIUS) > BOXSIZE) && ((ypos + PENRADIUS) < tft.height())) {
            tft.fillCircle(xpos, ypos, PENRADIUS, WHITE);
        }
        // are we in erase area ?
        if (ypos > tft.height() - 10) {
            // press the bottom of the screen to erase
            tft.fillRect(0, BOXSIZE, tft.width(), tft.height() - BOXSIZE, BLACK);
        }
        */
    }
}

 //////모드변경을 명령하는 함수선언
void modeChange(){

  //initial color menu
        tft.setTextColor(CYAN,BLACK);
        tft.setTextSize(2);
        tft.setCursor(10,40);
        tft.println("1. SPX (B7  mode)   001");
        tft.setCursor(10,40+row*1);
        tft.println("2. SPX (B41 mode)   010");
        tft.setCursor(10,40+row*2);
        tft.println("3. HPX(Mace)+B7     011");
        tft.setCursor(10,40+row*3);
        tft.println("4. HPX(Mace)+B41    100");
        tft.setCursor(10,40+row*4);
        tft.println("5. HPX only mode    101");
        tft.setCursor(10,40+row*5);
        tft.println("6. B7  only mode    110");
        tft.setCursor(10,40+row*6);
        tft.println("7. B41 only mode    111");
        tft.setCursor(10,40+row*7);
        tft.print("8. High Isolation   000");
  
  switch (ModeSelected) {
        
    case 0:
        tft.setTextColor(RED,YELLOW);
        tft.setCursor(10,40);
        tft.println("1. SPX (B7  mode)   001");
    
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 1:
        tft.setTextColor(RED,YELLOW);
        tft.setCursor(10,40+row*1);
        tft.println("2. SPX (B41 mode)   010");
        
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,LOW);
       break;

    case 2:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*2);
        tft.println("3. HPX(Mace)+B7     011");
        
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 3:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*3);
        tft.println("4. HPX(Mace)+B41    100");
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,LOW);
       break;
       
    case 4:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*4);
        tft.println("5. HPX only mode    101");
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 5:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*5);
        tft.println("6. B7  only mode    110");
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,LOW);
       break;
       
    case 6:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*6);
        tft.println("7. B41 only mode    111");
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 7:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*7);
        tft.print("8. High Isolation   000");
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,LOW);
       break;
    
  }
}

