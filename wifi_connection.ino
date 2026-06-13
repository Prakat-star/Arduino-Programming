#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_AP);

  bool ok = WiFi.softAP("MyESP32", "12345678");

  if (ok) {
    Serial.println("WiFi started!");
    Serial.println(WiFi.softAPIP());
  }
}

void loop() {
}