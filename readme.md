# 🤖 Control de Submarino Arduino

Este proyecto implementa un sistema de control para un submarino robótico utilizando Arduino. Ofrece múltiples opciones de control: joysticks analógicos, mando PS4/PS5 por USB, y control por script Python.

## 📝 Descripción General

El sistema controla tres motores para el movimiento del submarino:

- **Motores A y B**: Controlan el movimiento horizontal (adelante/atrás/izquierda/derecha)
- **Motor C**: Controla el movimiento vertical (subir/bajar)

### 🎮 Opciones de Control

1. **Control por Joysticks** (`/codigo/joysticks/`)

   - Dos joysticks analógicos
   - Joystick 1: Control de movimiento horizontal
   - Joystick 2: Control de movimiento vertical

2. **Control por Mando PS4/PS5** (`/codigo/ps-controller/`)

   - Conexión por USB Host Shield
   - Script Python para comunicación serial
   - Stick izquierdo: Movimiento horizontal
   - Stick derecho: Movimiento vertical
   - Hace falta uso del script `script.py` para enviar comandos desde el mando

## 🛠️ Componentes Necesarios

### Hardware Básico

- Arduino UNO o compatible
- 3 Motores DC
- 2 Controladoras L298N/L9110
- Pantalla LCD I2C 16x2
- Protoboard y jumpers

### Hardware Adicional (según método de control)

- **Opción Joysticks**: 2 Joysticks analógicos
- **Opción PS4/PS5**: USB Host Shield + Cable USB

## ⚡ Conexiones

### Motores

- **Controladora 1** (Motores A y B):
  - Motor A: IN1→D8, IN2→D9, ENA→D10
  - Motor B: IN3→D5, IN4→D6, ENB→D7
- **Controladora 2** (Motor C):
  - IN5→D11, IN6→D12, ENA2→D13

### Pantalla LCD I2C

- SDA → A4
- SCL → A5

### Joysticks (si se usa esta opción)

- **Joystick 1**: X→A0, Y→A1
- **Joystick 2**: X→A2

## 💻 Software Necesario

### Arduino

- Arduino IDE
- Bibliotecas:
  - `LiquidCrystal_I2C`
  - `USB Host Shield Library 2.0` (para control PS4/PS5)

### Python (para control por script)

- Python 3.x
- Bibliotecas:
  - `pyserial`
  - `pygame` (para control con mando)

## 📂 Estructura del Proyecto

```
├── codigo/
│   ├── joysticks/          # Control por joysticks
│   │   └── joysticks.ino
│   └── ps-controller/      # Control por mando PS4/PS5
│       ├── ps-controller.ino
│       └── script.py
├── tests/                  # Pruebas individuales
│   ├── controller/         # Control manual
│   │   ├── controller.ino
│   │   └── script.py
│   ├── joysticks/         # Test de joysticks
│   ├── lcd/              # Test de LCD
│   ├── motor/            # Test de motores
│   └── usb-hostshield/   # Test de USB Shield
```

## 🚀 Instalación y Uso

1. **Preparación del Hardware**

   - Realizar todas las conexiones según el diagrama elegido
   - Para PS4/PS5: Conectar el USB Host Shield a Arduino

2. **Instalación del Software**

   - Instalar Arduino IDE
   - Instalar las bibliotecas necesarias
   - Para control por script: Instalar Python y dependencias

3. **Configuración**

   - Elegir el método de control deseado
   - Cargar el sketch correspondiente en Arduino
   - Para PS4/PS5 o script: Ejecutar el script Python

4. **Calibración**
   - Ajustar la zona muerta de los controles si es necesario
   - Verificar la dirección I2C del LCD (por defecto 0x27)
   - Comprobar la orientación de los motores

## 🛟 Resolución de Problemas

- **LCD no funciona**: Verificar dirección I2C y conexiones
- **Motores no responden**: Comprobar polaridad y conexiones
- **Mando PS4/PS5 no detectado**: Verificar USB Host Shield
- **Error de comunicación serial**: Comprobar puerto COM y velocidad

## 📝 Notas de Desarrollo

- Zona muerta implementada para evitar ruido en los controles
- Velocidad de motores configurable (0-255)
- Sistema modular para fácil adaptación
- Retroalimentación visual mediante LCD

## 📄 Licencia

Este proyecto está bajo la Licencia MIT. Consulta el archivo LICENSE para más detalles.

## ⭐ Créditos

Desarrollado como proyecto educativo del IES Las Veredillas.
- [@Broslunas](https://github.com/Broslunas)
- [@elamogussus](https://github.com/elamogussus)
---
