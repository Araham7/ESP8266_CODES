String msg;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enter your message!");

  while (Serial.available() == 0){
    // Waiting for user input
  }

  msg = Serial.readString();
  Serial.println(msg);
}