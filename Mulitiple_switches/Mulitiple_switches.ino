int but1 = 0;
int but2 = 8;
int light = 10;
int bright = 0;
int buzz = 7;
int t=500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(but1,INPUT);
  pinMode(but2,INPUT);
  pinMode(light,OUTPUT);
  pinMode(buzz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int butVal1 = digitalRead(but1);
  int butVal2 = digitalRead(but2);
  Serial.println(butVal1);
  //delay(2000);
  Serial.println("but2");
  Serial.println(butVal2);
  //delay(2000);
  Serial.println(bright);
  //delay(2000);
  if (butVal1 == 0) {
    bright=bright+ 15;
  }
    if (butVal2 == 0) {
    bright =bright- 5;
  }
  if (bright > 255) {
    bright= 255;
        digitalWrite(buzz,HIGH);
      delay(t);
      digitalWrite(buzz,LOW); 
  }
  
  if (bright > 0) {
    bright = 0;
      digitalWrite(buzz,HIGH);
      delay(t);
      digitalWrite(buzz,LOW); 
  }  
  analogWrite(light,bright);
}
