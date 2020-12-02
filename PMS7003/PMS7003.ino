#include <SoftwareSerial.h>

SoftwareSerial mySerial(D1, D2); // RX, TX
unsigned char  pms[32];

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
   mySerial.begin(9600);
}

void loop() {
  if(mySerial.available()>=32){

    for(int j=0; j<32 ; j++){
      pms[j]=mySerial.read();
    }
    
    int PM1_0=(pms[10]<<8)   | pms[11];
    int PM2_5=(pms[12]<<8)  | pms[13];;
    int PM10 =(pms[14]<<8)  | pms[15];;
    Serial.printf("Home Atmospheric PM1.0 : %d,  PM2.5 : %d,  PM10 : %d  \r\n", PM1_0, PM2_5,PM10);

  }
}
