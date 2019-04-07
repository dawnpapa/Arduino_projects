int fading_ledPin=11;
int fadeValue=0;
int fadeDir=1;


long fading_previousMillis=0;
long fading_interval=30;

void fading_setup(){}
void fading_loop(){
  unsigned long currentMillis=millis();
  if(currentMillis-fading_previousMillis>=fading_interval){
    fading_previousMillis=currentMillis;
    if(fadeDir==1){
      if(fadeValue<=255){
        fadeValue+=5;
        if(fadeValue>255){
          fadeValue=255;
          fadeDir=0;
        }
      }
    }
    else{
      if(fadeValue>=0){
        fadeValue-=5;
        if(fadeValue<0){
          fadeValue=0;
          fadeDir=1;
        }
      }
    }
    analogWrite(fading_ledPin,fadeValue);
    
  }
  }


