
/*******************************************************************
 *  this is a basic example how to use the ESP8266 Huginn          *
 *  library to send webhooks to Huginn                             *
 *                                                                 *
 *  written by Witnessmenow                                        *
 *******************************************************************/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266Huginn.h>
#include <ArduinoJson.h>

// Initialize Wifi connection to the router
char ssid[] = "SSIDNAME";              // your network SSID (name)
char pass[] = "password";                              // your network key

int huginn_mtbs = 10000; //mean time between scan messages
long huginn_lasttime;   //last time messages' scan has been done

ESP8266Huginn huginn("huginn.yourdomain.com", 80);

void setup() {
  Serial.begin(115200);
  delay(3000);

  // attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
}



void loop() {
  if (millis() > huginn_lasttime + huginn_mtbs)  {
    StaticJsonBuffer<500> jsonBuffer;
    JsonObject& event = jsonBuffer.createObject().createNestedObject("event");
    event["description"] = "Something happened";
    event["type"] = "101";

    String response = huginn.sendPost("/users/1/web_requests/47/arduino", "", error);
    Serial.println(response);
    huginn_lasttime = millis();
  }
}
