#include <ESP8266WiFi.h>

// Replace with your Wi-Fi credentials
const char* ssid = "Your_Hotspot_SSID"; // your hotspot name.
const char* password = "Your_Hotspot_Password"; // your hotspot password.

void setup() {
  Serial.begin(115200); // Start serial communication
  delay(10);

  // Connecting to Wi-Fi
  Serial.println();
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); // This will print the IP address of the "ESP-8266".
}

void loop() {
  // Keep the program running
}