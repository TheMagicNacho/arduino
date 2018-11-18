#include <Servo.h>

#define TURN_TIME 175

Servo myservo;

void setup () {
    myservo.attach(6);
    // Initially the servo must be stopped 
    myservo.write(90);
}

void loop() {
    // Start turning clockwise
    myservo.write(0);
    // Go on turning for the right duration
    delay(TURN_TIME);
    // Stop turning
    myservo.write(90);

    // Wait for 12h
    delay(12 * 3600 * 1000);
}
