 
#include <Keypad.h> 
#include <Servo.h>
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

Servo servo;
int servoPin = 11;

char password[4] = ""; 
char correct[] = "7845";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(0);
  Serial.println("input a 4 digit password");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();
  //check if the key is true
  if(customKey) {
    if (strlen(password) <= 4) {
    strncat(password,&customKey,1);
    Serial.print("Current Password: ");
    Serial.println(password);                             
    }
    if (strlen(password) == 4 ) {
      if (strcmp(correct,password) == 0) {
        Serial.println("correct");
        servo.write(180);
        delay(8000);
        servo.write(0);
      } else {
      Serial.println("Incorrect, Retype Another password");   
      }
      Serial.println(""); 
      memset(password,0, 4);
    }
  }
}
