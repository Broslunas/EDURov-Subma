#include <PS5USB.h>
#include <usbhub.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// USB Host Shield
USB Usb;
PS4USB PS4(&Usb); // ← Conexión por cable USB

// Pines motores
const int IN1 = 8;
const int IN2 = 9;
const int ENA1 = 10;

const int IN3 = 5;
const int IN4 = 6;
const int ENB = 7;

const int IN5 = 11;
const int IN6 = 12;
const int ENA2 = 13;

// LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Sensibilidad
const int DEADZONE = 15;

void setup() {
  Serial.begin(115200);
  if (Usb.Init() == -1) {
    Serial.println("Error iniciando USB Host Shield");
    while (1); // Pausa si no detecta el shield
  }

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Esperando mando...");

  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT); pinMode(ENA1, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT); pinMode(ENB, OUTPUT);
  pinMode(IN5, OUTPUT); pinMode(IN6, OUTPUT); pinMode(ENA2, OUTPUT);
}

void loop() {
  Usb.Task();

  if (PS5.connected()) {
    int lx = PS5.getAnalogHat(LeftHatX);
    int ly = PS5.getAnalogHat(LeftHatY);
    int ry = PS5.getAnalogHat(RightHatY);

    lcd.clear();

    if (ly < 128 - DEADZONE) {
      lcd.setCursor(0, 0); lcd.print("Alante");
      avanzarMotores();
    } else if (ly > 128 + DEADZONE) {
      lcd.setCursor(0, 0); lcd.print("Atras");
      retrocederMotores();
    } else if (lx < 128 - DEADZONE) {
      lcd.setCursor(0, 0); lcd.print("Izquierda");
      girarIzquierda();
    } else if (lx > 128 + DEADZONE) {
      lcd.setCursor(0, 0); lcd.print("Derecha");
      girarDerecha();
    } else {
      lcd.setCursor(0, 0); lcd.print("Quieto");
      pararMotores();
    }

    lcd.setCursor(0, 1);
    if (ry < 128 - DEADZONE) {
      lcd.print("Sube");
      subirMotor();
    } else if (ry > 128 + DEADZONE) {
      lcd.print("Baja");
      bajarMotor();
    } else {
      lcd.print("Parado");
      pararMotor();
    }
  }
}

// Funciones motores
void avanzarMotores() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  analogWrite(ENA1, 200); analogWrite(ENB, 200);
}

void retrocederMotores() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(ENA1, 200); analogWrite(ENB, 200);
}

void girarIzquierda() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
  analogWrite(ENA1, 200);  analogWrite(ENB, 200);
}

void girarDerecha() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(ENA1, 200);  analogWrite(ENB, 200);
}

void pararMotores() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  analogWrite(ENA1, 0);   analogWrite(ENB, 0);
}

void subirMotor() {
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  analogWrite(ENA2, 200);
}

void bajarMotor() {
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  analogWrite(ENA2, 200);
}

void pararMotor() {
  digitalWrite(IN5, LOW); digitalWrite(IN6, LOW);
  analogWrite(ENA2, 0);
}
