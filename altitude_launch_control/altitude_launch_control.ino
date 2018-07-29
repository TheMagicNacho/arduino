// named constants for the switch and motor pins
const unsigned int trigPin = 2; // sensor
const unsigned int echoPin = 3; // sensor
const int outputPin =  9; // control transistor
const unsigned int BAUD_RATE=9600; // define sample rate

// Define Pins
void setup() {
  pinMode(outputPin, OUTPUT); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
// initilize sample rate
  Serial.begin(BAUD_RATE);
}

  // loop sonar functions
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 const unsigned long duration= pulseIn(echoPin, HIGH);
 
 // convert echo into distance
 int dist = duration/29/2;  
 if(duration==0){
 // print it
   Serial.println("Warning: no pulse from sensor");
   } 
  else{
      Serial.print("Distance: ");
      Serial.print(dist);
      Serial.print(" cm");
      Serial.println();
  }
if(dist < 20){
    digitalWrite(outputPin, LOW);
}
else{
    digitalWrite(outputPin, HIGH);
}
 delay(10);
 }
  
