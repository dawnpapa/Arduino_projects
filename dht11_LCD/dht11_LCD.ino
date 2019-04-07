#include <DHT11.h>
// #include <LiquidCrystal_I2C.h>

#define dht11_GND_PIN 3
#define dht11_VCC_PIN 2
#define dht11_S_PIN 8

DHT11 dht11(dht11_S_PIN);
//LiquidCrystal_I2C lcd(0x27,16,2);


float temp, humi;
int err;
 
void setup()
{
   Serial.begin(9600);
//  while (!Serial) {
//      ; // wait for serial port to connect. Needed for Leonardo only
//    }

//   lcd.init();
//   lcd.backlight(); 


// Activate dht11 module
//  digitalWrite(dht11_GND_PIN, LOW);
//  pinMode(dht11_GND_PIN, OUTPUT);

//  digitalWrite(dht11_VCC_PIN, HIGH);
//  pinMode(dht11_VCC_PIN, OUTPUT);

//  lcd.clear();
//  lcd.home();
//  lcd.print("DHT11 activated");
//  delay(1000);

  }

  
void loop()
{
   
  
  dht11.read(humi,temp);

 
 // if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();

/*
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp. :  ");
    lcd.print(temp,1);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Humid.:  ");
    lcd.print(humi,1);
    lcd.print("%"); 
*/
    
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();  
/*
     lcd.setCursor(0,0);
     lcd.print("Error No:  ");
     lcd.print(err); 
     */
  }
  delay(2000); //delay for reread
}



