
#include <LiquidCrystal.h>
#include <Wire.h>
#include <Keypad_I2C.h>
#include <Keypad.h>

#include "Game.h"
#include "LedBar.h"
#include "Buttons.h"

#define I2CADDR 0x38
#define LEDADDR 0x39
#define BTNADDR 0x39

LiquidCrystal lcd(13, 12, 11, 9, 10, 8);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {1, 6, 5, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 0, 4}; //connect to the column pinouts of the keypad

Keypad_I2C kpd( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR );
LedBar ledbar(LEDADDR);
Buttons buttons(BTNADDR);

Game* game;

void setup()   
{
  Serial.begin(9600);
  Serial.print("Hello Serial for PIC");

  game = new Game(&lcd, &kpd, &ledbar, &buttons, 6,5);
}



void loop()                     
{   
    game->loop();
}

