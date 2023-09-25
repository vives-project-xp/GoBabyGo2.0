//Input pinnen joystick
int leftpin = 14;
int rightpin = 12;
int uppin = 13;
int downpin = 4;

//output pinnen motor V/A
int forward = 0;
int backwards = 2;

//Status joystick
int leftvalue = 0;
int rightvalue = 0;
int upvalue = 0;
int downvalue = 0;

void setup() {
  pinMode(leftpin,INPUT_PULLUP);
  pinMode(rightpin,INPUT_PULLUP);
  pinMode(uppin,INPUT_PULLUP);
  pinMode(downpin,INPUT_PULLUP);
  pinMode(forward,OUTPUT);
  pinMode(backwards,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  leftvalue= digitalRead(leftpin);
  rightvalue= digitalRead(rightpin);
  upvalue= digitalRead(uppin);
  downvalue= digitalRead(downpin);

  if(upvalue == 0){
    Serial.println("Auto gaat voorruit");
    digitalWrite(forward,HIGH);
    digitalWrite(backwards,LOW);
  }
  else if(downvalue== 0){
    Serial.println("Auto gaat acheruit");
    digitalWrite(forward,LOW);
    digitalWrite(backwards,HIGH);
  }
  else{
    Serial.println("Auto staat stil");
    digitalWrite(forward,LOW);
    digitalWrite(backwards,LOW);
  }

}
