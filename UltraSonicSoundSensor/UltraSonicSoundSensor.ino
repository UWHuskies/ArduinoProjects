int echoPin = 11;
int triggerPin = 12;
int travelTime;

int dt = 25;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echoPin,INPUT);
  pinMode(triggerPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(dt);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(dt);
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(dt);

  //parameters: the pin when the pulse is out HIGH or LOW pin 
  // returns The length of the pulse (in microseconds) or 0 if no pulse started before the timeout.
  travelTime = pulseIn(echoPin,HIGH);
  delay(dt);
  Serial.print("Time : "); //microseconds
  Serial.println(travelTime); 
}
