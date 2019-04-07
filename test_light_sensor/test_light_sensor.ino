/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/

int sensorPin = A0;    // select the input pin for the potentiometer
float lightPower=0.0;
float sensorini=0.0;
float sensorValue = 0.0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);

}

void loop() {
  
  // read the value from the sensor:
  sensorini = analogRead(sensorPin);
//  sensorValue=map(sensorini, 0, 1023.0, 0, 5.0);
  sensorValue=(sensorini) * (5 - 0) / (1023 - 0);
  lightPower=sensorValue*2+10;
  Serial.print(sensorini);
  Serial.print("Measured volatage is ");
  Serial.print(sensorValue);
  Serial.print("  Light Power is ");
  Serial.println(lightPower);
  
  delay(500);
}
