#include <LiquidCrystal.h>



LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte flecha[8] = { B00000,
                   B00100,
                   B00010,
                   B11111,
                   B00010,
                   B00100,
                   B00000,
                   B00000 };
                   
byte vacio[8] = { B00000,
                    B00000,
                    B00000,
                    B00000,
                    B00000,
                    B00000,
                    B00000,
                    B00000 };

byte lleno[8] = { B00000,
                  B00100,
                  B01110,
                  B01110,
                  B01110,
                  B00100,
                  B00000,
                  B00000 };
                  
byte grados[8] = { B00110,
                   B01001,
                   B01001,
                   B00110,
                   B00000,
                   B00000,
                   B00000,
                   B00000 };


void setup() {
  
  lcd.begin(20,4);
  lcd.createChar(0,flecha);
  lcd.createChar(1,vacio);
  lcd.createChar(2,lleno);
  lcd.createChar(3,grados);
}
  
void loop() {
  
 lcd.setCursor(0,0);
 lcd.write(byte(0));
 lcd.print("Z1 ------");
 lcd.setCursor(1,1);
 lcd.print("Z2 ------");
 lcd.setCursor(1,2);
 lcd.print("Z3 ------");
 lcd.setCursor(1,3);
 lcd.print("Z4 ------");
 lcd.setCursor(11,0);
 lcd.print("Z5 ------");
 lcd.setCursor(11,1);
 lcd.print("Z6 ------");
 lcd.setCursor(11,2);
 lcd.print("Z7 ------");
 lcd.setCursor(11,3);
 lcd.print("Z8 ------");
}
