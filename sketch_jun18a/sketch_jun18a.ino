#include <OneWire.h>
#define PIN 9
#define N_CELL 8
NulSom_Rainbow stick = NulSom_Rainbow(N_CELL,PIN);
int DS18S20_Pin = 3;
OneWire ds(DS18S20_Pin);
float temperature = 0;
void setup() {
 Serial.begin(9600);
}
void loop(){
  float temperature = getTemp();
  Serial.println("Temperature : "); Serial.println(temperature);
  delay(500);
}

