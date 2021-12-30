int PotPin = A2;
float LEDVal =0;
int outPin = 11; //analogWrite (dimmer)
int reader;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //communicate with serial mobitor
  pinMode(outPin,OUTPUT); //setup LED
  pinMode(PotPin,INPUT); //setupPOT input
 

}

void loop() {
  // put your main code here, to run repeatedly:
  reader = analogRead(PotPin);
  LEDVal = (255./1023.)*reader; //255 equals 5V
 analogWrite(outPin,LEDVal); // can a float for input too
  Serial.println(LEDVal);
  delay(500);
}
