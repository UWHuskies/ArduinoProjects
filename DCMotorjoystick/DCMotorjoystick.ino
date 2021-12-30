//don't use power supply as it is only 5V, use the battery itself

//Control a speed and direction of a motor with the XPin on the joystick 


int speedPin = 5;
int dir1Pin = 4;
int dir2Pin = 3;
int motorSpeed;

int Xpin = A0;
int Xval;
int dt = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speedPin,OUTPUT);
  pinMode(dir1Pin,OUTPUT);
  pinMode(dir2Pin,OUTPUT);
  pinMode(Xpin,INPUT);


 
  
}

void loop() {

   Xval = analogRead(Xpin);
  delay(dt);
  Serial.print("X value =");
  Serial.print(Xval);

  if (Xval < 512) { 
  motorSpeed = (-255./512.)*Xval +  255.;
  digitalWrite(dir1Pin,LOW);
  digitalWrite(dir2Pin,HIGH);
  } else {
  motorSpeed = (255./512.)*Xval -  255.;
  digitalWrite(dir1Pin,HIGH);
  digitalWrite(dir2Pin,LOW);    
  }
  analogWrite(speedPin,motorSpeed);   
}
