#include "pitches.h"

const unsigned int TRIG_PIN=2;
const unsigned int ECHO_PIN=3;
const unsigned int BAUD_RATE=9600;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(BAUD_RATE);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  

 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int dist = duration/29/2;
 if(duration==0){
   Serial.println("Warning: no pulse from sensor");
   } 
  else{
      Serial.print("Distance: ");
      Serial.print(dist);
      Serial.print(" cm");

  }

int pitch = map(dist, 40, 3, 131, 523);

if(dist > 40){
  noTone(8);
}
else{
  tone(8, pitch, 8);
}
 delay(10);
 }
