/*
*
NOTE : { (BT = Bluetooth) & (ESP = ESP8266-module) }
-----------------------------------------------------WIRING----------------------------------------------------
    *** Tx(BT) = D2(ESP) , Rx(BT) = D3(ESP) , Vcc(BT) = (3.6v to 5v) , Gnd(BT) = GND(ESP).
*
 */

#include <SoftwareSerial.h>

// Initialize SoftwareSerial with RX and TX pins
SoftwareSerial mySerial(D2, D3); // Rx (D2), Tx (D3)

void setup() {
    mySerial.begin(9600); // Start SoftwareSerial at 9600 baud
    Serial.begin(9600);   // Start hardware Serial at 9600 baud
}

void loop() {
    String msg; // Variable to store received message
    
    Serial.println("Enter your message!"); // Prompt user for input

    // Wait for input from the Serial Monitor
    while (mySerial.available() == 0) {
        // Waiting for user input
        delay(200); // Avoid spamming the Serial Monitor
    }

    // If there is incoming data on the SoftwareSerial
    if (mySerial.available() > 0) {
        msg = mySerial.readString(); // Read the incoming message.
        msg.trim(); // Trim leading and trailing whitespace from the msg.
        Serial.print("Message from Phone : ");
        Serial.println(msg); // Display the message on the Serial Monitor.
    }
}


