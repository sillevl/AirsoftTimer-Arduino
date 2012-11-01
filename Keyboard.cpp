/*#include "Keyboard.h"


Keyboard::Keyboard(){
	const byte ROWS = 4; //four rows
	const byte COLS = 3; //three columns
	char keys[ROWS][COLS] = {
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'},
		{'*','0','#'}
	};
	byte rowPins[ROWS] = {1, 6, 5, 3}; //connect to the row pinouts of the keypad
	byte colPins[COLS] = {2, 0, 4}; //connect to the column pinouts of the keypad

	Keypad_I2C ( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR );
}*/