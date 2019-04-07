void setup() 
{
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
analogWrite(5,128);
delay(500);
digitalWrite(5,LOW);
delay(500);
analogWrite(5,1);
delay(500);
digitalWrite(5,LOW);
delay(500);
analogWrite(5,150);
delay(500);
digitalWrite(5,LOW);
delay(1000);
}
