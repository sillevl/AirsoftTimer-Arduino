
#include "Beep.h"


Beep::Beep(int beep, int horn){
	this->beeper = beep;
	this->horn = horn;
	toneHz = 1950;
	pinMode(horn, OUTPUT);
	pinMode(beep, OUTPUT);
}

void Beep::run(){
	unsigned long now = millis();
	if(beepEnd < now){ 
		noTone(beeper); 
	}
	if(hornEnd < now){ 
		noTone(horn);
	} else {
		if(runstart < millis()){
			runstart = millis() + 10;
			tone(horn, toneHz);
			toneHz = toneHz + 10;
			if(toneHz > 2050) toneHz = 1950;
		}
	}
}

void Beep::key(){
    tone(beeper,4000);
    beepEnd = millis() + 20;
}

void Beep::keyError(){
	tone(beeper,3500);
    beepEnd = millis() + 100;
}

void Beep::tick(){
	tone(horn,500);
	hornEnd = millis() + 2;
}

void Beep::tock(){
	tone(horn,2000);
	hornEnd = millis() + 100;
}

void Beep::alarm(){
	//tone(horn, 2800);
	runstart = millis();
	hornEnd = millis() + 60000;
}

void Beep::off(){
	noTone(beeper);
	noTone(horn);
	runstart = 0 - 1;
}

void Beep::confirm(){
	tone(beeper,4000);
    beepEnd = millis() + 500;
}




/*	tone(horn,3150);	
	delay(100);
	noTone(6);
	
	tone(beep,4000);
	delay(100);
	noTone(5);*/