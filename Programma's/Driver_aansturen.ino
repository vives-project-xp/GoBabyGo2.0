const int IN1 = 14;
const int IN2 = 12;
const int IN3 = 13;
const int IN4 = 4;

const int ENA = 0;
const int ENB = 5;

void setup() {
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
}

void loop() {

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
