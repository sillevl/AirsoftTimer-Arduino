
#ifndef Buttons_h
#define Buttons_h
 
#include <arduino.h>
#include <Wire.h>


class Buttons{
  public: 
    Buttons(int address);
    byte read();
  private:
    int address;
};

#endif
