
#ifndef LedBar_h
#define LedBar_h
 
#include <arduino.h>
#include <Wire.h>


class LedBar{
  public: 
    LedBar(int address);
    void set(int number);
    void run();
    void alarm();
    void allOff();
    void allOn();
  private:
    int address;
    void send(int data);
    int map(int data);

    long runstart;
    char runLed;
    bool direction;
};

#endif
