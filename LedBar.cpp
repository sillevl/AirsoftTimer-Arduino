
#include "LedBar.h"

LedBar::LedBar(int address){
	this->address = address;
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
	Serial.print(output, BIN);
	return ~output;
}