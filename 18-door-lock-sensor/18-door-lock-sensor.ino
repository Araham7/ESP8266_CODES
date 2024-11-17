/*
 *
 * - Connect the door sensor one-leg to pin D1 (or any other available digital pin-of-esp8266 except D0-pin).
 * - Connect the door sensor another-leg to pin GND.
 *
*/

#define DOOR_SENSOR_PIN D1 // Define the digital-pin(except D0) for the door sensor

int doorState; // Variable to store the door sensor state

void setup() {
    pinMode(DOOR_SENSOR_PIN, INPUT_PULLUP); // Set the pin as input with built-in pull-up
    Serial.begin(9600);                    // Initialize serial communication
}

void loop() {
    doorState = digitalRead(DOOR_SENSOR_PIN); // Read the door sensor state

    if (doorState == LOW) { // LOW indicates the door is locked (active low logic)
        Serial.println("Door is LOCKED");
    } else {                // HIGH indicates the door is unlocked
        Serial.println("Door is UNLOCKED");
    }

    delay(500); // Delay for stability
}


