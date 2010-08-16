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

/*
 * ATMEL ATMEGA8 & 168 / ARDUINO
 *
 *                  +-\/-+
 *            PC6  1|    |28  PC5 (AI 5)
 *      (D 0) PD0  2|    |27  PC4 (AI 4)
 *      (D 1) PD1  3|    |26  PC3 (AI 3)
 *      (D 2) PD2  4|    |25  PC2 (AI 2)
 * PWM+ (D 3) PD3  5|    |24  PC1 (AI 1)
 *      (D 4) PD4  6|    |23  PC0 (AI 0)
 *            VCC  7|    |22  GND
 *            GND  8|    |21  AREF
 *            PB6  9|    |20  AVCC
 *            PB7 10|    |19  PB5 (D 13)
 * PWM+ (D 5) PD5 11|    |18  PB4 (D 12)
 * PWM+ (D 6) PD6 12|    |17  PB3 (D 11) PWM
 *      (D 7) PD7 13|    |16  PB2 (D 10) PWM
 *      (D 8) PB0 14|    |15  PB1 (D 9) PWM
 *                  +----+
 *
 * (PWM+ indicates the additional PWM pins on the ATmega168.)
 */

#define INLINE __attribute__((always_inline)) inline
#define define_pin(nr, ddr, port, pinx, pcmsk, bit)\
	static INLINE void pin##nr##_mode_output() { ddr  |= _BV(bit);    }\
	static INLINE void pin##nr##_mode_input()  { ddr  &= ~(_BV(bit)); }\
	static INLINE void pin##nr##_high()        { port |= _BV(bit);    }\
	static INLINE void pin##nr##_low()         { port &= ~(_BV(bit)); }\
	static INLINE void pin##nr##_toggle()      { pinx |= _BV(bit);    }\
	static inline uint8_t pin##nr##_is_high()\
	{\
		return pinx & _BV(bit);\
	}\
	static inline void pin##nr##_interrupt_mask()\
	{\
		pcmsk |= _BV(bit);\
	}\
	static inline void pin##nr##_interrupt_unmask()\
	{\
		pcmsk &= ~(_BV(bit));\
	}

define_pin( 0, DDRD, PORTD, PIND, PCMSK2, 0)
define_pin( 1, DDRD, PORTD, PIND, PCMSK2, 1)
define_pin( 2, DDRD, PORTD, PIND, PCMSK2, 2)
define_pin( 3, DDRD, PORTD, PIND, PCMSK2, 3)
define_pin( 4, DDRD, PORTD, PIND, PCMSK2, 4)
define_pin( 5, DDRD, PORTD, PIND, PCMSK2, 5)
define_pin( 6, DDRD, PORTD, PIND, PCMSK2, 6)
define_pin( 7, DDRD, PORTD, PIND, PCMSK2, 7)

define_pin( 8, DDRB, PORTB, PINB, PCMSK0, 0)
define_pin( 9, DDRB, PORTB, PINB, PCMSK0, 1)
define_pin(10, DDRB, PORTB, PINB, PCMSK0, 2)
define_pin(11, DDRB, PORTB, PINB, PCMSK0, 3)
define_pin(12, DDRB, PORTB, PINB, PCMSK0, 4)
define_pin(13, DDRB, PORTB, PINB, PCMSK0, 5)

define_pin(a0, DDRC, PORTC, PINC, PCMSK1, 0)
define_pin(a1, DDRC, PORTC, PINC, PCMSK1, 1)
define_pin(a2, DDRC, PORTC, PINC, PCMSK1, 2)
define_pin(a3, DDRC, PORTC, PINC, PCMSK1, 3)
define_pin(a4, DDRC, PORTC, PINC, PCMSK1, 4)
define_pin(a5, DDRC, PORTC, PINC, PCMSK1, 5)

#undef define_pin
#undef INLINE

static inline void
pin2_interrupt_mode_low()     { EICRA = EICRA & ~(_BV(ISC01) | _BV(ISC00)); }
static inline void
pin2_interrupt_mode_change()  { EICRA = (EICRA & ~(_BV(ISC01))) | _BV(ISC00); }
static inline void
pin2_interrupt_mode_falling() { EICRA = (EICRA & ~(_BV(ISC00))) | _BV(ISC01); }
static inline void
pin2_interrupt_mode_rising()  { EICRA = EICRA | _BV(ISC01) | _BV(ISC00); }

