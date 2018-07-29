#include <Servo.h>

Servo myFucko;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  myFucko.attach(9);

  Serial.begin(9600);

}

void loop() {
 potVal = analogRead(potPin);
 Serial.print("potVal: ");
 Serial.print(potVal);

angle = map(potVal, 0, 1023, 0, 179);
Serial.print(", angle: ");
Serial.println(angle);

myFucko.write(angle);
delay(15);

}
