// 0x68 ===> This is the i2c address of the MPU6050.

#include <Wire.h>
#include <MPU6050.h>

// Define the I2C address (default is 0x68 or 0x69)
#define MPU6050_ADDR 0x68  // Change this to 0x69 if AD0 is high

MPU6050 mpu(MPU6050_ADDR);  // Initialize with the I2C address

void setup() {
  // Start serial communication
  Serial.begin(9600);
  
  // Initialize I2C communication
  Wire.begin();
  
  // Initialize the MPU6050 sensor
  mpu.initialize();
  
  // Check if the sensor is connected
  if (mpu.testConnection()) {
    Serial.println("MPU6050 is connected!");
  } else {
    Serial.println("MPU6050 connection failed!");
    while (1); // Stop the program if the sensor is not found
  }
}

void loop() {
  // Variables to store accelerometer and gyroscope data
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  // Get accelerometer and gyroscope data
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  
  // Print the data to the Serial Monitor
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(ax);
  Serial.print(", Y = "); Serial.print(ay);
  Serial.print(", Z = "); Serial.println(az);
  
  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(gx);
  Serial.print(", Y = "); Serial.print(gy);
  Serial.print(", Z = "); Serial.println(gz);
  
  // Delay for a while
  delay(1000);
}
