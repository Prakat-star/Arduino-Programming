const int redLED = 12;
const int yellowLED = 9;
const int greenLED = 7;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // Green light
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  delay(5000);

  // Yellow light
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(2000);

  // Red light
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  delay(5000);


  // Back to Green
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
}