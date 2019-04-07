//- See more at: http://www.esp8266.com/viewtopic.php?f=29&t=6007&start=5#sthash.J2YTZ7f7.dpuf
 
#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <Time.h>
//#include <DHT11.h>

#define DHTPIN 8 //dht11 pin
//#define DHTTYPE DHT11

//DHT11 dht11(DHTPIN); //DHT pin type
LiquidCrystal_I2C lcd(0x27,16,2); //address, lcd type
 
const char* ssid = "SJSLGU";
const char* password = "123456789b";
const char* month_arr[13] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const char* day_arr[8] = {"Sun", "Mon", "Tue", "Wen", "Thu", "Fri", "Sat"};
char buf[40];
char* time_cut=0;
char* time_val[8]={0};
char DaysOfMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};

float humid;
float temp;
 
void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200); 
  Serial.println();

  lcd.init();
  lcd.backlight();
 
  initWifi();
  delay(2000);
  lcd.clear();

}
 
void loop() {
 // lcd.clear();
  
  String str_time = getTime();
  str_time.toCharArray(buf, 30);
  
  time_cut = strtok(buf, ", :");  
  for(int i=0; time_cut; i++){ 
    time_val[i] = time_cut; 
    time_cut = strtok(0, ", :");
  }
  int year   = atoi(time_val[3]);
  int month  = month_to_digit((char *)time_val[2]);
  int date   = atoi(time_val[1]);
  int day    = day_to_digit((char *)time_val[0]);
  int hour   = atoi(time_val[4]) + 9;
  int minute = atoi(time_val[5]);
  int second = atoi(time_val[6]);
  
  if(hour>23) {
    hour %=24;
    if(++day>6) day=0;
    if     (!(year%400)) DaysOfMonth[1]=29;  // 윤년/윤달 계산
    else if(!(year%100)) DaysOfMonth[1]=28; 
    else if(!(year%  4)) DaysOfMonth[1]=29;  
    
    if(date<DaysOfMonth[month-1]) date++;
    else {
      date=1;
      if(++month>12) {
        month=1;
        year++;
      }  
    }
  }
  
  Serial.println(str_time);
  sprintf(buf, "%04d/%02d/%02d %s", year, month, date, day_arr[day]);
  lcd.setCursor(0,0);
  lcd.print(buf);
  sprintf(buf, "%02d:%02d:%02d ", hour, minute, second);
 
  lcd.setCursor(0,1);
  lcd.print(buf);
  Serial.print("------------------\r\n");
  

 
/* dht11.read(humid,temp);
  Serial.println(humid);
  lcd.print("% ");
  Serial.println(temp);
  lcd.print("C");
  //digitalWrite(2, HIGH); */
  delay(1000);
  //digitalWrite(2, LOW);

}
 
int month_to_digit(char* str) {
  for(int i=0; i<12; i++) {
      if(!strncmp(str, (char *)month_arr[i], 3)) return i+1;
  }
}
int day_to_digit(char* str) {
  for(int i=0; i<7; i++) {
      if(!strncmp(str, (char *)day_arr[i], 3)) return i;
  }
}
 
String getTime() {
  WiFiClient client;
  while (!!!client.connect("google.com", 80)) {
      Serial.println("connection failed, retrying...");
  }
 
  client.print("HEAD / HTTP/1.1\r\n\r\n");
 
  while(!!!client.available()) {
     delay(500);
     //lcd.clear();
     lcd.print(".");
     //yield();
  }
 
  while(client.available()){
    if (client.read() == '\n') {    
      if (client.read() == 'D') {    
        if (client.read() == 'a') {    
          if (client.read() == 't') {    
            if (client.read() == 'e') {    
              if (client.read() == ':') {    
                client.read();
                String theDate = client.readStringUntil('\r');
                client.stop();
                return theDate;
              }
            }
          }
        }
      }
    }
  }
}
 
void initWifi() {
   //lcd.scrollDisplayLeft();
   lcd.print("Connecting to ");
   lcd.setCursor(0,1);
   lcd.print(ssid);
   
   //if (strcmp (WiFi.SSID(),ssid) != 0) {
      WiFi.begin(ssid, password);
   //}
 
   while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      lcd.print(".");
   }
  lcd.clear();
  //lcd.scrollDisplayLeft();
  
  lcd.print("WiFi connected!");
  lcd.setCursor(0,1);
  lcd.print(WiFi.localIP());

  
}


