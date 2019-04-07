void showMenu(){
  Serial.println("1. Led blink enable/disable");
  Serial.println("2. Led fading enable/disable");
}

void serial_setup(){
  Serial.begin(115200);
  showMenu();
  }
int userCmd=0;

void serial_loop(){
  if(Serial.available()>0){
    userCmd=Serial.read();

    Serial.print("user command: ");
    Serial.println(userCmd);

    switch(userCmd){
      case '1':blink_en=!blink_en;  break;
      case '2':fading_en=!fading_en;  break;
      default: break;
    }
  }
}

