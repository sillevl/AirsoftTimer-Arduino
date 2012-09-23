#include <LiquidCrystal.h>
#include "Beeper.h"
//#include "BigNumbers.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()   
{                
  Serial.begin(9600);
  lcd.begin(20, 4);
  
  Beeper beeper(6);
  beeper.beep(1000);

  Serial.print("hello DuinOs and FreeRTOS\n");

  lcd.print("hello FreeRTOS!");

/*  xTaskCreate(task1, (const signed char*) "Task 1", 240,NULL ,1 , NULL);
  xTaskCreate(task2, (const signed char*) "Task 2", 240,NULL ,5 , NULL);
  
  vTaskStartScheduler();*/
}

/*void task1(void* pvParameters)
{
   const char *pcTaskName = "Task 1 is running\n";
   volatile unsigned long u1;
   
   for(;;)
   {
      Serial.print(pcTaskName);
      vTaskDelay(1000 / portTICK_RATE_MS);
   }
}

void task2(void* pvParameters)
{
   const char *pcTaskName = "Task 2 is running\n";
   volatile unsigned long u1;
   Beeper beeper(6);
   
   for(;;)
   {
      Serial.print(pcTaskName);
      beeper.beep(10);
      vTaskDelay(1000 / portTICK_RATE_MS);
   }
}*/

void loop()                     
{

}

