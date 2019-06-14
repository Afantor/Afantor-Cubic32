
/* Includes ------------------------------------------------------------------*/
#include <Afantor.h>

/* Private variables ---------------------------------------------------------*/

uint8_t keyPressed = BTN_NULL;
uint8_t keyPressedPrevious = BTN_NULL;

void setup()
{
  Serial.begin(115200);
  AF.begin();
  AF.LCD.print("Hello World");
}

void loop()
{
  keyPressedPrevious = keyPressed;
  keyPressed = AF.Btn.pressed();
  if (keyPressedPrevious != keyPressed)
  {
    if (keyPressed == BTN_A)
    {
      Serial.println("BTN_A pressed");
    }
    if (keyPressed == BTN_B)
    {
      Serial.println("BTN_B pressed");
    }
    if (keyPressed == BTN_C)
    {
      Serial.println("BTN_C pressed");
    }
    if (keyPressed == BTN_D)
    {
      Serial.println("BTN_D pressed");
    }
    if (keyPressed == BTN_NULL)
    {
      Serial.println("BTN NULL");
    }
  }
}
