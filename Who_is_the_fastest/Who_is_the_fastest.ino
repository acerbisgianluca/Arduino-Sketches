const int PLAYER1 = 8;  //DIGITAL PIN 8
const int PLAYER2 = 9;  //DIGITAL PIN 9 
const int LED = 7;      //DIGITAL PIN 7
int cont = 1;
unsigned long start;
unsigned long now;
unsigned long inputLag;

void setup() {
  start = millis();
  pinMode(PLAYER1, INPUT);
  pinMode(PLAYER2, INPUT);
  pinMode(LED, OUTPUT);
  randomSeed(1);
  Serial.begin(9600);
  Serial.println("\nWHO IS THE FASTEST?");
}

void loop() {
  long waiting = random(4000, 6000);
  bool victory = false;
  Serial.print(cont);
  Serial.print(" Winner: ");
  digitalWrite(LED, LOW);
  while (!victory) {
    now = millis();
    if (now - start > waiting) {
      digitalWrite(LED, HIGH);
      while (!victory) {
        if (digitalRead(PLAYER1) == HIGH) {
          Serial.print("Player 1\tDelay: ");
          inputLag = millis() - now;
          Serial.println(inputLag);
          victory = true;
        }
        else if (digitalRead(PLAYER2) == HIGH) {
          Serial.print("Player 2\tDelay: ");
          inputLag = millis() - now;
          Serial.println(inputLag);
          victory = true;
        }
      }
      start = millis();
    }
  }
  cont++;
}
