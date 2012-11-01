
#include "Buttons.h"

Buttons::Buttons(int address){
	this->address = address;
	Wire.begin();
}

/*void Buttons::read(int data){
	Wire.beginTransmission(address); // transmit to device #4
  	Wire.write(data);              // sends one byte  
  	Wire.endTransmission();    // stop transmitting
}*/

byte Buttons::read(){
	byte result = 0x00;
	Wire.requestFrom(address,1);
	while(Wire.available()){
		result = Wire.read();
	}
	return result;
}