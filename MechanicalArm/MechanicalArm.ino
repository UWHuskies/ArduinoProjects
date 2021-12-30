#include <Servo.h>
#include <Stepper.h>
int IN1 =8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int sPin =  2;
int stepsPerRev = 2048;
//rev per min
int motorSpeed = 10;
Servo servo;
int dt = 100;
Stepper myStep(stepsPerRev, IN1,IN3,IN2,IN4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(sPin);
  myStep.setSpeed(motorSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 180; i++) {
    myStep.step(2048.0/180.0);
    //only whole numbers in degree
    servo.write(i);
    delay(10);
  }
  delay(2000);
    for (int i = 180; i >= 0; i--) {
    myStep.step((-2048.0/180.0));
    servo.write(i);
    delay(10);
  }
  delay(2000);



}
