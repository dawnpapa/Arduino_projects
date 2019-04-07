// 알칸도 사선주행 밸런싱 로봇 - 서보모터 구동 체크 (V1.0)
//
// 본 프로그램은 오픈소스(GPL v2)인 JJROBOTS의 BROBOT EVO 2 소스(V2.82)를 기본으로 하여
// 가급적 최소한의 수정을 통해 작성되었습니다.
// 원본 소스는 깃허브(github)에서 'jjrobot' 혹은 'brobot'의 검색을 통해 보실 수가 있습니다.
// 
// 본 프로그램은 아두이노 레오나르도와 알칸도 사선주행 밸런싱 로봇 쉴드를 기준으로 작성되었습니다.
//
// 서보모터를 쉴드에 꼽고 본 프로그램을 업로드하면 서보모터가 움직입니다. 
// 서보모터 회전 범위의 설정값 내에서 5회 회전을 반복한 후에 중앙 위치에서 정지합니다. (다시 실행하려면 아두이노 리셋 버튼을 누르세요.)
// 이 중앙 위치에서 서보혼을 서보모터의 길이 방향과 나란히 꼽아주고 코너모듈을 조립하면 됩니다.
//
// 서보모터는 플라스틱 기어로 구성되어 있어 충격을 주거나 무리한 힘으로 회전시키면 기어가 망가지니 주의하시기 바랍니다.
// 특히 기어가 잠겨 있는 경우 손으로 억지로 회전시키면 쉽게 망가집니다. 이 경우에는 아두이노를 통해 회전시키면 됩니다.
//

// Servo definitions
#define SERVO_AUX_NEUTRO 1500  // Servo neutral position
#define SERVO1_RANGE 700   // 서보모터 조향 범위
// Default servo definitions
#define SERVO1_MIN_PULSEWIDTH 700
#define SERVO1_MAX_PULSEWIDTH 2300

void setup() {
  pinMode(10, OUTPUT);  // 서보모터 신호 입력핀
  BROBOT_initServo();
  BROBOT_moveServo1(SERVO_AUX_NEUTRO);
  delay(1000);
}

void loop() {
  for(int8_t k = 0; k < 5; k++) {
    for(int16_t i = SERVO_AUX_NEUTRO; i < SERVO_AUX_NEUTRO + 0.5* SERVO1_RANGE; i += 1) {
      BROBOT_moveServo1(i);
      delay(1);
    }
    for(int16_t i = SERVO_AUX_NEUTRO + 0.5* SERVO1_RANGE; i > SERVO_AUX_NEUTRO - 0.5* SERVO1_RANGE; i -= 1) {
      BROBOT_moveServo1(i);
      delay(1);
    }
    for(int16_t i = SERVO_AUX_NEUTRO - 0.5* SERVO1_RANGE; i < SERVO_AUX_NEUTRO; i += 1) {
      BROBOT_moveServo1(i);
      delay(1);
    }
  }
  BROBOT_moveServo1(SERVO_AUX_NEUTRO);
  while(1) { }     // 서보모터 중앙 위치에서 loop 함수 정지 (이 위치에서 서보혼을 서보모터의 길이 방향과 나란히 꼽아주세요) 
}

void BROBOT_initServo() {
  int temp;

  // Initialize Timer4 as Fast PWM
  TCCR4A = (1<<PWM4A)|(1<<PWM4B);
  TCCR4B = 0;
  TCCR4C = (1<<PWM4D);
  TCCR4D = 0;
  TCCR4E = (1<<ENHC4); // Enhaced -> 11 bits

  temp = 1500>>3;
  TC4H = temp >> 8;
  OCR4B = temp & 0xff;

  // Reset timer
  TC4H = 0;
  TCNT4 = 0;

  // Set TOP to 1023 (10 bit timer)
  TC4H = 3;
  OCR4C = 0xFF;

  // OC4A = PC7 (Pin13)  OC4B = PB6 (Pin10)   OC4D = PD7 (Pin6)
  // Set pins as outputs
  DDRB |= (1 << 6);  // OC4B = PB6 (Pin10 on Leonardo board)
  DDRC |= (1 << 7);  // OC4A = PC7 (Pin13 on Leonardo board)
  DDRD |= (1 << 7);  // OC4D = PD7 (Pin6 on Leonardo board)

  //Enable OC4A and OC4B and OCR4D output
  TCCR4A |= (1<<COM4B1)|(1<<COM4A1); 
  TCCR4C |= (1<<COM4D1);
  // set prescaler to 256 and enable timer    16Mhz/256/1024 = 61Hz (16.3ms)
  TCCR4B = (1 << CS43)|(1 << CS40);
}

void BROBOT_moveServo1(int pwm) {
  pwm = constrain(pwm,SERVO1_MIN_PULSEWIDTH,SERVO1_MAX_PULSEWIDTH)>>3;  // Check max values and Resolution: 8us
  // 11 bits => 3 MSB bits on TC4H, LSB bits on OCR4B
  TC4H = pwm>>8;
  OCR4B = pwm & 0xFF;
}
