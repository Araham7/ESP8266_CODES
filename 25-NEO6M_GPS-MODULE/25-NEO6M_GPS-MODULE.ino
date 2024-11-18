/*
Wiring for NEO-6M GPS module and ESP8266 (NodeMCU):
---------------------------------------------------
1. GPS TX (Transmit)  ---> ESP8266 RX (D2 or GPIO4)  
   (GPS module sends data to ESP8266, so connect GPS TX to ESP8266 RX)

2. GPS RX (Receive)  ---> ESP8266 TX (D1 or GPIO5)  
   (ESP8266 sends data to GPS, so connect ESP8266 TX to GPS RX)

3. GPS GND (Ground)  ---> ESP8266 GND  
   (Connect the ground pin of GPS to ESP8266 ground)

4. GPS VCC (Power)  ---> 5V

Ensure that the GPS module is properly powered and the wiring is correct for communication.
*/

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
