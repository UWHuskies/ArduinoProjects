//don't use power supply as it is only 5V, use the battery itself

//Control a speed and direction of a motor with the XPin on the joystick 


int speedPin = 5;
int dir1Pin = 4;
int dir2Pin = 3;
int mySpeed = 0;

int button1 = 8;
int button2  = 11;
int butVal1;
int butVal2;

int dt = 500; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speedPin,OUTPUT);
  pinMode(dir1Pin,OUTPUT);
  pinMode(dir2Pin,OUTPUT);
  
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);

  //setup a pullup button: 
    //when press down, reads a 0 and no press on button, reads a 1
  digitalWrite(button1,HIGH);
  digitalWrite(button2,HIGH);
}

void loop() {
  butVal1 = digitalRead(button1);
  butVal2 = digitalRead(button2);
  Serial.print("Motor Speed ");
  Serial.println(mySpeed);
  if (butVal1 == 0) {
    mySpeed += 10; 
    delay(dt);
  } 
  if (butVal2 == 0) {
    mySpeed -= 10; 
    delay(dt);
  }

  if (butVal2 > 255) {
    mySpeed = 255;
  }

  if (butVal1 < -255) {
    mySpeed = -255;
  }

  if (mySpeed == 10) {
    mySpeed = 100;
  }

  if (mySpeed == -10) {
    mySpeed = -100;
  }

  if (mySpeed == 90 || mySpeed == 95) {
    mySpeed = 0;
  }

  if (mySpeed == -90 || mySpeed == -95) {
    mySpeed = 0;
  }
  if (mySpeed == 0) {
    analogWrite(speedPin,0);  
  } else if (mySpeed > 0) {
  digitalWrite(dir1Pin,LOW);
  digitalWrite(dir2Pin,HIGH);
  analogWrite(speedPin,mySpeed); 
  } else {
    digitalWrite(dir1Pin,LOW);
  digitalWrite(dir2Pin,HIGH);
  analogWrite(speedPin,mySpeed);   
  }
  
}
