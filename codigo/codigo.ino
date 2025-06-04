#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// JOYSTICK 1
const int pinX1 = A0;
const int pinY1 = A1;

// JOYSTICK 2
const int pinX2 = A2;
const int pinY2 = A3;

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

// LCD
LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Esperando Indicaciones");
  Serial.begin(9600);

  // Motores
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
  int x1 = analogRead(pinX1);
  int y1 = analogRead(pinY1);
  int x2 = analogRead(pinX2);

  int deadZone = 30; // zona muerta +/- alrededor de 512

  // --- Movimiento Adelante / Atrás (JOYSTICK 1) ---
  if (abs(x1 - 512) > deadZone) {
    int velocidad = map(abs(x1 - 512), 0, 512, 0, 255);
    
    if (x1 < 512) { // Adelante
      lcd.clear(); lcd.setCursor(0,0); lcd.print("Alante");
      digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); analogWrite(ENA1, velocidad);
      digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); analogWrite(ENB, velocidad);
    } else { // Atrás
      lcd.clear(); lcd.setCursor(0,0); lcd.print("Atras");
      digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); analogWrite(ENA1, velocidad);
      digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); analogWrite(ENB, velocidad);
    }
  } 
  // --- Giro Izquierda / Derecha (JOYSTICK 1) ---
  else if (abs(y1 - 512) > deadZone) {
    int velocidad = map(abs(y1 - 512), 0, 512, 0, 255);

    if (y1 > 512) { // Izquierda
      lcd.clear(); lcd.setCursor(0,0); lcd.print("Izquierda");
      digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); analogWrite(ENA1, velocidad);
      digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); analogWrite(ENB, velocidad);
    } else { // Derecha
      lcd.clear(); lcd.setCursor(0,0); lcd.print("Derecha");
      digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); analogWrite(ENA1, velocidad);
      digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); analogWrite(ENB, velocidad);
    }
  } 
  else {
    lcd.clear(); lcd.setCursor(0,0); lcd.print("Toy quieto");
    digitalWrite(IN1, LOW); digitalWrite(IN2, LOW); analogWrite(ENA1, 0);
    digitalWrite(IN3, LOW); digitalWrite(IN4, LOW); analogWrite(ENB, 0);
  }

  // --- Movimiento vertical (JOYSTICK 2) ---
  if (abs(x2 - 512) > deadZone) {
    int velocidad = map(abs(x2 - 512), 0, 512, 0, 255);
    
    if (x2 > 512) { // Arriba
      lcd.setCursor(0,1); lcd.print("Arriba");
      digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW); analogWrite(ENA2, velocidad);
    } else { // Abajo
      lcd.setCursor(0,1); lcd.print("Abajo");
      digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH); analogWrite(ENA2, velocidad);
    }
  } else {
    lcd.setCursor(0,1); lcd.print("Quieto");
    digitalWrite(IN5, LOW); digitalWrite(IN6, LOW); analogWrite(ENA2, 0);
  }

  delay(100); // Para evitar parpadeo excesivo
}
