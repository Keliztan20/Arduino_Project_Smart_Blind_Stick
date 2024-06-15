#include <Servo.h>
#include <Calculation_Function.h>
#include <Tone.h>

//////////////////////////////////
//Global Variable Declaration

const int Depth_trigPin = 10;
const int Depth_echoPin = 11;
const int Distance_trigPin = 12;
const int Distance_echoPin = 13;

const int BuzzarPin = 8;
const int LDRpin = A0;

int distance, depth, LightIntensity;

Servo servo;
int angle = 0;

///////////////////////////////////

//-----------------------------------------------------------------//
//Instances of Classes
DistanceSensor forwarddistance(Distance_trigPin, Distance_echoPin);
DepthSensor depthdistance(Depth_trigPin, Depth_echoPin);
LightSensor lightintensity(LDRpin, LightIntensity);
BuzzerControl buzzercontrol(BuzzarPin);
//-----------------------------------------------------------------//

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(Distance_trigPin, OUTPUT);
  pinMode(Distance_echoPin, INPUT);

  pinMode(Depth_trigPin, OUTPUT);
  pinMode(Depth_echoPin, INPUT);

  pinMode(BuzzarPin, OUTPUT);

  servo.attach(7);
  servo.write(angle);
}

void loop() {
  // put your main code here, to run repeatedly:
  Servo_Motor();
}

void Looping() {

  /*LightIntensity = lightintensity.readIntensity();
  Serial.print(LightIntensity);
  Serial.println(" I");
  if (LightIntensity < 5) {
    buzzercontrol.intensityTone(BuzzarPin, LightIntensity);
  }*/

  distance = forwarddistance.readDistance();
  Serial.print(distance);
  Serial.println(" Cm");
  if (distance < 30) {
    buzzercontrol.forwardTone(BuzzarPin, distance);
  }

  depth = depthdistance.readDepth();
  Serial.print(depth);
  Serial.println(" M");
  if (depth > 15) {
    buzzercontrol.depthTone(BuzzarPin, depth);
  }
}

void Servo_Motor() {

  for (angle = 0; angle < 180; angle++) {
    servo.write(angle);
    delay(15);

    Looping();
  }
  for (angle = 180; angle > 0; angle--) {
    servo.write(angle);
    delay(15);

    Looping();
  }
}
