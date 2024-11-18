/*
*
NOTE :
-----------------------------------------------------WIRING----------------------------------------------------
    *** Tx(BT) = D2(ESP) , Rx(BT) = D3(ESP) , Vcc(BT) = (3.6v to 5v) , Gnd(BT) = GND(ESP).
*
 */

#include <SoftwareSerial.h>

String msg;

SoftwareSerial mySerial(D2, D3); // Rx, Tx

void setup(){
    mySerial.begin(9600);
    Serial.begin(9600);
}

void loop(){
    if (mySerial.available() > 0) {  // Fixing typo: available() and checking if data is available
        msg = mySerial.readString();  // Fixing typo: readString()
        Serial.print("Message from Phone: ");
        Serial.println(msg);  // Added println to print the message in a new line
    }
}