
int lightPen = A2;
int dv = 250;
int buzz = 13;


void setup() {
  // put your setup code here, to run once:
  pinMode(lightPen,INPUT);
  Serial.begin(9600);
  pinMode(buzz, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int lightVal = analogRead(lightPen);
  Serial.println(lightVal);
  delay(dv); 
 
  int buzzTime = (9./500.)*lightVal -(9.*200./500.)+1.;
  digitalWrite(buzz,HIGH);
  delay(buzzTime);
  digitalWrite(buzz,LOW);
  delay(buzzTime);
 
}
