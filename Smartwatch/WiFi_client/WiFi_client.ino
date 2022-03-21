/*

*/

#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "PoleDeVinci_DVIC"        // Enter your network SSID
#define STAPSK  "8PfURsp!dvic"       // Enter your network password
#endif

const char* ssid     = STASSID;       // Replace STASSID by "your_WiFi_network_name"
const char* password = STAPSK;        // Replace STAPSK by "your_WiFi_network_password"

const char* host = "smartwatch.net";      // Enter your domain
const uint16_t port = 1234;

void setup() {
  Serial.begin(115200);

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);              // Start the communication

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void loop() {
  static bool wait = false;

  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  if (client.connect(host, port)) {
    Serial.println("connection successed");
  } else {
    Serial.println("connection failed");
    delay(5000);
    return;
  }

//  // Make a HTTP request
//  client.println("GET / HTTP/1.1");      
//  client.println("Host: ..."); 
//  client.println("Connection close"); 
//  client.println(); 

  // Wait for receiving data during 10 seconds
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 10000) { 
      Serial.println("Client timeout!");
      client.stop();
      delay(60000);
      return;
    }
  }

  // Data are received
  while(client.available()) {
    int ecFlex_data = client.read();
    Serial.print(ecFlex_data);
  }

  // Serial receive buffer
  Serial.setTimeout(1000);            // ParseInt() wait 1 sec before reading, instead of reading in each byte as it arrives
  while (Serial.available() > 0) {
    int ecFlex_data = Serial.parseInt();
    Serial.print(ecFlex_data);
}

  // Close the connection
  Serial.println();
  Serial.println("closing connection");
  client.stop();


  delay(30000);  // Execute every 30 secondes

}
