// Copyright 2023 David SPORN
// ---
// This file is part of 'SevenSegments-by-sporniket'.
// ---
// 'SevenSegments-by-sporniket' is free software: you can redistribute it and/or 
// modify it under the terms of the GNU General Public License as published 
// by the Free Software Foundation, either version 3 of the License, or 
// (at your option) any later version.

// 'SevenSegments-by-sporniket' is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General 
// Public License for more details.

// You should have received a copy of the GNU General Public License along 
// with 'SevenSegments-by-sporniket'. If not, see <https://www.gnu.org/licenses/>. 

#ifndef SEVEN_SEGMENTS_TYPES_HPP
#define SEVEN_SEGMENTS_TYPES_HPP

// standard includes
#include <cstdint>

// esp32 includes

// project includes

/** @brief type for storing digit data. */
using SevenSegmentsDigit = uint8_t;
/** @brief type for storing the switch on/off setting.*/
using SevenSegmentsSwitchedOn = bool;
/** @brief type for storing the brightness setting.*/
using SevenSegmentsBrightness = uint8_t;

/** @brief the absolute maximum number of digits */
const uint8_t SEVEN_SEGMENTS_MAX_DIGITS = 16;

/** @brief Control register of the display, separated into elemental functions.
 */
struct SevenSegmentsControlRegisters {
  /** @brief store the state ON (true)/OFF (false) of the display.
   */
  SevenSegmentsSwitchedOn switchedOn = false;
  /** @brief store the brightness setting.
   */
  SevenSegmentsBrightness brightness = 0;
};

/** @brief Actual data of the display. */
struct SevenSegmentsDataRegisters {
  /** @brief store the number of digits to use. */
  uint8_t size = 0;
  /** @brief store the content of the digits to send to the controller. */
  SevenSegmentsDigit digits[SEVEN_SEGMENTS_MAX_DIGITS]{0, 0, 0, 0, 0, 0, 0, 0,
                                                       0, 0, 0, 0, 0, 0, 0, 0};
} ;

/** @brief Registers of a controller driving a set of 7 segments LEDs.
 *
 * Heavily inspired from the TM1637 controller.
 */
struct SevenSegmentsRegisters {
  /** @brief Control settings to send to the controller. */
  SevenSegmentsControlRegisters control;
  /** @brief Data to be sent to the controller.*/
  SevenSegmentsDataRegisters data;
};

#endif