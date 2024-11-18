/*
*
IMPORTANT NOTE:
*** Make sure to turn on the serial monitor, set the baud rate to 9600, and then enter a number in the serial monitor.
*
*/



// float myNumber; // ==> for getting the floating point data.
int myNumber; 


String msg1 = "Please enter the number : ";
String msg2 = "Your number is : ";

void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.println(msg1);
    while(Serial.available() == 0){
        /* It will waiting untill user enter something into the SerialMonitor. */
    }
    

    //  myNumber = Serial.parseFloat(); // ==> for getting the floating point data.
    myNumber = Serial.parseInt(); 

    Serial.print(msg2);
    Serial.println(myNumber);
}

