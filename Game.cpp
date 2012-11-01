
#include "Game.h"


Game::Game(LiquidCrystal* lcd, Keypad_I2C* keyboard, int horn, int beep){
	this->lcd = lcd;
	this->keyboard = keyboard;
	this->horn = horn;
	this->beep = beep;
	init();
}

void Game::printTitle(){
	lcd->setCursor(0,0);
	lcd->print("Start game...\xFF");
}

void Game::printMode(String title){
	lcd->setCursor(0,3);
	lcd->print(title);
}

void Game::getNumber(){
	lcd->setCursor(0,1);
	lcd->print("setMinutes: ");

	char key = keyboard->getKey();
  
  	if(key){
        lcd->print(key);
        tone(5,4000);
        delay(20);
        noTone(5);
    }

}

void Game::loop(){
	gamestate = INIT;
	int minutes;
	
	switch(gamestate){
		case INIT:
			printTitle();
			getNumber();
			printMode("INIT");
			break;
		case RUN:
			lcd->print("RUN");
			break;
		case END:
			lcd->print("END");
			break;
	}
}


void Game::init(){
	pinMode(horn, OUTPUT);
	pinMode(beep, OUTPUT);

	keyboard->begin();
	lcd->begin(20,4);

	lcd->setCursor(0,0);
	lcd->print("    \xFF\xFF\xFF  \xFF  \xFF\xFF\xFF");
	lcd->setCursor(0,1);
	lcd->print("    \xFF \xFF  \xFF  \xFF");
	lcd->setCursor(0,2);
	lcd->print("    \xFF\xFF\xFF  \xFF  \xFF");
	lcd->setCursor(0,3);
	lcd->print("    \xFF    \xFF  \xFF\xFF\xFF");

	tone(6,2800);
	delay(50);
	noTone(6);
	
	tone(5,4000);
	delay(50);
	noTone(5);

	delay(2000);

	for(int i = 0; i< 20; i++){
		delay(100);
		lcd->scrollDisplayLeft();
	}
	lcd->clear();
}