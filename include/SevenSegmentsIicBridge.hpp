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

#ifndef SEVEN_SEGMENTS_IIC_BRIDGE_HPP
#define SEVEN_SEGMENTS_IIC_BRIDGE_HPP

// standard includes
#include <cstdint>

// esp32 includes

// project includes
#include "SevenSegmentsTypes.hpp"

/** @brief An I2C device will be designated by an ID, platform-specific implementation will have to deal with it. */
using IicDeviceId = uint8_t ;

/** @brief model of status after some I2C operation took place, to wrap a platform-specific value type. */
template <typename ReturnCode> 
struct IicStatus {
    bool ok ;
    ReturnCode errorCode;
} ; 

/** @brief Model of a 7 segment display module addressable through an I2C link.
 */
template <typename ReturnCode> 
class SevenSegmentsIicBridge {
    private:

    public:
        virtual ~SevenSegmentsIicBridge() {} ;
        virtual IicStatus<ReturnCode> upload(SevenSegmentsRegisters *registers, IicDeviceId recipient) = 0 ;
} ;

#endif