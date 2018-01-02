#define SIGPORT 10
 
void setup() {
  Serial.begin(9600);
}
 
void loop() { 
  pinMode(10, OUTPUT);
  digitalWrite(SIGPORT, LOW);
  digitalWrite(SIGPORT, HIGH);
  delayMicroseconds(10);
  digitalWrite(SIGPORT, LOW);
  pinMode(10, INPUT);
   
  long period = pulseIn(SIGPORT, HIGH);
   
  long distance = period / 29 / 2;
  
  if( period > 38000 ){
    Serial.println("Out of reach!");
  }
  else{ 
    Serial.print(distance); 
    Serial.println(" cm");
  }
  
  delay(1000);
}
