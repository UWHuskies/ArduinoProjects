
//read Voltage across a resistor
//circuit voltage in series with 2 resistors
// also measured the pentiometer voltage reading(only prntiometer in the circuit)
 
int redPin = A2;
int readVal;
float V2 = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(redPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

readVal = analogRead(redPin); //return an integer
Serial.println(readVal);
V2 = (5./1023.)*readVal;
Serial.println(V2);
delay(500);
}//
