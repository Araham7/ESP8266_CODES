#include <ESP8266WiFi.h>

#define TRIG_PIN D1  // Trigger pin
#define ECHO_PIN D2  // Echo pin

long duration;
int distance;

void setup() {
  Serial.begin(115200);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  // Send a HIGH pulse for 10ms to trigger the ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW); 
  delay(2000);  // Wait for sensor to settle
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Measure the time it takes for the pulse to return
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate distance (in cm)
  distance = duration * 0.0344 / 2;  // Speed of sound is 0.0344 cm/µs
  
  // Print the distance in the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(1000);  // Wait 1 second before the next measurement
}
