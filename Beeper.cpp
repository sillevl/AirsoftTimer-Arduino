
#include "Beeper.h"

Beeper::Beeper(int pin){
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void Beeper::beep(int time){
  long totalTime = time * 4;
  for(int i = 0;i < totalTime; i++){
    digitalWrite(_pin,HIGH);
    delayMicroseconds(128);
    digitalWrite(_pin,LOW);
    delayMicroseconds(128);
  }
}
