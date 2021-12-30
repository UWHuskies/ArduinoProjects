int red = 7;
int potPin = A2;
//int yellow = 2;
int potVal;
int sec = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  //pinMode(yellow,OUTPUT);
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*for (int i = 0; i < 3; i++) { 
    digitalWrite(red,HIGH);
    delay(sec);
    digitalWrite(red,LOW);
    delay(sec); 
  }

    for (int i = 0; i < 3; i++) { 
    digitalWrite(yellow,HIGH);
    delay(sec);
    digitalWrite(yellow,LOW);
    delay(sec); 
  }*/

   potVal = analogRead(potPin);
   Serial.println(potVal);
  delay(sec);
   
   while (potVal < 1000) {
   digitalWrite(red,HIGH);
   potVal = analogRead(potPin);
   Serial.println(potVal);
    delay(sec);
   }
   digitalWrite(red,LOW);

}
