char msg[100]; // Message store karne ke liye character array
int currentIndex = 0; // Current index track karne ke liye

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enter your message:");

  // Poora message read karte hain
  while (true) {
    if (Serial.available() > 0) {
      char received = Serial.read(); // Ek character read karo
      if (received == '\n') { // Agar newline character mila, message end
        break;
      }
      msg[currentIndex++] = received; // Character ko array mein add karo
      if (currentIndex >= sizeof(msg) - 1) { // Overflow prevent karo
        break;
      }
    }
  }

  msg[currentIndex] = '\0'; // Null-terminate string

  // Message print karo
  Serial.println(msg);

  // Reset currentIndex for next input
  currentIndex = 0;
}