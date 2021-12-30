//libraries Servo with no semi colons
//servo is an object need to interact with it
#include <Servo.h>
int servo = 3;
int servoPos;
Servo myServo;
int photo = A2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servo);
  pinMode(photo,INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int photoVal = analogRead(photo);
  Serial.println(photoVal);
  delay(500);
  /*Serial.println("angle position between 0 and 180 degrees:" );
  while (Serial.available() ==0) {
      servoPos = Serial.parseInt();
  }*/
  if (photoVal < 200) {
    servoPos = 180;
  } else if (photoVal > 500) {
    servoPos = 0;
  } else {
    servoPos = 90;
  }
    myServo.write(servoPos); // position in degrees (cheap can't go beyond 180) 
}
