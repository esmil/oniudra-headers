#ifndef _ARDUINO_PINS_H
#define _ARDUINO_PINS_H

#include <avr/io.h>

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

#define define_pin(nr, ddr, port, pinx, pcmsk, bit) \
	static inline void pin##nr##_mode_output() { ddr  |= _BV(bit);    } \
	static inline void pin##nr##_mode_input()  { ddr  &= ~(_BV(bit)); } \
	static inline void pin##nr##_high()        { port |= _BV(bit);    } \
	static inline void pin##nr##_low()         { port &= ~(_BV(bit)); } \
	static inline void pin##nr##_toggle()      { pinx |= _BV(bit);    } \
	static inline void pin##nr##_interrupt_mask() \
		{ pcmsk |= _BV(bit); } \
	static inline void pin##nr##_interrupt_unmask() \
		{ pcmsk &= ~(_BV(bit)); }

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

/*
define_pin(a0, DDRC, PORTC, PINC, 0)
define_pin(a1, DDRC, PORTC, PINC, 1)
define_pin(a2, DDRC, PORTC, PINC, 2)
define_pin(a3, DDRC, PORTC, PINC, 3)
define_pin(a4, DDRC, PORTC, PINC, 4)
define_pin(a5, DDRC, PORTC, PINC, 5)
*/

#undef define_pin

static inline void pin_0to7_interrupt_enable()
	{ PCICR |= _BV(PCIE2); }
static inline void pin_0to7_interrupt_disable()
	{ PCICR &= ~(_BV(PCIE2)); }
static inline void pin_8to13_interrupt_enable()
	{ PCICR |= _BV(PCIE0); }
static inline void pin_8to13_interrupt_disable()
	{ PCICR &= ~(_BV(PCIE0)); }

#endif
