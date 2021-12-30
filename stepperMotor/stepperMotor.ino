
//stepper motor library
#include <Stepper.h>
//revolutions base on the stepper motor 28BYJ-48  specifications  
//need 2048 steps for 1 revolution 
int stepsPerRevolution = 2048;

//speed is 10 rpm (low speed is better)
int motSpeed = 10;
int dt = 100;

//setup the stepper object 
//parameters is stepsPer Revolution and the pins in the order that they were added
Stepper myStepper(stepsPerRevolution,8,10,9,11);


int switchPin = 4;

int motor=1;
int buttonNew;
int buttonOld = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
  pinMode(switchPin,INPUT);
  //gives it 5Vs as it is initized 
  digitalWrite(switchPin,HIGH);
}

void loop() {
  buttonNew = digitalRead(switchPin);
  if (buttonOld == 1 && buttonNew == 0) {
    motor = motor*-1;
  }
  myStepper.step(motor*1);
  buttonOld = buttonNew; 
  // goes one revolution 
/*
  myStepper.step(stepsPerRevolution);
  delay(dt);
  myStepper.step(-stepsPerRevolution);*/
}
