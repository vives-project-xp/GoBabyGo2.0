const int IN1 = 14;
const int IN2 = 12;

const int ENA = 0;

void setup() {
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);

  pinMode (ENA, OUTPUT);
}

void loop() {
  analogWrite(ENA, 255);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

}
