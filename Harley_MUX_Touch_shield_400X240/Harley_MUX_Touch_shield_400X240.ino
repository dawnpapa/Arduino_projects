// the regular Adafruit "TouchScreen.h" library only works on AVRs

// different mcufriend shields have Touchscreen on different pins
// and rotation.
// Run the UTouch_calibr_kbv sketch for calibration of your shield
//#define TOUCH_ORIENTATION  LANDSCAPE //PORTRAIT

#include <Adafruit_GFX.h>    // Core graphics library
#include <UTFTGLUE.h>
#include <Wire.h> //temperature sensor
#include <LM75.h>  //temperature sensor
#include <Time.h>

UTFTGLUE tft(0x9488,A2,A1,A3,A4,A0);
LM75 sensor;  // initialize an LM75 object

#include <TouchScreen.h>

// most mcufriend shields use these pins and Portrait mode:
uint8_t YP = A1;  // must be an analog pin, use "An" notation!
uint8_t XM = A2;  // must be an analog pin, use "An" notation!
uint8_t YM = 7;   // can be a digital pin
uint8_t XP = 6;   // can be a digital pin
uint8_t SwapXY = 0;

//touch screen 보정치 landscape case
uint16_t TS_LEFT = 900;//y-axis top
uint16_t TS_RT  = 220; //y-axis bottom
uint16_t TS_TOP = 940;//x-axis
uint16_t TS_BOT = 200;//x-axis
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

#define MINPRESSURE 100
#define MAXPRESSURE 1500

#define SWAP(a, b) {uint16_t tmp = a; a = b; b = tmp;}

int16_t BOXSIZE;
int16_t PENRADIUS = 3;
uint16_t identifier, oldcolor, currentcolor;
uint8_t Orientation = 1;    //0/2.PORTRAIT 1/3.landscape
int row=180/8;
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

    ts = TouchScreen(XP, YP, XM, YM, 300);     //call the constructor AGAIN with new values.
    tft.begin(identifier);
//    show_Serial();
    tft.setRotation(Orientation);
    tft.fillScreen(BLACK);
//    show_tft();

//    BOXSIZE = tft.width();
    
    tft.setTextColor(YELLOW,BLACK);
    tft.setCursor(27,0);
    tft.setTextSize(3);
    tft.print("MUX CONTROL",27,1);
    tft.setCursor(255,12);
    tft.setTextSize(1);
    tft.setTextColor(WHITE,BLUE);
    tft.print("CTRL",255,12);
    tft.setCursor(253,25);
    tft.print("0 1 2",253,25);

    tft.setTextSize(2);
    tft.setTextColor(WHITE,BLACK);
    tft.setCursor(210,222);
    tft.print("JMS's 3rd Edition",180,222);
//버튼생성
    tft.setColor(255,230,0);
    tft.fillCircle(350,50,30);
    tft.fillCircle(350,180,30);
    tft.setColor(100,250,100);
    tft.fillCircle(350,115,30);
    tft.setTextSize(3);
    tft.setTextColor(WHITE);
    tft.print("UP",337,40);
    tft.print("#1",337,105);
    tft.print("DN",337,170);
    
   
 

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

    //Temperature Sensor
    timenow=millis()/1000;
    //Serial.print(minute());Serial.print("M ");Serial.print(second());Serial.println("S");
    if(timenow>(timeold+60)) {
      sensor.shutdown(false);
    temperature=sensor.temp();
     
      Serial.print("Current temp: ");
      Serial.print(temperature);
      Serial.println(" C");
      
      sensor.shutdown(true);
      Serial.println((millis()/1000));Serial.println("milis ");
      /*tft.setTextSize(1);
      tft.setTextColor(WHITE,BLACK);
      tft.print("Elapsed Time",300,100);
      tft.printNumI(timenow,RIGHT,330,120);tft.print("sec",335,120); */
      timeold=timenow;
      
    }
    
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

        // are we in 메뉴선택 box area ?
 
        if (ypos > 40 && xpos<300 && xpos>2 && ypos<220) {               //티치스크린 메뉴선택

            if (ypos > row*7+40) {
                ModeSelected = 7;
               
            } else if (ypos > row*6+40 ) {
                ModeSelected = 6;
                
            } else if (ypos > row*5+40) {
                ModeSelected = 5;
                
            } else if (ypos > row*4+40) {
                ModeSelected = 4;
                
            } else if (ypos > row*3+40) {
                ModeSelected = 3;
                
            } else if (ypos > row*2+40) {
                ModeSelected = 2;
                
            } else if (ypos > row*1+40) {
                ModeSelected = 1;
                
            } else if (ypos > row*0+40) {
                ModeSelected = 0;
                
            }

            
            //modeChange실행
            modeChange();


        }

        // 버튼선택

            if (xpos > 345 && xpos<390 && ypos>25 && ypos<75) { //up button
              if(ModeSelected==0) ModeSelected=8;
              ModeSelected=(ModeSelected-1)%8;
              modeChange();
              
            }

            if (xpos > 345 && xpos<390 && ypos>165 && ypos<215) { //down button
              ModeSelected=(ModeSelected+1)%8;
              modeChange();
            }

            if (xpos > 345 && xpos<390 && ypos>95 && ypos<145) { //#1 button
              ModeSelected=0;
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
        tft.print("1. SPX (B7  mode)   001",10,40);
        tft.setCursor(10,40+row*1);
        tft.print("2. SPX (B41 mode)   010",10,40+row*1);
        tft.setCursor(10,40+row*2);
        tft.print("3. HPX(Venom)+B7    011",10,40+row*2);
        tft.setCursor(10,40+row*3);
        tft.print("4. HPX(Venom)+B41   100",10,40+row*3);
        tft.setCursor(10,40+row*4);
        tft.print("5. HPX only mode    101",10,40+row*4);
        tft.setCursor(10,40+row*5);
        tft.print("6. B7  only mode    110",10,40+row*5);
        tft.setCursor(10,40+row*6);
        tft.print("7. B41 only mode    111",10,40+row*6);
        tft.setCursor(10,40+row*7);
        tft.print("8. High Isolation   000",10,40+row*7);
  
  switch (ModeSelected) {
        
    case 0:
        tft.setTextColor(RED,YELLOW);
        tft.setCursor(10,40);
        tft.print("1. SPX (B7  mode)   001",10,40);
    
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 1:
        tft.setTextColor(RED,YELLOW);
        tft.setCursor(10,40+row*1);
        tft.print("2. SPX (B41 mode)   010",10,40+row*1);
        
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,LOW);
       break;

    case 2:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*2);
        tft.print("3. HPX(Mace)+B7     011",10,40+row*2);
        
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 3:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*3);
        tft.print("4. HPX(Mace)+B41    100",10,40+row*3);
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,LOW);
       break;
       
    case 4:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*4);
        tft.print("5. HPX only mode    101",10,40+row*4);
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 5:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*5);
        tft.print("6. B7  only mode    110",10,40+row*5);
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,LOW);
       break;
       
    case 6:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*6);
        tft.print("7. B41 only mode    111", 10,40+row*6);
        
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 7:
        tft.setTextColor(RED,YELLOW);
        
        tft.setCursor(10,40+row*7);
        tft.print("8. High Isolation   000",10,40+row*7);
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,LOW);
       break;
    
  }
}

