// 알칸도 초음파 센서 모듈, ATtiny84 소스 프로그램 (http://www.RSFTech.com) V2.0
// distance[ ] : 왼쪽/전방/오른쪽/별도('알칸도 초음파 센서모듈-2') 거리(Cm)
// >>>>>로 표현된 라인의 값을 적절하게 바꿔 사용 가능

#include "TinyWireS.h"
#define I2C_SLAVE_ADDR 7            // >>>>> I2C 슬레이브 주소
#define ULTRASONIC_NUM 3          // >>>>> 초음파 센서를 하나 더 추가할 경우 4로 변경('알칸도 초음파 센서모듈-2') 

int trigerPin = 8;
int echoPin[] = { 1, 2, 3, 10 };
int ledPin[] = { 0, 9, 7 };

unsigned long duration[ULTRASONIC_NUM];
uint8_t distance[ULTRASONIC_NUM], preDistance[ULTRASONIC_NUM][3];
unsigned long preTimeLed;

void requestEvent() {
  for (int i = 0; i < ULTRASONIC_NUM; i++)
    TinyWireS.send(distance[i]);
}

void setup() {
  TinyWireS.begin(I2C_SLAVE_ADDR);
  TinyWireS.onRequest(requestEvent);
  pinMode(trigerPin, OUTPUT);
  for(int i = 0; i < 4; i++) {
    pinMode(echoPin[i], INPUT);
    if(i != 3)
      pinMode(ledPin[i], OUTPUT);
    for(int j = 0; j < 3; j++) {
      ultrasonic(i);
      preDistance[i][j] = distance[i];
      delay(10);
    }
  }
  preTimeLed = millis();
}

void loop() {
  for(int i = 0; i < ULTRASONIC_NUM; i++)
  {
    ultrasonic(i);
    for(int j = 0; j < 2; j++) {
      preDistance[i][j] = preDistance[i][j+1];
    }
    distance[i] = preDistance[i][2] = (preDistance[i][0] + preDistance[i][1] + distance[i])/3.0;     // >>>>> 직전의 거리 데이터 2개와 측정 데이터의 평균값(3개 평균값)
    if(i != 3) {
      if(distance[i] < 30) {
        ledBlink(i);
      } else {
        ledOff(i);
      }
    }
    delay(2);
  }
  // TinyWireS_stop_check();  
}

void ultrasonic(int i) {
  digitalWrite(trigerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPin, HIGH);
  delayMicroseconds(5);                   // >>>>> 5 혹은 10
  digitalWrite(trigerPin, LOW);
  // noInterrupts();
  duration[i] = pulseIn(echoPin[i], HIGH, 5000);
  // interrupts();
  distance[i] = (int)(duration[i] / 58.2);
  if(distance[i] == 0) distance[i] = 86;
}

void ledBlink(int p) {
  unsigned long present = millis();
  if((present - preTimeLed) > 20*distance[p]) {
    preTimeLed = present;
  } else if((present - preTimeLed) > 10*distance[p]) {
    digitalWrite(ledPin[p], 1); 
  } else {
    digitalWrite(ledPin[p], 0); 
  }
}

void ledOff(int p) {
  digitalWrite(ledPin[p], 0);
}

