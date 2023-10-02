//driver
const int IN1 = 23;
const int IN2 = 22;
const int ENA = 4;
// Kies een PWM-kanaal (0-15) dat beschikbaar is voor je board
const int channel = 13;

//joystick
int leftpin = 5;
int rightpin = 18;
int uppin = 19;
int downpin = 21;

int leftvalue = 0;
int rightvalue = 0;
int upvalue = 0;
int downvalue = 0;

void setup() {
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  
  ledcSetup(channel, 5000, 8);// Kanaal, frequentie (Hz), resolutie (bits)
  ledcAttachPin(ENA, channel);

  pinMode(leftpin,INPUT_PULLUP);
  pinMode(rightpin,INPUT_PULLUP);
  pinMode(uppin,INPUT_PULLUP);
  pinMode(downpin,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  leftvalue= digitalRead(leftpin);
  rightvalue= digitalRead(rightpin);
  upvalue= digitalRead(uppin);
  downvalue= digitalRead(downpin);

  if(rightvalue == 0){
    ledcWrite(channel, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    Serial.println("Auto gaat naar rechts");
  }
  else if(leftvalue== 0){
    ledcWrite(channel, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    Serial.println("Auto gaat naar links");
  }
  else{
    ledcWrite(channel, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }

}
