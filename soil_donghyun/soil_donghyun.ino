const char analogInPin = A0; // Analog input pin that the potentiometer is attached to
const int MotorPin1 = 2; // output pin that the Motor is attached to
const int limit = 350; // limit value to put water
int sensorValue = 0; // value read from the pot

void setup() {
// initialize serial communications at 9600 bps:
Serial.begin(9600);
pinMode(analogInPin, INPUT);
pinMode(MotorPin1, OUTPUT);
}

void loop() {
sensorValue = analogRead(analogInPin);

Serial.print("sensor = ");
Serial.println(sensorValue);

if ( sensorValue < limit ) {
digitalWrite(MotorPin1,HIGH);
Serial.print("Motor working.........");
Serial.println(sensorValue);

delay(5000);

digitalWrite(MotorPin1,LOW);
}
delay(3000); 
}
