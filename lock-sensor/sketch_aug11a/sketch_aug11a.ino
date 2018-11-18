#include <Servo.h>
Servo myServo;

const int sensor = A0;
const int switchPin = 2;
const int greenLed = 3;
const int yellowLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;

int numberOfKnocks = 0;
void setup() {
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("Unlocked!");
}




void loop() {
  if(locked == false){
    switchVal = digitalRead(switchPin);

    if(switchVal == HIGH){
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("LOCKED");
      delay (1000);
      }
    }

    if(locked == true){
knockVal = analogRead(sensor);

if(numberOfKnocks < 3 && knockVal > 0){
  if(checkForKnock(knockVal) == true){
    numberOfKnocks++;
}
Serial.print(3-numberOfKnocks);
Serialprintln("more knocks remaining.");
    }
  }

if(numberOfKnocks >= 3){
  locked = false;
  myServo.write(0);
  delay(20);
  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed,LOW);
  Serial.println("the servo is unlocked");
    }
  }
}


  }

  
  boolean checkForKnock(int value){
  if(value > quiteKnock && value < loudKnock){
    digitalWrite(yellowLed, HIGH);
    delay(50)
    digitalWrite(yellowLED, LOW);
    Serial.print("valid knock of value");
    Serial.println(value);
    return false;
    }
