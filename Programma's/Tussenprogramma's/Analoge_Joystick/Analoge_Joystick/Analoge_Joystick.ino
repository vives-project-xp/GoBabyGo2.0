int xpin = 2;
int ypin = 4;
int xposition;
int yposition;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  xposition = analogRead(xpin);
  yposition = analogRead(ypin);

  if(yposition>4000){
    if(xposition>3500){
      Serial.println("rechtsvooruit");
    }
    else if(xposition<500){
      Serial.println("linksvooruit");
    }
    else{
      Serial.println("rechtdoor");
    }
  }
  else if(yposition<100){
    if(xposition>3500){
      Serial.println("rechtsachteruit");
    }
    else if(xposition<500){
      Serial.println("linkssachteruit");
    }
    else{
    Serial.println("achteruit");  
    }
  }
  else{
    Serial.println("staat stil");
  }
}
