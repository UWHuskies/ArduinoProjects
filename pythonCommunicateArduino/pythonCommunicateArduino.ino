int sum;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  Serial.print("Current: ");
  Serial.println(sum);
  // put your main code here, to run repeatedly:
  sum+=1;
  delay(1000);
}
