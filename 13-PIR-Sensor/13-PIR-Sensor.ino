/*
*
*Wiring : VCC = 3volt , GND = GND , OUT = D0
*
* NOTE : 
*
*** PIR-Sensor(Passive Infrared Sensor) : A PIR sensor (Passive Infrared Sensor) is an electronic sensor that detects infrared (IR) radiation emitted by objects, typically used for motion detection. It is widely used in security systems, automatic lighting, and other applications that require motion sensing.
*
*/


// Define the GPIO pin where the PIR sensor output is connected
const int pirPin = D0;  // Change this to the GPIO pin number you are using

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the PIR pin as input
  pinMode(pirPin, INPUT);
}

void loop() {
  // Read the PIR sensor output
  int pirState = digitalRead(pirPin);

  // Print the state of the PIR sensor
  if (pirState == HIGH) {
    Serial.println("Motion Detected!");
    Serial.println(pirState);
  } else {
    Serial.println("No Motion.");
    Serial.println(pirState);
  }

  // Wait for a second before checking again
  delay(250);
}