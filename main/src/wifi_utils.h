// wifi_utils.h

#ifndef WIFI_UTILS_H
#define WIFI_UTILS_H


#include <WiFi.h>

//const char* ssid = "ASUS_GRAM";
//const char* password = "GramLab0rat0ri0";
extern const char* password;
extern const char* ssid;

extern WiFiClient espClient;


void setup_wifi();
void get_wifi_credentials();


#endif // WIFI_UTILS_H
