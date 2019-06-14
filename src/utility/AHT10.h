/*
  AHT10 - A Humidity Library for Arduino.

  Supported Sensor modules:
    AHT10 Module

 * This file is part of AHT10.
 *
 * AHT10 is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or(at your option) any later version.
 *
 * Sodaq_SHT2x is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with AHT10.  If not, see
 * <http://www.gnu.org/licenses/>.
 */


#ifndef _AHT10_H
#define _AHT10_H

#include <stdint.h>

typedef enum {
    eAHT10Address_default = 0x38,
    eAHT10Address_Low     = 0x38,
    eAHT10Address_High    = 0x39,
} HUM_SENSOR_T;

typedef unsigned char Sensor_CMD;

class AHT10Class
{
  public:
    AHT10Class(void);
    boolean begin(unsigned char _AHT10_address = eAHT10Address_default);
    float GetHumidity(void);
    float GetTemperature(void);
    float GetDewPoint(void);
    unsigned char readStatus(void);
    void Reset(void);
  private:
    unsigned long readSensor(boolean GetDataCmd);
    unsigned char AHT10_address;
};

#endif
