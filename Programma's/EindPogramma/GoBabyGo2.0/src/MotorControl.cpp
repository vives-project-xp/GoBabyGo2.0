#include "MotorControl.h"

//Function definitions
void MotorControl::initialize() {
  //Initialize serial communication
  Serial.begin(9600);

  //Initialize pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  ledcSetup(channel, 5000, 8);
  ledcAttachPin(ENA, channel);

  pinMode(forward, OUTPUT);
  pinMode(backwards, OUTPUT);
}

//Functions for controlling the car
void MotorControl::moveForward() {
  digitalWrite(forward, HIGH);
  digitalWrite(backwards, LOW);
}

void MotorControl::moveBackward() {
  digitalWrite(forward, LOW);
  digitalWrite(backwards, HIGH);
}

void MotorControl::stopMotor() {
  digitalWrite(forward, HIGH);
  digitalWrite(backwards, HIGH);
}

void MotorControl::turnLeft() {
  ledcWrite(channel, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void MotorControl::turnRight() {
  ledcWrite(channel, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void MotorControl::turnStraight() {
  ledcWrite(channel, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}