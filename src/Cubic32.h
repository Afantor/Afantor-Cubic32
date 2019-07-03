// Copyright (c) Afantor. All rights reserved.

// Licensed under the MIT license. See LICENSE file in the project root for full license information.
/**
 * \par Copyright (C), 2016-2017, Afantor
 * \class Afantor
 * \brief   Afantor library.
 * @file    Afantor.h
 * @author  Afantor
 * @version V0.1.0
 * @date    2018/03/27
 * @brief   Header for Afantor.cpp module
 *
 * \par Description
 * This file is a drive for Afantor core.
 *
 * \par Method List:
 *    
 *  System:
        Afant.begin();
        Afant.update();

    LCD:
        Afant.LCD.setBrightness(uint8_t brightness);
        Afant.LCD.drawPixel(int16_t x, int16_t y, uint16_t color);
        Afant.LCD.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
        Afant.LCD.fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
        Afant.LCD.fillScreen(uint16_t color);
        Afant.LCD.drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
        Afant.LCD.drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,uint16_t color);
        Afant.LCD.fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
        Afant.LCD.fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,int16_t delta, uint16_t color);
        Afant.LCD.drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
        Afant.LCD.fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
        Afant.LCD.drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
        Afant.LCD.fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
        Afant.LCD.drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color);
        Afant.LCD.drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w, int16_t h),
        Afant.LCD.drawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg, uint8_t size);
        Afant.LCD.setCursor(uint16_t x0, uint16_t y0);
        Afant.LCD.setTextColor(uint16_t color);
        Afant.LCD.setTextColor(uint16_t color, uint16_t backgroundcolor);
        Afant.LCD.setTextSize(uint8_t size);
        Afant.LCD.setTextWrap(boolean w);
        Afant.LCD.printf();
        Afant.LCD.print();
        Afant.LCD.println();
        Afant.LCD.drawCentreString(const char *string, int dX, int poY, int font);
        Afant.LCD.drawRightString(const char *string, int dX, int poY, int font);
        Afant.LCD.drawJpg(const uint8_t *jpg_data, size_t jpg_len, uint16_t x, uint16_t y);
        Afant.LCD.drawJpgFile(fs::FS &fs, const char *path, uint16_t x, uint16_t y);
        Afant.LCD.drawBmpFile(fs::FS &fs, const char *path, uint16_t x, uint16_t y);


    Button:
        Afant.BtnA/B/C/D.read();
        Afant.BtnA/B/C/D.isPressed();
        Afant.BtnA/B/C/D.isReleased();
        Afant.BtnA/B/C/D.wasPressed();
        Afant.BtnA/B/C/D.wasReleased();
        Afant.BtnA/B/C/D.pressedFor(uint32_t ms);
        Afant.BtnA/B/C/D.releasedFor(uint32_t ms);
        Afant.BtnA/B/C/D.lastChange();

    Speaker:
        Afant.Speaker.tone(uint32_t freq);
        Afant.Speaker.tone(freq, time);
        Afant.Speaker.beep();
        Afant.Speaker.setBeep(uint16_t frequency, uint16_t duration);
        Afant.Speaker.mute();

    MPU6050:
        Afant.IMU.begin();
        Afant.IMU.update();
        Afant.IMU.getAngleX();
        Afant.IMU.getAngleY();
        Afant.IMU.getAngleZ();
        Afant.IMU.getGyroX();
        Afant.IMU.getGyroY();
        Afant.IMU.getGyroZ();
        Afant.IMU.getTemperature();

    SDCard：
        Afant.SDCard.init();

    Buzzer:

 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Blue God         2018/03/27         0.1.0            Rebuild the new.
 * </pre>
 *
 */

#ifndef _CUBIC32_H_
#define _CUBIC32_H_

#if defined(ESP32)

// #define MPU6050_INSDE
// #define AHT10_INSDE
// #define RTC_INSDE

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "FS.h"
#include "SD.h"

#include "lv_conf.h"
#include "littlevgl/lvgl.h"

#include "utility/bmp_map.h"
#include "utility/Config.h"
#include "utility/LCD_ILI9341.h"
#include "utility/TouchScreen.h"
#include "utility/Button.h"
#include "utility/Speaker.h"
#include "utility/Timer.h"
#include "utility/EasyBuzzer.h"

#ifdef AHT10_INSDE
#include "utility/AHT10.h"
#endif

#ifdef RTC_INSDE
#include "utility/PCF8563T.h"
#endif

#ifdef MPU6050_INSDE
#include "utility/MPU6050.h"
#include "utility/QuaternionFilters.h"
#endif


class Cubic32 {

 public:
    Cubic32();
    void begin(bool LCD_Enable = true, bool SD_Enable = true);
    void update();

    void setWakeupButton(uint8_t button);
    void powerOFF();

    // Button API
    //Button Btn = Button(BUTTON_PIN);

    // SPEAKER
    SPEAKER Speaker;
    // Buzzer
    EasyBuzzer Buzzer = EasyBuzzer();
    // LCD
    LCD_ILI9341 Lcd = LCD_ILI9341(TFT_CS_PIN, TFT_DC_PIN, TFT_RST_PIN);
    // UART
    // HardwareSerial Serial0 = HardwareSerial(0);
    // HardwareSerial Serial2 = HardwareSerial(2);

    // MPU6050
#ifdef MPU6050_INSDE
    MPU6050 IMU = MPU6050();
#endif

#ifdef AHT10_INSDE
    AHT10Class AHT10 = AHT10Class();
#endif

#ifdef RTC_INSDE
    PCF8563T RTC = PCF8563T();
#endif

 private:
   uint8_t _wakeupPin;
   bool isInited;
};

extern Cubic32 Cubic;
#define cubic Cubic
#define lcd Lcd

#else
#error “This library only supports boards with ESP32 processor.”
#endif

#endif

