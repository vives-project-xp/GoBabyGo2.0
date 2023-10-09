//driver
const int IN1 = 23;
const int IN2 = 22;
const int ENA = 4;
// Kies een PWM-kanaal (0-15) dat beschikbaar is voor je board
const int channel = 13;

//Input pinnen joystick
int rightpin = 18;
int leftpin = 5;
int uppin = 19;
int downpin = 21;

//output pinnen motor V/A
int forward = 15;
int backwards = 2;

//Status joystick
int leftvalue = 0;
int rightvalue = 0;
int upvalue = 0;
int downvalue = 0;

void setup() {
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  ledcSetup(channel, 5000, 8);// Kanaal, frequentie (Hz), resolutie (bits)
  ledcAttachPin(ENA, channel);

  pinMode(forward,OUTPUT);
  pinMode(backwards,OUTPUT);
  
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

  //Vooruit
  if(upvalue == 0){
    Serial.println("Voorruit");
    digitalWrite(forward,HIGH);
    digitalWrite(backwards,LOW);
    //Schuinvooruit
    if(leftvalue==0){
      digitalWrite(forward,HIGH);
      digitalWrite(backwards,LOW);
      
      ledcWrite(channel, 255);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      Serial.println("Shuinlinks Vooruit");
    }
    if(rightvalue==0){
      digitalWrite(forward,HIGH);
      digitalWrite(backwards,LOW);
      
      ledcWrite(channel, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      Serial.println("schuinrechts Vooruit");
    }
  }
  
  //Achteruit
  else if(downvalue== 0){
    Serial.println("Acheruit");
    digitalWrite(forward,LOW);
    digitalWrite(backwards,HIGH);
    //Schuinachteruit
    if(leftvalue==0){
      digitalWrite(forward,LOW);
      digitalWrite(backwards,HIGH);
      
      ledcWrite(channel, 255);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      Serial.println("Shuinlinks achteruit");
    }
    if(rightvalue==0){
      digitalWrite(forward,LOW);
      digitalWrite(backwards,HIGH);
      
      ledcWrite(channel, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      Serial.println("schuinrechts achteruit");
    }
  }
  
  else{
    Serial.println("Auto staat stil");
    digitalWrite(forward,LOW);
    digitalWrite(backwards,LOW);
  }
}
