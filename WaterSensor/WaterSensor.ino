

int adc_id = A0;

void setup()
{
  Serial.begin(9600);
  Serial.println("water level: ");
}
void loop()
{
    int value = analogRead(adc_id); // get adc value

    if(value <= 100) {
      Serial.println("Empty");
    } else if (value > 100 && value <= 300) {
      Serial.println("Low");
    } else if (value > 300 && value <= 330) {
      Serial.println("Medium");
    } else if (value > 330) {
      Serial.println("High");
    } else {
      Serial.print("No reading");
    }
    delay(1000);
    
}
