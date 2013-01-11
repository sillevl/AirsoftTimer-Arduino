
#include "LedBar.h"

LedBar::LedBar(int address){
	this->address = address;
	runLed = 0x01;
	Wire.begin();
}

void LedBar::send(int data){
	Wire.beginTransmission(address); // transmit to device #4
  	Wire.write(data);              // sends one byte  
  	Wire.endTransmission();    // stop transmitting
}

void LedBar::set(int data){
	send(map(data));
}


int LedBar::map(int data){
	// 4  -> led 4
	// 8  -> led 2
	// 16 -> led 5
	// 32 -> led 3
	// 64 -> led 1
	byte pinMap[] = {128,16,64,8,32};
	int output = 0;
	//data = data & B11111000;
	int mask = B00000001;
	for(int i = 0; i<5; i++){
		if(data & mask)
			output += pinMap[i];
		mask = mask << 1;
	}
	return ~output;
}

void LedBar::run(){
	if(runstart < millis()){
		runstart = millis() + 100;
		if(runLed == 0x01){
			direction = true;
		} else if(runLed == 0x10){
			direction = false;
		}
		
		if(direction){
			runLed = runLed << 1;
		} else {
			runLed = runLed >> 1;
		}
		set(runLed);
	}
}

void LedBar::alarm(){
	if(runstart < millis()){
		runstart = millis() + 100;
		int timer = ((millis() / 100)%5);
		if(timer == 0 || timer == 2){
			runLed = 0xFF;
		}else{
			runLed = 0x00;
		}
		set(runLed);
	}
}

void LedBar::allOff(){
	set(0x00);
}

void LedBar::allOn(){
	set(0xFF);
}