#include "OTA.h"

const char* ssid     = "WIFI_SSID";
const char* password = "WIFI_PASSWORD";

void setup() {
  Serial.begin(9600);
   
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  setupOTA("HOST_NAME");

  Serial.println();
  Serial.println("Connected to WiFi network.");
  Serial.print("Connect with Telnet client to ");
  Serial.println(WiFi.localIP());
}

void loop() {
  ArduinoOTA.handle();
}
