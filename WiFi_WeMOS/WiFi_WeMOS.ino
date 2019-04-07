#include <ESP8266WiFi.h>
 
String userKey = "u4hqabh76twgXXXXXXXXXXXXXXXXXX";        // your Pushover user key
String apiToken = "aq8k5xjhwcyoXXXXXXXXXXXXXXXXXX";       // your Pushover API token
String Title = "ESP8266(WeMos) Door Open Notification";   // your title of the message
 
const char* ssid = "SJSLGU";                           // your ssid
const char* password = "123456789b";                      // your password
 
int pinLED = 2;                                           // internal LED 
int pinSwitch = 5;                                       // switch pin (D5 of the WeMos)
int pinState = HIGH;
int length;
 
WiFiClient client;
 
void setup() {
  WiFi.begin(ssid, password);
  Serial.begin(9600);
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(WiFi.status());
  }
  pinMode(pinLED, OUTPUT);
  pinMode(pinSwitch, INPUT_PULLUP);
  
  pinState = digitalRead(pinSwitch);
  digitalWrite(pinLED, pinState);
}
 
void loop() {
   digitalWrite(pinLED, digitalRead(pinSwitch));
   
  if (pinState != digitalRead(pinSwitch)) {
    pinState = !pinState;
    digitalWrite(pinLED, pinState);
    if (pinState){
      sendToPushover("* Door OPENED !!! * 문이 열렸습니다 *");
    }
    else {
      sendToPushover("* Door CLOSED !!! * 문이 닫혔습니다 *");
    }
  }
}
 
void sendToPushover(String Msg) {
  Msg = Msg+"&title="+Title;
  length = Msg.length()+81;
  if (client.connect("api.pushover.net", 80)) {
    client.println("POST /1/messages.json HTTP/1.1");
    client.println("Host: api.pushover.net");
    client.println("Connection: close\r\nContent-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.print(length);
    client.println("\r\n");
    client.print("token="+apiToken+"&user="+userKey+"&message="+Msg);
    client.stop();
  }
}
