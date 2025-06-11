#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// LCD
LiquidCrystal_I2C lcd(0x27,16,2); 

// Motores Controladora 1
const int IN1 = 8;
const int IN2 = 9;
const int ENA1 = 10;

const int IN3 = 5;
const int IN4 = 6;
const int ENB = 7;

// Motores Controladora 2
const int IN5 = 11;
const int IN6 = 12;
const int ENA2 = 13;

void setup() {
  // LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Esperando ordenes");

  // Serial
  Serial.begin(9600);

  // Pines de motores
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA1, OUTPUT);
  
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(ENA2, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read();
    pararTodo();

    lcd.clear();
    switch (comando) {
      case 'w': // Avanzar
        lcd.setCursor(0,0);
        lcd.print("Avanzando");
        moverAdelante();
        break;

      case 's': // Retroceder
        lcd.setCursor(0,0);
        lcd.print("Retrocediendo");
        moverAtras();
        break;

      case 'a': // Izquierda
        lcd.setCursor(0,0);
        lcd.print("Izquierda");
        girarIzquierda();
        break;

      case 'd': // Derecha
        lcd.setCursor(0,0);
        lcd.print("Derecha");
        girarDerecha();
        break;

      case 'i': // Subir
        lcd.setCursor(0,0);
        lcd.print("Subiendo");
        subir();
        break;

      case 'k': // Bajar
        lcd.setCursor(0,0);
        lcd.print("Bajando");
        bajar();
        break;

      case 'x': // Parar todo
      default:
        lcd.setCursor(0,0);
        lcd.print("Parado");
        pararTodo();
        break;
    }
  }
}

// FUNCIONES

void moverAdelante() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA1, 200);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);
}

void moverAtras() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA1, 200);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200);
}

void girarIzquierda() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA1, 200);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);
}

void girarDerecha() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA1, 200);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200);
}

void subir() {
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  analogWrite(ENA2, 200);
}

void bajar() {
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENA2, 200);
}

void pararTodo() {
  // Apagar motores controladora 1
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA1, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);

  // Apagar motores controladora 2
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  analogWrite(ENA2, 0);
}
