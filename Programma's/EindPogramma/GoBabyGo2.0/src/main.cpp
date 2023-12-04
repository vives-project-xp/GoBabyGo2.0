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
  //binnenhalen van de waarden van de potmeter en de joystick
  int PotValue = analogRead(potPin);
  xposition = analogRead(xpin);
  yposition = analogRead(ypin);

  //Dit regelt de positie van het stuurwiel maar zetten we voorlopig in commentaar omdat we de potmeter niet gebruiken
  // if (PotValue != xposition) {
  //   adjustWheelPosition(xposition,potValue);
  // }

  //snelheid
  if (yposition > High) {
    Serial.println("Achteruit");
    car.moveBackward();
  } else if (yposition < Low) {
    Serial.println("Vooruit");
    car.moveForward();
  }else {
    car.stopMotor();
    Serial.println("Auto staat stil");
  }

  //sturen dit kan allemaal in commentaar omdat je de adjustWheelPosition functie gebruikt 
  //maar ik laat dit staan omdat het systeem met de potmeter niet werkt
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

//deze functie zorgt er voor dat de wielen van de automatisch worden gepositioneerd afgankelijk van de positie van de 
//xcoordinaat van de joystick en de potmeter
void adjustWheelPosition(int xposition, int potvalue) {
  int draaiHoek = xposition - potvalue;

  if (draaiHoek > 200) {
    // Draai naar rechts
    car.turnRight();
  } else if (draaiHoek < 200) {
    // Draai naar links
    car.turnLeft();
  } else {
    // Ga rechtuit als de draaihoek 0 is
    car.turnStraight();
  }
}