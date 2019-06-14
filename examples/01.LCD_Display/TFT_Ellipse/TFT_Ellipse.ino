/*
  Ellipse drawing example

  This sketch does not use any fonts.
*/

#include <Afantor.h>

void setup(void) {

  AF.begin();

}

void loop() {

  AF.LCD.fillScreen(TFT_BLACK);

  // Draw some random ellipses
  for (int i = 0; i < 40; i++)
  {
    int rx = random(60);
    int ry = random(60);
    int x = rx + random(320 - rx - rx);
    int y = ry + random(240 - ry - ry);
    AF.LCD.fillEllipse(x, y, rx, ry, random(0xFFFF));
  }

  delay(2000);
  AF.LCD.fillScreen(TFT_BLACK);

  for (int i = 0; i < 40; i++)
  {
    int rx = random(60);
    int ry = random(60);
    int x = rx + random(320 - rx - rx);
    int y = ry + random(240 - ry - ry);
    AF.LCD.drawEllipse(x, y, rx, ry, random(0xFFFF));
  }

  delay(2000);
}



