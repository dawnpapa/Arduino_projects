// 알칸도 사선주행 밸런싱 로봇 - 좌우 스텝모터 구동 체크 (V1.0)
//
// 본 프로그램은 오픈소스(GPL v2)인 JJROBOTS의 BROBOT EVO 2 소스(V2.82)를 기본으로 하여
// 가급적 최소한의 수정을 통해 작성되었습니다.
// 원본 소스는 깃허브(github)에서 'jjrobot' 혹은 'brobot'의 검색을 통해 보실 수가 있습니다.
// 
// 본 프로그램은 아두이노 레오나르도와 알칸도 사선주행 밸런싱 로봇 쉴드를 기준으로 작성되었습니다.
//
// 프로그램을 업로드한 후, 스텝모터에 외부전원(7.4~9.0V)을 넣으면 스텝모터가 움직입니다. 
// 맨 처음 앞뒤로 짧은 회전을 5회 반복한 후에 저속에서 고속까지, 고속에서 저속까지 방향을 바꿔가며 회전을 반복합니다.
// 이때 A4988 스텝모터 드라이버에 있는 전류제한 가변저항(다이얼)을 미세 조정하여 원활한 회전이 가능하도록 합니다.
// 알칸도 사선주행 밸런싱 로봇 키트에 있는 스텝모터 드라이버는 약 0.5~0.6A 정도로 사전 조정 및 모터구동 확인 후에 포장됩니다.
// 좌측바퀴는 시계방향, 우측바퀴는 반시계방향으로 고속회전을 시작합니다만,
// 만일 회전방향이 반대로 시작되면 스텝모터 1, 2, 3, 4번 커넥터를 역으로 끼우면 됩니다. 
//

#define MAX_CONTROL_OUTPUT 500
#define ZERO_SPEED 65535
#define MAX_ACCEL 14            // Maximun motor acceleration (MAX RECOMMENDED VALUE: 20) (default:14)
#define MICROSTEPPING 16    // 8 or 16 for 1/8 or 1/16 driver microstepping (default:16)

// AUX definitions
#define CLR(x,y) (x&=(~(1<<y)))
#define SET(x,y) (x|=(1<<y))

// position control
volatile int32_t steps1;
volatile int32_t steps2;

int16_t speed_M1, speed_M2;        // Actual speed of motors
int8_t  dir_M1, dir_M2;            // Actual direction of steppers motors

void setup() {
  pinMode(4, OUTPUT);   // ENABLE MOTORS
  pinMode(7, OUTPUT);   // STEP MOTOR 1 PORTE,6
  pinMode(8, OUTPUT);   // DIR MOTOR 1  PORTB,4
  pinMode(12, OUTPUT); // STEP MOTOR 2 PORTD,6
  pinMode(5, OUTPUT);   // DIR MOTOR 2  PORTC,6
  digitalWrite(4, HIGH);    // Disbale motors

  // STEPPER MOTORS INITIALIZATION
  // MOTOR1 => TIMER1
  TCCR1A = 0;                       // Timer1 CTC mode 4, OCxA,B outputs disconnected
  TCCR1B = (1 << WGM12) | (1 << CS11); // Prescaler=8, => 2Mhz
  OCR1A = ZERO_SPEED;               // Motor stopped
  dir_M1 = 0;
  TCNT1 = 0;
  
  // MOTOR2 => TIMER3
  TCCR3A = 0;                       // Timer3 CTC mode 4, OCxA,B outputs disconnected
  TCCR3B = (1 << WGM32) | (1 << CS31); // Prescaler=8, => 2Mhz
  OCR3A = ZERO_SPEED;   // Motor stopped
  dir_M2 = 0;
  TCNT3 = 0;
  delay(200);

  // Enable stepper drivers and TIMER interrupts
  digitalWrite(4, LOW);   // Enable stepper drivers
  // Enable TIMERs interrupts
  TIMSK1 |= (1 << OCIE1A); // Enable Timer1 interrupt
  TIMSK3 |= (1 << OCIE1A); // Enable Timer3 interrupt

  // Little motor vibration and servo move to indicate that robot is ready
  for (uint8_t k = 0; k < 5; k++) {
    setMotorSpeedM1(5);
    setMotorSpeedM2(5);
    delay(200);
    setMotorSpeedM1(-5);
    setMotorSpeedM2(-5);
    delay(200);
  }
}

