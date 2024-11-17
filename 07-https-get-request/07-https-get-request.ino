#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

#ifndef STASSID
#define STASSID "SSID" // Your WiFi(or, Hotspot) name.
#define STAPSK "8918172922" // Your WiFi(or, Hotspot) password.
#endif

ESP8266WiFiMulti WiFiMulti;

void setup() {
  Serial.begin(9600);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(STASSID, STAPSK);
  Serial.println("setup() done connecting to ssid '" STASSID "'");
}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    // Create a secure client instance
    std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);

    // Disable SSL certificate verification (unsafe for production)
    client->setInsecure();

    // Initialize HTTPClient for HTTPS request
    HTTPClient https;

    // GitHub user API URL
    String username = "Araham7"; // Replace with the desired GitHub username
    String url = "https://api.github.com/users/" + username;
    Serial.print("[HTTPS] begin...\n");

    if (https.begin(*client, url)) {  // HTTPS

      Serial.print("[HTTPS] GET...\n");
      // Start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been sent, and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // Check if the file was found at the server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println("GitHub User Details: ");
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
  }

  Serial.println("Wait 5s before next round...");
  delay(5000);
}
