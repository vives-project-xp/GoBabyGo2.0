#ifndef MotorControl_h
#define MotorControl_h

#include <Arduino.h>

class MotorControl {
  //Private variables
  const int IN1, IN2, ENA, channel;
  const int forward, backwards;

public:
  //Constructor
  MotorControl(int in1, int in2, int ena, int ch, int fw, int bw)
      : IN1(in1), IN2(in2), ENA(ena), channel(ch), forward(fw), backwards(bw) {}

  //Function definitions
  void initialize();
  void moveForward();
  void moveBackward();
  void stopMotor();
  void turnLeft();
  void turnRight();
  void turnStraight();

};

#endif