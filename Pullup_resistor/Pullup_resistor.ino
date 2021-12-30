
int red = 13;
int switch1 = 8;
int LEDstate = 0;
int oldBut = 1;
int newBut;
void setup() {
  // put your setup code here, to run once:
pinMode(red,OUTPUT);
pinMode(switch1,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  newBut = digitalRead(switch1);
  Serial.println(newBut);
  delay(100);
  if (oldBut == 0 && newBut == 1) {
    if (LEDstate == 1) {
    digitalWrite(red,LOW);
    LEDstate = 0;
    } else {
    digitalWrite(red,HIGH);
    LEDstate = 1;
    }
  }
  oldBut = newBut;
  
}
