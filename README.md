# ESP8266-OTA-Template

ESP8266-OTA-Template is a simple ESP8266 template with MDNS telnet and OTA updates. Edited from [Andreas's esp32 code ](https://github.com/SensorsIot/ESP32-OTA)



# Usage

Download and open the TEMPLATE.INO file with Arduino app.

* Make sure to install [ESP8266mDNS](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266mDNS) [TelnetStream](https://github.com/jandrassy/TelnetStream)
* Fill the WIFI_SSID and WIFI_PASSWORD with your wifi information
* replace HOST_NAME with your project name so you can find the esp8266 by using projectName.local


## OTA Usage 
connect your esp8266 to upload template then go to tools > port the ESP should be visible with the projectName.

## TelnetStream Usage
To connect to the telnet output use a telnet client such as [Putty](https://www.putty.org) with the ip or projectName.local.



debug using 

```c++
TelnetStream.println("test");
```
