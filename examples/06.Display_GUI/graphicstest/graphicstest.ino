/***************************************************
  This is our GFX example for the Adafruit ILI9341 Breakout and Shield
  ----> http://www.adafruit.com/products/1651

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/


#include <Cubic32.h>
        
void setup() {
  Cubic.begin(true,false);

  // read diagnostics (optional but can help debug problems)
  uint8_t x = Cubic.lcd.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = Cubic.lcd.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = Cubic.lcd.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = Cubic.lcd.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = Cubic.lcd.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 
  
  Serial.println(F("Benchmark                Time (microseconds)"));
  delay(10);
  Serial.print(F("Screen fill              "));
  Serial.println(testFillScreen());
  delay(500);

  Serial.print(F("Text                     "));
  Serial.println(testText());
  delay(3000);

  Serial.print(F("Lines                    "));
  Serial.println(testLines(ILI9341_CYAN));
  delay(500);

  Serial.print(F("Horiz/Vert Lines         "));
  Serial.println(testFastLines(ILI9341_RED, ILI9341_BLUE));
  delay(500);

  Serial.print(F("Rectangles (outline)     "));
  Serial.println(testRects(ILI9341_GREEN));
  delay(500);

  Serial.print(F("Rectangles (filled)      "));
  Serial.println(testFilledRects(ILI9341_YELLOW, ILI9341_MAGENTA));
  delay(500);

  Serial.print(F("Circles (filled)         "));
  Serial.println(testFilledCircles(10, ILI9341_MAGENTA));

  Serial.print(F("Circles (outline)        "));
  Serial.println(testCircles(10, ILI9341_WHITE));
  delay(500);

  Serial.print(F("Triangles (outline)      "));
  Serial.println(testTriangles());
  delay(500);

  Serial.print(F("Triangles (filled)       "));
  Serial.println(testFilledTriangles());
  delay(500);

  Serial.print(F("Rounded rects (outline)  "));
  Serial.println(testRoundRects());
  delay(500);

  Serial.print(F("Rounded rects (filled)   "));
  Serial.println(testFilledRoundRects());
  delay(500);

  Serial.println(F("Done!"));

}


void loop(void) {
  for(uint8_t rotation=0; rotation<4; rotation++) {
    Cubic.lcd.setRotation(rotation);
    testText();
    delay(1000);
  }
}

unsigned long testFillScreen() {
  unsigned long start = micros();
  Cubic.lcd.fillScreen(ILI9341_BLACK);
  yield();
  Cubic.lcd.fillScreen(ILI9341_RED);
  yield();
  Cubic.lcd.fillScreen(ILI9341_GREEN);
  yield();
  Cubic.lcd.fillScreen(ILI9341_BLUE);
  yield();
  Cubic.lcd.fillScreen(ILI9341_BLACK);
  yield();
  return micros() - start;
}

unsigned long testText() {
  Cubic.lcd.fillScreen(ILI9341_BLACK);
  unsigned long start = micros();
  Cubic.lcd.setCursor(0, 0);
  Cubic.lcd.setTextColor(ILI9341_WHITE);  Cubic.lcd.setTextSize(1);
  Cubic.lcd.println("Hello World!");
  Cubic.lcd.setTextColor(ILI9341_YELLOW); Cubic.lcd.setTextSize(2);
  Cubic.lcd.println(1234.56);
  Cubic.lcd.setTextColor(ILI9341_RED);    Cubic.lcd.setTextSize(3);
  Cubic.lcd.println(0xDEADBEEF, HEX);
  Cubic.lcd.println();
  Cubic.lcd.setTextColor(ILI9341_GREEN);
  Cubic.lcd.setTextSize(5);
  Cubic.lcd.println("Groop");
  Cubic.lcd.setTextSize(2);
  Cubic.lcd.println("I implore thee,");
  Cubic.lcd.setTextSize(1);
  Cubic.lcd.println("my foonting turlingdromes.");
  Cubic.lcd.println("And hooptiously drangle me");
  Cubic.lcd.println("with crinkly bindlewurdles,");
  Cubic.lcd.println("Or I will rend thee");
  Cubic.lcd.println("in the gobberwarts");
  Cubic.lcd.println("with my blurglecruncheon,");
  Cubic.lcd.println("see if I don't!");
  return micros() - start;
}

unsigned long testLines(uint16_t color) {
  unsigned long start, t;
  int           x1, y1, x2, y2,
                w = Cubic.lcd.width(),
                h = Cubic.lcd.height();

  Cubic.lcd.fillScreen(ILI9341_BLACK);
  yield();
  
  x1 = y1 = 0;
  y2    = h - 1;
  start = micros();
  for(x2=0; x2<w; x2+=6) Cubic.lcd.drawLine(x1, y1, x2, y2, color);
  x2    = w - 1;
  for(y2=0; y2<h; y2+=6) Cubic.lcd.drawLine(x1, y1, x2, y2, color);
  t     = micros() - start; // fillScreen doesn't count against timing

  yield();
  Cubic.lcd.fillScreen(ILI9341_BLACK);
  yield();

  x1    = w - 1;
  y1    = 0;
  y2    = h - 1;
  start = micros();
  for(x2=0; x2<w; x2+=6) Cubic.lcd.drawLine(x1, y1, x2, y2, color);
  x2    = 0;
  for(y2=0; y2<h; y2+=6) Cubic.lcd.drawLine(x1, y1, x2, y2, color);
  t    += micros() - start;

  yield();
  Cubic.lcd.fillScreen(ILI9341_BLACK);
  yield();

  x1    = 0;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for(x2=0; x2<w; x2+=6) Cubic.lcd.drawLine(x1, y1, x2, y2, color);
  x2    = w - 1;
  for(y2=0; y2<h; y2+=6) Cubic.lcd.drawLine(x1, y1, x2, y2, color);
  t    += micros() - start;

  yield();
  Cubic.lcd.fillScreen(ILI9341_BLACK);
  yield();

  x1    = w - 1;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for(x2=0; x2<w; x2+=6) Cubic.lcd.drawLine(x1, y1, x2, y2, color);
  x2    = 0;
  for(y2=0; y2<h; y2+=6) Cubic.lcd.drawLine(x1, y1, x2, y2, color);

  yield();
  return micros() - start;
}

unsigned long testFastLines(uint16_t color1, uint16_t color2) {
  unsigned long start;
  int           x, y, w = Cubic.lcd.width(), h = Cubic.lcd.height();

  Cubic.lcd.fillScreen(ILI9341_BLACK);
  start = micros();
  for(y=0; y<h; y+=5) Cubic.lcd.drawFastHLine(0, y, w, color1);
  for(x=0; x<w; x+=5) Cubic.lcd.drawFastVLine(x, 0, h, color2);

  return micros() - start;
}

unsigned long testRects(uint16_t color) {
  unsigned long start;
  int           n, i, i2,
                cx = Cubic.lcd.width()  / 2,
                cy = Cubic.lcd.height() / 2;

  Cubic.lcd.fillScreen(ILI9341_BLACK);
  n     = min(Cubic.lcd.width(), Cubic.lcd.height());
  start = micros();
  for(i=2; i<n; i+=6) {
    i2 = i / 2;
    Cubic.lcd.drawRect(cx-i2, cy-i2, i, i, color);
  }

  return micros() - start;
}

unsigned long testFilledRects(uint16_t color1, uint16_t color2) {
  unsigned long start, t = 0;
  int           n, i, i2,
                cx = Cubic.lcd.width()  / 2 - 1,
                cy = Cubic.lcd.height() / 2 - 1;

  Cubic.lcd.fillScreen(ILI9341_BLACK);
  n = min(Cubic.lcd.width(), Cubic.lcd.height());
  for(i=n; i>0; i-=6) {
    i2    = i / 2;
    start = micros();
    Cubic.lcd.fillRect(cx-i2, cy-i2, i, i, color1);
    t    += micros() - start;
    // Outlines are not included in timing results
    Cubic.lcd.drawRect(cx-i2, cy-i2, i, i, color2);
    yield();
  }

  return t;
}

unsigned long testFilledCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int x, y, w = Cubic.lcd.width(), h = Cubic.lcd.height(), r2 = radius * 2;

  Cubic.lcd.fillScreen(ILI9341_BLACK);
  start = micros();
  for(x=radius; x<w; x+=r2) {
    for(y=radius; y<h; y+=r2) {
      Cubic.lcd.fillCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

unsigned long testCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int           x, y, r2 = radius * 2,
                w = Cubic.lcd.width()  + radius,
                h = Cubic.lcd.height() + radius;

  // Screen is not cleared for this one -- this is
  // intentional and does not affect the reported time.
  start = micros();
  for(x=0; x<w; x+=r2) {
    for(y=0; y<h; y+=r2) {
      Cubic.lcd.drawCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

unsigned long testTriangles() {
  unsigned long start;
  int           n, i, cx = Cubic.lcd.width()  / 2 - 1,
                      cy = Cubic.lcd.height() / 2 - 1;

  Cubic.lcd.fillScreen(ILI9341_BLACK);
  n     = min(cx, cy);
  start = micros();
  for(i=0; i<n; i+=5) {
    Cubic.lcd.drawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      Cubic.lcd.color565(i, i, i));
  }

  return micros() - start;
}

unsigned long testFilledTriangles() {
  unsigned long start, t = 0;
  int           i, cx = Cubic.lcd.width()  / 2 - 1,
                   cy = Cubic.lcd.height() / 2 - 1;

  Cubic.lcd.fillScreen(ILI9341_BLACK);
  start = micros();
  for(i=min(cx,cy); i>10; i-=5) {
    start = micros();
    Cubic.lcd.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      Cubic.lcd.color565(0, i*10, i*10));
    t += micros() - start;
    Cubic.lcd.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      Cubic.lcd.color565(i*10, i*10, 0));
    yield();
  }

  return t;
}

unsigned long testRoundRects() {
  unsigned long start;
  int           w, i, i2,
                cx = Cubic.lcd.width()  / 2 - 1,
                cy = Cubic.lcd.height() / 2 - 1;

  Cubic.lcd.fillScreen(ILI9341_BLACK);
  w     = min(Cubic.lcd.width(), Cubic.lcd.height());
  start = micros();
  for(i=0; i<w; i+=6) {
    i2 = i / 2;
    Cubic.lcd.drawRoundRect(cx-i2, cy-i2, i, i, i/8, Cubic.lcd.color565(i, 0, 0));
  }

  return micros() - start;
}

unsigned long testFilledRoundRects() {
  unsigned long start;
  int           i, i2,
                cx = Cubic.lcd.width()  / 2 - 1,
                cy = Cubic.lcd.height() / 2 - 1;

  Cubic.lcd.fillScreen(ILI9341_BLACK);
  start = micros();
  for(i=min(Cubic.lcd.width(), Cubic.lcd.height()); i>20; i-=6) {
    i2 = i / 2;
    Cubic.lcd.fillRoundRect(cx-i2, cy-i2, i, i, i/8, Cubic.lcd.color565(0, i, 0));
    yield();
  }

  return micros() - start;
}
