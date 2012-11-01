
#ifndef Game_h
#define Game_h
 
#include <arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <Keypad_I2C.h>
#include <Keypad.h>

#include "LedBar.h"
#include "Buttons.h"

#include "MemoryFree.h"

enum state {INIT,RUN,END};

class Game{
  public: 
    Game(LiquidCrystal* lcd, Keypad_I2C* keyboard, LedBar* ledbar, Buttons* buttons, int horn, int beep);
    void loop();
  private: 
  	int horn;
  	int beep;

    int batteryPin; // battery pin
  	LiquidCrystal* lcd;
  	Keypad_I2C* keyboard;
    LedBar* ledbar;
    Buttons* buttons;

  	state gamestate;

  	void init();
  	void printTitle();
  	void printMode(String title);
    double getBatteryVoltage(void);


    int minutes;
    unsigned long startTime;
};

#endif
