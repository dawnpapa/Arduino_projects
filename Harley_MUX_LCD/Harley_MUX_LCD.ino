//editted by Jason, Oct 23, 2017
//can be used for Aduino UNO, pin set should be changed for esp8266

#include <TimeLib.h>
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

/////////////////////////Pin setup////////////////
// pin definition for buttons
const int UpButtonPin = 2;    // up pushbutton  pin
const int DownButtonPin=3;    // down pushbutton  pin

// pin definition for relays
const int ctrl0 = 5;      // bias for ctrl 0
const int ctrl1 = 6;      // bias for ctrl 1
const int ctrl2 = 7;      // bias for ctrl 2

//1.8inch TFT LCD pin assign, 
//Uno default setting 변경불가: SDA SDI 11(MOSI),SCK 13, 12(MISO)
#define cs   10 //cs(ss,slave select, chip select)
#define dc   9 //A0(data/command selection)
#define rst  8  //reset

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

// Variables will change:
int UpButtonState;             // the current reading from the input pin
int DownButtonState;
int lastUpButtonState = LOW;   // the previous reading from the input pin
int lastDownButtonState = LOW;   // the previous reading from the input pin
int ModeState=8000; //initial mode state. 80000 means 1st mode

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastUpDebounceTime = 0;  // the last time the output pin was toggled
long lastDownDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  
  // write the static text to the screen
  TFTscreen.stroke(255, 255, 0); //blue color
  // set the font size
  TFTscreen.setTextSize(2);
  // write the text to the top left corner of the screen
  TFTscreen.text("Harley's  MUX\n ", 0, 0);
 
  TFTscreen.setTextSize(1);
  //display current temperature
  TFTscreen.stroke(0, 255, 255); //temperatue color yellow
  TFTscreen.text(" Measured Temperature:   C",0,110);
  
  Serial.begin(115200);

  
  pinMode(UpButtonPin,INPUT);
  pinMode(DownButtonPin,INPUT);
  pinMode(ctrl0,OUTPUT);
  pinMode(ctrl1,OUTPUT);
  pinMode(ctrl2,OUTPUT);

  // internal pull-down setup
  digitalWrite(UpButtonPin,LOW);
  digitalWrite(DownButtonPin,LOW);
  
//default mode////////////
  modeChange(); //display default mode 
  
}

