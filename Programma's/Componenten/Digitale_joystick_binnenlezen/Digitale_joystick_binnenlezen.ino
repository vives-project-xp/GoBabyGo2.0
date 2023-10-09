int leftpin = 18;
int rightpin = 5;
int uppin = 19;
int downpin = 21;

int leftvalue = 0;
int rightvalue = 0;
int upvalue = 0;
int downvalue = 0;

void setup() {
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
  
  Serial.print(leftvalue);
  Serial.print(" left ");
  Serial.print(rightvalue);
  Serial.print(" right ");
  Serial.print(upvalue);
  Serial.print(" up ");
  Serial.print(downvalue);
  Serial.print(" down ");
  Serial.println();
  delay(500);
}
