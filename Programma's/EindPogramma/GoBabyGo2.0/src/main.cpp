#include <Arduino.h>
#include "MotorControl.h"

const int potPin = 14;
const int potCenterValue = 2042;

const int xpin = 2;
const int ypin = 4;
int xposition;
int yposition;

MotorControl car(23, 22, 4, 13, 15, 2);

void setup() {
  car.initialize();
}

void loop() {
  int PotValue = analogRead(potPin);
  xposition = analogRead(xpin);
  yposition = analogRead(ypin);

  if (yposition > 4000) {
    if (xposition<4000 && xposition>100) {
      if (PotValue < (potCenterValue - 150)) {
        car.turnRight();
        Serial.println("naar links");
      } else if (PotValue > (potCenterValue + 150)) {
        car.turnLeft();
        Serial.println("naar rechts");
      }
      Serial.println("Auto recht vooruit");
      car.moveForward();
    } else if (xposition<100) {
      car.moveForward();
      car.turnLeft();
      Serial.println("Shuinlinks Vooruit");
    } else if (xposition>3500) {
      car.moveForward();
      car.turnRight();
      Serial.println("schuinrechts Vooruit");
    }
  } else if (yposition<100) {
    if (xposition<4000 && xposition>100) {
      if (PotValue < (potCenterValue - 150)) {
        car.turnRight();
        Serial.println("naar links");
      } else if (PotValue > (potCenterValue + 150)) {
        car.turnLeft();
        Serial.println("naar rechts");
      }
      Serial.println("Auto recht achteruit");
      car.moveBackward();
    } else if (xposition<500) {
      car.moveBackward();
      car.turnLeft();
      Serial.println("Shuinlinks achteruit");
    } else if (yposition<100) {
      car.moveBackward();
      car.turnRight();
      Serial.println("schuinrechts achteruit");
    }
  } else {
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