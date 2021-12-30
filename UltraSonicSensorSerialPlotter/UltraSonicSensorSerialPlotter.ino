int echoPin = 11;
int triggerPin = 12;
float travelTime;
float distancetravel;
float targetDistance; 

int dt = 500;
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
  //speed of ultrasound light is the 760 mph
  // distancetravel is the distance there and back (not the distance from the object)
  distancetravel = 760.0 * 63360.0 * travelTime / 3.6E+9;
  targetDistance =  distancetravel / 2.0;


  //plot multiple graphs use a comma to space them out
  // each Serial.print is its own channel and println ends distance  over again
  //only a println at the end of all the channels
  Serial.print(0); // plot y=0 starting of the channels
  Serial.print(",");
  Serial.print(targetDistance);
  Serial.print(",");
  Serial.println(10); // y=10,  end all of the channels 
}
