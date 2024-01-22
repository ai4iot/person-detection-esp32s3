// wifi_utils.h

#ifndef WIFI_UTILS_H
#define WIFI_UTILS_H


#include <WiFi.h>

extern const char* password;
extern const char* ssid;

extern WiFiClient espClient;


void setup_wifi();
void get_wifi_credentials();


#endif // WIFI_UTILS_H
