int buttonPin = 2;
int buttonVal;
int dt = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);

  //pullup button -reads a one with pushing the button
  digitalWrite(buttonPin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //pushing down on the button reads a 0
  buttonVal = digitalRead(buttonPin);
  Serial.print("button Val: ");
  Serial.println(buttonVal);
  delay(dt);
  
}
