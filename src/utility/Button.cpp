/**   
 * \par Copyright (C), 2012-2019, Afantor
 * \class   Button
 * \brief   Driver for Button module.
 * @file    Button.cpp
 * @author  Afantor
 * @version V1.0.0
 * @date    2018/03/24
 * @brief   Driver for Button module
 *
 * \par Copyright
 * This software is Copyright (C), 2012-2019, Afantor. Use is subject to license \n
 * conditions. The main licensing options available are GPL V2 or Commercial: \n
 *
 * \par Open Source Licensing GPL V2
 * This is the appropriate option if you want to share the source code of your \n
 * application with everyone you distribute it to, and you also want to give them \n
 * the right to share who uses it. If you wish to use this software under Open \n
 * Source Licensing, you must contribute all your source code to the open source \n
 * community in accordance with the GPL Version 2 when your application is \n
 * distributed. See http://www.gnu.org/copyleft/gpl.html
 *
 * \par Description
 * This file is a drive for Button module, It supports Button V1.0 device provided 
 * by Afantor.
 *
 * \par Method List:
 *
 *    1.  void    Button::setpin(uint8_t port);
 *    2.  uint8_t Button::pressed();
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Blue God         2018/03/24        1.0.0            Rebuild the old lib.
 * </pre>
 *
 * @example ButtonTest.ino
 */

/* Includes ------------------------------------------------------------------*/
#include "Button.h"

/* Private functions ---------------------------------------------------------*/

/**
 * Alternate Constructor which can call your own function to map the _KeyPin to arduino port,
 * \param[in]
 *    port - arduino gpio number
 */
Button::Button(uint8_t pin)
{
  _KeyPin = pin;
  Pre_Button_Value = 950;
}

/**
 * \par Function
 *    setpin
 * \par Description
 *    Set the PIN for button module.
 * \param[in]
 *    port - arduino gpio number
 * \par Output
 *    None
 * \return
 *    None
 * \par Others
 *    None
 */
void Button::setpin(uint8_t pin)
{
  _KeyPin = pin;
  Pre_Button_Value = 950;
}

/**
 * \par Function
 *    pressed
 * \par Description
 *    Read key ADC value to a variable.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \return
 *    Return the key vlaue, the value maybe  KEY_1,KEY_2,KEY_3,KEY_4,KEY_NULL.
 * \par Others
 *    The key should periodically read, if it was delayed, It will affect the sensitivity of the keys
 */
uint8_t Button::pressed(void)
{
  uint8_t returnKey      = BUTTON_NULL;
  int16_t key_temp_value = BUTTON_NULL;
  int16_t button_key_val = Pre_Button_Value;
  uint32_t current_time  = 0;
  // current_time will be return to 0 after about 50 days
  // 2E32 / (float)(24*3600*1000) = 49.71026
  current_time = millis();
  if (current_time - previous_time > DEBOUNCED_INTERVAL)
  {
    // This statement will handle rollover itself, see more in arduino site.
    // http://playground.arduino.cc/Code/TimingRollover
    // If you want key resbonse faster, you can set DEBOUNCED_INTERVAL to a
    // smaller number in Button.h.
    previous_time = current_time;

    key_temp_value = analogRead(_KeyPin);

    if (key_debounced_count == 0)
    {
      key_debounced_value = key_temp_value;
    }
    if (abs(key_temp_value - key_debounced_value) < 20)
    {
      key_match_count++;
    }
    key_debounced_count++;
  }

  if (key_debounced_count == 5)
  {
    key_debounced_count = 0;
    if (key_match_count > 2)
    {
      button_key_val = key_debounced_value;
      Pre_Button_Value = button_key_val;
    }
    else
    {
      button_key_val = Pre_Button_Value;
    }
    key_match_count = 0;
  }

  button_key_val = button_key_val / 100;
  // Division is slow in 8bit MCU, division should be replaced with right shift.
  switch (button_key_val)
  {
    case 0:
      returnKey = BUTTON_A;
      break;

    case 4:
    case 5:
      returnKey = BUTTON_B;
      break;

    case 6:
      returnKey = BUTTON_C;
      break;

    case 7:
      returnKey = BUTTON_D;
      break;

    case 9:
    case 10:
      returnKey = BUTTON_NULL;
      break;
  }
  return(returnKey);
}

