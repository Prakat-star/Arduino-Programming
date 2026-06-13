void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {

    int value = Serial.parseInt();

    Serial.print("Received: ");
    Serial.println(value);
  }
}