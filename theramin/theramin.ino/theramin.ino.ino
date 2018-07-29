
int sensorLow = 1023;
int sensorHigh = 0;
int sensorValue = analogRead(A0);

void setup() {
Serial.begin(9600);

  // Make the LED pin an output and turn it on
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  
  while (millis() < 5000) {

    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
 
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  
  Serial.print ("sensorValue: ");
  Serial.println (sensorValue);

  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  tone(8, pitch, 20);

  delay(10);
}
