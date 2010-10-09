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

define_pin_basic( 0, DDRE, PORTE, PINE, 0)
define_pin_basic( 1, DDRE, PORTE, PINE, 1)
define_pin_basic( 2, DDRE, PORTE, PINE, 4)
define_pin_basic( 3, DDRE, PORTE, PINE, 5)
define_pin_basic( 4, DDRG, PORTG, PING, 5)
define_pin_basic( 5, DDRE, PORTE, PINE, 3)
define_pin_basic( 6, DDRH, PORTH, PINH, 3)
define_pin_basic( 7, DDRH, PORTH, PINH, 4)

define_pin_basic( 8, DDRH, PORTH, PINH, 5)
define_pin_basic( 9, DDRH, PORTH, PINH, 6)
define_pin_basic(10, DDRB, PORTB, PINB, 4)
define_pin_basic(11, DDRB, PORTB, PINB, 5)
define_pin_basic(12, DDRB, PORTB, PINB, 6)
define_pin_basic(13, DDRB, PORTB, PINB, 7)

define_pin_basic(22, DDRA, PORTA, PINA, 0)
define_pin_basic(23, DDRA, PORTA, PINA, 1)
define_pin_basic(24, DDRA, PORTA, PINA, 2)
define_pin_basic(25, DDRA, PORTA, PINA, 3)
define_pin_basic(26, DDRA, PORTA, PINA, 4)
define_pin_basic(27, DDRA, PORTA, PINA, 5)
define_pin_basic(28, DDRA, PORTA, PINA, 6)
define_pin_basic(29, DDRA, PORTA, PINA, 7)

define_pin_basic(30, DDRC, PORTC, PINC, 7)
define_pin_basic(31, DDRC, PORTC, PINC, 6)
define_pin_basic(32, DDRC, PORTC, PINC, 5)
define_pin_basic(33, DDRC, PORTC, PINC, 4)
define_pin_basic(34, DDRC, PORTC, PINC, 3)
define_pin_basic(35, DDRC, PORTC, PINC, 2)
define_pin_basic(36, DDRC, PORTC, PINC, 1)
define_pin_basic(37, DDRC, PORTC, PINC, 0)

define_pin_basic(38, DDRD, PORTD, PIND, 7)
define_pin_basic(39, DDRG, PORTG, PING, 2)
define_pin_basic(40, DDRG, PORTG, PING, 1)
define_pin_basic(41, DDRG, PORTG, PING, 0)
define_pin_basic(42, DDRL, PORTL, PINL, 7)
define_pin_basic(43, DDRL, PORTL, PINL, 6)
define_pin_basic(44, DDRL, PORTL, PINL, 5)
define_pin_basic(45, DDRL, PORTL, PINL, 4)

define_pin_basic(46, DDRL, PORTL, PINL, 3)
define_pin_basic(47, DDRL, PORTL, PINL, 2)
define_pin_basic(48, DDRL, PORTL, PINL, 1)
define_pin_basic(49, DDRL, PORTL, PINL, 0)
define_pin_basic(50, DDRB, PORTB, PINB, 3)
define_pin_basic(51, DDRB, PORTB, PINB, 2)
define_pin_basic(52, DDRB, PORTB, PINB, 1)
define_pin_basic(53, DDRB, PORTB, PINB, 0)

#undef define_pin_basic
#undef define_pin_change_mask
#undef define_pin_digital_input
#endif
