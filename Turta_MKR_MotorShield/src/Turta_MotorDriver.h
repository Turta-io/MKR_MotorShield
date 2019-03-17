/*
  Turta_MotorDriver.h - Dual Motor Driver Library for Turta MKR Motor Shield.
  Created by Turta, February 28, 2019.
  Released under the MIT Licence.
  www.turta.io
*/

#ifndef Turta_MotorDriver_h
#define Turta_MotorDriver_h

#include <Arduino.h>

class Turta_MotorDriver
{
  public:
    Turta_MotorDriver();
    void begin();
    void driveMotors(int16_t leftSpeed, int16_t rightSpeed);
    void coastMotors();
    void brakeMotors();
  private:
};

#endif