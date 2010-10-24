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

#ifndef _ARDUINO_TIMER1_H
#define _ARDUINO_TIMER1_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* timer1 mode select */
static inline void
timer1_mode_normal()
{
	TCCR1A &= ~(_BV(WGM11) | _BV(WGM10));
	TCCR1B &= ~(_BV(WGM13) | _BV(WGM12));
}

static inline void
timer1_mode_phase_correct_8bit()
{
	TCCR1A = (TCCR1A & ~(_BV(WGM11))) | _BV(WGM10);
	TCCR1B &= ~(_BV(WGM13) | _BV(WGM12));
}

static inline void
timer1_mode_phase_correct_9bit()
{
	TCCR1A = (TCCR1A & ~(_BV(WGM10))) | _BV(WGM11);
	TCCR1B &= ~(_BV(WGM13) | _BV(WGM12));
}

static inline void
timer1_mode_phase_correct_10bit()
{
	TCCR1A |= _BV(WGM11) | _BV(WGM10);
	TCCR1B &= ~(_BV(WGM13) | _BV(WGM12));
}

static inline void
timer1_mode_ctc()
{
	TCCR1A &= ~(_BV(WGM11) | _BV(WGM10));
	TCCR1B = (TCCR1B & ~(_BV(WGM13))) | _BV(WGM12);
}

static inline void
timer1_mode_fastpwm_8bit()
{
	TCCR1A = (TCCR1A & ~(_BV(WGM11))) | _BV(WGM10);
	TCCR1B = (TCCR1B & ~(_BV(WGM13))) | _BV(WGM12);
}

static inline void
timer1_mode_fastpwm_9bit()
{
	TCCR1A = (TCCR1A & ~(_BV(WGM10))) | _BV(WGM11);
	TCCR1B = (TCCR1B & ~(_BV(WGM13))) | _BV(WGM12);
}

static inline void
timer1_mode_fastpwm_10bit()
{
	TCCR1A |= _BV(WGM10) | _BV(WGM11);
	TCCR1B = (TCCR1B & ~(_BV(WGM13))) | _BV(WGM12);
}

static inline void
timer1_mode_phase_and_freq_correct_ic()
{
	TCCR1A &= ~(_BV(WGM11) | _BV(WGM10));
	TCCR1B = (TCCR1B & ~(_BV(WGM12))) | _BV(WGM13);
}

static inline void
timer1_mode_phase_and_freq_correct()
{
	TCCR1A = (TCCR1A & ~(_BV(WGM11))) | _BV(WGM10);
	TCCR1B = (TCCR1B & ~(_BV(WGM12))) | _BV(WGM13);
}

static inline void
timer1_mode_phase_correct_ic()
{
	TCCR1A = (TCCR1A & ~(_BV(WGM10))) | _BV(WGM11);
	TCCR1B = (TCCR1B & ~(_BV(WGM12))) | _BV(WGM13);
}

static inline void
timer1_mode_phase_correct()
{
	TCCR1A |= _BV(WGM11) | _BV(WGM10);
	TCCR1B = (TCCR1B & ~(_BV(WGM12))) | _BV(WGM13);
}

static inline void
timer1_mode_ctc_ic()
{
	TCCR1A &= ~(_BV(WGM11) | _BV(WGM10));
	TCCR1B |= _BV(WGM13) | _BV(WGM12);
}

static inline void
timer1_mode_fastpwm_ic()
{
	TCCR1A = (TCCR1A & ~(_BV(WGM10))) | _BV(WGM11);
	TCCR1B |= _BV(WGM13) | _BV(WGM12);
}

static inline void
timer1_mode_fastpwm()
{
	TCCR1A |= _BV(WGM11) | _BV(WGM10);
	TCCR1B |= _BV(WGM13) | _BV(WGM12);
}

/* timer1 clock select */
static inline void
timer1_clock_off()
{
	TCCR1B = TCCR1B & ~(_BV(CS12) | _BV(CS11) | _BV(CS10));
}

static inline void
timer1_clock_d1()
{
	TCCR1B = (TCCR1B & ~(_BV(CS12) | _BV(CS11))) | _BV(CS10);
}

static inline void
timer1_clock_d8()
{
	TCCR1B = (TCCR1B & ~(_BV(CS12) | _BV(CS10))) | _BV(CS11);
}

static inline void
timer1_clock_d64()
{
	TCCR1B = (TCCR1B & ~(_BV(CS12))) | _BV(CS11) | _BV(CS10);
}

static inline void
timer1_clock_d256()
{
	TCCR1B = (TCCR1B & ~(_BV(CS11) | _BV(CS10))) | _BV(CS12);
}

static inline void
timer1_clock_d1024()
{
	TCCR1B = (TCCR1B & ~(_BV(CS11))) | _BV(CS12) | _BV(CS10);
}

static inline void
timer1_clock_external_falling()
{
	TCCR1B = (TCCR1B & ~(_BV(CS10))) | _BV(CS12) | _BV(CS11);
}

static inline void
timer1_clock_external_rising()
{
	TCCR1B = TCCR1B | _BV(CS12) | _BV(CS11) | _BV(CS10);
}

