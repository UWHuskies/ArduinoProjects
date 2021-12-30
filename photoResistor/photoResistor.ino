
int lightPen = A2;
int dv = 250;
int green = 10;
int red = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPen,INPUT);
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
 int lightVal = analogRead(lightPen);
 Serial.println(lightVal);
 delay(dv); 
 if (lightVal > 500) {
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
 } 
 if (lightVal < 200) {
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
 } 
}
