
#define DATA 6
#define LATCH 8
#define CLOCK 10

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
  for(i=0;i<256;i++)
  {
    digitalWrite(LATCH,LOW);
    shiftOut(DATA,CLOCK,MSBFIRST,i);
    digitalWrite(LATCH,HIGH);
    Serial.println(i);
    delay(1000);
  }

}
