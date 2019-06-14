/*
  Example for TFT_eSPI library

  Created by Bodmer 31/12/16

  This example draws all fonts (as used by the Adafruit_GFX library) onto the
  screen. These fonts are called the GFX Free Fonts (GFXFF) in this library.

  The fonts are referenced by a short name, see the Free_Fonts.h file
  attached to this sketch.

  Other True Type fonts could be converted using the utility within the
  "fontconvert" folder inside the library. This converted has also been
  copied from the Adafruit_GFX library. 

  Since these fonts are a recent addition Adafruit do not have a tutorial
  available yet on how to use the fontconvert utility.   Linux users will
  no doubt figure it out!  In the meantime there are 48 font files to use
  in sizes from 9 point to 24 point, and in normal, bold, and italic or
  oblique styles.

  This example sketch uses both the print class and drawString() functions
  to plot text to the screen.

  Make sure LOAD_GFXFF is defined in the User_Setup.h file within the
  library folder.

  --------------------------- NOTE ----------------------------------------
  The free font encoding format does not lend itself easily to plotting
  the background without flicker. For values that changes on screen it is
  better to use Fonts 1- 8 which are encoded specifically for rapid
  drawing with background.
  -------------------------------------------------------------------------

  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  ######       TO SELECT YOUR DISPLAY TYPE AND ENABLE FONTS          ######
  #########################################################################
*/

#define TEXT "aA MWyz~12" // Text that will be printed on screen in any font

#include "Free_Fonts.h" // Include the header file attached to this sketch

#include <Afantor.h>


unsigned long drawTime = 0;

void setup(void) {

  AF.begin();

}

void loop() {

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Show all 48 fonts in centre of screen ( x,y coordinate 160,120)
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  // Where font sizes increase the screen is not cleared as the larger fonts overwrite
  // the smaller one with the background colour.

  // Set text datum to middle centre
  AF.LCD.setTextDatum(MC_DATUM);

  // Set text colour to orange with black background
  AF.LCD.setTextColor(TFT_WHITE, TFT_BLACK);
  
  AF.LCD.fillScreen(TFT_BLACK);            // Clear screen
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF1, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF1);                 // Select the font
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);// Print the string name of the font
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF2, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF2);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF3, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF3);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF4, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF4);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  
  AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF5, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF5);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF6, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF6);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF7, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF7);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF8, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF8);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  
  AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF9, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF9);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF10, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF10);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF11, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF11);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF12, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF12);
    AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  
  AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF13, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF13);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF14, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF14);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF15, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF15);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF16, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF16);
    AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  
  AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF17, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF17);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF18, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF18);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF19, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF19);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF20, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF20);
    AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  
  AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF21, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF21);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF22, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF22);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF23, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF23);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF24, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF24);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  
  AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF25, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF25);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF26, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF26);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF27, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF27);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF28, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF28);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  
  AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF29, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF29);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF30, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF30);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF31, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF31);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF32, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF32);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  
  AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF33, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF33);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF34, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF34);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF35, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF35);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF36, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF36);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  
  AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF37, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF37);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF38, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF38);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF39, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF39);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF40, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF40);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  
  AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF41, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF41);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF42, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF42);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF43, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF43);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF44, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF44);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  
  AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF45, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF45);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF46, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF46);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF47, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF47);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);
  //AF.LCD.fillScreen(TFT_BLACK);
  AF.LCD.setFreeFont(FF18);                 // Select the font
  AF.LCD.drawString(sFF48, 160, 60, GFXFF);// Print the string name of the font
  AF.LCD.setFreeFont(FF48);
  AF.LCD.drawString(TEXT, 160, 120, GFXFF);
  delay(1000);

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

#ifndef LOAD_GFXFF
ERROR_Please_enable_LOAD_GFXFF_in_User_Setup!
#endif

