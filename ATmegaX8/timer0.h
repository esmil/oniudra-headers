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

#ifndef _ARDUINO_TIMER0_H
#define _ARDUINO_TIMER0_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* timer0 mode select */
static inline void
timer0_mode_normal(void)
{
	TCCR0A = TCCR0A & ~(_BV(WGM01) | _BV(WGM00));
}

static inline void
timer0_mode_phase_correct(void)
{
	TCCR0A = (TCCR0A & ~_BV(WGM01)) | _BV(WGM00);
}

static inline void
timer0_mode_ctc(void)
{
	TCCR0A = (TCCR0A & ~_BV(WGM00)) | _BV(WGM01);
}

static inline void
timer0_mode_fastpwm(void)
{
	TCCR0A = TCCR0A | _BV(WGM01) | _BV(WGM00);
}

static inline void
timer0_top_max(void) { TCCR0B &= ~(_BV(WGM02)); }
static inline void
timer0_top_a(void)   { TCCR0B |= _BV(WGM02); }

/* timer0 clock select */
static inline void
timer0_clock_off(void)
{
	TCCR0B = TCCR0B & ~(_BV(CS02) | _BV(CS01) | _BV(CS00));
}

static inline void
timer0_clock_d1(void)
{
	TCCR0B = (TCCR0B & ~(_BV(CS02) | _BV(CS01))) | _BV(CS00);
}

static inline void
timer0_clock_d8(void)
{
	TCCR0B = (TCCR0B & ~(_BV(CS02) | _BV(CS00))) | _BV(CS01);
}

static inline void
timer0_clock_d64(void)
{
	TCCR0B = (TCCR0B & ~(_BV(CS02))) | _BV(CS01) | _BV(CS00);
}

static inline void
timer0_clock_d256(void)
{
	TCCR0B = (TCCR0B & ~(_BV(CS01) | _BV(CS00))) | _BV(CS02);
}

static inline void
timer0_clock_d1024(void)
{
	TCCR0B = (TCCR0B & ~(_BV(CS01))) | _BV(CS02) | _BV(CS00);
}

static inline void
timer0_clock_external_falling(void)
{
	TCCR0B = (TCCR0B & ~(_BV(CS00))) | _BV(CS02) | _BV(CS01);
}

static inline void
timer0_clock_external_rising(void)
{
	TCCR0B = TCCR0B | _BV(CS02) | _BV(CS01) | _BV(CS00);
}

static inline uint8_t
timer0_clock_running(void)
{
	return TCCR0B & (_BV(CS02) | _BV(CS01) | _BV(CS00));
}

static inline void
timer0_clock_reset(void)
{
	GTCCR |= _BV(PSRSYNC);
}

/* timer0 pins */
static inline void
timer0_pin6_off(void)
{
	TCCR0A = TCCR0A & ~(_BV(COM0A1) | _BV(COM0A0));
}

static inline void
timer0_pin6_toggle(void)
{
	TCCR0A = (TCCR0A & ~(_BV(COM0A1))) | _BV(COM0A0);
}

static inline void
timer0_pin6_clear(void)
{
	TCCR0A = (TCCR0A & ~(_BV(COM0A0))) | _BV(COM0A1);
}

static inline void
timer0_pin6_set(void)
{
	TCCR0A = TCCR0A | _BV(COM0A1) | _BV(COM0A0);
}

static inline void
timer0_pin5_off(void)
{
	TCCR0A = TCCR0A & ~(_BV(COM0B1) | _BV(COM0B0));
}

static inline void
timer0_pin5_toggle(void)
{
	TCCR0A = (TCCR0A & ~(_BV(COM0B1))) | _BV(COM0B0);
}

static inline void
timer0_pin5_clear(void)
{
	TCCR0A = (TCCR0A & ~(_BV(COM0B0))) | _BV(COM0B1);
}

static inline void
timer0_pin5_set(void)
{
	TCCR0A = TCCR0A | _BV(COM0B1) | _BV(COM0B0);
}

/* timer0 interrupts */
static inline void
timer0_interrupt_ovf_enable(void)  { TIMSK0 |= _BV(TOIE0); }
static inline void
timer0_interrupt_ovf_disable(void) { TIMSK0 &= ~(_BV(TOIE0)); }
static inline void
timer0_interrupt_a_enable(void)    { TIMSK0 |= _BV(OCIE0A); }
static inline void
timer0_interrupt_a_disable(void)   { TIMSK0 &= ~(_BV(OCIE0A)); }
static inline void
timer0_interrupt_b_enable(void)    { TIMSK0 |= _BV(OCIE0B); }
static inline void
timer0_interrupt_b_disable(void)   { TIMSK0 &= ~(_BV(OCIE0B)); }

#define timer0_interrupt_ovf() ISR(TIMER0_OVF_vect)
#define timer0_interrupt_ovf_naked() ISR(TIMER0_OVF_vect, ISR_NAKED)
#define timer0_interrupt_ovf_empty() EMPTY_INTERRUPT(TIMER0_OVF_vect)
#define timer0_interrupt_a() ISR(TIMER0_COMPA_vect)
#define timer0_interrupt_a_naked() ISR(TIMER0_COMPA_vect, ISR_NAKED)
#define timer0_interrupt_a_empty() EMPTY_INTERRUPT(TIMER0_COMPA_vect)
#define timer0_interrupt_b() ISR(TIMER0_COMPB_vect)
#define timer0_interrupt_b_naked() ISR(TIMER0_COMPB_vect, ISR_NAKED)
#define timer0_interrupt_b_empty() EMPTY_INTERRUPT(TIMER0_COMPB_vect)

/* timer0 count */
static inline uint8_t
timer0_count(void)              { return TCNT0; }
static inline void
timer0_count_set(uint8_t n) { TCNT0 = n; }

/* timer0 compare registers */
static inline uint8_t
timer0_compare_a(void)              { return OCR0A; }
static inline uint8_t
timer0_compare_b(void)              { return OCR0B; }
static inline void
timer0_compare_a_set(uint8_t v) { OCR0A = v; }
static inline void
timer0_compare_b_set(uint8_t v) { OCR0B = v; }

/* timer0 flags */
static inline void
timer0_flags_clear(void) { TIFR0 = 7; }
static inline uint8_t
timer0_flag_ovf(void)    { return TIFR0 & _BV(TOV0); }
static inline uint8_t
timer0_flag_a(void)      { return TIFR0 & _BV(OCF0A); }
static inline uint8_t
timer0_flag_b(void)      { return TIFR0 & _BV(OCF0B); }

#endif
