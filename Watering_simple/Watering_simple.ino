
int const interval=10; // interval hour
int swpin=12; //switch pin number
int watertime=5; //watering time in sec

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(swpin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(swpin, HIGH);   // turn on pump
  delay(1000*watertime);              // watering duration in sec
  digitalWrite(swpin, LOW);    // pump off
  delay(3600000*interval);              // interval
}
