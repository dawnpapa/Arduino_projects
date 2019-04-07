//#include <DHT11.h>
#include <DHT.h>


#define gnd 2
#define vcc 3
#define DHTPIN 4
#define DHTTYPE DHT11

//DHT11 dht11(dht11_S_PIN);
DHT dht(DHTPIN, DHTTYPE);

float temp, humi;
int err;
 
void setup()
{
   Serial.begin(9600);
//   pinMode(DHTPIN,INPUT);
  pinMode(gnd,OUTPUT);
  pinMode(vcc,OUTPUT);

  digitalWrite(gnd,LOW);
  digitalWrite(vcc,HIGH);

  }

  
void loop()
{
   
  temp=dht.readTemperature();
  humi=dht.readHumidity();
  

  Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();

  delay(5000); //delay for reread
}



