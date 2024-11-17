#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const String URL = "http://192.168.158.231:7569/"; // Replace with the desired URL.

const char* ssid = "Laptop";  // Your Wi-Fi SSID.
const char* password = "8918172922";  // Your Wi-Fi password.

void setup(){
  Serial.begin(9600);
  WiFi.disconnect();  // Disconnect any previous Wi-Fi connections
  delay(2000);  // Wait for 2 seconds before starting a new connection
  Serial.println("Connecting to Wi-Fi...");

  WiFi.begin(ssid, password);  // Start the Wi-Fi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);  // Wait for 200 milliseconds before checking again
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi");
  Serial.print("Device IP (ESP8266 IP address): ");
  Serial.println(WiFi.localIP());

  Serial.print("Gateway IP (Hotspot IP address): ");
  Serial.println(WiFi.gatewayIP());
}

void loop(){
  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  // Declare an HTTPClient object
    WiFiClient client;  // Declare a WiFiClient object
    http.begin(client, URL);  // Specify the WiFiClient and the URL
    int responseCode = http.GET();  // Make the GET request

    if (responseCode > 0) {
      Serial.print("Response code: ");
      Serial.println(responseCode);
      String data = http.getString();  // Get the response data
      Serial.println("Response data:");
      Serial.println(data);  // Print the response data
    } else {
      Serial.print("Error on HTTP request: ");
      Serial.println(responseCode);
    }

    http.end();  // End the HTTP request
  } else {
    Serial.println("Wi-Fi not connected.");
  }
  delay(500);  // Delay for 0.5 seconds before the next GET request
}







