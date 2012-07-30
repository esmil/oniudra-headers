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

#ifndef _ARDUINO_PINS_H
#define _ARDUINO_PINS_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include <arduino/common/pins.h>

define_pin_basic(14, DDRB, PORTB, PINB, 0)
define_pin_basic(15, DDRB, PORTB, PINB, 1)
define_pin_basic(16, DDRB, PORTB, PINB, 2)
define_pin_basic(17, DDRB, PORTB, PINB, 3)
define_pin_basic(18, DDRB, PORTB, PINB, 4)
define_pin_basic(19, DDRB, PORTB, PINB, 5)
define_pin_basic(20, DDRB, PORTB, PINB, 6)
define_pin_basic(21, DDRB, PORTB, PINB, 7)

define_pin_basic(24, DDRC, PORTC, PINC, 1)
define_pin_basic( 5, DDRC, PORTC, PINC, 2)
define_pin_basic(26, DDRC, PORTC, PINC, 4)
define_pin_basic(25, DDRC, PORTC, PINC, 5)
define_pin_basic(23, DDRC, PORTC, PINC, 6)
define_pin_basic(22, DDRC, PORTC, PINC, 7)

define_pin_basic( 6, DDRD, PORTD, PIND, 0)
define_pin_basic( 7, DDRD, PORTD, PIND, 1)
define_pin_basic( 8, DDRD, PORTD, PIND, 2)
define_pin_basic( 9, DDRD, PORTD, PIND, 3)
define_pin_basic(10, DDRD, PORTD, PIND, 4)
define_pin_basic(11, DDRD, PORTD, PIND, 5)
define_pin_basic(12, DDRD, PORTD, PIND, 6)
define_pin_basic(13, DDRD, PORTD, PIND, 7)

#undef define_pin_basic
#undef define_pin_change_mask
#undef define_pin_digital_input
#endif
