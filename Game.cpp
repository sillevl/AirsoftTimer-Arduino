
#include "Game.h"



Game::Game(LiquidCrystal* lcd, Keypad_I2C* keyboard, LedBar* ledbar, Buttons* buttons, int horn, int beep){
	this->lcd = lcd;
	this->keyboard = keyboard;
	this->batteryPin = A0;
	this->ledbar = ledbar;
	this->buttons = buttons;

	bigNumber = new BigNumber(lcd);
	this->beep = new Beep(beep, horn);

	init();

	minutes = 0;
	gamestate = INIT;
	run = false;
}

void Game::loop(){
/*	lcd->setCursor(0,2);
	lcd->print("freeMemory()=");
    lcd->println(freeMemory());*/

/*    lcd->setCursor(0,2);
    lcd->print(buttons->read(), BIN);*/
    beep->run();

    char key = keyboard->getKey();
    if(key){
    	beep->key();
    }
	long endTime = startTime + (1000L * minutes * 60L) + 1000L;
	
	long timer  = (long)(endTime - millis())/1000L;

	switch(gamestate){
		case INIT:
			if(key == '*'){
				minutes = 0;
			} else if (key == '#'){
				lcd->clear();
				ledbar->set(0x01);
				gamestate = RUN;
				startTime = millis();
				break;
			} else if(key){
				long temp = minutes;
				minutes = minutes *10 + (key-48);
				if(minutes > 60){
					minutes = temp;
					beep->keyError();
				}

			}
			lcd->setCursor(3,0);
			lcd->print("- Set time - ");
			bigNumber->setCursor(3,2);
			bigNumber->printTime(minutes*60);
			break;
		case RUN:
			if(!run){
				startTime = millis();
			}
			if(key){
				startTime = millis();
				run = true;
			}
			//timer = (endTime - millis())/1000;
			if(timer < 0){
				gamestate = END;
				lcd->clear();
				beep->alarm();
				break;
			}
			if(run){
				ledbar->run();
			}
			
			bigNumber->setCursor(4,1);
			bigNumber->printTime(timer);

			break;
		case END:
			if(run && key){
				run = false;
				beep->off();
				break;
			}
			lcd->setCursor(3,1);
			lcd->print("- GAME OVER -");
			if(key == '#'){
				gamestate = INIT;
				lcd->clear();
				minutes = 0;
				break;
			}
			break;
	}
}

double Game::getBatteryVoltage(){
	int sensorValue = analogRead(batteryPin); 
	int outputValue = map(sensorValue, 0, (1023*2)/3, 0, 1000);
	return outputValue/100.0;
}


void Game::init(){
	ledbar->set(0x1F);

	beep->key();

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

//	delay(2000);

	lcd->clear();
}