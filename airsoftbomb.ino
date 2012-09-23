#include <LiquidCrystal.h>
#include "Beeper.h"


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()   
{                
  Serial.begin(9600);
  lcd.begin(20, 4);
  
  Beeper beeper(6);

  lcd.print("hello FreeRTOS!");

}



void loop()                     
{

}

