#include "Calculation_Function.h"
#include <Arduino.h>

#define NOTE_L0 2000
#define NOTE_L1 20

DistanceSensor::DistanceSensor(int trigPin, int echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

DepthSensor::DepthSensor(int trigPin1, int echoPin1) {
  this->trigPin1 = trigPin1;
  this->echoPin1 = echoPin1;
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
}

LightSensor::LightSensor(int LDRpin, int LightIntensity) {
  this->LDRpin = LDRpin;
  this->LightIntensity = LightIntensity;
}


int DistanceSensor::readDistance() {
  //Distance calculation code here
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  //send ultrasonic wave
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = (duration * 0.034 / 2);

  return distance;
}

int DepthSensor::readDepth() {
  //Depth calculation code here
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);  //send ultrasonic wave
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  long duration1 = pulseIn(echoPin1, HIGH);
  int depth = (duration1 * 0.034 / 2);

  return depth;
}

int LightSensor::readIntensity() {
  //Light Intensity calculation code here
  int LightIntensity = analogRead(LDRpin);  // read the value from the sensor

  return LightIntensity;
}