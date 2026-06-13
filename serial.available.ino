void setup() {
  Serial.begin(9600);
}

void loop() {
  int bytesWaiting = Serial.available();

  Serial.println(bytesWaiting);

  delay(1000);
}