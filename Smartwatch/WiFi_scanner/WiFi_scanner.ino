#include "ESP8266WiFi.h"   // .h file is the glossary of all functions from ESP8266WiFi library. 
WiFiClient client;

void setup() {

  // initialize serial and wait for the port to open:

  Serial.begin(115200);

 
//  WiFi.mode(WiFi_STA);       // Set the ESP8266 in the Station mode. This mode allow the ESP to connect to a WiFi network.
//  WiFi.disconnect();           // Disconnection from an eventual network.
//  delay(100);

//  Serial.println("Setup done");
}

void loop() {
  Serial.println("Scan start");
  int n = WiFi.scanNetworks();     // WiFi.scanNetworks return the number of networks found
  Serial.println("Scan done");
  if (n==0) {
    Serial.println("No networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {         // Print SSID and RSSI (in dB) for each network found
      Serial.print(i + 1);  
      Serial.print(": "); 
      Serial.print(WiFi.SSID(i)); 
      Serial.print(" ("); 
      Serial.print(WiFi.RSSI(i)); 
      Serial.print(")");
      if (WiFi.encryptionType(i) == ENC_TYPE_NONE){     // Print a "*" if the WiFi Network is crypted 
        Serial.println(" ");                            
    } 
      else {
        Serial.println("*"); 
      }
     delay(10);
    }
  }
  Serial.println("");

  delay(5000);       // Wait a bit befor scanning again
}
