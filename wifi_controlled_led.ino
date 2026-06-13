#include <WiFi.h>
#include <WebServer.h>

const int LED = 23;  // afu la use garako pin lekha

WebServer server(80);

void rootPage() {
  server.send(200, "text/html",
    "<h1>ESP32 LED Control</h1>"
    "<a href='/on'><button>ON</button></a><br><br>"
    "<a href='/off'><button>OFF</button></a>");
}

void ledOn() {
  digitalWrite(LED, HIGH);
  //server.send(statusCode, contentType, content);
  server.send(200, "text/plain", "LED ON");
}

void ledOff() {
  digitalWrite(LED, LOW);
  server.send(200, "text/plain", "LED OFF");
}

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);

  WiFi.softAP("MyESP32", "12345678");
  //WiFi.softAP(ssid, pass);
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", rootPage);
  server.on("/on", ledOn);
  server.on("/off", ledOff);

  server.begin();
}

void loop() {
  server.handleClient();
}