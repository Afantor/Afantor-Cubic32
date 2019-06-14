/*  
 Test the AF.LCD.print() viz embedded AF.LCD.write() function

 This sketch used font 2, 4, 7

 Make sure all the display driver and pin comnenctions are correct by
 editting the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */


#include <Afantor.h>

#define TFT_GREY 0x5AEB // New colour


void setup(void) {
  AF.begin();
}

void loop() {
  
  // Fill screen with grey so we can see the effect of printing with and without 
  // a background colour defined
  AF.LCD.fillScreen(TFT_GREY);
  
  // Set "cursor" at top left corner of display (0,0) and select font 2
  // (cursor will move to next line automatically during printing with 'AF.LCD.println'
  //  or stay on the line is there is room for the text with AF.LCD.print)
  AF.LCD.setCursor(0, 0, 2);
  // Set the font colour to be white with a black background, set text size multiplier to 1
  AF.LCD.setTextColor(TFT_WHITE,TFT_BLACK);  AF.LCD.setTextSize(1);
  // We can now plot text on screen using the "print" class
  AF.LCD.println("Hello World!");
  
  // Set the font colour to be yellow with no background, set to font 7
  AF.LCD.setTextColor(TFT_YELLOW); AF.LCD.setTextFont(7);
  AF.LCD.println(1234.56);
  
  // Set the font colour to be red with black background, set to font 4
  AF.LCD.setTextColor(TFT_RED,TFT_BLACK);    AF.LCD.setTextFont(4);
  //AF.LCD.println(3735928559L, HEX); // Should print DEADBEEF

  // Set the font colour to be green with black background, set to font 4
  AF.LCD.setTextColor(TFT_GREEN,TFT_BLACK);
  AF.LCD.setTextFont(4);
  AF.LCD.println("Groop");
  AF.LCD.println("I implore thee,");

  // Change to font 2
  AF.LCD.setTextFont(2);
  AF.LCD.println("my foonting turlingdromes.");
  AF.LCD.println("And hooptiously drangle me");
  AF.LCD.println("with crinkly bindlewurdles,");
  // This next line is deliberately made too long for the display width to test
  // automatic text wrapping onto the next line
  AF.LCD.println("Or I will rend thee in the gobberwarts with my blurglecruncheon, see if I don't!");
  
  // Test some print formatting functions
  float fnumber = 123.45;
   // Set the font colour to be blue with no background, set to font 4
  AF.LCD.setTextColor(TFT_BLUE);    AF.LCD.setTextFont(4);
  AF.LCD.print("Float = "); AF.LCD.println(fnumber);           // Print floating point number
  AF.LCD.print("Binary = "); AF.LCD.println((int)fnumber, BIN); // Print as integer value in binary
  AF.LCD.print("Hexadecimal = "); AF.LCD.println((int)fnumber, HEX); // Print as integer number in Hexadecimal
  delay(10000);
}



