/*
Name:		Config.h
Version:	1.0.0
Created:	6/13/2019 12:03:48 AM
Author:		Afantor
Github:		https://github.com/Afantor/Afantor-Cubic32.git
Copyright (c) 2019 Afantor
*/

#pragma once

#ifndef _CONFIG_H_
#define _CONFIG_H_
//buzzer
#define DEFAULT_PIN			4		// Default pin number where the buzzer is connected.	
#define DEFAULT_FREQ		1000    // Default frequency.
#define DEFAULT_CHANNEL		0		// Default PWM channel.
#define DEFAULT_RESOLUTION	8		// Default resolution.
#define MINIMUM_INTERVAL    20      // Minimum interval allowed in milliseconds(ms).

#define DEFAULT_ON_DURATION		100 // Default ON duration of a cycle in milliseconds(ms).
#define DEFAULT_OFF_DURATION	100 // Default OFF duration of a cycle in milliseconds(ms).
#define DEFAULT_PAUSE_DURATION	100 // Default PAUSE duration of a cycle in milliseconds(ms).

// Buzzer PIN
#define Buzzer_PIN 	12

// SPI LCD Screen
#define TFT_BLK_PIN 	4
#define TFT_MISO_PIN 	-1
#define TFT_MOSI_PIN 	13
#define TFT_SCL_PIN 	14
#define TFT_CS_PIN 		15		// Chip select control pin
#define TFT_DC_PIN 		2		// Data Command control pin
#define TFT_RST_PIN 	27		// Reset pin (could connect to RST pin)
//#define TFT_RST  -1  // Set TFT_RST to -1 if display RESET is connected to ESP32 board RST


// SD card
#define SDCARD_CS_PIN 	5

// Buttons
#define BTN_NULL    (0)
#define BTN_A       (1)
#define BTN_B       (2)
#define BTN_C       (3)
#define BTN_D       (4)
#define BUTTON_NULL   (0)
#define BUTTON_A      (1)
#define BUTTON_B      (2)
#define BUTTON_C      (3)
#define BUTTON_D      (4)


#define BUTTON_PIN 	39

// SPEAKER PIN
#define SPEAKER_PIN 	25
#define TONE_PIN_CHANNEL 0

// UART
#define USE_SERIAL		Serial

#define FALSE  (0)
#define TRUE   (1)

#endif /* SETTINGS_C */
