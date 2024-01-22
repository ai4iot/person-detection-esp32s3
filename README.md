# Person Detection with ESP32S3 and OV2640

In this project, we will use the ESP32S3 and the OV2640 camera to detect people. The ESP32S3 is a new chip from 
Espressif that has a dual-core processor, a coprocessor, and a neural network accelerator. 
The OV2640 is a camera module that can capture images with a resolution of 1600x1200 pixels.

## Model

The model used in this project is th MobilenetV2. The mode was trained
with the [COCO dataset](https://cocodataset.org/#home). And some other pictures
taken directly from the ESP32S3.

We take pictures at a resolution of 320x240 pixels. And resize them to 160x160 pixels.

For training, we use [Edge Impulse](https://www.edgeimpulse.com/), a platform for developing and deploying
machine learning models on edge devices. The platform allows us to train the model and deploy it as a library
for the ESP32S3. In our case we use the Arduino IDE to program the ESP32S3. You can find the library
[here](model-zoo).  
We have two versions of the model:
* 8 int quantization.
* 32 float quantization.


## Test results

For testing the model we use 1000 images taken directly from the ESP32S3.
The results are:
- **Accuracy**  95.1%
- **F1 Score:** 0.96
- **Confusion Matrix:**

| Actual/Predicted | person | nonperson |
|------------------|--------|-----------|
| person           | 564    | 36        |
| nonperson        | 12     | 388       |




## Usage

To use the project, you must first install the [Arduino IDE](https://www.arduino.cc/en/software). 
And configure it to work with the ESP32S3 (model with at least 8MB flash and with PSRAM, normally when 
the developed kit includes a camera, it will have these characteristics).
You can find the instructions [here](https://www.luisllamas.es/como-programar-esp32-con-el-ide-de-arduino/).
Then you can download the model library from [here](model-zoo) and install it in the Arduino IDE.  
Also, you have to install these other librarys:
* PubSubClient
* ESPAsyncWebServer  

The Rest of the libraries are normally already included in the Arduino IDE.
Finally, you have to configure the project in the Arduino IDE, go to Tools and select the following options:
* Flash Size: select at least 8MB.
* Partition Scheme: 8MB with spiffs. (3MB APP/1.5MB SPIFFS).
* PSRAM: OPI Psram enabled.

These settings are necessary to be able to use the camera and make a partition to store the image
for the web page.
  
It has two modes of operation, you can change the mode with a macro in the [main](main/main.ino) code:
* MQTT mode.
* WEB mode.

### MQTT Mode

When you run the code, you have tto enter the SSID and password of your Wi-Fi network and the
IP address of the MQTT broker and the port.  
In this mode when the threshold is exceeded(0.65), the ESP32S3 sends a message to the MQTT broker.

### WEB Mode

When you run the code, you have to enter the SSID and password of your Wi-Fi network. Then you have to 
browse in your browser to the IP address of the ESP32S3, and the image captured by the camera will appear.
When the threshold is exceeded(0.65), the background of the page will turn green otherwise it will turn red.
Also, the percentage of person is shown on the web page.


## Config

For configuring the camera pins, you have to change the [pines.h](main/pines.h) file.
If you want to change the configuration, you can change the files in the [src](main/src) folder. 
Also, you have to configure the SSID and password for the Wi-Fi network and the IP address of the MQTT broker.



