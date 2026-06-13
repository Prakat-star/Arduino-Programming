int led = 4;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {

    int brightness = Serial.parseInt();

    brightness = constrain(brightness, 0, 255);
    //constrain() is an Arduino utility function that limits a value to stay within a specified range.

    analogWrite(led, brightness);
    delay(10000);
    Serial.print("Brightness = ");
    Serial.println(brightness);
  }
}