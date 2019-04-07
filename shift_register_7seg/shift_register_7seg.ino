
#define DATA 6
#define LATCH 8
#define CLOCK 10

int digits[]={252,96,218,242,102,182,190,224,254,246,238,62,156,122,158,142};

void setup() 
{
Serial.begin(9600);
pinMode(DATA,OUTPUT);
pinMode(LATCH,OUTPUT);
pinMode(CLOCK,OUTPUT); 

}

void loop() 
{
  int i;
  for(i=0;i<16;i++)
  {
    digitalWrite(LATCH,LOW);
    shiftOut(DATA,CLOCK,LSBFIRST,digits[i]);
    digitalWrite(LATCH,HIGH);
    Serial.println(i);
    delay(1000);
  }

}
