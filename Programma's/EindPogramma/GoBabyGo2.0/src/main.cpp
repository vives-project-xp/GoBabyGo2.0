#include <Arduino.h>
#include "MotorControl.h"

const int potPin = 14;
const int potCenterValue = 1024;

MotorControl car(18, 5, 19, 21, 23, 22, 4, 13, 15, 2);

void setup() {
  car.initialize();
}

void loop() {
  int PotValue = analogRead(potPin);

  int leftvalue = digitalRead(car.getLeftpin());
  int rightvalue = digitalRead(car.getrightpin());
  int upvalue = digitalRead(car.getuppin());
  int downvalue = digitalRead(car.getdownpin());

  if (upvalue == 0) {
    if (leftvalue == 1 && rightvalue == 1) {
      if (PotValue < (potCenterValue - 50)) {
        car.turnRight();
        Serial.println("naar rechts");
      } else if (PotValue > (potCenterValue + 50)) {
        car.turnLeft();
        Serial.println("naar links");
      }
      Serial.println("Auto recht vooruit");
      car.moveForward();
    } else if (leftvalue == 0) {
      car.moveForward();
      car.turnLeft();
      Serial.println("Shuinlinks Vooruit");
    } else if (rightvalue == 0) {
      car.moveForward();
      car.turnRight();
      Serial.println("schuinrechts Vooruit");
    }
  } else if (downvalue == 0) {
    if (leftvalue == 1 && rightvalue == 1) {
      if (PotValue < (potCenterValue - 50)) {
        car.turnRight();
        Serial.println("naar rechts");
      } else if (PotValue > (potCenterValue + 50)) {
        car.turnLeft();
        Serial.println("naar links");
      }
      Serial.println("Auto recht achteruit");
      car.moveBackward();
    } else if (leftvalue == 0) {
      car.moveBackward();
      car.turnLeft();
      Serial.println("Shuinlinks achteruit");
    } else if (rightvalue == 0) {
      car.moveBackward();
      car.turnRight();
      Serial.println("schuinrechts achteruit");
    }
  } else {
    car.stopMotor();
    if (PotValue < (potCenterValue - 50)) {
      car.turnRight();
      Serial.println("naar rechts");
    } else if (PotValue > (potCenterValue + 50)) {
      car.turnLeft();
      Serial.println("naar links");
    }
    Serial.println("Auto staat stil");
  }
}
