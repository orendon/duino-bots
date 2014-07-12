
/*
  Arduino Car
  Android remote controller via bluetooth HC-06
*/

#define HALF_SPEED 123
#define FULL_SPEED 255

#define UP 'U'
#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'
#define STOP 'S'

// left motor (channel A)
const int rightDir = 12;
const int rightSpeed = 3;
const int rightBrake = 9;

// right motor (channel B)
const int leftDir = 13;
const int leftSpeed = 11;
const int leftBrake = 8;

void setup() {
  pinMode(leftDir, OUTPUT);
  pinMode(leftBrake, OUTPUT);
  pinMode(rightDir, OUTPUT);
  pinMode(rightBrake, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int cmd = Serial.read();
    // Serial.println(cmd, DEC);

    switch (cmd) {
      case UP:
        moveForward();
        break;
      case DOWN:
        moveBackwards();
        break;
      case LEFT:
        turnLeft();
        break;
      case RIGHT:
        turnRight();
        break;
      case STOP:
        brake();
        break;
    }

    Serial.flush();
  }
}

void brake() {
  digitalWrite(rightBrake, HIGH);
  digitalWrite(leftBrake, HIGH);
}

void unbrake(int speedValue) {
  digitalWrite(leftBrake, LOW);
  analogWrite(leftSpeed, speedValue);
  digitalWrite(rightBrake, LOW);
  analogWrite(rightSpeed, speedValue);
}

void moveForward(){
  digitalWrite(leftDir, HIGH);
  digitalWrite(rightDir, HIGH);
  unbrake(FULL_SPEED);
}

void moveBackwards() {
  digitalWrite(leftDir, LOW);
  digitalWrite(rightDir, LOW);
  unbrake(FULL_SPEED);
}

void turnLeft() {
  unbrake(HALF_SPEED);
  digitalWrite(leftDir, LOW);
  digitalWrite(rightDir, HIGH);
}

void turnRight() {
  unbrake(HALF_SPEED);
  digitalWrite(leftDir, HIGH);
  digitalWrite(rightDir, LOW);
}
