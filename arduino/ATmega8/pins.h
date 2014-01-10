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

pin__define_basic( 0, DDRD, PORTD, PIND, 0)
pin__define_basic( 1, DDRD, PORTD, PIND, 1)
pin__define_basic( 2, DDRD, PORTD, PIND, 2)
pin__define_basic( 3, DDRD, PORTD, PIND, 3)
pin__define_basic( 4, DDRD, PORTD, PIND, 4)
pin__define_basic( 5, DDRD, PORTD, PIND, 5)
pin__define_basic( 6, DDRD, PORTD, PIND, 6)
pin__define_basic( 7, DDRD, PORTD, PIND, 7)

pin__define_basic( 8, DDRB, PORTB, PINB, 0)
pin__define_basic( 9, DDRB, PORTB, PINB, 1)
pin__define_basic(10, DDRB, PORTB, PINB, 2)
pin__define_basic(11, DDRB, PORTB, PINB, 3)
pin__define_basic(12, DDRB, PORTB, PINB, 4)
pin__define_basic(13, DDRB, PORTB, PINB, 5)

pin__define_basic(A0, DDRC, PORTC, PINC, 0)
pin__define_basic(A1, DDRC, PORTC, PINC, 1)
pin__define_basic(A2, DDRC, PORTC, PINC, 2)
pin__define_basic(A3, DDRC, PORTC, PINC, 3)
pin__define_basic(A4, DDRC, PORTC, PINC, 4)
pin__define_basic(A5, DDRC, PORTC, PINC, 5)

#endif