static inline void
pin3_interrupt_mode_low()     { EICRA = EICRA & ~(_BV(ISC11) | _BV(ISC10)); }
static inline void
pin3_interrupt_mode_change()  { EICRA = (EICRA & ~(_BV(ISC11))) | _BV(ISC10); }
static inline void
pin3_interrupt_mode_falling() { EICRA = (EICRA & ~(_BV(ISC10))) | _BV(ISC11); }
static inline void
pin3_interrupt_mode_rising()  { EICRA = EICRA | _BV(ISC11) | _BV(ISC10); }

#define pin2_interrupt() ISR(INT0_vect)
#define pin2_interrupt_naked() ISR(INT0_vect, ISR_NAKED)
#define pin2_interrupt_empty() EMPTY_INTERRUPT(INT0_vect)
static inline void
pin2_interrupt_enable()       { EIMSK |= _BV(INT0); }
static inline void
pin2_interrupt_disable()      { EIMSK &= ~(_BV(INT0)); }

#define pin3_interrupt() ISR(INT1_vect)
#define pin3_interrupt_naked() ISR(INT1_vect, ISR_NAKED)
#define pin3_interrupt_empty() EMPTY_INTERRUPT(INT1_vect)
static inline void
pin3_interrupt_enable()       { EIMSK |= _BV(INT1); }
static inline void
pin3_interrupt_disable()      { EIMSK &= ~(_BV(INT1)); }

static inline uint8_t
pin2_interrupt_flag()         { return EIFR & INTF0; }
static inline void
pin2_interrupt_flag_clear()   { EIMSK |= _BV(INTF0); }
static inline uint8_t
pin3_interrupt_flag()         { return EIFR & INTF1; }
static inline void
pin3_interrupt_flag_clear()   { EIMSK |= _BV(INTF1); }

#define pin_0to7_interrupt() ISR(PCINT2_vect)
#define pin_0to7_interrupt_naked() ISR(PCINT2_vect, ISR_NAKED)
#define pin_0to7_interrupt_empty() EMPTY_INTERRUPT(PCINT2_vect)
static inline void
pin_0to7_interrupt_enable()   { PCICR |= _BV(PCIE2); }
static inline void
pin_0to7_interrupt_disable()  { PCICR &= ~(_BV(PCIE2)); }
#define pin_8to13_interrupt() ISR(PCINT0_vect)
#define pin_8to13_interrupt_naked() ISR(PCINT0_vect, ISR_NAKED)
#define pin_8to13_interrupt_empty() EMPTY_INTERRUPT(PCINT0_vect)
static inline void
pin_8to13_interrupt_enable()  { PCICR |= _BV(PCIE0); }
static inline void
pin_8to13_interrupt_disable() { PCICR &= ~(_BV(PCIE0)); }

#define pin_mode_output_(nr) pin##nr##_mode_output()
#define pin_mode_output(nr) pin_mode_output_(nr)
#define pin_mode_input_(nr) pin##nr##_mode_input()
#define pin_mode_input(nr) pin_mode_input_(nr)
#define pin_high_(nr) pin##nr##_high()
#define pin_high(nr) pin_high_(nr)
#define pin_low_(nr) pin##nr##_low()
#define pin_low(nr) pin_low_(nr)
#define pin_toggle_(nr) pin##nr##_toggle()
#define pin_toggle(nr) pin_toggle_(nr)
#define pin_is_high_(nr) pin##nr##_is_high()
#define pin_is_high(nr) pin_is_high_(nr)
#define pin_interrupt_mask_(nr) pin##nr##_interrupt_mask()
#define pin_interrupt_mask(nr) pin_interrupt_mask_(nr)
#define pin_interrupt_unmask_(nr) pin##nr##_interrupt_unmask()
#define pin_interrupt_unmask(nr) pin_interrupt_unmask_(nr)

#endif
