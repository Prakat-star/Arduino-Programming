#define TOUCH_PIN T0      // GPIO 4
#define LED_PIN 23

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int touchValue = touchRead(TOUCH_PIN);

  Serial.println(touchValue);

  // Adjust threshold if needed
  if (touchValue < 25) {
    digitalWrite(LED_PIN, HIGH);   // Touch detected
    
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(50);
}