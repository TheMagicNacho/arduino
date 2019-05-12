const int azmX = 2;
const int azmY = 3;

const int controlPin3 = 5;
const int controlPin4 = 4;

const int potPin = A0;
const int enablePin = 9; 


int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  Serial.begin(9600);
  
  pinMode(azmX, OUTPUT);
  pinMode(azmY, OUTPUT);

  pinMode(controlPin3, OUTPUT);
  pinMode(controlPin4, OUTPUT);
  
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);

}

void loop() {

  int tiltAng = analogRead(A0);
  Serial.println(tiltAng);
  delay(3); 
  
  digitalWrite(azmX, LOW);
  digitalWrite(azmY, LOW);

if (200 >= tiltAng) {
    digitalWrite(controlPin3, LOW);
    digitalWrite(controlPin4, HIGH);
}
else if (tiltAng >= 210 && tiltAng <= 700) {
    digitalWrite(controlPin3, LOW);
    digitalWrite(controlPin4, LOW);
}
else {
    digitalWrite(controlPin3, HIGH);
    digitalWrite(controlPin4, LOW);
}



}
