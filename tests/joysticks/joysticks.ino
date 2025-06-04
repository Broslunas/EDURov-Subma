// Pines conectados al joystick
const int pinX = A0;   // Eje X al pin analógico A0
const int pinY = A1;   // Eje Y al pin analógico A1
const int pinSW = 2;   // Botón (SW) al pin digital 2

void setup() {
  Serial.begin(9600);               // Inicializa la comunicación serial
  pinMode(pinSW, INPUT_PULLUP);     // Habilita la resistencia pull-up interna
}
void loop() {
  int x = analogRead(pinX);         // Lee el valor del eje X (0 a 1023)
  int y = analogRead(pinY);         // Lee el valor del eje Y (0 a 1023)
  bool swPressed = digitalRead(pinSW) == LOW; // Botón presionado si es LOW

  // Imprime los valores en el monitor serial
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" | Y: ");
  Serial.print(y);
  Serial.print(" | Botón: ");
  Serial.println(swPressed ? "PULSADO" : "NO pulsado");

  delay(200); // Pequeña pausa para facilitar la lectura
}