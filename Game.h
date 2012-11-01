
#ifndef Game_h
#define Game_h
 
#include <arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <Keypad_I2C.h>
#include <Keypad.h>

enum state {INIT,RUN,END};

class Game{
  public: 
    Game(LiquidCrystal* lcd, Keypad_I2C* keyboard, int horn, int beep);
    void loop();
  private: 
  	int horn;
  	int beep;
  	LiquidCrystal* lcd;
  	Keypad_I2C* keyboard;

  	state gamestate;

  	void init();
  	void printTitle();
	void printMode(String title);
	void getNumber();
};

#endif
