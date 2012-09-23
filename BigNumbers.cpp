/*
#include "BigNumbers.h"


BigNumbers::BigNumbers(LiquidCrystal& liquidCrystal)
{
    lcd = liquidCrystal;
  
  // assignes each segment a write number
  lcd.createChar(0,LT);
  lcd.createChar(1,UB);
  lcd.createChar(2,RT);
  lcd.createChar(3,LL);
  lcd.createChar(4,LB);
  lcd.createChar(5,LR);
  lcd.createChar(6,MB);
  lcd.createChar(7,block);        
}

void BigNumbers::custom0()
{ // uses segments to build the number 0
  lcd.setCursor(0,0); // set cursor to column 0, line 0 (first row)
  lcd.write(0);  // call each segment to create
  lcd.write(1);  // top half of the number
  lcd.write(2);
  lcd.setCursor(0, 1); // set cursor to colum 0, line 1 (second row)
  lcd.write(3);  // call each segment to create
  lcd.write(4);  // bottom half of the number
  lcd.write(5);
}

void BigNumbers::custom1()
{
  lcd.setCursor(0,0);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(0,1);
  lcd.write(4);
  lcd.write(7);
  lcd.write(4);
}

void BigNumbers::custom2()
{
  lcd.setCursor(0,0);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(0, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(4);
}

void BigNumbers::custom3()
{
  lcd.setCursor(0,0);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(0, 1);
  lcd.write(4);
  lcd.write(4);
  lcd.write(5);
}

void BigNumbers::custom4()
{
  lcd.setCursor(0,0);
  lcd.write(3);
  lcd.write(4);
  lcd.write(7);
  lcd.setCursor(2, 1);
  lcd.write(7);
}

void BigNumbers::custom5()
{
  lcd.setCursor(0,0);
  lcd.write(3);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(0, 1);
  lcd.write(4);
  lcd.write(4);
  lcd.write(5);
}

void BigNumbers::custom6()
{
  lcd.setCursor(0,0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(0, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}

void BigNumbers::custom7()
{
  lcd.setCursor(0,0);
  lcd.write(1);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(2, 1);
  lcd.write(7);
}

void BigNumbers::custom8()
{
  lcd.setCursor(0,0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(0, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}

void BigNumbers::custom9()
{
  lcd.setCursor(0,0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(2, 1);
  lcd.write(7);
}

void BigNumbers::clearnumber()
{ // clears the area the custom number is displayed in
 lcd.setCursor(0,0);
 lcd.print("   ");
 lcd.setCursor(0,1);
 lcd.print("   ");
}
*/