/*
 * This file is part of oniudra-headers.
 *
 * oniudra-headers is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or(at your option) any later version.
 *
 * oniudra-headers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with oniudra-headers.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _ARDUINO_WDT_H
#define _ARDUINO_WDT_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#if defined(__AVR_ATmega8__)
#  error "arduino/wdt.h: Not implemented for ATmega8 chips yet"
#elif defined(__AVR_ATmega168__) \
   || defined(__AVR_ATmega328P__)
#  include <arduino/ATmegaX8/wdt.h>
#elif defined(__AVR_ATmega1280__)
#  error "arduino/wdt.h: Not implemented for ATmega1280 chips yet"
#elif defined(__AVR_ATtiny25__) \
   || defined(__AVR_ATtiny45__) \
   || defined(__AVR_ATtiny85__)
#  error "arduino/wdt.h: Not implemented for ATtiny25/45/85 chips yet"
#elif defined(__AVR_ATmega8U2__) \
   || defined(__AVR_ATmega16U2__) \
   || defined(__AVR_ATmega32U2__)
#  error "arduino/wdt.h: Not implemented for ATmega8U2/16U2/32U2 chips yet"
#else
#  error "arduino/wdt.h: Unknown chip type"
#endif

#endif
