/*
*
* WIRING : 
*          (D4 = Data-pin-of-DHT11), 
*          (3volt = VCC-pin-of-DHT11), 
*          (GND = GND-pin-of-DHT11)
*
*/


#include <ESP8266WiFi.h>
#include <DHT.h>

// Pin where the DHT11 is connected
#define DHTPIN 2    // D4 on ESP8266

// DHT sensor type
#define DHTTYPE DHT11

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start the Serial communication
  Serial.begin(115200);
  
  // Start the DHT sensor
  dht.begin();
  
  // Wait for a second before starting to get readings
  delay(2000);
}

void loop() {
  // Read humidity and temperature values
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();  // Celsius

  // Check if the readings failed
  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Convert Celsius to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32;

  // Print the values to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C  ");
  Serial.print(temperatureF);
  Serial.print(" °F  ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Wait for 2 seconds before the next reading
  delay(2000);
}
