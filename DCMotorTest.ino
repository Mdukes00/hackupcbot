#include <Stream.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"


Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

char keystroke = 7;
char newkeystroke = 7;
void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");
  AFMS.begin();
}

void loop() {

  if (keystroke != newkeystroke) {
    keystroke = newkeystroke;
    switch (keystroke) {
      case '1':
        Serial.println("Forward");
        break;
      case '2':
        Serial.println("Backward");
        break;
      case '3':
        Serial.println("TurnLeft");
        break;
      case '4':
        Serial.println("DriveLeft");
        break;
      case '5':
        Serial.println("TurnRight");
        break;
      case '6':
        Serial.println("DriveRight");
        break;
      case '7':
        Serial.println("Stop");
        break;
      case '8':
        Serial.println("Destory all other robots....");
        break;
      default:
        Serial.println("Maybe the last thing should be happening" );
        break;
    }

  }

  if (keystroke == newkeystroke) {

    switch (keystroke) {
      case '1':
        Serial.println("Forward");
        break;
      case '2':
        Serial.println("Backward");
        break;
      case '3':
        Serial.println("TurnLeft");
        break;
      case '4':
        Serial.println("DriveLeft");
        break;
      case '5':
        Serial.println("TurnRight");
        break;
      case '6':
        Serial.println("DriveRight");
        break;
      case '7':
        Serial.println("Stop");
        break;
      case '8':
        Serial.println("Destory all other robots....");
        break;
      default:
        Serial.println("Maybe the last thing should be happening" );
        break;
    }
  }
}



void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    newkeystroke = Serial.read();
  }
}

void SetSpeed(int right, int left) {
  leftMotor->setSpeed(left);
  rightMotor->setSpeed(right);
}

void Forward() {
  SetSpeed(255, 255);
  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);
}

void Backward() {
  SetSpeed(255, 255);
  rightMotor->run(BACKWARD);
  leftMotor->run(BACKWARD);
}
void TurnLeft() {
  SetSpeed(255, 255);
  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
}

void TurnRight() {
  SetSpeed(255, 255);
  rightMotor->run(BACKWARD);
  leftMotor->run(FORWARD);
}

void DriveLeft() {
  SetSpeed(255, 50);
  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);
}

void DriveRight() {
  SetSpeed(50, 255);
  rightMotor->run(FORWARD);
  leftMotor->run(FORWARD);
}

void Stop() {
  SetSpeed(0, 0);
  rightMotor->run(RELEASE);
  leftMotor->run(RELEASE);
}
