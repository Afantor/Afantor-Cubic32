/*
 An example showing rainbow colours on a 2.2" TFT LCD screen
 and to show basic examples of font use.

 This sketch uses the GLCD, 2, 4, 6 fonts only.

 Make sure all the display driver and pin comnenctions are correct by
 editting the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */

#include <Afantor.h>

unsigned long targetTime = 0;
byte red = 31;
byte green = 0;
byte blue = 0;
byte state = 0;
unsigned int colour = red << 11; // Colour order is RGB 5+6+5 bits each

void setup(void) {
  Serial.begin(9600);
  AF.begin();
  AF.LCD.setRotation(0);
  AF.LCD.fillScreen(TFT_BLACK);

  targetTime = millis() + 1000;
}

void loop() {

  if (targetTime < millis()) {
    targetTime = millis() + 10000;

    rainbow_fill(); // Fill the screen with rainbow colours

    // The standard AdaFruit font still works as before
    AF.LCD.setTextColor(TFT_BLACK); // Background is not defined so it is transparent
 
    AF.LCD.setCursor (60, 5);
    AF.LCD.setTextFont(0);        // Select font 0 which is the Adafruit font
    AF.LCD.print("Original Adafruit font!");

    //AF.LCD.drawString("Original Adafruit font!",60,5,1); 

    // The new larger fonts do not need to use the .setCursor call, coords are embedded
    AF.LCD.setTextColor(TFT_BLACK); // Do not plot the background colour
    // Overlay the black text on top of the rainbow plot (the advantage of not drawing the backgorund colour!)
    AF.LCD.drawCentreString("Font size 2", 120, 14, 2); // Draw text centre at position 120, 14 using font 2
    AF.LCD.drawCentreString("Font size 4", 120, 30, 4); // Draw text centre at position 120, 30 using font 4
    AF.LCD.drawCentreString("12.34", 120, 54, 6);       // Draw text centre at position 120, 54 using font 6

    AF.LCD.drawCentreString("12.34 is in font size 6", 120, 92, 2); // Draw text centre at position 120, 92 using font 2
    // Note the x position is the top of the font!

    // draw a floating point number
    float pi = 3.14159; // Value to print
    int precision = 3;  // Number of digits after decimal point
    int xpos = 90;      // x position
    int ypos = 110;     // y position
    int font = 2;       // font number 2
    xpos += AF.LCD.drawFloat(pi, precision, xpos, ypos, font); // Draw rounded number and return new xpos delta for next print position
    AF.LCD.drawString(" is pi", xpos, ypos, font);             // Continue printing from new x position

    AF.LCD.setTextSize(1);           // We are using a size multiplier of 1

    AF.LCD.setTextColor(TFT_BLACK);  // Set text colour to black, no background (so transparent)

    AF.LCD.setCursor(36, 150, 4);    // Set cursor to x = 36, y = 150 and use font 4
    AF.LCD.println("Transparent...");  // As we use println, the cursor moves to the next line

    AF.LCD.setCursor(30, 175);    // Set cursor to x = 30, y = 175
    AF.LCD.setTextColor(TFT_WHITE, TFT_BLACK);  // Set text colour to white and background to black
    AF.LCD.println("White on black");

    AF.LCD.setTextFont(4);        // Select font 4 without moving cursor
    AF.LCD.setCursor(50, 210);    // Set cursor to x = 50, y = 210 without changing the font
    AF.LCD.setTextColor(TFT_WHITE);
    // By using #TFT print we can use all the formatting features like printing HEX
    AF.LCD.print(57005, HEX);    // Cursor does no move to next line
    AF.LCD.println(48879, HEX);  // print and move cursor to next line

    AF.LCD.setTextColor(TFT_GREEN, TFT_BLACK); // This time we will use green text on a black background
    AF.LCD.setTextFont(2); // Select font 2
    //Text will wrap to the next line if needed, by luck it breaks the lines at spaces!
    AF.LCD.println(" Ode to a Small Lump of Green Putty I Found in My Armpit One Midsummer Morning ");
  }
}

// Fill screen with a rainbow pattern
void rainbow_fill()
{
  // The colours and state are not initialised so the start colour changes each time the funtion is called
  
  for (int i = 319; i > 0; i--) {
    // Draw a vertical line 1 pixel wide in the selected colour
    AF.LCD.drawFastHLine(0, i, AF.LCD.width(), colour); // in this example AF.LCD.width() returns the pixel width of the display
    // This is a "state machine" that ramps up/down the colour brightnesses in sequence
    switch (state) {
      case 0:
        green ++;
        if (green == 64) {
          green = 63;
          state = 1;
        }
        break;
      case 1:
        red--;
        if (red == 255) {
          red = 0;
          state = 2;
        }
        break;
      case 2:
        blue ++;
        if (blue == 32) {
          blue = 31;
          state = 3;
        }
        break;
      case 3:
        green --;
        if (green == 255) {
          green = 0;
          state = 4;
        }
        break;
      case 4:
        red ++;
        if (red == 32) {
          red = 31;
          state = 5;
        }
        break;
      case 5:
        blue --;
        if (blue == 255) {
          blue = 0;
          state = 0;
        }
        break;
    }
    colour = red << 11 | green << 5 | blue;
  }
}



