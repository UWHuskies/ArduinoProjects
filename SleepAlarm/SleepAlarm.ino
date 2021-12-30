
#include "math.h"
int blue = 12;
int red = 11;
int buzzer = 8;
int startPin = 5;
int stopPin = 6;
int resetPin = 7;
int dt = 1000;
float timer = 0.0; 
bool resetIndicator;
int stopVal;

int longtime = 3000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(startPin,INPUT);
  pinMode(stopPin,INPUT);
  pinMode(resetPin,INPUT);
  digitalWrite(startPin,HIGH);
  digitalWrite(stopPin,HIGH);
  digitalWrite(resetPin,HIGH);
}

void loop() {
  resetIndicator = false;
  Serial.println("How long in MINUTES do you want to set the timer: " );
  
  while(Serial.available() == 0) {
    
  }
  timer = Serial.parseFloat();
  Serial.print("Timer set at: ");
  Serial.print(timer);
  Serial.println(" minutes");
  delay(dt);
  Serial.println("");

  Serial.println("Press the Start or Reset button");
  Serial.println("hold down the stop button to stop");
  int startVal = digitalRead(startPin);
  int ResetVal = digitalRead(resetPin); 
  while ((startVal != 0 && ResetVal == 1) || (startVal == 1 && ResetVal != 0) ) {
      startVal = digitalRead(startPin);
      ResetVal = digitalRead(resetPin);
  }

  if (ResetVal == 0) {
    timer = 0.0;
    Serial.println("Timer Reset");
    Serial.println("");
    delay(dt);
  } else if (startVal == 0 && timer != 0.0) {
    digitalWrite(startPin,HIGH);
    digitalWrite(resetPin,HIGH);
    for (float i = timer; i > 0.0; i-=(1.0 / 60.0)) {
      if (resetIndicator == false) {
        Serial.println(timer);
        timer = timer - (1.0 / 60.0);
        delay(dt);
        stopVal = digitalRead(stopPin);
        if (stopVal == 0) {
          Serial.println("press start to continue or press Reset button");
          while ((digitalRead(startPin) != 0 && digitalRead(resetPin) == 1) || (digitalRead(startPin) == 1 && digitalRead(resetPin) != 0) ) {
            startVal = digitalRead(startPin);
            ResetVal = digitalRead(resetPin);
          }
          if (ResetVal == 0) {
              timer = 0.0;
              Serial.println("Timer Reset");
              Serial.println("");
              resetIndicator = true;
          }
        }
      }
    }
      if (roundf(timer) == 0.00 && ResetVal == 1 && stopVal == 1) {
          Serial.println("time to wake up");
          for (int i = 0; i < 10;i++) { 
            digitalWrite(buzzer,HIGH);
            digitalWrite(blue,HIGH);
            digitalWrite(red,LOW);
            delay(dt/2);
            digitalWrite(blue,LOW);
            digitalWrite(buzzer,LOW);
            digitalWrite(red,HIGH);
            delay(dt/2);
         }   
         digitalWrite(red,LOW);    
         Serial.println("");
      }
       }
}
