/*
 Basic MQTT Connection
 Date Create: 01/12/2021
 Create by: Parametrik
*/

// #include <ESP8266WiFi.h>                                                        // Include library wifi client (ESP8266)
#include <WiFi.h>                                                                  // Include library wifi client (ESP32)
#include <PubSubClient.h>                                                          // Include library Publish and Subscribe MQTT by Nick O'Leary (Knolleary)

#define internalLED 2                                                              // Define internal LED pinout for ESP (ESP8266: GPIO2, ESP32: GPIO2)

// Define variable ssd, password, & mqtt_broker
const char* ssid = "Parametrik RnD";                                              
const char* password = "tabassam";
const char* mqtt_broker = "192.168.1.5";

WiFiClient espClient;                                                              // Instance name WiFiClient as espClient
PubSubClient client(espClient);                                                    // Instance name PubSubClient as client 

char msgOut[20];                                                                   // Define char_of_array buffer variable publish message
char msgIn[128];                                                                   // Define char_of_array buffer varibale subscribe message
long lastMsg = 0;                                                                  // Define long varibale for function milis() time calculation
int value = 0;                                                                     // Define varible value use as increamment calculation
String struv;                                                                      // Define varibale string use as convertion integer to string

void setup() {
  Serial.begin(9600);
  pinMode(internalLED, OUTPUT);
  setup_wifi();
  client.setServer(mqtt_broker, 1883);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client")) {
      Serial.println("Connected to MQTT broker!");
      Serial.print("Broker:");
      Serial.println(mqtt_broker);
      digitalWrite(internalLED, HIGH);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
