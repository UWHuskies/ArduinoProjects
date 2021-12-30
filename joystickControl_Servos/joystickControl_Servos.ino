
//import servo
#include <Servo.h>
//setup servo object
Servo myServo;
//setUP the positon of servo
int servoPos;
//setUp servo pins
int servo = 10;

int buzzerPin =7;

int Xpin = A0;
int Ypin = A1;
int Spin = 2;
int Xval;
int Yval;
int Sval;
int dt = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  pinMode(Spin,INPUT);

  pinMode(buzzerPin,OUTPUT);
  pinMode(servo,OUTPUT);
  myServo.attach(servo);
  //write a a value at 1 
  digitalWrite(Spin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  //read the value from adruino
  Sval = digitalRead(Spin);
  delay(dt);
  Serial.print("X value =");
  Serial.print(Xval);
  Serial.print(" Y value = ");
  Serial.print(Yval);
  Serial.print(" S value = ");
  Serial.println(Sval);

//if press the switch, the buzzer turns on
 if (Sval == 0) {
    digitalWrite(buzzerPin,HIGH);
  } else {
    digitalWrite(buzzerPin,LOW);
  }
  
  // servos goes from 0 to 180 and joystick potenimeter goes from 0 to 1023
  //linear realtionships and produce a line 
  servoPos = (180.0/1023.0)*Xval;
  myServo.write(servoPos);
}
