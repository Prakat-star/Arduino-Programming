const byte RED_LED = 4;
const byte YELLOW_LED = 3;
const byte GREEN_LED = 2;

void setLights(bool red, bool yellow, bool green) {
  digitalWrite(RED_LED, red);
  digitalWrite(YELLOW_LED, yellow);
  digitalWrite(GREEN_LED, green);
}

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  setLights(LOW, LOW, HIGH);   // Green
  delay(5000);

  setLights(LOW, HIGH, LOW);   // Yellow
  delay(2000);

  setLights(HIGH, LOW, LOW);   // Red
  delay(5000);
}