/*
  This example draws fonts (as used by the Adafruit_GFX library) onto the
  screen. These fonts are called the GFX Free Fonts (GFXFF) in this library.

  Other True Type fonts could be converted using the utility within the
  "fontconvert" folder inside the library. This converted has also been
  copied from the Adafruit_GFX library.

  Since these fonts are a recent addition Adafruit do not have a tutorial
  available yet on how to use the utility.   Linux users will no doubt
  figure it out!  In the meantime there are 48 font files to use in sizes
  from 9 point to 24 point, and in normal, bold, and italic or oblique
  styles.

  This example sketch uses both the print class and drawString() functions
  to plot text to the screen.

  Make sure LOAD_GFXFF is defined in the User_Setup.h file within the
  TFT_eSPI library folder.

  --------------------------- NOTE ----------------------------------------
  The free font encoding format does not lend itself easily to plotting
  the background without flicker. For values that changes on screen it is
  better to use Fonts 1- 8 which are encoded specifically for rapid
  drawing with background.
  -------------------------------------------------------------------------
  
  >>>>>>>>>>>>>>>>>>>>>>>>>>> WARNING <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  As supplied with the default settings the sketch has 11 fonts loaded,
  i.e. GLCD (Font 1), Font 2, Font 4, Font 6, Font 7, Font 8 and five Free Fonts,
  even though they are not all used in the sketch.
  
  Disable fonts you do not need in User_Setup.h in the library folder.

  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  #########################################################################
*/

#include "Free_Fonts.h" // Include the header file attached to this sketch

#include <Afantor.h>


unsigned long drawTime = 0;

void setup(void) {

  AF.begin();

}

