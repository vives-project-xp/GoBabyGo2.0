#include <Arduino.h>
#include "MotorControl.h"

const int potPin = 14;
const int potCenterValue = 2042;

const int xpin = 2;
const int ypin = 4;
int xposition;
int yposition;
int High=2200;
int Low=1800;

MotorControl car(23, 22, 21, 13, 15, 19);

void setup() {
  car.initialize();
}

void loop() {
  int PotValue = analogRead(potPin);
  xposition = analogRead(xpin);
  yposition = analogRead(ypin);

  if (yposition > High) {
    if (xposition<High && xposition>Low) {
      if (PotValue < (potCenterValue - 150)) {
        car.turnRight();
        Serial.println("naar links");
      } else if (PotValue > (potCenterValue + 150)) {
        car.turnLeft();
        Serial.println("naar rechts");
      }
    }
    Serial.println("Vooruit");
    car.moveForward();
    car.turnStraight();
  } else if (yposition<Low) {
    if (xposition<High && xposition>Low) {
      if (PotValue < (potCenterValue - 150)) {
        car.turnRight();
        Serial.println("naar links");
      } else if (PotValue > (potCenterValue + 150)) {
        car.turnLeft();
        Serial.println("naar rechts");
      }
    }
    Serial.println("Achteruit");
    car.moveBackward();
    car.turnStraight();
  } else if(xposition>High){
    car.turnLeft();
    Serial.println("Links");
  } else if (xposition<100){
    car.turnRight();
    Serial.println("Rechts");
  }else {
    car.stopMotor();
      if (PotValue < (potCenterValue - 150)) {
        car.turnRight();
        Serial.println("naar links");
      } else if (PotValue > (potCenterValue + 150)) {
        car.turnLeft();
        Serial.println("naar rechts");
      }
    Serial.println("Auto staat stil");
  }
}