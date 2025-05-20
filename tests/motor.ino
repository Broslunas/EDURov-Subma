// Pines
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {
  // Gira en una dirección
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200); // velocidad (0 a 255)
  delay(5000); // 5 segundos

  // Gira en la dirección contraria
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
  delay(5000); // 5 segundos
}