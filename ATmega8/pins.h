/*
 * This file is part of arduino-headers.
 *
 * arduino-headers is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or(at your option) any later version.
 *
 * arduino-headers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with arduino-headers.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _ARDUINO_PINS_H
#define _ARDUINO_PINS_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include <arduino/common/pins.h>

define_pin_basic( 0, DDRD, PORTD, PIND, 0)
define_pin_basic( 1, DDRD, PORTD, PIND, 1)
define_pin_basic( 2, DDRD, PORTD, PIND, 2)
define_pin_basic( 3, DDRD, PORTD, PIND, 3)
define_pin_basic( 4, DDRD, PORTD, PIND, 4)
define_pin_basic( 5, DDRD, PORTD, PIND, 5)
define_pin_basic( 6, DDRD, PORTD, PIND, 6)
define_pin_basic( 7, DDRD, PORTD, PIND, 7)

define_pin_basic( 8, DDRB, PORTB, PINB, 0)
define_pin_basic( 9, DDRB, PORTB, PINB, 1)
define_pin_basic(10, DDRB, PORTB, PINB, 2)
define_pin_basic(11, DDRB, PORTB, PINB, 3)
define_pin_basic(12, DDRB, PORTB, PINB, 4)
define_pin_basic(13, DDRB, PORTB, PINB, 5)

define_pin_basic(A0, DDRC, PORTC, PINC, 0)
define_pin_basic(A1, DDRC, PORTC, PINC, 1)
define_pin_basic(A2, DDRC, PORTC, PINC, 2)
define_pin_basic(A3, DDRC, PORTC, PINC, 3)
define_pin_basic(A4, DDRC, PORTC, PINC, 4)
define_pin_basic(A5, DDRC, PORTC, PINC, 5)

#undef define_pin_basic
#undef define_pin_change_mask
#undef define_pin_digital_input
#endif
