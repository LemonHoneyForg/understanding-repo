#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
int potVal = 2;

void setup()
{
  
  lcd.init(); // initialize the lcd
  lcd.backlight();
  Serial.begin(9600);
  
  pinMode(potVal, INPUT);
}

void loop()
{
 
   int stressState = digitalRead(potVal);

  
  lcd.setCursor(0, 0);         
  lcd.print("social battery");        
  lcd.setCursor(0, 8);         
  lcd.print(stressState+"%"); 
  lcd.setCursor(13, 1);         
  delay(6000); 
  
  
  lcd.clear();                 
  lcd.setCursor(0, 0);         
  lcd.print("Luna Call");        
  lcd.setCursor(0, 1);         
  lcd.print("(She/Her)"); 
  lcd.setCursor(13, 1);         
  delay(6000);                 

  lcd.clear();                  
  lcd.setCursor(0, 0);         
  lcd.print("Luna Call");        
  lcd.setCursor(0, 1);          
  lcd.print("(They/Them)");
  lcd.setCursor(13, 1);         
  delay(6000);  
  
  
}
