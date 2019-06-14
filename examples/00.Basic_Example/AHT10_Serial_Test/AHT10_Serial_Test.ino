#include <Cubic32.h>

void setup() {
    // put your setup code here, to run once:
    Cubic.begin(true,false);
}

void loop() {
    // put your main code here, to run repeatedly:
    Serial.println("//Cubic32 AHT10 Module Test!!!//");
    Serial.println(String("")+"Humidity(%RH):\t\t"+Cubic.AHT10.GetHumidity()+"%");
    Serial.println(String("")+"Temperature(℃):\t"+Cubic.AHT10.GetTemperature()+"℃");
    Serial.println(String("")+"Dewpoint(℃):\t\t"+Cubic.AHT10.GetDewPoint()+"℃");
    delay(500);
}
