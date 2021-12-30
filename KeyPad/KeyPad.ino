 
#include <Keypad.h> 
//4 rows on keypad
const byte ROWS = 4;
//4 columns on keypad
const byte COLUMNS = 4;

char hexKey[ROWS][COLUMNS] = { 
 {'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'} };

byte rowPins[ROWS] = {9,8,7,6};//connect to row pinouts
byte colPins[COLUMNS] = {5,4,3,2};//connect to column pinout

Keypad customKeypad = Keypad(makeKeymap(hexKey),rowPins,colPins,ROWS,COLUMNS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();
  //check if the key is true
  if(customKey) {
    Serial.println(customKey);
  }

}