void loop() {
  digitalWrite(4, LOW);  // 스텝모터 작동
  for(int16_t i = 0; i < MAX_CONTROL_OUTPUT; i += 5) {
    setMotorSpeedM1(i);
    setMotorSpeedM2(i);
    delay(100);
  }
  for(int16_t i = MAX_CONTROL_OUTPUT; i > -MAX_CONTROL_OUTPUT; i -= 5) {
    setMotorSpeedM1(i);
    setMotorSpeedM2(i);
    delay(100);
  }
  for(int16_t i = -MAX_CONTROL_OUTPUT; i < 0; i += 5) {
    setMotorSpeedM1(i);
    setMotorSpeedM2(i);
    delay(100);
  }
  digitalWrite(4, HIGH);  // 스텝모터 불능
  setMotorSpeedM1(0);
  setMotorSpeedM2(0);
  delay(3000);
}


// TIMER 1 : STEPPER MOTOR1 SPEED CONTROL
ISR(TIMER1_COMPA_vect) {
  if (dir_M1 == 0) // If we are not moving we dont generate a pulse
    return;
  // We generate 1us STEP pulse
  SET(PORTE, 6); // STEP MOTOR 1
  //delay_1us();
  if (dir_M1 > 0)
    steps1--;
  else
    steps1++;
  CLR(PORTE, 6);
}

// TIMER 3 : STEPPER MOTOR2 SPEED CONTROL
ISR(TIMER3_COMPA_vect) {
  if (dir_M2 == 0) // If we are not moving we dont generate a pulse
    return;
  // We generate 1us STEP pulse
  SET(PORTD, 6); // STEP MOTOR 2
  //delay_1us();
  if (dir_M2 > 0)
    steps2--;
  else
    steps2++;
  CLR(PORTD, 6);
}

// Set speed of Stepper Motor1
// tspeed could be positive or negative (reverse)
void setMotorSpeedM1(int16_t tspeed) {
  long timer_period;
  int16_t speed;

  // Limit max speed?

  // WE LIMIT MAX ACCELERATION of the motors
  if ((speed_M1 - tspeed) > MAX_ACCEL)
    speed_M1 -= MAX_ACCEL;
  else if ((speed_M1 - tspeed) < -MAX_ACCEL)
    speed_M1 += MAX_ACCEL;
  else
    speed_M1 = tspeed;

#if MICROSTEPPING==16
  speed = speed_M1 * 50; // Adjust factor from control output speed to real motor speed in steps/second
#else
  speed = speed_M1 * 25; // 1/8 Microstepping
#endif

  if (speed == 0)
  {
    timer_period = ZERO_SPEED;
    dir_M1 = 0;
  }
  else if (speed > 0)
  {
    timer_period = 2000000 / speed; // 2Mhz timer
    dir_M1 = 1;
    SET(PORTB, 4); // DIR Motor 1 (Forward)
  }
  else
  {
    timer_period = 2000000 / -speed;
    dir_M1 = -1;
    CLR(PORTB, 4); // Dir Motor 1
  }
  if (timer_period > 65535)   // Check for minimun speed (maximun period without overflow)
    timer_period = ZERO_SPEED;

  OCR1A = timer_period;
  // Check  if we need to reset the timer...
  if (TCNT1 > OCR1A)
    TCNT1 = 0;
}

// Set speed of Stepper Motor2
// tspeed could be positive or negative (reverse)
void setMotorSpeedM2(int16_t tspeed) {
  long timer_period;
  int16_t speed;

  // Limit max speed?

  // WE LIMIT MAX ACCELERATION of the motors
  if ((speed_M2 - tspeed) > MAX_ACCEL)
    speed_M2 -= MAX_ACCEL;
  else if ((speed_M2 - tspeed) < -MAX_ACCEL)
    speed_M2 += MAX_ACCEL;
  else
    speed_M2 = tspeed;

#if MICROSTEPPING==16
  speed = speed_M2 * 50; // Adjust factor from control output speed to real motor speed in steps/second
#else
  speed = speed_M2 * 25; // 1/8 Microstepping
#endif

  if (speed == 0)
  {
    timer_period = ZERO_SPEED;
    dir_M2 = 0;
  }
  else if (speed > 0)
  {
    timer_period = 2000000 / speed; // 2Mhz timer
    dir_M2 = 1;
    CLR(PORTC, 6);   // Dir Motor2 (Forward)
  }
  else
  {
    timer_period = 2000000 / -speed;
    dir_M2 = -1;
    SET(PORTC, 6);  // DIR Motor 2
  }
  if (timer_period > 65535)   // Check for minimun speed (maximun period without overflow)
    timer_period = ZERO_SPEED;

  OCR3A = timer_period;
  // Check  if we need to reset the timer...
  if (TCNT3 > OCR3A)
    TCNT3 = 0;
}
