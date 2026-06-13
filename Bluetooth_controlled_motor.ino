#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define IN1 26
#define IN2 27
#define ENA 14

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  SerialBT.begin("chalne");
  Serial.println("Bluetooth Started");
}

void loop() {

  if (SerialBT.available()) {

    char cmd = SerialBT.read();

    if (cmd == 'F') {
      // Forward
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 200);
    }

    else if (cmd == 'B') {
      // Backward
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, 200);
    }

    else if (cmd == 'S') {
      // Stop
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 0);
    }
  }
}