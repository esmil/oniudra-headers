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

#ifndef _ARDUINO_ADC_H
#define _ARDUINO_ADC_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

static inline void
adc_reference_external(void)
{
	ADMUX = ADMUX & ~(_BV(REFS1) | _BV(REFS0));
}

static inline void
adc_reference_internal_5v(void)
{
	ADMUX = (ADMUX & ~(_BV(REFS1))) | _BV(REFS0);
}

static inline void
adc_reference_internal_1v1(void)
{
	ADMUX = ADMUX | _BV(REFS1) | _BV(REFS0);
}

static inline void
adc_adjust_left(void)  { ADMUX |= _BV(ADLAR); }
static inline void
adc_adjust_right(void) { ADMUX &= ~(_BV(ADLAR)); }

static inline void
adc_pin_select(uint8_t pin)
{
	ADMUX = (ADMUX & ~(_BV(MUX3) | _BV(MUX2) | _BV(MUX1) | _BV(MUX0)))
	      | pin;
}

static inline uint8_t
adc_pin(void)
{
	return ADMUX & (_BV(MUX3) | _BV(MUX2) | _BV(MUX1) | _BV(MUX0));
}

static inline void
adc_enable(void)               { ADCSRA |= _BV(ADEN); }
static inline void
adc_disable(void)              { ADCSRA &= ~(_BV(ADEN)); }
static inline void
adc_start(void)                { ADCSRA |= _BV(ADSC); }
static inline uint8_t
adc_running(void)              { return ADCSRA & _BV(ADSC); }
static inline void
adc_freerunning_enable(void)   { ADCSRA |= _BV(ADFR); }
static inline void
adc_freerunning_disable(void)  { ADCSRA &= ~(_BV(ADFR)); }
static inline uint8_t
adc_interrupt_flag(void)       { return ADCSRA & _BV(ADIF); }
static inline void
adc_interrupt_flag_clear(void) { ADCSRA |= _BV(ADIF); }
static inline void
adc_interrupt_enable(void)     { ADCSRA |= _BV(ADIE); }
static inline void
adc_interrupt_disable(void)    { ADCSRA &= ~(_BV(ADIE)); }

#define adc_interrupt() ISR(ADC_vect)
#define adc_interrupt_naked() ISR(ADC_vect, ISR_NAKED)
#define adc_interrupt_empty() EMPTY_INTERRUPT(ADC_vect)

static inline void
adc_clock_d2(void)
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS2) | _BV(ADPS1))) | _BV(ADPS0);
}

static inline void
adc_clock_d4(void)
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS2) | _BV(ADPS0))) | _BV(ADPS1);
}

static inline void
adc_clock_d8(void)
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS2))) | _BV(ADPS1) | _BV(ADPS0);
}

static inline void
adc_clock_d16(void)
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS1) | _BV(ADPS0))) | _BV(ADPS2);
}

static inline void
adc_clock_d32(void)
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS1))) | _BV(ADPS2) | _BV(ADPS0);
}

static inline void
adc_clock_d64(void)
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS0))) | _BV(ADPS2) | _BV(ADPS1);
}

static inline void
adc_clock_d128(void)
{
	ADCSRA = ADCSRA | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
}

static inline uint8_t
adc_data_high(void) { return ADCH; }
static inline uint8_t
adc_data_low(void)  { return ADCL; }
static inline uint16_t
adc_data(void)      { return ADC; }

#endif
