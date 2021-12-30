//left and right circular shift
//same circuit as shift register

int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte myBytes = 0b00000001;
int dt = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //allow for data to pass to chip
  digitalWrite(latchPin,LOW);
 /* shiftOut parameters:
  * 1. what pin does the ardruino pin go into, 
  * 2. clockPin which pin to synchronize data
    3. LSBFIRST - least significant byte first
       MSBFIRST - most significant byte first
    4. data package in hexadecimal
    */
  shiftOut(dataPin,clockPin,LSBFIRST,  myBytes);
  digitalWrite(latchPin,HIGH);
  delay(dt);
  Serial.println(myBytes, BIN);

  //only allow the right or left shifitng or cancellation will occur  
  //circular left shift   
  myBytes = myBytes / 128  + myBytes * 2;
 //circular right shift   
 // myBytes = myBytes * 128  + myBytes / 2;
}
