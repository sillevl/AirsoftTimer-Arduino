#ifndef BigNumber_h
#define BigNumber_h

#include <arduino.h>
#include <LiquidCrystal.h>

		static const char bignumchars1[40]={4,1,4,32, 1,4,32,32, 3,3,4,32, 1,3,4,32, 4,2,4,32,   4,3,3,32, 4,3,3,32, 1,1,4,32,   4,3,4,32, 4,3,4,32};
    	static const char bignumchars2[40]={4,2,4,32, 2,4,2,32,  4,2,2,32, 2,2,4,32, 32,32,4,32, 2,2,4,32, 4,2,4,32, 32,32,4,32, 4,2,4,32, 2,2,4,32}; 


class BigNumber{
	public:
		BigNumber(LiquidCrystal* lcd);
		void setCursor(char x,char line);
		void printNumber(char number);
		void printTime(int minutes);
		void printCollon();
	private:


		
		LiquidCrystal* lcd;

		char x;
		char line;
};


#endif