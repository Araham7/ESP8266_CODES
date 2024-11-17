/*
*
* This code is used to convert a push-button into a toggle-switch.
*
*/

boolean LEDState = false; // Use boolean for LED state
int LEDPin = D4;          // Pin connected to the LED
int buttonPin = D0;       // Pin connected to the button
int buttonNew;            // Stores the current button state
int buttonOld = 1;        // Stores the previous button state
int dt = 100;             // Debouncing delay

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);      // Set LED pin as OUTPUT
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor for the button
}

void loop() {
  buttonNew = digitalRead(buttonPin); // Read the current state of the button
  toggleSwitch(); // Call the function to handle LED toggle
  buttonOld = buttonNew; // Update the previous button state
  delay(dt); // Delay for debouncing
}

// Function to toggle the LED state
void toggleSwitch() {
  // Check if the button state has changed from LOW to HIGH
  if (buttonOld == 0 && buttonNew == 1) {
    LEDState = !LEDState;               // Toggle the LED state
    digitalWrite(LEDPin, LEDState ? HIGH : LOW); // Set LED state
    Serial.println(LEDState ? "ON" : "OFF");    // Print the current LED state
  }
}
