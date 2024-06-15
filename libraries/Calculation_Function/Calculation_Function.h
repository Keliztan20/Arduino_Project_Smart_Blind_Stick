#ifndef CALCULATION_FUNCTION_H
#define CALCULATION_FUNCTION_H

#include <Arduino.h>

class DistanceSensor {
public:
  DistanceSensor(int trigPin, int echoPin);
  int readDistance();
private:
  int trigPin;
  int echoPin;
};

class DepthSensor {
public:
  DepthSensor(int trigPin1, int echoPin1);
  int readDepth();
private:
  int trigPin1;
  int echoPin1;
};

class LightSensor {
public:
  LightSensor(int LDRpin, int LightIntensity);
  int readIntensity();
private:
  int LDRpin;
  int LightIntensity;
};

#endif