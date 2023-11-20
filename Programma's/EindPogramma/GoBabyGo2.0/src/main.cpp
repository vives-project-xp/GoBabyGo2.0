#include <Arduino.h>
#include "MotorControl.h"

const int potPin = 14;

const int xpin = 2;
const int ypin = 4;
int xposition;
int yposition;
int High=2800;
int Low=1200;

MotorControl car(23, 22, 21, 13, 15, 19);

void setup() {
  car.initialize();
}

void loop() {
  int PotValue = analogRead(potPin);
  xposition = analogRead(xpin);
  yposition = analogRead(ypin);

  //Dit regelt de positie van het stuurwiel maar zetten we voorlopig in commentaar omdat we de potmeter niet gebruiken
  // if (PotValue != xposition) {
  //   PotValue = xposition;
  //   adjustWheelPosition(xposition);
  // }

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

  //sturen dit kan allemaal in commentaar omdat je de adjustWheelPosition functie gebruikt 
  //maar ik laat dit staan om nu nog te testen zonder de potmeter
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

void adjustWheelPosition(int xposition) {
  int midpoint = 2048;
  int draaiHoek = xposition - midpoint;

  if (draaiHoek > 0) {
    // Draai naar rechts
    car.turnRight();
  } else if (draaiHoek < 0) {
    // Draai naar links
    car.turnLeft();
  } else {
    // Ga rechtuit als de draaihoek 0 is
    car.turnStraight();
  }
}