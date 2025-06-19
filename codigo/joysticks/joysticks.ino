#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// JOYSTICK 1
const int pinX1 = A0;
const int pinY1 = A1;

// JOYSTICK 2
const int pinX2 = A2;


// CONTROLADORA 1 > MOTOR A
const int IN1 = 8;
const int IN2 = 9;
const int ENA1 = 10;

// MOTOR B
const int IN3 = 5;
const int IN4 = 6;
const int ENB = 7;


// CONTROLADORA 2 > MOTOR A
const int IN5 = 11;
const int IN6 = 12;
const int ENA2 = 13;


// AÑADIR TAMBIEN LOS PINES DE LA LCD
// A LA PLACA ARDUINO
// SCL: A5
// SDA: A4
LiquidCrystal_I2C lcd(0x27,16,2); 

const int JOYSTICK_CENTRO = 512;
const int RADIO_DEADZONE = 15;

void setup(){
  //LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Esperando Indicaciones");
  lcd.setCursor(0,1);
  lcd.print("卐 Viva Hitler 卐");

  // JOYSTICK 1
  Serial.begin(9600);

  // PINES CONTROLADORA 1 > MOTOR A
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA1, OUTPUT);

  // PINES CONTROLADORA 1 > MOTOR B
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // PINES CONTROLADORA 2 > MOTOR A
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(ENA2, OUTPUT);
}

void loop() {
  // JOYSTICK DESPLAZAMIENTO EJE "XZ"
  int x1 = analogRead(pinX1);         // Lee el valor del eje X (0 a 1023)
  int y1 = analogRead(pinY1);         // Lee el valor del eje Y (0 a 1023)

  // JOYSTICK DESPLAZAMIENTO EJE "Y"
  int x2 = analogRead(pinX2);


  lcd.clear();
  lcd.setCursor(0,0);

  if (x1 > JOYSTICK_CENTRO + RADIO_DEADZONE)  
  {
    lcd.print("Atras");
    
    // MOTOR A
    digitalWrite(IN1, HIGH); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    digitalWrite(IN2, LOW);// MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    analogWrite(ENA1, 200);

    // MOTOR B
    digitalWrite(IN3, LOW); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    digitalWrite(IN4, HIGH); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    analogWrite(ENB, 200);
  }
  else if (x1 < JOYSTICK_CENTRO - RADIO_DEADZONE)
  {
    lcd.print("Alante");

    // MOTOR A
    digitalWrite(IN1, LOW); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    digitalWrite(IN2, HIGH);  // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    analogWrite(ENA1, 200);

    // MOTOR B
    digitalWrite(IN3, HIGH); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    digitalWrite(IN4, LOW); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    analogWrite(ENB, 200);
  }
  else if (y1 > JOYSTICK_CENTRO + RADIO_DEADZONE)
  {
    lcd.print("Izquierda");

    // MOTOR A
    digitalWrite(IN1, HIGH); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    digitalWrite(IN2, LOW); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    analogWrite(ENA1, 200);

    // MOTOR B
    digitalWrite(IN3, HIGH); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    digitalWrite(IN4, LOW); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    analogWrite(ENB, 200);
  }
  else if (y1 < JOYSTICK_CENTRO - RADIO_DEADZONE)
   {
    lcd.print("Derecha");

    // MOTOR A
    digitalWrite(IN1, LOW); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    digitalWrite(IN2, HIGH); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    analogWrite(ENA1, 200);

    // MOTOR B
    digitalWrite(IN3, LOW); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    digitalWrite(IN4, HIGH); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    analogWrite(ENB, 200);
  }
  else
  { // ESTABLECE LA ZONA MUERTA DEL JOYSTICK
    lcd.print("Toy quieto");

    // MOTOR A
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA1, 0);

    // MOTOR B
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0);
  }

  // DESPLAZAMIENTO EJE Y
  lcd.setCursor(0,1);
  if (x2 > JOYSTICK_CENTRO + RADIO_DEADZONE) 
  {
    lcd.print("Arriba");

    // MOTOR A
    digitalWrite(IN5, HIGH); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    digitalWrite(IN6, LOW);  // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    analogWrite(ENA2, 200);
  }
  else if (x2 < JOYSTICK_CENTRO - RADIO_DEADZONE)
  {
    lcd.print("Abajo");

    // MOTOR A
    digitalWrite(IN5, LOW); // MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    digitalWrite(IN6, HIGH);// MODIFICAR SEGUN ORIENTACIÓN DE LAS ASPAS
    analogWrite(ENA2, 200);
  }
  else
  { // ESTABLECE LA ZONA MUERTA DEL JOYSTICK
    lcd.print("Toy quieto");

    // MOTOR A
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, LOW);
    analogWrite(ENA2, 0);
  }
}