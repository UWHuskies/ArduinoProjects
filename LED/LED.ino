
//Turn a LED on and off
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH); //turn on
  delay(1000);
  digitalWrite(13,LOW);// turn off
    delay(1000);
}
