/*
NOTE: Is code me sabse pehle esp8266 module wifi se connect hoga aur phir ye server ki tarhe behave karega.
*
***** This code will handel the httpGET req.body JSON-data at root("/") route .
***** This code will handel the httpPOST req.params data at ("/data") route .
*
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

// Wi-Fi credentials
const char* ssid = "Laptop";
const char* password = "8918172922";

ESP8266WebServer server(80);  // Create a web server on port 80

// Handle POST request at /data route
void handlePost() {
  // Create a JSON document to store the response
  StaticJsonDocument<200> jsonResponse;

  // Check if the request body is not empty
  if (server.hasArg("plain")) {
    String payload = server.arg("plain");  // Get the raw POST data
    Serial.println("Received data: " + payload);

    // Parse the incoming JSON data (optional)
    DeserializationError error = deserializeJson(jsonResponse, payload);
    if (error) {
      Serial.println("Failed to parse JSON");
      jsonResponse["message"] = "Invalid JSON data!";
      server.send(400, "application/json", "{\"error\":\"Invalid JSON\"}");
      return;
    }

    // Respond with a JSON message
    jsonResponse["status"] = "Data received successfully!";
    String response;
    serializeJson(jsonResponse, response);
    server.send(200, "application/json", response);  // Send JSON response
  } else {
    jsonResponse["message"] = "No data received!";
    String response;
    serializeJson(jsonResponse, response);
    server.send(400, "application/json", response);  // Send error response
  }
}

// Handle GET request at root ("/") route
void handleRoot() {
  // Create a JSON object to store the response data
  StaticJsonDocument<200> jsonResponse;

  // Check if there are any query parameters
  if (server.args() > 0) {
    Serial.println("Received query parameters:");

    // Loop through all the query parameters and print them
    for (uint8_t i = 0; i < server.args(); i++) {
      String argName = server.argName(i);  // Get parameter name
      String argValue = server.arg(i);     // Get parameter value
      Serial.println(argName + " = " + argValue); // Print parameter name and value

      // Add the query parameter to the JSON response
      jsonResponse[argName] = argValue;
    }

    // Send JSON response with status 200
    String response;
    serializeJson(jsonResponse, response);
    server.send(200, "application/json", response); // Send JSON response
  } else {
    jsonResponse["message"] = "No query parameters received.";

    // Send JSON response with status 200
    String response;
    serializeJson(jsonResponse, response);
    server.send(200, "application/json", response); // Send JSON response
  }
}

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected!");

  // Print the IP address
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define the routes
  server.on("/data", HTTP_POST, handlePost);  // Handle POST request at /data route
  server.on("/", HTTP_GET, handleRoot);       // Handle GET request at root route

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();  // Handle incoming requests
}
