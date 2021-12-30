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
void setup() {
  // put your setup code here, to run once:
  
  // lcd size: 16 columns and 2 rows
  //lcd.begin(columns,rows);
  lcd.begin(16,2);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("watch count");
  for(int j = 1; j <= 10; j++) {
    lcd.setCursor(0,1);
    lcd.print(j);
    // need time to delay to see the display
    delay(dt);
  }
    // clear display
    lcd.clear();

}
