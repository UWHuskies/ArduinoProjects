int myPin = A2;
float V2 = 0;
int readVal;
int redPin = 9;
int timeC = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A2,INPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(myPin);
  V2=(5./1023.)*readVal;
  Serial.print("Pentiometer: ");
  Serial.println(V2);
  /*if (V2 > 4.0 && V2 < 3.0) {
    digitalWrite(redPin,HIGH);
  }
  if (V2 < 4.0 || ) {
    digitalWrie(redPin,LOW);
  }*/

  if (V2 == 5.0) {
    digitalWrite(redPin,HIGH);
  }
  if (V2 != 5.0) {
    digitalWrite(redPin,LOW);
  }
  delay(timeC);
}
