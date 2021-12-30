int buzz = 12;
int pot = A2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzz,OUTPUT);
  pinMode(pot,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(pot);
  int toneVal = (9940./1023.)*value+60;
    digitalWrite(buzz,HIGH);
    delayMicroseconds(toneVal);
    digitalWrite(buzz,LOW);
     delayMicroseconds(toneVal);
   
 
}
