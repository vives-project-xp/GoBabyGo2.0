#include <Arduino.h>
#include "MotorControl.h"

const int potPin = 14;
const int potCenterValue = 2042;

const int xpin = 2;
const int ypin = 4;
int xposition;
int yposition;
int High=2400;
int Low=1600;

MotorControl car(23, 22, 21, 13, 15, 19);

void setup() {
  car.initialize();
}

void loop() {
  int PotValue = analogRead(potPin);
  xposition = analogRead(xpin);
  yposition = analogRead(ypin);

  //snelheid
  if (yposition > High) {
    Serial.println("Vooruit");
    car.moveForward();
  } else if (yposition < Low) {
    Serial.println("Achteruit");
    car.moveBackward();
  }else {
    car.stopMotor();
    Serial.println("Auto staat stil");
  }

  //sturen 
  if (xposition > High) {
    car.turnLeft();
    Serial.println("Links");
  } else if (xposition < Low) {
    car.turnRight();
    Serial.println("Rechts");
  } else {
    car.turnStraight();
    Serial.println("Auto staat stil");
  }

}