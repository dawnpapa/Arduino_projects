int blink_ledState=LOW;

long blink_previousMillis=0;
long blink_interval=1000;


void blink_setup() {
  pinMode(13,OUTPUT);
  }

void blink_loop() {
  unsigned long currentMillis=millis();
  if (currentMillis-blink_previousMillis>=blink_interval){
    blink_previousMillis=currentMillis;

    if(blink_ledState==LOW)
    blink_ledState=HIGH;
    else
    blink_ledState=LOW;

    digitalWrite(13,blink_ledState);
  }
  
  
  }
