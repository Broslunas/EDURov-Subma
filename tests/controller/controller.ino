// Pines LEDs
const int ledRojo = 2;
const int ledVerde = 3;
const int ledAzul = 4;

void setup() {
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  apagarLeds();
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read();
    apagarLeds();

    switch (comando) {
      case 'w': // adelante o subir
      case 'i':
        digitalWrite(ledVerde, HIGH);
        Serial.println("LED Verde ON");
        break;

      case 's': // atras o bajar
      case 'k':
        digitalWrite(ledRojo, HIGH);
        Serial.println("LED Rojo ON");
        break;

      case 'a': // izquierda
      case 'd': // derecha
        digitalWrite(ledAzul, HIGH);
        Serial.println("LED Azul ON");
        break;

      case 'x': // quieto
      default:
        apagarLeds();
        Serial.println("Todos LEDs OFF");
        break;
    }
  }
}

void apagarLeds() {
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAzul, LOW);
}
