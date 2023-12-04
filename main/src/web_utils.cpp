#include "web_utils.h"

AsyncWebServer server(80);
camera_fb_t *fb;
float senial;

void init_sppifs(){

  if (!SPIFFS.begin(true)) {
    Serial.println("File system mounted failed");
    return;
  }else{
    Serial.println("File system mounted");
  }

}

void init_webserver(){

   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><head><title>ESP32 Imagen</title>";
    html += "<script>function reloadImage() { document.getElementById('img').src = 'image.jpg?' + new Date().getTime(); }</script>";

    html += "<script>var threshold = 0.5;</script>";
    html += "<script>function updateBackground(value) {";
    html += "if (value > threshold) { document.body.style.backgroundColor = 'green'; }";
    html += "else { document.body.style.backgroundColor = 'red'; }";
    html += "}</script>";

    html += "<p id='sensorValue'></p>";

    html += "<script>function updateSensorValue() {";
    html += "var xhr = new XMLHttpRequest();";
    html += "xhr.open('GET', '/getSensorValue', true);";
    html += "xhr.onreadystatechange = function () {";
    html += "if (xhr.readyState == 4 && xhr.status == 200) {";
    html += "var data = xhr.responseText;";
    html += "document.getElementById('sensorValue').innerText = 'Valor del sensor: ' + data;";
    html += "value = parseFloat(data);";  // Update threshold
    html += "updateBackground(value);";  //Refresh the background color
    html += "}";
    html += "};";
    html += "xhr.send();";
    html += "}";
    html += "setInterval(reloadImage, 600);";
    html += "setInterval(updateSensorValue, 600);";
    html +="</script>";

    html += "</head><body>";
    html += "<img id='img' src='image.jpg' style='display:block; margin: 0 auto; width='480'; height='360'/>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

    server.on("/image.jpg", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(SPIFFS, "/image.jpg", "image/jpeg");
    });

    server.on("/getSensorValue", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", String(senial));
});


}
