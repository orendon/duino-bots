/*
  Arduino Car
  Android remote controller via bluetooth HC-06
*/

#include "motor.h"

#define FULL_SPEED 255

#define UP 'U'
#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'
#define STOP 'S'

// right motor (channel A)
DuinoBots::Motor rightMotor(12, 9, 3);

// right motor (channel B)
DuinoBots::Motor leftMotor(13, 8, 11);

void setup() {
  leftMotor.initialize();
  leftMotor.setSpeed(FULL_SPEED);

  rightMotor.initialize();
  rightMotor.setSpeed(FULL_SPEED);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int cmd = Serial.read();
    // Serial.println(cmd, DEC);

    switch (cmd) {
      case UP:
        leftMotor.moveForward();
        rightMotor.moveForward();
        break;
      case DOWN:
        leftMotor.moveBackwards();
        rightMotor.moveBackwards();
        break;
      case LEFT:
        leftMotor.moveBackwards();
        rightMotor.moveForward();
        break;
      case RIGHT:
        leftMotor.moveForward();
        rightMotor.moveBackwards();
        break;
      case STOP:
        leftMotor.stop();
        rightMotor.stop();
        break;
    }

    Serial.flush();
  }
}
