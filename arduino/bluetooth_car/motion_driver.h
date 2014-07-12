namespace DuinoBots {
  class MotionDriver {

  public:

    MotionDriver() {
      currentSpeed = 0;
    }

    virtual void moveForward();
    virtual void moveBackwards();
    virtual void stop();

    int getSpeed() {
      return currentSpeed;
    }

    void setSpeed(int speed) {
      currentSpeed = constrain(speed, 0, 255);
    }

  private:

    int currentSpeed;

  };
};
