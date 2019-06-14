//This example implements a simple sliding On/Off button. The example
// demonstrates drawing and touch operations.
//
//Thanks to Adafruit forums member Asteroid for the original sketch!
//
#include <Cubic32.h>

boolean RecordOn = false;

#define FRAME_X 210
#define FRAME_Y 180
#define FRAME_W 100
#define FRAME_H 50

#define REDBUTTON_X FRAME_X
#define REDBUTTON_Y FRAME_Y
#define REDBUTTON_W (FRAME_W/2)
#define REDBUTTON_H FRAME_H

#define GREENBUTTON_X (REDBUTTON_X + REDBUTTON_W)
#define GREENBUTTON_Y FRAME_Y
#define GREENBUTTON_W (FRAME_W/2)
#define GREENBUTTON_H FRAME_H

void drawFrame()
{
    Cubic.lcd.drawRect(FRAME_X, FRAME_Y, FRAME_W, FRAME_H, ILI9341_BLACK);
}

void redBtn()
{ 
    Cubic.lcd.fillRect(REDBUTTON_X, REDBUTTON_Y, REDBUTTON_W, REDBUTTON_H, ILI9341_RED);
    Cubic.lcd.fillRect(GREENBUTTON_X, GREENBUTTON_Y, GREENBUTTON_W, GREENBUTTON_H, ILI9341_BLUE);
    drawFrame();
    Cubic.lcd.setCursor(GREENBUTTON_X + 6 , GREENBUTTON_Y + (GREENBUTTON_H/2));
    Cubic.lcd.setTextColor(ILI9341_WHITE);
    Cubic.lcd.setTextSize(2);
    Cubic.lcd.println("ON");
    RecordOn = false;
}

void greenBtn()
{
    Cubic.lcd.fillRect(GREENBUTTON_X, GREENBUTTON_Y, GREENBUTTON_W, GREENBUTTON_H, ILI9341_GREEN);
    Cubic.lcd.fillRect(REDBUTTON_X, REDBUTTON_Y, REDBUTTON_W, REDBUTTON_H, ILI9341_BLUE);
    drawFrame();
    Cubic.lcd.setCursor(REDBUTTON_X + 6 , REDBUTTON_Y + (REDBUTTON_H/2));
    Cubic.lcd.setTextColor(ILI9341_WHITE);
    Cubic.lcd.setTextSize(2);
    Cubic.lcd.println("OFF");
    RecordOn = true;
}

void setup(void)
{
    Cubic.begin(true,false);
    Cubic.lcd.fillScreen(ILI9341_BLUE);
    Cubic.lcd.setRotation(1); 
}

void loop()
{
    redBtn();
    delay(500);
    greenBtn();
    delay(500);
}



