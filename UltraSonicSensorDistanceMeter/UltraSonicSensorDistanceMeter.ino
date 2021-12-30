#include <LiquidCrystal.h>
int rs = 7;
int en= 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int echoPin = 3;
int triggerPin = 2;
float travelTime;
float distancetravel;
float targetDistance; 

int dt = 500;

//if run out of digital pins, use analog pins
int pushButton = A0;
int buttonVal;

int NumMeas = 500;
float avgMeas;
float distance = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echoPin,INPUT);
  pinMode(triggerPin,OUTPUT);
  lcd.begin(16,2);
  pinMode(pushButton,INPUT);
  digitalWrite(pushButton,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Place Target");
  lcd.setCursor(0,1);
  lcd.print("Press Button");
  
  buttonVal = digitalRead(pushButton); 
  while (buttonVal == 1) {
    buttonVal = digitalRead(pushButton);
  }  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Calculating");
  for (int j = 0; j < NumMeas;j++) { 
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

    distance = distance + targetDistance;
  }
  avgMeas = distance / NumMeas;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Avg. Distance");
  lcd.setCursor(0,1);
  lcd.print(avgMeas);
  lcd.print(" Inches ");
  delay(dt);

  
  Serial.print("Time: ");
  Serial.print(travelTime);
  Serial.print(" Microseconds"); 
  Serial.print(" Distance: ");
  Serial.print(targetDistance); 
  Serial.println(" inches");
}
