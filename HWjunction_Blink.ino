// Blinking program
// Author : Selvaraaju Murugesan
// Date   : 13-02-2016

int led=8

;
void setup() {

// Select the Pin mode
 pinMode(led,OUTPUT);

// Set baudrate for Serial port 
 Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
  
  int digital_status;
  
  digitalWrite(led,HIGH);
  delay(100);
  
  digital_status = digitalRead(led);
  Serial.println(digital_status);
  delay(1);
  
  digitalWrite(led,LOW);
  delay(1000);

  digital_status = digitalRead(led);
  Serial.println(digital_status);
  delay(1);
  
}
