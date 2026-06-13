#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int LED = 23;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  Serial.begin(115200);

  SerialBT.begin("ESP32_BT");

  Serial.println("Bluetooth ready");
}

void loop() {
  if (SerialBT.available()) {
    String msg = SerialBT.readStringUntil('\n');
    msg.trim();

    Serial.print("Received: ");
    Serial.println(msg);

    if (msg == "ON") {
      digitalWrite(LED, HIGH);
      SerialBT.println("LED ON");
    }
    else if (msg == "OFF") {
      digitalWrite(LED, LOW);
      SerialBT.println("LED OFF");
    }
    else {
      SerialBT.println("Invalid Command");
    }
  }
}