void loop() {
  
  // read the state of the switch into a local variable:
  int readingUp = digitalRead(UpButtonPin); //업버튼 상태를 읽음
  int readingDown=digitalRead(DownButtonPin); //다운버튼 상태를 읽음
/*
  Serial.print("\n 1st. readingUP: ");Serial.println(readingUp);
  Serial.print("1st readingDown: ");Serial.println(readingDown);
  Serial.print("lastUpButtonState");Serial.println(lastUpButtonState);
  Serial.print("lastDownButtonState");Serial.println(lastDownButtonState);
  Serial.print("mode state");Serial.println(ModeState);
  */
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:
  // If the switch changed, due to noise or pressing:

  //check Up button///////////////////////////////
  // If the switch changed, due to noise or pressing:
  if (readingUp != lastUpButtonState) { //업버튼 전압이 변하면 (누르거나 떼면)
    // reset the debouncing timer
    lastUpDebounceTime = millis();  //그시간을 체크하고

   // Serial.print("lastUpDebounceTime");Serial.println(lastUpDebounceTime);

  }

  if ((millis() - lastUpDebounceTime) > debounceDelay) {  //일정시간이후 부터 상태 체크
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    
    // if the button state has changed:
    if (readingUp != UpButtonState) {  //일정시간 이후에도 업버튼 전압이 변해있으면(계속 누르거나 계속 떼면)
      UpButtonState = readingUp;  // 버튼이 현재 상태인것으로 인식시키고
      
      // only toggle up the mode if the up button state is HIGH
      if (UpButtonState == HIGH) {  // 버튼이 눌렸으면
        ModeState--;  //모드상태를 1씩 감소시킴
        modeChange();  //모드를 바꿔라
        
       // Serial.print("Up button ON: mode state");Serial.println(ModeState);
        
      }
    }
  }


//check Down button////////////////////////////
  if (readingDown != lastDownButtonState) {
    // reset the debouncing timer
    lastDownDebounceTime = millis();
   
    //Serial.print("lastDownDebounceTime: ");Serial.println(lastDownDebounceTime);
    
  }

  if ((millis() - lastDownDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    // if the button state has changed:
 
    if (readingDown != DownButtonState) {
      DownButtonState = readingDown;
      
      // only toggle up the mode if the up button state is HIGH
      if (DownButtonState == HIGH) {
        ModeState++;
        modeChange();
      
        //Serial.println("down on");
       
        
      }
    }
  }

  //lastUp/DownButtonState를 현재값으로 update
  lastUpButtonState=readingUp;
  lastDownButtonState=readingDown;
  delay(30);
} //loop종료

  
  
  //////모드변경을 명령하는 함수선언
void modeChange(){
  int ModeSelected=ModeState%8; //assign 8 modes
  
  switch (ModeSelected) {
    case 0:
         TFTscreen.stroke(0, 0, 255); //red color
         TFTscreen.text(" 1. SPX (B7  mode) 001\n", 0, 25);
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 2. SPX (B41 mode)\n", 0, 35);
         TFTscreen.text(" 3. HPX+B7  mode\n", 0, 45);
         TFTscreen.text(" 4. HPX+B41 mode\n", 0, 55);
         TFTscreen.text(" 5. HPX only mode\n", 0, 65);
         TFTscreen.text(" 6. B7  only mode\n", 0, 75);
         TFTscreen.text(" 7. B41 only mode\n", 0, 85);
         TFTscreen.text(" 8. High Isolation\n", 0, 95);
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 1:
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 1. SPX (B7  mode)\n", 0, 25);
         TFTscreen.stroke(0, 0, 255); //red color
         TFTscreen.text(" 2. SPX (B41 mode) 010\n", 0, 35);
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 3. HPX+B7  mode\n", 0, 45);
         TFTscreen.text(" 4. HPX+B41 mode\n", 0, 55);
         TFTscreen.text(" 5. HPX only mode\n", 0, 65);
         TFTscreen.text(" 6. B7  only mode\n", 0, 75);
         TFTscreen.text(" 7. B41 only mode\n", 0, 85);
         TFTscreen.text(" 8. High Isolation\n", 0, 95);
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,LOW);
       break;

    case 2:
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 1. SPX (B7  mode)\n", 0, 25);
         TFTscreen.text(" 2. SPX (B41 mode)\n", 0, 35);
         TFTscreen.stroke(0, 0, 255); //red color
         TFTscreen.text(" 3. HPX+B7  mode   011\n", 0, 45);
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 4. HPX+B41 mode\n", 0, 55);
         TFTscreen.text(" 5. HPX only mode\n", 0, 65);
         TFTscreen.text(" 6. B7  only mode\n", 0, 75);
         TFTscreen.text(" 7. B41 only mode\n", 0, 85);
         TFTscreen.text(" 8. High Isolation\n", 0, 95);
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 3:
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 1. SPX (B7  mode)\n", 0, 25);
         TFTscreen.text(" 2. SPX (B41 mode)\n", 0, 35);
         TFTscreen.text(" 3. HPX+B7  mode\n", 0, 45);
         TFTscreen.stroke(0, 0, 255); //red color
         TFTscreen.text(" 4. HPX+B41 mode   100\n", 0, 55);
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 5. HPX only mode\n", 0, 65);
         TFTscreen.text(" 6. B7  only mode\n", 0, 75);
         TFTscreen.text(" 7. B41 only mode\n", 0, 85);
         TFTscreen.text(" 8. High Isolation\n", 0, 95);
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,LOW);
       break;
       
    case 4:
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 1. SPX (B7  mode)\n", 0, 25);
         TFTscreen.text(" 2. SPX (B41 mode)\n", 0, 35);
         TFTscreen.text(" 3. HPX+B7  mode\n", 0, 45);
         TFTscreen.text(" 4. HPX+B41 mode\n", 0, 55);
         TFTscreen.stroke(0, 0, 255); //red color
         TFTscreen.text(" 5. HPX only mode  101\n", 0, 65);
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 6. B7  only mode\n", 0, 75);
         TFTscreen.text(" 7. B41 only mode\n", 0, 85);
         TFTscreen.text(" 8. High Isolation\n", 0, 95);
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 5:
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 1. SPX (B7  mode)\n", 0, 25);
         TFTscreen.text(" 2. SPX (B41 mode)\n", 0, 35);
         TFTscreen.text(" 3. HPX+B7  mode\n", 0, 45);
         TFTscreen.text(" 4. HPX+B41 mode\n", 0, 55);
         TFTscreen.text(" 5. HPX only mode\n", 0, 65);
         TFTscreen.stroke(0, 0, 255); //red color
         TFTscreen.text(" 6. B7  only mode  110\n", 0, 75);
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 7. B41 only mode\n", 0, 85);
         TFTscreen.text(" 8. High Isolation\n", 0, 95);
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,LOW);
       break;
       
    case 6:
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 1. SPX (B7  mode)\n", 0, 25);
         TFTscreen.text(" 2. SPX (B41 mode)\n", 0, 35);
         TFTscreen.text(" 3. HPX+B7  mode\n", 0, 45);
         TFTscreen.text(" 4. HPX+B41 mode\n", 0, 55);
         TFTscreen.text(" 5. HPX only mode\n", 0, 65);
         TFTscreen.text(" 6. B7  only mode\n", 0, 75);
         TFTscreen.stroke(0, 0, 255); //red color
         TFTscreen.text(" 7. B41 only mode  111\n", 0, 85);
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 8. High Isolation\n", 0, 95);
       digitalWrite(ctrl0,HIGH);
       digitalWrite(ctrl1,HIGH);
       digitalWrite(ctrl2,HIGH);
       break;
       
    case 7:
         TFTscreen.stroke(0, 255, 0); //green color
         TFTscreen.text(" 1. SPX (B7  mode)\n", 0, 25);
         TFTscreen.text(" 2. SPX (B41 mode)\n", 0, 35);
         TFTscreen.text(" 3. HPX+B7  mode\n", 0, 45);
         TFTscreen.text(" 4. HPX+B41 mode\n", 0, 55);
         TFTscreen.text(" 5. HPX only mode\n", 0, 65);
         TFTscreen.text(" 6. B7  only mode\n", 0, 75);
         TFTscreen.text(" 7. B41 only mode\n", 0, 85);
         TFTscreen.stroke(0, 0, 255); //red color
         TFTscreen.text(" 8. High Isolation 000\n", 0, 95);
         TFTscreen.stroke(0, 255, 0); //green color
       digitalWrite(ctrl0,LOW);
       digitalWrite(ctrl1,LOW);
       digitalWrite(ctrl2,LOW);
       break;
    
  }
}

