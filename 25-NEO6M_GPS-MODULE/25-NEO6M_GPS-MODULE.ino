#include <SoftwareSerial.h>  // Library for software serial communication
#include <TinyGPS++.h>       // Library for parsing GPS data

// Pin definitions for ESP8266
#define RX_PIN D2 // GPS TX to ESP8266 RX
#define TX_PIN D1 // GPS RX to ESP8266 TX

SoftwareSerial ss(RX_PIN, TX_PIN);  // Create software serial object

TinyGPSPlus gps; // Create TinyGPS++ object

void setup() {
  Serial.begin(115200);  // Initialize serial monitor for debugging
  ss.begin(9600);        // Initialize software serial port for GPS communication

  Serial.println("GPS Module Initialized");
}

void loop() {
  while (ss.available() > 0) {  // If data is available from GPS
    gps.encode(ss.read());  // Feed GPS data into TinyGPS++
    
    if (gps.location.isUpdated()) {  // If new location data is available
      Serial.print("Latitude= ");  
      Serial.print(gps.location.lat(), 6);  // Print latitude
      Serial.print(" Longitude= ");  
      Serial.println(gps.location.lng(), 6);  // Print longitude
    }
  }
}
