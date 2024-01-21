#include "mqtt_utils.h"


const char* mqttServer;
int mqttPort = 1883;
PubSubClient mqttClient(espClient);

void init_mqtt()
{

  Serial.print("Connect to MQTT -");
  Serial.print(mqttServer);
  Serial.print("-");
  Serial.println(mqttPort);

  mqttClient.setServer(mqttServer, mqttPort);
}


void connect_mqtt()
{

  while (!mqttClient.connected())
  {

    Serial.print("Connecting to MQTT");

    if (mqttClient.connect("ESP32Client"))
      Serial.println("connected");

    else
    {
      Serial.print("failed with state ");
      Serial.print(mqttClient.state());
      delay(500);
    }
  }
}

void handdle_qmtt()
{

  if (!mqttClient.connected())
  {

    connect_mqtt();
  }

  mqttClient.loop();
}

void mqtt_publish(String topic, char *payload)
{

  mqttClient.publish(topic.c_str(), payload);
}


//void get_mqtt_credentials()
//{
//    Serial.print("MQTT broker ip: ");
//    while (!Serial.available()) {
//
//    }
//    String mqttServerString = Serial.readStringUntil('\n');
//    mqttServer = mqttServerString.c_str();
//    Serial.println("IP: ");
//    Serial.print(mqttServerString);
//
//    Serial.print("\nMQTT broker port: ");
//    while (!Serial.available()) {
//
//    }
//    mqttPort = Serial.readStringUntil('\n').toInt();
//    Serial.println("Port: " + mqttPort);
//
//}