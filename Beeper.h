
#ifndef Beeper_h
 #define Beeper_h
 
#include "Arduino.h"
 

class Beeper{
  public: 
    Beeper(int pin);
    void beep(int time);
  private: 
    int _pin;
};

#endif
