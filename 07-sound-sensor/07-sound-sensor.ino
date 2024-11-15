const int micPin = A0;  // Microphone connected to ADC pin
int soundLevel;

void setup() {
  Serial.begin(115200);
  pinMode(micPin, INPUT);
}

void loop() {
  soundLevel = analogRead(micPin);  // Read microphone signal
  Serial.println(soundLevel*100);      // Print sound level to Serial Monitor
  delay(50);                       // Delay for stability
}