/**
 * \par Copyright (C), 2012-2019, Afantor
 * \class   Button
 * \brief   Driver for Button module.
 * @file    Button.h
 * @author  Afantor
 * @version V1.0.0
 * @date    2018/03/24
 * @brief   Header for Button.cpp module
 *
 * \par Copyright
 * This software is Copyright (C), 2012-2016, Afantor. Use is subject to license \n
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
 * This file is the drive for 4 Button module, It supports
 *      Me-4 Button V1.0 module provided by Afantor.
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
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _Button_H
#define _Button_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "Config.h"

/* Exported macro ------------------------------------------------------------*/
#define KEY_NULL_VALUE   (962)     // 1023*((5-0.3)/5)
#define KEY_1_VALUE      (0)
#define KEY_2_VALUE      (481)     // 962/2
#define KEY_3_VALUE      (641)     // 962*2/3
#define KEY_4_VALUE      (721)     // 962*3/4


#define DEBOUNCED_INTERVAL (8)
// If you want key response faster, you can set DEBOUNCED_INTERVAL to a
// smaller number.


/**
 * Class: Button
 * \par Description
 * Declaration of Class Button
 */
class Button
{
public:
/**
 * Alternate Constructor which can call your own function to map the _KeyPin to arduino port,
 * \param[in]
 *    port - arduino gpio number
 */
  Button(uint8_t pin);

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
  void setpin(uint8_t pin);

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
  uint8_t pressed(void);
private:
  volatile unsigned long previous_time;
  volatile unsigned long key_debounced_count;
  volatile unsigned long key_match_count;
  volatile unsigned long key_debounced_value;
  volatile int16_t  Pre_Button_Value;
  volatile uint8_t  _KeyPin;
};
#endif // Button_H
