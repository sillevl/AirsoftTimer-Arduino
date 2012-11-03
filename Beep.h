#ifndef Beep_h
#define Beep_h

#include <arduino.h>

class Beep{
	public:
		Beep(int beeper, int horn);
		void key();
		void keyError();
		void confirm();
		void tick();
		void alarm();
		void off();
		void run();
	private:
		int beeper;
		int horn;
		unsigned long beepEnd;
		unsigned long hornEnd;
		unsigned long runstart;
		int toneHz;
};


#endif