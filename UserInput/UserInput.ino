
String color = "what light do you want to blink"; 
int red = 7;
int blue = 3;
int green = 8;
int t = 500;
int mixColor = 255;

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  Serial.println(color);
  while (Serial.available() == 0) {
  }
  String userInput = (Serial.readString());
  userInput.toLowerCase();

  if (userInput == "blue") {
    digitalWrite(blue,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    delay(t);
    digitalWrite(blue,LOW);
    delay(t);
  } else if (userInput == "green") {
    digitalWrite(blue,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    delay(t);
    digitalWrite(green,LOW);
    delay(t);
  } else if(userInput == "red"){
    analogWrite(blue,LOW);
    analogWrite(green,LOW);
    digitalWrite(red,HIGH);
    delay(t);
    digitalWrite(red,LOW);
    delay(t);
  } else if(userInput == "cyan"){
    analogWrite(blue,mixColor);
    analogWrite(green,mixColor);
    digitalWrite(red,LOW);
    delay(t);
    } else if(userInput == "magenta"){
    analogWrite(blue,mixColor);
    digitalWrite(green,LOW);
    analogWrite(red,mixColor);
    delay(t);
  } else {
    digitalWrite(blue,LOW);
    analogWrite(green,mixColor);
    analogWrite(red,mixColor);
        delay(t);
  }  
}
//asked user for a number
/*
String msg = "How many blinks:";
int red = 7;
String msg1 = "heelo";
void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  Serial.begin(9600);
}


void loop() {
  
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available() == 0){
  }
  int blinks = Serial.parseInt();
  //float s = Serial.parseFloat();
   //String s1 = Serial.readString();
  for (int i = 1; i <= blinks; i++) {
    digitalWrite(red,HIGH);
    delay(1000);
    digitalWrite(red,LOW);
    delay(1000);
  }
}*/
