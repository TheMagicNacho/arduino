int switchState = 0;
void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}
void loop() {
  switchState = digitalRead(2);
  if (switchState == 0) {
    // if the button is not pressed then...
    digitalWrite(3, 1); // Green LED
    digitalWrite(4, 1); //blue
    digitalWrite(5, 0); //red
      delay(250);
    digitalWrite(3, 1); // Green LED
    digitalWrite(4, 0); //blue
    digitalWrite(5, 0); //red
      delay(250);   
  }
  else {
    ///OR if the button is pressed then...
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 1);
  delay(90);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
  delay(90);
      digitalWrite(4, 1);
    digitalWrite(5, 1);
  delay(90);
  }
}
