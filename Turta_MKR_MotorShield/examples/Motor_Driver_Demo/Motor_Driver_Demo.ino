#include <Turta_MotorDriver.h>

// Create Motor Driver instance
Turta_MotorDriver md;

void setup() {
  // Initialize Motor Driver
  md.begin();
}

void loop() {
  // Increase motor speed from coast to maximum forward
  for (short i = 0; i < 255; i++) {
    md.driveMotors(i, i);
    delay(10);
  }

  // Set motor speed to maximum forward
  md.driveMotors(255, 255);
  delay(2000);

  // Decrease motor speed from maximum forward to coast
  for (short i = 255; i > 0; i--) {
    md.driveMotors(i, i);
    delay(10);
  }

  // Coast motors
  md.driveMotors(0, 0);
  delay(2000);

  // Set motor speed to half reverse
  md.driveMotors(-128, -128);
  delay(2000);

  // Set motor speed to maximum reverse
  md.driveMotors(-255, -255);
  delay(2000);

  // Set motor speed to half reverse
  md.driveMotors(-128, -128);
  delay(2000);

  // Short brake motors
  md.brakeMotors();
  delay(2000);
}