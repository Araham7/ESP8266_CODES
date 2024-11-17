/*
NOTE : 
(1). This code will print the Temperature in *C, *F and pressure in Pascal (Pa) and altitude in meters (m).
(2). We are using the "Adafruit_BMP280.h" library.

// Wiring : 
// SDA = GPIO4 (D2), SCL = GPIO5 (D1) , VCC = 3.3volt and GND = G
*/

#include <Wire.h>
#include <Adafruit_BMP280.h>

#define BMP280_I2C_ADDRESS 0x76  // Change this to your sensor's I2C address (0x76 or 0x77)

Adafruit_BMP280 bmp; // I2C (default)

void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 Forced Mode Test."));

  // Start I2C communication with custom SDA and SCL pins (optional, if you want to change default pins)
  Wire.begin(4, 5); // SDA = GPIO4 (D2), SCL = GPIO5 (D1)

  if (!bmp.begin(BMP280_I2C_ADDRESS)) { // Pass the I2C address here
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    while (1) delay(10);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_FORCED,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop() {
  // must call this to wake sensor up and get new measurement data
  // it blocks until measurement is complete
  if (bmp.takeForcedMeasurement()) {
    // can now print out the new measurements
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Temperature = "));
    Serial.print((bmp.readTemperature()*(9/5))+32);
    Serial.println(" *F");

    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");

    Serial.println();
    delay(2000);
  } else {
    Serial.println("Forced measurement failed!");
  }
}
