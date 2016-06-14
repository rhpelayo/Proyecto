int pins[5] = {2, 3, 4, 5, 6};
int pinBoton = 8;
int posicion = 0;
boolean pressed = false;
int nivel = 1;

void setup()
{
 pinMode(pins[0], OUTPUT);
 pinMode(pins[1], OUTPUT);
 pinMode(pins[2], OUTPUT);
 pinMode(pins[3], OUTPUT);
 pinMode(pins[4], OUTPUT);
 pinMode(pinBoton, INPUT);
 Serial.begin(9600);
}

void loop()
{
  if(digitalRead(pinBoton) == HIGH)
  {
  pressed = true;
  digitalWrite(pins[posicion], HIGH);
  delay(1000/nivel);
  
  posicion++;
    if(posicion == 5)
    {
      posicion = 0;
      digitalWrite(pins[0], LOW);
      digitalWrite(pins[1], LOW);
      digitalWrite(pins[2], LOW);
      digitalWrite(pins[3], LOW);
      digitalWrite(pins[4], LOW);
    }
  }
  else
  {
    digitalWrite(pins[posicion], HIGH);
    if(pressed)
    {
      pressed = false;
     if(posicion == 4)
    {
    nivel++;
    Serial.println(nivel);
    } 
    }
  }
}
