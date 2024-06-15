#include "Tone.h"

#define NOTE_L0 2000
#define NOTE_L1 20
#define NOTE_U0 800
#define NOTE_U1 970

BuzzerControl::BuzzerControl(int buzzerPin) {
  this->buzzerPin = buzzerPin;
  pinMode(buzzerPin, OUTPUT);
}

int BuzzerControl::forwardTone(int buzzarPin, int distance) {

  int melody[] = {
    //tone array
    NOTE_U0, NOTE_U1
  };

  for (int i = 0; i < sizeof(melody); i++) {
    tone(buzzarPin, melody[i], 250);  //play tone
    delay(80 + 5 * distance);         //delay
    noTone(buzzerPin);                //tone off
  }
}

int BuzzerControl::depthTone(int buzzarPin, int depth) {

  tone(buzzarPin, NOTE_L0);
  tone(buzzarPin, NOTE_L1);
  tone(buzzarPin, NOTE_L0);
 
  if (depth < 30) {
    delay(100);
  } else {
    delay(50);
  }

  noTone(buzzarPin);
}

int BuzzerControl::intensityTone(int buzzarPin, int LightIntensity) {

  if (LightIntensity < 5) {
    tone(buzzarPin, NOTE_L0);
    tone(buzzarPin, NOTE_L1);
    tone(buzzarPin, NOTE_L0);
    delay(80 + LightIntensity * 10);
    noTone(buzzarPin);
  }
}