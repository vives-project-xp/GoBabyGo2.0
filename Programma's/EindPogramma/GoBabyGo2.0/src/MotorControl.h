#ifndef MotorControl_h
#define MotorControl_h

#include <Arduino.h>

class MotorControl {
  const int leftpin, rightpin, uppin, downpin;
  const int IN1, IN2, ENA, channel;
  const int forward, backwards;

public:
  MotorControl(int left, int right, int up, int down, int in1, int in2, int ena, int ch, int fw, int bw)
      : leftpin(left), rightpin(right), uppin(up), downpin(down), IN1(in1), IN2(in2), ENA(ena), channel(ch), forward(fw), backwards(bw) {}

  void initialize();
  void moveForward();
  void moveBackward();
  void stopMotor();
  void turnLeft();
  void turnRight();
  int getLeftpin();
  int getrightpin();
  int getuppin();
  int getdownpin();

};

#endif
