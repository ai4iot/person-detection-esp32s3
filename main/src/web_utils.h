// web_utils.h

#ifndef WEB_UTILS_H
#define WEB_UTILS_H

#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include "esp_camera.h"
#include "wifi_utils.h"

extern AsyncWebServer server;
extern camera_fb_t *fb;
extern float senial;

void init_sppifs();
void init_webserver();





#endif // WEB_UTILS_H