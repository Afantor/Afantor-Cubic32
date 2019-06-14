#pragma mark - Depend ESP8266Audio and ESP8266_Spiram libraries
/* 
cd ~/Arduino/libraries
git clone https://github.com/earlephilhower/ESP8266Audio
git clone https://github.com/Gianbacchio/ESP8266_Spiram

Use the "Tools->ESP32 Sketch Data Upload" menu to write the MP3 to SPIFFS
Then upload the sketch normally.  
https://github.com/me-no-dev/arduino-esp32fs-plugin
*/

#include <Afantor.h>
#include <WiFi.h>
#include "AudioFileSourceSD.h"
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2S.h"


AudioGeneratorWAV *wav;
AudioFileSourceSD *file;
AudioOutputI2S *out;

void setup()
{
  AF.begin();
  WiFi.mode(WIFI_OFF); 
  delay(500);
  
  AF.LCD.setTextFont(2);
  AF.LCD.printf("Sample WAV playback begins...\n");
  Serial.printf("Sample WAV playback begins...\n");
  
  // pno_cs from https://ccrma.stanford.edu/~jos/pasp/Sound_Examples.html
  file = new AudioFileSourceSD("/pno-cs.wav");
  out = new AudioOutputI2S(0, 1); // Output to builtInDAC
  out->SetOutputModeMono(true);
  wav = new AudioGeneratorWAV();
  wav->begin(file, out);
}

void loop()
{
  if (wav->isRunning()) 
  {
    if (!wav->loop()) wav->stop();
  } 
  else 
  {
    Serial.printf("WAV done\n");
    delay(1000);
  }
}

