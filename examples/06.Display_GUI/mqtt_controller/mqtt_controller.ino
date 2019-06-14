#include <Cubic32.h>
#include <Ticker.h>
#include <ssl_client.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#include <WiFi.h>

const char* ssid     = "*****your ssid*****";
const char* password = "*****your ssid*****";

const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_user = "";
const char* mqtt_pass = "";
const char* mqtt_intopic = "in/#";
const char* mqtt_outtopic = "out";


#define XP 26
#define XM 33
#define YM 25
#define YP 32
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

void lvgl_init();
void create_control_gui();
void mqtt_setup();
void mqtt_loop();

void setup() {
  Cubic.begin(true,false);

  Cubic.Lcd.setRotation(1); // Landscape

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  mqtt_setup();

  lvgl_init(); // LittleVGL init
  create_control_gui(); // Create GUI
}

void loop() {

  delay(10);
  Cubic.Buzzer.update();
}
