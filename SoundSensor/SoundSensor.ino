int LED = 5;
int buttonpin = 2;
int val;
int analog = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  pinMode(LED,OUTPUT);
  pinMode(buttonpin,INPUT);
  //pinMode(analog,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(buttonpin);
  Serial.println(val);
  //int d = analogRead(analog);
 // Serial.println(d);
  if (val == 0) {
   digitalWrite(LED,HIGH);
  } else {
    digitalWrite(LED,LOW);
  }
      delay(1000);
}
