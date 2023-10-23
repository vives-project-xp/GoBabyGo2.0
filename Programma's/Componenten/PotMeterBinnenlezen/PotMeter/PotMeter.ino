const int potPin = 14;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(potPin);

  Serial.print("Pot waarde: ");
  Serial.println(sensorValue);

  delay(100);
}
