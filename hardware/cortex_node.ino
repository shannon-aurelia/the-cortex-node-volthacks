#include <Arduino.h>
#include <driver/i2s.h>
constexpr int BUTTON_PIN=14, STATUS_LED=2, I2S_WS=25, I2S_SCK=26, I2S_SD=33;
volatile bool captureRequested=false;
void IRAM_ATTR onCaptureButton(){captureRequested=true;}
void setup(){Serial.begin(115200);pinMode(BUTTON_PIN,INPUT_PULLUP);pinMode(STATUS_LED,OUTPUT);attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),onCaptureButton,FALLING);Serial.println("{\"source\":\"ESP32\",\"event\":\"BOOT_OK\"}");}
void loop(){if(!captureRequested)return;captureRequested=false;digitalWrite(STATUS_LED,HIGH);Serial.println("{\"source\":\"NODE\",\"event\":\"CAPTURE_PACKET\"}");delay(120);digitalWrite(STATUS_LED,LOW);}
