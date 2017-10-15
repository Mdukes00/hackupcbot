#include <Stream.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"


Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);
String stringFromConsole;
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
        Forward();
        break;
      case '2':
        Backward();
        break;
      case '3':
        TurnLeft();
        break;
      case '4':
        DriveLeft();
        break;
      case '5':
        TurnRight();
        break;
      case '6':
        DriveRight();
        break;
      case '7':
        Stop();
        break;
      case '8':
        break;
      default:
        break;
    }

  }

  if (keystroke == newkeystroke) {

    switch (keystroke) {
      case '1':
        Forward();
        break;
      case '2':
        Backward();
        break;
      case '3':
        TurnLeft();
        break;
      case '4':
        DriveLeft();
        break;
      case '5':
        TurnRight();
        break;
      case '6':
        DriveRight();
        break;
      case '7':
        Stop();
        break;
      case '8':
        break;
      default:
        break;
    }
  }
}



void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    newkeystroke = Serial.read();
     Serial.println(newkeystroke);
  //  newkeystroke = stringFromConsole[1];
  }
}

void SetSpeed(int right, int left) {
  leftMotor->setSpeed(left);
  rightMotor->setSpeed(right);
     Serial.println(String(newkeystroke));
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
