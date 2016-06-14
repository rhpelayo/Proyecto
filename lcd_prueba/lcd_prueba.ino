#include <LiquidCrystal.h>

int coords[2] = {0, 3};
int pinBoton = 6;
int sensorPin = 7;
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
  pantalla();
  lcd.createChar(0,flecha);
  lcd.createChar(1,vacio);
  lcd.createChar(2,lleno);
  lcd.createChar(3,grados);

}

void loop() {
  screenSelect();
}


void screenSelect() {
  
 for (int x = 0; x <= 10; x += 10) {
  
  for (int y = 0; y < 4; y++) {
  
    lcd.setCursor(x,y);
    lcd.write(byte(0));
    delay(1000);
    lcd.setCursor(x,y);
    lcd.print(" ");

  }
 }
}

void pantalla() {
  lcd.setCursor(1,0);
  lcd.print("Z1 ###");
  lcd.write(byte(3));
  lcd.print("C");
  lcd.write(byte(2));
  lcd.setCursor(1,1);
  lcd.print("Z2 ###");
  lcd.write(byte(3));
  lcd.print("C");
  lcd.write(byte(2));
  lcd.setCursor(1,2);
  lcd.print("Z3 ###");
  lcd.write(byte(3));
  lcd.print("C");
  lcd.write(byte(2));
  lcd.setCursor(1,3);
  lcd.print("Z4 ###");
  lcd.write(byte(3));
  lcd.print("C");
  lcd.write(byte(2));
  lcd.setCursor(11,0);
  lcd.print("Z5 ###");
  lcd.write(byte(3));
  lcd.print("C");
  lcd.write(byte(2));
  lcd.setCursor(11,1);
  lcd.print("Z6 ###");
  lcd.write(byte(3));
  lcd.print("C");
  lcd.write(byte(2));
  lcd.setCursor(11,2);
  lcd.print("Z7 ###");
  lcd.write(byte(3));
  lcd.print("C");
  lcd.write(byte(2));
  lcd.setCursor(11,3);
  lcd.print("Z8 ###");
  lcd.write(byte(3));
  lcd.print("C");
  lcd.write(byte(2));
}

