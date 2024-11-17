#define LDR_SENSOR_PIN A0

int ldrReading;

void setup(){
    pinMode(D4, OUTPUT);
    pinMode(LDR_SENSOR_PIN, INPUT);
    Serial.begin(9600);
}

void loop(){

    ldrReading = analogRead(LDR_SENSOR_PIN); // Reading the LDR data.

    Serial.print("LDR Reading: ");
    Serial.println(ldrReading); // Printing LDR(Light Depandent Resistor) data.

    if(ldrReading < 100){
      digitalWrite(D4 , LOW); // Turning ON the LED.
    }else{
      digitalWrite(D4 , HIGH); // Turning OFF the LED.
    }

    delay(250);
}




