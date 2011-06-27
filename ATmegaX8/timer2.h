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

#ifndef _ARDUINO_TIMER2_H
#define _ARDUINO_TIMER2_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* timer2 mode select */
static inline void
timer2_mode_normal(void)
{
	TCCR2A = TCCR2A & ~(_BV(WGM21) | _BV(WGM20));
}

static inline void
timer2_mode_phase_correct(void)
{
	TCCR2A = (TCCR2A & ~(_BV(WGM21))) | _BV(WGM20);
}

static inline void
timer2_mode_ctc(void)
{
	TCCR2A = (TCCR2A & ~(_BV(WGM20))) | _BV(WGM21);
}

static inline void
timer2_mode_fastpwm(void)
{
	TCCR2A = TCCR2A | _BV(WGM21) | _BV(WGM20);
}

static inline void
timer2_top_max(void) { TCCR2B &= ~(_BV(WGM22)); }
static inline void
timer2_top_a(void)   { TCCR2B |= _BV(WGM22); }

/* timer2 clock select */
static inline void
timer2_clock_off(void)
{
	TCCR2B = TCCR2B & ~(_BV(CS22) | _BV(CS21) | _BV(CS20));
}

static inline void
timer2_clock_d1(void)
{
	TCCR2B = (TCCR2B & ~(_BV(CS22) | _BV(CS21))) | _BV(CS20);
}

static inline void
timer2_clock_d8(void)
{
	TCCR2B = (TCCR2B & ~(_BV(CS22) | _BV(CS20))) | _BV(CS21);
}

static inline void
timer2_clock_d32(void)
{
	TCCR2B = (TCCR2B & ~(_BV(CS22))) | _BV(CS21) | _BV(CS20);
}

static inline void
timer2_clock_d64(void)
{
	TCCR2B = (TCCR2B & ~(_BV(CS21) | _BV(CS20))) | _BV(CS22);
}

static inline void
timer2_clock_d128(void)
{
	TCCR2B = (TCCR2B & ~(_BV(CS21))) | _BV(CS22) | _BV(CS20);
}

static inline void
timer2_clock_d256(void)
{
	TCCR2B = (TCCR2B & ~(_BV(CS20))) | _BV(CS22) | _BV(CS21);
}

static inline void
timer2_clock_d1024(void)
{
	TCCR2B = TCCR2B | _BV(CS22) | _BV(CS21) | _BV(CS20);
}

static inline void
timer2_clock_internal(void) { ASSR &= ~(_BV(AS2)); }
static inline void
timer2_clock_external(void) { ASSR |= _BV(AS2); }

static inline uint8_t
timer2_clock_running(void)
{
	return TCCR2B & (_BV(CS22) | _BV(CS21) | _BV(CS20));
}

static inline void
timer2_clock_reset(void)
{
	GTCCR |= _BV(PSRASY);
}

/* timer2 pins */
static inline void
timer2_pin11_off(void)
{
	TCCR2A = TCCR2A & ~(_BV(COM2A1) | _BV(COM2A0));
}

static inline void
timer2_pin11_toggle(void)
{
	TCCR2A = (TCCR2A & ~(_BV(COM2A1))) | _BV(COM2A0);
}

static inline void
timer2_pin11_clear(void)
{
	TCCR2A = (TCCR2A & ~(_BV(COM2A0))) | _BV(COM2A1);
}

static inline void
timer2_pin11_set(void)
{
	TCCR2A = TCCR2A | _BV(COM2A1) | _BV(COM2A0);
}

static inline void
timer2_pin3_off(void)
{
	TCCR2A = TCCR2A & ~(_BV(COM2B1) | _BV(COM2B0));
}

static inline void
timer2_pin3_toggle(void)
{
	TCCR2A = (TCCR2A & ~(_BV(COM2B1))) | _BV(COM2B0);
}

static inline void
timer2_pin3_clear(void)
{
	TCCR2A = (TCCR2A & ~(_BV(COM2B0))) | _BV(COM2B1);
}

static inline void
timer2_pin3_set(void)
{
	TCCR2A = TCCR2A | _BV(COM2B1) | _BV(COM2B0);
}

/* timer2 interrupts */
static inline void
timer2_interrupt_ovf_enable(void)  { TIMSK2 |= _BV(TOIE2); }
static inline void
timer2_interrupt_ovf_disable(void) { TIMSK2 &= ~(_BV(TOIE2)); }
static inline void
timer2_interrupt_a_enable(void)    { TIMSK2 |= _BV(OCIE2A); }
static inline void
timer2_interrupt_a_disable(void)   { TIMSK2 &= ~(_BV(OCIE2A)); }
static inline void
timer2_interrupt_b_enable(void)    { TIMSK2 |= _BV(OCIE2B); }
static inline void
timer2_interrupt_b_disable(void)   { TIMSK2 &= ~(_BV(OCIE2B)); }

#define timer2_interrupt_ovf() ISR(TIMER2_OVF_vect)
#define timer2_interrupt_ovf_naked() ISR(TIMER2_OVF_vect, ISR_NAKED)
#define timer2_interrupt_ovf_empty() EMPTY_INTERRUPT(TIMER2_OVF_vect)
#define timer2_interrupt_a() ISR(TIMER2_COMPA_vect)
#define timer2_interrupt_a_naked() ISR(TIMER2_COMPA_vect, ISR_NAKED)
#define timer2_interrupt_a_empty() EMPTY_INTERRUPT(TIMER2_COMPA_vect)
#define timer2_interrupt_b() ISR(TIMER2_COMPB_vect)
#define timer2_interrupt_b_naked() ISR(TIMER2_COMPB_vect, ISR_NAKED)
#define timer2_interrupt_b_empty() EMPTY_INTERRUPT(TIMER2_COMPB_vect)

/* timer2 count */
static inline uint8_t
timer2_count(void)              { return TCNT2; }
static inline void
timer2_count_set(uint8_t n) { TCNT2 = n; }

/* timer2 compare registers */
static inline uint8_t
timer2_compare_a(void)              { return OCR2A; }
static inline uint8_t
timer2_compare_b(void)              { return OCR2B; }
static inline void
timer2_compare_a_set(uint8_t v) { OCR2A = v; }
static inline void
timer2_compare_b_set(uint8_t v) { OCR2B = v; }

/* timer2 flags */
static inline void
timer2_flags_clear(void) { TIFR2 = 7; }
static inline uint8_t
timer2_flag_ovf(void)    { return TIFR2 & _BV(TOV2); }
static inline uint8_t
timer2_flag_a(void)      { return TIFR2 & _BV(OCF2A); }
static inline uint8_t
timer2_flag_b(void)      { return TIFR2 & _BV(OCF2B); }

#endif
