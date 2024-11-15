/*
*
* (1). GitHub link to install the ESP8266Ping library: https://github.com/dancol90/ESP8266Ping
*
* (2). This is an example code to check whether the ESP8266 connected to the hotspot has internet connectivity.
*
*/





#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>

// WiFi credentials
const char* ssid = "Your-hotspot-name";      // Replace with your WiFi SSID
const char* password = "Your-hotspot-password";  // Replace with your WiFi password

// Host to ping (Google DNS server for internet check)
const char* host = "8.8.8.8";  // Google's public DNS server

void setup() {
  Serial.begin(9600);
  Serial.println("\nESP8266 Internet Connectivity Check");

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // Print the local IP
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check internet connectivity every 5 seconds
  checkInternetConnectivity();
  delay(5000);  // Delay of 5 seconds
}

// Function to check internet connectivity by pinging a host
void checkInternetConnectivity() {
  Serial.println("\nPinging the host...");
  if (Ping.ping(host, 4)) {  // Ping 4 times
    Serial.println("Ping successful! Internet is connected.");
  } else {
    Serial.println("Ping failed! No internet connectivity.");
  }
}