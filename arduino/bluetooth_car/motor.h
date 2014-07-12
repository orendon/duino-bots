#include "motion_driver.h"

namespace DuinoBots {
  class Motor : public MotionDriver {

  public:

    Motor(int directionPin, int brakePin, int speedPin) : MotionDriver()
    {
      motorDirectionPin = directionPin;
      motorBrakePin = brakePin;
      motorSpeedPin = speedPin;
    }

    void initialize()
    {
      pinMode(motorDirectionPin, OUTPUT);
      pinMode(motorBrakePin, OUTPUT);
    }

    void moveForward() {
      digitalWrite(motorDirectionPin, HIGH);
      ignite();
    }

    void moveBackwards() {
      digitalWrite(motorDirectionPin, LOW);
      ignite();
    }

    void stop() {
      digitalWrite(motorBrakePin, HIGH);
    }

  private:

    int motorDirectionPin;
    int motorBrakePin;
    int motorSpeedPin;

    void ignite() {
      analogWrite(motorSpeedPin, getSpeed());
      digitalWrite(motorBrakePin, LOW);
    }

  };
};
