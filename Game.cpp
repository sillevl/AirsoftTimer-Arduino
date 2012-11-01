
#include "Game.h"



Game::Game(LiquidCrystal* lcd, Keypad_I2C* keyboard, LedBar* ledbar, Buttons* buttons, int horn, int beep){
	this->lcd = lcd;
	this->keyboard = keyboard;
	this->horn = horn;
	this->beep = beep;
	this->batteryPin = A0;
	this->ledbar = ledbar;
	this->buttons = buttons;
	init();

	minutes = 0;
	gamestate = INIT;
}

void Game::printTitle(){
	lcd->setCursor(0,0);
	lcd->print("Start game...");
}

void Game::printMode(String title){
/*	lcd->setCursor(0,3);
	lcd->print(title);
	lcd->setCursor(6,3);
	lcd->print("Voltage: ");
	lcd->print(getBatteryVoltage());*/
}

void Game::loop(){
/*	lcd->setCursor(0,2);
	lcd->print("freeMemory()=");
    lcd->println(freeMemory());*/

/*    lcd->setCursor(0,2);
    lcd->print(buttons->read(), BIN);*/

    char key = keyboard->getKey();
    if(key){
        tone(5,4000);
        delay(20);
        noTone(5);
    }
	unsigned long endTime = startTime + (1000 * minutes);
	unsigned long timer;

	switch(gamestate){
		case INIT:
			if(key == '*'){
				minutes = minutes /10;
			} else if (key == '#'){
				lcd->clear();
				gamestate = RUN;
				startTime = millis();
				minutes++;
				break;
			} else if(key){
				int temp = minutes;
				minutes = minutes *10 + (key-48);
				if(minutes > 60){
					minutes = temp;
				}
			}
			printTitle();
			lcd->setCursor(0,1);
			lcd->print("setMinutes: ");
			lcd->print(minutes);
			lcd->print("          ");
			printMode("INIT");
			break;
		case RUN:
			
			lcd->setCursor(0,0);
			timer = (endTime -millis())/1000;
			if(timer == 0){
				gamestate = END;
				lcd->clear();
				break;
			}
			lcd->print(timer);

			printMode("RUN");
			break;
		case END:
			lcd->setCursor(0,0);
			lcd->print("END !!!!");
			if(key == '#'){
				gamestate = INIT;
				lcd->clear();
				minutes = 0;
				break;
			}
			printMode("END");
			break;
	}
}

double Game::getBatteryVoltage(){
	int sensorValue = analogRead(batteryPin); 
	int outputValue = map(sensorValue, 0, (1023*2)/3, 0, 1000);
	return outputValue/100.0;
}


void Game::init(){
	pinMode(horn, OUTPUT);
	pinMode(beep, OUTPUT);

	ledbar->set(0xFF);

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

	tone(horn,3150);	
	delay(100);
	noTone(6);
	
	tone(beep,4000);
	delay(100);
	noTone(5);

	delay(2000);

	lcd->clear();
}