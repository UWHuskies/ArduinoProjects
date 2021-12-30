#include <Servo.h>
int servoPin = 11;
int echoPin = 10;
int triggerPin = 9;
Servo sv;
int dt = 25;
int pause = 1000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sv.attach(servoPin);
  pinMode(echoPin,INPUT);
  pinMode(triggerPin,OUTPUT);
  sv.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triggerPin,LOW);
  delay( dt);
  digitalWrite(triggerPin,HIGH);
  delay(dt);
  digitalWrite(triggerPin,LOW);
  delay(dt);

  float Time = pulseIn(echoPin,HIGH);
  delay(pause);
  float distance = 760.0 * 63360.0 * Time / (3.6E+9 * 2.0);
  Serial.println(distance);
 
  if (distance < 5.0) {
    sv.write(0);
    delay(pause);
    sv.write(180);
  } else {
    sv.write(90);
    delay(pause);
  }
  
}
