/* SoftwareDebounce
 * 
 * At each transition from LOW to HIGH or from HIGH to LOW 
 * the input signal is debounced by sampling across
 * multiple reads over several milli seconds.  The input
 * is not considered HIGH or LOW until the input signal 
 * has been sampled for at least "debounce_count" (10)
 * milliseconds in the new state.
 *
 * Notes:
 *   Adjust debounce_count to reflect the timescale 
 *     over which the input signal may bounce before
 *     becoming steady state
 *
 * Based on:
 *   http://www.arduino.cc/en/Tutorial/Debounce
 *
 * Jon Schlueter
 * 30 December 2008
 *
 * http://playground.arduino.cc/Learning/SoftwareDebounce
 */
#include <TimeLib.h> 
#include <LiquidCrystal_I2C.h>

int buttonPin = 4;         // the number of the input pin
int outPin = 8;       // the number of the output pin
int buttonGND=2;

int counter = 0;       // how many times we have seen new value
int reading;           // the current value read from the input pin
int current_state = LOW;    // the debounced input value

// the following variable is a long because the time, measured in milliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was sampled
int debounce_count = 10; // number of millis/samples to consider before declaring a debounced input

LiquidCrystal_I2C lcd(0x27,16,2); //address, lcd type

void setup()
{

  
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  
  pinMode(buttonPin, INPUT);
  pinMode(outPin, OUTPUT);
  pinMode(buttonGND,OUTPUT);
  digitalWrite(outPin, current_state); // setup the Output LED for initial state
  digitalWrite(buttonGND,LOW);
  digitalWrite(buttonPin,LOW); //pull-down
}


void loop()
{
  // If we have gone on to the next millisecond
  if(millis() != time)
  {
    reading = digitalRead(buttonPin);
    Serial.print("button");Serial.println(reading);

    if(reading == current_state && counter > 0)
    {
      counter--;
    }
    if(reading != current_state)
    {
       counter++; 
    }
    // If the Input has shown the same value for long enough let's switch it
    if(counter >= debounce_count)
    {
      counter = 0;
      current_state = reading;
      digitalWrite(outPin, current_state);
    }
    time = millis();
  }
}
