#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);

const int analogInPin = A0; // Analog input pin that the potentiometer is attached to
const int digitalInPin = 4; // Analog output pin that the LED is attached to
const int limit = 350; // Analog output pin that the LED is attached to
int sensorValue = 0; // value read from the pot
void setup() {
// initialize serial communications at 9600 bps:
Serial.begin(9600);
pinMode(analogInPin, INPUT);
pinMode(digitalInPin, OUTPUT);

lcd.init();
lcd.backlight();
}

void loop() {
// read the analog in value:
sensorValue = analogRead(analogInPin);
// map it to the range of the analog out:

Serial.print("sensor = ");
Serial.println(sensorValue);

lcd.init();
lcd.setCursor(0,0);
lcd.print("Soil sensor=");
lcd.print(sensorValue);

if ( sensorValue > limit ) {
digitalWrite(digitalInPin,HIGH);
Serial.print("\t\t\tMotor working.........");
Serial.println(sensorValue);

lcd.setCursor(0,1);
lcd.print("Water please..");

delay(5000);
analogWrite(digitalInPin,128);
}
delay(6000); 
}
