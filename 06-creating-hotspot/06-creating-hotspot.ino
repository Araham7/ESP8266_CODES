#include <ESP8266WiFi.h>

// Replace with your desired SSID and password
const char* ssid = "Name-of-the-hotspot-that-u-want-to-create"; // Your hotspot name
const char* password = "enter-the-passwrd-that-u-want-to-your-hotspot"; // Your hotspot password

// Variable to track the last execution time
unsigned long previousMillis = 0;
// Interval between updates in milliseconds
const unsigned long interval = 250;

// Function to check if the interval has passed
bool hasIntervalPassed() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Save the current time
    return true; // Interval has passed
  }
  return false; // Interval has not passed
}

// Function to log the number of connected devices
void logConnectedDevices() {
  Serial.print("Number of devices is = ");
  Serial.println(WiFi.softAPgetStationNum());
}

void setup() {
  Serial.begin(9600);
  WiFi.softAP(ssid, password); // Start the hotspot
  Serial.print("Device IP is = ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Call the interval-checking function
  if (hasIntervalPassed()) {
    // Call the separate function to log connected devices
    logConnectedDevices();
  }
}