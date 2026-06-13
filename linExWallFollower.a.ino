#include <L298N.h>

// Motor pins
#define AIN1 6
#define AIN2 7
#define PWMA 5
#define BIN1 8
#define BIN2 9
#define PWMB 10

// IR sensor pins
#define LEFT_IR A0
#define CENTER_IR A1
#define RIGHT_IR A2

// Motor driver setup
L298N motorLeft(PWMA, AIN1, AIN2);
L298N motorRight(PWMB, BIN1, BIN2);

// PID constants
float Kp = 15;
float Ki = 0;
float Kd = 8;

// Control variables
int baseSpeed = 130; // Adjust this based on your motor power
int error = 0, previousError = 0, P = 0, I = 0, D = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LEFT_IR, INPUT);
  pinMode(CENTER_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);

  // Optional: small delay at startup
  delay(1000);
}

void loop() {
  int leftSensor = analogRead(LEFT_IR);
  int centerSensor = analogRead(CENTER_IR);
  int rightSensor = analogRead(RIGHT_IR);

  // Print sensor values for debugging
  Serial.print("L: "); Serial.print(leftSensor);
  Serial.print(" C: "); Serial.print(centerSensor);
  Serial.print(" R: "); Serial.println(rightSensor);

  // White line = higher value (usually > 700 for white)
  bool onLeft = leftSensor > 700;
  bool onCenter = centerSensor > 700;
  bool onRight = rightSensor > 700;

  // Define error: center = 0, left = +1, right = -1
  if (onLeft && !onCenter && !onRight) {
    error = 1;
  } else if (!onLeft && !onCenter && onRight) {
    error = -1;
  } else if (!onLeft && onCenter && !onRight) {
    error = 0;
  } else if (onLeft && onCenter && !onRight) {
    error = 0.5;
  } else if (!onLeft && onCenter && onRight) {
    error = -0.5;
  } else if (onLeft && onCenter && onRight) {
    error = 0;  // Perfectly centered
  } else {
    // Lost line: turn based on previous error
    if (previousError > 0) error = 2;
    else error = -2;
  }

  // PID computation
  P = error;
  I += error;
  D = error - previousError;

  int PIDvalue = Kp * P + Ki * I + Kd * D;
  previousError = error;

  int leftSpeed = baseSpeed - PIDvalue;
  int rightSpeed = baseSpeed + PIDvalue;

  // Constrain speeds
  leftSpeed = constrain(leftSpeed, -255, 255);
  rightSpeed = constrain(rightSpeed, -255, 255);

  motor_drive(leftSpeed, rightSpeed);
  delay(10);
}

void motor_drive(int left, int right) {
  if (left >= 0) {
    motorLeft.setSpeed(left);
    motorLeft.forward();
  } else {
    motorLeft.setSpeed(abs(left));
    motorLeft.backward();
  }

  if (right >= 0) {
    motorRight.setSpeed(right);
    motorRight.forward();
  } else {
    motorRight.setSpeed(abs(right));
    motorRight.backward();
  }
}
