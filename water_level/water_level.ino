void setup()
{
  Serial.begin(9600);
  pinMode(3,INPUT);
}
void loop()
{
  int level = analogRead(A0);
  int level_d=digitalRead(3);

  // analog input: no water: 0, full water: 670
  // digital input: no water:0, with water: 1
  Serial.println(level);
  Serial.println(level_d);
  delay(1000);
}
