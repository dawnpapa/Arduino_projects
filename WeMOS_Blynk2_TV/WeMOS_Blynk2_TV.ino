/**************************************************************
 * Output any data on LCD widget!
 *
 * App project setup:
 *
 *   LCD widget, SIMPLE mode, in widget settings :
 *
 *   - Select pin V0 for zero pin
 *   - Select pin V1 for first pin
 *   - Change "Reading Frequency" to PUSH mode
 *   - Type into first edit field "/pin0/ seconds"
 *   - Type into second edit field "/pin1/ millis"
 *
 **************************************************************/
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>
#define dht11p 4
#define TV 11 //PB3, D11, OC2A
#define Fan_out 3  //PD3, D3, OC2B

DHT mydht11(dht11p,DHT11);

SimpleTimer timer;

WidgetLED led1(V3);
WidgetLED led2(V4);

uint8_t pwm_out;
int tv_on;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "579d76c974ea48fa927461a5c591619a";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SJSLGU";
char pass[] = "123456789b";

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(10, 12); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

//ESP8266 wifi(&EspSerial);

void setup()
{
  pinMode(2,OUTPUT);
  
  // Set console baud rate
  Serial.begin(9600);
  delay(10);
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  
  Blynk.begin(auth,"SJSLGU","123456789b");
  
  // Setup a function to be called every second
  timer.setInterval(1000L, dht11_chk);
  
  while(Blynk.connect()==0){
         // Wait until connected
  }
  //led1.setValue(0);
  led1.off();
  led2.off();
}

BLYNK_READ(V2)
{
  Blynk.virtualWrite(V2, millis()/1000);
}

void dht11_chk()
{
  int chk = mydht11.read(dht11p);
  int h = mydht11.readHumidity();
  int t = mydht11.readTemperature();
  switch(chk){
  case 1:
    Serial.print("Humidity (%) =  ");
    Serial.println(h);
    Blynk.virtualWrite(V11, h);
        
    Serial.print("Temperature (oC) =  ");
    Serial.println(t);
    Serial.println();
    Blynk.virtualWrite(V10, t);
    if(t>=30.0){
      led1.on();
      //analogWrite(Fan_out,pwm_out);
      //analogWrite(Led_out,0);
    }
    else if(t<=28.0){
      led2.on();
      //analogWrite(Fan_out,0);
      //analogWrite(Led_out,led_out);
    }
    else {
      led1.off();
      led2.off();
    }
    break;
    
  default:
    Serial.println("DHT Error!!\r\n");
    Serial.println();
    break;
   }
}

BLYNK_WRITE(V5)
{
  pwm_out = param.asInt();
  analogWrite(Fan_out,pwm_out);
}

BLYNK_WRITE(V6)
{
  tv_on = param.asInt();
  digitalWrite(TV,tv_on);
}

void loop()
{
  Blynk.run();
  timer.run();
}


    

