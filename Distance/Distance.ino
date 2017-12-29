const int triggerPort = 7;  //DIGITAL PIN 7
const int echoPort = 8;     //DIGITAL PIN 8
 
void setup() {
  pinMode(triggerPort, OUTPUT);
  pinMode(echoPort, INPUT);
}
 
void loop() { 
  digitalWrite(triggerPort, LOW);
  digitalWrite(triggerPort, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPort, LOW);
   
  long period = pulseIn(echoPort, HIGH);
   
  long distance = 0.034 * period / 2;
  
  if( period > 38000 ){
    Serial.println("Out of reach!");
  }
  else{ 
    Serial.print(distance); 
    Serial.println(" cm");
  }
  
  delay(1000);
}
