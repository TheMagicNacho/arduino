
const int sensorPin = A0;
//const float baselineTemp = 20.0;
int sensorMin = 2000;        // minimum sensor value
int sensorMax = 100;           // maximum sensor value

void setup() {

  Serial.begin(9600);
  
  int sensorVal = analogRead(sensorPin);

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

    // turn on LED to signal the start of the calibration period:
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);

  while (millis() < 9000) {
    sensorVal = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorVal > sensorMax) {
      sensorMax = baselineTemp;
    }

    // record the minimum sensor value
if (sensorVal < sensorMin) {
      sensorMin = baselineTemp;
    }
  }


  digitalWrite(3, LOW);
  
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  if (temperature < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  
  else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, 1);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
  }
  else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 0);
  }
  else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
  }
  delay(1);
}
