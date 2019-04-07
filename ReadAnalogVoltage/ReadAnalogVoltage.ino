/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() 
{
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.print("Voltage is ");
  Serial.print(voltage,3);
  Serial.println("V 입니다.");  
  if(voltage>=3.1)
  {
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  }
  else if(voltage<3.1 && voltage>2.3)
  {
    digitalWrite(12,HIGH);
    delay(1000);
    digitalWrite(12,LOW);
  }
  else if(voltage<=2.3)
  {
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(11,LOW);
  }
  
}
