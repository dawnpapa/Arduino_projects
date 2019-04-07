#include <LiquidCrystal_I2C.h>
//#include <Wire.h>
#include "cactus_io_DS18B20.h"
LiquidCrystal_I2C lcd(0x3F,16,2);

int DS18B20_Pin = 2;       //DS18B20 Signal pin on digital 2

// Create DS18B20 object
DS18B20 ds(DS18B20_Pin);  // on digital pin 2

void setup() {
//  ds.readSensor();
//  Serial.begin(9600);
//  Serial.println("cactus.io | Basic Webserver Tutorial");
//  Serial.println("Temp (C)\tTemp (F)");
  lcd.init();
  lcd.backlight();
  lcd.println("Temperature is  ");
  
}

void loop() {
   // put your main code here, to run repeatedly:
   ds.readSensor();

//   Serial.print(ds.getTemperature_C()); Serial.print(" *C\t");
//   Serial.print(ds.getTemperature_F()); Serial.println(" *F");
   lcd.setCursor(0,1);
   lcd.print(ds.getTemperature_C(),1);
  lcd.print(" C");
  lcd.setCursor(10,1);
  lcd.print(ds.getTemperature_F(),1);
  lcd.print(" F");

   // Add a 2 second delay.
   delay(2000); //just here to slow down the output.
}
