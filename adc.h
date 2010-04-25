#ifndef _ARDUINO_ADC_H
#define _ARDUINO_ADC_H

#include <avr/io.h>
#include <avr/interrupt.h>

static inline void
adc_reference_external()
{
	ADMUX = ADMUX & ~(_BV(REFS1) | _BV(REFS0));
}

static inline void
adc_reference_internal_5v()
{
	ADMUX = (ADMUX & ~(_BV(REFS1))) | _BV(REFS0);
}

static inline void
adc_reference_internal_1v1()
{
	ADMUX = ADMUX | _BV(REFS1) | _BV(REFS0);
}

static inline void
adc_adjust_left()  { ADMUX |= _BV(ADLAR); }
static inline void
adc_adjust_right() { ADMUX &= ~(_BV(ADLAR)); }

static inline void
adc_pin_select(uint8_t pin)
{
	ADMUX = (ADMUX & ~(_BV(MUX3) | _BV(MUX2) | _BV(MUX1) | _BV(MUX0)))
	      | pin;
}

static inline uint8_t
adc_pin()
{
	return ADMUX & (_BV(MUX3) | _BV(MUX2) | _BV(MUX1) | _BV(MUX0));
}

static inline void
adc_enable()               { ADCSRA |= _BV(ADEN); }
static inline void
adc_disable()              { ADCSRA &= ~(_BV(ADEN)); }
static inline void
adc_start()                { ADCSRA |= _BV(ADSC); }
static inline uint8_t
adc_running()              { return ADCSRA & _BV(ADSC); }
static inline void
adc_trigger_auto()         { ADCSRA |= _BV(ADATE); }
static inline void
adc_trigger_manual()       { ADCSRA &= ~(_BV(ADATE)); }
static inline uint8_t
adc_interrupt_flag()       { return ADCSRA & _BV(ADIF); }
static inline void
adc_interrupt_flag_clear() { ADCSRA &= ~(_BV(ADIF)); }
static inline void
adc_interrupt_enable()     { ADCSRA |= _BV(ADIE); }
static inline void
adc_interrupt_disable()    { ADCSRA &= ~(_BV(ADIE)); }

#define adc_interrupt() ISR(ADC_vect)
#define adc_interrupt_naked() ISR(ADC_vect, ISR_NAKED)
#define adc_interrupt_empty() EMPTY_INTERRUPT(ADC_vect)

static inline void
adc_clock_d2()
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS2) | _BV(ADPS1))) | _BV(ADPS0);
}

static inline void
adc_clock_d4()
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS2) | _BV(ADPS0))) | _BV(ADPS1);
}

static inline void
adc_clock_d8()
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS2))) | _BV(ADPS1) | _BV(ADPS0);
}

static inline void
adc_clock_d16()
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS1) | _BV(ADPS0))) | _BV(ADPS2);
}

static inline void
adc_clock_d32()
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS1))) | _BV(ADPS2) | _BV(ADPS0);
}

static inline void
adc_clock_d64()
{
	ADCSRA = (ADCSRA & ~(_BV(ADPS0))) | _BV(ADPS2) | _BV(ADPS1);
}

static inline void
adc_clock_d128()
{
	ADCSRA = ADCSRA | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
}

static inline void
adc_trigger_free()
{
	ADCSRB = ADCSRB & ~(_BV(ADTS2) | _BV(ADTS1) | _BV(ADTS0));
}

static inline void
adc_trigger_ac()
{
	ADCSRB = (ADCSRB & ~(_BV(ADTS2) | _BV(ADTS1))) | _BV(ADTS0);
}

static inline void
adc_trigger_external0()
{
	ADCSRB = (ADCSRB & ~(_BV(ADTS2) | _BV(ADTS0))) | _BV(ADTS1);
}

static inline void
adc_trigger_timer0_a()
{
	ADCSRB = (ADCSRB & ~(_BV(ADTS2))) | _BV(ADTS1) | _BV(ADTS0);
}

static inline void
adc_trigger_timer0_ovf()
{
	ADCSRB = (ADCSRB & ~(_BV(ADTS1) | _BV(ADTS0))) | _BV(ADTS2);
}

static inline void
adc_trigger_timer1_b()
{
	ADCSRB = (ADCSRB & ~(_BV(ADTS1))) | _BV(ADTS2) | _BV(ADTS0);
}

static inline void
adc_trigger_timer1_ovf()
{
	ADCSRB = (ADCSRB & ~(_BV(ADTS0))) | _BV(ADTS2) | _BV(ADTS1);
}

static inline void
adc_trigger_timer1_ce()
{
	ADCSRB = ADCSRB | _BV(ADTS2) | _BV(ADTS1) | _BV(ADTS0);
}

static inline uint8_t
adc_data_high() { return ADCH; }
static inline uint8_t
adc_data_low()  { return ADCL; }

#endif
