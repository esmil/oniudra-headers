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

define_pin_basic(0, DDRB, PORTB, PINB, 0)
define_pin_basic(1, DDRB, PORTB, PINB, 1)
define_pin_basic(2, DDRB, PORTB, PINB, 2)
define_pin_basic(3, DDRB, PORTB, PINB, 3)
define_pin_basic(4, DDRB, PORTB, PINB, 4)
define_pin_basic(5, DDRB, PORTB, PINB, 5)

/* external interrupts */
static inline void
pin2_interrupt_mode_low()     { MCUCR = MCUCR & ~(_BV(ISC01) | _BV(ISC00)); }
static inline void
pin2_interrupt_mode_change()  { MCUCR = (MCUCR & ~(_BV(ISC01))) | _BV(ISC00); }
static inline void
pin2_interrupt_mode_falling() { MCUCR = (MCUCR & ~(_BV(ISC00))) | _BV(ISC01); }
static inline void
pin2_interrupt_mode_rising()  { MCUCR = MCUCR | _BV(ISC01) | _BV(ISC00); }

#define pin2_interrupt() ISR(INT0_vect)
#define pin2_interrupt_naked() ISR(INT0_vect, ISR_NAKED)
#define pin2_interrupt_empty() EMPTY_INTERRUPT(INT0_vect)

static inline void
pin2_interrupt_enable()       { GIMSK |= _BV(INT0); }
static inline void
pin2_interrupt_disable()      { GIMSK &= ~(_BV(INT0)); }

static inline uint8_t
pin2_interrupt_flag()         { return GIFR & INTF0; }
static inline void
pin2_interrupt_flag_clear()   { GIFR |= _BV(INTF0); }

/* pin change interrupts */
define_pin_change_mask(0, PCMSK, PCINT0)
define_pin_change_mask(1, PCMSK, PCINT1)
define_pin_change_mask(2, PCMSK, PCINT2)
define_pin_change_mask(3, PCMSK, PCINT3)
define_pin_change_mask(4, PCMSK, PCINT4)
define_pin_change_mask(5, PCMSK, PCINT5)

#define pin_0to5_interrupt() ISR(PCINT_vect)
#define pin_0to5_interrupt_naked() ISR(PCINT_vect, ISR_NAKED)
#define pin_0to5_interrupt_empty() EMPTY_INTERRUPT(PCINT_vect)
static inline void
pin_0to5_interrupt_enable()   { GIMSK |= _BV(PCIE); }
static inline void
pin_0to5_interrupt_disable()  { GIMSK &= ~(_BV(PCIE)); }

/* enable/disable digital input */
define_pin_digital_input(0, DIDR0, AIN0D)
define_pin_digital_input(1, DIDR0, AIN1D)

#undef define_pin_basic
#undef define_pin_change_mask
#undef define_pin_digital_input
#endif
