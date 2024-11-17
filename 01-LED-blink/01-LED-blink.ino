/* 
*
 ***Important Notes:---
 *  
 *  (1). All digital pins of the ESP8266 are "Active-Low". 
 *       This means that setting a digital pin to HIGH will result in a low voltage, and vice versa. 
 *  (2). The "BUILTIN_LED" pin on the ESP8266 can be referenced as both "D4" and "2". 
 *
 */

void setup() {
  // Set GPIO2 (built-in LED) as output
  pinMode(D4, OUTPUT); // Configure pin D4 as an output pin
}

void loop() {
  // Turn the LED on
  digitalWrite(D4, HIGH); // This will turn the built-in LED of the ESP8266 off (Active-Low behavior)
  delay(1000);  // Wait for 1 second

  // Turn the LED off
  digitalWrite(D4, LOW); // This will turn the built-in LED of the ESP8266 on
  delay(1000);  // Wait for 1 second
}