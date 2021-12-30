
//upload button - will transfer the code into the adruino (if adruino is plugged into computer)
//verify - check code

const int ledPin = 13; // reference pin 13
// integer range from values between -32,000 to 32,000

/*
//global variable - variables that can be used in all function 
const - never change varible
int - integer variable
*/
// Initiate or set up values 
void setup() {
  // put your setup code here, to run once:
  // talk to serial monitor to set the port to 690 character per second (standard)
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT); // change the value(turn on and off) of the ledPin

  //countDown(5);

  // while loop for countDown function
  int j = 3;
  while (j > 0) {
    Serial.print(j);
    Serial.print(", ");
    j--;
  }
  Serial.print("Go....\n");
  Serial.print("3.1111111 + 4.111111 = ");
  Serial.println(addFloat(3.1111111,4.1111111),8);
  Serial.println(addDouble(3.1111111,4.1111111),8); 
  // print digit to 8 decimal places
  // double/float are only precise to 6 digits


  //Data Types
  bool canVote = true;
  Serial.print("Can I vote?");
  //? : - ternary operator
  Serial.println(((canVote == true) ? "Yes" : "No"));  

  //characters - single quotes
  char letD = 'd';
  Serial.println(letD);

  /*Other data types values range
   * byte: 0 - 255
   * // unsigned increase the max value for integer
   * unsigned int: 0 - 65535 
   * long : -2,147,483,648 - -2,147,483,648
   * unsigned long : 0
   */
   
}





void loop() {
  // put your main code here, to run repeatedly:
  static int delayPeriod = 100; 
  //static initaize it one time and doesn't run it after it goes through a loop
  static int countDir = 1;

  
  digitalWrite(ledPin,HIGH); //turn on light
  delay(delayPeriod);
  digitalWrite(ledPin,LOW); // turn off light
  countDir = checkDirChange(delayPeriod, countDir);

  delayPeriod += 100 * countDir;
  Serial.print("New Wait Time: ");
  Serial.println(delayPeriod);
}

// a function that return a integer
int checkDirChange(int timePeriod, int count) {
  //|| - or
  //&& - and
  if ((timePeriod == 1000) || (timePeriod == 0)) {
    count *= -1; // direction = direction * -1

    if (count < 0) { // delay period is 0 or greater 
      Serial.println("Going Down");
    } else {
      Serial.println("Going Up");
    }
  }
  return count;
}


// for loop
void countDown(int max) {
  // < > <= >=
  for (int i = max; i > 0; i--) {
    Serial.print(i);
    Serial.print(", ");
  }
  Serial.print("Go....\n"); //\n  - new line
}  


// integer -no decimal values
// float/doubles - numbers with decimal values (decimal and float are same)

float addFloat(float num1, float num2) {
  return num1 + num2;
}

double addDouble(double num1, double num2) {
  return num1 + num2;
}
