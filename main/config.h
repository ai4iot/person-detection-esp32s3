static bool debug_nn = false; // Set this to true to see e.g. features generated from the raw signal
static bool is_initialised = false;
uint8_t *snapshot_buf; //points to the output of the capture

const char* ssid = "ASUS_GRAM";
const char* password = "GramLab0rat0ri0";
const char* mqttServer = "192.168.79.91";
const int mqttPort = 1883;