#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int analogInPin = 0; // Analog input pin that the potentiometer is attached to
const int digitalInPin = 13; // Analog output pin that the LED is attached to
const int digitalGNDPin=8;
const int limit = 350; // Analog output pin that the LED is attached to
int sensorValue = 0; // value read from the pot
void setup() {
// initialize serial communications at 9600 bps:
Serial.begin(9600);
pinMode(analogInPin, INPUT);
pinMode(digitalInPin, OUTPUT);
pinMode(digitalGNDPin, OUTPUT);

digitalWrite(digitalGNDPin,LOW);

lcd.init();
lcd.backlight();
}

void loop() {
// read the analog in value:
digitalWrite(digitalInPin,HIGH);
sensorValue = analogRead(analogInPin);
digitalWrite(digitalInPin,LOW);
// map it to the range of the analog out:

Serial.print("sensor = ");
Serial.println(sensorValue);

lcd.init();
lcd.setCursor(0,0);
lcd.print("Soil sensor=");
lcd.print(sensorValue);
lcd.setCursor(0,1);
lcd.print("Good! Thank you!");

if ( sensorValue < limit ) {
//analogWrite(digitalInPin,1);
Serial.print("\t\t\tMotor working.........");
Serial.println(sensorValue);

lcd.setCursor(0,1);
lcd.print("Water please...");

delay(1000);
digitalWrite(digitalInPin,LOW);
}
delay(1000); 
}
