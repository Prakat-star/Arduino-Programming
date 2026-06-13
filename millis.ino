const int ledPin = 13;

unsigned long previousMillis = 0;
const unsigned long interval = 1000;  // 1 second

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    digitalWrite(ledPin, !digitalRead(ledPin)); // Toggle LED
  }

  // Other code can run here at the same time
}