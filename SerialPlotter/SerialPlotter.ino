//plot sin and cos function

float cosGraph;
float sinGraph;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //bounds of each plot and repeat them
  for (float j = 0; j < 2*3.14159; j=j+0.01) {
    cosGraph = cos(j);
    sinGraph = sin(j);

    //y plot of the function
    Serial.print(cosGraph);
    Serial.print(","); //need sperator between each data
    Serial.println(sinGraph); //println end the plotted data
  }

   
}
