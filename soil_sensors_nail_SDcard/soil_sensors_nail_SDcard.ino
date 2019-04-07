#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);

int duration;

const int sensor1=1; 
const int sensor2=2;
const int sensor3=3;

const int vcc1=13; 
const int vcc2=11;
const int vcc3=9;

const int gnd1=12;
const int gnd2=10;
const int gnd3=8;

const int limit = 350; // watering value
int sensor1Value = 0; // value read from the pot
int sensor2Value = 0; // value read from the pot
int sensor3Value = 0; // value read from the pot

int sensor1Value0; // initial sensing value
int sensor2Value0; 
int sensor3Value0; 

int sensor1value_old=0;
int sensor2value_old=0;
int sensor3value_old=0;

void setup() {
// initialize serial communications at 9600 bps:
//Serial.begin(9600);
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
pinMode(sensor3, INPUT);

pinMode(vcc1, OUTPUT);
pinMode(vcc2, OUTPUT);
pinMode(vcc3, OUTPUT);

pinMode(gnd1, OUTPUT);
pinMode(gnd2, OUTPUT);
pinMode(gnd3, OUTPUT);

digitalWrite(gnd1,LOW);
digitalWrite(gnd2,LOW);
digitalWrite(gnd3,LOW);

lcd.init();

digitalWrite(vcc1,HIGH);
digitalWrite(vcc2,HIGH);
digitalWrite(vcc3,HIGH);
delay(500);

sensor1Value0 = analogRead(sensor1);
sensor2Value0 = analogRead(sensor2);
sensor3Value0 = analogRead(sensor3);

digitalWrite(vcc1,LOW);
digitalWrite(vcc2,LOW);
digitalWrite(vcc3,LOW);
delay(1000);

}

void loop() {
// read the analog in value:
lcd.backlight();
digitalWrite(vcc1,HIGH);
digitalWrite(vcc2,HIGH);
digitalWrite(vcc3,HIGH);
delay(500);

sensor1Value = analogRead(sensor1);
sensor2Value = analogRead(sensor2);
sensor3Value = analogRead(sensor3);

digitalWrite(vcc1,LOW);
digitalWrite(vcc2,LOW);
digitalWrite(vcc3,LOW);

/*
Serial.print("s1=");
Serial.println(sensor1Value);
Serial.print("s2=");
Serial.println(sensor2Value);
Serial.print("s3=");
Serial.println(sensor3Value);
*/
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Sensor ");
lcd.print(sensor1Value0);
lcd.print("/");
lcd.print(sensor2Value0);
lcd.print("/");
lcd.print(sensor3Value0);


lcd.setCursor(0,1);
lcd.print(sensor1Value);
lcd.print(" / ");
lcd.print(sensor2Value);
lcd.print(" / ");
lcd.print(sensor3Value);

lcd.setCursor(0,2);
lcd.print(sensor1Value-sensor1value_old);
lcd.print(" / ");
lcd.print(sensor2Value-sensor2value_old);
lcd.print(" / ");
lcd.print(sensor3Value-sensor3value_old);

lcd.setCursor(0,3);
lcd.print("check time:");
duration=millis()/60000;
lcd.print(duration/60);lcd.print("h ");
lcd.print(duration%60);lcd.print("m");

/*
if ( sensorValue < limit ) {
//analogWrite(digitalInPin,1);
Serial.print("\t\t\tMotor working.........");
Serial.println(sensorValue);

lcd.setCursor(0,1);
lcd.print("Water please...");

delay(1000);
digitalWrite(digitalInPin,LOW);
}
*/

delay(1000*5);
lcd.noBacklight();

sensor1value_old=sensor1Value;
sensor2value_old=sensor2Value;
sensor3value_old=sensor3Value;

delay(60000*10); 
}
