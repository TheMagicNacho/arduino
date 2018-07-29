const int onSwitch = 5;
const int polaritySwitch = 4;
const int speedSwitch = A0;

const int controlPin1 = 2;
const int controlPin2 = 3;
const int powerPin = 9;

int onSwitchState = 0;
int previousOnSwitchState = 0;
int directionState = 0;
int previousDirectionState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;


void setup() {
  pinMode(onSwitch, INPUT);
  pinMode(polaritySwitch, INPUT);
  pinMode(speedSwitch, INPUT);

  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(powerPin, OUTPUT);

  digitalWrite(powerPin,0);

}

void loop() {
  //ASIGN MEMORY VALUES
  // read the on/off switch state for onSwitchStateo
  onSwitchState = digitalRead(onSwitch);
  
  // read teh polarity switch state for directionState
  directionState = digitalRead(polaritySwitch);
  
  // analogue read the speed knob
  motorSpeed = analogRead(speedSwitch) / 4;
  
  // LOGIC

 if (onSwitchState != previousOnSwitchState) {
  onSwitchState == HIGH;
 }
 /*
  if (onSwitchState != previousOnSwitchState) {
    // change the value of motorEnabled if pressed
    if (onSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }
*/
  // if the direction button changed state since the last loop()
  if (directionState != previousDirectionState) {
    // change the value of motorDirection if pressed
    if (directionState == HIGH) {
      motorDirection = !motorDirection;
    }
  }
  
  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  if (motorEnabled == 1) {
    analogWrite(powerPin, motorSpeed);
  } else {
    analogWrite(powerPin, 0);
  }

  previousDirectionState = directionState;

  previousOnSwitchState = onSwitchState;
}
