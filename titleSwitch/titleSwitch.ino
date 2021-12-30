int tiltPin = 2;
int tiltVal;

int redPin = 5;
int greenPin = 8;

void setup() {
  // put your setup code here, to run once:
    pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  Serial.begin(9600);
  pinMode(tiltPin,INPUT);
  digitalWrite(tiltPin,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  tiltVal = digitalRead(tiltPin);
  Serial.println(tiltVal);
  if (tiltVal == 0) {
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
  } else {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  }
  
}
