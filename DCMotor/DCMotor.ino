//don't use power supply as it is only 5V, use the battery itself

int speedPin = 5;
int dir1Pin = 4;
int dir2Pin = 3;
int motorSpeed = 125;
int tiltPin=2;
int tiltVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speedPin,OUTPUT);
  pinMode(dir1Pin,OUTPUT);
  pinMode(dir2Pin,OUTPUT);
   pinMode(tiltPin,INPUT);
  //switch closed which means HIGH which reads a 0,  so it will be ground
  digitalWrite(tiltPin,HIGH);
 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir1Pin,LOW);
  digitalWrite(dir2Pin,HIGH);
  // read 0 if titled and 1 if upright
  tiltVal = digitalRead(tiltPin);
  Serial.println(tiltVal);
  if (tiltVal == 1)  {
      analogWrite(speedPin,0);
  } else {
  analogWrite(speedPin,motorSpeed);
  }
}
