#define IR_SENSOR 2
#define LED 9

void setup() {
  pinMode(IR_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int obstacle = digitalRead(IR_SENSOR);

  if (obstacle == HIGH) {
    // Object detected → blink LED
    digitalWrite(LED, HIGH);
  
  }
  else {
    // No object → LED OFF
    digitalWrite(LED, LOW);
  }
}