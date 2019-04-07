/*
 Debounce

 Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
 press), the output pin is toggled from LOW to HIGH or HIGH to LOW.  There's
 a minimum delay between toggles to debounce the circuit (i.e. to ignore
 noise).

 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached from pin 2 to +5V
 * 10K resistor attached from pin 2 to ground

 * Note: On most Arduino boards, there is already an LED on the board
 connected to pin 13, so you don't need any extra components for this example.


 created 21 November 2006
 by David A. Mellis
 modified 30 Aug 2011
 by Limor Fried
 modified 28 Dec 2012
 by Mike Walters

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Debounce
 */


#include <TimeLib.h> 
#include <LiquidCrystal_I2C.h>

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 4;    // the number of the pushbutton pin
const int ledPin = 8;      // the number of the LED pin
const int buttonRef=2;

// Variables will change:
int ledState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers


LiquidCrystal_I2C lcd(0x27,16,2); //address, lcd type

void setup() {

  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonRef, OUTPUT);

  // set initial LED state
  digitalWrite(buttonPin, LOW); //pull-down
  digitalWrite(ledPin, ledState);
  digitalWrite(buttonRef, HIGH);
  digitalWrite(13,LOW);

  lcd.print("Mace MUX Control");

  
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);
  

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:
  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
    
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    // if the button state has changed:
 
    if (reading != buttonState) {
      buttonState = reading;
      
      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
        
        
      }
    }
  }

  // set the LED:
  
  if (ledState==HIGH){
          
          digitalWrite(ledPin,HIGH); //
          digitalWrite(13,HIGH);
          lcd.setCursor(0,1);
        lcd.print(" B7 Mode  SW-ON ");
        
        }
        else{
          digitalWrite(ledPin,LOW); //
          digitalWrite(13,LOW);
        lcd.setCursor(0,1);
        lcd.print(" B38 Mode SW-OFF");
        }

 //       digitalWrite(ledPin, ledState);
        
        
  Serial.print("output");Serial.println(ledState);
  Serial.print("button");Serial.println(reading);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
  delay(100);
}

