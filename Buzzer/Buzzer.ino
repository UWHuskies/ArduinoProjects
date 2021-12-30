//Active Buzzer
int potPin = A2;
int buzz = 12;
int t = 2000;
String msg = "Integer Number input: ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potPin,INPUT);
  pinMode(buzz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 // Serial.println(msg);
  //while(Serial.available() == 0) {
    
  //}
  //int num = Serial.parseInt();
  int potVal = analogRead(potPin);

  while (potVal>1000) {
    digitalWrite(buzz,HIGH);
    potVal = analogRead(potPin);
  }
      digitalWrite(buzz,LOW);

/*
 * 
 * //different t values create different tones
 * for (j=1; j<=100;j++) {
 *  digitalWrite(buzz,HIGH);
 *  delay(t);
 *  digitalWrite(buzz,LOW);
 *  delay(t);
 *  }
 * 
 * 
 */
      
}
