#include <Afantor.h>

void setup() 
{
  	AF.begin();

  	// Display QRCode
  	AF.LCD.qrcode("http://www.afantor.cc");

}

void loop() 
{
}
