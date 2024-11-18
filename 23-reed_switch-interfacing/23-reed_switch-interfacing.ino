/*
*
*
Wiring :---

             +-----------+
             |  Reed     |
             | Switch    |
             +----+  +---+
                  |  |
                  |  +------------> GND (ESP8266)
                  |
                  +------------> D2 (ESP8266)
*
*
*/

#define reedPin D2  // Pin connected to the reed switch
int reedState;      // Variable to store the state of the reed switch

void setup() {
  Serial.begin(9600);             // Initialize serial communication
  pinMode(reedPin, INPUT_PULLUP); // Configure reedPin as input with internal pull-up

  /*
   Wiring for the reed switch:
   - One terminal of the reed switch connects to D2 (GPIO4) on the ESP8266.
   - The other terminal connects to GND.
   - No external pull-up resistor is needed, as INPUT_PULLUP enables the internal pull-up resistor.
  */
}

void loop() {
  reedState = digitalRead(reedPin); // Read the state of the reed switch

  if (reedState == LOW) {
    // Reed switch is activated (magnet present)
    Serial.println("Magnet Detected!");
  } else {
    // Reed switch is not activated (no magnet)
    Serial.println("No Magnet Detected!");
  }

  delay(500); // Small delay to avoid spamming the Serial Monitor
}
