
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

	teamName = "Bravo";
	currentTeam = 0;
	teamCode = 0;
	tocking = false;
	askTocking = false;

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
	
	long timer  = (long)(endTime - millis());
	//Serial.println(timer);
	timer = timer / 1000;
	//Serial.println(timer);
	//Serial.println("*******");

	Serial.println(buttons->read(), BIN);


	switch(gamestate){
		case INIT:
			if(!askTocking){
				if(key == '*'){
					minutes = 0;
				} else if (key == '#'){
					lcd->clear();
					askTocking = true;
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
			}else{
				if(key == '#'){
					lcd->clear();
					ledbar->set(0x01);
					gamestate = RUN;
					askTocking = false;
					startTime = millis();
					break;
				} else if(key == '*'){
					tocking = !tocking;
				}
				lcd->setCursor(0,0);
				lcd->print("- use timer beeps -");
				lcd->setCursor(6,2);
				if(tocking){
					lcd->print("YES");
				} else {
					lcd->print("NO ");
				}
			}
			break;
		case RUN:
			if(!run){
				startTime = millis();
			} 
			if(key && key != '#' && key != '*'){
				int temp = teamCode;
				teamCode = teamCode *10 + (key-48);
				if(teamCode > 10000 || teamCode < 0){
					teamCode = temp;
					beep->keyError();
				}
			}
			if(key == '#'){
				if(teamCode == 1397){
					teamName = "Alpha";
					run = true;
					startTime = millis();
					beep->confirm();
				} else if(teamCode == 2684){
					teamName = "Bravo";
					run = true;
					startTime = millis();
					beep->confirm();
				} else if(teamCode == 1597){
					teamName = "Charlie";
					run = true;
					startTime = millis();
					beep->confirm();
				} else if(teamCode == 3579){
					teamName = "Delta";
					run = true;
					startTime = millis();
					beep->confirm();
				} else {
					beep->keyError();
				}
				teamCode = 0;
			}

			if(key == '*'){
				teamCode = 0;
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

				lcd->setCursor(3,3);
				lcd->print("Team: ");
				lcd->print(teamName);
				lcd->print("    ");

				if(tickCounter != timer){
					tickCounter = timer;
					if(timer%3 == 0 && tocking){
						beep->tock();
					}else{
						beep->tick();
					}
				}
			}

			lcd->setCursor(8,2);

			if(teamCode != 0){
				lcd->print(teamCode);
				lcd->print("      ");
			} else {
				lcd->print("code ?");
			}
			

			
			bigNumber->setCursor(4,0);
			bigNumber->printTime(timer);

			break;
		case END:
			if(run && key){
				run = false;
				beep->off();
				break;
			}
			//if(run){
				ledbar->alarm();
			//}
			lcd->setCursor(3,0);
			lcd->print("- GAME OVER -");
			lcd->setCursor(0,2);
			lcd->print("Winning team: ");
			//lcd->setCursor(0,3);
			lcd->print(teamName);

			if(key == '#'){
				gamestate = INIT;
				lcd->clear();
				ledbar->allOff();
				minutes = 0;
				break;
			} else if(key){
				beep->keyError();
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
	ledbar->allOff();

	tone(6,2000);	
	delay(100);
	noTone(6);
	
	tone(5,4000);
	delay(100);
	noTone(5);

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

	delay(5000);

	lcd->clear();
}