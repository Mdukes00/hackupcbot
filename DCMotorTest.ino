

#include <Stream.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

  // Set the speed to start, from 0 (off) to 255 (max speed)


}

void loop() {
  char keystroke;
  if (Serial.available() > 0) {
    keystroke = Serial.read();
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
        // if nothing else matches, do the default
        // default is optional
        break;
    }
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
