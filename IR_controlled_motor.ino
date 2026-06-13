#define IR_SENSOR 34

#define IN1 26
#define IN2 27
#define ENA 14

void setup() {

  Serial.begin(115200);

  pinMode(IR_SENSOR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {

  int sensorValue = digitalRead(IR_SENSOR);

  Serial.println(sensorValue);

  // BLACK detected
  if(sensorValue == LOW) {

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    analogWrite(ENA, 200);

    Serial.println("Motor ON");
  }

  // WHITE detected
  else {

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    analogWrite(ENA, 0);

    Serial.println("Motor OFF");
  }

  delay(100);
}