void loop() {

  int xpos =  0;
  int ypos = 40;

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Select different fonts to draw on screen using the print class
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  header("Using print() method", TFT_NAVY);

  // For comaptibility with Adafruit_GFX library the text background is not plotted when using the print class
  // even if we specify it.
  AF.LCD.setTextColor(TFT_YELLOW);
  AF.LCD.setCursor(xpos, ypos);    // Set cursor near top left corner of screen

  AF.LCD.setFreeFont(TT1);     // Select the orginal small TomThumb font
  AF.LCD.println();             // Move cursor down a line
  AF.LCD.print("The really tiny TomThumb font");    // Print the font name onto the TFT screen
  AF.LCD.println();
  AF.LCD.println();

  AF.LCD.setFreeFont(FSB9);   // Select Free Serif 9 point font, could use:
  // AF.LCD.setFreeFont(&FreeSerif9pt7b);
  AF.LCD.println();          // Free fonts plot with the baseline (imaginary line the letter A would sit on)
  // as the datum, so we must move the cursor down a line from the 0,0 position
  AF.LCD.print("Serif Bold 9pt");  // Print the font name onto the TFT screen

  AF.LCD.setFreeFont(FSB12);       // Select Free Serif 12 point font
  AF.LCD.println();                // Move cursor down a line
  AF.LCD.print("Serif Bold 12pt"); // Print the font name onto the TFT screen

  AF.LCD.setFreeFont(FSB18);       // Select Free Serif 12 point font
  AF.LCD.println();                // Move cursor down a line
  AF.LCD.print("Serif Bold 18pt"); // Print the font name onto the TFT screen

  AF.LCD.setFreeFont(FSB24);       // Select Free Serif 24 point font
  AF.LCD.println();                // Move cursor down a line
  AF.LCD.print("Serif Bold 24pt"); // Print the font name onto the TFT screen


  delay(4000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Now use drawString() so we can set font background colours and the datum
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  header("Using drawString()", TFT_BLACK);

  AF.LCD.setTextColor(TFT_WHITE, TFT_BLACK);

  AF.LCD.setTextDatum(TC_DATUM); // Centre text on x,y position

  xpos = AF.LCD.width() / 2; // Half the screen width
  ypos = 50;

  AF.LCD.setFreeFont(FSB9);                              // Select the font
  AF.LCD.drawString("Serif Bold 9pt", xpos, ypos, GFXFF);  // Draw the text string in the selected GFX free font
  ypos += AF.LCD.fontHeight(GFXFF);                      // Get the font height and move ypos down

  AF.LCD.setFreeFont(FSB12);
  AF.LCD.drawString("Serif Bold 12pt", xpos, ypos, GFXFF);
  ypos += AF.LCD.fontHeight(GFXFF);

  AF.LCD.setFreeFont(FSB18);
  AF.LCD.drawString("Serif Bold 18pt", xpos, ypos, GFXFF);
  ypos += AF.LCD.fontHeight(GFXFF);

  AF.LCD.setFreeFont(FSB24);
  AF.LCD.drawString("Serif Bold 24pt", xpos, ypos, GFXFF);
  ypos += AF.LCD.fontHeight(GFXFF);

  // Set text padding to 100 pixels wide area to over-write old values on screen
  AF.LCD.setTextPadding(100);
  for (int i = 0; i <= 20; i++) {
    AF.LCD.drawFloat(i / 10.0, 1, xpos, ypos, GFXFF);
    delay (200);
  }

  delay(4000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Same again but with colours that show bounding boxes
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


  header("With background", TFT_DARKGREY);

  AF.LCD.setTextColor(TFT_YELLOW, TFT_BLACK);

  AF.LCD.setTextDatum(TC_DATUM); // Centre text on x,y position

  xpos = AF.LCD.width() / 2; // Half the screen width
  ypos = 50;

  AF.LCD.setFreeFont(FSB9);                              // Select the font
  AF.LCD.drawString("Serif Bold 9pt", xpos, ypos, GFXFF);  // Draw the text string in the selected GFX free font
  ypos += AF.LCD.fontHeight(GFXFF);                        // Get the font height and move ypos down

  AF.LCD.setFreeFont(FSB12);
  AF.LCD.drawString("Serif Bold 12pt", xpos, ypos, GFXFF);
  ypos += AF.LCD.fontHeight(GFXFF);

  AF.LCD.setFreeFont(FSB18);
  AF.LCD.drawString("Serif Bold 18pt", xpos, ypos, GFXFF);
  ypos += AF.LCD.fontHeight(GFXFF);

  AF.LCD.setFreeFont(FSBI24);
  AF.LCD.drawString("Bold Italic 24pt", xpos, ypos, GFXFF);
  ypos += AF.LCD.fontHeight(GFXFF);

  // Set text padding to 100 pixels wide area to over-write old values on screen
  AF.LCD.setTextPadding(100);
  for (int i = 0; i <= 20; i++) {
    AF.LCD.drawFloat(i / 10.0, 1, xpos, ypos, GFXFF);
    delay (200);
  }

  delay(4000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Now show setting the 12 datum positions works with free fonts
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  // Numbers, floats and strings can be drawn relative to a datum
  header("Text with a datum", TFT_BLACK);
  AF.LCD.setTextColor(TFT_DARKGREY, TFT_BLACK);
  AF.LCD.setFreeFont(FSS12);
  AF.LCD.setTextDatum(TL_DATUM);
  AF.LCD.drawString("[Top left]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  AF.LCD.fillRect(0, 80, 320, 80, TFT_BLACK);
  AF.LCD.setTextDatum(TC_DATUM);
  AF.LCD.drawString("[Top centre]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  AF.LCD.fillRect(0, 80, 320, 80, TFT_BLACK);
  AF.LCD.setTextDatum(TR_DATUM);
  AF.LCD.drawString("[Top right]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  AF.LCD.fillRect(0, 80, 320, 80, TFT_BLACK);
  AF.LCD.setTextDatum(ML_DATUM);
  AF.LCD.drawString("[Middle left]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  AF.LCD.fillRect(0, 80, 320, 80, TFT_BLACK);
  AF.LCD.setTextDatum(MC_DATUM);
  AF.LCD.drawString("[Middle centre]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  AF.LCD.fillRect(0, 80, 320, 80, TFT_BLACK);
  AF.LCD.setTextDatum(MR_DATUM);
  AF.LCD.drawString("[Middle right]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  AF.LCD.fillRect(0, 80, 320, 80, TFT_BLACK);
  AF.LCD.setTextDatum(BL_DATUM);
  AF.LCD.drawString("[Bottom left]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  AF.LCD.fillRect(0, 80, 320, 80, TFT_BLACK);
  AF.LCD.setTextDatum(BC_DATUM);
  AF.LCD.drawString("[Bottom centre]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  AF.LCD.fillRect(0, 80, 320, 80, TFT_BLACK);
  AF.LCD.setTextDatum(BR_DATUM);
  AF.LCD.drawString("[Bottom right]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  AF.LCD.fillRect(0, 80, 320, 80, TFT_BLACK);
  AF.LCD.setTextDatum(L_BASELINE);
  AF.LCD.drawString("[Left baseline]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  AF.LCD.fillRect(0, 80, 320, 80, TFT_BLACK);
  AF.LCD.setTextDatum(C_BASELINE);
  AF.LCD.drawString("[Centre baseline]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  AF.LCD.fillRect(0, 80, 320, 80, TFT_BLACK);
  AF.LCD.setTextDatum(R_BASELINE);
  AF.LCD.drawString("[Right baseline]", 160, 120, GFXFF);
  drawDatumMarker(160,120);
  delay(1000);

  //while(1);
  delay(8000);

}

// Print the header for a display screen
void header(const char *string, uint16_t color)
{
  AF.LCD.fillScreen(color);
  AF.LCD.setTextSize(1);
  AF.LCD.setTextColor(TFT_MAGENTA, TFT_BLUE);
  AF.LCD.fillRect(0, 0, 320, 30, TFT_BLUE);
  AF.LCD.setTextDatum(TC_DATUM);
  AF.LCD.drawString(string, 160, 2, 4); // Font 4 for fast drawing with background
}

// Draw a + mark centred on x,y
void drawDatumMarker(int x, int y)
{
  AF.LCD.drawLine(x - 5, y, x + 5, y, TFT_GREEN);
  AF.LCD.drawLine(x, y - 5, x, y + 5, TFT_GREEN);
}


// There follows a crude way of flagging that this example sketch needs fonts which
// have not been enbabled in the User_Setup.h file inside the TFT_HX8357 library.
//
// These lines produce errors during compile time if settings in User_Setup are not correct
//
// The error will be "does not name a type" but ignore this and read the text between ''
// it will indicate which font or feature needs to be enabled
//
// Either delete all the following lines if you do not want warnings, or change the lines
// to suit your sketch modifications.

#ifndef LOAD_GLCD
//ERROR_Please_enable_LOAD_GLCD_in_User_Setup
#endif

#ifndef LOAD_FONT2
//ERROR_Please_enable_LOAD_FONT2_in_User_Setup!
#endif

#ifndef LOAD_FONT4
//ERROR_Please_enable_LOAD_FONT4_in_User_Setup!
#endif

#ifndef LOAD_FONT6
//ERROR_Please_enable_LOAD_FONT6_in_User_Setup!
#endif

#ifndef LOAD_FONT7
//ERROR_Please_enable_LOAD_FONT7_in_User_Setup!
#endif

#ifndef LOAD_FONT8
//ERROR_Please_enable_LOAD_FONT8_in_User_Setup!
#endif

#ifndef LOAD_GFXFF
ERROR_Please_enable_LOAD_GFXFF_in_User_Setup!
#endif

