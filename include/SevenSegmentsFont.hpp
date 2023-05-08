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

#ifndef SEVEN_SEGMENTS_FONT_HPP
#define SEVEN_SEGMENTS_FONT_HPP

// standard includes
#include <cstdint>

// esp32 includes

// project includes
#include "SevenSegmentsTypes.hpp"

/** @brief Digit data to use when a font does not covers a given code point.*/
const SevenSegmentsDigit DEFAULT_GLYPH = 0 ;

/** @brief Description of a font for a 7 segments display.
 * A font covers a range of 'code points' (e.g. ascii code), starting from
 * `firstCodePoint` included to `firstCodePoint + glyphCount` excluded.
 * 
 * Outside the covered range, the value to be use is `DEFAULT_GLYPH`.
 */
struct SevenSegmentFont {
  /** @brief The first code point covered by this font. */
  uint8_t firstCodePoint;
  /** @brief The number of glyphes. */
  uint8_t glyphCount;
  /** @brief The actual data for each glyph.*/
  const SevenSegmentsDigit * const glyphData;
};

// write code here
extern const SevenSegmentFont SevenSegmentsFontUsAscii ;

#endif