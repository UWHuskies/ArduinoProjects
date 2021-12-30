#include <LiquidCrystal.h>

// global variables and objects
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

int dt = 1000;
//setup lcd pins
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


float FirstNum;
float SecondNum;
String op;
float ans;
void setup() {
  // put your setup code here, to run once:
  
  // lcd size: 16 columns and 2 rows
  //lcd.begin(columns,rows);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("First Number");
  while(Serial.available() == 0){
  }
  FirstNum = Serial.parseFloat();
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Second Number");
  while(Serial.available() == 0){
  } 
   SecondNum = Serial.parseFloat();
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Operator");
  while(Serial.available() == 0){
  }
  op = Serial.readString();
  lcd.clear();
  if (op == "+") {
    ans = FirstNum + SecondNum;
  } else if (op == "-") {
    ans = FirstNum - SecondNum;
  } else if (op == "*") {
    ans = FirstNum * SecondNum;
  } else if(op == "/") {
    ans = FirstNum / SecondNum;
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(FirstNum);
  lcd.print(op);
  lcd.print(SecondNum);
  lcd.print(" = ");
  lcd.print(ans);
  delay(5000);
  lcd.clear();
}
