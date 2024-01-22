#include "wifi_utils.h"

const char* password;
const char* ssid;

WiFiClient espClient;



void setup_wifi()
{

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi.");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected to WiFi");
}

//void get_wifi_credentials()
//{
//
//    Serial.print("WiFi SSID: ");
//    while (!Serial.available()) {
//
//    }
//    String ssidString = Serial.readStringUntil('\n');
//    ssid = ssidString.c_str();
//    Serial.println("SSID: " + ssidString);
//
//    Serial.print("WiFi password: ");
//    while (!Serial.available()) {
//
//    }
//    String passwordString = Serial.readStringUntil('\n');
//    password = passwordString.c_str();
//    Serial.println("\npassword: " + passwordString);
//
//
//
//}