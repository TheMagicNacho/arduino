const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9; 

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);

}

void loop() {
  digitalWrite(controlPin1, HIGH);
  digitalWrite(controlPin2, LOW); 
  delay(3000);            // waits for a second
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, HIGH); 
  delay(3000);            // waits for a second
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, LOW); 
  delay(1000);            // waits for a second

}
