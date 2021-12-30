#include <IRremote.h>
int IRpin = 9;

//setup the object with the pin used
IRrecv IR(IRpin);

//recieve a signal from infrared module chip
decode_results results;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // start the infrared module chip
  IR.enableIRIn();
  Serial.println("hi");
}

void loop() {
  // put your main code here, to run repeatedly:

  //& - calling the value that the cmd function returns   
  if(IR.decode(&results)) {
  
  //need time between the buttons to get a good results
  Serial.print("numb: ");
  Serial.println(results.value,HEX);
  delay(100);
  IR.resume();
  }
}
