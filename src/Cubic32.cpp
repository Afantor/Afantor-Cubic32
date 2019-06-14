// Copyright (c) Afantor. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "Cubic32.h"

Cubic32::Cubic32():isInited(0) {
}

void Cubic32::begin(bool LCD_Enable, bool SD_Enable) {
    // Correct init once
    if (isInited == true) {
        return;
    } else {
        isInited = true;
    }
    // UART 
    Serial.begin(115200);
    Serial.flush();
    Serial.print("Afantor-Core initializing...");

    // I2C Startup BUG?
    // pinMode(SCL, OUTPUT);
    // digitalWrite(SCL, 1);

    // TONE
    Speaker.begin();

    //Buzzer
    Buzzer.setPin(Buzzer_PIN);

    // Setup the button with an internal pull-up
    // pinMode(BUTTON_PIN, INPUT_PULLUP);
    // LCD INIT
    if (LCD_Enable == true) {
        pinMode(TFT_BLK_PIN, OUTPUT);
        digitalWrite(TFT_BLK_PIN, LOW);
        Lcd.begin();
    }
    // TF Card
    if (SD_Enable == true)
        SD.begin(SDCARD_CS_PIN, SPI, 40000000);
//    
//    // Set wakeup button
//    setWakeupButton(BUTTON_A_PIN);

    // MPU6050
#ifdef MPU6050_INSDE
    Wire.begin();
#endif

    //ANT10
#ifdef ANT10_INSDE
    Wire.begin();

    if(ANT10.begin(eAHT10Address_Low))
        Serial.println("Init AHT10 Sucess.");
    else
        Serial.println("Init AHT10 Failure.");
#endif    

    Serial.println("OK");
}

void Cubic32::update() {

//    //Button update
//    BtnA.read();
//    BtnB.read();
//    BtnC.read();
//
    //Speaker update
    Speaker.update();
}

void Cubic32::setWakeupButton(uint8_t button) {
    _wakeupPin = button;
}

void Cubic32::powerOFF() {
    
    // power off the Lcd
//    Lcd.setBrightness(0);
//    Lcd.sleep();
//
//    // ESP32 into deep sleep
//    USE_SERIAL.printf("Enabling EXT0 wakeup on pins GPIO%d\n", _wakeupPin);
//    esp_sleep_enable_ext0_wakeup((gpio_num_t)_wakeupPin , LOW);
//    
//    while(digitalRead(_wakeupPin) == LOW) {
//        delay(10);
//    }
//    USE_SERIAL.println("On deep sleep mode.");
//    esp_deep_sleep_start();
//    USE_SERIAL.println("On power OFF fail!");
}

Cubic32 Cubic;
