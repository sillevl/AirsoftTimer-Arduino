
#ifndef Game_h
#define Game_h
 
#include <arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <Keypad_I2C.h>
#include <Keypad.h>

#include "LedBar.h"
#include "Buttons.h"
#include "BigNumber.h"
#include "Beep.h"

#include "MemoryFree.h"

enum state {INIT,RUN,END};

class Game{
  public: 
    Game(LiquidCrystal* lcd, Keypad_I2C* keyboard, LedBar* ledbar, Buttons* buttons, int horn, int beep);
    void loop();
  private: 
    Beep* beep;

    int batteryPin; // battery pin
  	LiquidCrystal* lcd;
  	Keypad_I2C* keyboard;
    LedBar* ledbar;
    Buttons* buttons;

    BigNumber* bigNumber;

  	state gamestate;

  	void init();
    double getBatteryVoltage(void);


    long minutes;
    unsigned long startTime;
    bool run;

    String teamName;
    int currentTeam;
};

#endif
