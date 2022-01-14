#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <TelnetStream.h>


void setupOTA(const char* hostName) {
    // OTA Hostname 
   	ArduinoOTA.setHostname(hostName);

	  // MDNS hostname
	  if (!MDNS.begin("esp8266-clock")) {
		  Serial.println("Error setting up MDNS responder!");
	  }
  
  	ArduinoOTA.onStart([]() {
    	String type;
    	if (ArduinoOTA.getCommand() == U_FLASH) {
      		type = "sketch";
    	} else { // U_FS
      		type = "filesystem";
    	}

    	// NOTE: if updating FS this would be the place to unmount FS using FS.end()
    	Serial.println("Start updating " + type);
  	});

  	ArduinoOTA.onEnd([]() {
  	  Serial.println("\nEnd");
  	});

  	ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
  		Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  	});

	ArduinoOTA.onError([](ota_error_t error) {
		Serial.printf("Error[%u]: ", error);
		if (error == OTA_BEGIN_ERROR) {
		  Serial.println("Begin Failed");
		} else if (error == OTA_CONNECT_ERROR) {
		  Serial.println("Connect Failed");
		} else if (error == OTA_RECEIVE_ERROR) {
		  Serial.println("Receive Failed");
		} else if (error == OTA_END_ERROR) {
		  Serial.println("End Failed");
		}
	});

  	ArduinoOTA.begin();
    TelnetStream.begin();
}
