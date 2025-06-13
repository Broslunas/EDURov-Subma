from flask import Flask, render_template
from flask_socketio import SocketIO
import pygame
import time
import threading
import serial

arduino = serial.Serial('COM3', 9600)

app = Flask(__name__)
socketio = SocketIO(app, cors_allowed_origins="*")

# pygame setup
pygame.init()
pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

def enviar_comando(c):
    if c != 'x':
        print(f"📤 Enviado: '{c}'")
    socketio.emit('comando', {'comando': c})
    arduino.write(c.encode())

def leer_mando():
    while True:
        pygame.event.pump()
        comando = 'x'

        if joystick.get_button(11):
            comando = 'w'
        elif joystick.get_button(12):
            comando = 's'
        elif joystick.get_button(13):
            comando = 'a'
        elif joystick.get_button(14):
            comando = 'd'
        elif joystick.get_button(1):
            comando = 'i'
        elif joystick.get_button(0):
            comando = 'k'

        enviar_comando(comando)
        time.sleep(0.1)

@app.route('/')
def index():
    return render_template('index.html')

if __name__ == '__main__':
    thread = threading.Thread(target=leer_mando)
    thread.daemon = True
    thread.start()
    socketio.run(app, host='0.0.0.0', port=5000)
