/***************************************************

****************************************************/
#include <Afantor.h>


void setup()
{
    Serial.begin(115200);
    AF.begin();
  
    Serial.println(F("Done!"));
}

void loop(void) 
{
    AF.LCD.drawBitmap(0, 0, 320, 240, (uint16_t *)gImage_logoAF);
    delay(10000);
    AF.LCD.drawBitmap(0, 0, 320, 240, (uint16_t *)gImage_logoAF1);
    delay(10000);
}

