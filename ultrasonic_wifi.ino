#include <WiFi.h>

const char* ssid = "ESP32";
const char* password = "123";

// Ultrasonic pins afu la use garako lekha
#define TRIG_PIN 5
#define ECHO_PIN 18

WiFiServer server(80);

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  WiFi.softAP(ssid, password);

  Serial.println("AP Started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());  // usually 192.168.4.1

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    client.readStringUntil('\r');

    long d = getDistance();

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println("Connection: close");
    client.println();

    client.println("<html><h1>ESP32 Ultrasonic (AP Mode)</h1>");
    client.print("<h2>Distance: ");
    client.print(d);
    client.println(" cm</h2></html>");

    client.stop();
  }
}