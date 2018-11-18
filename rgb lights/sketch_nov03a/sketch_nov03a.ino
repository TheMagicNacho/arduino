int green = 9;
int yellow = 7;
int red = 5;
int brightnessr = 0; //intilal LED brightnes
int brightnessy = 0; //intilal LED brightnes
int resolution = 5;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  analogWrite(green, brightnessr);
  brightnessr = brightnessr + resolution; // fade math
  if (brightnessr <= 0 || brightnessr >= 255) {
    resolution = -resolution;
    }
  delay(30);
  /*
    analogWrite(yellow, brightnessy);
      brightnessy = brightnessy + resolution; // fade math
  if (brightnessy <= 0 || brightnessy >= 255) {
    resolution = -resolution;
    }
  delay(30);
 // analogWrite(green, brightness);
 */
 
}
