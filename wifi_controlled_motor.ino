#include <WiFi.h>
#include <WebServer.h>

#define IN1 26
#define IN2 27
#define ENA 14

WebServer server(80);

void rootPage() {
  server.send(200, "text/html",
    "<h1>ESP32 Motor Control</h1>"

    "<a href='/forward'>"
    "<button style='width:200px;height:60px;'>FORWARD</button>"
    "</a><br><br>"

    "<a href='/backward'>"
    "<button style='width:200px;height:60px;'>BACKWARD</button>"
    "</a><br><br>"

    "<a href='/stop'>"
    "<button style='width:200px;height:60px;'>STOP</button>"
    "</a>");
}

void motorForward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENA, 200);

  server.send(200, "text/plain", "Motor Forward");
}

void motorBackward() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENA, 200);

  server.send(200, "text/plain", "Motor Backward");
}

void motorStop() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  analogWrite(ENA, 0);

  server.send(200, "text/plain", "Motor Stopped");
}

void setup() {

  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  WiFi.softAP("MyESP32", "12345678");

  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", rootPage);

  server.on("/forward", motorForward);
  server.on("/backward", motorBackward);
  server.on("/stop", motorStop);

  server.begin();
}

void loop() {
  server.handleClient();
}