/*
*
* NOTE: 
* This is the code to find the I2C address of I2C sensor.
*
*/

#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin(D2, D1); // SDA = D2, SCL = D1
  Serial.println("\nI2C Scanner");

  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found I2C device at: 0x");
      Serial.println(address, HEX);
      delay(500);
    }
  }
}

void loop() {
  // Nothing to do here
}