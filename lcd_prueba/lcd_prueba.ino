#include <Key.h>                                                                 //Librerías que se utilizan
#include <Keypad.h>
#include <LiquidCrystal.h>

int x = 0;                                                                       //Define las variables de posición
int y = -1;
int zona = -1;
int menuState[8] = {0,0,0,0,0,0,0,0};   
LiquidCrystal lcd(10, 9, A5, A4, A3, A2);                                        //Define en que pines está conectado el lcd
const byte ROWS = 4;                                                             //filas y columnas del keypad
const byte COLS = 4;
char keys[ROWS][COLS] = {                                                        //Teclas del keypad
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};
byte rowPins[ROWS] = { 7, 6, 5, 4 };                                             //pines donde está conectado el keypad
byte colPins[COLS] = { 3, 2, 1, 0 }; 
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );           //"crea" el keypad
byte flecha[8] = { B00000,                                                       // Define los caracteres personalizados
                   B00100,
                   B00010,
                   B11111,
                   B00010,
                   B00100,
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
  lcd.createChar(0,flecha);   //crea los caracteres
  lcd.createChar(2,lleno);
  lcd.createChar(3,grados);
}

void loop() {

  char key = kpd.getKey();
  if(key)  {
    switch (key) {
      case 'A':
      screenSelectUP(x, y);
      break;
      case 'B':
      screenSelectDOWN(x, y);
      break;
      case 'C':
      Menu(menuState[zona]);
      break;
      default:
      break;
   }
 }
}


void screenSelectDOWN(int ex, int ey) {
 
  lcd.setCursor(ex,ey);
  lcd.print(" ");
    for (int i = x; x <= 10; i += 10) {
      for (int j = y; y < 3; j++) {
        y++;
        zona++;
        lcd.setCursor(x,y);
        lcd.print(menuState[zona]);
        return;
     }
    y = -1;
    x += 10;
   }
  y = -1;
  x = 0;
  zona = -1;
}

void screenSelectUP(int ex, int ey) {
 
  lcd.setCursor(ex,ey);
  lcd.print(" ");
    for (int i = x; x >= 0; i -= 10) {
      for (int j = y; y > 0; j--) {
        y--;
        zona--;
        lcd.setCursor(x,y);
        lcd.print(menuState[zona]);
        return;
     }
    y = 4;
    x -= 10;
   }
  y = 4;
  x = 10;
  zona = 8;
}


void Menu(int currentMenu) {

  
  switch(currentMenu){
    case 0:
    menuState[zona]++;
    lcd.setCursor(x+1,y);
    lcd.print("R");
    lcd.print(zona+1);
    lcd.print("-## +##");
    break;
    case 1:
    menuState[zona]++;
    lcd.setCursor(x+1,y);
    lcd.print("S");
    lcd.print(zona+1);
    lcd.print( " ###");
    lcd.write(byte(3));
    lcd.print("C");
    lcd.write(byte(2));
    break;
    case 2:
    menuState[zona] = 0;
    lcd.setCursor(x+1,y);
    lcd.print("Z");
    lcd.print(zona+1);
    lcd.print( " ###");
    lcd.write(byte(3));
    lcd.print("C");
    lcd.write(byte(2));
    break;
  }
  
}

void pantalla() {      //Crea el formato de la pantalla
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

