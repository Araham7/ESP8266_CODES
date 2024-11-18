/*
Wiring:
- LM35 GND pin -> ESP8266 GND
- LM35 VCC pin -> 5v
- LM35 OUT pin -> ESP8266 A0 (Analog Pin)
*/


const int sensorPin = A0; // LM35 analog output connected to A0 pin on ESP8266
float temperature;

void setup() {
  Serial.begin(9600); // Set the baud rate to 9600
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read the analog value
  temperature = (sensorValue * 3.3) / 1024.0; // Convert to voltage (0-3.3V)
  temperature = temperature * 100; // LM35 outputs 10mV per degree Celsius
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000); // Delay for 1 second
}

