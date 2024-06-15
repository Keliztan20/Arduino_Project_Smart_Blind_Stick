#ifndef TONE_H
#define TONE_H

#include <Arduino.h>

class BuzzerControl {
public:
  BuzzerControl(int buzzerPin);
  int forwardTone(int buzzerPin, int distance);
  int depthTone(int buzzerPin, int depth);
  int intensityTone(int buzzerPin, int LightIntensity);
private:
  int buzzerPin;
  int distance;
  int depth;
  int LightIntensity;
};

#endif


