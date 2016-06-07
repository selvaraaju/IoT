// Read voltages from LM35 sensor
// Author : Selvaraaju Murugesan
// Date   : 13-02-2016

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);


  // Set the analog reference voltage to 1.1V
  analogReference(1.1);
}


void loop() {
  // read the input on analog pin 0:
  
  int reading, temp;
  
  reading = analogRead(A0);
  temp = reading / 9.31;
  
  // print out the value you read:
  
  Serial.println(temp);
  delay(1000);        // delay in between reads for stability
}
