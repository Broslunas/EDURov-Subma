# Control de Motores con Joystick y LCD en Arduino

Este proyecto de Arduino permite controlar tres motores de manera independiente utilizando dos joysticks analógicos. Además, una pantalla LCD I2C proporciona retroalimentación visual del movimiento en tiempo real.

## 🧠 Descripción

- **Joystick 1** controla el desplazamiento en los ejes X y Z, moviendo dos motores (Motor A y Motor B) hacia adelante, atrás, izquierda o derecha.
- **Joystick 2** controla el eje Y con un motor adicional (Motor C), simulando un movimiento vertical (arriba/abajo).
- Una **pantalla LCD I2C 16x2** muestra el estado actual del movimiento de los motores.

## 🛠️ Componentes Utilizados

- Arduino UNO (o compatible)
- 2 Joysticks analógicos
- 3 Motores DC
- 2 Controladoras L298N o L9110 (según configuración)
- Pantalla LCD I2C 16x2 (dirección: `0x27`)
- Jumpers y protoboard

## ⚙️ Conexiones

### Joysticks
- Joystick 1: `X → A0`, `Y → A1`
- Joystick 2: `X → A2`, `Y → A3`

### Motores (con controladoras)
- Controladora 1 (Motor A y B):
  - IN1 → D8, IN2 → D9, ENA → D10 (Motor A)
  - IN3 → D5, IN4 → D6, ENB → D7 (Motor B)
- Controladora 2 (Motor C):
  - IN5 → D11, IN6 → D12, ENA2 → D13

### Pantalla LCD
- SDA → A4  
- SCL → A5  

## 🧾 Funcionamiento

- Cuando el usuario mueve el joystick 1:
  - **X+** → Atrás
  - **X-** → Adelante
  - **Y+** → Izquierda
  - **Y-** → Derecha
  - Zona muerta para evitar ruido entre valores 500–520

- Cuando el usuario mueve el joystick 2:
  - **X+** → Subir (Arriba)
  - **X-** → Bajar (Abajo)
  - Zona muerta entre 500–520

- La pantalla LCD indica el estado actual del sistema (movimiento o inactividad).

## 🚀 Requisitos

- Arduino IDE
- Librería `LiquidCrystal_I2C` instalada (`Sketch > Include Library > Manage Libraries...`)

## 📦 Instalación

1. Clona este repositorio o copia el código en el IDE de Arduino.
2. Conecta los componentes según el esquema.
3. Sube el código a tu placa Arduino.
4. ¡Listo! El sistema está listo para recibir tus comandos desde los joysticks.

## 📝 Notas

- Asegúrate de calibrar los valores de zona muerta si los joysticks son muy sensibles.
- Puedes modificar la dirección del LCD (`0x27`) si usas otro modelo.

## 📄 Licencia

Este proyecto se distribuye bajo la licencia MIT. Puedes usarlo, modificarlo y compartirlo libremente.

---
