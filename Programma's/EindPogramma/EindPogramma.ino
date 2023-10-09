//PotWaarde
const int potPin = 14;

//Input pinnen joystick
int leftpin = 18;
int rightpin = 5;
int uppin = 19;
int downpin = 21;

//Status joystick
int leftvalue = 0;
int rightvalue = 0;
int upvalue = 0;
int downvalue = 0;

//driver
const int IN1 = 23;
const int IN2 = 22;
const int ENA = 4;
// Kies een PWM-kanaal (0-15) dat beschikbaar is voor je board
const int channel = 13;

//output pinnen motor V/A
int forward = 15;
int backwards = 2;

void setup() {
  //joystick
  pinMode(leftpin,INPUT_PULLUP);
  pinMode(rightpin,INPUT_PULLUP);
  pinMode(uppin,INPUT_PULLUP);
  pinMode(downpin,INPUT_PULLUP);
  Serial.begin(9600);
  
  //driver
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  ledcSetup(channel, 5000, 8);// Kanaal, frequentie (Hz), resolutie (bits)
  ledcAttachPin(ENA, channel);
  
  //motor
  pinMode(forward,OUTPUT);
  pinMode(backwards,OUTPUT);
}

void loop() {
  int PotValue = analogRead(potPin);

  leftvalue= digitalRead(leftpin);
  rightvalue= digitalRead(rightpin);
  upvalue= digitalRead(uppin);
  downvalue= digitalRead(downpin);

  //Vooruit
  if(upvalue == 0){
    if(leftvalue==1 && rightvalue==1){
      //Vorige richting veranderen
      if(PotValue < 1900){
        ledcWrite(channel, 255);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        Serial.println("naar rechts");
      }
      else if(PotValue > 2100){
        ledcWrite(channel, 255);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        Serial.println("naar links");
      }
      Serial.println("Auto recht vooruit");
      digitalWrite(forward,HIGH);
      digitalWrite(backwards,LOW);
    }  
    else if(leftvalue==0){
      digitalWrite(forward,HIGH);
      digitalWrite(backwards,LOW);
      
      ledcWrite(channel, 255);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      Serial.println("Shuinlinks Vooruit");
    }
    else if(rightvalue==0){
      digitalWrite(forward,HIGH);
      digitalWrite(backwards,LOW);
      
      ledcWrite(channel, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      Serial.println("schuinrechts Vooruit");
    }
  }
  
  //Achteruit
  else if(downvalue==0){
    if(leftvalue==1 && rightvalue==1){
      //Vorige richting veranderen
      if(PotValue < 1900){
        ledcWrite(channel, 255);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        Serial.println("naar rechts");
      }
      else if(PotValue > 2100){
        ledcWrite(channel, 255);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        Serial.println("naar links");
      }
      Serial.println("Auto recht achteruit");
      digitalWrite(forward,LOW);
      digitalWrite(backwards,HIGH);
    }
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
    digitalWrite(forward,LOW);
    digitalWrite(backwards,LOW);
    //Vorige richting veranderen
    if(PotValue < 1900){
      ledcWrite(channel, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      Serial.println("naar rechts");
    }
    else if(PotValue > 2100){
      ledcWrite(channel, 255);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      Serial.println("naar links");
    }
    Serial.println("Auto staat stil");
  }
}
