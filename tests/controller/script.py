import pygame
import serial
import time

arduino = serial.Serial('COM4', 9600)
time.sleep(2)

pygame.init()
pygame.joystick.init()

joystick = pygame.joystick.Joystick(0)
joystick.init()

print("✅ Mando conectado:", joystick.get_name())

def enviar_comando(c, x, y):
    arduino.write(c.encode())
    if c != 'x':
        print(f"📤 Enviado: '{c}' | Coords: X={x:.2f} Y={y:.2f}")

while True:
    pygame.event.pump()

    eje_x = joystick.get_axis(0)
    eje_y = joystick.get_axis(1)

    deadzone = 0.2
    comando = 'x'  # quieto por defecto

    # Leer botones círculo y equis
    boton_circulo = joystick.get_button(1)  # botón círculo suele ser el 1
    boton_cuadrado = joystick.get_button(0)  # botón equis suele ser el 0

    if eje_y < -deadzone:
        comando = 'w'  # alante
    elif eje_y > deadzone:
        comando = 's'  # atrás
    elif eje_x < -deadzone:
        comando = 'a'  # izquierda
    elif eje_x > deadzone:
        comando = 'd'  # derecha
    elif boton_circulo:
        comando = 'i'  # subir con círculo
    elif boton_cuadrado:
        comando = 'k'  # bajar con cuadrado

    enviar_comando(comando, eje_x, eje_y)
    time.sleep(0.1)
