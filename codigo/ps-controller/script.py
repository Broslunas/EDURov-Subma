import pygame
import serial
import time

# arduino = serial.Serial('COM4', 9600)
time.sleep(2)

pygame.init()
pygame.joystick.init()

joystick = pygame.joystick.Joystick(0)
joystick.init()

print("✅ Mando conectado:", joystick.get_name())

def enviar_comando(c):
    # arduino.write(c.encode())
    if c != 'x':
        print(f"📤 Enviado: '{c}'")

while True:
    pygame.event.pump()

    deadzone = 0.2
    comando = 'x'  # quieto por defecto

    # Leer botones círculo y equis
    boton_circulo = joystick.get_button(1)  # botón círculo suele ser el 1
    boton_cuadrado = joystick.get_button(0)  # botón equis suele ser el 0
    pad_up = joystick.get_button(11)
    pad_down = joystick.get_button(12)
    pad_left = joystick.get_button(13)
    pad_right = joystick.get_button(14)

    if pad_up:
        comando = 'w'  # alante
    if pad_down:
        comando = 's'  # atrás
    if pad_left:
        comando = 'a'  # izquierda
    if pad_right:
        comando = 'd'  # derecha
    if boton_circulo:
        comando = 'i'  # subir con círculo
    if boton_cuadrado:
        comando = 'k'  # bajar con cuadrado

    enviar_comando(comando)
    time.sleep(0.1)
