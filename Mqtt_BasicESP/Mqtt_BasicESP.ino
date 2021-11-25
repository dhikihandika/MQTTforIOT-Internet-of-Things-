/*
 Basic MQTT example
 Date Create: 11/25/2021
 Create by: Parametrik

 This sketch demonstrates the basic capabilities of the library.
 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary

 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.
*/

#include <WiFi.h>
#include <PubSubClient.h>

// Replace the next variables with your SSID/Password combination
const char* ssid = "Parametrik_Prod";
const char* password = "tabassam";

// Add your MQTT Broker:
const char* mqtt_broker = "192.168.0.120";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[20];
int value = 0;
String struv;

void setup() {
  Serial.begin(115200);

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
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client")) {
      Serial.println("Connected to MQTT broker!");
      Serial.print("Broker:");
      Serial.println(mqtt_broker);
      client.publish("ITSCourse", "connected");
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
    Serial.println("Disconnected to MQTT broker!");
  }

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;

    struv = "value: " + String(value);
	  struv.toCharArray(msg,20);
    
    Serial.print(" all: ");
    Serial.println(msg);
    client.publish("ITSCourse", msg);

    value++;
    client.loop();
  }
}