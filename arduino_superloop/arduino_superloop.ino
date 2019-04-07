int blink_en=1;
int fading_en=1;


void setup() {
  
  blink_setup();
  fading_setup();
  serial_setup();
}

void loop() {
  if (blink_en==1)
  blink_loop();
  
  if(fading_en==1)
  fading_loop();

  serial_loop();

}
