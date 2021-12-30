//count from 0 to 256
//same circuit as shigft register

int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

//set up hexadecimal(turning all 8 LEDS on)
//byte LEDs=0xFF; // 11111111
byte LED = 0b00000000;
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
  shiftOut(dataPin,clockPin,LSBFIRST, LED);
  digitalWrite(latchPin,HIGH);
  delay(dt);
  Serial.println(LED,BIN);
  LED = LED + 1;
  
}
