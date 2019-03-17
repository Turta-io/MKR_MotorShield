/*
  Turta_MotorDriver.cpp - Dual Motor Driver Library for Turta MKR Motor Shield.
  Created by Turta, February 28, 2019.
  Released under the MIT Licence.
  www.turta.io
*/

#include <Arduino.h>
#include "Turta_MotorDriver.h"

// Pin Definitions
#define R_EN_PIN 0
#define L_EN_PIN 1
#define L_R_PWM_PIN 2
#define L_F_PWM_PIN 3
#define R_R_PWM_PIN 4
#define R_F_PWM_PIN 5

Turta_MotorDriver::Turta_MotorDriver() {}

void Turta_MotorDriver::begin() {
  pinMode(L_EN_PIN, OUTPUT);
  pinMode(R_EN_PIN, OUTPUT);
  pinMode(L_F_PWM_PIN, OUTPUT);
  pinMode(L_R_PWM_PIN, OUTPUT);
  pinMode(R_F_PWM_PIN, OUTPUT);
  pinMode(R_R_PWM_PIN, OUTPUT);

  digitalWrite(L_EN_PIN, LOW);
  digitalWrite(R_EN_PIN, LOW);
  digitalWrite(L_F_PWM_PIN, LOW);
  digitalWrite(L_R_PWM_PIN, LOW);
  digitalWrite(R_F_PWM_PIN, LOW);
  digitalWrite(R_R_PWM_PIN, LOW);
}

void Turta_MotorDriver::driveMotors(int16_t leftSpeed, int16_t rightSpeed) {
  // Left motor speed & direction
  if (leftSpeed >= 0) {
		analogWrite(L_R_PWM_PIN, 0);
    analogWrite(L_F_PWM_PIN, leftSpeed);
  } else {
		analogWrite(L_F_PWM_PIN, 0);
		analogWrite(L_R_PWM_PIN, -leftSpeed);
  }
  
  // Right motor speed & direction
  if (rightSpeed >= 0) {
		analogWrite(R_R_PWM_PIN, 0);
    analogWrite(R_F_PWM_PIN, leftSpeed);
  } else {
		analogWrite(R_F_PWM_PIN, 0);
		analogWrite(R_R_PWM_PIN, -leftSpeed);
  }

  // Enable motor drivers
  digitalWrite(L_EN_PIN, HIGH);
  digitalWrite(R_EN_PIN, HIGH);
}

void Turta_MotorDriver::coastMotors() {
  // Stand-by motor drivers
  digitalWrite(L_EN_PIN, LOW);
  digitalWrite(R_EN_PIN, LOW);

  // Coast motors
  analogWrite(L_F_PWM_PIN, 0);
  analogWrite(L_R_PWM_PIN, 0);
  analogWrite(R_F_PWM_PIN, 0);
  analogWrite(R_R_PWM_PIN, 0);
}

void Turta_MotorDriver::brakeMotors() {
  // Short brake motors
  analogWrite(L_F_PWM_PIN, 255);
  analogWrite(L_R_PWM_PIN, 255);
  analogWrite(R_F_PWM_PIN, 255);
  analogWrite(R_R_PWM_PIN, 255);

  // Enable motor drivers
  digitalWrite(L_EN_PIN, HIGH);
  digitalWrite(R_EN_PIN, HIGH);
}