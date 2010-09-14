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
timer2_mode_normal()
{
	TCCR2A = TCCR2A & ~(_BV(WGM21) | _BV(WGM20));
}

static inline void
timer2_mode_phase_correct()
{
	TCCR2A = (TCCR2A & ~(_BV(WGM21))) | _BV(WGM20);
}

static inline void
timer2_mode_ctc()
{
	TCCR2A = (TCCR2A & ~(_BV(WGM20))) | _BV(WGM21);
}

static inline void
timer2_mode_fastpwm()
{
	TCCR2A = TCCR2A | _BV(WGM21) | _BV(WGM20);
}

static inline void
timer2_top_max() { TCCR2B &= ~(_BV(WGM22)); }
static inline void
timer2_top_a()   { TCCR2B |= _BV(WGM22); }

/* timer2 clock select */
static inline void
timer2_clock_off()
{
	TCCR2B = TCCR2B & ~(_BV(CS22) | _BV(CS21) | _BV(CS20));
}

static inline void
timer2_clock_d1()
{
	TCCR2B = (TCCR2B & ~(_BV(CS22) | _BV(CS21))) | _BV(CS20);
}

static inline void
timer2_clock_d8()
{
	TCCR2B = (TCCR2B & ~(_BV(CS22) | _BV(CS20))) | _BV(CS21);
}

static inline void
timer2_clock_d32()
{
	TCCR2B = (TCCR2B & ~(_BV(CS22))) | _BV(CS21) | _BV(CS20);
}

static inline void
timer2_clock_d64()
{
	TCCR2B = (TCCR2B & ~(_BV(CS21) | _BV(CS20))) | _BV(CS22);
}

static inline void
timer2_clock_d128()
{
	TCCR2B = (TCCR2B & ~(_BV(CS21))) | _BV(CS22) | _BV(CS20);
}

static inline void
timer2_clock_d256()
{
	TCCR2B = (TCCR2B & ~(_BV(CS20))) | _BV(CS22) | _BV(CS21);
}

static inline void
timer2_clock_d1024()
{
	TCCR2B = TCCR2B | _BV(CS22) | _BV(CS21) | _BV(CS20);
}

static inline uint8_t
timer2_clock_running()
{
	return TCCR2B & (_BV(CS22) | _BV(CS21) | _BV(CS20));
}

static inline void
timer2_clock_reset()
{
	GTCCR |= _BV(PSRASY);
}

/* timer2 pins */
static inline void
timer2_pin11_off()
{
	TCCR2A = TCCR2A & ~(_BV(COM2A1) | _BV(COM2A0));
}

static inline void
timer2_pin11_toggle()
{
	TCCR2A = (TCCR2A & ~(_BV(COM2A1))) | _BV(COM2A0);
}

static inline void
timer2_pin11_clear()
{
	TCCR2A = (TCCR2A & ~(_BV(COM2A0))) | _BV(COM2A1);
}

static inline void
timer2_pin11_set()
{
	TCCR2A = TCCR2A | _BV(COM2A1) | _BV(COM2A0);
}

static inline void
timer2_pin3_off()
{
	TCCR2A = TCCR2A & ~(_BV(COM2B1) | _BV(COM2B0));
}

static inline void
timer2_pin3_toggle()
{
	TCCR2A = (TCCR2A & ~(_BV(COM2B1))) | _BV(COM2B0);
}

static inline void
timer2_pin3_clear()
{
	TCCR2A = (TCCR2A & ~(_BV(COM2B0))) | _BV(COM2B1);
}

static inline void
timer2_pin3_set()
{
	TCCR2A = TCCR2A | _BV(COM2B1) | _BV(COM2B0);
}

/* timer2 interrupts */
static inline void
timer2_interrupt_ovf_enable()  { TIMSK2 |= _BV(TOIE2); }
static inline void
timer2_interrupt_ovf_disable() { TIMSK2 &= ~(_BV(TOIE2)); }
static inline void
timer2_interrupt_a_enable()    { TIMSK2 |= _BV(OCIE2A); }
static inline void
timer2_interrupt_a_disable()   { TIMSK2 &= ~(_BV(OCIE2A)); }
static inline void
timer2_interrupt_b_enable()    { TIMSK2 |= _BV(OCIE2B); }
static inline void
timer2_interrupt_b_disable()   { TIMSK2 &= ~(_BV(OCIE2B)); }

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
timer2_count()              { return TCNT2; }
static inline void
timer2_count_set(uint8_t n) { TCNT2 = n; }

/* timer2 compare registers */
static inline uint8_t
timer2_compare_a()              { return OCR2A; }
static inline uint8_t
timer2_compare_b()              { return OCR2B; }
static inline void
timer2_compare_a_set(uint8_t v) { OCR2A = v; }
static inline void
timer2_compare_b_set(uint8_t v) { OCR2B = v; }

/* timer2 flags */
static inline void
timer2_flags_clear() { TIFR2 = 7; }
static inline uint8_t
timer2_flag_ovf()    { return TIFR2 & _BV(TOV2); }
static inline uint8_t
timer2_flag_a()      { return TIFR2 & _BV(OCF2A); }
static inline uint8_t
timer2_flag_b()      { return TIFR2 & _BV(OCF2B); }

#endif
