// mqtt_utils.h

#ifndef MQTT_UTILS_H
#define MQTT_UTILS_H

#include <PubSubClient.h>
#include "wifi_utils.h"


// const char* mqttServer = "192.168.79.91";
// const int mqttPort = 1883;

extern const char* mqttServer;
extern int mqttPort;
extern PubSubClient mqttClient;

void init_mqtt();
void handdle_qmtt();
void connect_mqtt();
void mqtt_publish(String topic, char *payload);
void get_mqtt_credentials();


#endif // MQTT_UTILS_H