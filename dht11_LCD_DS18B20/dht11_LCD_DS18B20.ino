#include <DHT11.h>
#include <LiquidCrystal_I2C.h>
#include<cactus_io_DS18B20.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

int DS18B20_Pin = 2;       //DS18B20 Signal pin on digital 2

// Create DS18B20 object
DS18B20 ds(DS18B20_Pin);  // on digital pin 2

int pin=4;

DHT11 dht11(pin); 
void setup()
{
   Serial.begin(9600);
//  while (!Serial) {
//      ; // wait for serial port to connect. Needed for Leonardo only
//    }

   lcd.init();
   lcd.backlight(); 
}

void loop()
{
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();

    ds.readSensor();
    lcd.setCursor(0,0);
    lcd.print("Temp. :  ");
    lcd.print(ds.getTemperature_C(),1);
    lcd.print(" C");
    lcd.setCursor(0,1);
    lcd.print("Humid.:  ");
    lcd.print(humi,1);
    lcd.print(" %");


    Serial.print(ds.getTemperature_C(),1); Serial.println(" C\t");
    
    
    
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();  

     lcd.init();
     lcd.setCursor(0,0);
     lcd.print("Error No:  ");
     lcd.print(err); 
  }
  delay(DHT11_RETRY_DELAY*2); //delay for reread
}