static inline uint8_t
timer1_clock_running()
{
	return TCCR1B & (_BV(CS12) | _BV(CS11) | _BV(CS10));
}

static inline void
timer1_clock_reset()
{
	GTCCR |= _BV(PSRSYNC);
}

/* timer1 pins */
static inline void
timer1_pin9_off()
{
	TCCR1A = (TCCR1A & ~(_BV(COM1A1) | _BV(COM1A0)));
}

static inline void
timer1_pin9_toggle()
{
	TCCR1A = (TCCR1A & ~(_BV(COM1A1))) | _BV(COM1A0);
}

static inline void
timer1_pin9_clear()
{
	TCCR1A = (TCCR1A & ~(_BV(COM1A0))) | _BV(COM1A1);
}

static inline void
timer1_pin9_set()
{
	TCCR1A = TCCR1A | _BV(COM1A1) | _BV(COM1A0);
}

static inline void
timer1_pin10_off()
{
	TCCR1A = (TCCR1A & ~(_BV(COM1B1) | _BV(COM1B0)));
}

static inline void
timer1_pin10_toggle()
{
	TCCR1A = (TCCR1A & ~(_BV(COM1B1))) | _BV(COM1B0);
}

static inline void
timer1_pin10_clear()
{
	TCCR1A = (TCCR1A & ~(_BV(COM1B0))) | _BV(COM1B1);
}

static inline void
timer1_pin10_set()
{
	TCCR1A = TCCR1A | _BV(COM1B1) | _BV(COM1B0);
}

/* timer1 interrupts */
static inline void
timer1_interrupt_ovf_enable()  { TIMSK1 |= _BV(TOIE1); }
static inline void
timer1_interrupt_ovf_disable() { TIMSK1 &= ~(_BV(TOIE1)); }
static inline void
timer1_interrupt_a_enable()    { TIMSK1 |= _BV(OCIE1A); }
static inline void
timer1_interrupt_a_disable()   { TIMSK1 &= ~(_BV(OCIE1A)); }
static inline void
timer1_interrupt_b_enable()    { TIMSK1 |= _BV(OCIE1B); }
static inline void
timer1_interrupt_b_disable()   { TIMSK1 &= ~(_BV(OCIE1B)); }

#define timer1_interrupt_ovf() ISR(TIMER1_OVF_vect)
#define timer1_interrupt_ovf_naked() ISR(TIMER1_OVF_vect, ISR_NAKED)
#define timer1_interrupt_ovf_empty() EMPTY_INTERRUPT(TIMER1_OVF_vect)
#define timer1_interrupt_a() ISR(TIMER1_COMPA_vect)
#define timer1_interrupt_a_naked() ISR(TIMER1_COMPA_vect, ISR_NAKED)
#define timer1_interrupt_a_empty() EMPTY_INTERRUPT(TIMER1_COMPA_vect)
#define timer1_interrupt_b() ISR(TIMER1_COMPB_vect)
#define timer1_interrupt_b_naked() ISR(TIMER1_COMPB_vect, ISR_NAKED)
#define timer1_interrupt_b_empty() EMPTY_INTERRUPT(TIMER1_COMPB_vect)

/* timer1 count */
static inline uint8_t
timer1_count_high()              { return TCNT1H; }
static inline uint8_t
timer1_count_low()               { return TCNT1L; }
static inline uint16_t
timer1_count()                   { return TCNT1; }

static inline void
timer1_count_high_set(uint8_t n) { TCNT1H = n; }
static inline void
timer1_count_low_set(uint8_t n)  { TCNT1L = n; }
static inline void
timer1_count_set(uint16_t n)     { TCNT1 = n; }

/* timer1 compare registers */
static inline uint8_t
timer1_compare_a_high()              { return OCR1AH; }
static inline uint8_t
timer1_compare_a_low()               { return OCR1AL; }
static inline uint16_t
timer1_compare_a()                   { return OCR1A; }

static inline uint8_t
timer1_compare_b_high()              { return OCR1BH; }
static inline uint8_t
timer1_compare_b_low()               { return OCR1BL; }
static inline uint16_t
timer1_compare_b()                   { return OCR1B; }

static inline void
timer1_compare_a_high_set(uint8_t v) { OCR1AH = v; }
static inline void
timer1_compare_a_low_set(uint8_t v)  { OCR1AL = v; }
static inline void
timer1_compare_a_set(uint16_t v)     { OCR1A = v; }

static inline void
timer1_compare_b_high_set(uint8_t v) { OCR1BH = v; }
static inline void
timer1_compare_b_low_set(uint8_t v)  { OCR1BL = v; }
static inline void
timer1_compare_b_set(uint16_t v)     { OCR1B = v; }

/* timer1 flags */
static inline void
timer1_flags_clear()   { TIFR1 = 7; }
static inline uint8_t
timer1_flag_overflow() { return TIFR1 & _BV(TOV1); }
static inline uint8_t
timer1_flag_a()        { return TIFR1 & _BV(OCF1A); }
static inline uint8_t
timer1_flag_b()        { return TIFR1 & _BV(OCF1B); }

#endif
