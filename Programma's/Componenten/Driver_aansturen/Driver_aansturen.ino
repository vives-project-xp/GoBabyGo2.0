const int IN1 = 23;
const int IN2 = 22;

const int ENA = 4;
// Kies een PWM-kanaal (0-15) dat beschikbaar is voor je board
const int channel = 13;

void setup() {
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);

  ledcSetup(channel, 5000, 8);// Kanaal, frequentie (Hz), resolutie (bits)
  ledcAttachPin(ENA, channel);
}

void loop() {
  ledcWrite(channel, 255);// Stel de PWM-waarde in (0-255) om de motorsnelheid te regelen
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

}
