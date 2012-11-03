
#include "BigNumber.h"


BigNumber::BigNumber(LiquidCrystal* lcd){
	this->lcd = lcd;

	uint8_t chars[5][8]={
	  		{0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	  		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F},
	  		{0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F},
	  		{0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F},
	  		{0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00}
	  	};

    for(char x=0;x<5;x++){     
    	lcd->createChar(x+1, chars[x]);
    	delay(1);
    }
}

void BigNumber::printTime(int minutes){
	x = x + 12;
	char sec = minutes % 60;
	char min = (minutes - sec) / 60;
	printNumber(sec%10);
	x = x -4;
	printNumber((sec - sec % 10) / 10);
	x = x -2;
	printCollon();
	x = x -4;
	printNumber(min%10);
	x = x -4;
	printNumber((min - min % 10) / 10);
/*	do{
		printNumber(minutes % 10);
		minutes = minutes / 10;
		x = x -4;
	}while(minutes != 0);*/
}

void BigNumber::setCursor(char x, char line){
	this->x = x;
	this->line = line;
}

void BigNumber::printNumber(char number){
	lcd->setCursor(x,line);
	for(int i = 0; i < 4; i++)
		lcd->print(bignumchars1[(number*4)+i]);
	lcd->setCursor(x,line+1);
	for(int i = 0; i < 4; i++)
		lcd->print(bignumchars2[(number*4)+i]);
}

void BigNumber::printCollon(){
	lcd->setCursor(x,line);
	lcd->write(0x05);
	lcd->setCursor(x,line+1);
	lcd->write(0x05);
}